// default.cpp - written and placed in the public domain by Wei Dai

#include "pch.h"
#include "default.h"
#include "cbc.h"
#include "queue.h"
#include <time.h>
#include <memory>

NAMESPACE_BEGIN(CryptoPP)

static const unsigned int MASH_ITERATIONS = 200;
static const unsigned int SALTLENGTH = 8;
static const unsigned int BLOCKSIZE = Default_ECB_Encryption::BLOCKSIZE;
static const unsigned int KEYLENGTH = Default_ECB_Encryption::DEFAULT_KEYLENGTH;

// The purpose of this function Mash() is to take an arbitrary length input
// string and *deterministicly* produce an arbitrary length output string such
// that (1) it looks random, (2) no information about the input is
// deducible from it, and (3) it contains as much entropy as it can hold, or
// the amount of entropy in the input string, whichever is smaller.

static void Mash(const byte *in, word16 inLen, byte *out, word16 outLen, int iterations)
{
	unsigned int bufSize = (outLen-1+DefaultHashModule::DIGESTSIZE-((outLen-1)%DefaultHashModule::DIGESTSIZE));

	// ASSERT: bufSize == (the smallest multiple of DIGESTSIZE that is >= outLen)

	byte b[2];
	SecByteBlock buf(bufSize);
	SecByteBlock outBuf(bufSize);
	DefaultHashModule hash;

	unsigned int i;
	for(i=0; i<outLen; i+=DefaultHashModule::DIGESTSIZE)
	{
		b[0] = (byte) i >> 8;
		b[1] = (byte) i;
		hash.Update(b, 2);
		hash.Update(in, inLen);
		hash.Final(outBuf+i);
	}

	while (iterations-- > 1)
	{
		memcpy(buf, outBuf, bufSize);
		for (i=0; i<bufSize; i+=DefaultHashModule::DIGESTSIZE)
		{
			b[0] = (byte) i >> 8;
			b[1] = (byte) i;
			hash.Update(b, 2);
			hash.Update(buf, bufSize);
			hash.Final(outBuf+i);
		}
	}

	memcpy(out, outBuf, outLen);
}

static void GenerateKeyIV(const byte *passphrase, unsigned int passphraseLength, const byte *salt, unsigned int saltLength, byte *key, byte *IV)
{
	SecByteBlock temp(passphraseLength+saltLength);
	memcpy(temp, passphrase, passphraseLength);
	memcpy(temp+passphraseLength, salt, saltLength);
	SecByteBlock keyIV(KEYLENGTH+BLOCKSIZE);
	Mash(temp, passphraseLength + saltLength, keyIV, KEYLENGTH+BLOCKSIZE, MASH_ITERATIONS);
	memcpy(key, keyIV, KEYLENGTH);
	memcpy(IV, keyIV+KEYLENGTH, BLOCKSIZE);
}

// ********************************************************

DefaultEncryptor::DefaultEncryptor(const char *passphrase, BufferedTransformation *outQ)
	: ProxyFilter(NULL, 0, 0, outQ), m_passphrase((const byte *)passphrase, strlen(passphrase))
{
}

DefaultEncryptor::DefaultEncryptor(const byte *passphrase, unsigned int passphraseLength, BufferedTransformation *outQ)
	: ProxyFilter(NULL, 0, 0, outQ), m_passphrase(passphrase, passphraseLength)
{
}

void DefaultEncryptor::FirstPut(const byte *)
{
	assert(SALTLENGTH <= DefaultHashModule::DIGESTSIZE);
	assert(BLOCKSIZE <= DefaultHashModule::DIGESTSIZE);

	SecByteBlock salt(DefaultHashModule::DIGESTSIZE), keyCheck(DefaultHashModule::DIGESTSIZE);
	DefaultHashModule hash;

	// use hash(passphrase | time | clock) as salt
	hash.Update(m_passphrase, m_passphrase.size);
	time_t t=time(0);
	hash.Update((byte *)&t, sizeof(t));
	clock_t c=clock();
	hash.Update((byte *)&c, sizeof(c));
	hash.Final(salt);

	// use hash(passphrase | salt) as key check
	hash.Update(m_passphrase, m_passphrase.size);
	hash.Update(salt, SALTLENGTH);
	hash.Final(keyCheck);

	AttachedTransformation()->Put(salt, SALTLENGTH);

	// mash passphrase and salt together into key and IV
	SecByteBlock key(KEYLENGTH);
	SecByteBlock IV(BLOCKSIZE);
	GenerateKeyIV(m_passphrase, m_passphrase.size, salt, SALTLENGTH, key, IV);

	m_cipher.reset(new Default_ECB_Encryption(key));
	SetFilter(new CBCPaddedEncryptor(*m_cipher, IV));

	m_filter->Put(keyCheck, BLOCKSIZE);
}

void DefaultEncryptor::LastPut(const byte *inString, unsigned int length)
{
	m_filter->MessageEnd();
}

// ********************************************************

DefaultDecryptor::DefaultDecryptor(const char *p, BufferedTransformation *outQ, bool throwException)
	: ProxyFilter(NULL, SALTLENGTH+BLOCKSIZE, 0, outQ)
	, m_state(WAITING_FOR_KEYCHECK)
	, m_passphrase((const byte *)p, strlen(p))
	, m_throwException(throwException)
{
}

