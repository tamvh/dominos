import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

import QtQuick.Window 2.2



Rectangle {
    property int iconsize: Screen.devicePixelRatio < 2 ? 200 : 120 / Screen.devicePixelRatio
    property int fooditemfntsize: mainController.getConfigFoodItemFontsize()
    property int m_colCount: 3//Math.min(width < iconsize ? 1 : width / iconsize, 4)
    property int m_colSpace: width / 25
    property int m_cellw: width / m_colCount
    property int m_cellh: m_cellw+30

    property bool itmfilter: false
    property string presrchtxt: ""

    color: "transparent"

    ListModel {
        id: foodsModel
    }
    ListModel {
        id: subCateModel
    }

    function reset() {
        foodsModel.clear()
    }

    function resetfilter() {
        for (var i = 0; i < foodsModel.count; i++) {
            foodsModel.get(i).itmviewable = true;
        }
    }

    function filter_counttimer(srchtxt)
    {
        var timeticks1 = new Date().getTime();

        var foundfilter = true;
        var srchItems = 0;
        var foundItems = 0;
        var moveItems = 0;

        if (srchtxt === "") {
            resetfilter();
        }
        else if (srchtxt.length < presrchtxt.length)
        {
            // kiểm tra show những item đã bị hide

            // giả định không có food item nào tìm thấy
            foundfilter = false

            for (var i = 0, pos=0; i < foodsModel.count; pos++, i++)
            {
                //++ dùng code này để đếm hàm search

                if ( !foodsModel.get(pos).itmviewable )
                {
                    srchItems++;

                    if ( !mainController.searchFilter(foodsModel.get(pos).namelatin, srchtxt) )
                    {
                        foodsModel.move(pos--, foodsModel.count-1, 1);

                        moveItems++;
                    }
                    else {
                        foodsModel.get(pos).itmviewable = true;
                        foundfilter = true

                        foundItems++;
                    }
                }
                else {
                    foodsModel.get(pos).itmviewable = true;
                    foundfilter = true

                    foundItems++;
                }
            }
        }
        else
        {
            // tìm chuỗi mới, giả định không có food item nào tìm thấy
            foundfilter = false

            for (var i = 0, pos=0; i < foodsModel.count; pos++, i++)
            {
                //++ dùng code này để đếm hàm search

                if ( foodsModel.get(pos).itmviewable )
                {
                    srchItems++;

                    if ( !mainController.searchFilter(foodsModel.get(pos).namelatin, srchtxt) )
                    {
                        foodsModel.get(pos).itmviewable = false;
                        foodsModel.move(pos--, foodsModel.count-1, 1);

                        moveItems++;
                    }
                    else {
                        foundfilter = true

                        foundItems++;
                    }
                }
                else {
                    foundfilter = true
                }
            }
        }

        // scroll position to beginning of view
        gridItemView.positionViewAtBeginning()
        gridItemView.currentIndex = 0
        verticalScrollBar.position = gridItemView.visibleArea.yPosition

        presrchtxt = srchtxt

        var timeticks2 = new Date().getTime();
        console.log("Search " + srchItems + " items, text:'" + srchtxt + "' found item:" + foundItems + ", moved item:" + moveItems + ", total time tick:" + (timeticks2-timeticks1))

        return foundfilter;
    }
    function filter(srchtxt)
    {
        var foundfilter = true;

        if (srchtxt === "") {
            resetfilter();
        }
        else if (srchtxt.length < presrchtxt.length)
        {
            // kiểm tra show những item đã bị hide

            // giả định không có food item nào tìm thấy
            foundfilter = false

            for (var i = 0, pos=0; i < foodsModel.count; pos++, i++)
            {
                if ( !foodsModel.get(pos).itmviewable &&
                     !mainController.searchFilter(foodsModel.get(pos).namelatin, srchtxt) )
                {
                    foodsModel.move(pos--, foodsModel.count-1, 1);
                } else {
                    foodsModel.get(pos).itmviewable = true;
                    foundfilter = true
                }
            }
        }
        else
        {
            // tìm chuỗi mới, giả định không có food item nào tìm thấy
            foundfilter = false

            for (var i = 0, pos=0; i < foodsModel.count; pos++, i++)
            {
                if ( foodsModel.get(pos).itmviewable &&
                     !mainController.searchFilter(foodsModel.get(pos).namelatin, srchtxt) )
                {
                    foodsModel.get(pos).itmviewable = false;
                    foodsModel.move(pos--, foodsModel.count-1, 1);
                } else {
                    foundfilter = true
                }
            }
        }

        // scroll position to beginning of view
        gridItemView.positionViewAtBeginning()
        gridItemView.currentIndex = 0
        verticalScrollBar.position = gridItemView.visibleArea.yPosition

        presrchtxt = srchtxt

        return foundfilter;
    }

    function appendSubCate(visible_price, text_price7, text_price9, text_price12) {
        subCateModel.append({visible_price: visible_price, text_price7: text_price7, text_price9: text_price9, text_price12: text_price12})
    }

    function appendFood(description, min_size, objdata, category, foodcode, foodname, price, image, img_cache, oriprice, promtype) {
        var priceString = mainController.moneyMoney(price)
        var oriString = "";
        if (oriprice > 0) {
            oriString = mainController.moneyMoney(oriprice)
        }

        var latin = mainController.viet2latin(foodname)
        var visible_price = true;

        if(category.split(' ')[0] === 'Pizza') {
            visible_price = false
        }
        foodsModel.append({description: description, visible_price: visible_price, min_size: min_size, objdata: objdata, category: category, code: foodcode, name: foodname, namelatin: latin, price: priceString, image: image, img_cache: img_cache,
                              oriprice: oriString, promtype: promtype, itmviewable: true})
    }

    Rectangle {
        id: rectTitle
        height: 100
        width: parent.width
        color: "transparent"
        GridView {
            id: gridSubCateView

            anchors.centerIn: parent
            focus: true
            model: subCateModel

            delegate: Item {
                property int cellFontSize: fooditemfntsize
                RowLayout {
                    anchors.centerIn: parent
                    //anchors.fill: parent
                    Item {
                        height: 80
                        width: 80
                        visible: visible_price
                        Image {
                            fillMode: Image.Stretch
                            anchors.fill: parent
                            anchors.margins: 2
                            source: 'qrc:/icons/images/app/size_7.svg'
                        }
                    }
                    Column {
                        spacing: 10
                        RowLayout {
                            Label {
                                visible: visible_price
                                text: "Nhỏ(7\")"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                visible: visible_price
                                text: "-"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                visible: visible_price
                                text: "4 miếng"
                                font.pixelSize: cellFontSize + 4
                            }
                        }
                        RowLayout {
                            Label {
                                visible: visible_price
                                text: text_price7 + " VNĐ"
                                color: "red"
                                font.pixelSize: cellFontSize + 4
                            }
                        }
                    }


                    Rectangle {
                        visible: visible_price
                        height: 60
                        width: 10
                        color: "transparent"
                    }
                    Item {
                        height: 80
                        width: 80
                        Image {
                            fillMode: Image.Stretch
                            anchors.fill: parent
                            anchors.margins: 2
                            source: 'qrc:/icons/images/app/size_9.svg'
                        }
                    }
                    Column {
                        spacing: 10
                        RowLayout {
                            Label {
                                text: "Vừa(9\")"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                text: "-"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                text: "6 miếng"
                                font.pixelSize: cellFontSize + 4
                            }
                        }
                        RowLayout {
                            Label {
                                text: text_price9
                                color: "#4a9fe7"
                                font.pixelSize: cellFontSize + 4
                                font.strikeout: true
                            }
                            Label {
                                text: mainController.moneyMoney(mainController.getPriceCoupon(mainController.getMoneyValue(text_price9), '9'))  + " VNĐ"
                                color: "red"
                                font.pixelSize: cellFontSize + 6
                            }
                        }
                    }


                    Rectangle {
                        height: 60
                        width: 10
                        color: "transparent"
                    }
                    Item {
                        height: 80
                        width: 80
                        Image {
                            fillMode: Image.Stretch
                            anchors.fill: parent
                            anchors.margins: 2
                            source: 'qrc:/icons/images/app/size_12.svg'
                        }
                    }
                    Column {
                        spacing: 10
                        RowLayout {
                            Label {
                                text: "Nhỏ(12\")"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                text: "-"
                                font.pixelSize: cellFontSize + 4
                            }
                            Label {
                                text: "8 miếng"
                                font.pixelSize: cellFontSize + 4
                            }
                        }
                        RowLayout {
                            Label {
                                text: text_price12
                                color: "#4a9fe7"
                                font.pixelSize: cellFontSize + 6
                                font.strikeout: true
                            }
                            Label {
                                text: mainController.moneyMoney(mainController.getPriceCoupon(mainController.getMoneyValue(text_price12), '12'))  + " VNĐ"
                                color: "red"
                                font.pixelSize: cellFontSize + 6
                            }
                        }
                    }
                }
            }
        }
    }

    GridView {
        id: gridItemView
        anchors.fill: parent
        cellWidth: m_cellw
        cellHeight: m_cellh
        focus: true
        anchors.top: rectTitle.bottom
        anchors.topMargin: 100
        model: foodsModel

        delegate: Item {
            id: item
            width: m_cellw
            height: m_cellh
            property int cellPadding: 3
            property int cellFontSize: fooditemfntsize

            HalfRadiusRectangle {
                id: halfRect
                anchors.fill: parent
                anchors.leftMargin: cellPadding
                anchors.rightMargin: cellPadding
                anchors.bottomMargin: cellPadding*2
                property bool viewitem : true

                bottomRadius: 10
                radiusWidth: 1
                rcColor: item.GridView.isCurrentItem? "#006493":"#E2E6E7"
                // search-filter
                opacity: itmviewable

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Item {
                        id: itemImage
                        anchors.top: parent.top
                        width:parent.width
                        height:width*255/310
                        Image {
                            id: foodIcon
                            fillMode: Image.Stretch
                            anchors.fill: parent
                            anchors.margins: 2
                            asynchronous: true
                            cache: img_cache
                            source: image
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                        anchors.top: itemImage.bottom
                        anchors.bottom: parent.bottom

                        ColumnLayout {
                            anchors.centerIn: parent
                            spacing: 5 / Screen.devicePixelRatio
                            RowLayout {
                                anchors.horizontalCenter: parent.horizontalCenter
                                Label {
                                    id:foodName
                                    text: name
                                    font.pixelSize: cellFontSize
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    horizontalAlignment: Text.AlignHCenter

                                    //--- text multi lines ...
                                }
                            }

                            RowLayout {
                                anchors.horizontalCenter: parent.horizontalCenter
                                visible: visible_price
                                Text {
                                    text: oriprice
                                    //text: promtype
                                    color: "#4a9fe7"
                                    font.pixelSize: cellFontSize + 2
                                    font.strikeout: true
                                }

                                Text {
                                    text: price
                                    color: "red"
                                    font.pixelSize: cellFontSize + 6
                                }

                                Text {
                                    text: "VNĐ"
                                    color: "red"
                                    font.pixelSize: cellFontSize
                                    anchors.bottom: parent.bottom
                                    anchors.margins: 4
                                }
                            }
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (halfRect.opacity) {
                            gridItemView.currentIndex = index
                            var name_code = "";
                            window.url_img = image
                            window.obj_data = objdata
                            window.pizza_prod_code = code
                            window.pizza_prod_name = name
                            window.pizza_prize = mainController.getMoneyValue(price);
                            var _quantity = 1;
                            window.pizza_money = mainController.moneyMoney(mainController.getMoneyValue(price) * _quantity)
                            window.min_size = min_size;
                            window.pizza_category = category;
                            var _cateName = category.split('\n')[0];
                            if(_cateName === "Pizza Favorite" ||
                                    _cateName === "Pizza Classic" ||
                                    _cateName === "Pizza Premium" ||
                                    _cateName === "Pizza Signature") {
                                if(_cateName === "Pizza Signature") {
                                    window.getMoney(_cateName, '9', 1)
                                    window.enable_cheesy = true;
                                } else {
                                    window.getMoney(_cateName, '7', 1)
                                    window.enable_cheesy = false;
                                }
                                window.reset(category);
                                cakeInfoDialog.open()
                            } else {
                                mainController.insertItem(name_code, name.split('\n')[0], "-", "-", price, _quantity, oriprice, 0)
                            }
                        }
                    }
                }
            }
            Rectangle {
                width: 48
                height: 48
                opacity: 0.5
                anchors.left: parent.left
                anchors.leftMargin: 6
                anchors.top: parent.top
                anchors.topMargin: 3
                color: "transparent"
                border.color: "lightgrey"
                border.width: 1
                radius: 30
                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    fillMode: Image.Pad
                    source: "qrc:/icons/images/app/details.png"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        window.zoom_prod_name = name;
                        window.zoom_prod_img = image;
                        window.zoom_prod_thanhphan = description;
                        zoomItemDialog.open()
                    }
                }
            }
        }
    }

    VPOSScrollBar {
        id: verticalScrollBar
        width: 10
        height: gridItemView.height - 10
        anchors.right: gridItemView.right
        anchors.margins: -8
        opacity: gridItemView.contentHeight > gridItemView.height ? 1.0: 0
        orientation: Qt.Vertical
        position: gridItemView.visibleArea.yPosition
        pageSize: gridItemView.visibleArea.heightRatio
    }
}
