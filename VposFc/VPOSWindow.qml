import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

import MainController 1.0
import QmlDefine 1.0
import "dynamicqml"

ApplicationWindow {
    id: window
    width: 800
    height: 600
    visibility: mainController.isDebugmode() ? "Maximized" : Window.FullScreen
    flags: mainController.isDebugmode() ? Qt.Window : Qt.FramelessWindowHint | Qt.Window
    visible: true

    property string txtThanhTien: qsTr("")
    property string txtGiagoc: qsTr("")
    property int iDiscount: 0
    property int globalPadding: 10
    property bool isShowSearch: false
    property int fntsize: (mainController.getConfigBillItemFontsize() + 2)
    property int usrConfColwidth1: 220
    property int usrConfColwidth2: Screen.width - usrConfColwidth1 - 160
    property int admConfColwidth1: 220
    property int admConfColwidth2: 180

    property alias userConfigButtonVisible: userBtnConfig.visible
    property string searchFilter: ""
    property bool idleAlertShowed: false
    property int foodItemcount: 0

    Material.primary: Material.DeepOrange
    Material.accent: Material.DeepOrange

    Component.onCompleted: {
        titleLabel.text = (mainController.getAppTitle() + " - " + mainController.getAppMachine());

        if (mainController.getAppName() === "") {
            idPageLogin.open()
        }
    }

    header: ToolBar {
        Rectangle {
            anchors.fill: parent
            LinearGradient {
                anchors.fill: parent
                start: Qt.point(0, 0)
                end: Qt.point(parent.width, parent.height)

                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#ad3906" }
                    GradientStop { position: 1.0; color: "#ef8422" }
                }

                RowLayout {
                    id: searchBox
                    anchors.fill: parent
                    visible: isShowSearch
                    width: parent.width

                    Rectangle {
                        width: 3
                    }

                    ToolButton {
                        id: tbimg1
                        contentItem: Image {
                            fillMode: Image.Pad
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            source: "qrc:/icons/icons/logo.png"
                        }
                    }

                    Rectangle {
                        anchors.left: tbimg1.right
                        width: parent.width - (tbimg1.width+tbimg2.width)*2
                        height: parent.height - 2
                        radius: parent.height/2
                        border.color: "#333"
                        border.width: 1

                        RowLayout {
                            width: parent.width
                            ToolButton {
                                id: tbimg2
                                contentItem: Image {
                                    fillMode: Image.Stretch
                                    horizontalAlignment: Image.AlignHCenter
                                    verticalAlignment: Image.AlignVCenter
                                    source: "qrc:/icons/icons/search_back.png"
                                }
                                onClicked: {
                                    idSearchbox.text = ""
                                    isShowSearch = !isShowSearch
                                    mainController.uiFoodupdateStatus( isShowSearch ? -4 : 4)
                                }
                            }

                            Image {
                                anchors { top: parent.top; bottom: parent.bottom; right: parent.right; margins: 1 }
                                id: clearText
                                fillMode: Image.Pad
                                smooth: true
                                visible: (idSearchbox.text != "")
                                source: "qrc:/icons/icons/delete.png"
                                height: parent.height //- platformStyle.paddingMedium * 2
                                width: parent.height //- platformStyle.paddingMedium * 2

                                MouseArea {
                                    id: clear
                                    anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }
                                    height: idSearchbox.height; width: idSearchbox.height
                                    onClicked: {
                                        idSearchbox.text = ""
                                        idSearchbox.forceActiveFocus()
                                    }
                                }
                            }

                            Timer {
                                id: idTimer
                                interval: 90000 //90000 = 90 seconds to clear search-filter
                                running: false
                                repeat: false
                                onTriggered: searchFilter = ""
                            }

                            TextField {
                                id: idSearchbox
                                anchors.left: tbimg2.right
                                anchors.right: clearText.left
                                placeholderText: mainController.getConfigSearchadvance() ? "Tên ... hoặc các ký tự đầu, ví dụ bb = Bún Bò" : "Gõ tên ..."
                                text: ""
                                color: "black"
                                focus: true

                                onVisibleChanged: {
                                    if (visible)
                                        placeholderText = mainController.getConfigSearchadvance() ? "Tên ... hoặc các ký tự đầu, ví dụ bb = Bún Bò" : "Gõ tên ..."
                                }

                                onDisplayTextChanged: {
                                    var srchtxt = mainController.viet2latin(text);
                                    if (searchFilter !== srchtxt)
                                    {
                                        searchFilter = srchtxt;
                                        mainController.searchFood(searchFilter);

                                        idTimer.restart()
                                    }
                                }
                            }
                        }
                    }
                }

                RowLayout {
                    anchors.fill: parent
                    visible: !isShowSearch

                    ToolButton {
                        id: toolButtonBack
                        visible: false
                        contentItem: Image {
                            fillMode: Image.Pad
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            source: "qrc:/icons/icons/ic_arrow_back_white_24px.svg"
                        }
                        onClicked: {
                            stackView.pop()
                        }
                    }

                    Rectangle {
                        width: 3
                    }

                    ToolButton {
                        id: vposButton
                        property int settingFlags1: 0
                        property int settingFlags2: 0
                        contentItem: Image {
                            fillMode: Image.Pad
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            source: "qrc:/icons/icons/logo.png"
                        }
                        onClicked: {
                            if (toolBtnSetting.visible === true) {
                                toolBtnSetting.visible = mainController.isDebugmode();
                            }
                            else {
                                if ((settingFlags1 > 0) && ((settingFlags1 + 1) ==  settingFlags2)) {
                                    toolBtnSetting.visible = true
                                }

                                settingFlags1 = 0
                                settingFlags2 = 0
                            }
                        }
                    }

                    FontLoader {
                        id: idFont
                        source: "qrc:/fonts/fonts/UnisectVnuBold.ttf"
                        name: "UnisectVnu"

                    }

                    Label {
                        id: titleLabel
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        Layout.fillWidth: true
                        color: "white"
                        font.pixelSize: 25
                        font.family: idFont.name
                        text: "NONAME"

                        Connections {
                            target: mainController
                            onUpdateTitle: {
                                titleLabel.text = title
                            }
                        }
                    }

                    RowLayout {
                        id: controlBox
                        ToolButton {
                            ToolTip.visible: pressed
                            ToolTip.text: "Tìm kiếm món ăn"
                            ToolTip.timeout: 2000
                            contentItem: Image {
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                source: "qrc:/icons/icons/search_white.png"
                            }
                            onClicked: {
                                idSearchbox.text = ""
                                idSearchbox.focus = true
                                isShowSearch = !isShowSearch
                                mainController.uiFoodupdateStatus( isShowSearch ? -4 : 4)
                            }
                        }

                        ToolButton {
                            id: toolButtonCloud
                            ToolTip.visible: pressed
                            ToolTip.text: "Trạng thái kết nối đến máy chủ VPOS"
                            ToolTip.timeout: 3000

                            contentItem: Image {
                                id: imageCloudStatus
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                source: "qrc:/icons/icons/ic_cloud_queue_white_24px.svg"

                                Connections {
                                    target: mainController
                                    onCloudConnectionChange: {
                                        imageCloudStatus.updateStatus(connected)
                                    }
                                }

                                function updateStatus(connected) {
                                    if (connected) {
                                        source = "qrc:/icons/icons/ic_cloud_done_white_24px.svg"
                                    } else {
                                        source = "qrc:/icons/icons/ic_cloud_off_white_24px.svg"
                                    }
                                }
                            }

                            onClicked: {
                                vposButton.settingFlags1++
                            }
                        }

                        ToolButton {
                            id: toolButtonDock

                            ToolTip.visible: pressed
                            ToolTip.text: "Trạng thái kết nối đến thiết bị"
                            ToolTip.timeout: 3000

                            contentItem: Image {
                                id: imageDockStatus
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter

                                Component.onCompleted: {
                                    updateStatus(mainController.isConnected())
                                }

                                Connections {
                                    target: mainController
                                    onDockConnectionChange: {
                                        imageDockStatus.updateStatus(connected)

                                        if (connected)  {
                                            appMessage.showMessage("Đã kết nối đến thiết bị")
                                        } else {
                                            appMessage.showMessage("Mất kết nối đển thiết bị")
                                        }
                                    }
                                }

                                function updateStatus(connected) {
                                    if (connected) {
                                        source = "qrc:/icons/icons/ic_signal_wifi_4_bar_white_24px.svg"
                                    } else {
                                        source = "qrc:/icons/icons/ic_signal_wifi_off_white_24px.svg"
                                    }
                                }
                            }

                            onClicked: {
                                if (vposButton.settingFlags1===0) {
                                    mainController.scanDock(true);
                                }
                                vposButton.settingFlags2++
                            }
                        }

                        ToolButton {
                            id: userBtnConfig
                            visible: mainController.getUserEnableConfig()
                            contentItem: Image {
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                source: "qrc:/icons/icons/userconfig.png"
                            }
                            onClicked: {
                                idPageLogin.open()
                            }
                        }

                        ToolButton {
                            id: toolBtnSetting
                            visible: mainController.isDebugmode()
                            contentItem: Image {
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                source: "qrc:/icons/icons/menu.png"
                            }
                            onClicked: optionsMenu.open()

                            Menu {
                                id: optionsMenu
                                x: parent.width - width
                                transformOrigin: Menu.TopRight

                                MenuItem {
                                    text: "Cài đặt Thiết bị"
                                    onTriggered:  {
                                        stackView.push(settingPage)
                                    }
                                }
                                MenuItem {
                                    text: "Cài đặt Quầy hàng"
                                    onTriggered:  {
                                        stackView.push(settingPages2)
                                    }
                                }
                                MenuItem {
                                    text: "Cập nhật menu ngay"
                                    onTriggered: {
                                        mainController.checkUpdateFoodData()
                                    }
                                }
                                MenuItem {
                                    text: "Thông tin ứng dụng"
                                    onTriggered: {
                                        systemDialog.open()
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: VposPage {
            onVisibleChanged: {
                if (visible) {
                    toolButtonBack.visible = false
                    userConfigButtonVisible = mainController.getUserEnableConfig()
                } else {
                    toolButtonBack.visible = true
                    userConfigButtonVisible = false
                }
            }
        }
    }

    ToolTip {
        id: appMessage
        timeout: 2000
        x: (parent.width - width) / 2
        y: parent.height / 3

        function showMessage(msg) {
            text = msg
            open()
        }
    }

    Popup {
        // show bảng thanh toán Zalopay
        id: payZaloDialog
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height -  payZaloDialog.height)/3
        closePolicy: Popup.NoAutoClose
        property string totalBill: "0"
        property string foId: "" // foods order ID

        function resetQRCode() {
            qrimage.setImage("")
            labelInvoice.text = ""
            busyIndicatorQR.visible = true
        }

        function resetTimer() {
            qrTimer.restartTimerCounter();
        }

        function doCancelBill() {
            // send signal do cancel bill, and waiting respone ok to close dialog
            mainController.cancelBill(foId, labelInvoice.text, payZaloDialog.totalBill);
        }

        Column {
            id: aboutColumn
            width: implicitHeight
            height: implicitHeight
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Column {
                id: rowContent
                anchors.horizontalCenter: parent.horizontalCenter
                width: implicitWidth
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding

                Label {
                    id: labelTitle
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: fntsize + 4
                    font.weight: Font.DemiBold
                    text: "XÁC NHẬN THANH TOÁN"
                }

                Row {
                    width: childrenRect.width
                    height: childrenRect.height
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10

                    Rectangle {
                        width: 10
                        height: qrimage.height
                    }

                    Rectangle {
                        border.width: 1
                        border.color: "#E2E6E7"
                        width: qrimage.width + 4
                        height: qrimage.height + 4
                        Image {
                            id: qrimage
                            visible: false
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            x: 1
                            y: 1
                            function setImage(url) {source=url;busyIndicatorQR.visible=false}
                        }
                    }

                    Rectangle {
                        width: 10
                        height: qrimage.height
                    }
                }

                Label {
                    // show msg payment if fail
                    id: labelError
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: ""
                    font.pixelSize: fntsize
                }

                Column {
                    id:idGroupInfos
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10
                    Label {
                        id: labelQR
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Quét QR code để thanh toán cho hóa đơn"
                        font.pixelSize: fntsize
                    }

                    RowLayout {
                        anchors.horizontalCenter: parent.horizontalCenter

                        Label {
                            id: labelInvSign
                            font.weight: Font.DemiBold
                            text: ""
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: labelInvoice
                            anchors.left: labelInvSign.right
                            font.weight: Font.DemiBold
                            text: ""
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: labelText1
                            anchors.left: labelInvoice.right
                            text: " với số tiền "
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: labelGiagoc // giá gốc
                            anchors.left: labelText1.right
                            font.weight: Font.DemiBold
                            visible: iDiscount > 0
                            font.strikeout: true
                            font.pixelSize: fntsize - 2
                            text: txtGiagoc
                        }

                        Label {
                            id: labelThanhtien
                            anchors.left: (iDiscount > 0) ? labelGiagoc.right : labelText1.right
                            font.weight: Font.DemiBold
                            color: "#ff0000"
                            text: txtThanhTien
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: labelText2
                            anchors.left: labelThanhtien.right
                            anchors.bottom: labelThanhtien.bottom
                            anchors.bottomMargin: 2
                            color: "#ff0000"
                            font.pixelSize: labelThanhtien.font.pixelSize*2/3
                            text: " VNĐ"
                        }
                    }
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: idGroupTimer
                    BusyIndicator {
                        id: busyIndicatorQR
                        width: 60
                        height: 60
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Column {
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: implicitWidth
                        spacing: 5
                        Label {
                            id: labelTimer
                            text: "Thời gian còn lại:   "
                            font.pixelSize: fntsize
                        }

                        QrTimer {
                            id: qrTimer
                            anchors.left: labelTimer.right
                            anchors.verticalCenter: parent.verticalCenter
                            parentId:payZaloDialog
                        }
                    }
                }
            }

            Row {
                width: rowContent.width
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    height: 60
                    width: mainController.isDebugmode() ? parent.width/2 : parent.width
                    highlighted: true
                    font.pixelSize: fntsize + 4
                    text: "Hủy"
                    onClicked: {
                        payZaloDialog.doCancelBill()
                    }
                }

                Button {
                    height: 60
                    width: parent.width/2
                    highlighted: true
                    font.pixelSize: fntsize + 4
                    text: "Giả Zalopay"
                    visible: mainController.isDebugmode()
                    onClicked: {
                        payZaloDialog.doCancelBill()
                    }
                }
            }
        }

        onOpened: {
            qrTimer.parentId = 1;
            qrTimer.restartTimerCounter();
            idleAlertShowed = true;
        }

        onClosed: {
            qrTimer.stopTimerCounter();
            resetQRCode()
            mainController.stopDevice()
            idleAlertShowed = false;
        }

        Connections {
            target: mainController
            onCancellBillCloseQRDialog: {
                payZaloDialog.close();
            }
        }
    }

    Popup {
        id: popQuetthe
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height -  popQuetthe.height)/3
        closePolicy: Popup.NoAutoClose

        property string totalBill: "0"

        Column {
            id: qtaboutColumn
            height: implicitHeight
            width: qtrowContent.width
            spacing: 10

            Column {
                id: qtrowContent
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding
                width: implicitWidth + 60

                Label {
                    id: qtlabelTitle
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: fntsize + 4
                    font.weight: Font.DemiBold
                    text: "XÁC NHẬN THANH TOÁN"
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10

                    Label {
                        id: qtlabelQR
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Quét thẻ để thanh toán đơn hàng"
                        font.pixelSize: fntsize
                    }

                    RowLayout {
                        id:qtrowInfos
                        anchors.horizontalCenter: parent.horizontalCenter

                        Label {
                            id: qtlabelText1
                            text: " với số tiền "
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: qtlabelThanhtien
                            anchors.left: qtlabelText1.right
                            font.weight: Font.DemiBold
                            color: "#ff0000"
                            text: txtThanhTien
                            font.pixelSize: fntsize
                        }

                        Label {
                            id: qtlabelText2
                            anchors.left: qtlabelThanhtien.right
                            anchors.bottom: qtlabelThanhtien.bottom
                            anchors.bottomMargin: 2
                            color: "#ff0000"
                            font.pointSize: qtlabelThanhtien.font.pointSize*2/3
                            text: " VNĐ"
                        }
                    }
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    AnimatedImage {
                        width: 200
                        height:250
                        source: "qrc:/icons/images/docheckin.gif"
                    }
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: implicitWidth
                    spacing: 5
                    Label {
                        id: qtlabelTimer
                        text: "Thời gian còn lại:   "
                        font.pixelSize: fntsize
                    }

                    QrTimer {
                        id: qtqrTimer
                        anchors.left: qtlabelTimer.right
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                Row {
                    // code cho DEV only
                    visible: false
                    anchors.horizontalCenter: parent.horizontalCenter
                    Layout.fillWidth: true
                    height: 30
                    spacing: 30
                    Label {
                        id: idmathetitle
                        text:"Mã thẻ"
                        //anchors.horizontalCenter: parent.horizontalCenter
                    }
                    TextInput {
                        id: idmathe
                        text: "CFFB7B"
                        width: 100
                        //anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Button {
                        id: idnhanthe
                        text: "Nhận thẻ"
                        //anchors.horizontalCenter: parent.horizontalCenter
                        onClicked: {
                            mainController.giaQuetthe(idmathe.text)
                        }
                    }
                }
            }

            Button {
                width: 200
                font.pixelSize: fntsize
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Hủy"
                onClicked: {
                    mainController.cancelBill("", "", popQuetthe.totalBill);
                    popQuetthe.close()
                }
            }
        }

        onOpened: {
            qtqrTimer.restartTimerCounter();
        }

        onClosed: {
            qtqrTimer.stopTimerCounter();
        }

        Connections {
            target: mainController
            onCardPayment: {
                mainController.payCash(popQuetthe.totalBill, cardId, 2)
                popQuetthe.close();
            }
        }
    }

    Popup {
        // show bảng thông báo thanh toán Tiền mặt
        id: cashAlert
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height - cashAlert.height) / 3
        closePolicy: Popup.NoAutoClose
        property string cashValue: "0"
        property var foodItems;

        Column {
            id: cashAlertColumn
            width: implicitWidth
            height: implicitHeight
            spacing: 10

            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: fntsize + 4
                    font.weight: Font.DemiBold
                    text: "XÁC NHẬN THANH TOÁN"
                }

                Rectangle {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: childrenRect.width + 2
                    height: childrenRect.height + 2
                    Image {
                        x: 1
                        y: 1
                        source: "qrc:/icons/images/cash.png"
                    }
                }

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Label {
                        text: "Tiền mặt "
                        font.pixelSize: fntsize
                    }
                    Label {
                        id: labelCashvalue
                        font.weight: Font.DemiBold
                        color: "#ff0000"
                        text: cashAlert.cashValue
                        font.pixelSize: fntsize
                    }

                    Label {
                        text: " VNĐ"
                        font.pixelSize: fntsize
                    }
                }

                Row {
                    spacing: globalPadding
                    anchors.horizontalCenter: parent.horizontalCenter
                    Button {
                        width: 140
                        highlighted: true
                        font.pixelSize: fntsize
                        text: "Thanh toán"
                        onClicked: {
                            mainController.pay(cashAlert.cashValue, cashAlert.foodItems, 4)
                            cashAlert.close()
                        }
                    }
                    Button {
                        width: 140
                        font.pixelSize: fntsize
                        text: "Hủy"
                        onClicked: {
                            mainController.sendCancelBillUI();
                            cashAlert.close()
                        }
                    }
                }
            }
        }
    }

    Popup {
        // show bảng báo nhận hóa đơn
        id: getBillAlert
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height - getBillAlert.height) / 3
        closePolicy: Popup.NoAutoClose

        Column {
            id: billAlertColumn
            width: implicitWidth
            height: implicitHeight
            spacing: 10

            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding
                width: implicitWidth
                height: implicitHeight

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: fntsize + 4
                    font.weight: Font.DemiBold
                    text: "THANH TOÁN THÀNH CÔNG"
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
                    font.pixelSize: fntsize
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: implicitWidth
                    spacing: 5
                    Label {
                        id: labelTimerBillAlert
                        text: "Thời gian còn lại:   "
                        font.pixelSize: fntsize
                    }

                    QrTimer {
                        id: getBillTimer
                        anchors.left: labelTimerBillAlert.right
                        anchors.verticalCenter: parent.verticalCenter
                        delayTimer:mainController.getBillAlertTimer()*1000  //1000 = 1s
                    }
                }

                Button {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: billAlertColumn.width
                    highlighted: true
                    font.pixelSize: fntsize
                    text: "Đóng"
                    onClicked: {
                        getBillAlert.close()
                    }
                }
            }
        }

        onOpened: {
            getBillTimer.parentId = 2;
            getBillTimer.restartTimerCounter();
        }

        onClosed: {
            getBillTimer.stopTimerCounter();
        }
    }

    Popup {
        id: systemDialog
        modal: true
        focus: true
        width: 360
        height: 220
        x: (window.width - width) / 2
        y: (window.height -  height)/3
        font.pixelSize: 14

        contentItem: ColumnLayout {
            spacing: globalPadding
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Label {
                text: "Thông tin ứng dụng"
                Layout.alignment: Qt.AlignHCenter
                font.bold: true
            }

            Row {
                Column {
                    width:110
                    spacing: globalPadding
                    Label {
                        text: "App version:"
                    }
                    Label {
                        text: "Build date:"
                    }
                    Label {
                        text: "Merchant ID:"
                    }
                    Label {
                        text: "Server: "
                    }
                    Label {
                        text: "Dock version:"
                    }
                    Label {
                        text: "Printer type:"
                    }
                }

                Column {
                    width:240
                    spacing: globalPadding
                    Label {
                        text: qmlDefine.appVersion()
                    }
                    Label {
                        text: qmlDefine.buildDate()
                    }
                    Label {
                        id: appUser
                    }
                    Label {
                        id: lblService
                    }
                    Label {
                        id: dockVersion
                    }
                    Label {
                        id: printerType
                    }
                }
            }
        }

        onVisibleChanged: {
            if (visible) {
                appUser.text = mainController.getAppName();
                lblService.text = mainController.getUrlService();
                dockVersion.text = mainController.getConfigDockversion();
                printerType.text = mainController.getConfigPrintersize();
            }
        }
    }

    Popup {
        id: printerMessageDialog
        modal: true
        focus: true
        x: (window.width - width)/2
        y: (window.height - height)/2
        closePolicy: Popup.NoAutoClose

        Connections {
            target: mainController
            onPrinterReadyChanged: {
                if (ready === false) {
                    printerMessageDialog.showMessage(false, "Máy in chưa sẵn sàng vui lòng kiểm tra lại máy in")
                    appMessage.showMessage("Máy in chưa sẵn sàng !!!")
                } else {
                    printerMessageDialog.showMessage(true, "Máy in đã sẵn sàng")
                    appMessage.showMessage("Máy in đã sẵn sàng")
                }
            }
        }

        contentItem: ColumnLayout {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                text: "Thông báo"
                font.bold: true
            }

            ColumnLayout {
                spacing: 10
                Label {
                    id: lblMessage
                }

                RowLayout {
                    spacing: 10
                    Layout.fillWidth: true
                    Button {
                        id: btnClose
                        text: "Đóng"
                        highlighted: true
                        Layout.preferredWidth: 0
                        Layout.fillWidth: true
                        onClicked: {
                            printerMessageDialog.close()
                        }
                    }

                    Button {
                        id: btnCheck
                        text: "Kiểm tra"
                        highlighted: true
                        Layout.preferredWidth: 0
                        Layout.fillWidth: true

                        onClicked: {
                            mainController.checkPrinterStatus()
                        }
                    }
                }
            }
        }

        function showMessage(ready, msg) {
            lblMessage.text = msg
            if (!visible)
                open()
            if (ready) {
                close()
            } else {
                btnClose.enabled = false
                btnCheck.visible = true
            }
        }
    }

    Popup {
        id: errAlert
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: (window.height -  height)/2
        closePolicy: Popup.NoAutoClose

        contentItem: Column {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                text: "Mạng Lỗi"
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Column {
                Layout.fillWidth: true
                Label {
                    id: errAlertErr
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Mã lỗi: "
                }

                Label {
                    id: errAlertInfo
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Thông tin lỗi: "
                }
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 100
                highlighted: true
                font.pointSize: 16
                text: "Đóng"
                onClicked: {
                    errAlert.close()
                }
            }
        }
    }

    Popup {
        // show bảng thông báo xóa danh sách thực đơn
        id: systemIdleAlert
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height - systemIdleAlert.height) / 3
        closePolicy: Popup.NoAutoClose
        margins: 10

        Column {
            id: billAlertColumn1
            width: implicitWidth
            height: implicitHeight
            spacing: 10

            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding
                width: implicitWidth
                height: implicitHeight

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: fntsize + 4
                    font.weight: Font.DemiBold
                    text: "HẾT THỜI GIAN CHỜ"
                }

