import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4
import MainController 1.0
import QmlDefine 1.0
import "dynamicqml"

Popup {
    // show bảng báo nhận hóa đơn
    id: doBillDominosErrAlert
    modal: true
    focus: true
    x: (window.width - width) / 2
    y: Math.abs(window.height - doBillDominosErrAlert.height) / 3
    closePolicy: Popup.NoAutoClose
    leftPadding: 30
    rightPadding: 30
    Column {
        id: billAlertColumn
        width: implicitWidth
        height: implicitHeight
        spacing: 10

        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            topPadding: globalPadding
            bottomPadding: globalPadding
            width: implicitWidth
            height: implicitHeight

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: fntsize + 4
                font.weight: Font.DemiBold
                text: "THANH TOÁN HOÀN TẤT"
            }

            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: childrenRect.width + 2
                height: childrenRect.height + 2
                Image {
                    x: 1
                    y: 1
                    source: "qrc:/icons/images/billonprinter.png"
                }
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Vui lòng nhận hóa đơn từ máy in"
                font.pixelSize: 36
            }
            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "LIÊN HỆ QUẦY ĐỂ ĐƯỢC HƯỚNG DẪN"
                font.bold: true
                font.pixelSize: 36
            }

            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                width: implicitWidth
                spacing: 5
                Label {
                    id: labelTimerBillAlert
                    text: "Cửa sổ sẽ đóng sau thời gian:   "
                    font.pixelSize: 25
                }

                QrTimer {
                    id: doBillDominosErrTimer
                    anchors.left: labelTimerBillAlert.right
                    anchors.verticalCenter: parent.verticalCenter
                    delayTimer:mainController.getBillAlertTimer()*2000  //1000 = 1s
                }
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                width: billAlertColumn.width
                height: 70
                highlighted: true
                font.pixelSize: fntsize
                text: "Đóng"
                onClicked: {
                    doBillDominosErrAlert.close()
                }
            }
        }
    }

    onOpened: {
        doBillDominosErrTimer.parentId = 5;
        doBillDominosErrTimer.restartTimerCounter();
    }

    onClosed: {
        doBillDominosErrTimer.stopTimerCounter();
    }
}
