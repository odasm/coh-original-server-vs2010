/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * This file was generated by the dom/make_names.pl script.
 *
 * Copyright (C) 2005, 2006, 2007, 2008, 2009 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#ifdef SKIP_STATIC_CONSTRUCTORS_ON_GCC
#define DOM_XMLNAMES_HIDE_GLOBALS 1
#else
#define QNAME_DEFAULT_CONSTRUCTOR 1
#endif

#include "XMLNames.h"

#include "StaticConstructors.h"
namespace WebCore {

 namespace XMLNames {

using namespace WebCore;

DEFINE_GLOBAL(AtomicString, xmlNamespaceURI, "http://www.w3.org/XML/1998/namespace")

// Attributes
DEFINE_GLOBAL(QualifiedName, baseAttr, nullAtom, "base", xmlNamespaceURI);
DEFINE_GLOBAL(QualifiedName, langAttr, nullAtom, "lang", xmlNamespaceURI);
DEFINE_GLOBAL(QualifiedName, spaceAttr, nullAtom, "space", xmlNamespaceURI);


WebCore::QualifiedName** getXMLAttrs(size_t* size)
{
    static WebCore::QualifiedName* XMLAttr[] = {
        (WebCore::QualifiedName*)&baseAttr,
        (WebCore::QualifiedName*)&langAttr,
        (WebCore::QualifiedName*)&spaceAttr,
    };
    *size = 3;
    return XMLAttr;
}

void init()
{
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    
    // Use placement new to initialize the globals.
    
    AtomicString::init();
    AtomicString xmlNS("http://www.w3.org/XML/1998/namespace");

    // Namespace
    new ((void*)&xmlNamespaceURI) AtomicString(xmlNS);

    // Attributes
    new ((void*)&baseAttr) QualifiedName(nullAtom, "base", xmlNS);
    new ((void*)&langAttr) QualifiedName(nullAtom, "lang", xmlNS);
    new ((void*)&spaceAttr) QualifiedName(nullAtom, "space", xmlNS);
}

} }