DefaultDecryptor::DefaultDecryptor(const byte *passphrase, unsigned int passphraseLength, BufferedTransformation *outQ, bool throwException)
	: ProxyFilter(NULL, SALTLENGTH+BLOCKSIZE, 0, outQ)
	, m_state(WAITING_FOR_KEYCHECK)
	, m_passphrase(passphrase, passphraseLength)
	, m_throwException(throwException)
{
}

void DefaultDecryptor::FirstPut(const byte *inString)
{
	CheckKey(inString, inString+SALTLENGTH);
}

void DefaultDecryptor::LastPut(const byte *inString, unsigned int length)
{
	if (m_filter.get() == NULL)
	{
		m_state = KEY_BAD;
		if (m_throwException)
			throw KeyBadErr();
	}
	else
	{
		m_filter->MessageEnd();
		m_state = WAITING_FOR_KEYCHECK;
	}
}

void DefaultDecryptor::CheckKey(const byte *salt, const byte *keyCheck)
{
	SecByteBlock check(STDMAX((unsigned int)2*BLOCKSIZE, (unsigned int)DefaultHashModule::DIGESTSIZE));

	DefaultHashModule hash;
	hash.Update(m_passphrase, m_passphrase.size);
	hash.Update(salt, SALTLENGTH);
	hash.Final(check);

	SecByteBlock key(KEYLENGTH);
	SecByteBlock IV(BLOCKSIZE);
	GenerateKeyIV(m_passphrase, m_passphrase.size, salt, SALTLENGTH, key, IV);

	m_cipher.reset(new Default_ECB_Decryption(key));
	std::auto_ptr<CBCPaddedDecryptor> decryptor(new CBCPaddedDecryptor(*m_cipher, IV));

	decryptor->Put(keyCheck, BLOCKSIZE);
	decryptor->ForceNextPut();
	decryptor->Get(check+BLOCKSIZE, BLOCKSIZE);

	SetFilter(decryptor.release());

	if (memcmp(check, check+BLOCKSIZE, BLOCKSIZE))
	{
		m_state = KEY_BAD;
		if (m_throwException)
			throw KeyBadErr();
	}
	else
		m_state = KEY_GOOD;
}

// ********************************************************

static DefaultMAC * NewDefaultEncryptorMAC(const byte *passphrase, unsigned int passphraseLength)
{
	unsigned int macKeyLength = DefaultMAC::KeyLength(16);
	SecByteBlock macKey(macKeyLength);
	// since the MAC is encrypted there is no reason to mash the passphrase for many iterations
	Mash(passphrase, passphraseLength, macKey, macKeyLength, 1);
	return new DefaultMAC(macKey, macKeyLength);
}

DefaultEncryptorWithMAC::DefaultEncryptorWithMAC(const char *passphrase, BufferedTransformation *outQueue)
	: ProxyFilter(NULL, 0, 0, outQueue)
	, m_mac(NewDefaultEncryptorMAC((const byte *)passphrase, strlen(passphrase)))
{
	SetFilter(new HashFilter(*m_mac, new DefaultEncryptor(passphrase), true));
}

DefaultEncryptorWithMAC::DefaultEncryptorWithMAC(const byte *passphrase, unsigned int passphraseLength, BufferedTransformation *outQueue)
	: ProxyFilter(NULL, 0, 0, outQueue)
	, m_mac(NewDefaultEncryptorMAC(passphrase, passphraseLength))
{
	SetFilter(new HashFilter(*m_mac, new DefaultEncryptor(passphrase, passphraseLength), true));
}

void DefaultEncryptorWithMAC::LastPut(const byte *inString, unsigned int length)
{
	m_filter->MessageEnd();
}

// ********************************************************

DefaultDecryptorWithMAC::DefaultDecryptorWithMAC(const char *passphrase, BufferedTransformation *outQueue, bool throwException)
	: ProxyFilter(NULL, 0, 0, outQueue)
	, m_mac(NewDefaultEncryptorMAC((const byte *)passphrase, strlen(passphrase)))
	, m_throwException(throwException)
{
	SetFilter(new DefaultDecryptor(passphrase, m_hashVerifier=new HashVerifier(*m_mac, NULL, HashVerifier::PUT_MESSAGE), throwException));
}

DefaultDecryptorWithMAC::DefaultDecryptorWithMAC(const byte *passphrase, unsigned int passphraseLength, BufferedTransformation *outQueue, bool throwException)
	: ProxyFilter(NULL, 0, 0, outQueue)
	, m_mac(NewDefaultEncryptorMAC(passphrase, passphraseLength))
	, m_throwException(throwException)
{
	SetFilter(new DefaultDecryptor(passphrase, passphraseLength, m_hashVerifier=new HashVerifier(*m_mac, NULL, HashVerifier::PUT_MESSAGE), throwException));
}

DefaultDecryptor::State DefaultDecryptorWithMAC::CurrentState() const
{
	return static_cast<const DefaultDecryptor *>(m_filter.get())->CurrentState();
}

bool DefaultDecryptorWithMAC::CheckLastMAC() const
{
	return m_hashVerifier->GetLastResult();
}

void DefaultDecryptorWithMAC::LastPut(const byte *inString, unsigned int length)
{
	m_filter->MessageEnd();
	if (m_throwException && !CheckLastMAC())
		throw MACBadErr();
}

NAMESPACE_END