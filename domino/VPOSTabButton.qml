import QtQuick 2.6
import QtQuick.Templates 2.0 as T
import QtQuick.Controls.Material 2.0

T.TabButton {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.contentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem.contentHeight + topPadding + bottomPadding)
    baselineOffset: contentItem.y + contentItem.baselineOffset

    //padding: 12

    //! [contentItem]
    contentItem: Text {
        text: control.text
        font: control.font
        elide: Text.ElideRight
        color: control.down || control.checked ? "white" : "black"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    //! [contentItem]

    //! [background]
    background: Item {
        implicitHeight: 60
        Rectangle {
            color: !control.enabled ? control.Material.hintTextColor : control.down || control.checked ? "red" : "white"
            border.width: 1
            border.color: "#E2E6E7"
            anchors.fill: parent
            anchors.rightMargin: -1
        }
    }
    //! [background]
}
