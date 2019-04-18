/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef QPatternist_ReferenceCountedValue_p_h
#define QPatternist_ReferenceCountedValue_p_h

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

namespace QPatternist
{
/*!
   \class ReferenceCountedValue
   \internal
   \since 4.4
   \brief A template class that reference counts a value.

   This class is useful when an instance needs to have ownership semantics
   as if it was value based. A typical examples is a QObject pointer, which
   doesn't have a single owner.

   This is achieved through storing a copy of the object as
   a member inside ReferenceCountedValue, which never is copied. It will
   stay in scope until the last reference to the ReferenceCountedValue instance
   is removed, and subsequently ReferenceCountedValue is deleted and hence also
   the contained value. One should use ReferenceCountedValue by passing around
   copies of Ptr, which is a typedef for the QExplicitlySharedDataPointer
   smart pointer.
*/
    template<typename T>
    class ReferenceCountedValue : public QSharedData
    {
    public:
        typedef QExplicitlySharedDataPointer<ReferenceCountedValue<T> > Ptr;

        inline ReferenceCountedValue(T *const v) : value(v)
        {
        }

        inline ~ReferenceCountedValue()
        {
            delete value;
        }

        T *const value;
    private:
        /*!
          Disabled, no implementation provided.
         */
        inline ReferenceCountedValue();
        Q_DISABLE_COPY(ReferenceCountedValue)
    };
}

QT_END_NAMESPACE
QT_END_HEADER

#endif
