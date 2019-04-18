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

#if ENABLE(SVG)

#include "JSSVGElementWrapperFactory.h"
#include "JSSVGAElement.h"
#include "JSSVGAltGlyphElement.h"
#include "JSSVGAnimateElement.h"
#include "JSSVGAnimateColorElement.h"
#include "JSSVGAnimateTransformElement.h"
#include "JSSVGCircleElement.h"
#include "JSSVGClipPathElement.h"
#include "JSSVGCursorElement.h"
#include "JSSVGDefsElement.h"
#include "JSSVGDescElement.h"
#include "JSSVGEllipseElement.h"
#include "JSSVGFEBlendElement.h"
#include "JSSVGFEColorMatrixElement.h"
#include "JSSVGFEComponentTransferElement.h"
#include "JSSVGFECompositeElement.h"
#include "JSSVGFEDiffuseLightingElement.h"
#include "JSSVGFEDisplacementMapElement.h"
#include "JSSVGFEDistantLightElement.h"
#include "JSSVGFEFloodElement.h"
#include "JSSVGFEFuncAElement.h"
#include "JSSVGFEFuncBElement.h"
#include "JSSVGFEFuncGElement.h"
#include "JSSVGFEFuncRElement.h"
#include "JSSVGFEGaussianBlurElement.h"
#include "JSSVGFEImageElement.h"
#include "JSSVGFEMergeElement.h"
#include "JSSVGFEMergeNodeElement.h"
#include "JSSVGFEMorphologyElement.h"
#include "JSSVGFEOffsetElement.h"
#include "JSSVGFEPointLightElement.h"
#include "JSSVGFESpecularLightingElement.h"
#include "JSSVGFESpotLightElement.h"
#include "JSSVGFETileElement.h"
#include "JSSVGFETurbulenceElement.h"
#include "JSSVGFilterElement.h"
#include "JSSVGFontElement.h"
#include "JSSVGFontFaceElement.h"
#include "JSSVGFontFaceFormatElement.h"
#include "JSSVGFontFaceNameElement.h"
#include "JSSVGFontFaceSrcElement.h"
#include "JSSVGFontFaceUriElement.h"
#include "JSSVGForeignObjectElement.h"
#include "JSSVGGElement.h"
#include "JSSVGGlyphElement.h"
#include "JSSVGImageElement.h"
#include "JSSVGLineElement.h"
#include "JSSVGLinearGradientElement.h"
#include "JSSVGMarkerElement.h"
#include "JSSVGMaskElement.h"
#include "JSSVGMetadataElement.h"
#include "JSSVGMissingGlyphElement.h"
#include "JSSVGPathElement.h"
#include "JSSVGPatternElement.h"
#include "JSSVGPolygonElement.h"
#include "JSSVGPolylineElement.h"
#include "JSSVGRadialGradientElement.h"
#include "JSSVGRectElement.h"
#include "JSSVGScriptElement.h"
#include "JSSVGSetElement.h"
#include "JSSVGStopElement.h"
#include "JSSVGStyleElement.h"
#include "JSSVGSVGElement.h"
#include "JSSVGSwitchElement.h"
#include "JSSVGSymbolElement.h"
#include "JSSVGTextElement.h"
#include "JSSVGTextPathElement.h"
#include "JSSVGTitleElement.h"
#include "JSSVGTRefElement.h"
#include "JSSVGTSpanElement.h"
#include "JSSVGUseElement.h"
#include "JSSVGViewElement.h"

#include "SVGNames.h"

