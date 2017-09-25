import QtQuick 2.6
import QtQuick.Templates 2.0 as T
import QtQuick.Controls.Material 2.0

T.TabBar {
    id: control

    padding: 0


    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem.implicitHeight + topPadding + bottomPadding)

    //! [contentItem]
    contentItem: ListView {
        implicitWidth: contentWidth
        implicitHeight: 55

        model: control.contentModel
        currentIndex: control.currentIndex

        //spacing: control.spacing
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds
        snapMode: ListView.SnapToItem
    }
    //! [contentItem]

    //! [background]
    background: Rectangle {
        color: control.Material.backgroundColor
    }
    //! [background]
}
