import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Window 2.2

Pane {
    id:appconfigPage
    property int col1width: 100
    property int col2width: 250

    Flickable {
        anchors.fill: parent
        contentHeight: configColumn.height

        Column {
            id: configColumn
            width: parent.width
            spacing: globalPadding

            GroupBox {
                title: "CÀI ĐẶT MÁY CHỦ VÀ THIẾT BỊ"
                width: parent.width

                Column {
                    spacing: 10

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 10
                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Máy chủ Domino:"
                            }
                            TextField {
                                id: idDominoServerUrl
                                enabled: true
                                placeholderText: "http://localhost"
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                text: mainController.getDominoServerUrl()
                                onEditingFinished: {
                                    mainController.setDominoServerUrl(text)
                                }
                            }
                        }

                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Máy chủ: "
                            }
                            ComboBox {
                                id: idServer
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                model: ListModel {
                                    id: cbServer
                                    ListElement { text: "vpos"; server: "vpos.zing.vn/vpos"}
                                    ListElement { text: "gbcstaging"; server: "gbcstaging.zing.vn/vpos"}
                                    ListElement { text: "gbcdev"; server: "gbcdev.zing.vn/vpos"}
                                }
                                textRole: "text"
                                currentIndex: mainController.getPayment() === "gbcstaging.zing.vn/vpos"
                                onCurrentIndexChanged: {
                                    mainController.setPayment(cbServer.get(currentIndex).server)
                                    idServerUrl.text = mainController.getPayment();
                                }
                            }
                        }

                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Máy chủ URL:"
                            }
                            TextField {
                                id: idServerUrl
                                enabled: mainController.isDebugmode() ? true : false
                                placeholderText: "vpos.zing.vn/vpos"
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                text: mainController.getPayment()
                                onEditingFinished: {
                                    mainController.setPayment(text)
                                }
                            }
                        }

                        Row {
                            visible: mainController.isDebugmode()
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Trans Protocol: "
                            }
                            ComboBox {
                                id: idTransProtocol
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                model: ListModel {
                                    id: cbTranspro
                                    ListElement { text: "HTTP / WS"; transpro: "http"}
                                    ListElement { text: "HTTPS / WSS"; transpro: "https"}
                                }
                                textRole: "text"
                                currentIndex: mainController.getTransferProtocol() === "https"
                                onCurrentIndexChanged: {
                                    mainController.setTransferProtocol(cbTranspro.get(currentIndex).transpro)
                                }
                            }
                        }

                        Row {
                            visible: mainController.isDebugmode()
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Dock version: "
                            }

                            ComboBox {
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                model: ListModel {
                                    id: cbItems
                                    ListElement { text: "1.0" }
                                    ListElement { text: "2.0" }
                                }
                                currentIndex: mainController.getConfigDockversion() === "1.0" ? 0 : 1

                                onCurrentIndexChanged: {
                                    mainController.setConfigDockversion(cbItems.get(currentIndex).text)
                                }
                            }
                        }
                    }

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 10

                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Local IP:"
                            }

                            TextField {
                                id: idLocalIp
                                enabled: false
                                width: admConfColwidth2 * 5
                                Layout.fillWidth: true
                                text: mainController.getLocalIp();
                            }
                        }

                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Dịch vụ trung tâm:"
                            }
                            TextField {
                                id: idCenterService
                                width: admConfColwidth2 * 5
                                Layout.fillWidth: true
                                enabled: false
                                text: mainController.getConfigCenterService()
                            }
                        }

                        Row {
                            Layout.fillWidth: true
                            spacing: 10
                            Label {
                                width: admConfColwidth1
                                anchors.verticalCenter: parent.verticalCenter
                                text: "-   Printer size: "
                            }

                            ComboBox {
                                width: admConfColwidth2
                                Layout.fillWidth: true
                                model: ListModel {
                                    id: cbPageItem
                                    ListElement { text: "small" }
                                    ListElement { text: "large" }
                                }
                                currentIndex: mainController.getConfigPrintersize() === "small" ? 0 : 1

                                onCurrentIndexChanged: {
                                    mainController.setConfigPrintersize(cbPageItem.get(currentIndex).text)
                                }
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: "CÀI ĐẶT QUẦY HÀNG (User Config)"
                width: parent.width

                onVisibleChanged: {
                    if (visible) {
                        idMerchantID.text = mainController.getAppName()
                        idAppTitle.text = mainController.getAppTitle()
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true

                    Row {
                        Layout.fillWidth: true
                        spacing: 10
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Mã quầy hàng : "
                        }
                        TextField {
                            id: idMerchantID
                            placeholderText: "vpos"
                            text: mainController.getAppName()
                            width: admConfColwidth2
                            onEditingFinished: {
                                // need check appname/merchantID from server and show valid alert msg ...
                                mainController.setAppName(text)
                                idAppTitle.text = mainController.getAppTitle()

                                // set title to save to config file
                                mainController.setAppTitle(idAppTitle.text)
                            }
                        }

                        Button {
                            text: "Food court . . ."
                            onClicked: {
                                stackView.push(accountPage)
                            }
                        }
                    }

                    Row {
                        Layout.fillWidth: true
                        spacing: 10
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Tên quầy hàng : "
                        }
                        TextField {
                            id: idAppTitle
                            text: mainController.getAppTitle()
                            placeholderText: "TÊN QUẦY HÀNG"
                            width: admConfColwidth2
                            onEditingFinished: {
                                mainController.setAppTitle(text)
                            }
                        }
                    }

                    Row {
                        Layout.fillWidth: true
                        spacing: 10
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Tên máy : "
                        }
                        ListModel {
                            id: lmMayid
                            ListElement { name: "May  1";  mayid:  1 }
                            ListElement { name: "May  2";  mayid:  2 }
                            ListElement { name: "May  3";  mayid:  3 }
                            ListElement { name: "May  4";  mayid:  4 }
                            ListElement { name: "May  5";  mayid:  5 }
                            ListElement { name: "May  6";  mayid:  6 }
                            ListElement { name: "May  7";  mayid:  7 }
                            ListElement { name: "May  8";  mayid:  8 }
                            ListElement { name: "May  9";  mayid:  9 }
                        }
                        ComboBox {
                            id: cbxMachine
                            model: lmMayid
                            textRole: "name"
                            currentIndex: mainController.getRechargeNum();
                            onCurrentTextChanged: {
                                mainController.setRechargeNum(cbxMachine.currentIndex);
                            }
                        }
                        Button {
                            id: idButInhoadon
                            text: "In thử Hóa đơn"
                            //enabled: mainController.isConnected()
                            onClicked: {
                                mainController.printTest("");
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Số bản in hóa đơn (1..5) : "
                        }

                        TextField {
                            id:idSobanin
                            text: mainController.getConfigSobanin();
                            width: 60
                            onEditingFinished: {
                                var num = parseInt(text);
                                mainController.setConfigSobanin(num);

                                // cập nhật tên bản in theo số lượng bản in
                                text = mainController.getConfigSobanin();
                                idTenbanin.text = mainController.getConfigTenbanin()
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Layout.fillWidth: true
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Tên bản in : "
                        }

                        TextField {
                            id:idTenbanin
                            enabled: (parseInt(idSobanin.text) > 1)
                            width: usrConfColwidth2
                            text: mainController.getConfigTenbanin();
                            onEditingFinished: {
                                mainController.setConfigTenbanin(text);

                                // lấy lại tên bản in sau khi cập nhật
                                text = mainController.getConfigTenbanin();
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Layout.fillWidth: true
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: " "
                        }

                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            Layout.fillWidth: true
                            enabled: false
                            text: "Tên bản in cách nhau bằng dấu ';' từ 2 bản in trở lên tên bản in mới được in ra"
                        }
                    }

                    Row {
                        spacing: 10
                        Layout.fillWidth: true
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Thông tin (đầu) hóa đơn : "
                        }

                        TextField {
                            id:idBillInfo
                            width: usrConfColwidth2
                            text: mainController.getConfigBillPreinf()
                            placeholderText: "Thông tin địa chỉ số điện thoại ... ';' để xuống dòng"
                            onEditingFinished: {
                                mainController.setConfigBillPreinf(text);

                                // lấy lại tên bản in sau khi cập nhật
                                text = mainController.getConfigBillPreinf();
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Layout.fillWidth: true
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Thông tin (cuối) hóa đơn : "
                        }

                        TextField {
                            id:idBillInfoLast
                            width: usrConfColwidth2
                            text: mainController.getConfigBillPostinf()
                            placeholderText: "Cảm ơn Quí khách, hẹn gặp lại ... ';' để xuống dòng"
                            onEditingFinished: {
                                mainController.setConfigBillPostinf(text);

                                // lấy lại tên bản in sau khi cập nhật
                                text = mainController.getConfigBillPostinf();
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            width: usrConfColwidth1
                            anchors.verticalCenter: parent.verticalCenter
                            text: "-   Cỡ chữ giao diện (10..26) : "
                        }
                        TextField {
                            text: mainController.getConfigFoodItemFontsize()
                            width: 60
                            onEditingFinished: {
                                var fntsize = parseInt(text)
                                mainController.setConfigFoodItemFontsize(fntsize);
                                mainController.setConfigBillItemFontsize(fntsize);
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: "PHƯƠNG PHÁP TÌM KIẾM (User Config)"
                width: parent.width

                ColumnLayout {
                    Layout.fillWidth: true
                    RadioButton {
                        checked: !mainController.getConfigSearchadvance()
                        text: "Tìm nhanh - tìm theo tên"
                        onClicked: mainController.setConfigSearchadvance(false)
                    }
                    RadioButton {
                        checked: mainController.getConfigSearchadvance()
                        text: "Tìm nâng cao - tìm theo tên và các từ viết tắt"
                        onClicked: mainController.setConfigSearchadvance(true)
                    }
                }
            }

            GroupBox {
                title: "CÀI ĐẶT CHỨC NĂNG"
                width: parent.width

                Column {
                    CheckBox {
                        text: "Hiển thị nút 'User Config'"
                        checked: mainController.getUserEnableConfig()
                        onClicked: {
                            mainController.setUserEnableConfig(checked);
                            userConfigButtonVisible = checked
                        }
                    }

                    CheckBox {
                        text: "Hiển thị ô nhập 'Ngày Báo cáo'"
                        checked: mainController.getConfigShowBaocaoDate()
                        onClicked: {
                            mainController.setConfigShowBaocaoDate(checked);
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "Thời gian cập nhật foods (seconds 5..600): "
                        }

                        TextField {
                            text: mainController.getFoodRefreshTimer();
                            onEditingFinished: {
                                var timer = parseInt(text)
                                if ((timer > 4) && (timer < 601)) {
                                    mainController.setFoodRefreshTimer(timer);
                                } else {
                                    if ( timer < 5) {
                                        text = "5"
                                        mainController.setFoodRefreshTimer(5);
                                    }
                                    else {
                                        text = "600"
                                        mainController.setFoodRefreshTimer(600);
                                    }
                                }
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "Thời gian chờ nhận hóa đơn (seconds 0..60): "
                        }

                        TextField {
                            text: mainController.getBillAlertTimer();
                            onEditingFinished: {
                                var timer = parseInt(text)
                                if ((timer >= 0) && (timer < 61)) {
                                    mainController.setBillAlertTimer(timer);
                                } else {
                                    if ( timer < 0) {
                                        text = "0"
                                        mainController.setBillAlertTimer(0);
                                    }
                                    else {
                                        text = "60"
                                        mainController.setBillAlertTimer(60);
                                    }
                                }
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "Thời gian Idle chờ User chọn món (seconds 0..90): "
                        }

                        TextField {
                            text: mainController.getConfigIdletime();
                            onEditingFinished: {
                                var timer = parseInt(text)
                                if ((timer >= 0) && (timer < 91)) {
                                    mainController.setConfigIdletime(timer);
                                } else {
                                    if ( timer < 0) {
                                        text = "0"
                                        mainController.setConfigIdletime(0);
                                    }
                                    else {
                                        text = "90"
                                        mainController.setConfigIdletime(90);
                                    }
                                }
                            }
                        }
                    }

                    Row {
                        spacing: 10
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "Tỉ lệ hình QR (5..1): "
                        }

                        TextField {
                            text: mainController.getConfigQrcodeRatio();
                            onEditingFinished: {
                                var ratio = parseFloat(text).toFixed(2)
                                mainController.setConfigQrcodeRatio(ratio);
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: "PHƯƠNG THỨC THANH TOÁN"
                width: parent.width

                Column {
                    Row {
                        CheckBox {
                            text: "Hiển thị 'Thanh toán cùng hóa đơn' ra màn hình"
                            checked:mainController.getShowThanhtoancungdonhang()
                            onClicked: {
                                mainController.setShowThanhtoancungdonhang(checked);
                            }
                        }
                    }

                    RowLayout  {
                        Layout.fillWidth: true
                        Rectangle {
                            width: 30
                            height: 20
                        }

                        ColumnLayout {
                            Layout.fillWidth: true

                            CheckBox {
                                text: " - Zalo pay"
                                checked:((mainController.getPaymentMask() & 1) === 1)
                                onClicked: {
                                    mainController.setPaymentMask(1, checked);
                                }
                            }
                            CheckBox {
                                text: " - Thẻ"
                                checked:((mainController.getPaymentMask() & 2) === 2)
                                onClicked: {
                                    mainController.setPaymentMask(2, checked);
                                }
                            }
                            CheckBox {
                                text: " - Tiền mặt"
                                checked:((mainController.getPaymentMask() & 4) === 4)
                                onClicked: {
                                    mainController.setPaymentMask(4, checked);
                                }
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: "CẤU HÌNH COUPON"
                width: parent.width

                Column {
                    RowLayout  {
                        Layout.fillWidth: true
                        Rectangle {
                            width: 30
                            height: 20
                        }

                        ColumnLayout {
                            Layout.fillWidth: true

                            Row {
                                Layout.fillWidth: true
                                spacing: 10
                                Label {
                                    width: usrConfColwidth1
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: "-   Mã coupon : "
                                }
                                TextField {
                                    id: idcoupon
                                    text: mainController.getIdCoupon()
                                    placeholderText: "Mã coupon"
                                    width: admConfColwidth2
                                    onEditingFinished: {
                                        mainController.setIdCoupon(text)
                                    }
                                }
                            }

                            Row {
                                Layout.fillWidth: true
                                spacing: 10
                                Label {
                                    width: usrConfColwidth1
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: "-   % coupon : "
                                }
                                TextField {
                                    id: idcouponpercent
                                    text: mainController.getIdCouponPercent()
                                    placeholderText: "% coupon"
                                    width: admConfColwidth2
                                    onEditingFinished: {
                                        var percent = parseFloat(text).toFixed(2)
                                        mainController.setIdCouponPercent(percent)
                                    }
                                }
                            }
                        }
                    }
                }
            }

            GroupBox {
                title: "Vpos Application"
                width: parent.width

                Column {
                    spacing: 10
                    Column {
                        visible: true //mainController.isRaspberry();
                        spacing: 10
                        Label {
                            text: "Lập lịch reboot Pi.  Vpos khởi động lúc: " + mainController.getRestartTime();
                        }

                        Label {
                            id: idlabtime
                        }

                        Timer  {
                            id: elapsedTimer
                            interval: 1000;
                            running: true;
                            repeat: true;

                            property bool timerswitch: true

                            onTriggered: {
                                idlabtime.text = "Giờ hệ thống: " + mainController.getCurrentTime(timerswitch);
                                timerswitch = !timerswitch;
                            }
                        }

                        ListView {
                            width: parent.width
                            height: contentHeight
                            spacing: 10
                            model: ListModel {
                                ListElement { number: 0; name: "Chủ Nhật" }
                                ListElement { number: 1; name: "Thứ Hai" }
                                ListElement { number: 2; name: "Thứ Ba" }
                                ListElement { number: 3; name: "Thứ Tư" }
                                ListElement { number: 4; name: "Thứ Năm" }
                                ListElement { number: 5; name: "Thứ Sáu" }
                                ListElement { number: 6; name: "Thứ Bảy" }
                            }

                            delegate: Component {
                                Row {
                                    width: 100
                                    height: 30
                                    CheckBox {
                                        height: parent.height
                                        checked: (mainController.getConfigRebootDatePi() & (1<<number));
                                        text: name
                                        onCheckedChanged: mainController.setConfigRebootDatePi(number, checked);
                                    }
                                }
                            }
                        }

                        Row {
                            height: 40
                            spacing: 10
                            Label {
                                height: parent.height
                                verticalAlignment: Qt.AlignVCenter
                                text: "Reboot vào lúc:" }

                            TextField {
                                height: parent.height
                                width: 40
                                verticalAlignment: Qt.AlignVCenter
                                horizontalAlignment: Qt.AlignHCenter
                                text: mainController.getConfigRebootTimePi(1);
                                onEditingFinished: {
                                    mainController.setConfigRebootTimePi(parseInt(text), 1);
                                    text = mainController.getConfigRebootTimePi(1);
                                    idrebootMinute.text = mainController.getConfigRebootTimePi(2);
                                }
                            }

                            Label {
                                height: parent.height
                                verticalAlignment: Qt.AlignVCenter
                                text: "giờ" }

                            TextField {
                                id: idrebootMinute
                                height: parent.height
                                width: 40
                                verticalAlignment: Qt.AlignVCenter
                                horizontalAlignment: Qt.AlignHCenter
                                text: mainController.getConfigRebootTimePi(2);
                                onEditingFinished: {
                                    mainController.setConfigRebootTimePi(parseInt(text), 2);
                                    text = mainController.getConfigRebootTimePi(2);
                                }
                            }

                            Label {
                                height: parent.height
                                verticalAlignment: Qt.AlignVCenter
                                text: "phút   ( chọn từ 00:03 . . 23:56 )" }
                        }
                    }

                    Button {
                        text: "Lưu cấu hình"
                        onClicked: {
                            mainController.saveConfig();
                        }
                    }

                    Button {
                        text: "Thoát chương trình"
                        onClicked: {
                            mainController.appQuit();
                        }
                    }
                }
            }
        }
    }
}
