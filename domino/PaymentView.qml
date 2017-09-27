import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4



Rectangle {
    height: childrenRect.height
    color: "#F5F5F5"
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
            anchors.margins: 10

            RowLayout {
                Layout.fillWidth: true
                width: parent.width

                Text {
                    id: textThanhtienLabel
                    height: 85
                    anchors.left: parent.left
                    anchors.margins: 20
                    text: qsTr("Tổng tiền:")
                    font.pointSize: 30
                    font.bold: true
                }

                Text {
                    id: textThanhtienVnd
                    anchors.right: parent.right
                    height: 85
                    text: qsTr("VNĐ")
                    font.pointSize: 30
                    font.weight: Font.DemiBold
                    color: "#0078AE"
                }

                Text {
                    id: textThanhtienValue
                    anchors.right: textThanhtienVnd.left
                    anchors.margins: 10
                    height: 85
                    text: qsTr("0")
                    font.pointSize: 30
                    font.weight: Font.DemiBold
                    color: "#0078AE"

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
                height: 95
                text: qsTr("Thanh toán")
                enabled: false
                highlighted: true
                font.pointSize: txtfntsize + 8
                Material.primary: "#0695D6"
                Material.accent: "#0695D6"

                onClicked: {
                    window.txtThanhTien = textThanhtienValue.text
                    window.global_foodItems = choosenItemListView.generateBillDetail()
                    window.g_autoThanhtoan = autoThanhtoan.checked;
                    idProfilePage.open()
                }
            }

            Rectangle {
                height: 5
                width: parent.width
                color: "#F5F5F5"
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
