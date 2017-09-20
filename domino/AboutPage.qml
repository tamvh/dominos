import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Popup {
    id: aboutPage
    width: 400
    height: 300
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    focus: true
    modal: true
    contentItem: ColumnLayout {
        id: appOptionColumn
        Layout.alignment: Qt.AlignHCenter
        spacing: 20
        Row {
            width: appOptionColumn.width
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                height: 90
                width: 90
                source: "qrc:/icons/icons/logo.png"
            }
        }


        ColumnLayout {
            width: appOptionColumn.width
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                text: "Sản phẩm được phát triển bởi"
                font.pixelSize: fntsize
            }
            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                text: "VNG Corporation"
                font.bold: true
                font.pixelSize: fntsize
            }
        }

        Row {
            width: appOptionColumn.width
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                text: "Phiên bản 1.0"
                font.pixelSize: fntsize
            }
        }

        Row {
            spacing: 10
            width: appOptionColumn.width
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: cancelButton
                text: "ĐÓNG"
                width: 200
                highlighted: true
                onClicked: {
                    aboutPage.close();
                }
            }
        }
    }
}
