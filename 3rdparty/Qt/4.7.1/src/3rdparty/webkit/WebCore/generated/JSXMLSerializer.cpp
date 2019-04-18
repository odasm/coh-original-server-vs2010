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
#include "JSXMLSerializer.h"

#include "JSNode.h"
#include "KURL.h"
#include "XMLSerializer.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSXMLSerializer);

/* Hash table */

static const HashTableValue JSXMLSerializerTableValues[2] =
{
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsXMLSerializerConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXMLSerializerTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSXMLSerializerTableValues, 0 };
#else
    { 2, 1, JSXMLSerializerTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSXMLSerializerConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXMLSerializerConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSXMLSerializerConstructorTableValues, 0 };
#else
    { 1, 0, JSXMLSerializerConstructorTableValues, 0 };
#endif

class JSXMLSerializerConstructor : public DOMConstructorObject {
public:
    JSXMLSerializerConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSXMLSerializerConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSXMLSerializerPrototype::self(exec, globalObject), None);
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
    static JSObject* constructXMLSerializer(ExecState* exec, JSObject* constructor, const ArgList&)
    {
        return asObject(toJS(exec, static_cast<JSXMLSerializerConstructor*>(constructor)->globalObject(), XMLSerializer::create()));
    }
    virtual ConstructType getConstructData(ConstructData& constructData)
    {
        constructData.native.function = constructXMLSerializer;
        return ConstructTypeHost;
    }
};

const ClassInfo JSXMLSerializerConstructor::s_info = { "XMLSerializerConstructor", 0, &JSXMLSerializerConstructorTable, 0 };

bool JSXMLSerializerConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSXMLSerializerConstructor, DOMObject>(exec, &JSXMLSerializerConstructorTable, this, propertyName, slot);
}

bool JSXMLSerializerConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSXMLSerializerConstructor, DOMObject>(exec, &JSXMLSerializerConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSXMLSerializerPrototypeTableValues[2] =
{
    { "serializeToString", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsXMLSerializerPrototypeFunctionSerializeToString), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSXMLSerializerPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSXMLSerializerPrototypeTableValues, 0 };
#else
    { 2, 1, JSXMLSerializerPrototypeTableValues, 0 };
#endif

const ClassInfo JSXMLSerializerPrototype::s_info = { "XMLSerializerPrototype", 0, &JSXMLSerializerPrototypeTable, 0 };

JSObject* JSXMLSerializerPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSXMLSerializer>(exec, globalObject);
}

bool JSXMLSerializerPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSXMLSerializerPrototypeTable, this, propertyName, slot);
}

bool JSXMLSerializerPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSXMLSerializerPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSXMLSerializer::s_info = { "XMLSerializer", 0, &JSXMLSerializerTable, 0 };

JSXMLSerializer::JSXMLSerializer(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<XMLSerializer> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSXMLSerializer::~JSXMLSerializer()
{
    forgetDOMObject(this, impl());
}

JSObject* JSXMLSerializer::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSXMLSerializerPrototype(JSXMLSerializerPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSXMLSerializer::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSXMLSerializer, Base>(exec, &JSXMLSerializerTable, this, propertyName, slot);
}

bool JSXMLSerializer::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSXMLSerializer, Base>(exec, &JSXMLSerializerTable, this, propertyName, descriptor);
}

JSValue jsXMLSerializerConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSXMLSerializer* domObject = static_cast<JSXMLSerializer*>(asObject(slotBase));
    return JSXMLSerializer::getConstructor(exec, domObject->globalObject());
}
JSValue JSXMLSerializer::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSXMLSerializerConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsXMLSerializerPrototypeFunctionSerializeToString(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSXMLSerializer::s_info))
        return throwError(exec, TypeError);
    JSXMLSerializer* castedThisObj = static_cast<JSXMLSerializer*>(asObject(thisValue));
    XMLSerializer* imp = static_cast<XMLSerializer*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* node = toNode(args.at(0));


    JSC::JSValue result = jsString(exec, imp->serializeToString(node, ec));
    setDOMException(exec, ec);
    return result;
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, XMLSerializer* object)
{
    return getDOMObjectWrapper<JSXMLSerializer>(exec, globalObject, object);
}
XMLSerializer* toXMLSerializer(JSC::JSValue value)
{
    return value.inherits(&JSXMLSerializer::s_info) ? static_cast<JSXMLSerializer*>(asObject(value))->impl() : 0;
}

}
