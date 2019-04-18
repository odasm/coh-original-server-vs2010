/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 2000 Simon Hausmann <hausmann@kde.org>
 * Copyright (C) 2004, 2005, 2006, 2008, 2009, 2010 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef RenderEmbeddedObject_h
#define RenderEmbeddedObject_h

#include "RenderPartObject.h"

namespace WebCore {

// Renderer for embeds and objects.
class RenderEmbeddedObject : public RenderPartObject {
public:
    RenderEmbeddedObject(Element*);
    virtual ~RenderEmbeddedObject();

    void updateWidget(bool onlyCreateNonNetscapePlugins);
    void setShowsMissingPluginIndicator(bool showsMissingPluginIndicator) { m_showsMissingPluginIndicator = showsMissingPluginIndicator; }
    bool showsMissingPluginIndicator() const { return m_showsMissingPluginIndicator; }
#if USE(ACCELERATED_COMPOSITING)
    virtual bool allowsAcceleratedCompositing() const;
#endif

private:
    virtual const char* renderName() const { return "RenderEmbeddedObject"; }
    virtual bool isEmbeddedObject() const { return true; }

    virtual void paintReplaced(PaintInfo&, int, int);
    virtual void paint(PaintInfo& paintInfo, int, int);

#if USE(ACCELERATED_COMPOSITING)
    virtual bool requiresLayer() const;
#endif

    virtual void layout();
    bool m_showsMissingPluginIndicator;
};

inline RenderEmbeddedObject* toRenderEmbeddedObject(RenderObject* object)
{
    ASSERT(!object || !strcmp(object->renderName(), "RenderEmbeddedObject"));
    return static_cast<RenderEmbeddedObject*>(object);
}

// This will catch anyone doing an unnecessary cast.
void toRenderEmbeddedObject(const RenderEmbeddedObject*);

} // namespace WebCore

#endif // RenderEmbeddedObject_h
