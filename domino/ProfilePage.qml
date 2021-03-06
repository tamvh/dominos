import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.VirtualKeyboard 2.1
import QtQuick.VirtualKeyboard.Settings 2.1
import QtQuick.Controls.Styles 1.4
import "content"
import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
Popup {
    id: profilePage
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    closePolicy: Popup.NoAutoClose
    focus: true
//    modal: true
//    dim: true
    topPadding: 30
    rightPadding: 30
    leftPadding: 30
    bottomPadding: 30
    width: 874
    height: 549
    function select_hinhthuc() {
        reset_color();
        if(customer_hinhthuc === 'dinein') {
            radioDineIn.border.color = "#0695D6";
        }

        if(customer_hinhthuc === 'carryout') {
            radioCarryOut.border.color = "#0695D6";
        }
    }

    function init() {
        customer_hinhthuc = 'dinein';
        select_hinhthuc();
    }

    function reset_color() {
        radioDineIn.border.color = "#DDDDDD";
        radioCarryOut.border.color = "#DDDDDD";
    }

    function enable_btnThanhToan(n) {
        if(n > 0) {
            btnThanhToan.enabled = true;
        } else {
            btnThanhToan.enabled = false;
        }
    }

    onVisibleChanged: {
        txtCustomerName.text = "";
        txtCustomerName.focus = true;
        inputPanel.focus = true;
    }

    contentItem: ColumnLayout   {
        id: appOptionColumn
        Layout.alignment: Qt.AlignHCenter
        spacing: 40
        Label {
            text: "NHẬP THÔNG TIN KHÁCH HÀNG"
            Layout.alignment: Qt.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pixelSize: 36
            color: "#0078AE"
        }


        ColumnLayout {
            width: 814
            RowLayout {
                spacing: 10
                Label {
                    width: 814
                    text: "TÊN KHÁCH HÀNG"
                    font.bold: true
                    font.pixelSize: 24
                    color: "#777777"
                }
                Label {
                    id: lblWarning
                    text: "(*) Tên Khách Hàng không được quá " + txtCustomerName.maximumLength + " kí tự"
                    font.pixelSize: 18
                    color: "white"
                }
            }

            TextField {
                id: txtCustomerName
                width: 814
                Layout.fillWidth: true
                text: ''
                Material.primary: "#0695D6"
                Material.accent: "#0695D6"
                font.pixelSize: 36
                maximumLength: 20
                inputMethodHints: Qt.ImhUppercaseOnly
                onTextChanged: {
                    var n = txtCustomerName.text.trim().length;
                    enable_btnThanhToan(n);
                    if(txtCustomerName.text.trim().length === 20) {
                        lblWarning.color = "red";
                    } else {
                        lblWarning.color = "white";
                    }
                }
            }
        }

        ColumnLayout {
            spacing: 10
            Label {
                width: appOptionColumn.width
                text: "TÙY CHỌN"
                font.bold: true
                font.pixelSize: 24
                color: "#777777"
            }
            RowLayout {
                spacing: 20
                Rectangle {
                    id: radioDineIn
                    height: 70
                    width: 178
                    border.color: "#0695D6"
                    border.width: 2
                    radius: 10
                    Text {
                        anchors.centerIn: parent
                        text: qsTr("Ăn tại chỗ")
                        font.bold: true
                        font.pixelSize: 24
                        color: "#000000"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            customer_hinhthuc = "dinein";
                            select_hinhthuc();
                        }
                    }
                }
                Rectangle {
                    id: radioCarryOut
                    height: 70
                    width: 178
                    border.color: "#DDDDDD"
                    border.width: 2
                    radius: 10
                    Text {
                        anchors.centerIn: parent
                        text: qsTr("Mang về")
                        font.bold: true
                        font.pixelSize: 24
                        color: "#000000"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            customer_hinhthuc = "carryout";
                            select_hinhthuc();
                        }
                    }
                }
            }
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: btnThanhToan
                height: 90
                width: 342
                highlighted: true
                enabled: false
                text: qsTr("THANH TOÁN")
                font.pixelSize: 30
                Material.primary: "#0695D6"
                Material.accent: "#0695D6"
                onClicked: {
                    // clear search keyword
                    console.log('begin pay');
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
                    init();
                    window.window_enable = true
                    profilePage.close()
                    mainController.closeThanhtoan(0);
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
//                        if (errcode === 0 ) {

//                            if (g_autoThanhtoan === true) {
//                                if ( mainController.getPaymentMethod() === 1 ) {
//                                    // === 1 : zalopay
//                                    // reset QR code
//                                    payZaloDialog.resetQRCode();
//                                    payZaloDialog.resetTimer();

//                                    // tiếp tục thanh toán cho khách kế tiếp cùng hóa đơn
//                                    //var foodItems = choosenItemListView.generateBillDetail()
//                                    payZaloDialog.foId = mainController.pay(textThanhtienValue.text, window.global_foodItems, 1);
//                                }
//                                else if ( mainController.getPaymentMethod() === 2 ) {
//                                    // === 2 : card
//                                }
//                                else if ( mainController.getPaymentMethod() === 4 ) {
//                                    // === 4 : cash - tiền mặt
//                                    cashAlert.open();
//                                }

//                                bClose = false;

//                            }
//                            else {
//                                // xoá hóa đơn đã thanh toán, chờ khách tiếp theo chọn món
////                                textThanhtienValue.text = "0";
////                                button1.enabled = false;
//                                choosenItemListView.cleanup();
//                            }
//                        }

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
                        console.log("err code: " + errcode);

                        // open popup dialog to guide user get the bill
                        if ((bClose == true) && (errcode == 0)) {
//                            if (mainController.getBillAlertTimer() > 0) {
//                                getBillAlert.open()
//                            }
                        }
                        if ( errcode == 1) {
                            if (mainController.getBillAlertTimer() > 0) {
                                getErrAlert.open()
                            }
                        }
                    }
                }


            }

            Rectangle {
                height: 90
                width: 50
            }

            Button {
                text: "HỦY"
                width: 342
                height: 90
                highlighted: true
                font.pixelSize: 30
                Material.primary: "#8397A0"
                Material.accent: "#8397A0"
                onClicked: {
                    init();                    
                    window.window_enable = true
                    profilePage.close()
                    mainController.closeThanhtoan(0);
                }
            }

        }
    }
}
