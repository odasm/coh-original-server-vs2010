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
#include "JSCSSRule.h"

#include "CSSRule.h"
#include "CSSStyleSheet.h"
#include "JSCSSRule.h"
#include "JSCSSStyleSheet.h"
#include "KURL.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCSSRule);

/* Hash table */

static const HashTableValue JSCSSRuleTableValues[6] =
{
    { "type", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleType), (intptr_t)0 },
    { "cssText", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleCssText), (intptr_t)setJSCSSRuleCssText },
    { "parentStyleSheet", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleParentStyleSheet), (intptr_t)0 },
    { "parentRule", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleParentRule), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRuleTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSCSSRuleTableValues, 0 };
#else
    { 17, 15, JSCSSRuleTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSCSSRuleConstructorTableValues[11] =
{
    { "UNKNOWN_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleUNKNOWN_RULE), (intptr_t)0 },
    { "STYLE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleSTYLE_RULE), (intptr_t)0 },
    { "CHARSET_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleCHARSET_RULE), (intptr_t)0 },
    { "IMPORT_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleIMPORT_RULE), (intptr_t)0 },
    { "MEDIA_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleMEDIA_RULE), (intptr_t)0 },
    { "FONT_FACE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleFONT_FACE_RULE), (intptr_t)0 },
    { "PAGE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRulePAGE_RULE), (intptr_t)0 },
    { "VARIABLES_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleVARIABLES_RULE), (intptr_t)0 },
    { "WEBKIT_KEYFRAMES_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleWEBKIT_KEYFRAMES_RULE), (intptr_t)0 },
    { "WEBKIT_KEYFRAME_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleWEBKIT_KEYFRAME_RULE), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRuleConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1023, JSCSSRuleConstructorTableValues, 0 };
#else
    { 34, 31, JSCSSRuleConstructorTableValues, 0 };
#endif

class JSCSSRuleConstructor : public DOMConstructorObject {
public:
    JSCSSRuleConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSCSSRuleConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSCSSRulePrototype::self(exec, globalObject), None);
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

const ClassInfo JSCSSRuleConstructor::s_info = { "CSSRuleConstructor", 0, &JSCSSRuleConstructorTable, 0 };

bool JSCSSRuleConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSRuleConstructor, DOMObject>(exec, &JSCSSRuleConstructorTable, this, propertyName, slot);
}

bool JSCSSRuleConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSRuleConstructor, DOMObject>(exec, &JSCSSRuleConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSCSSRulePrototypeTableValues[11] =
{
    { "UNKNOWN_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleUNKNOWN_RULE), (intptr_t)0 },
    { "STYLE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleSTYLE_RULE), (intptr_t)0 },
    { "CHARSET_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleCHARSET_RULE), (intptr_t)0 },
    { "IMPORT_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleIMPORT_RULE), (intptr_t)0 },
    { "MEDIA_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleMEDIA_RULE), (intptr_t)0 },
    { "FONT_FACE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleFONT_FACE_RULE), (intptr_t)0 },
    { "PAGE_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRulePAGE_RULE), (intptr_t)0 },
    { "VARIABLES_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleVARIABLES_RULE), (intptr_t)0 },
    { "WEBKIT_KEYFRAMES_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleWEBKIT_KEYFRAMES_RULE), (intptr_t)0 },
    { "WEBKIT_KEYFRAME_RULE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleWEBKIT_KEYFRAME_RULE), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRulePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1023, JSCSSRulePrototypeTableValues, 0 };
#else
    { 34, 31, JSCSSRulePrototypeTableValues, 0 };
#endif

const ClassInfo JSCSSRulePrototype::s_info = { "CSSRulePrototype", 0, &JSCSSRulePrototypeTable, 0 };

JSObject* JSCSSRulePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCSSRule>(exec, globalObject);
}

bool JSCSSRulePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSRulePrototype, JSObject>(exec, &JSCSSRulePrototypeTable, this, propertyName, slot);
}

bool JSCSSRulePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSRulePrototype, JSObject>(exec, &JSCSSRulePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSCSSRule::s_info = { "CSSRule", 0, &JSCSSRuleTable, 0 };

JSCSSRule::JSCSSRule(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<CSSRule> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSCSSRule::~JSCSSRule()
{
    forgetDOMObject(this, impl());
}

JSObject* JSCSSRule::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCSSRulePrototype(JSCSSRulePrototype::createStructure(globalObject->objectPrototype()));
}

bool JSCSSRule::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSRule, Base>(exec, &JSCSSRuleTable, this, propertyName, slot);
}

bool JSCSSRule::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSRule, Base>(exec, &JSCSSRuleTable, this, propertyName, descriptor);
}

JSValue jsCSSRuleType(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRule* castedThis = static_cast<JSCSSRule*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSRule* imp = static_cast<CSSRule*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->type());
    return result;
}

JSValue jsCSSRuleCssText(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRule* castedThis = static_cast<JSCSSRule*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSRule* imp = static_cast<CSSRule*>(castedThis->impl());
    JSValue result = jsStringOrNull(exec, imp->cssText());
    return result;
}

JSValue jsCSSRuleParentStyleSheet(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRule* castedThis = static_cast<JSCSSRule*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSRule* imp = static_cast<CSSRule*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->parentStyleSheet()));
    return result;
}

JSValue jsCSSRuleParentRule(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRule* castedThis = static_cast<JSCSSRule*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSRule* imp = static_cast<CSSRule*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->parentRule()));
    return result;
}

JSValue jsCSSRuleConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRule* domObject = static_cast<JSCSSRule*>(asObject(slotBase));
    return JSCSSRule::getConstructor(exec, domObject->globalObject());
}
void JSCSSRule::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSCSSRule, Base>(exec, propertyName, value, &JSCSSRuleTable, this, slot);
}

void setJSCSSRuleCssText(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSCSSRule* castedThisObj = static_cast<JSCSSRule*>(thisObject);
    CSSRule* imp = static_cast<CSSRule*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    imp->setCssText(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

JSValue JSCSSRule::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCSSRuleConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

// Constant getters

JSValue jsCSSRuleUNKNOWN_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsCSSRuleSTYLE_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsCSSRuleCHARSET_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsCSSRuleIMPORT_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(3));
}

JSValue jsCSSRuleMEDIA_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(4));
}

JSValue jsCSSRuleFONT_FACE_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(5));
}

JSValue jsCSSRulePAGE_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(6));
}

JSValue jsCSSRuleVARIABLES_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(7));
}

JSValue jsCSSRuleWEBKIT_KEYFRAMES_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(8));
}

JSValue jsCSSRuleWEBKIT_KEYFRAME_RULE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(9));
}

CSSRule* toCSSRule(JSC::JSValue value)
{
    return value.inherits(&JSCSSRule::s_info) ? static_cast<JSCSSRule*>(asObject(value))->impl() : 0;
}

}
