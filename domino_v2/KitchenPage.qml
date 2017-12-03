import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

Component {
    Pane {

        // layout-double-checked

        property int diskcolumspace: 10

        Material.primary: Material.DeepOrange
        Material.accent: Material.DeepOrange

        RowLayout {
            anchors.fill: parent
            anchors.margins: diskcolumspace/2
            spacing: diskcolumspace

            // left panel
            KitchenDishPrepare {
                id: kitchenDiskPrepare
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                width: parent.width/2 - diskcolumspace
            }

            // right panel
            KitchenDishReserve {
                id: kitchDishReserve
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                width: parent.width/2 - diskcolumspace
                //width: parent.width - kitchDishReserve.width
            }
        }
    }
}
