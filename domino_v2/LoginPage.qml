import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Popup {
    id: loginPage

    width: 300
    height: 250
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    closePolicy: Popup.NoAutoClose
    focus: true

    onVisibleChanged: {
        if (visible) {
            idusrName.focus = idusrName.text === "" ? true : false
            idPassword.focus = idusrName.text === "" ? false : true
            idPassword.focusReason = Qt.OtherFocusReason
        }
    }

    contentItem: ColumnLayout {
        id: appOptionColumn
        Layout.alignment: Qt.AlignHCenter

        Label {
            text: "Đăng Nhập"
            Layout.alignment: Qt.AlignHCenter
            font.bold: true
            font.pixelSize: fntsize + 4
        }

        Row {
            Label {
                anchors.verticalCenter: parent.verticalCenter
                width: 80
                text: "Tên: "
            }

            TextField {
                id: idusrName
                width: 180
                text: mainController.getConfigUsername()
                onDisplayTextChanged: loginErrorMsg.text = ""
            }
        }

        Row {
            Label {
                anchors.verticalCenter: parent.verticalCenter
                width: 80
                text: "Mật khẩu: "
            }

            TextField {
                id: idPassword
                width: 180
                text: mainController.isDebugmode() ? mainController.getConfigUserpwd() : ""
                echoMode: TextInput.Password
                onDisplayTextChanged: loginErrorMsg.text = ""
            }
        }

        Label {
            id: loginErrorMsg
            Layout.alignment: Qt.AlignHCenter
            text: " "
        }

        Row {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Button {
                id: okButton
                text: "Đồng ý"
                width: 100
                onClicked: {
                    mainController.userLogin(idusrName.text, idPassword.text);
                }
            }

            Button {
                id: cancelButton
                text: "Hủy"
                width: 100
                onClicked: {
                    if (!mainController.isDebugmode()) {
                        idPassword.text = ""
                    }
                    loginErrorMsg.text = ""
                    loginPage.close()
                }
            }
        }
    }

    Connections {
        target: mainController
        onLogin: {
            if (err == 0) {
                if (!mainController.isDebugmode()) {
                    idPassword.text = ""
                }
                loginErrorMsg.text = ""
                loginPage.close()
                stackView.push(userConfigPage)
            }
            else {
                loginErrorMsg.text = msg;
            }
        }
    }
}
