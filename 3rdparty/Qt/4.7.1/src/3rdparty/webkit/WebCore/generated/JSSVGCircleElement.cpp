/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(SVG)

#include "JSSVGCircleElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSSVGAnimatedBoolean.h"
#include "JSSVGAnimatedLength.h"
#include "JSSVGAnimatedString.h"
#include "JSSVGAnimatedTransformList.h"
#include "JSSVGElement.h"
#include "JSSVGMatrix.h"
#include "JSSVGRect.h"
#include "JSSVGStringList.h"
#include "KURL.h"
#include "SVGCircleElement.h"
#include "SVGElement.h"
#include "SVGStringList.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGCircleElement);

/* Hash table */

static const HashTableValue JSSVGCircleElementTableValues[16] =
{
    { "cx", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementCx), (intptr_t)0 },
    { "cy", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementCy), (intptr_t)0 },
    { "r", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementR), (intptr_t)0 },
    { "requiredFeatures", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementRequiredFeatures), (intptr_t)0 },
    { "requiredExtensions", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementRequiredExtensions), (intptr_t)0 },
    { "systemLanguage", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementSystemLanguage), (intptr_t)0 },
    { "xmllang", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementXmllang), (intptr_t)setJSSVGCircleElementXmllang },
    { "xmlspace", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementXmlspace), (intptr_t)setJSSVGCircleElementXmlspace },
    { "externalResourcesRequired", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementExternalResourcesRequired), (intptr_t)0 },
    { "className", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementClassName), (intptr_t)0 },
    { "style", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementStyle), (intptr_t)0 },
    { "transform", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementTransform), (intptr_t)0 },
    { "nearestViewportElement", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementNearestViewportElement), (intptr_t)0 },
    { "farthestViewportElement", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementFarthestViewportElement), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGCircleElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGCircleElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSSVGCircleElementTableValues, 0 };
#else
    { 35, 31, JSSVGCircleElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGCircleElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGCircleElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGCircleElementConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGCircleElementConstructorTableValues, 0 };
#endif

class JSSVGCircleElementConstructor : public DOMConstructorObject {
public:
    JSSVGCircleElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGCircleElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGCircleElementPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSSVGCircleElementConstructor::s_info = { "SVGCircleElementConstructor", 0, &JSSVGCircleElementConstructorTable, 0 };

bool JSSVGCircleElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGCircleElementConstructor, DOMObject>(exec, &JSSVGCircleElementConstructorTable, this, propertyName, slot);
}

bool JSSVGCircleElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGCircleElementConstructor, DOMObject>(exec, &JSSVGCircleElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGCircleElementPrototypeTableValues[7] =
{
    { "hasExtension", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionHasExtension), (intptr_t)1 },
    { "getPresentationAttribute", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionGetPresentationAttribute), (intptr_t)1 },
    { "getBBox", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionGetBBox), (intptr_t)0 },
    { "getCTM", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionGetCTM), (intptr_t)0 },
    { "getScreenCTM", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionGetScreenCTM), (intptr_t)0 },
    { "getTransformToElement", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGCircleElementPrototypeFunctionGetTransformToElement), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGCircleElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 2047, JSSVGCircleElementPrototypeTableValues, 0 };
#else
    { 17, 15, JSSVGCircleElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGCircleElementPrototype::s_info = { "SVGCircleElementPrototype", 0, &JSSVGCircleElementPrototypeTable, 0 };

JSObject* JSSVGCircleElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGCircleElement>(exec, globalObject);
}

bool JSSVGCircleElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGCircleElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGCircleElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGCircleElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGCircleElement::s_info = { "SVGCircleElement", &JSSVGElement::s_info, &JSSVGCircleElementTable, 0 };

JSSVGCircleElement::JSSVGCircleElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGCircleElement> impl)
    : JSSVGElement(structure, globalObject, impl)
{
}

JSObject* JSSVGCircleElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGCircleElementPrototype(JSSVGCircleElementPrototype::createStructure(JSSVGElementPrototype::self(exec, globalObject)));
}

bool JSSVGCircleElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGCircleElement, Base>(exec, &JSSVGCircleElementTable, this, propertyName, slot);
}

bool JSSVGCircleElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGCircleElement, Base>(exec, &JSSVGCircleElementTable, this, propertyName, descriptor);
}

JSValue jsSVGCircleElementCx(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->cxAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementCy(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->cyAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementR(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->rAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementRequiredFeatures(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredFeatures()), imp);
    return result;
}

JSValue jsSVGCircleElementRequiredExtensions(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredExtensions()), imp);
    return result;
}

JSValue jsSVGCircleElementSystemLanguage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->systemLanguage()), imp);
    return result;
}

JSValue jsSVGCircleElementXmllang(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->xmllang());
    return result;
}

JSValue jsSVGCircleElementXmlspace(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->xmlspace());
    return result;
}

JSValue jsSVGCircleElementExternalResourcesRequired(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedBoolean> obj = imp->externalResourcesRequiredAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementClassName(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementStyle(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->style()));
    return result;
}

JSValue jsSVGCircleElementTransform(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    RefPtr<SVGAnimatedTransformList> obj = imp->transformAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGCircleElementNearestViewportElement(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->nearestViewportElement()));
    return result;
}

JSValue jsSVGCircleElementFarthestViewportElement(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* castedThis = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->farthestViewportElement()));
    return result;
}

JSValue jsSVGCircleElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGCircleElement* domObject = static_cast<JSSVGCircleElement*>(asObject(slotBase));
    return JSSVGCircleElement::getConstructor(exec, domObject->globalObject());
}
void JSSVGCircleElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGCircleElement, Base>(exec, propertyName, value, &JSSVGCircleElementTable, this, slot);
}

void setJSSVGCircleElementXmllang(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(thisObject);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());
    imp->setXmllang(value.toString(exec));
}

void setJSSVGCircleElementXmlspace(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(thisObject);
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());
    imp->setXmlspace(value.toString(exec));
}

JSValue JSSVGCircleElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGCircleElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionHasExtension(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());
    const UString& extension = args.at(0).toString(exec);


    JSC::JSValue result = jsBoolean(imp->hasExtension(extension));
    return result;
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionGetPresentationAttribute(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());
    const UString& name = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getPresentationAttribute(name)));
    return result;
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionGetBBox(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatRect>::create(imp->getBBox()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionGetCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getCTM()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionGetScreenCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getScreenCTM()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGCircleElementPrototypeFunctionGetTransformToElement(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGCircleElement::s_info))
        return throwError(exec, TypeError);
    JSSVGCircleElement* castedThisObj = static_cast<JSSVGCircleElement*>(asObject(thisValue));
    SVGCircleElement* imp = static_cast<SVGCircleElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    SVGElement* element = toSVGElement(args.at(0));


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getTransformToElement(element, ec)).get(), 0 /* no context on purpose */);
    setDOMException(exec, ec);
    return result;
}


}

#endif // ENABLE(SVG)
