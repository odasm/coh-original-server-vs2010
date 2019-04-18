// zinflate.cpp - written and placed in the public domain by Wei Dai

#include "pch.h"
#include "zinflate.h"

NAMESPACE_BEGIN(CryptoPP)

inline bool LowFirstBitReader::FillBuffer(unsigned int length)
{
	while (m_bitsBuffered < length)
	{
		byte b;
		if (!m_store.Get(b))
			return false;
		m_buffer |= (unsigned long)b << m_bitsBuffered;
		m_bitsBuffered += 8;
	}
	assert(m_bitsBuffered <= sizeof(unsigned long)*8);
	return true;
}

inline unsigned long LowFirstBitReader::PeekBits(unsigned int length)
{
	bool result = FillBuffer(length);
	assert(result);
	return m_buffer & (((unsigned long)1 << length) - 1);
}

inline void LowFirstBitReader::SkipBits(unsigned int length)
{
	assert(m_bitsBuffered >= length);
	m_buffer >>= length;
	m_bitsBuffered -= length;
}

inline unsigned long LowFirstBitReader::GetBits(unsigned int length)
{
	unsigned long result = PeekBits(length);
	SkipBits(length);
	return result;
}

inline HuffmanDecoder::code_t HuffmanDecoder::NormalizeCode(HuffmanDecoder::code_t code, unsigned int codeBits)
{
	return code << (MAX_CODE_BITS - codeBits);
}

void HuffmanDecoder::Initialize(const unsigned int *codeBits, unsigned int nCodes)
{
	if (nCodes == 0)
		throw Err("null code");

	m_maxCodeBits = *std::max_element(codeBits, codeBits+nCodes);

	if (m_maxCodeBits == 0)
		throw Err("null code");

	SecBlock<unsigned int> blCount(m_maxCodeBits+1);
	std::fill(blCount.Begin(), blCount.End(), 0);
	unsigned int i;
	for (i=0; i<nCodes; i++)
		blCount[codeBits[i]]++;

	code_t code = 0;
	SecBlock<code_t> nextCode(m_maxCodeBits+1);
	nextCode[1] = 0;
	for (i=2; i<=m_maxCodeBits; i++)
	{
		// compute this while checking for overflow: code = (code + blCount[i-1]) << 1
		if (code > code + blCount[i-1])
			throw Err("codes oversubscribed");
		code += blCount[i-1];
		if (code > (code << 1))
			throw Err("codes oversubscribed");
		code <<= 1;
		nextCode[i] = code;
	}

	if (code > (1 << m_maxCodeBits) - blCount[m_maxCodeBits])
		throw Err("codes oversubscribed");
	else if (m_maxCodeBits != 1 && code < (1 << m_maxCodeBits) - blCount[m_maxCodeBits])
		throw Err("codes incomplete");

	m_codeToValue.Resize(nCodes - blCount[0]);
	unsigned int j=0;
	for (i=0; i<nCodes; i++) 
	{
		unsigned int len = codeBits[i];
		if (len != 0)
		{
			code = NormalizeCode(nextCode[len]++, len);
			m_codeToValue[j].code = code;
			m_codeToValue[j].len = len;
			m_codeToValue[j].value = i;
			j++;
		}
	}
	std::sort(m_codeToValue.Begin(), m_codeToValue.End());

	m_cacheBits = STDMIN(9U, m_maxCodeBits);
	m_cacheMask = (1 << m_cacheBits) - 1;
	code_t leftoverMask = ~NormalizeCode(m_cacheMask, m_cacheBits);
	m_cache.Resize(1 << m_cacheBits);

	for (i=0; i<m_cache.size; i++)
	{
		code_t normalizedCode = bitReverse(i);
		const CodeInfo &codeInfo = *(std::upper_bound(m_codeToValue.Begin(), m_codeToValue.End(), normalizedCode, CodeLessThan)-1);
		if (codeInfo.len <= m_cacheBits)
		{
			m_cache[i].type = 0;
			m_cache[i].value = codeInfo.value;
			m_cache[i].len = codeInfo.len;
		}
		else
		{
			m_cache[i].begin = &codeInfo;
			const CodeInfo *last = std::upper_bound(m_codeToValue.Begin(), m_codeToValue.End(), normalizedCode + leftoverMask, CodeLessThan)-1;
			if (codeInfo.len == last->len)
			{
				m_cache[i].type = 1;
				m_cache[i].len = codeInfo.len;
			}
			else
			{
				m_cache[i].type = 2;
				m_cache[i].end = last+1;
			}
		}
	}
}

