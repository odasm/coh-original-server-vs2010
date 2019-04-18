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
#include "JSHTMLParagraphElement.h"

#include "HTMLParagraphElement.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLParagraphElement);

/* Hash table */

static const HashTableValue JSHTMLParagraphElementTableValues[3] =
{
    { "align", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLParagraphElementAlign), (intptr_t)setJSHTMLParagraphElementAlign },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLParagraphElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLParagraphElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSHTMLParagraphElementTableValues, 0 };
#else
    { 5, 3, JSHTMLParagraphElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLParagraphElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLParagraphElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLParagraphElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLParagraphElementConstructorTableValues, 0 };
#endif

class JSHTMLParagraphElementConstructor : public DOMConstructorObject {
public:
    JSHTMLParagraphElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLParagraphElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLParagraphElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSHTMLParagraphElementConstructor::s_info = { "HTMLParagraphElementConstructor", 0, &JSHTMLParagraphElementConstructorTable, 0 };

bool JSHTMLParagraphElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLParagraphElementConstructor, DOMObject>(exec, &JSHTMLParagraphElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLParagraphElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLParagraphElementConstructor, DOMObject>(exec, &JSHTMLParagraphElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLParagraphElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLParagraphElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLParagraphElementPrototypeTableValues, 0 };
#else
    { 1, 0, JSHTMLParagraphElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLParagraphElementPrototype::s_info = { "HTMLParagraphElementPrototype", 0, &JSHTMLParagraphElementPrototypeTable, 0 };

JSObject* JSHTMLParagraphElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLParagraphElement>(exec, globalObject);
}

const ClassInfo JSHTMLParagraphElement::s_info = { "HTMLParagraphElement", &JSHTMLElement::s_info, &JSHTMLParagraphElementTable, 0 };

JSHTMLParagraphElement::JSHTMLParagraphElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLParagraphElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLParagraphElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLParagraphElementPrototype(JSHTMLParagraphElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLParagraphElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLParagraphElement, Base>(exec, &JSHTMLParagraphElementTable, this, propertyName, slot);
}

bool JSHTMLParagraphElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLParagraphElement, Base>(exec, &JSHTMLParagraphElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLParagraphElementAlign(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLParagraphElement* castedThis = static_cast<JSHTMLParagraphElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLParagraphElement* imp = static_cast<HTMLParagraphElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->align());
    return result;
}

JSValue jsHTMLParagraphElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLParagraphElement* domObject = static_cast<JSHTMLParagraphElement*>(asObject(slotBase));
    return JSHTMLParagraphElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLParagraphElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLParagraphElement, Base>(exec, propertyName, value, &JSHTMLParagraphElementTable, this, slot);
}

void setJSHTMLParagraphElementAlign(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLParagraphElement* castedThisObj = static_cast<JSHTMLParagraphElement*>(thisObject);
    HTMLParagraphElement* imp = static_cast<HTMLParagraphElement*>(castedThisObj->impl());
    imp->setAlign(valueToStringWithNullCheck(exec, value));
}

JSValue JSHTMLParagraphElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLParagraphElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
