/*
 * QML Material - An application framework implementing Material Design.
 * Copyright (C) 2015 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    id: page
    RectMain {
        id: rectMainPage
        anchors.fill: parent
        z: -1
        opacity: 0.8
    }
    RowLayout {
        anchors.fill: parent
        enabled: window.window_enable
        Rectangle {
            id: idFrame
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width*2/3

            SwipeMenu {
                anchors.fill: parent
                visible:!isShowSearch
            }

            SearchPage {
                anchors.fill: parent
                visible:isShowSearch
            }
        }

        PaymentPage {
            id: paymentPage
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.left: idFrame.right
        }
    }
}
