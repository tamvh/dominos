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
    QByteArrayData data[303];
    char stringdata0[3851];
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
QT_MOC_LITERAL(21, 180, 4), // "type"
QT_MOC_LITERAL(22, 185, 9), // "code_name"
QT_MOC_LITERAL(23, 195, 4), // "name"
QT_MOC_LITERAL(24, 200, 4), // "size"
QT_MOC_LITERAL(25, 205, 6), // "debanh"
QT_MOC_LITERAL(26, 212, 6), // "phomai"
QT_MOC_LITERAL(27, 219, 8), // "quantity"
QT_MOC_LITERAL(28, 228, 5), // "price"
QT_MOC_LITERAL(29, 234, 6), // "amount"
QT_MOC_LITERAL(30, 241, 8), // "oriprice"
QT_MOC_LITERAL(31, 250, 8), // "promtype"
QT_MOC_LITERAL(32, 259, 14), // "cancelBillItem"
QT_MOC_LITERAL(33, 274, 24), // "cancellBillCloseQRDialog"
QT_MOC_LITERAL(34, 299, 12), // "updateAmount"
QT_MOC_LITERAL(35, 312, 12), // "scanDockDone"
QT_MOC_LITERAL(36, 325, 8), // "listDock"
QT_MOC_LITERAL(37, 334, 20), // "dockConnectionChange"
QT_MOC_LITERAL(38, 355, 9), // "connected"
QT_MOC_LITERAL(39, 365, 8), // "pingDone"
QT_MOC_LITERAL(40, 374, 4), // "data"
QT_MOC_LITERAL(41, 379, 14), // "wifiStatusDone"
QT_MOC_LITERAL(42, 394, 11), // "showMessage"
QT_MOC_LITERAL(43, 406, 21), // "cloudConnectionChange"
QT_MOC_LITERAL(44, 428, 17), // "notifyFoodRequest"
QT_MOC_LITERAL(45, 446, 9), // "printDone"
QT_MOC_LITERAL(46, 456, 14), // "dockStatistics"
QT_MOC_LITERAL(47, 471, 4), // "stat"
QT_MOC_LITERAL(48, 476, 19), // "printerReadyChanged"
QT_MOC_LITERAL(49, 496, 5), // "ready"
QT_MOC_LITERAL(50, 502, 13), // "paymentUpdate"
QT_MOC_LITERAL(51, 516, 7), // "methods"
QT_MOC_LITERAL(52, 524, 11), // "paymentMask"
QT_MOC_LITERAL(53, 536, 30), // "updateShowthanhtoancungdonhang"
QT_MOC_LITERAL(54, 567, 6), // "isShow"
QT_MOC_LITERAL(55, 574, 11), // "cardPayment"
QT_MOC_LITERAL(56, 586, 6), // "cardId"
QT_MOC_LITERAL(57, 593, 12), // "errorMessage"
QT_MOC_LITERAL(58, 606, 3), // "err"
QT_MOC_LITERAL(59, 610, 11), // "updateTitle"
QT_MOC_LITERAL(60, 622, 5), // "title"
QT_MOC_LITERAL(61, 628, 9), // "onPayZalo"
QT_MOC_LITERAL(62, 638, 5), // "sesid"
QT_MOC_LITERAL(63, 644, 4), // "biid"
QT_MOC_LITERAL(64, 649, 12), // "loginRequest"
QT_MOC_LITERAL(65, 662, 5), // "login"
QT_MOC_LITERAL(66, 668, 13), // "baocaoRequest"
QT_MOC_LITERAL(67, 682, 11), // "idleTimeout"
QT_MOC_LITERAL(68, 694, 11), // "dominosData"
QT_MOC_LITERAL(69, 706, 18), // "dominosSetProdName"
QT_MOC_LITERAL(70, 725, 13), // "QSet<QString>"
QT_MOC_LITERAL(71, 739, 21), // "removeItemPaymentView"
QT_MOC_LITERAL(72, 761, 3), // "row"
QT_MOC_LITERAL(73, 765, 9), // "prod_type"
QT_MOC_LITERAL(74, 775, 9), // "size_banh"
QT_MOC_LITERAL(75, 785, 7), // "de_banh"
QT_MOC_LITERAL(76, 793, 12), // "onCancelDone"
QT_MOC_LITERAL(77, 806, 13), // "onCancelError"
QT_MOC_LITERAL(78, 820, 12), // "onRejectDone"
QT_MOC_LITERAL(79, 833, 13), // "onRejectError"
QT_MOC_LITERAL(80, 847, 13), // "onPayZaloDone"
QT_MOC_LITERAL(81, 861, 14), // "onPayZaloError"
QT_MOC_LITERAL(82, 876, 5), // "error"
QT_MOC_LITERAL(83, 882, 8), // "onNotify"
QT_MOC_LITERAL(84, 891, 7), // "message"
QT_MOC_LITERAL(85, 899, 13), // "onMifareFound"
QT_MOC_LITERAL(86, 913, 2), // "id"
QT_MOC_LITERAL(87, 916, 20), // "onCenterServiceFound"
QT_MOC_LITERAL(88, 937, 2), // "ip"
QT_MOC_LITERAL(89, 940, 4), // "port"
QT_MOC_LITERAL(90, 945, 11), // "onFoodsDone"
QT_MOC_LITERAL(91, 957, 12), // "onFoodsError"
QT_MOC_LITERAL(92, 970, 18), // "onUpdatedFoodsData"
QT_MOC_LITERAL(93, 989, 22), // "onCheckUpdateFoodsData"
QT_MOC_LITERAL(94, 1012, 27), // "onCheckUpdateFoodsDataError"
QT_MOC_LITERAL(95, 1040, 7), // "onLogin"
QT_MOC_LITERAL(96, 1048, 5), // "uname"
QT_MOC_LITERAL(97, 1054, 3), // "pwd"
QT_MOC_LITERAL(98, 1058, 8), // "isBaocao"
QT_MOC_LITERAL(99, 1067, 11), // "onLoginDone"
QT_MOC_LITERAL(100, 1079, 12), // "onLoginError"
QT_MOC_LITERAL(101, 1092, 8), // "onBaocao"
QT_MOC_LITERAL(102, 1101, 12), // "onBaocaoDone"
QT_MOC_LITERAL(103, 1114, 13), // "onBaocaoError"
QT_MOC_LITERAL(104, 1128, 9), // "doPayCard"
QT_MOC_LITERAL(105, 1138, 10), // "doGetPmsid"
QT_MOC_LITERAL(106, 1149, 12), // "merchantCode"
QT_MOC_LITERAL(107, 1162, 5), // "devId"
QT_MOC_LITERAL(108, 1168, 4), // "biId"
QT_MOC_LITERAL(109, 1173, 9), // "payMethod"
QT_MOC_LITERAL(110, 1183, 15), // "onPmsidDoneZalo"
QT_MOC_LITERAL(111, 1199, 15), // "onPmsidDoneCash"
QT_MOC_LITERAL(112, 1215, 12), // "onPmsidError"
QT_MOC_LITERAL(113, 1228, 9), // "doPayZalo"
QT_MOC_LITERAL(114, 1238, 5), // "sesId"
QT_MOC_LITERAL(115, 1244, 9), // "doPayCash"
QT_MOC_LITERAL(116, 1254, 13), // "onPayCashDone"
QT_MOC_LITERAL(117, 1268, 14), // "onPayCashError"
QT_MOC_LITERAL(118, 1283, 12), // "foodsRequest"
QT_MOC_LITERAL(119, 1296, 19), // "checkUpdateFoodData"
QT_MOC_LITERAL(120, 1316, 16), // "timerStartUpdate"
QT_MOC_LITERAL(121, 1333, 13), // "timerDoUpdate"
QT_MOC_LITERAL(122, 1347, 11), // "timerReboot"
QT_MOC_LITERAL(123, 1359, 15), // "timerSystemIdle"
QT_MOC_LITERAL(124, 1375, 15), // "onStoreProducts"
QT_MOC_LITERAL(125, 1391, 13), // "storeProducts"
QT_MOC_LITERAL(126, 1405, 18), // "onStoreInformation"
QT_MOC_LITERAL(127, 1424, 16), // "storeInformation"
QT_MOC_LITERAL(128, 1441, 15), // "eventPlaceOrder"
QT_MOC_LITERAL(129, 1457, 6), // "result"
QT_MOC_LITERAL(130, 1464, 18), // "eventPlaceOrderErr"
QT_MOC_LITERAL(131, 1483, 11), // "isDebugmode"
QT_MOC_LITERAL(132, 1495, 11), // "isRaspberry"
QT_MOC_LITERAL(133, 1507, 13), // "isCashAllowed"
QT_MOC_LITERAL(134, 1521, 13), // "isCardAllowed"
QT_MOC_LITERAL(135, 1535, 7), // "appQuit"
QT_MOC_LITERAL(136, 1543, 12), // "searchFilter"
QT_MOC_LITERAL(137, 1556, 8), // "foodname"
QT_MOC_LITERAL(138, 1565, 10), // "searchFood"
QT_MOC_LITERAL(139, 1576, 10), // "viet2latin"
QT_MOC_LITERAL(140, 1587, 3), // "pay"
QT_MOC_LITERAL(141, 1591, 13), // "customer_name"
QT_MOC_LITERAL(142, 1605, 17), // "customer_hinhthuc"
QT_MOC_LITERAL(143, 1623, 5), // "foods"
QT_MOC_LITERAL(144, 1629, 10), // "insertItem"
QT_MOC_LITERAL(145, 1640, 11), // "formatMoney"
QT_MOC_LITERAL(146, 1652, 10), // "moneyValue"
QT_MOC_LITERAL(147, 1663, 13), // "getMoneyValue"
QT_MOC_LITERAL(148, 1677, 11), // "moneyString"
QT_MOC_LITERAL(149, 1689, 10), // "moneyMoney"
QT_MOC_LITERAL(150, 1700, 5), // "money"
QT_MOC_LITERAL(151, 1706, 16), // "updateTotalMoney"
QT_MOC_LITERAL(152, 1723, 20), // "updateCardWaitingPay"
QT_MOC_LITERAL(153, 1744, 7), // "waiting"
QT_MOC_LITERAL(154, 1752, 9), // "printBill"
QT_MOC_LITERAL(155, 1762, 6), // "ivcode"
QT_MOC_LITERAL(156, 1769, 9), // "printData"
QT_MOC_LITERAL(157, 1779, 10), // "cancelBill"
QT_MOC_LITERAL(158, 1790, 4), // "foId"
QT_MOC_LITERAL(159, 1795, 5), // "total"
QT_MOC_LITERAL(160, 1801, 10), // "stopDevice"
QT_MOC_LITERAL(161, 1812, 10), // "getPrinter"
QT_MOC_LITERAL(162, 1823, 10), // "setPrinter"
QT_MOC_LITERAL(163, 1834, 7), // "prnName"
QT_MOC_LITERAL(164, 1842, 10), // "getPayment"
QT_MOC_LITERAL(165, 1853, 18), // "getDominoServerUrl"
QT_MOC_LITERAL(166, 1872, 13), // "getUrlService"
QT_MOC_LITERAL(167, 1886, 19), // "getTransferProtocol"
QT_MOC_LITERAL(168, 1906, 19), // "setTransferProtocol"
QT_MOC_LITERAL(169, 1926, 8), // "transpro"
QT_MOC_LITERAL(170, 1935, 10), // "initSocket"
QT_MOC_LITERAL(171, 1946, 10), // "setPayment"
QT_MOC_LITERAL(172, 1957, 11), // "paymentName"
QT_MOC_LITERAL(173, 1969, 18), // "setDominoServerUrl"
QT_MOC_LITERAL(174, 1988, 3), // "url"
QT_MOC_LITERAL(175, 1992, 16), // "setPaymentMethod"
QT_MOC_LITERAL(176, 2009, 13), // "paymentMethod"
QT_MOC_LITERAL(177, 2023, 16), // "getPaymentMethod"
QT_MOC_LITERAL(178, 2040, 14), // "setPaymentMask"
QT_MOC_LITERAL(179, 2055, 7), // "payment"
QT_MOC_LITERAL(180, 2063, 5), // "onoff"
QT_MOC_LITERAL(181, 2069, 14), // "getPaymentMask"
QT_MOC_LITERAL(182, 2084, 13), // "getDockServer"
QT_MOC_LITERAL(183, 2098, 13), // "setDockServer"
QT_MOC_LITERAL(184, 2112, 10), // "dockServer"
QT_MOC_LITERAL(185, 2123, 8), // "scanDock"
QT_MOC_LITERAL(186, 2132, 6), // "doAuto"
QT_MOC_LITERAL(187, 2139, 11), // "isConnected"
QT_MOC_LITERAL(188, 2151, 13), // "connectToDock"
QT_MOC_LITERAL(189, 2165, 8), // "serverIp"
QT_MOC_LITERAL(190, 2174, 18), // "disconnectFromDock"
QT_MOC_LITERAL(191, 2193, 16), // "testReaderDevice"
QT_MOC_LITERAL(192, 2210, 3), // "run"
QT_MOC_LITERAL(193, 2214, 10), // "updateWifi"
QT_MOC_LITERAL(194, 2225, 4), // "ssid"
QT_MOC_LITERAL(195, 2230, 3), // "key"
QT_MOC_LITERAL(196, 2234, 7), // "encrypt"
QT_MOC_LITERAL(197, 2242, 12), // "updateWifiPi"
QT_MOC_LITERAL(198, 2255, 9), // "interface"
QT_MOC_LITERAL(199, 2265, 9), // "scan_ssid"
QT_MOC_LITERAL(200, 2275, 10), // "wifiStatus"
QT_MOC_LITERAL(201, 2286, 8), // "testPing"
QT_MOC_LITERAL(202, 2295, 4), // "host"
QT_MOC_LITERAL(203, 2300, 11), // "restartDock"
QT_MOC_LITERAL(204, 2312, 9), // "restartPi"
QT_MOC_LITERAL(205, 2322, 6), // "haltPi"
QT_MOC_LITERAL(206, 2329, 18), // "checkPrinterStatus"
QT_MOC_LITERAL(207, 2348, 9), // "printTest"
QT_MOC_LITERAL(208, 2358, 10), // "getLocalIp"
QT_MOC_LITERAL(209, 2369, 11), // "getAppIndex"
QT_MOC_LITERAL(210, 2381, 10), // "getAppName"
QT_MOC_LITERAL(211, 2392, 10), // "setAppName"
QT_MOC_LITERAL(212, 2403, 7), // "appName"
QT_MOC_LITERAL(213, 2411, 11), // "getAppTitle"
QT_MOC_LITERAL(214, 2423, 11), // "getTitleEng"
QT_MOC_LITERAL(215, 2435, 11), // "setAppTitle"
QT_MOC_LITERAL(216, 2447, 15), // "getMachineIndex"
QT_MOC_LITERAL(217, 2463, 13), // "getAppMachine"
QT_MOC_LITERAL(218, 2477, 14), // "getRechargeNum"
QT_MOC_LITERAL(219, 2492, 14), // "setRechargeNum"
QT_MOC_LITERAL(220, 2507, 5), // "mcNum"
QT_MOC_LITERAL(221, 2513, 19), // "getFoodRefreshTimer"
QT_MOC_LITERAL(222, 2533, 19), // "setFoodRefreshTimer"
QT_MOC_LITERAL(223, 2553, 5), // "timer"
QT_MOC_LITERAL(224, 2559, 17), // "getBillAlertTimer"
QT_MOC_LITERAL(225, 2577, 17), // "setBillAlertTimer"
QT_MOC_LITERAL(226, 2595, 27), // "getShowThanhtoancungdonhang"
QT_MOC_LITERAL(227, 2623, 27), // "setShowThanhtoancungdonhang"
QT_MOC_LITERAL(228, 2651, 20), // "getConfigQrcodeRatio"
QT_MOC_LITERAL(229, 2672, 20), // "setConfigQrcodeRatio"
QT_MOC_LITERAL(230, 2693, 5), // "ratio"
QT_MOC_LITERAL(231, 2699, 25), // "getConfigFoodItemFontsize"
QT_MOC_LITERAL(232, 2725, 25), // "setConfigFoodItemFontsize"
QT_MOC_LITERAL(233, 2751, 7), // "fntsize"
QT_MOC_LITERAL(234, 2759, 25), // "getConfigBillItemFontsize"
QT_MOC_LITERAL(235, 2785, 25), // "setConfigBillItemFontsize"
QT_MOC_LITERAL(236, 2811, 16), // "getConfigSobanin"
QT_MOC_LITERAL(237, 2828, 16), // "setConfigSobanin"
QT_MOC_LITERAL(238, 2845, 3), // "num"
QT_MOC_LITERAL(239, 2849, 17), // "getConfigTenbanin"
QT_MOC_LITERAL(240, 2867, 17), // "setConfigTenbanin"
QT_MOC_LITERAL(241, 2885, 19), // "getConfigBillPreinf"
QT_MOC_LITERAL(242, 2905, 19), // "setConfigBillPreinf"
QT_MOC_LITERAL(243, 2925, 4), // "info"
QT_MOC_LITERAL(244, 2930, 20), // "getConfigBillPostinf"
QT_MOC_LITERAL(245, 2951, 20), // "setConfigBillPostinf"
QT_MOC_LITERAL(246, 2972, 20), // "getConfigDockversion"
QT_MOC_LITERAL(247, 2993, 20), // "setConfigDockversion"
QT_MOC_LITERAL(248, 3014, 7), // "version"
QT_MOC_LITERAL(249, 3022, 20), // "getConfigPrintersize"
QT_MOC_LITERAL(250, 3043, 20), // "setConfigPrintersize"
QT_MOC_LITERAL(251, 3064, 8), // "pagesize"
QT_MOC_LITERAL(252, 3073, 19), // "getUserEnableConfig"
QT_MOC_LITERAL(253, 3093, 19), // "setUserEnableConfig"
QT_MOC_LITERAL(254, 3113, 10), // "enableconf"
QT_MOC_LITERAL(255, 3124, 21), // "getConfigRebootDatePi"
QT_MOC_LITERAL(256, 3146, 21), // "setConfigRebootDatePi"
QT_MOC_LITERAL(257, 3168, 9), // "dayofweek"
QT_MOC_LITERAL(258, 3178, 2), // "on"
QT_MOC_LITERAL(259, 3181, 21), // "getConfigRebootTimePi"
QT_MOC_LITERAL(260, 3203, 21), // "setConfigRebootTimePi"
QT_MOC_LITERAL(261, 3225, 5), // "value"
QT_MOC_LITERAL(262, 3231, 14), // "getRestartTime"
QT_MOC_LITERAL(263, 3246, 14), // "getCurrentTime"
QT_MOC_LITERAL(264, 3261, 17), // "getConfigUsername"
QT_MOC_LITERAL(265, 3279, 16), // "getConfigUserpwd"
QT_MOC_LITERAL(266, 3296, 22), // "getConfigSearchadvance"
QT_MOC_LITERAL(267, 3319, 22), // "setConfigSearchadvance"
QT_MOC_LITERAL(268, 3342, 13), // "searchadvance"
QT_MOC_LITERAL(269, 3356, 23), // "getConfigShowBaocaoDate"
QT_MOC_LITERAL(270, 3380, 23), // "setConfigShowBaocaoDate"
QT_MOC_LITERAL(271, 3404, 8), // "showDate"
QT_MOC_LITERAL(272, 3413, 22), // "getConfigCenterService"
QT_MOC_LITERAL(273, 3436, 22), // "setConfigCenterService"
QT_MOC_LITERAL(274, 3459, 15), // "centerServiceIp"
QT_MOC_LITERAL(275, 3475, 17), // "getConfigIdletime"
QT_MOC_LITERAL(276, 3493, 17), // "setConfigIdletime"
QT_MOC_LITERAL(277, 3511, 11), // "setIdCoupon"
QT_MOC_LITERAL(278, 3523, 11), // "getIdCoupon"
QT_MOC_LITERAL(279, 3535, 18), // "setIdCouponPercent"
QT_MOC_LITERAL(280, 3554, 7), // "percent"
QT_MOC_LITERAL(281, 3562, 18), // "getIdCouponPercent"
QT_MOC_LITERAL(282, 3581, 10), // "saveConfig"
QT_MOC_LITERAL(283, 3592, 16), // "sendCancelBillUI"
QT_MOC_LITERAL(284, 3609, 20), // "getBaocaoCurrentTime"
QT_MOC_LITERAL(285, 3630, 8), // "inBaocao"
QT_MOC_LITERAL(286, 3639, 4), // "date"
QT_MOC_LITERAL(287, 3644, 6), // "bcType"
QT_MOC_LITERAL(288, 3651, 9), // "userLogin"
QT_MOC_LITERAL(289, 3661, 18), // "uiFoodupdateStatus"
QT_MOC_LITERAL(290, 3680, 6), // "uiType"
QT_MOC_LITERAL(291, 3687, 10), // "getAccount"
QT_MOC_LITERAL(292, 3698, 14), // "getDiskPrepare"
QT_MOC_LITERAL(293, 3713, 14), // "getDiskReserve"
QT_MOC_LITERAL(294, 3728, 11), // "idleClearup"
QT_MOC_LITERAL(295, 3740, 9), // "idleReset"
QT_MOC_LITERAL(296, 3750, 14), // "getProductCode"
QT_MOC_LITERAL(297, 3765, 8), // "pro_name"
QT_MOC_LITERAL(298, 3774, 9), // "prod_size"
QT_MOC_LITERAL(299, 3784, 16), // "prod_plavor_code"
QT_MOC_LITERAL(300, 3801, 14), // "getPriceCoupon"
QT_MOC_LITERAL(301, 3816, 10), // "pizza_size"
QT_MOC_LITERAL(302, 3827, 23) // "removeItemInPaymentView"

    },
    "MainController\0foodReset\0\0foodUpdate\0"
    "menus\0foodSearching\0srchtxt\0paySucc\0"
    "invcecode\0qrcode\0discount\0oripay\0"
    "discpay\0payError\0msg\0notifySucc\0errcode\0"
    "invcetime\0barcode\0balance\0addItem\0"
    "type\0code_name\0name\0size\0debanh\0phomai\0"
    "quantity\0price\0amount\0oriprice\0promtype\0"
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
    "row\0prod_type\0size_banh\0de_banh\0"
    "onCancelDone\0onCancelError\0onRejectDone\0"
    "onRejectError\0onPayZaloDone\0onPayZaloError\0"
    "error\0onNotify\0message\0onMifareFound\0"
    "id\0onCenterServiceFound\0ip\0port\0"
    "onFoodsDone\0onFoodsError\0onUpdatedFoodsData\0"
    "onCheckUpdateFoodsData\0"
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
    "eventPlaceOrder\0result\0eventPlaceOrderErr\0"
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
    "getDominoServerUrl\0getUrlService\0"
    "getTransferProtocol\0setTransferProtocol\0"
    "transpro\0initSocket\0setPayment\0"
    "paymentName\0setDominoServerUrl\0url\0"
    "setPaymentMethod\0paymentMethod\0"
    "getPaymentMethod\0setPaymentMask\0payment\0"
    "onoff\0getPaymentMask\0getDockServer\0"
    "setDockServer\0dockServer\0scanDock\0"
    "doAuto\0isConnected\0connectToDock\0"
    "serverIp\0disconnectFromDock\0"
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
    "setConfigRebootTimePi\0value\0getRestartTime\0"
    "getCurrentTime\0getConfigUsername\0"
    "getConfigUserpwd\0getConfigSearchadvance\0"
    "setConfigSearchadvance\0searchadvance\0"
    "getConfigShowBaocaoDate\0setConfigShowBaocaoDate\0"
    "showDate\0getConfigCenterService\0"
    "setConfigCenterService\0centerServiceIp\0"
    "getConfigIdletime\0setConfigIdletime\0"
    "setIdCoupon\0getIdCoupon\0setIdCouponPercent\0"
    "percent\0getIdCouponPercent\0saveConfig\0"
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
     201,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      34,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0, 1019,    2, 0x06 /* Public */,
       3,    1, 1020,    2, 0x06 /* Public */,
       5,    1, 1023,    2, 0x06 /* Public */,
       7,    5, 1026,    2, 0x06 /* Public */,
      13,    1, 1037,    2, 0x06 /* Public */,
      15,    5, 1040,    2, 0x06 /* Public */,
      20,   11, 1051,    2, 0x06 /* Public */,
      32,    0, 1074,    2, 0x06 /* Public */,
      33,    0, 1075,    2, 0x06 /* Public */,
      34,    1, 1076,    2, 0x06 /* Public */,
      35,    1, 1079,    2, 0x06 /* Public */,
      37,    1, 1082,    2, 0x06 /* Public */,
      39,    1, 1085,    2, 0x06 /* Public */,
      41,    1, 1088,    2, 0x06 /* Public */,
      42,    1, 1091,    2, 0x06 /* Public */,
      43,    1, 1094,    2, 0x06 /* Public */,
      44,    0, 1097,    2, 0x06 /* Public */,
      45,    1, 1098,    2, 0x06 /* Public */,
      46,    1, 1101,    2, 0x06 /* Public */,
      48,    1, 1104,    2, 0x06 /* Public */,
      50,    1, 1107,    2, 0x06 /* Public */,
      52,    1, 1110,    2, 0x06 /* Public */,
      53,    1, 1113,    2, 0x06 /* Public */,
      55,    1, 1116,    2, 0x06 /* Public */,
      57,    2, 1119,    2, 0x06 /* Public */,
      59,    1, 1124,    2, 0x06 /* Public */,
      61,    2, 1127,    2, 0x06 /* Public */,
      64,    0, 1132,    2, 0x06 /* Public */,
      65,    2, 1133,    2, 0x06 /* Public */,
      66,    0, 1138,    2, 0x06 /* Public */,
      67,    0, 1139,    2, 0x06 /* Public */,
      68,    1, 1140,    2, 0x06 /* Public */,
      69,    1, 1143,    2, 0x06 /* Public */,
      71,    5, 1146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      76,    1, 1157,    2, 0x0a /* Public */,
      77,    2, 1160,    2, 0x0a /* Public */,
      78,    1, 1165,    2, 0x0a /* Public */,
      79,    2, 1168,    2, 0x0a /* Public */,
      80,    1, 1173,    2, 0x0a /* Public */,
      81,    2, 1176,    2, 0x0a /* Public */,
      83,    1, 1181,    2, 0x0a /* Public */,
      85,    1, 1184,    2, 0x0a /* Public */,
      87,    2, 1187,    2, 0x0a /* Public */,
      90,    1, 1192,    2, 0x0a /* Public */,
      91,    2, 1195,    2, 0x0a /* Public */,
      92,    1, 1200,    2, 0x0a /* Public */,
      93,    1, 1203,    2, 0x0a /* Public */,
      94,    2, 1206,    2, 0x0a /* Public */,
      95,    3, 1211,    2, 0x0a /* Public */,
      99,    1, 1218,    2, 0x0a /* Public */,
     100,    2, 1221,    2, 0x0a /* Public */,
     101,    0, 1226,    2, 0x0a /* Public */,
     102,    1, 1227,    2, 0x0a /* Public */,
     103,    2, 1230,    2, 0x0a /* Public */,
     104,    1, 1235,    2, 0x0a /* Public */,
     105,    4, 1238,    2, 0x0a /* Public */,
     110,    1, 1247,    2, 0x0a /* Public */,
     111,    1, 1250,    2, 0x0a /* Public */,
     112,    2, 1253,    2, 0x0a /* Public */,
     113,    2, 1258,    2, 0x0a /* Public */,
     115,    2, 1263,    2, 0x0a /* Public */,
     116,    1, 1268,    2, 0x0a /* Public */,
     117,    2, 1271,    2, 0x0a /* Public */,
     118,    0, 1276,    2, 0x0a /* Public */,
     119,    0, 1277,    2, 0x0a /* Public */,
     120,    0, 1278,    2, 0x0a /* Public */,
     121,    0, 1279,    2, 0x0a /* Public */,
     122,    0, 1280,    2, 0x0a /* Public */,
     123,    0, 1281,    2, 0x0a /* Public */,
     124,    1, 1282,    2, 0x0a /* Public */,
     126,    1, 1285,    2, 0x0a /* Public */,
     128,    1, 1288,    2, 0x0a /* Public */,
     130,    1, 1291,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
     131,    0, 1294,    2, 0x02 /* Public */,
     132,    0, 1295,    2, 0x02 /* Public */,
     133,    0, 1296,    2, 0x02 /* Public */,
     134,    0, 1297,    2, 0x02 /* Public */,
     135,    0, 1298,    2, 0x02 /* Public */,
     136,    2, 1299,    2, 0x02 /* Public */,
     138,    1, 1304,    2, 0x02 /* Public */,
     139,    1, 1307,    2, 0x02 /* Public */,
     140,    5, 1310,    2, 0x02 /* Public */,
     144,   10, 1321,    2, 0x02 /* Public */,
     145,    1, 1342,    2, 0x02 /* Public */,
     147,    1, 1345,    2, 0x02 /* Public */,
     149,    1, 1348,    2, 0x02 /* Public */,
     151,    1, 1351,    2, 0x02 /* Public */,
     152,    1, 1354,    2, 0x02 /* Public */,
     154,    2, 1357,    2, 0x02 /* Public */,
     157,    3, 1362,    2, 0x02 /* Public */,
     160,    0, 1369,    2, 0x02 /* Public */,
     161,    0, 1370,    2, 0x02 /* Public */,
     162,    1, 1371,    2, 0x02 /* Public */,
     164,    0, 1374,    2, 0x02 /* Public */,
     165,    0, 1375,    2, 0x02 /* Public */,
     166,    0, 1376,    2, 0x02 /* Public */,
     167,    0, 1377,    2, 0x02 /* Public */,
     168,    2, 1378,    2, 0x02 /* Public */,
     168,    1, 1383,    2, 0x22 /* Public | MethodCloned */,
     171,    2, 1386,    2, 0x02 /* Public */,
     171,    1, 1391,    2, 0x22 /* Public | MethodCloned */,
     173,    1, 1394,    2, 0x02 /* Public */,
     175,    1, 1397,    2, 0x02 /* Public */,
     177,    0, 1400,    2, 0x02 /* Public */,
     178,    2, 1401,    2, 0x02 /* Public */,
     181,    0, 1406,    2, 0x02 /* Public */,
     182,    0, 1407,    2, 0x02 /* Public */,
     183,    1, 1408,    2, 0x02 /* Public */,
     185,    1, 1411,    2, 0x02 /* Public */,
     185,    0, 1414,    2, 0x22 /* Public | MethodCloned */,
     187,    0, 1415,    2, 0x02 /* Public */,
     188,    1, 1416,    2, 0x02 /* Public */,
     190,    0, 1419,    2, 0x02 /* Public */,
     191,    1, 1420,    2, 0x02 /* Public */,
     193,    3, 1423,    2, 0x02 /* Public */,
     193,    2, 1430,    2, 0x22 /* Public | MethodCloned */,
     197,    5, 1435,    2, 0x02 /* Public */,
     197,    4, 1446,    2, 0x22 /* Public | MethodCloned */,
     197,    3, 1455,    2, 0x22 /* Public | MethodCloned */,
     200,    1, 1462,    2, 0x02 /* Public */,
     200,    0, 1465,    2, 0x22 /* Public | MethodCloned */,
     201,    1, 1466,    2, 0x02 /* Public */,
     203,    0, 1469,    2, 0x02 /* Public */,
     204,    0, 1470,    2, 0x02 /* Public */,
     205,    0, 1471,    2, 0x02 /* Public */,
     206,    0, 1472,    2, 0x02 /* Public */,
     207,    1, 1473,    2, 0x02 /* Public */,
     208,    0, 1476,    2, 0x02 /* Public */,
     209,    0, 1477,    2, 0x02 /* Public */,
     210,    0, 1478,    2, 0x02 /* Public */,
     211,    2, 1479,    2, 0x02 /* Public */,
     211,    1, 1484,    2, 0x22 /* Public | MethodCloned */,
     213,    0, 1487,    2, 0x02 /* Public */,
     214,    0, 1488,    2, 0x02 /* Public */,
     215,    1, 1489,    2, 0x02 /* Public */,
     216,    0, 1492,    2, 0x02 /* Public */,
     217,    0, 1493,    2, 0x02 /* Public */,
     218,    0, 1494,    2, 0x02 /* Public */,
     219,    1, 1495,    2, 0x02 /* Public */,
     221,    0, 1498,    2, 0x02 /* Public */,
     222,    1, 1499,    2, 0x02 /* Public */,
     224,    0, 1502,    2, 0x02 /* Public */,
     225,    1, 1503,    2, 0x02 /* Public */,
     226,    0, 1506,    2, 0x02 /* Public */,
     227,    1, 1507,    2, 0x02 /* Public */,
     228,    0, 1510,    2, 0x02 /* Public */,
     229,    1, 1511,    2, 0x02 /* Public */,
     231,    0, 1514,    2, 0x02 /* Public */,
     232,    1, 1515,    2, 0x02 /* Public */,
     234,    0, 1518,    2, 0x02 /* Public */,
     235,    1, 1519,    2, 0x02 /* Public */,
     236,    0, 1522,    2, 0x02 /* Public */,
     237,    1, 1523,    2, 0x02 /* Public */,
     239,    0, 1526,    2, 0x02 /* Public */,
     240,    1, 1527,    2, 0x02 /* Public */,
     241,    0, 1530,    2, 0x02 /* Public */,
     242,    1, 1531,    2, 0x02 /* Public */,
     244,    0, 1534,    2, 0x02 /* Public */,
     245,    1, 1535,    2, 0x02 /* Public */,
     246,    0, 1538,    2, 0x02 /* Public */,
     247,    1, 1539,    2, 0x02 /* Public */,
     249,    0, 1542,    2, 0x02 /* Public */,
     250,    1, 1543,    2, 0x02 /* Public */,
     252,    0, 1546,    2, 0x02 /* Public */,
     253,    1, 1547,    2, 0x02 /* Public */,
     255,    0, 1550,    2, 0x02 /* Public */,
     256,    2, 1551,    2, 0x02 /* Public */,
     259,    1, 1556,    2, 0x02 /* Public */,
     259,    0, 1559,    2, 0x22 /* Public | MethodCloned */,
     260,    2, 1560,    2, 0x02 /* Public */,
     260,    1, 1565,    2, 0x22 /* Public | MethodCloned */,
     262,    0, 1568,    2, 0x02 /* Public */,
     263,    1, 1569,    2, 0x02 /* Public */,
     264,    0, 1572,    2, 0x02 /* Public */,
     265,    0, 1573,    2, 0x02 /* Public */,
     266,    0, 1574,    2, 0x02 /* Public */,
     267,    1, 1575,    2, 0x02 /* Public */,
     269,    0, 1578,    2, 0x02 /* Public */,
     270,    1, 1579,    2, 0x02 /* Public */,
     272,    0, 1582,    2, 0x02 /* Public */,
     273,    1, 1583,    2, 0x02 /* Public */,
     275,    0, 1586,    2, 0x02 /* Public */,
     276,    1, 1587,    2, 0x02 /* Public */,
     277,    1, 1590,    2, 0x02 /* Public */,
     278,    0, 1593,    2, 0x02 /* Public */,
     279,    1, 1594,    2, 0x02 /* Public */,
     281,    0, 1597,    2, 0x02 /* Public */,
     282,    0, 1598,    2, 0x02 /* Public */,
     283,    0, 1599,    2, 0x02 /* Public */,
     284,    0, 1600,    2, 0x02 /* Public */,
     285,    2, 1601,    2, 0x02 /* Public */,
     288,    2, 1606,    2, 0x02 /* Public */,
     289,    1, 1611,    2, 0x02 /* Public */,
     291,    0, 1614,    2, 0x02 /* Public */,
     292,    0, 1615,    2, 0x02 /* Public */,
     293,    0, 1616,    2, 0x02 /* Public */,
     294,    0, 1617,    2, 0x02 /* Public */,
     295,    0, 1618,    2, 0x02 /* Public */,
     296,    3, 1619,    2, 0x02 /* Public */,
     300,    2, 1626,    2, 0x02 /* Public */,
     302,    5, 1631,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,    8,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QStringList,   36,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   16,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Bool,   54,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   58,   14,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   62,   63,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   58,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   40,
    QMetaType::Void, 0x80000000 | 70,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   72,   73,   74,   75,   26,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   14,
    QMetaType::Void, QMetaType::QString,   84,
    QMetaType::Void, QMetaType::QString,   86,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   88,   89,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   84,
    QMetaType::Void, QMetaType::QString,   84,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   84,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   96,   97,   98,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   14,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,  106,  107,  108,  109,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  114,  108,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  114,  108,
    QMetaType::Void, QMetaType::QVariant,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   82,   84,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,  125,
    QMetaType::Void, QMetaType::QJsonObject,  127,
    QMetaType::Void, QMetaType::QJsonObject,  129,
    QMetaType::Void, QMetaType::QString,   58,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  137,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,   23,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QJsonArray, QMetaType::Int,  141,  142,   29,  143,  109,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,   26,   28,   27,   30,   31,
    QMetaType::QString, QMetaType::LongLong,  146,
    QMetaType::LongLong, QMetaType::QString,  148,
    QMetaType::QString, QMetaType::QString,  150,
    QMetaType::Void, QMetaType::LongLong,  146,
    QMetaType::Void, QMetaType::Bool,  153,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  155,  156,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  158,    8,  159,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  163,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  169,  170,
    QMetaType::Void, QMetaType::QString,  169,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  172,  170,
    QMetaType::Void, QMetaType::QString,  172,
    QMetaType::Void, QMetaType::QString,  174,
    QMetaType::Void, QMetaType::Int,  176,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  179,  180,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  184,
    QMetaType::Void, QMetaType::Bool,  186,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,  189,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  192,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  194,  195,  196,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  194,  195,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  198,  194,  195,  196,  199,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  198,  194,  195,  196,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  198,  194,  195,
    QMetaType::Void, QMetaType::QString,  198,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  202,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,  143,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  212,  170,
    QMetaType::Void, QMetaType::QString,  212,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  220,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  223,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  223,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   54,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  230,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  233,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  233,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  238,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  243,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  243,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  248,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  251,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  254,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  257,  258,
    QMetaType::Int, QMetaType::Int,   21,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  261,   21,
    QMetaType::Void, QMetaType::Int,  261,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Bool,  258,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  268,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  271,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  274,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  223,
    QMetaType::Void, QMetaType::QString,   86,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  280,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  286,  287,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   96,   97,
    QMetaType::Void, QMetaType::Int,  290,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  297,  298,  299,
    QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,   28,  301,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   72,   73,   74,   75,   26,

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
        case 6: _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< long(*)>(_a[7])),(*reinterpret_cast< long long(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11]))); break;
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
        case 33: _t->removeItemPaymentView((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
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
        case 71: _t->eventPlaceOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 72: _t->eventPlaceOrderErr((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 73: { bool _r = _t->isDebugmode();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->isRaspberry();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 75: { bool _r = _t->isCashAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 76: { bool _r = _t->isCardAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 77: _t->appQuit(); break;
        case 78: { bool _r = _t->searchFilter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 79: _t->searchFood((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 80: { QString _r = _t->viet2latin((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 81: { QString _r = _t->pay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonArray(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 82: _t->insertItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< long(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10]))); break;
        case 83: { QString _r = _t->formatMoney((*reinterpret_cast< long long(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 84: { long long _r = _t->getMoneyValue((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = std::move(_r); }  break;
        case 85: { QString _r = _t->moneyMoney((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 86: _t->updateTotalMoney((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 87: _t->updateCardWaitingPay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 88: _t->printBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 89: _t->cancelBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 90: _t->stopDevice(); break;
        case 91: { QString _r = _t->getPrinter();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 92: _t->setPrinter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 93: { QString _r = _t->getPayment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 94: { QString _r = _t->getDominoServerUrl();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 95: { QString _r = _t->getUrlService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 96: { QString _r = _t->getTransferProtocol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 97: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 98: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 99: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 100: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 101: _t->setDominoServerUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 102: _t->setPaymentMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: { int _r = _t->getPaymentMethod();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 104: _t->setPaymentMask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 105: { int _r = _t->getPaymentMask();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 106: { QString _r = _t->getDockServer();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 107: _t->setDockServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 108: _t->scanDock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 109: _t->scanDock(); break;
        case 110: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 111: { bool _r = _t->connectToDock((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 112: _t->disconnectFromDock(); break;
        case 113: _t->testReaderDevice((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 114: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 115: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 116: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 117: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 118: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 119: _t->wifiStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 120: _t->wifiStatus(); break;
        case 121: _t->testPing((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 122: _t->restartDock(); break;
        case 123: _t->restartPi(); break;
        case 124: _t->haltPi(); break;
        case 125: _t->checkPrinterStatus(); break;
        case 126: _t->printTest((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 127: { QString _r = _t->getLocalIp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 128: { int _r = _t->getAppIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 129: { QString _r = _t->getAppName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 130: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 131: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 132: { QString _r = _t->getAppTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 133: { QString _r = _t->getTitleEng();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 134: _t->setAppTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 135: { int _r = _t->getMachineIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 136: { QString _r = _t->getAppMachine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 137: { int _r = _t->getRechargeNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 138: _t->setRechargeNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 139: { int _r = _t->getFoodRefreshTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 140: _t->setFoodRefreshTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 141: { int _r = _t->getBillAlertTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 142: _t->setBillAlertTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 143: { bool _r = _t->getShowThanhtoancungdonhang();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 144: _t->setShowThanhtoancungdonhang((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 145: { QString _r = _t->getConfigQrcodeRatio();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 146: _t->setConfigQrcodeRatio((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 147: { int _r = _t->getConfigFoodItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 148: _t->setConfigFoodItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 149: { int _r = _t->getConfigBillItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 150: _t->setConfigBillItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 151: { int _r = _t->getConfigSobanin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 152: _t->setConfigSobanin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 153: { QString _r = _t->getConfigTenbanin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 154: _t->setConfigTenbanin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 155: { QString _r = _t->getConfigBillPreinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 156: _t->setConfigBillPreinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 157: { QString _r = _t->getConfigBillPostinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 158: _t->setConfigBillPostinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 159: { QString _r = _t->getConfigDockversion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 160: _t->setConfigDockversion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 161: { QString _r = _t->getConfigPrintersize();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 162: _t->setConfigPrintersize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 163: { bool _r = _t->getUserEnableConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 164: _t->setUserEnableConfig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 165: { int _r = _t->getConfigRebootDatePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 166: _t->setConfigRebootDatePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 167: { int _r = _t->getConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 168: { int _r = _t->getConfigRebootTimePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 169: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 170: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 171: { QString _r = _t->getRestartTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 172: { QString _r = _t->getCurrentTime((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 173: { QString _r = _t->getConfigUsername();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 174: { QString _r = _t->getConfigUserpwd();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 175: { bool _r = _t->getConfigSearchadvance();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 176: _t->setConfigSearchadvance((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 177: { bool _r = _t->getConfigShowBaocaoDate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 178: _t->setConfigShowBaocaoDate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 179: { QString _r = _t->getConfigCenterService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 180: _t->setConfigCenterService((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 181: { int _r = _t->getConfigIdletime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 182: _t->setConfigIdletime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 183: _t->setIdCoupon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 184: { QString _r = _t->getIdCoupon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 185: _t->setIdCouponPercent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 186: { QString _r = _t->getIdCouponPercent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 187: _t->saveConfig(); break;
        case 188: _t->sendCancelBillUI(); break;
        case 189: { QString _r = _t->getBaocaoCurrentTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 190: _t->inBaocao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 191: _t->userLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 192: _t->uiFoodupdateStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 193: { QString _r = _t->getAccount();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 194: { QString _r = _t->getDiskPrepare();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 195: { QString _r = _t->getDiskReserve();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 196: _t->idleClearup(); break;
        case 197: _t->idleReset(); break;
        case 198: { QString _r = _t->getProductCode((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 199: { long long _r = _t->getPriceCoupon((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = std::move(_r); }  break;
        case 200: _t->removeItemInPaymentView((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
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
            typedef void (MainController::*_t)(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , long , long long , const QString & , const QString & , const QString & );
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
            typedef void (MainController::*_t)(int , const QString & , const QString & , const QString & , const QString & );
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
        if (_id < 201)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 201;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 201)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 201;
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
void MainController::addItem(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6, long _t7, long long _t8, const QString & _t9, const QString & _t10, const QString & _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
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
void MainController::removeItemPaymentView(int _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
