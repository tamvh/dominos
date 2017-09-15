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

        function addSwipeView(foods, cateValue, cateName, visible)
        {
            var component = Qt.createComponent("FoodPage.qml")
            var swipe = component.createObject(swipeView, {visible:visible})

            // add foods to swipe page
            for(var item in foods.dt.items) {
                if ((foods.dt.items[item].cate_mask & cateValue) === cateValue) {
                    swipe.appendFood(
                                foods.dt.items[item].description,
                                "",
                                "",
                                cateName,
                                foods.dt.items[item].item_name,
                                foods.dt.items[item].price,
                                foods.dt.items[item].img_path,
                                foods.dt.items[item].img_cache,
                                foods.dt.items[item].promotion_type > 0 ? foods.dt.items[item].original_price : "",
                                                                          foods.dt.items[item].promotion_type)
                }
            }

        }

        function addSwipeViewPizza(foods, cateValue, cateName, visible)
        {
            var component_pizza = Qt.createComponent("FoodPizzaPage.qml")
            var swipe_pizza = component_pizza.createObject(swipeView, {visible:visible})

            if(cateName === 'Pizza Favorite') {
                swipe_pizza.appendSubCate(true, '59.000', '119.000', '179.000');
            }
            if(cateName === 'Pizza Classic') {
                swipe_pizza.appendSubCate(true, '69.000', '129.000', '199.000');
            }
            if(cateName === 'Pizza Premium') {
                swipe_pizza.appendSubCate(true, '79.000', '139.000', '219.000');
            }
            if(cateName === 'Pizza Signature') {
                swipe_pizza.appendSubCate(false, '0', '179.000', '279.000');
            }


            // add foods to swipe page
            for(var item_pizza in foods.dt.items) {
                if ((foods.dt.items[item_pizza].cate_mask & cateValue) === cateValue) {
                    swipe_pizza.appendFood(
                                foods.dt.items[item_pizza].description,
                                "",
                                "",
                                cateName,
                                foods.dt.items[item_pizza].item_name,
                                foods.dt.items[item_pizza].price,
                                foods.dt.items[item_pizza].img_path,
                                foods.dt.items[item_pizza].img_cache,
                                foods.dt.items[item_pizza].promotion_type > 0 ? foods.dt.items[item_pizza].original_price : "",
                                                                          foods.dt.items[item_pizza].promotion_type)
                }
            }
        }

        function groupBy(input) {
            var group = {};
            for(var i in input) {
                var item = input[i];
                var name = item["ProductName"];

                if (!name) {
                    group['Default Group'] = group['Default Group'] || [];
                    group['Default Group'].push(item);
                    return;
                }

                group[name] = group[name] || [];
                group[name].push(item);
            }
            return group;
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

        function addTabButtonPizza(title, visible) {
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

            // show tab categories "Khác (s)"
            var cate = menus.dt.categories;
            console.log("cate: " + JSON.stringify(cate));
            for(var category in cate)
            {
                if (cate[category].category_id !== 0) {
                    // add tabbar header item
                    var _cateName = cate[category].category_name
                    var _cateFull = "";
                    if(_cateName !== "Tất cả"){
                        if(_cateName === "Pizza Favorite") {
                            _cateFull = _cateName //+ "\n(S:59K, M: 119K, L: 179K)";
                        }
                        else if(_cateName === "Pizza Classic") {
                            _cateFull = _cateName //+ "\n(S:69K, M: 129K, L: 199K)";
                        }
                        else if(_cateName === "Pizza Premium") {
                            _cateFull = _cateName //+ "\n(S:79K, M: 139K, L: 219K)";
                        }
                        else if(_cateName === "Pizza Signature") {
                            _cateFull = _cateName //+ "\n(M: 179K, L: 279K)";
                        }
                        else {
                            _cateFull = _cateName;
                        }

                        if(_cateName.split(' ')[0] === 'Pizza') {
                            // add swipe page
                            tabBar.addTabButtonPizza(_cateFull, true);
                            swipeView.addSwipeViewPizza(menus, cate[category].category_value, _cateName, true);
                        } else {
                            tabBar.addTabButton(_cateFull, true);
                            swipeView.addSwipeView(menus, cate[category].category_value, _cateName, true);
                        }

                    }
                }
            }

            mainController.uiFoodupdateStatus(1);
        }
    }
}
