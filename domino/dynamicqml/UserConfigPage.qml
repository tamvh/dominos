import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

import QtQuick.Window 2.2

Component {
    Pane {
        id:userConfigPage

        Flickable {
            anchors.fill: parent
            contentHeight: configColumn.height

            ColumnLayout {
                id: configColumn
                Layout.fillWidth: true
                spacing: 10

                Label {
                    text: "BÁO CÁO"
                }

                Column {
                    Row {
                        id: idNgayBaocao
                        spacing: 10
                        visible: mainController.getConfigShowBaocaoDate()
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "Ngày Báo cao: "
                            onVisibleChanged: {
                                visible = mainController.getConfigShowBaocaoDate()
                            }
                        }

                        TextField {
                            id:idDateBaocao
                            text: mainController.getBaocaoCurrentTime();
                            placeholderText: "yyyy-mm-dd"
                        }
                    }

                    Row {
                        spacing: 10

                        Button {
                            id: idButBaocaoX
                            text: "BÁO CÁO X"
                            anchors.leftMargin: 120
                            anchors.horizontalCenter: parent.Center
                            onClicked: {
                                mainController.inBaocao(idDateBaocao.text, 0);
                            }
                        }

                        Button {
                            id: idButBaocaoZ
                            text: "BÁO CÁO Z"
                            anchors.leftMargin: 120
                            anchors.horizontalCenter: parent.Center
                            onClicked: {
                                mainController.inBaocao(idDateBaocao.text, 1);
                            }
                        }

                        Button {
                            id: idButBaocao
                            visible: false
                            text: "BÁO CÁO Chi tiết"
                            anchors.leftMargin: 120
                            anchors.horizontalCenter: parent.Center
                            onClicked: {
                                mainController.inBaocao(idDateBaocao.text, 2);
                            }
                        }
                    }
                }

                Rectangle {
                    width: 1
                    height: 30
                }

                GroupBox {
                    title: "CÀI ĐẶT QUẦY HÀNG"
                    width: parent.width

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
                                enabled: false
                                text: mainController.getAppName()
                                width: 160
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
                                width: 160
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
                    title: "PHƯƠNG PHÁP TÌM KIẾM"
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

            }
        }

        Connections {
            target: mainController
            onDockConnectionChange: {
                idButInhoadon.enabled = connected;
                idButBaocaoX.enabled = connected;
                idButBaocaoZ.enabled = connected;
            }
        }
    }
}