inline unsigned int HuffmanDecoder::Decode(code_t code, /* out */ value_t &value) const
{
	assert(m_codeToValue.size > 0);
	const LookupEntry &entry = m_cache[code & m_cacheMask];
	if (entry.type == 0)
	{
		value = entry.value;
		return entry.len;
	}
	else
	{
		code_t normalizedCode = bitReverse(code);
		const CodeInfo &codeInfo = (entry.type == 1)
			? entry.begin[(normalizedCode << m_cacheBits) >> (MAX_CODE_BITS - (entry.len - m_cacheBits))]
			: *(std::upper_bound(entry.begin, entry.end, normalizedCode, CodeLessThan)-1);
		value = codeInfo.value;
		return codeInfo.len;
	}
}

bool HuffmanDecoder::Decode(LowFirstBitReader &reader, value_t &value) const
{
	reader.FillBuffer(m_maxCodeBits);
	unsigned int codeBits = Decode(reader.PeekBuffer(), value);
	if (codeBits > reader.BitsBuffered())
		return false;
	reader.SkipBits(codeBits);
	return true;
}

// *************************************************************

Inflator::Inflator(BufferedTransformation *outQueue, bool repeat, int propagation)
	: Filter(outQueue), BufferedTransformationWithAutoSignal(propagation)
	, m_repeat(repeat), m_decodersInitializedWithFixedCodes(false)
	, m_state(PRE_STREAM), m_reader(m_inQueue)
{
}

inline void Inflator::OutputByte(byte b)
{
	m_window[m_current++] = b;
	if (m_current == m_window.size)
	{
		ProcessDecompressedData(m_window + m_lastFlush, m_window.size - m_lastFlush);
		m_lastFlush = 0;
		m_current = 0;
	}
	if (m_maxDistance < m_window.size)
		m_maxDistance++;
}

void Inflator::OutputString(const byte *string, unsigned int length)
{
	while (length--)
		OutputByte(*string++);
}

void Inflator::OutputPast(unsigned int length, unsigned int distance)
{
	if (distance > m_maxDistance)
		throw BadBlockErr();
	unsigned int start;
	if (m_current > distance)
		start = m_current - distance;
	else
		start = m_current + m_window.size - distance;

	if (start + length > m_window.size)
	{
		for (; start < m_window.size; start++, length--)
			OutputByte(m_window[start]);
		start = 0;
	}

	if (start + length > m_current || m_current + length >= m_window.size)
	{
		while (length--)
			OutputByte(m_window[start++]);
	}
	else
	{
		memcpy(m_window + m_current, m_window + start, length);
		m_current += length;
		m_maxDistance = STDMIN(m_window.size, m_maxDistance + length);
	}
}

void Inflator::Put(const byte *inString, unsigned int length)
{
	LazyPutter lp(m_inQueue, inString, length);
	ProcessInput(false);
}

void Inflator::Flush(bool completeFlush, int propagation)
{
	if (completeFlush)
		ProcessInput(true);
	FlushOutput();
	Filter::Flush(completeFlush, propagation);
}

void Inflator::MessageEnd(int propagation)
{
	ProcessInput(true);
	if (!(m_state == PRE_STREAM || m_state == AFTER_END))
		throw UnexpectedEndErr();
	Filter::MessageEnd(propagation);
}

