import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Page {
    // Danh sách các món ăn đã chế biến xong, chuyển qua phục vụ Khách

    id: idKitchenDishsPage

    property int namewidth: parent.width/2 - 230

    ListModel {
        id: lmDiskReserve
    }

    Component {
        id: compDiskReserve

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
                height: column.implicitHeight + 10
                border.color: "lightsteelblue"
                border.width: 1
                radius: 5

                Row {
                    id: column
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
                        source: "qrc:/icons/icons/dishcheck.png"
                    }
                }
            }
        }
    }

    Flickable {
        anchors.fill: parent
        contentHeight: column.height

        Column {
            id: column
            width: parent.width
            spacing: 10

            ListView {
                id: lvDiskReserve
                width: parent.width
                height: contentHeight
                model: lmDiskReserve
                spacing: 10
                delegate: compDiskReserve
            }
        }
    }

    Component.onCompleted: {
        var diskItem, data = JSON.parse( mainController.getDiskReserve() );

        lmDiskReserve.clear()
        for (diskItem in data) {
            lmDiskReserve.append({
                                     idx:data[diskItem]["idx"],
                                     name:data[diskItem]["name"],
                                     amout:data[diskItem]["amout"],
                                     time:data[diskItem]["time"],
                                 })
        }
    }
}
