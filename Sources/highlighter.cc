/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "Headers/highlighter.h"

Highlighter::Highlighter(QTextDocument *parent): QSyntaxHighlighter(parent) {
    HighlightingRule rule;

    keywordFormat.setForeground(QColor("#F4E175"));
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b" <<"\\b__inline\\b" << "\\b__int64\\b"
                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b" << "\\bauto\\b" <<"\\bfor\\b"
                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b" << "\\bconstexpr\\b"
                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b" << "\\bwhile\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b" << "\\bswitch\\b"
<<<<<<< HEAD
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b" << "\\breturn\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b" << "\\bif\\b" << "\\bbreak\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b" << "\\bgoto\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b" << "\\bcontinue\\b" << "\\bdelete\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b" << "\\busing\\b" << "\\bnew\\b"
                    << "\\band\\b" << "\\bor\\b" << "\\bxor\\b";
=======
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b" << "\\bextern\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b" << "\\bif\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b" << "\\bfloat\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b" << "\\b__int128\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b" << "\\busing\\b";
>>>>>>> 0628c67a9a1bf32fb185071fd7f417569b6ea906
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    sharpFormat.setForeground(QColor("#ec711e"));
    rule.pattern = QRegularExpression("\#.*[^\n]");
    rule.format = sharpFormat;
    highlightingRules.append(rule);

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(QColor("#EFBCAC"));
    rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(QColor("#71C671"));
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(QColor("#71C671"));

    quotationFormat.setForeground(QColor("#E89D86"));
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(QColor("#63DAE8"));
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_*]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
