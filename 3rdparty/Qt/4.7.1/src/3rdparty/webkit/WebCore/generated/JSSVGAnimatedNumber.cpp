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

#include "JSSVGAnimatedNumber.h"

#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGAnimatedNumber);

/* Hash table */

static const HashTableValue JSSVGAnimatedNumberTableValues[4] =
{
    { "baseVal", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGAnimatedNumberBaseVal), (intptr_t)setJSSVGAnimatedNumberBaseVal },
    { "animVal", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGAnimatedNumberAnimVal), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGAnimatedNumberConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedNumberTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSSVGAnimatedNumberTableValues, 0 };
#else
    { 8, 7, JSSVGAnimatedNumberTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGAnimatedNumberConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedNumberConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGAnimatedNumberConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGAnimatedNumberConstructorTableValues, 0 };
#endif

class JSSVGAnimatedNumberConstructor : public DOMConstructorObject {
public:
    JSSVGAnimatedNumberConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGAnimatedNumberConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGAnimatedNumberPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGAnimatedNumberConstructor::s_info = { "SVGAnimatedNumberConstructor", 0, &JSSVGAnimatedNumberConstructorTable, 0 };

bool JSSVGAnimatedNumberConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGAnimatedNumberConstructor, DOMObject>(exec, &JSSVGAnimatedNumberConstructorTable, this, propertyName, slot);
}

bool JSSVGAnimatedNumberConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGAnimatedNumberConstructor, DOMObject>(exec, &JSSVGAnimatedNumberConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGAnimatedNumberPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGAnimatedNumberPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGAnimatedNumberPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGAnimatedNumberPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGAnimatedNumberPrototype::s_info = { "SVGAnimatedNumberPrototype", 0, &JSSVGAnimatedNumberPrototypeTable, 0 };

JSObject* JSSVGAnimatedNumberPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGAnimatedNumber>(exec, globalObject);
}

const ClassInfo JSSVGAnimatedNumber::s_info = { "SVGAnimatedNumber", 0, &JSSVGAnimatedNumberTable, 0 };

JSSVGAnimatedNumber::JSSVGAnimatedNumber(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGAnimatedNumber> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSSVGAnimatedNumber::~JSSVGAnimatedNumber()
{
    forgetDOMObject(this, impl());
    JSSVGContextCache::forgetWrapper(this);
}

JSObject* JSSVGAnimatedNumber::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGAnimatedNumberPrototype(JSSVGAnimatedNumberPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSSVGAnimatedNumber::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGAnimatedNumber, Base>(exec, &JSSVGAnimatedNumberTable, this, propertyName, slot);
}

bool JSSVGAnimatedNumber::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGAnimatedNumber, Base>(exec, &JSSVGAnimatedNumberTable, this, propertyName, descriptor);
}

JSValue jsSVGAnimatedNumberBaseVal(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGAnimatedNumber* castedThis = static_cast<JSSVGAnimatedNumber*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGAnimatedNumber* imp = static_cast<SVGAnimatedNumber*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->baseVal());
    return result;
}

JSValue jsSVGAnimatedNumberAnimVal(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGAnimatedNumber* castedThis = static_cast<JSSVGAnimatedNumber*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGAnimatedNumber* imp = static_cast<SVGAnimatedNumber*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->animVal());
    return result;
}

JSValue jsSVGAnimatedNumberConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGAnimatedNumber* domObject = static_cast<JSSVGAnimatedNumber*>(asObject(slotBase));
    return JSSVGAnimatedNumber::getConstructor(exec, domObject->globalObject());
}
void JSSVGAnimatedNumber::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGAnimatedNumber, Base>(exec, propertyName, value, &JSSVGAnimatedNumberTable, this, slot);
}

void setJSSVGAnimatedNumberBaseVal(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGAnimatedNumber* castedThisObj = static_cast<JSSVGAnimatedNumber*>(thisObject);
    SVGAnimatedNumber* imp = static_cast<SVGAnimatedNumber*>(castedThisObj->impl());
    imp->setBaseVal(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

JSValue JSSVGAnimatedNumber::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGAnimatedNumberConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SVGAnimatedNumber* object, SVGElement* context)
{
    return getDOMObjectWrapper<JSSVGAnimatedNumber>(exec, globalObject, object, context);
}
SVGAnimatedNumber* toSVGAnimatedNumber(JSC::JSValue value)
{
    return value.inherits(&JSSVGAnimatedNumber::s_info) ? static_cast<JSSVGAnimatedNumber*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SVG)