void Inflator::ProcessInput(bool flush)
{
	while (true)
	{
		if (m_inQueue.IsEmpty())
			return;

		switch (m_state)
		{
		case PRE_STREAM:
			if (!flush && m_inQueue.CurrentSize() < MaxPrestreamHeaderSize())
				return;
			ProcessPrestreamHeader();
			m_state = WAIT_HEADER;
			m_maxDistance = 0;
			m_current = 0;
			m_lastFlush = 0;
			m_window.Resize(1 << GetLog2WindowSize());
			break;
		case WAIT_HEADER:
			{
			// maximum number of bytes before actual compressed data starts
			const unsigned int MAX_HEADER_SIZE = bitsToBytes(3+5+5+4+19*7+286*15+19*15);
			if (m_inQueue.CurrentSize() < (flush ? 1 : MAX_HEADER_SIZE))
				return;
			DecodeHeader();
			break;
			}
		case DECODING_BODY:
			if (!DecodeBody())
				return;
			break;
		case POST_STREAM:
			if (!flush && m_inQueue.CurrentSize() < MaxPoststreamTailSize())
				return;
			ProcessPoststreamTail();
			m_state = m_repeat ? PRE_STREAM : AFTER_END;
			Filter::MessageEnd(GetAutoSignalPropagation());
			break;
		case AFTER_END:
			m_inQueue.TransferTo(*AttachedTransformation());
			return;
		}
	}
}

