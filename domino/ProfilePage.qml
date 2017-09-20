import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Popup {
    id: profilePage
    width: window.width/3
    height: 250
    x: (parent.width - width)/2
    y: (parent.height - height)/4
    closePolicy: Popup.NoAutoClose
    focus: true

    onVisibleChanged: {
        if (visible) {
            idusrName.focus = idusrName.text === "" ? true : false
        }
    }

    contentItem: ColumnLayout {
        id: appOptionColumn
        Layout.alignment: Qt.AlignHCenter

        Label {
            text: "NHẬP THÔNG TIN KHÁCH HÀNG"
            Layout.alignment: Qt.AlignHCenter
            font.bold: true
            font.pixelSize: fntsize + 4
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            TextField {
                id: idusrName
                width: 480
                text: ''
                onDisplayTextChanged: loginErrorMsg.text = ""
            }
        }

        Row {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Button {
                id: okButton
                text: "Đồng ý"
                width: 240
                height: 80
                highlighted: true
                onClicked: {

                }
            }

            Button {
                id: cancelButton
                text: "Hủy"
                width: 240
                height: 80
                onClicked: {
                    profilePage.close()
                }
            }
        }
    }
}
