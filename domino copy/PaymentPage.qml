import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: pagePaymentPage

    Rectangle {
        height: parent.height
        width: 1
        color: "#E2E6E7"
    }

    ChoosenItemListView {
        anchors.topMargin: window.globalPadding
        anchors.rightMargin: window.globalPadding
        anchors.right: parent.right

        id: choosenItemListView
        anchors.top: parent.top
        anchors.bottom: paymentView.top
        width: parent.width - window.globalPadding
    }

    PaymentView {
        id: paymentView
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.leftMargin: 1
        anchors.bottomMargin: window.globalPadding
    }

    Component.onCompleted: {
        paymentView.citlv = choosenItemListView
    }
}
