/*
 * This file is part of the DOM implementation for KDE.
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
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
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */
#ifndef HTML_OBJECTIMPL_H
#define HTML_OBJECTIMPL_H

#include "html_elementimpl.h"
#include "xml/dom_stringimpl.h"
#include "java/kjavaappletcontext.h"

#include <qstringlist.h>

#if APPLE_CHANGES
#include <JavaVM/jni.h>
#include <JavaScriptCore/runtime.h>
#endif

class KHTMLView;

// -------------------------------------------------------------------------
namespace DOM {

class HTMLFormElementImpl;
class DOMStringImpl;

class HTMLAppletElementImpl : public HTMLElementImpl
{
public:
    HTMLAppletElementImpl(DocumentPtr *doc);

    ~HTMLAppletElementImpl();

    virtual Id id() const;

    virtual bool mapToEntry(AttributeImpl* attr, MappedAttributeEntry& result) const;
    virtual void parseHTMLAttribute(HTMLAttributeImpl *token);
    
    virtual bool rendererIsNeeded(khtml::RenderStyle *);
    virtual khtml::RenderObject *createRenderer(RenderArena *, khtml::RenderStyle *);

    bool getMember(const QString &, JType &, QString &);
    bool callMember(const QString &, const QStringList &, JType &, QString &);
    
#if APPLE_CHANGES
    void setupApplet() const;
    KJS::Bindings::Instance *getAppletInstance() const;
#endif

protected:
    khtml::VAlign valign;

private:
    mutable KJS::Bindings::Instance *appletInstance;
};

// -------------------------------------------------------------------------

class HTMLEmbedElementImpl : public HTMLElementImpl
{
public:
    HTMLEmbedElementImpl(DocumentPtr *doc);

    ~HTMLEmbedElementImpl();

    virtual Id id() const;

    virtual bool mapToEntry(AttributeImpl* attr, MappedAttributeEntry& result) const;
    virtual void parseHTMLAttribute(HTMLAttributeImpl *attr);

    virtual void attach();
    virtual bool rendererIsNeeded(khtml::RenderStyle *);
    virtual khtml::RenderObject *createRenderer(RenderArena *, khtml::RenderStyle *);

    QString url;
    QString pluginPage;
    QString serviceType;
};

// -------------------------------------------------------------------------

class HTMLObjectElementImpl : public HTMLElementImpl
{
public:
    HTMLObjectElementImpl(DocumentPtr *doc);

    ~HTMLObjectElementImpl();

    virtual Id id() const;

    HTMLFormElementImpl *form() const;

    virtual bool mapToEntry(AttributeImpl* attr, MappedAttributeEntry& result) const;
    virtual void parseHTMLAttribute(HTMLAttributeImpl *token);

    virtual void attach();
    virtual bool rendererIsNeeded(khtml::RenderStyle *);
    virtual khtml::RenderObject *createRenderer(RenderArena *, khtml::RenderStyle *);
    virtual void detach();

    virtual void recalcStyle( StyleChange ch );

    DocumentImpl* contentDocument() const;

    QString serviceType;
    QString url;
    QString classId;
    bool needWidgetUpdate;
};

// -------------------------------------------------------------------------

class HTMLParamElementImpl : public HTMLElementImpl
{
    friend class HTMLAppletElementImpl;
public:
    HTMLParamElementImpl(DocumentPtr *doc);

    ~HTMLParamElementImpl();

    virtual Id id() const;

    virtual void parseHTMLAttribute(HTMLAttributeImpl *token);

    QString name() const { return m_name.string(); }
    QString value() const { return m_value.string(); }

 protected:
    AtomicString m_name;
    AtomicString m_value;
};

};
#endif
