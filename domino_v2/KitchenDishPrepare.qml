import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0

Page {
    // Danh sách các món ăn chờ Bếp chế biến

    id: idKitchenDishPreparePage

    property int namewidth: width - 280
    property int globalspace: 10

    Material.primary: Material.DeepOrange
    Material.accent: Material.DeepOrange

    ListModel {
        id: lmDiskPrepare
    }

    Component {
        id: compDiskPrepare

        MouseArea {
            id: dragArea
            anchors { left: parent.left; right: parent.right; }
            anchors.margins: 5
            height: content.height
            onClicked: {
                console.log("disk item click ...")
            }

            Rectangle {
                id: content
                anchors { left: parent.left; right: parent.right }
                width: parent.width
//                height: 46
                height: idRow.implicitHeight + 10
                border.color: "lightsteelblue"
                border.width: 1
                radius: 5

                Row {
                    id: idRow
                    anchors.fill:parent
                    anchors.margins: 5
                    spacing: 10

                    Label {
                        width: 10
                        text: idx
                        height: parent.height
                        verticalAlignment: Qt.AlignVCenter
                    }
                    Label {
                        text: name
                        width: namewidth
                        height: parent.height
                        verticalAlignment: Qt.AlignVCenter
                    }
                    Rectangle {
                        height: parent.height
                        width: parent.height
                        radius: parent.height
                        color: "#f17419"
                        Text {
                            anchors.fill: parent
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            color: "white"
                            text: amout
                        }
                    }
                    Label {
                        text: time
                        height: parent.height
                        verticalAlignment: Qt.AlignVCenter
                    }
                    Image {
                        source: "qrc:/icons/icons/dishcyclebin.png"
                    }
                    Image {
                        source: "qrc:/icons/icons/dishnext.png"
                    }
                }
            }
        }
    }

    Column {
        width: parent.width-10
        height: parent.height
        anchors.fill: parent
        spacing: 30

        RowLayout {
            //id: idDiskPrepareHeader
            id: idDiskPrepare1
            anchors.top: parent.top
            width: parent.width-20
            height: 40

            Label {
                height: parent.height
                text: qsTr("  CHỜ CHẾ BIẾN")
                verticalAlignment: Qt.AlignVCenter
                color: "#f17419"
            }

            Row {
                anchors.top: parent.top
                anchors.right: parent.right
                height: parent.height
                Label {
                    height: parent.height
                    width: contentWidth
                    verticalAlignment: Qt.AlignVCenter
                    color: "#f17419"
                    text: "15 "
                }

                Label {
                    anchors.right: parent.right
                    height: parent.height
                    width: contentWidth
                    verticalAlignment: Qt.AlignVCenter
                    text: qsTr("món đang chờ ")
                }
            }            
        }

        RowLayout {
            id: idDiskPrepareHeader
            anchors.top: idDiskPrepare1.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            width: parent.width-20
            height: 40

            Rectangle {
//                width: parent.width
//                height: 40
                anchors.fill: parent
                border.width: 3
                border.color: "red"
            }
        }

        RowLayout {
            id: idRow
            anchors.top: idDiskPrepareHeader.bottom
            width: parent.width
            height: parent.height-80

            ListView {
                id: lvDiskPrepare
                width: parent.width
                height: contentHeight
                anchors.fill: parent //must define anchors.fill
                model: lmDiskPrepare
                spacing: globalspace
                delegate: compDiskPrepare
            }

            VPOSScrollBar {
                id: verticalScrollBar
                width: 10
                height: lvDiskPrepare.height - 10
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: lvDiskPrepare.right
                opacity: lvDiskPrepare.contentHeight > lvDiskPrepare.height ? 1.0: 0
                orientation: Qt.Vertical
                position: lvDiskPrepare.visibleArea.yPosition
                pageSize: lvDiskPrepare.visibleArea.heightRatio
            }

        }
    }

    Component.onCompleted: {
        var diskItem, data = JSON.parse( mainController.getDiskPrepare() );

        lmDiskPrepare.clear()
        for (diskItem in data) {
            lmDiskPrepare.append({
                                     idx:data[diskItem]["idx"],
                                     name:data[diskItem]["name"],
                                     amout:data[diskItem]["amout"],
                                     time:data[diskItem]["time"],
                                 })
        }
    }
}
