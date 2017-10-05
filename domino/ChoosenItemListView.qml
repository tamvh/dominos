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

        function getQuantityPizza(row) {
            var pizza_quantity = 0;
            if(row < count) {
                pizza_quantity = get(row).quantity;
            }
            return pizza_quantity;
        }

        function getSizeBanh(row) {
            var size_banh = '';
            if(row < count) {
                size_banh = get(row).size;
            }
            return size_banh;
        }

        function getDeBanh(row) {
            var de_banh = '';
            if(row < count) {
                de_banh = get(row).debanh;
            }
            return de_banh;
        }

        function getPhoMai(row) {
            var phomai = '';
            if(row < count) {
                phomai = get(row).phomai;
            }
            return phomai;
        }

        function getTypeProduct(row) {
            var prod_type = '';
            if(row < count) {
                prod_type = get(row).type;
            }
            return prod_type;
        }

        function updateTotalMoney() {
            var i
            var toTal = 0
            for (i = 0; i < count; i++) {
                toTal = toTal +  mainController.getMoneyValue(get(i).amount)
            }

            mainController.updateTotalMoney(toTal)
        }

        function addItem(type, code_name, name, size, debanh, phomai, quantity, price, amount, oriprice, promtype) {
            var quantityValue
            var amountValue
            var index
            index = checkExisted(name)
            if (index < 0) {
                quantityValue = mainController.getMoneyValue(quantity)
                amountValue = mainController.moneyMoney(quantityValue * mainController.getMoneyValue(price))
                choosenItemModel.append({"type": type,"code_name": code_name, "item_name": name, size: size, debanh: debanh, "phomai" : phomai, "quantity": quantityValue, "price": mainController.moneyMoney(price), "amount": amountValue, "cancel": "X",
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

        function removeItemPizza(local_prodtype, local_productName, size_banh, de_banh, phomai) {
            for (var i = 0; i < count; i++) {
                if(size_banh === get(i).size &&
                        de_banh === get(i).debanh &&
                        phomai === get(i).phomai &&
                        local_productName === get(i).item_name &&
                        get(i).type === local_prodtype) {
                    console.log("row pizza: " + JSON.stringify(get(i)));
                    remove(i, 1);
                    break;
                }
            }
            updateTotalMoney()
        }

        function removePizzaOptionPlusChessy(pizza_quantity, local_prodtype, size_banh, phomai) {
            for (var i = 0; i < count; i++) {
                if(size_banh === get(i).size &&
                        phomai === get(i).phomai &&
                        get(i).type === local_prodtype) {
                    console.log("pizza_quantity: " + pizza_quantity);
                    console.log("row option: " + JSON.stringify(get(i)));
                    if(pizza_quantity < get(i).quantity) {
                        var quantityValue = get(i).quantity - pizza_quantity;
                        var amountValue = quantityValue * mainController.getMoneyValue(get(i).price);
                        var amountString = mainController.formatMoney(amountValue);
                        setProperty(i, "quantity", quantityValue);
                        setProperty(i, "amount", amountString);
                    } else {
                         remove(i, 1);
                    }
                    break;
                }
            }
            updateTotalMoney()
        }

        function removePizzaOptionDebanhPhomai(pizza_quantity, local_prodtype, size_banh, de_banh) {
            for (var i = 0; i < count; i++) {
                if(size_banh === get(i).size &&
                        de_banh === get(i).debanh &&
                        get(i).type === local_prodtype) {
                    console.log("pizza_quantity: " + pizza_quantity);
                    console.log("row option: " + JSON.stringify(get(i)));
                    if(pizza_quantity < get(i).quantity) {
                        var quantityValue = get(i).quantity - pizza_quantity;
                        var amountValue = quantityValue * mainController.getMoneyValue(get(i).price);
                        var amountString = mainController.formatMoney(amountValue);
                        setProperty(i, "quantity", quantityValue);
                        setProperty(i, "amount", amountString);
                    } else {
                         remove(i, 1);
                    }
                    break;
                }
            }
            updateTotalMoney()
        }

        function removeItem(row1, size_banh, de_banh, phomai) {
            var i;
            console.log("size banh: " + size_banh);
            console.log("de banh: " + de_banh);
            console.log("pho mai: " + phomai);
            var quantity_pizza = 0;
            quantity_pizza = get(row1).quantity;
            console.log("count before: " + count);
            remove(row1, 1);
            console.log("count after: " + count);
            console.log("quantity_pizza: " + quantity_pizza);


            var l = count;
            var item, ax;

            for (i = 0; i < count; i++) {
                console.log("row: " + JSON.stringify(get(i)));
                if(size_banh === get(i).size &&
                        de_banh === get(i).debanh &&
                        phomai === get(i).phomai &&
                        get(i).type !== "PIZZA") {

                    console.log(": " + quantity_pizza);
                    console.log("quantity item: " + get(i).quantity);
                    if(quantity_pizza < get(i).quantity) {
                        var quantityValue = get(i).quantity - quantity_pizza;
                        var amountValue = quantityValue * mainController.getMoneyValue(get(i).price);
                        var amountString = mainController.formatMoney(amountValue);
                        setProperty(i, "quantity", quantityValue);
                        setProperty(i, "amount", amountString);
                    } else {
                         remove(i, 1);
                        i--;
                    }
                }
            }


            updateTotalMoney()
        }
        function removeItemOther(row1) {
            remove(row1, 1);
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

        property int colRatio: width/27

        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff

        TableViewColumn {
            resizable: false
            movable: false
            role: "item_name"
            title: qsTr("  TÊN HÀNG")
            width: tableViewChoosen.colRatio*13
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
            title: qsTr("GIÁ      ")
            width: tableViewChoosen.colRatio*5
            //width: Units.dp(75)
        }
        TableViewColumn {
            resizable: false
            movable: false
            role: "amount"
            title: qsTr("THÀNH TIỀN")
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
                implicitHeight: 60
                color: "#DBF0FA"
                Text {
                    id: textItem
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: ((styleData.column === 0) ? Text.AlignLeft :
                                                                   ((styleData.column === 1 || styleData.column === 2 || styleData.column === 3 || styleData.column === 4) ? Text.AlignRight:Text.AlignHCenter))
                    text: styleData.value
                    font.pixelSize: 18
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
                height: 60
                property int implicitWidth: label.implicitWidth + 20

                Text {
                    id: label
                    objectName: "label"
                    width: parent.width
                    x: (styleData.hasOwnProperty("depth") && styleData.column === 0) ? 0 :
                                                                                       horizontalAlignment === Text.AlignRight ? 1 : 8
                    verticalAlignment:  Text.AlignVCenter
                    horizontalAlignment: ((styleData.column === 0) ? Text.AlignLeft :
                                                                   ((styleData.column === 1 || styleData.column === 2 || styleData.column === 3) ? Text.AlignRight : Text.AlignHCenter))

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: 1
                    elide: styleData.elideMode
                    text: styleData.value !== undefined ? styleData.value : ""
                    font.pixelSize: 18
                    font.bold: (styleData.column === 0 || styleData.column === 1 || styleData.column === 4) ? false : true
                    color: "#000000"
                    renderType: Settings.isMobile ? Text.QtRendering : Text.NativeRendering
                }

                MouseArea {
                    id:mouseArea
                    anchors.fill: parent
                    onClicked: {
                        window.styleData_row = styleData.row;
                        window.prodNameInPaymenView = choosenItemModel.getProductName(styleData.row);
                        window.choose_sizebanh = choosenItemModel.getSizeBanh(styleData.row);
                        window.choose_debanh = choosenItemModel.getDeBanh(styleData.row);
                        window.choose_phomai = choosenItemModel.getPhoMai(styleData.row);
                        window.g_prod_type = choosenItemModel.getTypeProduct(styleData.row);
                        if(window.g_prod_type === "OPTION_THEMPHOMAI" || window.g_prod_type === "OPTION_DEVIENPHOMAI") {
                            // khong the xoa duoc
                            deleteOptionPizzaDialog.open();
                        } else {
                            deleteItemDialog.open();
                        }
                    }
                }
            }

            rowDelegate: Rectangle {
                id: abc
                height: 60
                property color selectedColor: control.activeFocus ? "#07c" : "#999"
                color: styleData.selected ? selectedColor : !styleData.alternate ? "#FFFFFF" : "#F5F5F5"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.styleData_row = styleData.row;
                        window.prodNameInPaymenView = choosenItemModel.getProductName(styleData.row);
                        window.choose_sizebanh = choosenItemModel.getSizeBanh(styleData.row);
                        window.choose_debanh = choosenItemModel.getDeBanh(styleData.row);
                        window.choose_phomai = choosenItemModel.getPhoMai(styleData.row);
                        window.g_prod_type = choosenItemModel.getTypeProduct(styleData.row);
                        if(window.g_prod_type === "OPTION_THEMPHOMAI" || window.g_prod_type === "OPTION_DEVIENPHOMAI") {
                            // khong the xoa duoc
                            deleteOptionPizzaDialog.open();
                        } else {
                            deleteItemDialog.open();
                        }
                    }
                }
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
                    source: "qrc:/icons/images/app/close_red.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.styleData_row = styleData.row;
                        window.prodNameInPaymenView = choosenItemModel.getProductName(styleData.row);
                        window.choose_sizebanh = choosenItemModel.getSizeBanh(styleData.row);
                        window.choose_debanh = choosenItemModel.getDeBanh(styleData.row);
                        window.choose_phomai = choosenItemModel.getPhoMai(styleData.row);
                        window.g_prod_type = choosenItemModel.getTypeProduct(styleData.row);
                        if(window.g_prod_type === "OPTION_THEMPHOMAI" || window.g_prod_type === "OPTION_DEVIENPHOMAI") {
                            // khong the xoa duoc
                            deleteOptionPizzaDialog.open();
                        } else {
                            deleteItemDialog.open();
                        }
                    }
                }
            }
        }

        Connections {
            target: mainController
            onAddItem: {
                choosenItemModel.addItem(type, code_name, name, size, debanh, phomai, quantity, price, amount, oriprice, promtype)
            }

            onCancelBillItem: {
                // xóa hóa đơn đã thanh toán xong
                choosenItemModel.clear();
            }

            onRemoveItemPaymentView: {
                if(prod_type === "OTHER") {
                    choosenItemModel.removeItemOther(row);
                }

                if(prod_type === "PIZZA") {
                    var local_quantity = choosenItemModel.getQuantityPizza(row);
                    var local_productName = choosenItemModel.getProductName(row);
                    choosenItemModel.removePizzaOptionPlusChessy(local_quantity, "OPTION_THEMPHOMAI", size_banh, phomai)
                    choosenItemModel.removePizzaOptionDebanhPhomai(local_quantity, "OPTION_DEVIENPHOMAI", size_banh, de_banh)
                    choosenItemModel.removeItemPizza("PIZZA", local_productName, size_banh, de_banh, phomai);
                }
            }
        }
    }
}
