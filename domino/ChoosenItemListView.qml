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
                    size:get(i).size,
                    code_name:get(i).code_name,
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

        function getProductName(row) {
            var prod_name = '';
            if(row < count) {
                prod_name = get(row).item_name;
            }
            return prod_name;
        }

        function updateTotalMoney() {
            var i
            var toTal = 0
            for (i = 0; i < count; i++) {
                toTal = toTal +  mainController.getMoneyValue(get(i).amount)
            }

            mainController.updateTotalMoney(toTal)
        }

        function addItem(code_name, name, size, debanh, quantity, price, amount, oriprice, promtype) {
            var quantityValue
            var amountValue
            var index
            index = checkExisted(name)
            if (index < 0) {
                quantityValue = mainController.getMoneyValue(quantity)
                amountValue = mainController.moneyMoney(quantityValue * mainController.getMoneyValue(price))
                choosenItemModel.append({"code_name": code_name, "item_name": name, size: size, debanh: debanh, "quantity": quantityValue, "price": mainController.moneyMoney(price), "amount": amountValue, "cancel": "X",
                                            "oriprice": oriprice, "promtype": promtype})
            } else {
                quantityValue = get(index).quantity
                quantityValue = quantityValue + mainController.getMoneyValue(quantity)
                amountValue = quantityValue * mainController.getMoneyValue(price)

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
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: idXoachon.top

        property int colRatio: width/22

        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff

        TableViewColumn {
            resizable: false
            movable: false
            role: "item_name"
            title: qsTr("  Tên hàng")
            width: tableViewChoosen.colRatio*12
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
            title: qsTr("Giá")
            width: tableViewChoosen.colRatio*4
            //width: Units.dp(75)
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "amount"
            title: qsTr("Thành tiền")
            width: tableViewChoosen.colRatio*4
            //width: Units.dp(75)
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
                implicitHeight: Screen.devicePixelRatio <= 2? 60: 60
                color: "#DBF0FA"
                Text {
                    id: textItem
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    //horizontalAlignment: (styleData.column === 0 ? Text.AlignLeft : Text.AlignHCenter)
                    horizontalAlignment: ((styleData.column === 0) ? Text.AlignLeft :
                                                                   ((styleData.column === 2 || styleData.column === 3) ? Text.AlignHCenter:Text.AlignRight))
                    text: styleData.value
                    font.pixelSize: 16
                    font.bold: true
                    elide: Text.ElideRight
                    color: "#000000"
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
                height: Screen.devicePixelRatio <= 2? 60: 60
                property int implicitWidth: label.implicitWidth + 20

                Text {
                    id: label
                    objectName: "label"
                    width: parent.width - x - (horizontalAlignment === Text.AlignRight ? 8 : 1)
                    x: (styleData.hasOwnProperty("depth") && styleData.column === 0) ? 0 :
                                                                                       horizontalAlignment === Text.AlignRight ? 1 : 8
                    verticalAlignment:  Text.AlignVCenter
                    horizontalAlignment: ((styleData.column === 0) ? Text.AlignLeft :
                                                                   ((styleData.column === 2 || styleData.column === 3) ? Text.AlignRight : Text.AlignHCenter))

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: 1
                    elide: styleData.elideMode
                    text: styleData.value !== undefined ? styleData.value : ""
                    font.pixelSize: 18
                    font.bold: (styleData.column === 0 || styleData.column === 1) ? false : true
                    color: "#000000"
                    renderType: Settings.isMobile ? Text.QtRendering : Text.NativeRendering
                }

                MouseArea {
                    id:mouseArea
                    anchors.fill: parent
                    onClicked: {
                        window.styleData_row = styleData.row;
                        window.prodNameInPaymenView = choosenItemModel.getProductName(styleData.row);
                        deleteItemDialog.open();
                    }
                }
            }

            rowDelegate: Rectangle {
                id: abc
                height: Screen.devicePixelRatio <= 2? 60: 60
                property color selectedColor: control.activeFocus ? "#07c" : "#999"
                color: styleData.selected ? selectedColor : !styleData.alternate ? "#FFFFFF" : "#F5F5F5"
            }
        }

        Connections {
            target: mainController
            onAddItem: {
                choosenItemModel.addItem(code_name, name, size, debanh, quantity, price, amount, oriprice, promtype)
            }

            onCancelBillItem: {
                // xóa hóa đơn đã thanh toán xong
                choosenItemModel.clear();
            }

            onRemoveItemPaymentView: {
                choosenItemModel.removeItem(row)
            }
        }
    }
}
