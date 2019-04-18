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

#ifndef JSDOMApplicationCache_h
#define JSDOMApplicationCache_h

#if ENABLE(OFFLINE_WEB_APPLICATIONS)

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class DOMApplicationCache;

class JSDOMApplicationCache : public DOMObjectWithGlobalPointer {
    typedef DOMObjectWithGlobalPointer Base;
public:
    JSDOMApplicationCache(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<DOMApplicationCache>);
    virtual ~JSDOMApplicationCache();
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }

    virtual void markChildren(JSC::MarkStack&);


    // Custom functions
    JSC::JSValue addEventListener(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue removeEventListener(JSC::ExecState*, const JSC::ArgList&);
    DOMApplicationCache* impl() const { return m_impl.get(); }

private:
    RefPtr<DOMApplicationCache> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, DOMApplicationCache*);
DOMApplicationCache* toDOMApplicationCache(JSC::JSValue);

class JSDOMApplicationCachePrototype : public JSC::JSObject {
    typedef JSC::JSObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
    JSDOMApplicationCachePrototype(NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::JSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionUpdate(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionSwapCache(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionAddEventListener(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionRemoveEventListener(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsDOMApplicationCachePrototypeFunctionDispatchEvent(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
// Attributes

JSC::JSValue jsDOMApplicationCacheStatus(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheOnchecking(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnchecking(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOnerror(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnerror(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOnnoupdate(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnnoupdate(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOndownloading(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOndownloading(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOnprogress(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnprogress(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOnupdateready(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnupdateready(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOncached(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOncached(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDOMApplicationCacheOnobsolete(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSDOMApplicationCacheOnobsolete(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
// Constants

JSC::JSValue jsDOMApplicationCacheUNCACHED(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheIDLE(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheCHECKING(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheDOWNLOADING(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheUPDATEREADY(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMApplicationCacheOBSOLETE(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif // ENABLE(OFFLINE_WEB_APPLICATIONS)

#endif
