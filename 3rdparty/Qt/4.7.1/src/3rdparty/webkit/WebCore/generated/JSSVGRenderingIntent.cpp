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

#include "JSSVGRenderingIntent.h"

#include "SVGRenderingIntent.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGRenderingIntent);

/* Hash table */

static const HashTableValue JSSVGRenderingIntentTableValues[2] =
{
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGRenderingIntentTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGRenderingIntentTableValues, 0 };
#else
    { 2, 1, JSSVGRenderingIntentTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGRenderingIntentConstructorTableValues[7] =
{
    { "RENDERING_INTENT_UNKNOWN", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_UNKNOWN), (intptr_t)0 },
    { "RENDERING_INTENT_AUTO", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_AUTO), (intptr_t)0 },
    { "RENDERING_INTENT_PERCEPTUAL", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_PERCEPTUAL), (intptr_t)0 },
    { "RENDERING_INTENT_RELATIVE_COLORIMETRIC", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_RELATIVE_COLORIMETRIC), (intptr_t)0 },
    { "RENDERING_INTENT_SATURATION", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_SATURATION), (intptr_t)0 },
    { "RENDERING_INTENT_ABSOLUTE_COLORIMETRIC", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_ABSOLUTE_COLORIMETRIC), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGRenderingIntentConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGRenderingIntentConstructorTableValues, 0 };
#else
    { 16, 15, JSSVGRenderingIntentConstructorTableValues, 0 };
#endif

class JSSVGRenderingIntentConstructor : public DOMConstructorObject {
public:
    JSSVGRenderingIntentConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGRenderingIntentConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGRenderingIntentPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGRenderingIntentConstructor::s_info = { "SVGRenderingIntentConstructor", 0, &JSSVGRenderingIntentConstructorTable, 0 };

bool JSSVGRenderingIntentConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGRenderingIntentConstructor, DOMObject>(exec, &JSSVGRenderingIntentConstructorTable, this, propertyName, slot);
}

bool JSSVGRenderingIntentConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGRenderingIntentConstructor, DOMObject>(exec, &JSSVGRenderingIntentConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGRenderingIntentPrototypeTableValues[7] =
{
    { "RENDERING_INTENT_UNKNOWN", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_UNKNOWN), (intptr_t)0 },
    { "RENDERING_INTENT_AUTO", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_AUTO), (intptr_t)0 },
    { "RENDERING_INTENT_PERCEPTUAL", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_PERCEPTUAL), (intptr_t)0 },
    { "RENDERING_INTENT_RELATIVE_COLORIMETRIC", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_RELATIVE_COLORIMETRIC), (intptr_t)0 },
    { "RENDERING_INTENT_SATURATION", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_SATURATION), (intptr_t)0 },
    { "RENDERING_INTENT_ABSOLUTE_COLORIMETRIC", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGRenderingIntentRENDERING_INTENT_ABSOLUTE_COLORIMETRIC), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGRenderingIntentPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGRenderingIntentPrototypeTableValues, 0 };
#else
    { 16, 15, JSSVGRenderingIntentPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGRenderingIntentPrototype::s_info = { "SVGRenderingIntentPrototype", 0, &JSSVGRenderingIntentPrototypeTable, 0 };

JSObject* JSSVGRenderingIntentPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGRenderingIntent>(exec, globalObject);
}

bool JSSVGRenderingIntentPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGRenderingIntentPrototype, JSObject>(exec, &JSSVGRenderingIntentPrototypeTable, this, propertyName, slot);
}

bool JSSVGRenderingIntentPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGRenderingIntentPrototype, JSObject>(exec, &JSSVGRenderingIntentPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGRenderingIntent::s_info = { "SVGRenderingIntent", 0, &JSSVGRenderingIntentTable, 0 };

JSSVGRenderingIntent::JSSVGRenderingIntent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGRenderingIntent> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSSVGRenderingIntent::~JSSVGRenderingIntent()
{
    forgetDOMObject(this, impl());
    JSSVGContextCache::forgetWrapper(this);
}

JSObject* JSSVGRenderingIntent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGRenderingIntentPrototype(JSSVGRenderingIntentPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSSVGRenderingIntent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGRenderingIntent, Base>(exec, &JSSVGRenderingIntentTable, this, propertyName, slot);
}

bool JSSVGRenderingIntent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGRenderingIntent, Base>(exec, &JSSVGRenderingIntentTable, this, propertyName, descriptor);
}

JSValue jsSVGRenderingIntentConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGRenderingIntent* domObject = static_cast<JSSVGRenderingIntent*>(asObject(slotBase));
    return JSSVGRenderingIntent::getConstructor(exec, domObject->globalObject());
}
JSValue JSSVGRenderingIntent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGRenderingIntentConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

// Constant getters

JSValue jsSVGRenderingIntentRENDERING_INTENT_UNKNOWN(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsSVGRenderingIntentRENDERING_INTENT_AUTO(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsSVGRenderingIntentRENDERING_INTENT_PERCEPTUAL(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsSVGRenderingIntentRENDERING_INTENT_RELATIVE_COLORIMETRIC(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(3));
}

JSValue jsSVGRenderingIntentRENDERING_INTENT_SATURATION(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(4));
}

JSValue jsSVGRenderingIntentRENDERING_INTENT_ABSOLUTE_COLORIMETRIC(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(5));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, SVGRenderingIntent* object, SVGElement* context)
{
    return getDOMObjectWrapper<JSSVGRenderingIntent>(exec, globalObject, object, context);
}
SVGRenderingIntent* toSVGRenderingIntent(JSC::JSValue value)
{
    return value.inherits(&JSSVGRenderingIntent::s_info) ? static_cast<JSSVGRenderingIntent*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(SVG)
