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
#include "JSHTMLPreElement.h"

#include "HTMLPreElement.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLPreElement);

/* Hash table */

static const HashTableValue JSHTMLPreElementTableValues[4] =
{
    { "width", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLPreElementWidth), (intptr_t)setJSHTMLPreElementWidth },
    { "wrap", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLPreElementWrap), (intptr_t)setJSHTMLPreElementWrap },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLPreElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLPreElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSHTMLPreElementTableValues, 0 };
#else
    { 9, 7, JSHTMLPreElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLPreElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLPreElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLPreElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLPreElementConstructorTableValues, 0 };
#endif

class JSHTMLPreElementConstructor : public DOMConstructorObject {
public:
    JSHTMLPreElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLPreElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLPreElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSHTMLPreElementConstructor::s_info = { "HTMLPreElementConstructor", 0, &JSHTMLPreElementConstructorTable, 0 };

bool JSHTMLPreElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLPreElementConstructor, DOMObject>(exec, &JSHTMLPreElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLPreElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLPreElementConstructor, DOMObject>(exec, &JSHTMLPreElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLPreElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLPreElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLPreElementPrototypeTableValues, 0 };
#else
    { 1, 0, JSHTMLPreElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLPreElementPrototype::s_info = { "HTMLPreElementPrototype", 0, &JSHTMLPreElementPrototypeTable, 0 };

JSObject* JSHTMLPreElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLPreElement>(exec, globalObject);
}

const ClassInfo JSHTMLPreElement::s_info = { "HTMLPreElement", &JSHTMLElement::s_info, &JSHTMLPreElementTable, 0 };

JSHTMLPreElement::JSHTMLPreElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLPreElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLPreElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLPreElementPrototype(JSHTMLPreElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLPreElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLPreElement, Base>(exec, &JSHTMLPreElementTable, this, propertyName, slot);
}

bool JSHTMLPreElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLPreElement, Base>(exec, &JSHTMLPreElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLPreElementWidth(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLPreElement* castedThis = static_cast<JSHTMLPreElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLPreElement* imp = static_cast<HTMLPreElement*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->width());
    return result;
}

JSValue jsHTMLPreElementWrap(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLPreElement* castedThis = static_cast<JSHTMLPreElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLPreElement* imp = static_cast<HTMLPreElement*>(castedThis->impl());
    JSValue result = jsBoolean(imp->wrap());
    return result;
}

JSValue jsHTMLPreElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLPreElement* domObject = static_cast<JSHTMLPreElement*>(asObject(slotBase));
    return JSHTMLPreElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLPreElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLPreElement, Base>(exec, propertyName, value, &JSHTMLPreElementTable, this, slot);
}

void setJSHTMLPreElementWidth(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLPreElement* castedThisObj = static_cast<JSHTMLPreElement*>(thisObject);
    HTMLPreElement* imp = static_cast<HTMLPreElement*>(castedThisObj->impl());
    imp->setWidth(value.toInt32(exec));
}

void setJSHTMLPreElementWrap(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLPreElement* castedThisObj = static_cast<JSHTMLPreElement*>(thisObject);
    HTMLPreElement* imp = static_cast<HTMLPreElement*>(castedThisObj->impl());
    imp->setWrap(value.toBoolean(exec));
}

JSValue JSHTMLPreElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLPreElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
