import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0

Rectangle {
    property int bottomRadius: 10
    property int radiusWidth: 3
    property color rcColor: "#006493"
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        width: parent.width
        height: bottomRadius * 3

        border.color: rcColor
        border.width: radiusWidth
        radius: bottomRadius
    }

    Rectangle {
        id: rectTop
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: parent.height
        border.color: rcColor
        border.width: radiusWidth
        radius: bottomRadius
    }

//    Rectangle {
//        width: parent.width - radiusWidth*2
//        x: radiusWidth
//        anchors.bottom: rectTop.bottom
//        height: radiusWidth
//        radius: bottomRadius
//    }

    color: "transparent"
}
