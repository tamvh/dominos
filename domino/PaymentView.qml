import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4


Rectangle {
    height: childrenRect.height
    color: "transparent"
    property var citlv: null
    property int txtfntsize: mainController.getConfigFoodItemFontsize()

    function updatePaymentMask(paymentMask) {
        payZalo.enabled = ((paymentMask & 1) === 1)
        payCard.enabled = ((paymentMask & 2) === 2)
        payCash.enabled = ((paymentMask & 4) === 4)
    }

    function updatePaymentMethod(method) {
        if ((method & 1) == 1) {
            payZalo.checked = true
        }

        if ((method & 2) == 2) {
            payCard.checked = true
        }

        if ((method & 4) == 4) {
            payCash.checked = true
        }
    }

    function updateShowthanhtoancungdonhang(isShow) {
        autoThanhtoan.visible = isShow;

        if (isShow === false) {
            // bỏ check nếu không show ra màn hình
            autoThanhtoan.checked = false
        }
    }

    Component.onCompleted: {
        updatePaymentMask(mainController.getPaymentMask())
        updatePaymentMethod(mainController.getPaymentMethod())
    }

    Column {
        width: parent.width
        spacing: 20

        Image {
            id: imageSeparate
            height: 20
            fillMode: Image.Stretch
            cache: true
            source: "qrc:/icons/icons/rangcua.png"
            width: parent.width
        }

        Column {
            width: parent.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: window.globalPadding

            RowLayout {
                Layout.fillWidth: true
                width: parent.width

                Text {
                    id: textThanhtienLabel
                    height: 85
                    anchors.left: parent.left
                    anchors.margins: 20
                    text: qsTr("Tổng tiền:")
                    font.pointSize: txtfntsize + 2
                }

                Text {
                    id: textThanhtienVnd
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 3
                    height: 85
                    text: qsTr("VNĐ")
                    font.pointSize: txtfntsize
                    font.weight: Font.DemiBold
                }

                Text {
                    id: textThanhtienValue
                    anchors.right: textThanhtienVnd.left
                    anchors.margins: 10
                    height: 85
                    text: qsTr("0")
                    font.pointSize: txtfntsize + 2
                    font.weight: Font.DemiBold
                }
            }

            CheckBox {
                id: autoThanhtoan
                text: "Tự động thanh toán cùng đơn hàng"
                visible: mainController.getShowThanhtoancungdonhang();
                checked: false
                enabled: (mainController.getPaymentMethod() === 1)
                anchors.left: parent.left
                anchors.margins: 10
            }

            RowLayout {
                id: idPaymethod
                Layout.fillWidth: true
                visible: !((mainController.getPaymentMask()===1)||(mainController.getPaymentMask()===2)||(mainController.getPaymentMask()===4))
                width: parent.width

                RadioButton {
                    id: payZalo
                    height: 85
                    enabled: false
                    text: qsTr("Zalopay")
                    onClicked: {
                        mainController.setPaymentMethod(1)
                        updateShowthanhtoancungdonhang(autoThanhtoan.visible)
                        autoThanhtoan.enabled = true
                    }
                }

                RadioButton {
                    id: payCard
                    enabled: false
                    text: qsTr("Thẻ")
                    onClicked: {
                        mainController.setPaymentMethod(2)
                        autoThanhtoan.checked = false;
                        autoThanhtoan.enabled = false
                    }
                }

                RadioButton {
                    id: payCash
                    enabled: false
                    text: qsTr("Tiền mặt")
                    onClicked: {
                        mainController.setPaymentMethod(4)
                        autoThanhtoan.checked = false;
                        autoThanhtoan.enabled = false
                    }
                }
            }

            Button {
                id: button1
                anchors.left: parent.left
                anchors.right: parent.right
                height: 80
                text: qsTr("Thanh toán")
                enabled: false
                highlighted: true
                font.pointSize: txtfntsize + 8
                Material.accent: "#01579B"
                onClicked: {
                    window.txtThanhTien = textThanhtienValue.text
                    window.global_foodItems = choosenItemListView.generateBillDetail()
                    idPageProfile.open()
                }
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
                                var foodItems = choosenItemListView.generateBillDetail()
                                payZaloDialog.foId = mainController.pay(textThanhtienValue.text, foodItems, 1);
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

            Connections {
                target: mainController
                onPaySucc: {

                    // update QR code
                    qrimage.visible = true
                    qrimage.setImage("image://colors/" + qrcode)

                    window.txtThanhTien = discpay
                    window.txtGiagoc = oripay + " "
                    window.iDiscount = discount

                    // enable controls
                    idGroupInfos.visible = true;
                    idGroupTimer.visible = true;
                    labelError.visible = false;
                    labelInvoice.text = "#" + invcecode;
                }

                onPayError: {
                    // disable controls
                    idGroupInfos.visible = false;
                    idGroupTimer.visible = false;
                    labelError.visible = true;
                    labelError.text = msg;
                }

                onUpdateAmount: {
                    textThanhtienValue.text = amount
                    if ( amount === "" || amount === "0") {
                        button1.enabled = false
                    }
                    else {
                        button1.enabled = true
                    }
                }

                onCancelBillItem: {
                    textThanhtienValue.text = "0"
                    button1.enabled = false
                }

                onErrorMessage: {
                    errAlertErr.text = "Mã lỗi: " + err;
                    errAlertInfo.text = "Thông tin lỗi: " + msg;
                    errAlert.open();
                }
            }
        }
    }
}
