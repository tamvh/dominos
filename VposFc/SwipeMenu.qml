import QtQuick 2.6
import QtQuick.Controls 2.0

Page {
    id: page
    anchors.fill: parent

    SwipeView {
        id: swipeView
        anchors.fill: parent
        leftPadding: window.globalPadding - 5
        rightPadding: window.globalPadding - 7
        bottomPadding: window.globalPadding - 10
        spacing: 3

        currentIndex: tabBar.currentIndex

        function addSwipeViewAll(foods, visible)
        {
            var component = Qt.createComponent("FoodPage.qml")
            var swipe = component.createObject(swipeView, {visible:visible})

            var catelist = [];
            for( var cate in foods.dt.categories )
            {
                catelist.push(foods.dt.categories[cate].category_value)
            }

            // add foods to swipe page
            for(var item in foods.dt.items)
            {
                if( catelist.indexOf(foods.dt.items[item].cate_mask) >= 0 ) {
                    swipe.appendFood(
                                foods.dt.items[item].item_name,
                                foods.dt.items[item].price,
                                foods.dt.items[item].img_path,
                                foods.dt.items[item].img_cache,
                                foods.dt.items[item].promotion_type > 0 ? foods.dt.items[item].original_price : "",
                                                                          foods.dt.items[item].promotion_type)
                }
            }
        }

        function addSwipeView(foods, cateValue, visible)
        {
            var component = Qt.createComponent("FoodPage.qml")
            var swipe = component.createObject(swipeView, {visible:visible})

            // add foods to swipe page
            for(var item in foods.dt.items) {
                if ((foods.dt.items[item].cate_mask & cateValue) === cateValue) {
                    swipe.appendFood(
                                foods.dt.items[item].item_name,
                                foods.dt.items[item].price,
                                foods.dt.items[item].img_path,
                                foods.dt.items[item].img_cache,
                                foods.dt.items[item].promotion_type > 0 ? foods.dt.items[item].original_price : "",
                                                                          foods.dt.items[item].promotion_type)
                }
            }
        }        
    }

    header:
        VPOSTabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        function addTabButton(title, visible) {
            var component = Qt.createComponent("FoodTab.qml");
            var tab = component.createObject(tabBar, {text: title, visible:visible});
        }
    }

    Connections {
        target: mainController
        onFoodReset: {
            // reset tabbar header & food data
            while (tabBar.count > 0) {
                tabBar.removeItem(0);
                swipeView.removeItem(0);
            }
        }

        onFoodUpdate: {
            // refresh tabbar header & food data
            while (tabBar.count > 0) {
                tabBar.removeItem(0);
                swipeView.removeItem(0);
            }

            menus = JSON.parse(menus);

            // show tab categories "Tat ca"
            for(var categories in menus.dt.categories)
            {
                if (menus.dt.categories[categories].category_id === 0) {
                    // add tabbar header item
                    tabBar.addTabButton(menus.dt.categories[categories].category_name, true);

                    // add swipe page
                    swipeView.addSwipeViewAll(menus, true);

                    break;
                }
            }

            // show tab categories "Khác (s)"
            for(var category in menus.dt.categories)
            {
                if (menus.dt.categories[category].category_id !== 0) {
                    // add tabbar header item
                    tabBar.addTabButton(menus.dt.categories[category].category_name, true);

                    // add swipe page
                    swipeView.addSwipeView(menus, menus.dt.categories[category].category_value, true);
                }
            }

            mainController.uiFoodupdateStatus(1);
        }
    }
}
