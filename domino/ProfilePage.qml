import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Popup {
    id: profilePage
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    closePolicy: Popup.NoAutoClose
    //focus: true
    modal: true
    clip: true
    width: window.width/4
    contentItem: ColumnLayout {
        id: appOptionColumn
        anchors.horizontalCenter: parent.horizontalCenter
        Layout.alignment: Qt.AlignHCenter
        spacing: 10
        Label {
            text: "NHẬP THÔNG TIN KHÁCH HÀNG"
            Layout.alignment: Qt.AlignHCenter
            font.bold: true
            font.pixelSize: fntsize + 4
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            TextField {
                id: txtCustomerName
                width: appOptionColumn.width
                text: ''
                placeholderText: "Nhập tên Khách Hàng"
                focus: true
                onTextChanged: {
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
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                width: appOptionColumn.width
                RadioButton {
                    id: radioDineIn
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Ăn tại chỗ")
                    checked: true
                    onClicked: {
                        console.log("dinein");
                        customer_hinhthuc = "dinein";
                    }
                }
                RadioButton {
                    id: radioCarryOut
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Mang về")
                    onClicked: {
                        console.log("carryout");
                        customer_hinhthuc = "carryout";
                    }
                }
            }
        }
        Row {
            Layout.alignment: Qt.AlignHCenter
            Button {
                id: btnThanhToan
                width: (appOptionColumn.width*2)/3 -5
                height: 70
                highlighted: true
                enabled: false
                font.pixelSize: fntsize
                text: "Thanh toán"


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
                    radioDineIn.checked = true;
                    txtCustomerName.focus = true;
                    profilePage.close()
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
            Rectangle {
                height: 70
                width: 10
            }
            Button {
                id: btnHuy
                width: appOptionColumn.width/3-5
                height: 70
                font.pixelSize: fntsize
                text: "Hủy"

                onClicked: {
                    txtCustomerName.text = "";
                    radioDineIn.checked = true;
                    txtCustomerName.focus = true;
                    profilePage.close()
                }
            }
        }
    }
}
