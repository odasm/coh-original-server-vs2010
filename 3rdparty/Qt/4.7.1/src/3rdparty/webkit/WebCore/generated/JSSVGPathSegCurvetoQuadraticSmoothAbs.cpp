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

#include "JSSVGPathSegCurvetoQuadraticSmoothAbs.h"

#include "SVGPathSegCurvetoQuadraticSmooth.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGPathSegCurvetoQuadraticSmoothAbs);

/* Hash table */

static const HashTableValue JSSVGPathSegCurvetoQuadraticSmoothAbsTableValues[4] =
{
    { "x", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticSmoothAbsX), (intptr_t)setJSSVGPathSegCurvetoQuadraticSmoothAbsX },
    { "y", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticSmoothAbsY), (intptr_t)setJSSVGPathSegCurvetoQuadraticSmoothAbsY },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticSmoothAbsConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticSmoothAbsTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGPathSegCurvetoQuadraticSmoothAbsTableValues, 0 };
#else
    { 9, 7, JSSVGPathSegCurvetoQuadraticSmoothAbsTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTableValues, 0 };
#endif

class JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor : public DOMConstructorObject {
public:
    JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGPathSegCurvetoQuadraticSmoothAbsPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor::s_info = { "SVGPathSegCurvetoQuadraticSmoothAbsConstructor", 0, &JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTable, 0 };

bool JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor, DOMObject>(exec, &JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTable, this, propertyName, slot);
}

bool JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor, DOMObject>(exec, &JSSVGPathSegCurvetoQuadraticSmoothAbsConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGPathSegCurvetoQuadraticSmoothAbsPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticSmoothAbsPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGPathSegCurvetoQuadraticSmoothAbsPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGPathSegCurvetoQuadraticSmoothAbsPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGPathSegCurvetoQuadraticSmoothAbsPrototype::s_info = { "SVGPathSegCurvetoQuadraticSmoothAbsPrototype", 0, &JSSVGPathSegCurvetoQuadraticSmoothAbsPrototypeTable, 0 };

JSObject* JSSVGPathSegCurvetoQuadraticSmoothAbsPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGPathSegCurvetoQuadraticSmoothAbs>(exec, globalObject);
}

const ClassInfo JSSVGPathSegCurvetoQuadraticSmoothAbs::s_info = { "SVGPathSegCurvetoQuadraticSmoothAbs", &JSSVGPathSeg::s_info, &JSSVGPathSegCurvetoQuadraticSmoothAbsTable, 0 };

JSSVGPathSegCurvetoQuadraticSmoothAbs::JSSVGPathSegCurvetoQuadraticSmoothAbs(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGPathSegCurvetoQuadraticSmoothAbs> impl)
    : JSSVGPathSeg(structure, globalObject, impl)
{
}

JSObject* JSSVGPathSegCurvetoQuadraticSmoothAbs::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGPathSegCurvetoQuadraticSmoothAbsPrototype(JSSVGPathSegCurvetoQuadraticSmoothAbsPrototype::createStructure(JSSVGPathSegPrototype::self(exec, globalObject)));
}

bool JSSVGPathSegCurvetoQuadraticSmoothAbs::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGPathSegCurvetoQuadraticSmoothAbs, Base>(exec, &JSSVGPathSegCurvetoQuadraticSmoothAbsTable, this, propertyName, slot);
}

bool JSSVGPathSegCurvetoQuadraticSmoothAbs::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGPathSegCurvetoQuadraticSmoothAbs, Base>(exec, &JSSVGPathSegCurvetoQuadraticSmoothAbsTable, this, propertyName, descriptor);
}

JSValue jsSVGPathSegCurvetoQuadraticSmoothAbsX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticSmoothAbs* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticSmoothAbs*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticSmoothAbs* imp = static_cast<SVGPathSegCurvetoQuadraticSmoothAbs*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->x());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticSmoothAbsY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticSmoothAbs* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticSmoothAbs*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticSmoothAbs* imp = static_cast<SVGPathSegCurvetoQuadraticSmoothAbs*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->y());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticSmoothAbsConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticSmoothAbs* domObject = static_cast<JSSVGPathSegCurvetoQuadraticSmoothAbs*>(asObject(slotBase));
    return JSSVGPathSegCurvetoQuadraticSmoothAbs::getConstructor(exec, domObject->globalObject());
}
void JSSVGPathSegCurvetoQuadraticSmoothAbs::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGPathSegCurvetoQuadraticSmoothAbs, Base>(exec, propertyName, value, &JSSVGPathSegCurvetoQuadraticSmoothAbsTable, this, slot);
}

void setJSSVGPathSegCurvetoQuadraticSmoothAbsX(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticSmoothAbs* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticSmoothAbs*>(thisObject);
    SVGPathSegCurvetoQuadraticSmoothAbs* imp = static_cast<SVGPathSegCurvetoQuadraticSmoothAbs*>(castedThisObj->impl());
    imp->setX(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

void setJSSVGPathSegCurvetoQuadraticSmoothAbsY(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticSmoothAbs* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticSmoothAbs*>(thisObject);
    SVGPathSegCurvetoQuadraticSmoothAbs* imp = static_cast<SVGPathSegCurvetoQuadraticSmoothAbs*>(castedThisObj->impl());
    imp->setY(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

JSValue JSSVGPathSegCurvetoQuadraticSmoothAbs::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGPathSegCurvetoQuadraticSmoothAbsConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}

#endif // ENABLE(SVG)
