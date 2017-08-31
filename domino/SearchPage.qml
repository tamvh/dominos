import QtQuick 2.6
import QtQuick.Controls 2.0

Page {
    id: searchPage
    anchors.fill: parent

    FoodPage {
        id: searchResult
        itmfilter:true
        anchors.fill: parent
        anchors.topMargin:globalPadding
    }

    Connections {
        target: mainController
        onFoodSearching: {
            appMessage.close()
            if ( searchResult.filter(srchtxt) === false ) {
                appMessage.showMessage("Không có món ăn nào tìm thấy ...")
            }
        }

        onFoodReset: {
            searchResult.reset();
        }

        onFoodUpdate: {
            searchResult.reset();

            var foods = JSON.parse(menus);

            // add foods to swipe page

            var catelist = [];
            for( var cate in foods.dt.categories )
            {
                catelist.push(foods.dt.categories[cate].category_value)
            }

            // add foods to swipe page
            for(var item in foods.dt.items)
            {
                if( catelist.indexOf(foods.dt.items[item].cate_mask) >= 0 ) {
                    searchResult.appendFood(
                                foods.dt.items[item].item_name,
                                foods.dt.items[item].price,
                                foods.dt.items[item].img_path,
                                foods.dt.items[item].img_cache,
                                foods.dt.items[item].promotion_type > 0 ? foods.dt.items[item].original_price : "",
                                                                          foods.dt.items[item].promotion_type)
                }
            }

            mainController.uiFoodupdateStatus(2);
        }
    }
}