#include "SVGAElement.h"
#include "SVGAltGlyphElement.h"
#include "SVGAnimateElement.h"
#include "SVGAnimateColorElement.h"
#include "SVGAnimateMotionElement.h"
#include "SVGAnimateTransformElement.h"
#include "SVGCircleElement.h"
#include "SVGClipPathElement.h"
#include "SVGCursorElement.h"
#include "SVGDefsElement.h"
#include "SVGDescElement.h"
#include "SVGEllipseElement.h"
#include "SVGFEBlendElement.h"
#include "SVGFEColorMatrixElement.h"
#include "SVGFEComponentTransferElement.h"
#include "SVGFECompositeElement.h"
#include "SVGFEDiffuseLightingElement.h"
#include "SVGFEDisplacementMapElement.h"
#include "SVGFEDistantLightElement.h"
#include "SVGFEFloodElement.h"
#include "SVGFEFuncAElement.h"
#include "SVGFEFuncBElement.h"
#include "SVGFEFuncGElement.h"
#include "SVGFEFuncRElement.h"
#include "SVGFEGaussianBlurElement.h"
#include "SVGFEImageElement.h"
#include "SVGFEMergeElement.h"
#include "SVGFEMergeNodeElement.h"
#include "SVGFEMorphologyElement.h"
#include "SVGFEOffsetElement.h"
#include "SVGFEPointLightElement.h"
#include "SVGFESpecularLightingElement.h"
#include "SVGFESpotLightElement.h"
#include "SVGFETileElement.h"
#include "SVGFETurbulenceElement.h"
#include "SVGFilterElement.h"
#include "SVGFontElement.h"
#include "SVGFontFaceElement.h"
#include "SVGFontFaceFormatElement.h"
#include "SVGFontFaceNameElement.h"
#include "SVGFontFaceSrcElement.h"
#include "SVGFontFaceUriElement.h"
#include "SVGForeignObjectElement.h"
#include "SVGGElement.h"
#include "SVGGlyphElement.h"
#include "SVGHKernElement.h"
#include "SVGImageElement.h"
#include "SVGLineElement.h"
#include "SVGLinearGradientElement.h"
#include "SVGMarkerElement.h"
#include "SVGMaskElement.h"
#include "SVGMetadataElement.h"
#include "SVGMissingGlyphElement.h"
#include "SVGMPathElement.h"
#include "SVGPathElement.h"
#include "SVGPatternElement.h"
#include "SVGPolygonElement.h"
#include "SVGPolylineElement.h"
#include "SVGRadialGradientElement.h"
#include "SVGRectElement.h"
#include "SVGScriptElement.h"
#include "SVGSetElement.h"
#include "SVGStopElement.h"
#include "SVGStyleElement.h"
#include "SVGSVGElement.h"
#include "SVGSwitchElement.h"
#include "SVGSymbolElement.h"
#include "SVGTextElement.h"
#include "SVGTextPathElement.h"
#include "SVGTitleElement.h"
#include "SVGTRefElement.h"
#include "SVGTSpanElement.h"
#include "SVGUseElement.h"
#include "SVGViewElement.h"

#include <wtf/StdLibExtras.h>

using namespace JSC;

namespace WebCore {

using namespace SVGNames;

typedef JSNode* (*CreateSVGElementWrapperFunction)(ExecState*, JSDOMGlobalObject*, PassRefPtr<SVGElement>);

static JSNode* createSVGAElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGAElement, element.get());
}

static JSNode* createSVGAltGlyphElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGAltGlyphElement, element.get());
}

static JSNode* createSVGAnimateElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGAnimateElement, element.get());
}

static JSNode* createSVGAnimateColorElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGAnimateColorElement, element.get());
}

static JSNode* createSVGAnimateTransformElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGAnimateTransformElement, element.get());
}

static JSNode* createSVGCircleElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGCircleElement, element.get());
}

static JSNode* createSVGClipPathElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGClipPathElement, element.get());
}

static JSNode* createSVGCursorElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGCursorElement, element.get());
}

static JSNode* createSVGDefsElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGDefsElement, element.get());
}

static JSNode* createSVGDescElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGDescElement, element.get());
}

static JSNode* createSVGEllipseElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGEllipseElement, element.get());
}

static JSNode* createSVGFEBlendElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEBlendElement, element.get());
}

static JSNode* createSVGFEColorMatrixElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEColorMatrixElement, element.get());
}

static JSNode* createSVGFEComponentTransferElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEComponentTransferElement, element.get());
}

static JSNode* createSVGFECompositeElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFECompositeElement, element.get());
}

static JSNode* createSVGFEDiffuseLightingElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEDiffuseLightingElement, element.get());
}

static JSNode* createSVGFEDisplacementMapElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEDisplacementMapElement, element.get());
}

static JSNode* createSVGFEDistantLightElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEDistantLightElement, element.get());
}

static JSNode* createSVGFEFloodElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEFloodElement, element.get());
}

static JSNode* createSVGFEFuncAElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEFuncAElement, element.get());
}

static JSNode* createSVGFEFuncBElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEFuncBElement, element.get());
}

static JSNode* createSVGFEFuncGElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEFuncGElement, element.get());
}

static JSNode* createSVGFEFuncRElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEFuncRElement, element.get());
}

static JSNode* createSVGFEGaussianBlurElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEGaussianBlurElement, element.get());
}

static JSNode* createSVGFEImageElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEImageElement, element.get());
}

static JSNode* createSVGFEMergeElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEMergeElement, element.get());
}

static JSNode* createSVGFEMergeNodeElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEMergeNodeElement, element.get());
}

static JSNode* createSVGFEMorphologyElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEMorphologyElement, element.get());
}

static JSNode* createSVGFEOffsetElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEOffsetElement, element.get());
}

static JSNode* createSVGFEPointLightElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFEPointLightElement, element.get());
}

static JSNode* createSVGFESpecularLightingElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFESpecularLightingElement, element.get());
}

static JSNode* createSVGFESpotLightElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFESpotLightElement, element.get());
}

static JSNode* createSVGFETileElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFETileElement, element.get());
}

static JSNode* createSVGFETurbulenceElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFETurbulenceElement, element.get());
}

static JSNode* createSVGFilterElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFilterElement, element.get());
}

static JSNode* createSVGFontElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontElement, element.get());
}

static JSNode* createSVGFontFaceElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontFaceElement, element.get());
}

static JSNode* createSVGFontFaceFormatElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontFaceFormatElement, element.get());
}

static JSNode* createSVGFontFaceNameElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontFaceNameElement, element.get());
}

static JSNode* createSVGFontFaceSrcElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontFaceSrcElement, element.get());
}

static JSNode* createSVGFontFaceUriElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGFontFaceUriElement, element.get());
}

static JSNode* createSVGForeignObjectElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGForeignObjectElement, element.get());
}

static JSNode* createSVGGElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGGElement, element.get());
}

static JSNode* createSVGGlyphElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGGlyphElement, element.get());
}

static JSNode* createSVGImageElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGImageElement, element.get());
}

static JSNode* createSVGLineElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGLineElement, element.get());
}

static JSNode* createSVGLinearGradientElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGLinearGradientElement, element.get());
}

static JSNode* createSVGMarkerElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGMarkerElement, element.get());
}

static JSNode* createSVGMaskElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGMaskElement, element.get());
}

static JSNode* createSVGMetadataElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGMetadataElement, element.get());
}

static JSNode* createSVGMissingGlyphElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGMissingGlyphElement, element.get());
}

static JSNode* createSVGPathElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGPathElement, element.get());
}

static JSNode* createSVGPatternElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGPatternElement, element.get());
}

static JSNode* createSVGPolygonElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGPolygonElement, element.get());
}

static JSNode* createSVGPolylineElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGPolylineElement, element.get());
}

static JSNode* createSVGRadialGradientElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGRadialGradientElement, element.get());
}

static JSNode* createSVGRectElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGRectElement, element.get());
}

static JSNode* createSVGScriptElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGScriptElement, element.get());
}

static JSNode* createSVGSetElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGSetElement, element.get());
}

static JSNode* createSVGStopElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGStopElement, element.get());
}

