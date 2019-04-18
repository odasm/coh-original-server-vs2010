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

#ifndef Patternist_EBVExtractor_H
#define Patternist_EBVExtractor_H

#include "qsinglecontainer_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Calculates the Effective Boolean Value of its operand.
     *
     * EBVExtractor performs functionality wise the same as @c fn:boolean(),
     * but does it without the dependencies which FunctionCall requires.
     *
     * There is code-duplication going on with BooleanFN.
     *
     * @see BooleanFN
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class EBVExtractor : public SingleContainer
    {
    public:
        EBVExtractor(const Expression::Ptr &operand);
        virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;
        virtual SequenceType::List expectedOperandTypes() const;
        virtual const SourceLocationReflection *actualReflection() const;
        virtual Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                          const SequenceType::Ptr &reqType);
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;

        /**
         * @short Returns always @c xs:boolean.
         */
        virtual SequenceType::Ptr staticType() const;

        template<typename TSubClass, typename ThisType>
        static Expression::Ptr typeCheck(const StaticContext::Ptr &context,
                                         const SequenceType::Ptr &reqType,
                                         ThisType *const caller)
        {
            if(*CommonSequenceTypes::EBV->itemType() == *reqType->itemType())
                return caller->operands().first()->typeCheck(context, reqType);
            else
                return caller->TSubClass::typeCheck(context, reqType);
        }

    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
