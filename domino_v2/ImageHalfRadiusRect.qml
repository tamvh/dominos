import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0

Rectangle {
    property int bottomRadius: 10
    property color rcColor: "#006493"

    Rectangle {
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        width: parent.width
        height: bottomRadius * 3
    }

    Rectangle {
        id: rectTop
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: parent.height
        radius: bottomRadius
    }

    color: "transparent"
}
