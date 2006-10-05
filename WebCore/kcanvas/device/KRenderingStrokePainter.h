/*
    Copyright (C) 2004, 2005 Nikolas Zimmermann <wildfox@kde.org>
                  2004, 2005 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    aint with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef KRenderingStrokePainter_H
#define KRenderingStrokePainter_H
#ifdef SVG_SUPPORT

#include "KCanvasRenderingStyle.h"

namespace WebCore {
class KRenderingPaintServer;
class KRenderingDeviceContext;
class KRenderingStrokePainter
{
public:
    KRenderingStrokePainter();
    virtual ~KRenderingStrokePainter();

    // Common interface for fill and stroke parameters
    float strokeWidth() const;
    void setStrokeWidth(float);

    unsigned strokeMiterLimit() const;
    void setStrokeMiterLimit(unsigned);

    KCCapStyle strokeCapStyle() const;
    void setStrokeCapStyle(KCCapStyle);

    KCJoinStyle strokeJoinStyle() const;
    void setStrokeJoinStyle(KCJoinStyle);

    float dashOffset() const;
    void setDashOffset(float offset);

    const KCDashArray& dashArray() const;
    void setDashArray(const KCDashArray&);

    float opacity() const;
    void setOpacity(float);

    // Helpers
    bool dirty() const;
    void setDirty(bool dirty = true);

private:
    bool m_dirty;
    float m_opacity;

    float m_strokeWidth;
    unsigned m_miterLimit;

    KCCapStyle m_capStyle;
    KCJoinStyle m_joinStyle;

    float m_dashOffset;
    KCDashArray m_dashArray;
};

}

#endif // SVG_SUPPORT
#endif

// vim:ts=4:noet
