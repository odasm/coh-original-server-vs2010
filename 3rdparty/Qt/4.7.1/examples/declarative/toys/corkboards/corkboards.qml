/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
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
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
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
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 1.0

Rectangle {
    width: 800; height: 480
    color: "#464646"

    ListModel {
        id: list

        ListElement {
            name: "Sunday"
            notes: [ 
                ListElement { noteText: "Lunch" },
                ListElement { noteText: "Birthday Party" }
            ]
        }
        
        ListElement {
            name: "Monday"
            notes: [
                ListElement { noteText: "Pickup kids from\nschool\n4.30pm" },
                ListElement { noteText: "Checkout Qt" }, ListElement { noteText: "Read email" }
            ]
        }

        ListElement {
            name: "Tuesday"
            notes: [
                ListElement { noteText: "Walk dog" },
                ListElement { noteText: "Buy newspaper" }
            ]
        }

        ListElement {
            name: "Wednesday"
            notes: [ ListElement { noteText: "Cook dinner" } ]
        }

        ListElement {
            name: "Thursday"
            notes: [
                ListElement { noteText: "Meeting\n5.30pm" },
                ListElement { noteText: "Weed garden" }
            ]
        }

        ListElement {
            name: "Friday"
            notes: [
                ListElement { noteText: "More work" },
                ListElement { noteText: "Grocery shopping" }
            ]
        }

        ListElement {
            name: "Saturday"
            notes: [
                ListElement { noteText: "Drink" },
                ListElement { noteText: "Download Qt\nPlay with QML" }
            ]
        }
    }

    ListView {
        id: flickable

        anchors.fill: parent
        focus: true
        highlightRangeMode: ListView.StrictlyEnforceRange
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
        model: list
        delegate: Day { }
    }
}
