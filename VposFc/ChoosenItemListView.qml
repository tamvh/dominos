import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtQuick.Layouts 1.3

import MainController 1.0
import QtQuick.Window 2.0

Item {
    property int billitemfntsize: mainController.getConfigBillItemFontsize()

    function generateBillDetail() {
        return choosenItemModel.billDetail()
    }

    function cleanup() {
        choosenItemModel.clear();
    }

    ListModel {
        id: choosenItemModel

        // id: số hóa đơn
        // time: thời gian thanh toán
        // total: tổng tiền
        // bill json format:
        //    {
        //     title: "Canteen VNG"
        //     receiptNum: "12345",
        //     datetime: "20116-06-05 10:00:00",
        //     total: "100,000",
        //     item: [
        //       {
        //         item_name: "ba con soi",
        //         quantity: "2",
        //         price: "10,000",
        //         amount: "20,000"
        //       }
        //       ]
        //    }
        function outjson(invcecode, invcetime, barcode, total) {
            var printData = {
                title: mainController.getTitleEng(),
                receiptNum:invcecode,
                datetime:invcetime,
                barcode:barcode,
                total:total,
                machine: mainController.getAppMachine(),
                item:[]
            };

            var i
            for (i=0; i<count; i++) {
                var itemData = {
                    item_name:get(i).item_name,
                    quantity:get(i).quantity,
                    price:get(i).price,
                    amount:get(i).amount
                };
                printData.item.push(itemData);
            }

            return JSON.stringify(printData);
        }

        function billDetail() {
            var items = [];

            var i
            for (i=0; i<count; i++) {
                var itemData = {
                    item_name:get(i).item_name,
                    quantity:get(i).quantity,
                    price:mainController.getMoneyValue(get(i).price),
                    amount:mainController.getMoneyValue(get(i).amount),
                    original_price:mainController.getMoneyValue(get(i).oriprice),
                    promotion_type:mainController.getMoneyValue(get(i).promtype)
                };
                items.push(itemData);
            }

            return items;
        }

        function checkExisted(name) {
            var i
            for (i = 0; i < count; i++) {
                if (get(i).item_name === name) {
                    return i;
                }
            }

            return -1;
        }

        function updateTotalMoney() {
            var i
            var toTal = 0
            for (i = 0; i < count; i++) {
                toTal = toTal +  mainController.getMoneyValue(get(i).amount)
            }

            mainController.updateTotalMoney(toTal)
        }

        function addItem(name, quantity, price, amount, oriprice, promtype) {

            var index
            index = checkExisted(name)
            if (index < 0) {
                choosenItemModel.append({"item_name": name, "quantity": 1, "price": amount, "amount": amount, "cancel": "X",
                                            "oriprice": oriprice, "promtype": promtype})
            } else {
                var quantityValue = get(index).quantity
                quantityValue = quantityValue + 1
                var amountValue = quantityValue * price
                var amountString = mainController.formatMoney(amountValue)
                var priceString = mainController.formatMoney(price)
                setProperty(index, "price", priceString)
                setProperty(index, "quantity", quantityValue)
                setProperty(index, "amount", amountString)
            }

            updateTotalMoney()
        }

        function removeItem(row1) {
            remove(row1, 1)
            updateTotalMoney()
        }

        onCountChanged: {
            foodItemcount = choosenItemModel.count;
            mainController.idleReset();
        }
    }

    TableView {
        id: tableViewChoosen
        anchors.fill: parent

        //anchors.top: parent.top
        //anchors.left: parent.left
        //anchors.right: parent.right
        //anchors.bottom: idXoachon.top

        property int colRatio: width/20

        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff

        TableViewColumn {
            resizable: false
            movable: false
            role: "item_name"
            title: qsTr("  Tên hàng")
            width: tableViewChoosen.colRatio*7
            //width: Units.dp(150) > 20 ? Units.dp(150) : 150
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "quantity"
            title: qsTr("SL")
            width: tableViewChoosen.colRatio*2
            //width: Units.dp(75) > 20 ? Units.dp(75) : 75
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "price"
            title: qsTr("Giá     ")
            width: tableViewChoosen.colRatio*4
            //width: Units.dp(75)
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "amount"
            title: qsTr("Thành tiền")
            width: tableViewChoosen.colRatio*5
            //width: Units.dp(75)
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "cancel"
            title: qsTr("")
            width: tableViewChoosen.colRatio*2
            delegate: imageDelegate
        }

        model: choosenItemModel

        style: TableViewStyle {
            frame: Rectangle {
                border {
                    color: "transparent" // color of the border
                }
                color: "transparent"
            }
            headerDelegate: Rectangle {
                implicitHeight: Screen.devicePixelRatio <= 2? 48: 32
                color: "#e2e6e7"
                Text {
                    id: textItem
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    //horizontalAlignment: (styleData.column === 0 ? Text.AlignLeft : Text.AlignHCenter)
                    horizontalAlignment: (styleData.column === 0 ? Text.AlignLeft :
                                                                   ((styleData.column === 4 || styleData.column === 1) ? Text.AlignHCenter:Text.AlignRight))
                    text: styleData.value
                    font.pixelSize: billitemfntsize
                    elide: Text.ElideRight
                    color: "#404040"
                    renderType: Settings.isMobile ? Text.QtRendering : Text.NativeRendering
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    y: parent.height
                    color: "white"
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    y: parent.height
                    color: "white"
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    y:0
                    color: "white"
                }
            }

            itemDelegate: Item {
                height: Screen.devicePixelRatio <= 2? 48: 32
                property int implicitWidth: label.implicitWidth + 20

                Text {
                    id: label
                    objectName: "label"
                    width: parent.width - x - (horizontalAlignment === Text.AlignRight ? 8 : 1)
                    x: (styleData.hasOwnProperty("depth") && styleData.column === 0) ? 0 :
                                                                                       horizontalAlignment === Text.AlignRight ? 1 : 8
                    verticalAlignment:  Text.AlignVCenter
                    horizontalAlignment: (styleData.column === 0 ? Text.AlignLeft :
                                                                   ((styleData.column === 4 || styleData.column === 1) ? Text.AlignHCenter:Text.AlignRight))

                    //horizontalAlignment: styleData.textAlignment
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: 1
                    elide: styleData.elideMode
                    text: styleData.value !== undefined ? styleData.value : ""
                    font.pixelSize: billitemfntsize
                    color: styleData.textColor
                    renderType: Settings.isMobile ? Text.QtRendering : Text.NativeRendering
                }

                MouseArea {
                    id:mouseArea
                    anchors.fill: parent
                    onClicked: {
                        choosenItemModel.removeItem(styleData.row)
                    }
                }
            }

            rowDelegate: Rectangle {
                id: abc
                height: Screen.devicePixelRatio <= 2? 48: 32
                property color selectedColor: control.activeFocus ? "#07c" : "#999"
                color: styleData.selected ? selectedColor : !styleData.alternate ? "#FFFFFF" : "#F5F5F5"
            }
        }

        Component {
            id: imageDelegate
            Item {
                anchors.fill: parent
                Image {
                    fillMode: Image.Pad
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source:"qrc:/icons/cancel.png"
                }

                MouseArea {
                    id:mouseArea
                    anchors.fill: parent
                    onClicked: {
                        // click at ROW to delete
                        choosenItemModel.removeItem(styleData.row)
                    }
                }
            }
        }

        Connections {
            target: mainController
            onAddItem: {
                choosenItemModel.addItem(name, quantity, price, amount, oriprice, promtype)
            }

            onCancelBillItem: {
                // xóa hóa đơn đã thanh toán xong
                choosenItemModel.clear();
            }
        }
    }
}