static JSNode* createSVGStyleElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGStyleElement, element.get());
}

static JSNode* createSVGSVGElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGSVGElement, element.get());
}

static JSNode* createSVGSwitchElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGSwitchElement, element.get());
}

static JSNode* createSVGSymbolElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGSymbolElement, element.get());
}

static JSNode* createSVGTextElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGTextElement, element.get());
}

static JSNode* createSVGTextPathElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGTextPathElement, element.get());
}

static JSNode* createSVGTitleElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGTitleElement, element.get());
}

static JSNode* createSVGTRefElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGTRefElement, element.get());
}

static JSNode* createSVGTSpanElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGTSpanElement, element.get());
}

static JSNode* createSVGUseElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGUseElement, element.get());
}

static JSNode* createSVGViewElementWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGViewElement, element.get());
}

JSNode* createJSSVGWrapper(ExecState* exec, JSDOMGlobalObject* globalObject, PassRefPtr<SVGElement> element)
{
    typedef HashMap<WebCore::AtomicStringImpl*, CreateSVGElementWrapperFunction> FunctionMap;
    DEFINE_STATIC_LOCAL(FunctionMap, map, ());
    if (map.isEmpty()) {
       map.set(aTag.localName().impl(), createSVGAElementWrapper);
       map.set(altGlyphTag.localName().impl(), createSVGAltGlyphElementWrapper);
       map.set(animateTag.localName().impl(), createSVGAnimateElementWrapper);
       map.set(animateColorTag.localName().impl(), createSVGAnimateColorElementWrapper);
       map.set(animateTransformTag.localName().impl(), createSVGAnimateTransformElementWrapper);
       map.set(circleTag.localName().impl(), createSVGCircleElementWrapper);
       map.set(clipPathTag.localName().impl(), createSVGClipPathElementWrapper);
       map.set(cursorTag.localName().impl(), createSVGCursorElementWrapper);
       map.set(defsTag.localName().impl(), createSVGDefsElementWrapper);
       map.set(descTag.localName().impl(), createSVGDescElementWrapper);
       map.set(ellipseTag.localName().impl(), createSVGEllipseElementWrapper);
       map.set(feBlendTag.localName().impl(), createSVGFEBlendElementWrapper);
       map.set(feColorMatrixTag.localName().impl(), createSVGFEColorMatrixElementWrapper);
       map.set(feComponentTransferTag.localName().impl(), createSVGFEComponentTransferElementWrapper);
       map.set(feCompositeTag.localName().impl(), createSVGFECompositeElementWrapper);
       map.set(feDiffuseLightingTag.localName().impl(), createSVGFEDiffuseLightingElementWrapper);
       map.set(feDisplacementMapTag.localName().impl(), createSVGFEDisplacementMapElementWrapper);
       map.set(feDistantLightTag.localName().impl(), createSVGFEDistantLightElementWrapper);
       map.set(feFloodTag.localName().impl(), createSVGFEFloodElementWrapper);
       map.set(feFuncATag.localName().impl(), createSVGFEFuncAElementWrapper);
       map.set(feFuncBTag.localName().impl(), createSVGFEFuncBElementWrapper);
       map.set(feFuncGTag.localName().impl(), createSVGFEFuncGElementWrapper);
       map.set(feFuncRTag.localName().impl(), createSVGFEFuncRElementWrapper);
       map.set(feGaussianBlurTag.localName().impl(), createSVGFEGaussianBlurElementWrapper);
       map.set(feImageTag.localName().impl(), createSVGFEImageElementWrapper);
       map.set(feMergeTag.localName().impl(), createSVGFEMergeElementWrapper);
       map.set(feMergeNodeTag.localName().impl(), createSVGFEMergeNodeElementWrapper);
       map.set(feMorphologyTag.localName().impl(), createSVGFEMorphologyElementWrapper);
       map.set(feOffsetTag.localName().impl(), createSVGFEOffsetElementWrapper);
       map.set(fePointLightTag.localName().impl(), createSVGFEPointLightElementWrapper);
       map.set(feSpecularLightingTag.localName().impl(), createSVGFESpecularLightingElementWrapper);
       map.set(feSpotLightTag.localName().impl(), createSVGFESpotLightElementWrapper);
       map.set(feTileTag.localName().impl(), createSVGFETileElementWrapper);
       map.set(feTurbulenceTag.localName().impl(), createSVGFETurbulenceElementWrapper);
       map.set(filterTag.localName().impl(), createSVGFilterElementWrapper);
       map.set(fontTag.localName().impl(), createSVGFontElementWrapper);
       map.set(font_faceTag.localName().impl(), createSVGFontFaceElementWrapper);
       map.set(font_face_formatTag.localName().impl(), createSVGFontFaceFormatElementWrapper);
       map.set(font_face_nameTag.localName().impl(), createSVGFontFaceNameElementWrapper);
       map.set(font_face_srcTag.localName().impl(), createSVGFontFaceSrcElementWrapper);
       map.set(font_face_uriTag.localName().impl(), createSVGFontFaceUriElementWrapper);
       map.set(foreignObjectTag.localName().impl(), createSVGForeignObjectElementWrapper);
       map.set(gTag.localName().impl(), createSVGGElementWrapper);
       map.set(glyphTag.localName().impl(), createSVGGlyphElementWrapper);
       map.set(imageTag.localName().impl(), createSVGImageElementWrapper);
       map.set(lineTag.localName().impl(), createSVGLineElementWrapper);
       map.set(linearGradientTag.localName().impl(), createSVGLinearGradientElementWrapper);
       map.set(markerTag.localName().impl(), createSVGMarkerElementWrapper);
       map.set(maskTag.localName().impl(), createSVGMaskElementWrapper);
       map.set(metadataTag.localName().impl(), createSVGMetadataElementWrapper);
       map.set(missing_glyphTag.localName().impl(), createSVGMissingGlyphElementWrapper);
       map.set(pathTag.localName().impl(), createSVGPathElementWrapper);
       map.set(patternTag.localName().impl(), createSVGPatternElementWrapper);
       map.set(polygonTag.localName().impl(), createSVGPolygonElementWrapper);
       map.set(polylineTag.localName().impl(), createSVGPolylineElementWrapper);
       map.set(radialGradientTag.localName().impl(), createSVGRadialGradientElementWrapper);
       map.set(rectTag.localName().impl(), createSVGRectElementWrapper);
       map.set(scriptTag.localName().impl(), createSVGScriptElementWrapper);
       map.set(setTag.localName().impl(), createSVGSetElementWrapper);
       map.set(stopTag.localName().impl(), createSVGStopElementWrapper);
       map.set(styleTag.localName().impl(), createSVGStyleElementWrapper);
       map.set(svgTag.localName().impl(), createSVGSVGElementWrapper);
       map.set(switchTag.localName().impl(), createSVGSwitchElementWrapper);
       map.set(symbolTag.localName().impl(), createSVGSymbolElementWrapper);
       map.set(textTag.localName().impl(), createSVGTextElementWrapper);
       map.set(textPathTag.localName().impl(), createSVGTextPathElementWrapper);
       map.set(titleTag.localName().impl(), createSVGTitleElementWrapper);
       map.set(trefTag.localName().impl(), createSVGTRefElementWrapper);
       map.set(tspanTag.localName().impl(), createSVGTSpanElementWrapper);
       map.set(useTag.localName().impl(), createSVGUseElementWrapper);
       map.set(viewTag.localName().impl(), createSVGViewElementWrapper);
    }
    CreateSVGElementWrapperFunction createWrapperFunction = map.get(element->localName().impl());
    if (createWrapperFunction)
        return createWrapperFunction(exec, globalObject, element);
    return CREATE_DOM_NODE_WRAPPER(exec, globalObject, SVGElement, element.get());
}

}

#endif
