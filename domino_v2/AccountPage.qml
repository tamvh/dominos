import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Component {
    Pane {

        ListModel {
            id: lmAccount
        }

        Component {
            id: compAccount

            MouseArea {
                id: dragArea
                anchors { left: parent.left; right: parent.right; }
                anchors.margins: 5
                height: content.height
                onClicked: {

                    mainController.setAppName(accid, true)
                    mainController.setAppTitle(accname)

                    stackView.pop()
                }

                Rectangle {
                    id: content
                    anchors { left: parent.left; right: parent.right }
                    height: 46
                    border.color: "lightsteelblue"
                    border.width: 1
                    radius: 5

                    Row {
                        id: idRow
                        anchors.fill: parent
                        anchors.margins: 5

                        Label {
                            text: accid
                            width: 220
                            height: parent.height
                            verticalAlignment: Qt.AlignVCenter
                        }
                        Label {
                            text: accname
                            width: parent.width-285
                            height: parent.height
                            verticalAlignment: Qt.AlignVCenter
                        }
                        Image {
                            source: "qrc:/icons/icons/dishnext.png"
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
                    id: lvAccount
                    width: parent.width
                    height: contentHeight
                    model: lmAccount
                    spacing: 10
                    delegate: compAccount
                }
            }
        }

        Component.onCompleted: {
            var accItem, data = JSON.parse( mainController.getAccount() );

            lmAccount.clear()
            for (accItem in data) {
                lmAccount.append({ accid:data[accItem]["accid"],
                                     accname:data[accItem]["accname"] })
            }
        }
    }
}
