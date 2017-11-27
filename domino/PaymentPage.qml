import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: pagePaymentPage

    Rectangle {
        height: parent.height
        width: 1
        color: "#F5F5F5"
    }

    ChoosenItemListView {
        id: choosenItemListView
        anchors.top: parent.top
        anchors.bottom: paymentView.top
        width: parent.width
    }

    PaymentView {
        id: paymentView
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
    }

    Component.onCompleted: {
        paymentView.citlv = choosenItemListView
    }
}