void Inflator::DecodeHeader()
{
	if (!m_reader.FillBuffer(3))
		throw UnexpectedEndErr();
	m_eof = m_reader.GetBits(1);
	m_blockType = m_reader.GetBits(2);
	switch (m_blockType)
	{
	case 0:	// stored
		{
		m_reader.SkipBits(m_reader.BitsBuffered() % 8);
		if (!m_reader.FillBuffer(32))
			throw UnexpectedEndErr();
		m_storedLen = m_reader.GetBits(16);
		word16 nlen = m_reader.GetBits(16);
		if (nlen != (word16)~m_storedLen)
			throw BadBlockErr();
		break;
		}
	case 1:	// fixed codes
		if (!m_decodersInitializedWithFixedCodes)
		{
			unsigned int codeLengths[288];
			std::fill(codeLengths + 0, codeLengths + 144, 8);
			std::fill(codeLengths + 144, codeLengths + 256, 9);
			std::fill(codeLengths + 256, codeLengths + 280, 7);
			std::fill(codeLengths + 280, codeLengths + 288, 8);
			m_literalDecoder.Initialize(codeLengths, 288);
			std::fill(codeLengths + 0, codeLengths + 32, 5);
			m_distanceDecoder.Initialize(codeLengths, 32);
			m_decodersInitializedWithFixedCodes = true;
		}
		m_nextDecode = LITERAL;
		break;
	case 2:	// dynamic codes
		{
		m_decodersInitializedWithFixedCodes = false;
		if (!m_reader.FillBuffer(5+5+4))
			throw UnexpectedEndErr();
		unsigned int hlit = m_reader.GetBits(5);
		unsigned int hdist = m_reader.GetBits(5);
		unsigned int hclen = m_reader.GetBits(4);

		SecBlock<unsigned int> codeLengths(286+32);
		unsigned int i;
		static const unsigned int border[] = {    // Order of the bit length code lengths
			16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
		std::fill(codeLengths.ptr, codeLengths+19, 0);
		for (i=0; i<hclen+4; i++)
			codeLengths[border[i]] = m_reader.GetBits(3);

		try
		{
			HuffmanDecoder codeLengthDecoder(codeLengths, 19);
			for (i = 0; i < hlit+257+hdist+1; )
			{
				unsigned int k, count, repeater;
				bool result = codeLengthDecoder.Decode(m_reader, k);
				if (!result)
					throw UnexpectedEndErr();
				if (k <= 15)
				{
					count = 1;
					repeater = k;
				}
				else switch (k)
				{
				case 16:
					if (!m_reader.FillBuffer(2))
						throw UnexpectedEndErr();
					count = 3 + m_reader.GetBits(2);
					if (i == 0)
						throw BadBlockErr();
					repeater = codeLengths[i-1];
					break;
				case 17:
					if (!m_reader.FillBuffer(3))
						throw UnexpectedEndErr();
					count = 3 + m_reader.GetBits(3);
					repeater = 0;
					break;
				case 18:
					if (!m_reader.FillBuffer(7))
						throw UnexpectedEndErr();
					count = 11 + m_reader.GetBits(7);
					repeater = 0;
					break;
				}
				if (i + count > hlit+257+hdist+1)
					throw BadBlockErr();
				std::fill(codeLengths + i, codeLengths + i + count, repeater);
				i += count;
			}
			m_literalDecoder.Initialize(codeLengths, hlit+257);
			if (hdist == 0 && codeLengths[hlit+257] == 0)
			{
				if (hlit != 0)	// a single zero distance code length means all literals
					throw BadBlockErr();
			}
			else
				m_distanceDecoder.Initialize(codeLengths+hlit+257, hdist+1);
			m_nextDecode = LITERAL;
		}
		catch (HuffmanDecoder::Err &)
		{
			throw BadBlockErr();
		}
		break;
		}
	default:
		throw BadBlockErr();	// reserved block type
	}
	m_state = DECODING_BODY;
}

bool Inflator::DecodeBody()
{
	bool blockEnd = false;
	switch (m_blockType)
	{
	case 0:	// stored
		assert(m_reader.BitsBuffered() == 0);
		while (!m_inQueue.IsEmpty() && !blockEnd)
		{
			unsigned int size;
			const byte *block = m_inQueue.Spy(size);
			size = STDMIN(size, (unsigned int)m_storedLen);
			OutputString(block, size);
			m_inQueue.Skip(size);
			m_storedLen -= size;
			if (m_storedLen == 0)
				blockEnd = true;
		}
		break;
	case 1:	// fixed codes
	case 2:	// dynamic codes
		static const unsigned int lengthStarts[] = {
			3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
			35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
		static const unsigned int lengthExtraBits[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
			3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
		static const unsigned int distanceStarts[] = {
			1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
			257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
			8193, 12289, 16385, 24577};
		static const unsigned int distanceExtraBits[] = {
			0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
			7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
			12, 12, 13, 13};

		switch (m_nextDecode)
		{
			while (true)
			{
		case LITERAL:
				if (!m_literalDecoder.Decode(m_reader, m_literal))
				{
					m_nextDecode = LITERAL;
					break;
				}
				if (m_literal < 256)
					OutputByte((byte)m_literal);
				else if (m_literal == 256)	// end of block
				{
					blockEnd = true;
					break;
				}
				else
				{
					if (m_literal > 285)
						throw BadBlockErr();
					unsigned int bits;
		case LENGTH_BITS:
					bits = lengthExtraBits[m_literal-257];
					if (!m_reader.FillBuffer(bits))
					{
						m_nextDecode = LENGTH_BITS;
						break;
					}
					m_literal = m_reader.GetBits(bits) + lengthStarts[m_literal-257];
		case DISTANCE:
					if (!m_distanceDecoder.Decode(m_reader, m_distance))
					{
						m_nextDecode = DISTANCE;
						break;
					}
		case DISTANCE_BITS:
					bits = distanceExtraBits[m_distance];
					if (!m_reader.FillBuffer(bits))
					{
						m_nextDecode = DISTANCE_BITS;
						break;
					}
					m_distance = m_reader.GetBits(bits) + distanceStarts[m_distance];
					OutputPast(m_literal, m_distance);
				}
			}
		}
	}
	if (blockEnd)
	{
		if (m_eof)
		{
			FlushOutput();
			m_reader.SkipBits(m_reader.BitsBuffered()%8);
			if (m_reader.BitsBuffered())
			{
				// undo too much lookahead
				SecByteBlock buffer(m_reader.BitsBuffered() / 8);
				for (unsigned int i=0; i<buffer.size; i++)
					buffer[i] = m_reader.GetBits(8);
				m_inQueue.Unget(buffer, buffer.size);
			}
			m_state = POST_STREAM;
		}
		else
			m_state = WAIT_HEADER;
	}
	return blockEnd;
}

void Inflator::FlushOutput()
{
	assert(m_current >= m_lastFlush);
	ProcessDecompressedData(m_window + m_lastFlush, m_current - m_lastFlush);
	m_lastFlush = m_current;
}

NAMESPACE_END
