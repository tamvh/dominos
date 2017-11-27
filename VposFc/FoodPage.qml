import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

import QtQuick.Window 2.2

Rectangle {
    property int iconsize: Screen.devicePixelRatio < 2 ? 200 : 120 / Screen.devicePixelRatio
    property int fooditemfntsize: mainController.getConfigFoodItemFontsize()
    property int m_colCount: Math.min(width < iconsize ? 1 : width / iconsize, 4)
    property int m_colSpace: width / 25
    property int m_cellw: width / m_colCount
    property int m_cellh: m_cellw+30

    property bool itmfilter: false
    property string presrchtxt: ""

    color: "transparent"

    ListModel {
        id: foodsModel
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

    function appendFood(foodname, price, image, img_cache, oriprice, promtype) {
        var priceString = mainController.moneyMoney(price)
        var oriString = "";
        if (oriprice > 0) {
            oriString = mainController.moneyMoney(oriprice)
        }

        var latin = mainController.viet2latin(foodname)

        foodsModel.append({name: foodname, namelatin: latin, price: priceString, image: image, img_cache: img_cache,
                              oriprice: oriString, promtype: promtype, itmviewable: true})
    }

    GridView {
        id: gridItemView
        anchors.fill: parent
        cellWidth: m_cellw
        cellHeight: m_cellh
        focus: true
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
                rcColor: item.GridView.isCurrentItem? "#FF5722":"#E2E6E7"

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
                            Label {
                                id:foodName
                                text: name
                                font.pixelSize: cellFontSize
                                anchors.horizontalCenter: parent.horizontalCenter
                                horizontalAlignment: Text.AlignHCenter

                                //--- text multi lines ...
                            }

                            RowLayout {
                                anchors.horizontalCenter: parent.horizontalCenter

                                Text {
                                    text: oriprice
                                    //text: promtype
                                    color: "#4a9fe7"
                                    font.pixelSize: cellFontSize + 2
                                    font.strikeout: true
                                }

                                Text {
                                    text: price
                                    color: "#FF0000"
                                    font.pixelSize: cellFontSize + 6
                                }

                                Text {
                                    text: "VNĐ"
                                    color: "#FF0000"
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
                            mainController.insertItem(name, price, oriprice, promtype)
                        }
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
