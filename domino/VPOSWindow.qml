import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

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

    property string searchFilter: ""
    property bool idleAlertShowed: false
    property int foodItemcount: 0

    property string url_img: qsTr("")
    property string obj_data: qsTr("")
    property string pizza_prod_code: qsTr("")
    property string pizza_prod_name: qsTr("")
    property string pizza_debanh_id: qsTr("TC")
    property string pizza_sizebanh_id: qsTr("7")
    property string pizza_sizebanh: qsTr("7\"")
    property string pizza_debanh: qsTr("Đế mỏng")
    property string pizza_money: qsTr("")
    property string pizza_money_root: qsTr("")
    property string min_size: qsTr("")
    property string pizza_category: qsTr("")
    property string pizza_prize: qsTr("")
    property string pizza_prize_7: qsTr("")
    property string pizza_prize_9: qsTr("")
    property string pizza_prize_12: qsTr("")
    property string promote_price: qsTr("")
    property int nItem: 1
    property int nChessy: 0
    property var global_foodItems;
    property string customer_name: qsTr("")
    property string customer_hinhthuc: qsTr("dinein")
    property string name_code: qsTr("")
    property bool enable_cheesy: false
    property double opacity_cheesy: 1.0
    property string cheesy_text: qsTr("")
    property double opacity_rect_pizzasize_small: 1.0
    property int styleData_row: -1
    property string prodNameInPaymenView: qsTr("")
    property string  zoom_prod_name: qsTr("")
    property string  zoom_prod_img: qsTr("")
    property string  zoom_prod_thanhphan: qsTr("")

    property bool visible_imgchk_7: false
    property bool visible_imgchk_9: false
    property bool visible_imgchk_12: false

    property bool visible_demong: false
    property bool visible_devua: false
    property bool visible_deday: false
    property bool visible_dephomaimong: false
    property bool visible_dephomaiday: false

    property bool pressbtn_selected: true
    property bool g_autoThanhtoan: false



    Material.primary: "#006493"
    Material.accent: "#006493" //"#01579B"

    function getTotalMoney() {
        //get money
        var total_money = 0;

        var json_data = JSON.parse(obj_data);
        var local_money = 0;
        console.log("pizza_sizebanh_id: " + pizza_sizebanh_id);
        console.log("pizza_debanh_id: " + pizza_debanh_id);
        for(var i in json_data) {
            var obj = json_data[i];
            if(pizza_sizebanh_id === obj.SizeCode && pizza_debanh_id === obj.FlavorCode) {
                local_money = obj.Price10;
                pizza_prize = obj.Price10;
                name_code = obj.ProductCode;
                break;
            }
        }

        pizza_money = mainController.moneyMoney(local_money);
        return pizza_money;
    }

    function check_min_size()
    {
        var result_check_min_size = false;
        if(min_size === "7") {
            check_sizebanh(7);
            pizza_sizebanh_id = "7";
            pizza_sizebanh = qsTr("7\"");
            result_check_min_size = true;
            getMoney(7, 1);
        } else {
            check_sizebanh(9);
            pizza_sizebanh_id = "9";
            pizza_sizebanh = qsTr("9\"");
            result_check_min_size = false;
            getMoney(9, 1);
        }
        return result_check_min_size;
    }

    function init_check_debanh(){
        reset_debanh();
        select_debanh("de_mong");
        return true;
    }

    function getMoney(cateName, sizebanh_id, soluong) {
        var local_money = 0;
        if(cateName === 'Pizza Favorite') {
            if(sizebanh_id === "7") {
                local_money = 59000
            }
            if(sizebanh_id === "9") {
                local_money = 119000
            }
            if(sizebanh_id === "12") {
                local_money = 179000
            }
        }
        if(cateName === 'Pizza Classic') {
            if(sizebanh_id === "7") {
                local_money = 69000
            }
            if(sizebanh_id === "9") {
                local_money = 129000
            }
            if(sizebanh_id === "12") {
                local_money = 199000
            }
        }
        if(cateName === 'Pizza Premium') {
            if(sizebanh_id === "7") {
                local_money = 79000
            }
            if(sizebanh_id === "9") {
                local_money = 139000
            }
            if(sizebanh_id === "12") {
                local_money = 219000
            }
        }
        if(cateName === 'Pizza Signature') {
            if(sizebanh_id === "9") {
                local_money = 179000
            }
            if(sizebanh_id === "12") {
                local_money = 279000
            }
        }

        pizza_prize = mainController.moneyMoney(local_money);
        promote_price = mainController.moneyMoney(mainController.getPriceCoupon(local_money, sizebanh_id));

        if(promote_price === "0") {
            promote_price = pizza_prize;
            pizza_prize = "";
        }
        pizza_money_root = mainController.moneyMoney(soluong * mainController.getMoneyValue(pizza_prize));
        if(pizza_money_root === "0") {
            pizza_money_root = "";
        }
        local_money = soluong * mainController.getMoneyValue(promote_price);
        if(pizza_sizebanh_id === "9") {
            if(nChessy === 1) {
                local_money = local_money + soluong*10000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*10000);
            }
            if(nChessy === 2) {
                local_money = local_money + soluong*20000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*20000);
            }
            if(nChessy === 3) {
                local_money = local_money + soluong*30000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*30000);
            }
        }

        if(pizza_sizebanh_id === "12") {
            if(nChessy === 1) {
                local_money = local_money + soluong*15000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*15000);
            }
            if(nChessy === 2) {
                local_money = local_money + soluong*30000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*30000);
            }
            if(nChessy === 3) {
                local_money = local_money + soluong*45000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*45000);
            }
        }

        if(pizza_debanh_id === "CC" || pizza_debanh_id === "TCC") {
            if(pizza_sizebanh_id === "9") {
                local_money = local_money + soluong*49000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*49000);
            }
            if(pizza_sizebanh_id === "12") {
                local_money = local_money + soluong*69000;
                pizza_money_root = mainController.moneyMoney(mainController.getMoneyValue(pizza_money_root) + soluong*69000);
            }
        }

        pizza_money = mainController.moneyMoney(local_money);

    }

    function select_sizebanh(sizebanh) {
        reset_sizebanh();
        reset_color_sizebanh();
        if(sizebanh === 7) {
            pizza_sizebanh = qsTr("7\"")
            pizza_sizebanh_id = "7"
            check_sizebanh(7)
            enable_cheesy = false
            opacity_cheesy = 0.2
            if(pizza_debanh_id === "CC" || pizza_debanh_id === "TCC" || pizza_debanh_id === "NY") {
                pizza_debanh_id = "TC";
                select_debanh("de_mong");
            }

            nChessy = 0;
            txtPercentCheesy.text = getPercentCheesy(nChessy);

            rect_pizzasize_small.border.color = "#0695D6"
        } else if(sizebanh === 9) {
            pizza_sizebanh = qsTr("9\"")
            pizza_sizebanh_id = "9"
            check_sizebanh(9)
            enable_cheesy = true
            opacity_cheesy = 1.0
            rect_pizzasize_avg.border.color = "#0695D6"
        } else if(sizebanh === 12) {
            pizza_sizebanh = qsTr("12\"")
            pizza_sizebanh_id = "12"
            check_sizebanh(12)
            enable_cheesy = true
            opacity_cheesy = 1.0
            rect_pizzasize_big.border.color = "#0695D6"
        }
        getMoney(pizza_category, pizza_sizebanh_id, nItem)
    }

    function reset_color_sizebanh() {
        rect_pizzasize_small.border.color = "#DDDDDD"
        rect_pizzasize_avg.border.color = "#DDDDDD"
        rect_pizzasize_big.border.color = "#DDDDDD"
    }

    function reset_color_debanh() {
        rectDemong.border.color = "#DDDDDD"
        rectDevua.border.color = "#DDDDDD"
        rectDeday.border.color = "#DDDDDD"
        rectVienphomaiMong.border.color = "#DDDDDD"
        rectVienphomaiDay.border.color = "#DDDDDD"
    }

    function check_sizebanh(sizebanh) {
        reset_sizebanh();
        if(sizebanh === 7) {
            visible_imgchk_7 = true;
        } else if(sizebanh === 9) {
            visible_imgchk_9 = true;
        } else if(sizebanh === 12) {
            visible_imgchk_12 = true;
        }
    }

    function reset_sizebanh() {
        visible_imgchk_7 = false;
        visible_imgchk_9 = false;
        visible_imgchk_12 = false;
    }

    function select_debanh(debanh) {
        check_debanh(debanh);
        reset_color_debanh()
        if(debanh === "de_mong") {
            pizza_debanh = "Đế mỏng"
            rectDemong.border.color = "#0695D6"
        } else if(debanh === "de_vua") {
            pizza_debanh = "Đế vừa";
            rectDevua.border.color = "#0695D6"
        } else if( debanh === "de_day") {
            pizza_debanh = "Đế dày";
            rectDeday.border.color = "#0695D6"
        } else if(debanh === "de_cheesy") {
            pizza_debanh = "Viền phô mai dày";
            rectVienphomaiDay.border.color = "#0695D6"
        } else if(debanh === "de_thin_cheesy") {
            pizza_debanh = "Viền phô mai mỏng";
            rectVienphomaiMong.border.color = "#0695D6"
        }
        getMoney(pizza_category, pizza_sizebanh_id, nItem)
    }

    function check_debanh(debanh) {
        reset_debanh();
        if(debanh === "de_mong") {
            visible_demong = true;
        } else if(debanh === "de_vua") {
            visible_devua = true;
        } else if( debanh === "de_day") {
            visible_deday = true;
        } else if( debanh === "de_thin_cheesy") {
            visible_dephomaimong = true;
        } else if( debanh === "de_cheesy") {
            visible_dephomaiday = true;
        }
    }

    function reset_debanh() {
        visible_demong = false;
        visible_devua = false;
        visible_deday = false;
        visible_dephomaimong = false;
        visible_dephomaiday = false;
    }


    function reset(cateName) {
        nItem = 1;
        txtTotalItem.text = nItem
        if(cateName === "Pizza Signature") {
            select_sizebanh(9)
            rect_pizzasize_small.enabled = false
            enable_cheesy = true;
            opacity_cheesy = 1.0;
            opacity_rect_pizzasize_small = 0.2
        } else {
            select_sizebanh(7)
            rect_pizzasize_small.enabled = true
            enable_cheesy = false;
            opacity_cheesy = 0.2;
            opacity_rect_pizzasize_small = 1.0
        }
        select_debanh('de_mong');
        nChessy = 0;
        pizza_debanh_id = "TC";
        txtPercentCheesy.text = getPercentCheesy(0);
        btnSelectItem.enabled = pressbtn_selected;
    }

    function getPercentCheesy(n){
        var _percentcheesy = "0%";
        cheesy_text = "";
        if(n === 0) {
            _percentcheesy = "0%";
        } else if(n === 1) {
            _percentcheesy = "50%";
            cheesy_text = "Thêm phô mai: 50%";
        } else if(n === 2) {
            _percentcheesy = "100%";
            cheesy_text = "Thêm phô mai: 100%";
        } else if(n === 3) {
            _percentcheesy = "200%";
            cheesy_text = "Thêm phô mai: 200%";
        }
        return _percentcheesy;
    }

    Component.onCompleted: {
        titleLabel.text = mainController.getAppMachine();

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
                    GradientStop { position: 0.0; color: "#006493" }
                    GradientStop { position: 1.0; color: "#006493" }
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
                                if (settingFlags1 > 0) {
                                    toolBtnSetting.visible = true
                                }

                                settingFlags1 = 0
                            }
                            idAboutPage.open();
                        }
                    }

                    FontLoader {
                        id: idFont
                        source: "qrc:/fonts/fonts/UnisectVnuBold.ttf"
                        name: "UnisectVnu"

                    }
                    RowLayout {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        Image {
                            id: imgLogoDominos
                            source: "qrc:/icons/images/app/dominos_logo_vertical.svg"
                            height: 45
                            width: 150
                        }

                    }


                    RowLayout {
                        id: controlBox
                        anchors.right: parent.right
                        anchors.rightMargin: 5
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
                            id: toolBtnSetting
                            visible: mainController.isDebugmode()
                            contentItem: Image {
                                fillMode: Image.Pad
                                horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                source: "qrc:/icons/icons/menu.png"
                            }
                            onClicked: {
                                optionsMenu.open()
                            }

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
        id: cakeInfoDialog
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height -  cakeInfoDialog.height)/3
        closePolicy: Popup.NoAutoClose
        width: 1095
        height: 922
        topPadding: 30
        rightPadding: 30
        leftPadding: 30
        bottomPadding: 30
        Column {
            id: columnContentCakeInfo
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20

            Column {
                id: columnHeader
                anchors.horizontalCenter: parent.horizontalCenter
                width: implicitWidth
                spacing: 10
                topPadding: globalPadding
                bottomPadding: globalPadding
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 36
                    font.bold: true
                    text: "VUI LÒNG CHỌN THÔNG TIN LOẠI BÁNH"
                    color: "#0078AE"
                }
            }


            ColumnLayout {
                spacing: 30
                width: 1035
                Row {
                    ColumnLayout {
                        spacing: 10
                        Label {
                            text: "TÊN BÁNH"
                            font.pixelSize: 20
                            font.bold: true
                            color: "#777777"
                        }
                        Label {
                            text: window.pizza_prod_name.replace('\n', ' ')
                            font.pixelSize: 24
                            font.bold: true
                            color: "#000000"
                        }
                    }
                }
                Row {
                    ColumnLayout {
                        spacing: 10
                        Label {
                            text: "SIZE BÁNH"
                            font.pixelSize: 20
                            font.bold: true
                            color: "#777777"
                        }
                        RowLayout {
                            id: idKichthuocBanh
                            width: 1035
                            spacing: 30
                            Rectangle {
                                id: rect_pizzasize_small
                                opacity: opacity_rect_pizzasize_small
                                width: 325
                                height: 112
                                radius: 10
                                border.width: 2
                                border.color: "#0695D6"
                                RowLayout {
                                    id: pizzasize_7
                                    anchors.centerIn: parent
                                    Item {
                                        height: 72
                                        width: 72
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/size_7.png'
                                        }
                                    }
                                    ColumnLayout {
                                        Label {
                                            text: "Cỡ nhỏ (7\") - 4 miếng"
                                            font.bold: true
                                            font.pixelSize: 18
                                            color: "#000000"
                                        }
                                        Label {
                                            text: pizza_prize_7 + " VNĐ"
                                            font.bold: true
                                            font.pixelSize: 30
                                            color: "#000000"
                                        }
                                    }
                                }



                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        select_sizebanh(7)
                                    }
                                }
                            }
                            Rectangle {
                                id: rect_pizzasize_avg
                                width: 325
                                height: 112
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                RowLayout {
                                    id: pizzasize_9
                                    anchors.centerIn: parent
                                    Item {
                                        height: 72
                                        width: 72
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            anchors.margins: 2
                                            source: 'qrc:/icons/images/app/size_9.png'
                                        }
                                    }
                                    Column {
                                        Label {
                                            text: "Cỡ vừa (9\") - 6 miếng"
                                            font.bold: true
                                            font.pixelSize: 18
                                            color: "#000000"
                                        }
                                        Label {
                                            text: mainController.moneyMoney(mainController.getPriceCoupon(mainController.getMoneyValue(pizza_prize_9), "12")) + "VNĐ"
                                            font.bold: true
                                            font.pixelSize: 30
                                            color: "#000000"
                                        }
                                        Label {
                                            text: pizza_prize_9 + " VNĐ"
                                            font.bold: true
                                            font.pixelSize: 20
                                            font.strikeout: true
                                            color: "#9B9B9B"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        select_sizebanh(9)
                                    }
                                }
                            }
                            Rectangle {
                                id: rect_pizzasize_big
                                width: 325
                                height: 112
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                RowLayout {
                                    id: pizzasize_12
                                    anchors.centerIn: parent
                                    Item {
                                        height: 72
                                        width: 72
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            anchors.margins: 2
                                            source: 'qrc:/icons/images/app/size_12.png'
                                        }
                                    }
                                    Column {
                                        Label {
                                            text: "Cỡ to (12\") - 8 miếng"
                                            font.bold: true
                                            font.pixelSize: 18
                                            color: "#000000"
                                        }
                                        Label {
                                            text: mainController.moneyMoney(mainController.getPriceCoupon(mainController.getMoneyValue(pizza_prize_12), "12")) + "VNĐ"
                                            font.bold: true
                                            font.pixelSize: 30
                                            color: "#000000"
                                        }
                                        Label {
                                            text: pizza_prize_12 + " VNĐ"
                                            font.bold: true
                                            font.pixelSize: 20
                                            font.strikeout: true
                                            color: "#9B9B9B"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        select_sizebanh(12)
                                    }
                                }
                            }
                        }
                    }
                }

                Row {
                    ColumnLayout {
                        spacing: 10
                        Label {
                            text: "ĐẾ BÁNH"
                            font.pixelSize: 20
                            font.bold: true
                            color: "#777777"
                        }
                        RowLayout {
                            id: idDebanh
                            width: 1035
                            spacing: 35.5
                            Rectangle {
                                id: rectDemong
                                width: 178
                                height: 106
                                radius: 10
                                border.width: 2
                                border.color: "#0695D6"
                                ColumnLayout {
                                    anchors.centerIn: parent
                                    spacing: 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Item {
                                        height: 26.53
                                        width: 71
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/icon-thickness-thin.svg'
                                        }
                                    }
                                    Column {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Label {
                                            text: "Đế mỏng"
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            font.pixelSize: 18
                                            font.bold: true
                                            color: "#000000"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        pizza_debanh_id = "TC"
                                        select_debanh("de_mong")
                                    }
                                }
                            }
                            Rectangle {
                                id: rectDevua
                                enabled: enable_cheesy
                                opacity: opacity_cheesy
                                width: 178
                                height: 106
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                ColumnLayout {
                                    anchors.centerIn: parent
                                    spacing: 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Item {
                                        height: 26.53
                                        width: 71
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/icon-thickness-med.svg'
                                        }
                                    }
                                    Column {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Label {
                                            text: "Đế vừa"
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            font.pixelSize: 18
                                            font.bold: true
                                            color: "#000000"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        pizza_debanh_id = "NY"
                                        select_debanh("de_vua")
                                    }
                                }

                            }
                            Rectangle {
                                id: rectDeday
                                width: 178
                                height: 106
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                ColumnLayout {
                                    anchors.centerIn: parent
                                    spacing: 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Item {
                                        height: 26.53
                                        width: 71
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/icon-thickness-thick.svg'
                                        }
                                    }
                                    Column {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Label {
                                            text: "Đế dày"
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            font.pixelSize: 18
                                            font.bold: true
                                            color: "#000000"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        pizza_debanh_id = "HT"
                                        select_debanh("de_day")
                                    }
                                }
                            }
                            Rectangle {
                                id: rectVienphomaiMong
                                enabled: enable_cheesy
                                opacity: opacity_cheesy
                                width: 178
                                height: 106
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                ColumnLayout {
                                    anchors.centerIn: parent
                                    spacing: 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Item {
                                        height: 26.53
                                        width: 71
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/icon-cheese-side-thin.svg'
                                        }
                                    }
                                    Column {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Label {
                                            text: "Phô mai mỏng"
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            font.pixelSize: 18
                                            font.bold: true
                                            color: "#000000"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        pizza_debanh_id = "TCC"
                                        select_debanh("de_thin_cheesy")
                                    }
                                }
                            }
                            Rectangle {
                                id: rectVienphomaiDay
                                enabled: enable_cheesy
                                opacity: opacity_cheesy
                                width: 178
                                height: 106
                                radius: 10
                                border.width: 2
                                border.color: "#DDDDDD"
                                ColumnLayout {
                                    anchors.centerIn: parent
                                    spacing: 10
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Item {
                                        height: 26.53
                                        width: 71
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Image {
                                            fillMode: Image.Stretch
                                            anchors.fill: parent
                                            source: 'qrc:/icons/images/app/icon-cheese-side-thick.svg'
                                        }
                                    }
                                    Column {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        Label {
                                            text: "Phô mai dày"
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            font.pixelSize: 18
                                            font.bold: true
                                            color: "#000000"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        pizza_debanh_id = "CC"
                                        select_debanh("de_cheesy")
                                    }
                                }
                            }

                        }
                    }
                }

                Row {
                    RowLayout {
                        spacing: 80
                        ColumnLayout {
                            spacing: 10
                            Label {
                                text: "THÊM PHÔ MAI"
                                enabled: enable_cheesy
                                opacity: opacity_cheesy
                                font.pixelSize: 20
                                font.bold: true
                                color: "#777777"
                            }
                            Row {
                                width: 300
                                enabled: enable_cheesy
                                opacity: opacity_cheesy
                                Rectangle {
                                    height: 60
                                    width:  60
                                    color: "#0695D6"
                                    radius: 3
                                    Label {
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        text: "-"
                                        color: "white"
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if(nChessy > 0) {
                                                nChessy -= 1;
                                                txtPercentCheesy.text = getPercentCheesy(nChessy);
                                                getMoney(pizza_category, pizza_sizebanh_id, nItem);
                                            }
                                        }
                                    }
                                }

                                Rectangle {
                                    height: 60
                                    width:  130
                                    color: "#F2F2F2"
                                    Label {
                                        id:txtPercentCheesy
                                        text: getPercentCheesy(nChessy)
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        color: "#000000"
                                    }
                                }

                                Rectangle {
                                    height: 60
                                    width:  60
                                    color: "#0695D6"
                                    radius: 3
                                    Label {
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        text: "+"
                                        color: "white"
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if(nChessy < 3) {
                                                nChessy += 1
                                                txtPercentCheesy.text = getPercentCheesy(nChessy);
                                                getMoney(pizza_category, pizza_sizebanh_id, nItem)
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        ColumnLayout {
                            spacing: 10
                            Label {
                                text: "SỐ LƯỢNG"
                                font.pixelSize: 20
                                font.bold: true
                                color: "#777777"
                            }
                            Row {
                                width: 300
                                Rectangle {
                                    height: 60
                                    width:  60
                                    color: "#0695D6"
                                    radius: 3
                                    Label {
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        text: "-"
                                        color: "white"
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if(nItem > 1) {
                                                nItem -= 1
                                                txtTotalItem.text = nItem
                                                getMoney(pizza_category, pizza_sizebanh_id, nItem)
                                            }
                                        }
                                    }
                                }

                                Rectangle {
                                    height: 60
                                    width:  130
                                    color: "#F2F2F2"
                                    Label {
                                        id:txtTotalItem
                                        text: nItem
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        color: "#000000"
                                    }
                                }

                                Rectangle {
                                    height: 60
                                    width:  60
                                    color: "#0695D6"
                                    radius: 3
                                    Label {
                                        anchors.centerIn: parent
                                        font.pointSize: 24
                                        font.bold: true
                                        text: "+"
                                        color: "white"
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            nItem += 1
                                            txtTotalItem.text = nItem
                                            getMoney(pizza_category, pizza_sizebanh_id, nItem)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                Row {
                    Rectangle {
                        height: 1
                        width: 1035
                        color: "#E0E0E0"
                    }
                }

                Row {
                    Grid {
                        columns: 2
                        Layout.fillHeight: true
                        ColumnLayout {
                            spacing: 30
                            width: 692
                            ColumnLayout {
                                width: 692
                                Label {
                                    width: 692
                                    text: "MÔ TẢ"
                                    font.pixelSize: 20
                                    font.bold: true
                                    color: "#777777"
                                }
                                Label {
                                    id: lblChitiet
                                    width: 692
                                    text: (nChessy > 0) ? nItem + " " + pizza_prod_name.split('\n')[0] + "/" + pizza_sizebanh + "/" + pizza_debanh + "/" + cheesy_text : nItem + " " + pizza_prod_name.split('\n')[0] + "/" + pizza_sizebanh + "/" + pizza_debanh
                                    font.pixelSize: 20
                                    font.bold: true
                                    color: "#000000"
                                }
                            }
                            ColumnLayout {
                                width: 692
                                Label {
                                    text: "THÀNH TIỀN"
                                    font.pixelSize: 20
                                    font.bold: true
                                    color: "#777777"
                                }
                                RowLayout {
                                    Layout.fillWidth: true
                                    spacing: 7
                                    Text {
                                        text: pizza_money_root
                                        color: "#9B9B9B"
                                        font.pixelSize: 20
                                        font.strikeout: true
                                        font.bold: true
                                    }

                                    Text {
                                        text: pizza_money + " VNĐ"
                                        color: "#E61837"
                                        font.pixelSize: 30
                                        font.bold: true
                                    }
                                }
                            }
                        }

                        ColumnLayout {
                            spacing: 30
                            Row {
                                 width: 342
                                 spacing: 30
                                 anchors.right: parent.right
                                 anchors.rightMargin: 0
                                 Rectangle {
                                     id: btnSelectItem
                                     height: 80
                                     width: 342
                                     color: "#0695D6"
                                     radius: 5
                                     Label {
                                         anchors.centerIn: parent
                                         font.pixelSize: 30
                                         font.bold: true
                                         text: "ĐỒNG Ý"
                                         color: "#FFFFFF"
                                     }
                                     MouseArea{
                                         anchors.fill: parent
                                         onClicked: {
                                             pressbtn_selected = false;
                                             btnSelectItem.enabled = pressbtn_selected;
                                             var _prod_name = pizza_prod_name.split('\n').length > 1 ? pizza_prod_name.split('\n')[1].toString().replace('(','').replace(')',''): pizza_prod_name;
                                             var _name = _prod_name + "/" + pizza_sizebanh + "/" + pizza_debanh;
                                             var _price = mainController.moneyMoney(promote_price);
                                             var _oriprice = 0;
                                             var _quantity = nItem;
                                             name_code = pizza_sizebanh_id + pizza_debanh_id + pizza_prod_code;
                                             if(name_code === '12TCCCB') {
                                                 name_code = '2TCCCB';
                                             }
                                             if(name_code === '12HTMRITA') {
                                                 name_code = '12HTMAR';
                                             }
                                             console.log("Name Code: " + name_code);
                                             mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);

                                             if(pizza_sizebanh_id === "9") {
                                                 if(nChessy === 1) {
                                                     _name = "Thêm phô mai 50% bánh 9\"";
                                                     name_code = "O9XCHE";
                                                     _price = "10,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(nChessy === 2) {
                                                     _name = "Thêm phô mai 100% bánh 9\"";
                                                     name_code = "O9DCHE";
                                                     _price = "20,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(nChessy === 3) {
                                                     _name = "Thêm phô mai 200% bánh 9\"";
                                                     name_code = "O9TCHE";
                                                     _price = "30,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(pizza_debanh_id === "CC") {
                                                     _name = "Viền phô mai dày bánh 9\"";
                                                     name_code = "O9CC";
                                                     _price = "49,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(pizza_debanh_id === "TCC") {
                                                     _name = "Viền phô mai mỏng bánh 9\"";
                                                     name_code = "O9CC";
                                                     _price = "49,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }
                                             }

                                             if(pizza_sizebanh_id === "12") {
                                                 if(nChessy === 1) {
                                                     _name = "Thêm phô mai 50% bánh 12\"";
                                                     name_code = "O12XCHE";
                                                     _price = "15,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(nChessy === 2) {
                                                     _name = "Thêm phô mai 100% bánh 12\"";
                                                     name_code = "O12DCHE";
                                                     _price = "30,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(nChessy === 3) {
                                                     _name = "Thêm phô mai 200% bánh 12\"";
                                                     name_code = "O12TCHE";
                                                     _price = "45,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(pizza_debanh_id === "CC") {
                                                     _name = "Viền phô mai dày bánh 12\"";
                                                     name_code = "O12CC";
                                                     _price = "69,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }

                                                 if(pizza_debanh_id === "TCC") {
                                                     _name = "Viền phô mai mỏng bánh 12\"";
                                                     name_code = "O12CC";
                                                     _price = "69,000";
                                                     pizza_sizebanh = "-";
                                                     pizza_debanh = "-";
                                                     mainController.insertItem(name_code, _name, pizza_sizebanh, pizza_debanh, _price, _quantity, _oriprice, 0);
                                                 }
                                             }

                                             reset();
                                             cakeInfoDialog.close();
                                         }
                                     }
                                 }
                            }

                            Row {
                                width: 342
                                Rectangle {
                                    id: btnCancelSelectItem
                                    height: 80
                                    width:  342
                                    color: "#8397A0"
                                    radius: 5
                                    Label {
                                        anchors.centerIn: parent
                                        font.pixelSize: 30
                                        font.bold: true
                                        text: "HỦY"
                                        color: "#FFFFFF"
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            reset();
                                            cakeInfoDialog.close()
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Row {
                width: parent.width
                spacing: globalPadding
                topPadding: globalPadding

            }
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
                    width: parent.width
                    highlighted: true
                    font.pixelSize: fntsize + 4
                    text: "Hủy"
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
        // show bảng báo nhận hóa đơn
        id: getErrAlert
        modal: true
        focus: true
        x: (window.width - width) / 2
        y: Math.abs(window.height - getErrAlert.height) / 3

        width: 874
        height: 422
        topPadding: 50
        rightPadding: 30
        leftPadding: 30
        bottomPadding: 30
        Column {
            id: billAlerErrColumn
            spacing: 50
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 36
                font.bold: true
                color: "#0078AE"
                text: "THÔNG BÁO"
            }

            Text {
                width: 700
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Rất tiếc, đã xảy ra lỗi khi thanh toán.\nVui lòng thử lại sau."
                font.pixelSize: 36
                horizontalAlignment: Text.AlignHCenter
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 342
                height: 90
                highlighted: true
                font.pixelSize: 30
                text: "Đóng"
                Material.primary: "#E61837"
                Material.accent: "#E61837"
                onClicked: {
                    getErrAlert.close()
                }
            }
        }

        onOpened: {
            getErrTimer.parentId = 4;
            getErrTimer.restartTimerCounter();
        }

        onClosed: {
            getErrTimer.stopTimerCounter();
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
                    //printerMessageDialog.showMessage(false, "Máy in chưa sẵn sàng vui lòng kiểm tra lại máy in")
                    //appMessage.showMessage("Máy in chưa sẵn sàng !!!")
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

    Popup {
        id: deleteItemDialog
        modal: true
        focus: true
        topPadding: 40
        rightPadding: 40
        leftPadding: 40
        bottomPadding: 40
        x: (window.width - width)/2
        y: (window.height - height)/2
        closePolicy: Popup.NoAutoClose

        contentItem: ColumnLayout {
            spacing: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                text: "XÁC NHẬN"
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 36
                font.bold: true
                color: "#0078AE"
            }

            ColumnLayout {
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Bạn có muốn xoá món này không?"
                    font.pixelSize: 36
                    color: "#4A4A4A"

                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: prodNameInPaymenView
                    font.pixelSize: 36
                    font.bold: true
                }


            }
            Row {
                spacing: 30
                Layout.alignment: Qt.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    id: btnConfirm
                    text: "Xóa"
                    highlighted: true
                    font.pixelSize: 30
                    height: 90
                    width: 342
                    Material.primary: "#E61837"
                    Material.accent: "#E61837"
                    onClicked: {
                        mainController.removeItemInPaymentView(styleData_row);
                        deleteItemDialog.close();
                    }
                }
                Button {
                    id: btnCancel
                    text: "Không"
                    font.pixelSize: 30
                    height: 90
                    width: 342
                    onClicked: {
                        deleteItemDialog.close();
                    }
                }
            }
        }
    }

    Popup {
        id: zoomItemDialog
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
            RowLayout {
                spacing: 10
                width: 874
                Item {
                    id: itemImage
                    anchors.top: parent.top
                    width: 365
                    height: 300
                    Image {
                        id: foodIcon
                        fillMode: Image.Stretch
                        anchors.fill: parent
                        anchors.margins: 2
                        source: zoom_prod_img
                    }
                }
                ColumnLayout {
                    spacing: 30
                    Label {
                        text: zoom_prod_name
                        font.pixelSize: 32
                        font.bold: true
                        color: "#000000"
                    }
                    ColumnLayout {
                        Text {
                            text: qsTr("THÀNH PHẦN")
                            font.pixelSize: 20
                            font.bold: true
                            color: "#4A4A4A"
                        }
                        Text {
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.preferredWidth: 420
                            text: zoom_prod_thanhphan.trim().length == 0 ? "Chưa có thông tin" : zoom_prod_thanhphan;
                            wrapMode: Text.Wrap
                            font.pixelSize: 24
                            color: "#4A4A4A"
                        }
                    }
                }
            }
            Rectangle {
                height: 30
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    text: "Đóng"
                    Layout.fillWidth: true
                    height: 90
                    width: 342
                    highlighted: true
                    font.pixelSize: 30
                    Material.primary: "#0695D6"
                    Material.accent: "#0695D6"
                    onClicked: {
                        zoomItemDialog.close();
                    }
                }
            }
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

    ProfilePage {
        id: idProfilePage
    }

    AccountPage {
        id: accountPage
    }

    AboutPage {
        id: idAboutPage
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
