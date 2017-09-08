import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import MainController 1.0
import QmlDefine 1.0
import "dynamicqml"

Popup {
    id: popupProfile
    x: (window.width - width) / 2
    y: Math.abs(window.height -  popupProfile.height)/3
    closePolicy: Popup.NoAutoClose
    focus: true
    modal: true
    property var citlv: null
    property int txtfntsize: mainController.getConfigFoodItemFontsize()

    Column {
        id: columnContentProfile
        width: window.width/3
        height: (window.height*2)/3
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth
            anchors.margins: 0
            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: fntsize + 2
                font.weight: Font.DemiBold
                text: "NHẬP THÔNG TIN KHÁCH HÀNG"
            }
        }
        Rectangle {
            width: columnContentProfile.width
            height: 20
            anchors.margins: 0

        }
        ColumnLayout {
            id: appOptionColumn
            width: window.width/3
            Layout.alignment: Qt.AlignHCenter
            anchors.leftMargin: 0
            Row {
                spacing: globalPadding
                anchors.leftMargin: 0
                width: appOptionColumn.width
                TextField {
                    id: txtCustomerName
                    width: appOptionColumn.width
                    text: ""
                    placeholderText: "Nhập tên Khách Hàng"
                    Material.accent: "#01579B"
                    onTextChanged: {
                        console.log("customer name change...");
                        if(txtCustomerName.text.trim().length > 0) {
                            btnThanhToan.enabled = true;
                        } else {
                            btnThanhToan.enabled = false;
                        }
                    }
                }
            }
            Row {
                spacing: globalPadding
                width: appOptionColumn.width

                Row {
                    width: appOptionColumn.width
                    RadioButton {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Ăn tại chỗ")
                        checked: true
                        Material.accent: "#01579B"
                        onClicked: {
                            console.log("dinein");
                            customer_hinhthuc = "dinein";
                        }
                    }
                    RadioButton {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Mang về")
                        Material.accent: "#01579B"
                        onClicked: {
                            console.log("carryout");
                            customer_hinhthuc = "carryout";
                        }
                    }
                }
            }

            Row {
                width: appOptionColumn.width
                spacing: globalPadding
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    id: btnThanhToan
                    width: (appOptionColumn.width*2)/3
                    height: 80
                    highlighted: true
                    enabled: false
                    font.pixelSize: fntsize
                    text: "Thanh toán"
                    Material.accent: "#01579B"
                    onClicked: {
                        // clear search keyword
                        searchFilter = ""
                        // set bill detail to mainController
                        window.customer_name = txtCustomerName.text.trim();
                        if (mainController.getPaymentMethod() === 4 && mainController.isCashAllowed()) {
                            // thanh toán bằng tiền mặt: gửi request hóa đơn lên server, OK in hóa đơn thu tiền
                            cashAlert.cashValue = window.txtThanhTien
                            cashAlert.foodItems = window.global_foodItems;
                            cashAlert.open()
                        }
                        else if (mainController.getPaymentMethod() === 2 && mainController.isCardAllowed()) {
                            // thanh toán thẻ, chờ quẹt thẻ, gửi request hóa đơn lên server, OK in hóa đơn giao khách
                            var foId = mainController.pay(window.customer_name, customer_hinhthuc, window.txtThanhTien, window.global_foodItems, 1)
                            enabled = false
                            mainController.updateCardWaitingPay(true)
                            popQuetthe.totalBill = window.txtThanhTien
                            popQuetthe.open()
                        }
                        else if (mainController.getPaymentMethod() === 1) {
                            // thanh toán qua Zalopay, gửi request lên server, nhận về qr-code show ra và chờ Zalopay gửi tín hiệu thành công để in hóa đơn giao khách
                            var foId_zalopay = mainController.pay(window.customer_name, customer_hinhthuc, window.txtThanhTien, window.global_foodItems, 1)
                            enabled = false
                            payZaloDialog.totalBill = window.txtThanhTien
                            payZaloDialog.foId = foId_zalopay;
                            payZaloDialog.open()
                        }
                        else {
                           appMessage.showMessage("Xin lỗi, chương trình này chỉ hỗ trợ thanh toán bằng Zalopay!")
                        }
                        txtCustomerName.text = "";
                        popupProfile.close()
                    }
                    Connections {
                        target: mainController

                        onPaymentUpdate: {
                            updatePaymentMethod(methods)
                        }

                        onPaymentMask: {
                            updatePaymentMask(paymentMask)
                            idPaymethod.visible = !((paymentMask===1)||(paymentMask===2)||(paymentMask===4))
                        }

                        onUpdateShowthanhtoancungdonhang: {
                            updateShowthanhtoancungdonhang(isShow);
                        }

                        onNotifySucc: {
                            var bClose = true;
                            if (errcode === 0 ) {

                                if (autoThanhtoan.checked === true) {
                                    if ( mainController.getPaymentMethod() === 1 ) {
                                        // === 1 : zalopay
                                        // reset QR code
                                        payZaloDialog.resetQRCode();
                                        payZaloDialog.resetTimer();

                                        // tiếp tục thanh toán cho khách kế tiếp cùng hóa đơn
                                        //var foodItems = choosenItemListView.generateBillDetail()
                                        payZaloDialog.foId = mainController.pay(textThanhtienValue.text, window.global_foodItems, 1);
                                    }
                                    else if ( mainController.getPaymentMethod() === 2 ) {
                                        // === 2 : card
                                    }
                                    else if ( mainController.getPaymentMethod() === 4 ) {
                                        // === 4 : cash - tiền mặt
                                        cashAlert.open();
                                    }

                                    bClose = false;

                                }
                                else {
                                    // xoá hóa đơn đã thanh toán, chờ khách tiếp theo chọn món
                                    textThanhtienValue.text = "0";
                                    button1.enabled = false;
                                    choosenItemListView.cleanup();
                                }
                            }

                            if (bClose == true){
                                if ( mainController.getPaymentMethod() === 1 ) {
                                    // === : zalopay
                                    payZaloDialog.close();
                                }
                                else if ( mainController.getPaymentMethod() === 2 ) {
                                    // === 2 : card
                                    popQuetthe.close();
                                }
                                else if ( mainController.getPaymentMethod() === 4 ) {
                                    // === 4 : cash - tiền mặt
                                    cashAlert.close();
                                }
                            }

                            // open popup dialog to guide user get the bill
                            if ((bClose == true) && (errcode == 0)) {
                                if (mainController.getBillAlertTimer() > 0) {
                                    getBillAlert.open()
                                }
                            }
                        }
                    }
                }
                Button {
                    width: appOptionColumn.width/3
                    height: 80
                    font.pixelSize: fntsize
                    text: "Hủy"
                    onClicked: {
                        txtCustomerName.text = "";
                        popupProfile.close()
                    }
                }
            }
        }
    }
}
