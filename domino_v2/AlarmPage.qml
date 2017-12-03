import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

Popup {
    id: alarmPage
    modal: true
    focus: true
    x: (window.width - width)/2
    y: (window.height - height)/2
    topPadding: 40
    rightPadding: 40
    leftPadding: 40
    bottomPadding: 40
    contentItem: ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        width: 600
        Column {

            Image {
                fillMode: Image.Pad
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/icons/images/app/icon_maintenance.svg"
                scale: 0.7
            }

            Rectangle {
                height: 150
                width: 600
                Column {
                    anchors.centerIn: parent
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 20
                    Text {
                        text: "Hệ thống đang bảo trì"
                        font.pixelSize: 30
                        color: "#4A4A4A"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        text: "Vui lòng liên hệ quầy để được hướng dẫn"
                        font.pixelSize: 30
                        color: "#4A4A4A"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    text: "Đóng"
                    height: 90
                    width: 342
                    highlighted: true
                    font.pixelSize: 30
                    Material.primary: "#0695D6"
                    Material.accent: "#0695D6"
                    onClicked: {
                        alarmPage.close();
                    }
                }
            }
        }
    }
}
