/****************************************************************************
** Meta object code from reading C++ file 'maincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../domino/maincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainController_t {
    QByteArrayData data[293];
    char stringdata0[3732];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainController_t qt_meta_stringdata_MainController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainController"
QT_MOC_LITERAL(1, 15, 9), // "foodReset"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "foodUpdate"
QT_MOC_LITERAL(4, 37, 5), // "menus"
QT_MOC_LITERAL(5, 43, 13), // "foodSearching"
QT_MOC_LITERAL(6, 57, 7), // "srchtxt"
QT_MOC_LITERAL(7, 65, 7), // "paySucc"
QT_MOC_LITERAL(8, 73, 9), // "invcecode"
QT_MOC_LITERAL(9, 83, 6), // "qrcode"
QT_MOC_LITERAL(10, 90, 8), // "discount"
QT_MOC_LITERAL(11, 99, 6), // "oripay"
QT_MOC_LITERAL(12, 106, 7), // "discpay"
QT_MOC_LITERAL(13, 114, 8), // "payError"
QT_MOC_LITERAL(14, 123, 3), // "msg"
QT_MOC_LITERAL(15, 127, 10), // "notifySucc"
QT_MOC_LITERAL(16, 138, 7), // "errcode"
QT_MOC_LITERAL(17, 146, 9), // "invcetime"
QT_MOC_LITERAL(18, 156, 7), // "barcode"
QT_MOC_LITERAL(19, 164, 7), // "balance"
QT_MOC_LITERAL(20, 172, 7), // "addItem"
QT_MOC_LITERAL(21, 180, 9), // "code_name"
QT_MOC_LITERAL(22, 190, 4), // "name"
QT_MOC_LITERAL(23, 195, 4), // "size"
QT_MOC_LITERAL(24, 200, 6), // "debanh"
QT_MOC_LITERAL(25, 207, 8), // "quantity"
QT_MOC_LITERAL(26, 216, 5), // "price"
QT_MOC_LITERAL(27, 222, 6), // "amount"
QT_MOC_LITERAL(28, 229, 8), // "oriprice"
QT_MOC_LITERAL(29, 238, 8), // "promtype"
QT_MOC_LITERAL(30, 247, 14), // "cancelBillItem"
QT_MOC_LITERAL(31, 262, 24), // "cancellBillCloseQRDialog"
QT_MOC_LITERAL(32, 287, 12), // "updateAmount"
QT_MOC_LITERAL(33, 300, 12), // "scanDockDone"
QT_MOC_LITERAL(34, 313, 8), // "listDock"
QT_MOC_LITERAL(35, 322, 20), // "dockConnectionChange"
QT_MOC_LITERAL(36, 343, 9), // "connected"
QT_MOC_LITERAL(37, 353, 8), // "pingDone"
QT_MOC_LITERAL(38, 362, 4), // "data"
QT_MOC_LITERAL(39, 367, 14), // "wifiStatusDone"
QT_MOC_LITERAL(40, 382, 11), // "showMessage"
QT_MOC_LITERAL(41, 394, 21), // "cloudConnectionChange"
QT_MOC_LITERAL(42, 416, 17), // "notifyFoodRequest"
QT_MOC_LITERAL(43, 434, 9), // "printDone"
QT_MOC_LITERAL(44, 444, 14), // "dockStatistics"
QT_MOC_LITERAL(45, 459, 4), // "stat"
QT_MOC_LITERAL(46, 464, 19), // "printerReadyChanged"
QT_MOC_LITERAL(47, 484, 5), // "ready"
QT_MOC_LITERAL(48, 490, 13), // "paymentUpdate"
QT_MOC_LITERAL(49, 504, 7), // "methods"
QT_MOC_LITERAL(50, 512, 11), // "paymentMask"
QT_MOC_LITERAL(51, 524, 30), // "updateShowthanhtoancungdonhang"
QT_MOC_LITERAL(52, 555, 6), // "isShow"
QT_MOC_LITERAL(53, 562, 11), // "cardPayment"
QT_MOC_LITERAL(54, 574, 6), // "cardId"
QT_MOC_LITERAL(55, 581, 12), // "errorMessage"
QT_MOC_LITERAL(56, 594, 3), // "err"
QT_MOC_LITERAL(57, 598, 11), // "updateTitle"
QT_MOC_LITERAL(58, 610, 5), // "title"
QT_MOC_LITERAL(59, 616, 9), // "onPayZalo"
QT_MOC_LITERAL(60, 626, 5), // "sesid"
QT_MOC_LITERAL(61, 632, 4), // "biid"
QT_MOC_LITERAL(62, 637, 12), // "loginRequest"
QT_MOC_LITERAL(63, 650, 5), // "login"
QT_MOC_LITERAL(64, 656, 13), // "baocaoRequest"
QT_MOC_LITERAL(65, 670, 11), // "idleTimeout"
QT_MOC_LITERAL(66, 682, 11), // "dominosData"
QT_MOC_LITERAL(67, 694, 18), // "dominosSetProdName"
QT_MOC_LITERAL(68, 713, 13), // "QSet<QString>"
QT_MOC_LITERAL(69, 727, 21), // "removeItemPaymentView"
QT_MOC_LITERAL(70, 749, 3), // "row"
QT_MOC_LITERAL(71, 753, 12), // "onCancelDone"
QT_MOC_LITERAL(72, 766, 13), // "onCancelError"
QT_MOC_LITERAL(73, 780, 12), // "onRejectDone"
QT_MOC_LITERAL(74, 793, 13), // "onRejectError"
QT_MOC_LITERAL(75, 807, 13), // "onPayZaloDone"
QT_MOC_LITERAL(76, 821, 14), // "onPayZaloError"
QT_MOC_LITERAL(77, 836, 5), // "error"
QT_MOC_LITERAL(78, 842, 8), // "onNotify"
QT_MOC_LITERAL(79, 851, 7), // "message"
QT_MOC_LITERAL(80, 859, 13), // "onMifareFound"
QT_MOC_LITERAL(81, 873, 2), // "id"
QT_MOC_LITERAL(82, 876, 20), // "onCenterServiceFound"
QT_MOC_LITERAL(83, 897, 2), // "ip"
QT_MOC_LITERAL(84, 900, 4), // "port"
QT_MOC_LITERAL(85, 905, 11), // "onFoodsDone"
QT_MOC_LITERAL(86, 917, 12), // "onFoodsError"
QT_MOC_LITERAL(87, 930, 18), // "onUpdatedFoodsData"
QT_MOC_LITERAL(88, 949, 22), // "onCheckUpdateFoodsData"
QT_MOC_LITERAL(89, 972, 27), // "onCheckUpdateFoodsDataError"
QT_MOC_LITERAL(90, 1000, 7), // "onLogin"
QT_MOC_LITERAL(91, 1008, 5), // "uname"
QT_MOC_LITERAL(92, 1014, 3), // "pwd"
QT_MOC_LITERAL(93, 1018, 8), // "isBaocao"
QT_MOC_LITERAL(94, 1027, 11), // "onLoginDone"
QT_MOC_LITERAL(95, 1039, 12), // "onLoginError"
QT_MOC_LITERAL(96, 1052, 8), // "onBaocao"
QT_MOC_LITERAL(97, 1061, 12), // "onBaocaoDone"
QT_MOC_LITERAL(98, 1074, 13), // "onBaocaoError"
QT_MOC_LITERAL(99, 1088, 9), // "doPayCard"
QT_MOC_LITERAL(100, 1098, 10), // "doGetPmsid"
QT_MOC_LITERAL(101, 1109, 12), // "merchantCode"
QT_MOC_LITERAL(102, 1122, 5), // "devId"
QT_MOC_LITERAL(103, 1128, 4), // "biId"
QT_MOC_LITERAL(104, 1133, 9), // "payMethod"
QT_MOC_LITERAL(105, 1143, 15), // "onPmsidDoneZalo"
QT_MOC_LITERAL(106, 1159, 15), // "onPmsidDoneCash"
QT_MOC_LITERAL(107, 1175, 12), // "onPmsidError"
QT_MOC_LITERAL(108, 1188, 9), // "doPayZalo"
QT_MOC_LITERAL(109, 1198, 5), // "sesId"
QT_MOC_LITERAL(110, 1204, 9), // "doPayCash"
QT_MOC_LITERAL(111, 1214, 13), // "onPayCashDone"
QT_MOC_LITERAL(112, 1228, 14), // "onPayCashError"
QT_MOC_LITERAL(113, 1243, 12), // "foodsRequest"
QT_MOC_LITERAL(114, 1256, 19), // "checkUpdateFoodData"
QT_MOC_LITERAL(115, 1276, 16), // "timerStartUpdate"
QT_MOC_LITERAL(116, 1293, 13), // "timerDoUpdate"
QT_MOC_LITERAL(117, 1307, 11), // "timerReboot"
QT_MOC_LITERAL(118, 1319, 15), // "timerSystemIdle"
QT_MOC_LITERAL(119, 1335, 15), // "onStoreProducts"
QT_MOC_LITERAL(120, 1351, 13), // "storeProducts"
QT_MOC_LITERAL(121, 1365, 18), // "onStoreInformation"
QT_MOC_LITERAL(122, 1384, 16), // "storeInformation"
QT_MOC_LITERAL(123, 1401, 11), // "isDebugmode"
QT_MOC_LITERAL(124, 1413, 11), // "isRaspberry"
QT_MOC_LITERAL(125, 1425, 13), // "isCashAllowed"
QT_MOC_LITERAL(126, 1439, 13), // "isCardAllowed"
QT_MOC_LITERAL(127, 1453, 7), // "appQuit"
QT_MOC_LITERAL(128, 1461, 12), // "searchFilter"
QT_MOC_LITERAL(129, 1474, 8), // "foodname"
QT_MOC_LITERAL(130, 1483, 10), // "searchFood"
QT_MOC_LITERAL(131, 1494, 10), // "viet2latin"
QT_MOC_LITERAL(132, 1505, 3), // "pay"
QT_MOC_LITERAL(133, 1509, 13), // "customer_name"
QT_MOC_LITERAL(134, 1523, 17), // "customer_hinhthuc"
QT_MOC_LITERAL(135, 1541, 5), // "foods"
QT_MOC_LITERAL(136, 1547, 10), // "insertItem"
QT_MOC_LITERAL(137, 1558, 11), // "formatMoney"
QT_MOC_LITERAL(138, 1570, 10), // "moneyValue"
QT_MOC_LITERAL(139, 1581, 13), // "getMoneyValue"
QT_MOC_LITERAL(140, 1595, 11), // "moneyString"
QT_MOC_LITERAL(141, 1607, 10), // "moneyMoney"
QT_MOC_LITERAL(142, 1618, 5), // "money"
QT_MOC_LITERAL(143, 1624, 16), // "updateTotalMoney"
QT_MOC_LITERAL(144, 1641, 20), // "updateCardWaitingPay"
QT_MOC_LITERAL(145, 1662, 7), // "waiting"
QT_MOC_LITERAL(146, 1670, 9), // "printBill"
QT_MOC_LITERAL(147, 1680, 6), // "ivcode"
QT_MOC_LITERAL(148, 1687, 9), // "printData"
QT_MOC_LITERAL(149, 1697, 10), // "cancelBill"
QT_MOC_LITERAL(150, 1708, 4), // "foId"
QT_MOC_LITERAL(151, 1713, 5), // "total"
QT_MOC_LITERAL(152, 1719, 10), // "stopDevice"
QT_MOC_LITERAL(153, 1730, 10), // "getPrinter"
QT_MOC_LITERAL(154, 1741, 10), // "setPrinter"
QT_MOC_LITERAL(155, 1752, 7), // "prnName"
QT_MOC_LITERAL(156, 1760, 10), // "getPayment"
QT_MOC_LITERAL(157, 1771, 13), // "getUrlService"
QT_MOC_LITERAL(158, 1785, 19), // "getTransferProtocol"
QT_MOC_LITERAL(159, 1805, 19), // "setTransferProtocol"
QT_MOC_LITERAL(160, 1825, 8), // "transpro"
QT_MOC_LITERAL(161, 1834, 10), // "initSocket"
QT_MOC_LITERAL(162, 1845, 10), // "setPayment"
QT_MOC_LITERAL(163, 1856, 11), // "paymentName"
QT_MOC_LITERAL(164, 1868, 16), // "setPaymentMethod"
QT_MOC_LITERAL(165, 1885, 13), // "paymentMethod"
QT_MOC_LITERAL(166, 1899, 16), // "getPaymentMethod"
QT_MOC_LITERAL(167, 1916, 14), // "setPaymentMask"
QT_MOC_LITERAL(168, 1931, 7), // "payment"
QT_MOC_LITERAL(169, 1939, 5), // "onoff"
QT_MOC_LITERAL(170, 1945, 14), // "getPaymentMask"
QT_MOC_LITERAL(171, 1960, 13), // "getDockServer"
QT_MOC_LITERAL(172, 1974, 13), // "setDockServer"
QT_MOC_LITERAL(173, 1988, 10), // "dockServer"
QT_MOC_LITERAL(174, 1999, 8), // "scanDock"
QT_MOC_LITERAL(175, 2008, 6), // "doAuto"
QT_MOC_LITERAL(176, 2015, 11), // "isConnected"
QT_MOC_LITERAL(177, 2027, 13), // "connectToDock"
QT_MOC_LITERAL(178, 2041, 8), // "serverIp"
QT_MOC_LITERAL(179, 2050, 18), // "disconnectFromDock"
QT_MOC_LITERAL(180, 2069, 16), // "testReaderDevice"
QT_MOC_LITERAL(181, 2086, 3), // "run"
QT_MOC_LITERAL(182, 2090, 10), // "updateWifi"
QT_MOC_LITERAL(183, 2101, 4), // "ssid"
QT_MOC_LITERAL(184, 2106, 3), // "key"
QT_MOC_LITERAL(185, 2110, 7), // "encrypt"
QT_MOC_LITERAL(186, 2118, 12), // "updateWifiPi"
QT_MOC_LITERAL(187, 2131, 9), // "interface"
QT_MOC_LITERAL(188, 2141, 9), // "scan_ssid"
QT_MOC_LITERAL(189, 2151, 10), // "wifiStatus"
QT_MOC_LITERAL(190, 2162, 8), // "testPing"
QT_MOC_LITERAL(191, 2171, 4), // "host"
QT_MOC_LITERAL(192, 2176, 11), // "restartDock"
QT_MOC_LITERAL(193, 2188, 9), // "restartPi"
QT_MOC_LITERAL(194, 2198, 6), // "haltPi"
QT_MOC_LITERAL(195, 2205, 18), // "checkPrinterStatus"
QT_MOC_LITERAL(196, 2224, 9), // "printTest"
QT_MOC_LITERAL(197, 2234, 10), // "getLocalIp"
QT_MOC_LITERAL(198, 2245, 11), // "getAppIndex"
QT_MOC_LITERAL(199, 2257, 10), // "getAppName"
QT_MOC_LITERAL(200, 2268, 10), // "setAppName"
QT_MOC_LITERAL(201, 2279, 7), // "appName"
QT_MOC_LITERAL(202, 2287, 11), // "getAppTitle"
QT_MOC_LITERAL(203, 2299, 11), // "getTitleEng"
QT_MOC_LITERAL(204, 2311, 11), // "setAppTitle"
QT_MOC_LITERAL(205, 2323, 15), // "getMachineIndex"
QT_MOC_LITERAL(206, 2339, 13), // "getAppMachine"
QT_MOC_LITERAL(207, 2353, 14), // "getRechargeNum"
QT_MOC_LITERAL(208, 2368, 14), // "setRechargeNum"
QT_MOC_LITERAL(209, 2383, 5), // "mcNum"
QT_MOC_LITERAL(210, 2389, 19), // "getFoodRefreshTimer"
QT_MOC_LITERAL(211, 2409, 19), // "setFoodRefreshTimer"
QT_MOC_LITERAL(212, 2429, 5), // "timer"
QT_MOC_LITERAL(213, 2435, 17), // "getBillAlertTimer"
QT_MOC_LITERAL(214, 2453, 17), // "setBillAlertTimer"
QT_MOC_LITERAL(215, 2471, 27), // "getShowThanhtoancungdonhang"
QT_MOC_LITERAL(216, 2499, 27), // "setShowThanhtoancungdonhang"
QT_MOC_LITERAL(217, 2527, 20), // "getConfigQrcodeRatio"
QT_MOC_LITERAL(218, 2548, 20), // "setConfigQrcodeRatio"
QT_MOC_LITERAL(219, 2569, 5), // "ratio"
QT_MOC_LITERAL(220, 2575, 25), // "getConfigFoodItemFontsize"
QT_MOC_LITERAL(221, 2601, 25), // "setConfigFoodItemFontsize"
QT_MOC_LITERAL(222, 2627, 7), // "fntsize"
QT_MOC_LITERAL(223, 2635, 25), // "getConfigBillItemFontsize"
QT_MOC_LITERAL(224, 2661, 25), // "setConfigBillItemFontsize"
QT_MOC_LITERAL(225, 2687, 16), // "getConfigSobanin"
QT_MOC_LITERAL(226, 2704, 16), // "setConfigSobanin"
QT_MOC_LITERAL(227, 2721, 3), // "num"
QT_MOC_LITERAL(228, 2725, 17), // "getConfigTenbanin"
QT_MOC_LITERAL(229, 2743, 17), // "setConfigTenbanin"
QT_MOC_LITERAL(230, 2761, 19), // "getConfigBillPreinf"
QT_MOC_LITERAL(231, 2781, 19), // "setConfigBillPreinf"
QT_MOC_LITERAL(232, 2801, 4), // "info"
QT_MOC_LITERAL(233, 2806, 20), // "getConfigBillPostinf"
QT_MOC_LITERAL(234, 2827, 20), // "setConfigBillPostinf"
QT_MOC_LITERAL(235, 2848, 20), // "getConfigDockversion"
QT_MOC_LITERAL(236, 2869, 20), // "setConfigDockversion"
QT_MOC_LITERAL(237, 2890, 7), // "version"
QT_MOC_LITERAL(238, 2898, 20), // "getConfigPrintersize"
QT_MOC_LITERAL(239, 2919, 20), // "setConfigPrintersize"
QT_MOC_LITERAL(240, 2940, 8), // "pagesize"
QT_MOC_LITERAL(241, 2949, 19), // "getUserEnableConfig"
QT_MOC_LITERAL(242, 2969, 19), // "setUserEnableConfig"
QT_MOC_LITERAL(243, 2989, 10), // "enableconf"
QT_MOC_LITERAL(244, 3000, 21), // "getConfigRebootDatePi"
QT_MOC_LITERAL(245, 3022, 21), // "setConfigRebootDatePi"
QT_MOC_LITERAL(246, 3044, 9), // "dayofweek"
QT_MOC_LITERAL(247, 3054, 2), // "on"
QT_MOC_LITERAL(248, 3057, 21), // "getConfigRebootTimePi"
QT_MOC_LITERAL(249, 3079, 4), // "type"
QT_MOC_LITERAL(250, 3084, 21), // "setConfigRebootTimePi"
QT_MOC_LITERAL(251, 3106, 5), // "value"
QT_MOC_LITERAL(252, 3112, 14), // "getRestartTime"
QT_MOC_LITERAL(253, 3127, 14), // "getCurrentTime"
QT_MOC_LITERAL(254, 3142, 17), // "getConfigUsername"
QT_MOC_LITERAL(255, 3160, 16), // "getConfigUserpwd"
QT_MOC_LITERAL(256, 3177, 22), // "getConfigSearchadvance"
QT_MOC_LITERAL(257, 3200, 22), // "setConfigSearchadvance"
QT_MOC_LITERAL(258, 3223, 13), // "searchadvance"
QT_MOC_LITERAL(259, 3237, 23), // "getConfigShowBaocaoDate"
QT_MOC_LITERAL(260, 3261, 23), // "setConfigShowBaocaoDate"
QT_MOC_LITERAL(261, 3285, 8), // "showDate"
QT_MOC_LITERAL(262, 3294, 22), // "getConfigCenterService"
QT_MOC_LITERAL(263, 3317, 22), // "setConfigCenterService"
QT_MOC_LITERAL(264, 3340, 15), // "centerServiceIp"
QT_MOC_LITERAL(265, 3356, 17), // "getConfigIdletime"
QT_MOC_LITERAL(266, 3374, 17), // "setConfigIdletime"
QT_MOC_LITERAL(267, 3392, 11), // "setIdCoupon"
QT_MOC_LITERAL(268, 3404, 11), // "getIdCoupon"
QT_MOC_LITERAL(269, 3416, 18), // "setIdCouponPercent"
QT_MOC_LITERAL(270, 3435, 7), // "percent"
QT_MOC_LITERAL(271, 3443, 18), // "getIdCouponPercent"
QT_MOC_LITERAL(272, 3462, 10), // "saveConfig"
QT_MOC_LITERAL(273, 3473, 16), // "sendCancelBillUI"
QT_MOC_LITERAL(274, 3490, 20), // "getBaocaoCurrentTime"
QT_MOC_LITERAL(275, 3511, 8), // "inBaocao"
QT_MOC_LITERAL(276, 3520, 4), // "date"
QT_MOC_LITERAL(277, 3525, 6), // "bcType"
QT_MOC_LITERAL(278, 3532, 9), // "userLogin"
QT_MOC_LITERAL(279, 3542, 18), // "uiFoodupdateStatus"
QT_MOC_LITERAL(280, 3561, 6), // "uiType"
QT_MOC_LITERAL(281, 3568, 10), // "getAccount"
QT_MOC_LITERAL(282, 3579, 14), // "getDiskPrepare"
QT_MOC_LITERAL(283, 3594, 14), // "getDiskReserve"
QT_MOC_LITERAL(284, 3609, 11), // "idleClearup"
QT_MOC_LITERAL(285, 3621, 9), // "idleReset"
QT_MOC_LITERAL(286, 3631, 14), // "getProductCode"
QT_MOC_LITERAL(287, 3646, 8), // "pro_name"
QT_MOC_LITERAL(288, 3655, 9), // "prod_size"
QT_MOC_LITERAL(289, 3665, 16), // "prod_plavor_code"
QT_MOC_LITERAL(290, 3682, 14), // "getPriceCoupon"
QT_MOC_LITERAL(291, 3697, 10), // "pizza_size"
QT_MOC_LITERAL(292, 3708, 23) // "removeItemInPaymentView"

    },
    "MainController\0foodReset\0\0foodUpdate\0"
    "menus\0foodSearching\0srchtxt\0paySucc\0"
    "invcecode\0qrcode\0discount\0oripay\0"
    "discpay\0payError\0msg\0notifySucc\0errcode\0"
    "invcetime\0barcode\0balance\0addItem\0"
    "code_name\0name\0size\0debanh\0quantity\0"
    "price\0amount\0oriprice\0promtype\0"
    "cancelBillItem\0cancellBillCloseQRDialog\0"
    "updateAmount\0scanDockDone\0listDock\0"
    "dockConnectionChange\0connected\0pingDone\0"
    "data\0wifiStatusDone\0showMessage\0"
    "cloudConnectionChange\0notifyFoodRequest\0"
    "printDone\0dockStatistics\0stat\0"
    "printerReadyChanged\0ready\0paymentUpdate\0"
    "methods\0paymentMask\0updateShowthanhtoancungdonhang\0"
    "isShow\0cardPayment\0cardId\0errorMessage\0"
    "err\0updateTitle\0title\0onPayZalo\0sesid\0"
    "biid\0loginRequest\0login\0baocaoRequest\0"
    "idleTimeout\0dominosData\0dominosSetProdName\0"
    "QSet<QString>\0removeItemPaymentView\0"
    "row\0onCancelDone\0onCancelError\0"
    "onRejectDone\0onRejectError\0onPayZaloDone\0"
    "onPayZaloError\0error\0onNotify\0message\0"
    "onMifareFound\0id\0onCenterServiceFound\0"
    "ip\0port\0onFoodsDone\0onFoodsError\0"
    "onUpdatedFoodsData\0onCheckUpdateFoodsData\0"
    "onCheckUpdateFoodsDataError\0onLogin\0"
    "uname\0pwd\0isBaocao\0onLoginDone\0"
    "onLoginError\0onBaocao\0onBaocaoDone\0"
    "onBaocaoError\0doPayCard\0doGetPmsid\0"
    "merchantCode\0devId\0biId\0payMethod\0"
    "onPmsidDoneZalo\0onPmsidDoneCash\0"
    "onPmsidError\0doPayZalo\0sesId\0doPayCash\0"
    "onPayCashDone\0onPayCashError\0foodsRequest\0"
    "checkUpdateFoodData\0timerStartUpdate\0"
    "timerDoUpdate\0timerReboot\0timerSystemIdle\0"
    "onStoreProducts\0storeProducts\0"
    "onStoreInformation\0storeInformation\0"
    "isDebugmode\0isRaspberry\0isCashAllowed\0"
    "isCardAllowed\0appQuit\0searchFilter\0"
    "foodname\0searchFood\0viet2latin\0pay\0"
    "customer_name\0customer_hinhthuc\0foods\0"
    "insertItem\0formatMoney\0moneyValue\0"
    "getMoneyValue\0moneyString\0moneyMoney\0"
    "money\0updateTotalMoney\0updateCardWaitingPay\0"
    "waiting\0printBill\0ivcode\0printData\0"
    "cancelBill\0foId\0total\0stopDevice\0"
    "getPrinter\0setPrinter\0prnName\0getPayment\0"
    "getUrlService\0getTransferProtocol\0"
    "setTransferProtocol\0transpro\0initSocket\0"
    "setPayment\0paymentName\0setPaymentMethod\0"
    "paymentMethod\0getPaymentMethod\0"
    "setPaymentMask\0payment\0onoff\0"
    "getPaymentMask\0getDockServer\0setDockServer\0"
    "dockServer\0scanDock\0doAuto\0isConnected\0"
    "connectToDock\0serverIp\0disconnectFromDock\0"
    "testReaderDevice\0run\0updateWifi\0ssid\0"
    "key\0encrypt\0updateWifiPi\0interface\0"
    "scan_ssid\0wifiStatus\0testPing\0host\0"
    "restartDock\0restartPi\0haltPi\0"
    "checkPrinterStatus\0printTest\0getLocalIp\0"
    "getAppIndex\0getAppName\0setAppName\0"
    "appName\0getAppTitle\0getTitleEng\0"
    "setAppTitle\0getMachineIndex\0getAppMachine\0"
    "getRechargeNum\0setRechargeNum\0mcNum\0"
    "getFoodRefreshTimer\0setFoodRefreshTimer\0"
    "timer\0getBillAlertTimer\0setBillAlertTimer\0"
    "getShowThanhtoancungdonhang\0"
    "setShowThanhtoancungdonhang\0"
    "getConfigQrcodeRatio\0setConfigQrcodeRatio\0"
    "ratio\0getConfigFoodItemFontsize\0"
    "setConfigFoodItemFontsize\0fntsize\0"
    "getConfigBillItemFontsize\0"
    "setConfigBillItemFontsize\0getConfigSobanin\0"
    "setConfigSobanin\0num\0getConfigTenbanin\0"
    "setConfigTenbanin\0getConfigBillPreinf\0"
    "setConfigBillPreinf\0info\0getConfigBillPostinf\0"
    "setConfigBillPostinf\0getConfigDockversion\0"
    "setConfigDockversion\0version\0"
    "getConfigPrintersize\0setConfigPrintersize\0"
    "pagesize\0getUserEnableConfig\0"
    "setUserEnableConfig\0enableconf\0"
    "getConfigRebootDatePi\0setConfigRebootDatePi\0"
    "dayofweek\0on\0getConfigRebootTimePi\0"
    "type\0setConfigRebootTimePi\0value\0"
    "getRestartTime\0getCurrentTime\0"
    "getConfigUsername\0getConfigUserpwd\0"
    "getConfigSearchadvance\0setConfigSearchadvance\0"
    "searchadvance\0getConfigShowBaocaoDate\0"
    "setConfigShowBaocaoDate\0showDate\0"
    "getConfigCenterService\0setConfigCenterService\0"
    "centerServiceIp\0getConfigIdletime\0"
    "setConfigIdletime\0setIdCoupon\0getIdCoupon\0"
    "setIdCouponPercent\0percent\0"
    "getIdCouponPercent\0saveConfig\0"
    "sendCancelBillUI\0getBaocaoCurrentTime\0"
    "inBaocao\0date\0bcType\0userLogin\0"
    "uiFoodupdateStatus\0uiType\0getAccount\0"
    "getDiskPrepare\0getDiskReserve\0idleClearup\0"
    "idleReset\0getProductCode\0pro_name\0"
    "prod_size\0prod_plavor_code\0getPriceCoupon\0"
    "pizza_size\0removeItemInPaymentView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     197,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      34,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  999,    2, 0x06 /* Public */,
       3,    1, 1000,    2, 0x06 /* Public */,
       5,    1, 1003,    2, 0x06 /* Public */,
       7,    5, 1006,    2, 0x06 /* Public */,
      13,    1, 1017,    2, 0x06 /* Public */,
      15,    5, 1020,    2, 0x06 /* Public */,
      20,    9, 1031,    2, 0x06 /* Public */,
      30,    0, 1050,    2, 0x06 /* Public */,
      31,    0, 1051,    2, 0x06 /* Public */,
      32,    1, 1052,    2, 0x06 /* Public */,
      33,    1, 1055,    2, 0x06 /* Public */,
      35,    1, 1058,    2, 0x06 /* Public */,
      37,    1, 1061,    2, 0x06 /* Public */,
      39,    1, 1064,    2, 0x06 /* Public */,
      40,    1, 1067,    2, 0x06 /* Public */,
      41,    1, 1070,    2, 0x06 /* Public */,
      42,    0, 1073,    2, 0x06 /* Public */,
      43,    1, 1074,    2, 0x06 /* Public */,
      44,    1, 1077,    2, 0x06 /* Public */,
      46,    1, 1080,    2, 0x06 /* Public */,
      48,    1, 1083,    2, 0x06 /* Public */,
      50,    1, 1086,    2, 0x06 /* Public */,
      51,    1, 1089,    2, 0x06 /* Public */,
      53,    1, 1092,    2, 0x06 /* Public */,
      55,    2, 1095,    2, 0x06 /* Public */,
      57,    1, 1100,    2, 0x06 /* Public */,
      59,    2, 1103,    2, 0x06 /* Public */,
      62,    0, 1108,    2, 0x06 /* Public */,
      63,    2, 1109,    2, 0x06 /* Public */,
      64,    0, 1114,    2, 0x06 /* Public */,
      65,    0, 1115,    2, 0x06 /* Public */,
      66,    1, 1116,    2, 0x06 /* Public */,
      67,    1, 1119,    2, 0x06 /* Public */,
      69,    1, 1122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      71,    1, 1125,    2, 0x0a /* Public */,
      72,    2, 1128,    2, 0x0a /* Public */,
      73,    1, 1133,    2, 0x0a /* Public */,
      74,    2, 1136,    2, 0x0a /* Public */,
      75,    1, 1141,    2, 0x0a /* Public */,
      76,    2, 1144,    2, 0x0a /* Public */,
      78,    1, 1149,    2, 0x0a /* Public */,
      80,    1, 1152,    2, 0x0a /* Public */,
      82,    2, 1155,    2, 0x0a /* Public */,
      85,    1, 1160,    2, 0x0a /* Public */,
      86,    2, 1163,    2, 0x0a /* Public */,
      87,    1, 1168,    2, 0x0a /* Public */,
      88,    1, 1171,    2, 0x0a /* Public */,
      89,    2, 1174,    2, 0x0a /* Public */,
      90,    3, 1179,    2, 0x0a /* Public */,
      94,    1, 1186,    2, 0x0a /* Public */,
      95,    2, 1189,    2, 0x0a /* Public */,
      96,    0, 1194,    2, 0x0a /* Public */,
      97,    1, 1195,    2, 0x0a /* Public */,
      98,    2, 1198,    2, 0x0a /* Public */,
      99,    1, 1203,    2, 0x0a /* Public */,
     100,    4, 1206,    2, 0x0a /* Public */,
     105,    1, 1215,    2, 0x0a /* Public */,
     106,    1, 1218,    2, 0x0a /* Public */,
     107,    2, 1221,    2, 0x0a /* Public */,
     108,    2, 1226,    2, 0x0a /* Public */,
     110,    2, 1231,    2, 0x0a /* Public */,
     111,    1, 1236,    2, 0x0a /* Public */,
     112,    2, 1239,    2, 0x0a /* Public */,
     113,    0, 1244,    2, 0x0a /* Public */,
     114,    0, 1245,    2, 0x0a /* Public */,
     115,    0, 1246,    2, 0x0a /* Public */,
     116,    0, 1247,    2, 0x0a /* Public */,
     117,    0, 1248,    2, 0x0a /* Public */,
     118,    0, 1249,    2, 0x0a /* Public */,
     119,    1, 1250,    2, 0x0a /* Public */,
     121,    1, 1253,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
     123,    0, 1256,    2, 0x02 /* Public */,
     124,    0, 1257,    2, 0x02 /* Public */,
     125,    0, 1258,    2, 0x02 /* Public */,
     126,    0, 1259,    2, 0x02 /* Public */,
     127,    0, 1260,    2, 0x02 /* Public */,
     128,    2, 1261,    2, 0x02 /* Public */,
     130,    1, 1266,    2, 0x02 /* Public */,
     131,    1, 1269,    2, 0x02 /* Public */,
     132,    5, 1272,    2, 0x02 /* Public */,
     136,    8, 1283,    2, 0x02 /* Public */,
     137,    1, 1300,    2, 0x02 /* Public */,
     139,    1, 1303,    2, 0x02 /* Public */,
     141,    1, 1306,    2, 0x02 /* Public */,
     143,    1, 1309,    2, 0x02 /* Public */,
     144,    1, 1312,    2, 0x02 /* Public */,
     146,    2, 1315,    2, 0x02 /* Public */,
     149,    3, 1320,    2, 0x02 /* Public */,
     152,    0, 1327,    2, 0x02 /* Public */,
     153,    0, 1328,    2, 0x02 /* Public */,
     154,    1, 1329,    2, 0x02 /* Public */,
     156,    0, 1332,    2, 0x02 /* Public */,
     157,    0, 1333,    2, 0x02 /* Public */,
     158,    0, 1334,    2, 0x02 /* Public */,
     159,    2, 1335,    2, 0x02 /* Public */,
     159,    1, 1340,    2, 0x22 /* Public | MethodCloned */,
     162,    2, 1343,    2, 0x02 /* Public */,
     162,    1, 1348,    2, 0x22 /* Public | MethodCloned */,
     164,    1, 1351,    2, 0x02 /* Public */,
     166,    0, 1354,    2, 0x02 /* Public */,
     167,    2, 1355,    2, 0x02 /* Public */,
     170,    0, 1360,    2, 0x02 /* Public */,
     171,    0, 1361,    2, 0x02 /* Public */,
     172,    1, 1362,    2, 0x02 /* Public */,
     174,    1, 1365,    2, 0x02 /* Public */,
     174,    0, 1368,    2, 0x22 /* Public | MethodCloned */,
     176,    0, 1369,    2, 0x02 /* Public */,
     177,    1, 1370,    2, 0x02 /* Public */,
     179,    0, 1373,    2, 0x02 /* Public */,
     180,    1, 1374,    2, 0x02 /* Public */,
     182,    3, 1377,    2, 0x02 /* Public */,
     182,    2, 1384,    2, 0x22 /* Public | MethodCloned */,
     186,    5, 1389,    2, 0x02 /* Public */,
     186,    4, 1400,    2, 0x22 /* Public | MethodCloned */,
     186,    3, 1409,    2, 0x22 /* Public | MethodCloned */,
     189,    1, 1416,    2, 0x02 /* Public */,
     189,    0, 1419,    2, 0x22 /* Public | MethodCloned */,
     190,    1, 1420,    2, 0x02 /* Public */,
     192,    0, 1423,    2, 0x02 /* Public */,
     193,    0, 1424,    2, 0x02 /* Public */,
     194,    0, 1425,    2, 0x02 /* Public */,
     195,    0, 1426,    2, 0x02 /* Public */,
     196,    1, 1427,    2, 0x02 /* Public */,
     197,    0, 1430,    2, 0x02 /* Public */,
     198,    0, 1431,    2, 0x02 /* Public */,
     199,    0, 1432,    2, 0x02 /* Public */,
     200,    2, 1433,    2, 0x02 /* Public */,
     200,    1, 1438,    2, 0x22 /* Public | MethodCloned */,
     202,    0, 1441,    2, 0x02 /* Public */,
     203,    0, 1442,    2, 0x02 /* Public */,
     204,    1, 1443,    2, 0x02 /* Public */,
     205,    0, 1446,    2, 0x02 /* Public */,
     206,    0, 1447,    2, 0x02 /* Public */,
     207,    0, 1448,    2, 0x02 /* Public */,
     208,    1, 1449,    2, 0x02 /* Public */,
     210,    0, 1452,    2, 0x02 /* Public */,
     211,    1, 1453,    2, 0x02 /* Public */,
     213,    0, 1456,    2, 0x02 /* Public */,
     214,    1, 1457,    2, 0x02 /* Public */,
     215,    0, 1460,    2, 0x02 /* Public */,
     216,    1, 1461,    2, 0x02 /* Public */,
     217,    0, 1464,    2, 0x02 /* Public */,
     218,    1, 1465,    2, 0x02 /* Public */,
     220,    0, 1468,    2, 0x02 /* Public */,
     221,    1, 1469,    2, 0x02 /* Public */,
     223,    0, 1472,    2, 0x02 /* Public */,
     224,    1, 1473,    2, 0x02 /* Public */,
     225,    0, 1476,    2, 0x02 /* Public */,
     226,    1, 1477,    2, 0x02 /* Public */,
     228,    0, 1480,    2, 0x02 /* Public */,
     229,    1, 1481,    2, 0x02 /* Public */,
     230,    0, 1484,    2, 0x02 /* Public */,
     231,    1, 1485,    2, 0x02 /* Public */,
     233,    0, 1488,    2, 0x02 /* Public */,
     234,    1, 1489,    2, 0x02 /* Public */,
     235,    0, 1492,    2, 0x02 /* Public */,
     236,    1, 1493,    2, 0x02 /* Public */,
     238,    0, 1496,    2, 0x02 /* Public */,
     239,    1, 1497,    2, 0x02 /* Public */,
     241,    0, 1500,    2, 0x02 /* Public */,
     242,    1, 1501,    2, 0x02 /* Public */,
     244,    0, 1504,    2, 0x02 /* Public */,
     245,    2, 1505,    2, 0x02 /* Public */,
     248,    1, 1510,    2, 0x02 /* Public */,
     248,    0, 1513,    2, 0x22 /* Public | MethodCloned */,
     250,    2, 1514,    2, 0x02 /* Public */,
     250,    1, 1519,    2, 0x22 /* Public | MethodCloned */,
     252,    0, 1522,    2, 0x02 /* Public */,
     253,    1, 1523,    2, 0x02 /* Public */,
     254,    0, 1526,    2, 0x02 /* Public */,
     255,    0, 1527,    2, 0x02 /* Public */,
     256,    0, 1528,    2, 0x02 /* Public */,
     257,    1, 1529,    2, 0x02 /* Public */,
     259,    0, 1532,    2, 0x02 /* Public */,
     260,    1, 1533,    2, 0x02 /* Public */,
     262,    0, 1536,    2, 0x02 /* Public */,
     263,    1, 1537,    2, 0x02 /* Public */,
     265,    0, 1540,    2, 0x02 /* Public */,
     266,    1, 1541,    2, 0x02 /* Public */,
     267,    1, 1544,    2, 0x02 /* Public */,
     268,    0, 1547,    2, 0x02 /* Public */,
     269,    1, 1548,    2, 0x02 /* Public */,
     271,    0, 1551,    2, 0x02 /* Public */,
     272,    0, 1552,    2, 0x02 /* Public */,
     273,    0, 1553,    2, 0x02 /* Public */,
     274,    0, 1554,    2, 0x02 /* Public */,
     275,    2, 1555,    2, 0x02 /* Public */,
     278,    2, 1560,    2, 0x02 /* Public */,
     279,    1, 1565,    2, 0x02 /* Public */,
     281,    0, 1568,    2, 0x02 /* Public */,
     282,    0, 1569,    2, 0x02 /* Public */,
     283,    0, 1570,    2, 0x02 /* Public */,
     284,    0, 1571,    2, 0x02 /* Public */,
     285,    0, 1572,    2, 0x02 /* Public */,
     286,    3, 1573,    2, 0x02 /* Public */,
     290,    2, 1580,    2, 0x02 /* Public */,
     292,    1, 1585,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,    8,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,   26,   27,   28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QStringList,   34,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   16,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   56,   14,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   60,   61,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   56,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   38,
    QMetaType::Void, 0x80000000 | 68,   38,
    QMetaType::Void, QMetaType::Int,   70,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   14,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QString,   81,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   83,   84,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   79,
    QMetaType::Void, QMetaType::QString,   79,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   79,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   91,   92,   93,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   14,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,  101,  102,  103,  104,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  109,  103,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  109,  103,
    QMetaType::Void, QMetaType::QVariant,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   77,   79,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,  120,
    QMetaType::Void, QMetaType::QJsonObject,  122,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  129,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,   22,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QJsonArray, QMetaType::Int,  133,  134,   27,  135,  104,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   26,   25,   28,   29,
    QMetaType::QString, QMetaType::LongLong,  138,
    QMetaType::LongLong, QMetaType::QString,  140,
    QMetaType::QString, QMetaType::QString,  142,
    QMetaType::Void, QMetaType::LongLong,  138,
    QMetaType::Void, QMetaType::Bool,  145,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  147,  148,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  150,    8,  151,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  155,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  160,  161,
    QMetaType::Void, QMetaType::QString,  160,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  163,  161,
    QMetaType::Void, QMetaType::QString,  163,
    QMetaType::Void, QMetaType::Int,  165,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  168,  169,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  173,
    QMetaType::Void, QMetaType::Bool,  175,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,  178,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  181,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  183,  184,  185,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  183,  184,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  187,  183,  184,  185,  188,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  187,  183,  184,  185,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  187,  183,  184,
    QMetaType::Void, QMetaType::QString,  187,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  191,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,  135,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  201,  161,
    QMetaType::Void, QMetaType::QString,  201,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  209,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  212,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  212,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  219,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  222,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  222,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  227,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  232,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  232,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  237,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  240,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  243,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  246,  247,
    QMetaType::Int, QMetaType::Int,  249,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  251,  249,
    QMetaType::Void, QMetaType::Int,  251,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Bool,  247,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  258,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  261,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  264,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  212,
    QMetaType::Void, QMetaType::QString,   81,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  270,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  276,  277,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   91,   92,
    QMetaType::Void, QMetaType::Int,  280,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  287,  288,  289,
    QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,   26,  291,
    QMetaType::Void, QMetaType::Int,   70,

       0        // eod
};

void MainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainController *_t = static_cast<MainController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->foodReset(); break;
        case 1: _t->foodUpdate((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 2: _t->foodSearching((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->paySucc((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 4: _t->payError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->notifySucc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 6: _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< long(*)>(_a[5])),(*reinterpret_cast< long long(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9]))); break;
        case 7: _t->cancelBillItem(); break;
        case 8: _t->cancellBillCloseQRDialog(); break;
        case 9: _t->updateAmount((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->scanDockDone((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 11: _t->dockConnectionChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->pingDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->wifiStatusDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->cloudConnectionChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->notifyFoodRequest(); break;
        case 17: _t->printDone((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 18: _t->dockStatistics((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->printerReadyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->paymentUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->paymentMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->updateShowthanhtoancungdonhang((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->cardPayment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->errorMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 25: _t->updateTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->onPayZalo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 27: _t->loginRequest(); break;
        case 28: _t->login((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 29: _t->baocaoRequest(); break;
        case 30: _t->idleTimeout(); break;
        case 31: _t->dominosData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 32: _t->dominosSetProdName((*reinterpret_cast< const QSet<QString>(*)>(_a[1]))); break;
        case 33: _t->removeItemPaymentView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->onCancelDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 35: _t->onCancelError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 36: _t->onRejectDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 37: _t->onRejectError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 38: _t->onPayZaloDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 39: _t->onPayZaloError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 40: _t->onNotify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->onMifareFound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->onCenterServiceFound((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 43: _t->onFoodsDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 44: _t->onFoodsError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 45: _t->onUpdatedFoodsData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->onCheckUpdateFoodsData((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 47: _t->onCheckUpdateFoodsDataError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 48: _t->onLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 49: _t->onLoginDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 50: _t->onLoginError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 51: _t->onBaocao(); break;
        case 52: _t->onBaocaoDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 53: _t->onBaocaoError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 54: _t->doPayCard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: { bool _r = _t->doGetPmsid((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->onPmsidDoneZalo((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 57: _t->onPmsidDoneCash((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 58: _t->onPmsidError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 59: _t->doPayZalo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 60: _t->doPayCash((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 61: _t->onPayCashDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 62: _t->onPayCashError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 63: _t->foodsRequest(); break;
        case 64: _t->checkUpdateFoodData(); break;
        case 65: _t->timerStartUpdate(); break;
        case 66: _t->timerDoUpdate(); break;
        case 67: _t->timerReboot(); break;
        case 68: _t->timerSystemIdle(); break;
        case 69: _t->onStoreProducts((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 70: _t->onStoreInformation((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 71: { bool _r = _t->isDebugmode();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 72: { bool _r = _t->isRaspberry();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 73: { bool _r = _t->isCashAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->isCardAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 75: _t->appQuit(); break;
        case 76: { bool _r = _t->searchFilter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 77: _t->searchFood((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 78: { QString _r = _t->viet2latin((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 79: { QString _r = _t->pay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonArray(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 80: _t->insertItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< long(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8]))); break;
        case 81: { QString _r = _t->formatMoney((*reinterpret_cast< long long(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 82: { long long _r = _t->getMoneyValue((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = std::move(_r); }  break;
        case 83: { QString _r = _t->moneyMoney((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 84: _t->updateTotalMoney((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 85: _t->updateCardWaitingPay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 86: _t->printBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 87: _t->cancelBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 88: _t->stopDevice(); break;
        case 89: { QString _r = _t->getPrinter();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 90: _t->setPrinter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 91: { QString _r = _t->getPayment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 92: { QString _r = _t->getUrlService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 93: { QString _r = _t->getTransferProtocol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 94: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 95: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 96: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 97: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 98: _t->setPaymentMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: { int _r = _t->getPaymentMethod();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 100: _t->setPaymentMask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 101: { int _r = _t->getPaymentMask();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 102: { QString _r = _t->getDockServer();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 103: _t->setDockServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 104: _t->scanDock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 105: _t->scanDock(); break;
        case 106: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 107: { bool _r = _t->connectToDock((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 108: _t->disconnectFromDock(); break;
        case 109: _t->testReaderDevice((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 110: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 111: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 112: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 113: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 114: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 115: _t->wifiStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 116: _t->wifiStatus(); break;
        case 117: _t->testPing((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 118: _t->restartDock(); break;
        case 119: _t->restartPi(); break;
        case 120: _t->haltPi(); break;
        case 121: _t->checkPrinterStatus(); break;
        case 122: _t->printTest((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 123: { QString _r = _t->getLocalIp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 124: { int _r = _t->getAppIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 125: { QString _r = _t->getAppName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 126: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 127: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 128: { QString _r = _t->getAppTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 129: { QString _r = _t->getTitleEng();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 130: _t->setAppTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 131: { int _r = _t->getMachineIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 132: { QString _r = _t->getAppMachine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 133: { int _r = _t->getRechargeNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 134: _t->setRechargeNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 135: { int _r = _t->getFoodRefreshTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 136: _t->setFoodRefreshTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 137: { int _r = _t->getBillAlertTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 138: _t->setBillAlertTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 139: { bool _r = _t->getShowThanhtoancungdonhang();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 140: _t->setShowThanhtoancungdonhang((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 141: { QString _r = _t->getConfigQrcodeRatio();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 142: _t->setConfigQrcodeRatio((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 143: { int _r = _t->getConfigFoodItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 144: _t->setConfigFoodItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 145: { int _r = _t->getConfigBillItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 146: _t->setConfigBillItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 147: { int _r = _t->getConfigSobanin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 148: _t->setConfigSobanin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 149: { QString _r = _t->getConfigTenbanin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 150: _t->setConfigTenbanin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 151: { QString _r = _t->getConfigBillPreinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 152: _t->setConfigBillPreinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 153: { QString _r = _t->getConfigBillPostinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 154: _t->setConfigBillPostinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 155: { QString _r = _t->getConfigDockversion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 156: _t->setConfigDockversion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 157: { QString _r = _t->getConfigPrintersize();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 158: _t->setConfigPrintersize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 159: { bool _r = _t->getUserEnableConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 160: _t->setUserEnableConfig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 161: { int _r = _t->getConfigRebootDatePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 162: _t->setConfigRebootDatePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 163: { int _r = _t->getConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 164: { int _r = _t->getConfigRebootTimePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 165: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 166: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 167: { QString _r = _t->getRestartTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 168: { QString _r = _t->getCurrentTime((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 169: { QString _r = _t->getConfigUsername();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 170: { QString _r = _t->getConfigUserpwd();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 171: { bool _r = _t->getConfigSearchadvance();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 172: _t->setConfigSearchadvance((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 173: { bool _r = _t->getConfigShowBaocaoDate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 174: _t->setConfigShowBaocaoDate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 175: { QString _r = _t->getConfigCenterService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 176: _t->setConfigCenterService((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 177: { int _r = _t->getConfigIdletime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 178: _t->setConfigIdletime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 179: _t->setIdCoupon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 180: { QString _r = _t->getIdCoupon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 181: _t->setIdCouponPercent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 182: { QString _r = _t->getIdCouponPercent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 183: _t->saveConfig(); break;
        case 184: _t->sendCancelBillUI(); break;
        case 185: { QString _r = _t->getBaocaoCurrentTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 186: _t->inBaocao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 187: _t->userLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 188: _t->uiFoodupdateStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 189: { QString _r = _t->getAccount();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 190: { QString _r = _t->getDiskPrepare();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 191: { QString _r = _t->getDiskReserve();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 192: _t->idleClearup(); break;
        case 193: _t->idleReset(); break;
        case 194: { QString _r = _t->getProductCode((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 195: { long long _r = _t->getPriceCoupon((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = std::move(_r); }  break;
        case 196: _t->removeItemInPaymentView((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSet<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodReset)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodSearching)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & , int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paySucc)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::payError)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::notifySucc)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & , const QString & , const QString & , long , long long , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::addItem)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cancelBillItem)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cancellBillCloseQRDialog)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateAmount)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::scanDockDone)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dockConnectionChange)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::pingDone)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::wifiStatusDone)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::showMessage)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cloudConnectionChange)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::notifyFoodRequest)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::printDone)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dockStatistics)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::printerReadyChanged)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paymentUpdate)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paymentMask)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateShowthanhtoancungdonhang)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cardPayment)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::errorMessage)) {
                *result = 24;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateTitle)) {
                *result = 25;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::onPayZalo)) {
                *result = 26;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::loginRequest)) {
                *result = 27;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::login)) {
                *result = 28;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::baocaoRequest)) {
                *result = 29;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::idleTimeout)) {
                *result = 30;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dominosData)) {
                *result = 31;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QSet<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dominosSetProdName)) {
                *result = 32;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::removeItemPaymentView)) {
                *result = 33;
                return;
            }
        }
    }
}

const QMetaObject MainController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainController.data,
      qt_meta_data_MainController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainController.stringdata0))
        return static_cast<void*>(const_cast< MainController*>(this));
    return QObject::qt_metacast(_clname);
}

int MainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 197)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 197;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 197)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 197;
    }
    return _id;
}

// SIGNAL 0
void MainController::foodReset()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainController::foodUpdate(const QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainController::foodSearching(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainController::paySucc(const QString & _t1, const QString & _t2, int _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainController::payError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainController::notifySucc(int _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainController::addItem(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, long _t5, long long _t6, const QString & _t7, const QString & _t8, const QString & _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainController::cancelBillItem()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainController::cancellBillCloseQRDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainController::updateAmount(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainController::scanDockDone(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainController::dockConnectionChange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainController::pingDone(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainController::wifiStatusDone(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainController::showMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainController::cloudConnectionChange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainController::notifyFoodRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MainController::printDone(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainController::dockStatistics(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainController::printerReadyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainController::paymentUpdate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainController::paymentMask(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainController::updateShowthanhtoancungdonhang(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainController::cardPayment(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainController::errorMessage(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void MainController::updateTitle(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void MainController::onPayZalo(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void MainController::loginRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void MainController::login(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void MainController::baocaoRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void MainController::idleTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void MainController::dominosData(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void MainController::dominosSetProdName(const QSet<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void MainController::removeItemPaymentView(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
