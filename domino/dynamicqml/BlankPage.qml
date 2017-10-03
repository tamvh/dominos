import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import QtQuick.Window 2.2

Item {
    Pane {
        id: blankContainer
        Flickable {
            anchors.fill: parent
            contentHeight: column.height
            contentWidth: column.width
            opacity: 0.2
        }
    }
}