//                Rectangle {
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    width: childrenRect.width + 2
//                    height: childrenRect.height + 2
//                    Image {
//                        x: 1
//                        y: 1
//                        source: "qrc:/icons/images/billonprinter.png"
//                    }
//                }

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Danh sách đơn hàng sẽ được xóa!"
                    font.pixelSize: fntsize
                }

                Column {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: implicitWidth
                    spacing: 5
                    Label {
                        id: labelTimerBillAlert1
                        text: "Thời gian còn lại:   "
                        font.pixelSize: fntsize
                    }

                    QrTimer {
                        id: idleTimer
                        anchors.left: labelTimerBillAlert1.right
                        anchors.verticalCenter: parent.verticalCenter
                        delayTimer:mainController.getBillAlertTimer()*1000  //1000 = 1s
                    }
                }

                Button {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: billAlertColumn1.width
                    highlighted: true
                    font.pixelSize: fntsize
                    text: "Không xóa"
                    onClicked: {
                        mainController.idleReset();
                        systemIdleAlert.close()
                    }
                }
            }
        }

        onOpened: {
            idleAlertShowed = true;
            idleTimer.parentId = 3;
            idleTimer.restartTimerCounter();
        }

        onClosed: {
            idleTimer.stopTimerCounter();
            idleAlertShowed = false;
        }
    }

    UserConfigPage {
        id: userConfigPage
    }

    SettingPages {
        id: settingPages2
    }

    LoginPage {
        id: idPageLogin
    }

    AccountPage {
        id: accountPage
    }

    Connections {
        target: mainController
        onIdleTimeout: {
            if( (idleAlertShowed === false) && (foodItemcount > 0) ) {
                systemIdleAlert.open();
            }
        }
    }
}
