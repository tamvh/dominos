import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Popup {
    id: aboutPage
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    focus: true
    modal: true
    width: 600
    height: 500
    topPadding: 30
    rightPadding: 30
    leftPadding: 30
    bottomPadding: 30
    Column {
        id: appOptionColumn
        Layout.alignment: Qt.AlignHCenter
        spacing: 40
        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter
        Column {
            width: 600
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                fillMode: Image.Pad
                anchors.horizontalCenter: parent.horizontalCenter
                height: 135
                width: 274
                source: "qrc:/icons/images/app/vpos_logo_black.png"
            }
        }


        ColumnLayout {
            width: 600
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 40
            Row {
                width: 600
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: "Sản phẩm được phát triển bởi"
                    font.pixelSize: 27
                    color: "#58585A"
                }
            }
            Row {
                width: 600
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: "VNG Corporation"
                    font.bold: true
                    font.pixelSize: 30
                    color: "#58585A"
                }
            }
            Row {
                width: 600
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    text: "Phiên bản 1.0"
                    font.pixelSize: 27
                    color: "#58585A"
                }
            }
            Row {
                spacing: 10
                width: 600
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    id: cancelButton
                    text: "ĐÓNG"
                    width: 342
                    height: 78
                    highlighted: true
                    font.pixelSize: 30
                    onClicked: {
                        aboutPage.close();
                    }
                }
            }
        }
    }
}
