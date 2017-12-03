/****************************************************************************
** Meta object code from reading C++ file 'maincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../domino_v2/maincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainController_t {
    QByteArrayData data[337];
    char stringdata0[4340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainController_t qt_meta_stringdata_MainController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainController"
QT_MOC_LITERAL(1, 15, 15), // "startPlaceOrder"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "showPopupAfterPrint"
QT_MOC_LITERAL(4, 52, 17), // "dominoInvoiceCode"
QT_MOC_LITERAL(5, 70, 9), // "foodReset"
QT_MOC_LITERAL(6, 80, 10), // "foodUpdate"
QT_MOC_LITERAL(7, 91, 5), // "menus"
QT_MOC_LITERAL(8, 97, 13), // "foodSearching"
QT_MOC_LITERAL(9, 111, 7), // "srchtxt"
QT_MOC_LITERAL(10, 119, 7), // "paySucc"
QT_MOC_LITERAL(11, 127, 9), // "invcecode"
QT_MOC_LITERAL(12, 137, 6), // "qrcode"
QT_MOC_LITERAL(13, 144, 8), // "discount"
QT_MOC_LITERAL(14, 153, 6), // "oripay"
QT_MOC_LITERAL(15, 160, 7), // "discpay"
QT_MOC_LITERAL(16, 168, 8), // "payError"
QT_MOC_LITERAL(17, 177, 3), // "msg"
QT_MOC_LITERAL(18, 181, 10), // "notifySucc"
QT_MOC_LITERAL(19, 192, 7), // "errcode"
QT_MOC_LITERAL(20, 200, 9), // "invcetime"
QT_MOC_LITERAL(21, 210, 7), // "barcode"
QT_MOC_LITERAL(22, 218, 7), // "balance"
QT_MOC_LITERAL(23, 226, 7), // "addItem"
QT_MOC_LITERAL(24, 234, 4), // "type"
QT_MOC_LITERAL(25, 239, 9), // "code_name"
QT_MOC_LITERAL(26, 249, 4), // "name"
QT_MOC_LITERAL(27, 254, 4), // "size"
QT_MOC_LITERAL(28, 259, 6), // "debanh"
QT_MOC_LITERAL(29, 266, 6), // "phomai"
QT_MOC_LITERAL(30, 273, 8), // "quantity"
QT_MOC_LITERAL(31, 282, 5), // "price"
QT_MOC_LITERAL(32, 288, 6), // "amount"
QT_MOC_LITERAL(33, 295, 8), // "oriprice"
QT_MOC_LITERAL(34, 304, 8), // "promtype"
QT_MOC_LITERAL(35, 313, 14), // "cancelBillItem"
QT_MOC_LITERAL(36, 328, 24), // "cancellBillCloseQRDialog"
QT_MOC_LITERAL(37, 353, 12), // "updateAmount"
QT_MOC_LITERAL(38, 366, 12), // "scanDockDone"
QT_MOC_LITERAL(39, 379, 8), // "listDock"
QT_MOC_LITERAL(40, 388, 20), // "dockConnectionChange"
QT_MOC_LITERAL(41, 409, 9), // "connected"
QT_MOC_LITERAL(42, 419, 8), // "pingDone"
QT_MOC_LITERAL(43, 428, 4), // "data"
QT_MOC_LITERAL(44, 433, 11), // "loadingDone"
QT_MOC_LITERAL(45, 445, 10), // "telnetDone"
QT_MOC_LITERAL(46, 456, 12), // "telnetResult"
QT_MOC_LITERAL(47, 469, 6), // "result"
QT_MOC_LITERAL(48, 476, 14), // "wifiStatusDone"
QT_MOC_LITERAL(49, 491, 11), // "showMessage"
QT_MOC_LITERAL(50, 503, 21), // "cloudConnectionChange"
QT_MOC_LITERAL(51, 525, 17), // "notifyFoodRequest"
QT_MOC_LITERAL(52, 543, 9), // "printDone"
QT_MOC_LITERAL(53, 553, 14), // "dockStatistics"
QT_MOC_LITERAL(54, 568, 4), // "stat"
QT_MOC_LITERAL(55, 573, 19), // "printerReadyChanged"
QT_MOC_LITERAL(56, 593, 5), // "ready"
QT_MOC_LITERAL(57, 599, 13), // "paymentUpdate"
QT_MOC_LITERAL(58, 613, 7), // "methods"
QT_MOC_LITERAL(59, 621, 11), // "paymentMask"
QT_MOC_LITERAL(60, 633, 30), // "updateShowthanhtoancungdonhang"
QT_MOC_LITERAL(61, 664, 6), // "isShow"
QT_MOC_LITERAL(62, 671, 11), // "cardPayment"
QT_MOC_LITERAL(63, 683, 6), // "cardId"
QT_MOC_LITERAL(64, 690, 12), // "errorMessage"
QT_MOC_LITERAL(65, 703, 3), // "err"
QT_MOC_LITERAL(66, 707, 11), // "updateTitle"
QT_MOC_LITERAL(67, 719, 5), // "title"
QT_MOC_LITERAL(68, 725, 9), // "onPayZalo"
QT_MOC_LITERAL(69, 735, 5), // "sesid"
QT_MOC_LITERAL(70, 741, 4), // "biid"
QT_MOC_LITERAL(71, 746, 12), // "loginRequest"
QT_MOC_LITERAL(72, 759, 5), // "login"
QT_MOC_LITERAL(73, 765, 13), // "baocaoRequest"
QT_MOC_LITERAL(74, 779, 11), // "idleTimeout"
QT_MOC_LITERAL(75, 791, 11), // "dominosData"
QT_MOC_LITERAL(76, 803, 18), // "dominosSetProdName"
QT_MOC_LITERAL(77, 822, 13), // "QSet<QString>"
QT_MOC_LITERAL(78, 836, 21), // "removeItemPaymentView"
QT_MOC_LITERAL(79, 858, 3), // "row"
QT_MOC_LITERAL(80, 862, 9), // "prod_type"
QT_MOC_LITERAL(81, 872, 9), // "size_banh"
QT_MOC_LITERAL(82, 882, 7), // "de_banh"
QT_MOC_LITERAL(83, 890, 10), // "closePopup"
QT_MOC_LITERAL(84, 901, 7), // "popupid"
QT_MOC_LITERAL(85, 909, 21), // "closePopupSelectPizza"
QT_MOC_LITERAL(86, 931, 12), // "onCancelDone"
QT_MOC_LITERAL(87, 944, 13), // "onCancelError"
QT_MOC_LITERAL(88, 958, 12), // "onRejectDone"
QT_MOC_LITERAL(89, 971, 13), // "onRejectError"
QT_MOC_LITERAL(90, 985, 13), // "onPayZaloDone"
QT_MOC_LITERAL(91, 999, 14), // "onPayZaloError"
QT_MOC_LITERAL(92, 1014, 5), // "error"
QT_MOC_LITERAL(93, 1020, 8), // "onNotify"
QT_MOC_LITERAL(94, 1029, 7), // "message"
QT_MOC_LITERAL(95, 1037, 13), // "onMifareFound"
QT_MOC_LITERAL(96, 1051, 2), // "id"
QT_MOC_LITERAL(97, 1054, 20), // "onCenterServiceFound"
QT_MOC_LITERAL(98, 1075, 2), // "ip"
QT_MOC_LITERAL(99, 1078, 4), // "port"
QT_MOC_LITERAL(100, 1083, 11), // "onFoodsDone"
QT_MOC_LITERAL(101, 1095, 12), // "onFoodsError"
QT_MOC_LITERAL(102, 1108, 18), // "onUpdatedFoodsData"
QT_MOC_LITERAL(103, 1127, 22), // "onCheckUpdateFoodsData"
QT_MOC_LITERAL(104, 1150, 27), // "onCheckUpdateFoodsDataError"
QT_MOC_LITERAL(105, 1178, 7), // "onLogin"
QT_MOC_LITERAL(106, 1186, 5), // "uname"
QT_MOC_LITERAL(107, 1192, 3), // "pwd"
QT_MOC_LITERAL(108, 1196, 8), // "isBaocao"
QT_MOC_LITERAL(109, 1205, 11), // "onLoginDone"
QT_MOC_LITERAL(110, 1217, 12), // "onLoginError"
QT_MOC_LITERAL(111, 1230, 8), // "onBaocao"
QT_MOC_LITERAL(112, 1239, 12), // "onBaocaoDone"
QT_MOC_LITERAL(113, 1252, 13), // "onBaocaoError"
QT_MOC_LITERAL(114, 1266, 16), // "onAlertEmailDone"
QT_MOC_LITERAL(115, 1283, 17), // "onAlertEmailError"
QT_MOC_LITERAL(116, 1301, 16), // "onAlertPhoneDone"
QT_MOC_LITERAL(117, 1318, 17), // "onAlertPhoneError"
QT_MOC_LITERAL(118, 1336, 9), // "doPayCard"
QT_MOC_LITERAL(119, 1346, 10), // "doGetPmsid"
QT_MOC_LITERAL(120, 1357, 12), // "merchantCode"
QT_MOC_LITERAL(121, 1370, 5), // "devId"
QT_MOC_LITERAL(122, 1376, 4), // "biId"
QT_MOC_LITERAL(123, 1381, 9), // "payMethod"
QT_MOC_LITERAL(124, 1391, 15), // "onPmsidDoneZalo"
QT_MOC_LITERAL(125, 1407, 15), // "onPmsidDoneCash"
QT_MOC_LITERAL(126, 1423, 12), // "onPmsidError"
QT_MOC_LITERAL(127, 1436, 9), // "doPayZalo"
QT_MOC_LITERAL(128, 1446, 5), // "sesId"
QT_MOC_LITERAL(129, 1452, 9), // "doPayCash"
QT_MOC_LITERAL(130, 1462, 13), // "onPayCashDone"
QT_MOC_LITERAL(131, 1476, 14), // "onPayCashError"
QT_MOC_LITERAL(132, 1491, 12), // "foodsRequest"
QT_MOC_LITERAL(133, 1504, 19), // "checkUpdateFoodData"
QT_MOC_LITERAL(134, 1524, 16), // "timerStartUpdate"
QT_MOC_LITERAL(135, 1541, 13), // "timerDoUpdate"
QT_MOC_LITERAL(136, 1555, 11), // "timerReboot"
QT_MOC_LITERAL(137, 1567, 15), // "timerSystemIdle"
QT_MOC_LITERAL(138, 1583, 15), // "onStoreProducts"
QT_MOC_LITERAL(139, 1599, 13), // "storeProducts"
QT_MOC_LITERAL(140, 1613, 18), // "onStoreInformation"
QT_MOC_LITERAL(141, 1632, 16), // "storeInformation"
QT_MOC_LITERAL(142, 1649, 15), // "eventPlaceOrder"
QT_MOC_LITERAL(143, 1665, 18), // "eventPlaceOrderErr"
QT_MOC_LITERAL(144, 1684, 11), // "isDebugmode"
QT_MOC_LITERAL(145, 1696, 11), // "isRaspberry"
QT_MOC_LITERAL(146, 1708, 13), // "isCashAllowed"
QT_MOC_LITERAL(147, 1722, 13), // "isCardAllowed"
QT_MOC_LITERAL(148, 1736, 7), // "appQuit"
QT_MOC_LITERAL(149, 1744, 12), // "searchFilter"
QT_MOC_LITERAL(150, 1757, 8), // "foodname"
QT_MOC_LITERAL(151, 1766, 10), // "searchFood"
QT_MOC_LITERAL(152, 1777, 10), // "viet2latin"
QT_MOC_LITERAL(153, 1788, 3), // "pay"
QT_MOC_LITERAL(154, 1792, 13), // "customer_name"
QT_MOC_LITERAL(155, 1806, 17), // "customer_hinhthuc"
QT_MOC_LITERAL(156, 1824, 5), // "foods"
QT_MOC_LITERAL(157, 1830, 10), // "insertItem"
QT_MOC_LITERAL(158, 1841, 11), // "formatMoney"
QT_MOC_LITERAL(159, 1853, 10), // "moneyValue"
QT_MOC_LITERAL(160, 1864, 13), // "getMoneyValue"
QT_MOC_LITERAL(161, 1878, 11), // "moneyString"
QT_MOC_LITERAL(162, 1890, 10), // "moneyMoney"
QT_MOC_LITERAL(163, 1901, 5), // "money"
QT_MOC_LITERAL(164, 1907, 16), // "updateTotalMoney"
QT_MOC_LITERAL(165, 1924, 20), // "updateCardWaitingPay"
QT_MOC_LITERAL(166, 1945, 7), // "waiting"
QT_MOC_LITERAL(167, 1953, 9), // "printBill"
QT_MOC_LITERAL(168, 1963, 6), // "ivcode"
QT_MOC_LITERAL(169, 1970, 9), // "printData"
QT_MOC_LITERAL(170, 1980, 10), // "cancelBill"
QT_MOC_LITERAL(171, 1991, 4), // "foId"
QT_MOC_LITERAL(172, 1996, 5), // "total"
QT_MOC_LITERAL(173, 2002, 10), // "stopDevice"
QT_MOC_LITERAL(174, 2013, 10), // "getPrinter"
QT_MOC_LITERAL(175, 2024, 10), // "setPrinter"
QT_MOC_LITERAL(176, 2035, 7), // "prnName"
QT_MOC_LITERAL(177, 2043, 10), // "getPayment"
QT_MOC_LITERAL(178, 2054, 18), // "getDominoServerUrl"
QT_MOC_LITERAL(179, 2073, 13), // "getHostTelnet"
QT_MOC_LITERAL(180, 2087, 13), // "getPortTelnet"
QT_MOC_LITERAL(181, 2101, 13), // "setHostTelnet"
QT_MOC_LITERAL(182, 2115, 4), // "host"
QT_MOC_LITERAL(183, 2120, 13), // "setPortTelnet"
QT_MOC_LITERAL(184, 2134, 14), // "getDominoStore"
QT_MOC_LITERAL(185, 2149, 12), // "getListEmail"
QT_MOC_LITERAL(186, 2162, 12), // "setListEmail"
QT_MOC_LITERAL(187, 2175, 9), // "listemail"
QT_MOC_LITERAL(188, 2185, 12), // "getListPhone"
QT_MOC_LITERAL(189, 2198, 12), // "setListPhone"
QT_MOC_LITERAL(190, 2211, 9), // "listphone"
QT_MOC_LITERAL(191, 2221, 13), // "getUrlService"
QT_MOC_LITERAL(192, 2235, 19), // "getTransferProtocol"
QT_MOC_LITERAL(193, 2255, 19), // "setTransferProtocol"
QT_MOC_LITERAL(194, 2275, 8), // "transpro"
QT_MOC_LITERAL(195, 2284, 10), // "initSocket"
QT_MOC_LITERAL(196, 2295, 10), // "setPayment"
QT_MOC_LITERAL(197, 2306, 11), // "paymentName"
QT_MOC_LITERAL(198, 2318, 18), // "setDominoServerUrl"
QT_MOC_LITERAL(199, 2337, 3), // "url"
QT_MOC_LITERAL(200, 2341, 14), // "setDominoStore"
QT_MOC_LITERAL(201, 2356, 5), // "store"
QT_MOC_LITERAL(202, 2362, 16), // "setPaymentMethod"
QT_MOC_LITERAL(203, 2379, 13), // "paymentMethod"
QT_MOC_LITERAL(204, 2393, 16), // "getPaymentMethod"
QT_MOC_LITERAL(205, 2410, 14), // "setPaymentMask"
QT_MOC_LITERAL(206, 2425, 7), // "payment"
QT_MOC_LITERAL(207, 2433, 5), // "onoff"
QT_MOC_LITERAL(208, 2439, 14), // "getPaymentMask"
QT_MOC_LITERAL(209, 2454, 13), // "getDockServer"
QT_MOC_LITERAL(210, 2468, 13), // "setDockServer"
QT_MOC_LITERAL(211, 2482, 10), // "dockServer"
QT_MOC_LITERAL(212, 2493, 8), // "scanDock"
QT_MOC_LITERAL(213, 2502, 6), // "doAuto"
QT_MOC_LITERAL(214, 2509, 11), // "isConnected"
QT_MOC_LITERAL(215, 2521, 13), // "connectToDock"
QT_MOC_LITERAL(216, 2535, 8), // "serverIp"
QT_MOC_LITERAL(217, 2544, 18), // "disconnectFromDock"
QT_MOC_LITERAL(218, 2563, 16), // "testReaderDevice"
QT_MOC_LITERAL(219, 2580, 3), // "run"
QT_MOC_LITERAL(220, 2584, 10), // "updateWifi"
QT_MOC_LITERAL(221, 2595, 4), // "ssid"
QT_MOC_LITERAL(222, 2600, 3), // "key"
QT_MOC_LITERAL(223, 2604, 7), // "encrypt"
QT_MOC_LITERAL(224, 2612, 12), // "updateWifiPi"
QT_MOC_LITERAL(225, 2625, 9), // "interface"
QT_MOC_LITERAL(226, 2635, 9), // "scan_ssid"
QT_MOC_LITERAL(227, 2645, 10), // "wifiStatus"
QT_MOC_LITERAL(228, 2656, 8), // "testPing"
QT_MOC_LITERAL(229, 2665, 10), // "testTelnet"
QT_MOC_LITERAL(230, 2676, 18), // "telnetDominoServer"
QT_MOC_LITERAL(231, 2695, 23), // "killProcessTelnetDomino"
QT_MOC_LITERAL(232, 2719, 7), // "doAlert"
QT_MOC_LITERAL(233, 2727, 11), // "restartDock"
QT_MOC_LITERAL(234, 2739, 9), // "restartPi"
QT_MOC_LITERAL(235, 2749, 6), // "haltPi"
QT_MOC_LITERAL(236, 2756, 18), // "checkPrinterStatus"
QT_MOC_LITERAL(237, 2775, 9), // "printTest"
QT_MOC_LITERAL(238, 2785, 14), // "getPrintStatus"
QT_MOC_LITERAL(239, 2800, 10), // "getLocalIp"
QT_MOC_LITERAL(240, 2811, 11), // "getAppIndex"
QT_MOC_LITERAL(241, 2823, 10), // "getAppName"
QT_MOC_LITERAL(242, 2834, 10), // "setAppName"
QT_MOC_LITERAL(243, 2845, 7), // "appName"
QT_MOC_LITERAL(244, 2853, 11), // "getAppTitle"
QT_MOC_LITERAL(245, 2865, 11), // "getTitleEng"
QT_MOC_LITERAL(246, 2877, 11), // "setAppTitle"
QT_MOC_LITERAL(247, 2889, 15), // "getMachineIndex"
QT_MOC_LITERAL(248, 2905, 13), // "getAppMachine"
QT_MOC_LITERAL(249, 2919, 14), // "getRechargeNum"
QT_MOC_LITERAL(250, 2934, 14), // "setRechargeNum"
QT_MOC_LITERAL(251, 2949, 5), // "mcNum"
QT_MOC_LITERAL(252, 2955, 19), // "getFoodRefreshTimer"
QT_MOC_LITERAL(253, 2975, 19), // "setFoodRefreshTimer"
QT_MOC_LITERAL(254, 2995, 5), // "timer"
QT_MOC_LITERAL(255, 3001, 17), // "getBillAlertTimer"
QT_MOC_LITERAL(256, 3019, 15), // "getGInvoiceCode"
QT_MOC_LITERAL(257, 3035, 17), // "setBillAlertTimer"
QT_MOC_LITERAL(258, 3053, 27), // "getShowThanhtoancungdonhang"
QT_MOC_LITERAL(259, 3081, 27), // "setShowThanhtoancungdonhang"
QT_MOC_LITERAL(260, 3109, 20), // "getConfigQrcodeRatio"
QT_MOC_LITERAL(261, 3130, 20), // "setConfigQrcodeRatio"
QT_MOC_LITERAL(262, 3151, 5), // "ratio"
QT_MOC_LITERAL(263, 3157, 25), // "getConfigFoodItemFontsize"
QT_MOC_LITERAL(264, 3183, 25), // "setConfigFoodItemFontsize"
QT_MOC_LITERAL(265, 3209, 7), // "fntsize"
QT_MOC_LITERAL(266, 3217, 25), // "getConfigBillItemFontsize"
QT_MOC_LITERAL(267, 3243, 25), // "setConfigBillItemFontsize"
QT_MOC_LITERAL(268, 3269, 16), // "getConfigSobanin"
QT_MOC_LITERAL(269, 3286, 16), // "setConfigSobanin"
QT_MOC_LITERAL(270, 3303, 3), // "num"
QT_MOC_LITERAL(271, 3307, 17), // "getConfigTenbanin"
QT_MOC_LITERAL(272, 3325, 17), // "setConfigTenbanin"
QT_MOC_LITERAL(273, 3343, 19), // "getConfigBillPreinf"
QT_MOC_LITERAL(274, 3363, 19), // "setConfigBillPreinf"
QT_MOC_LITERAL(275, 3383, 4), // "info"
QT_MOC_LITERAL(276, 3388, 20), // "getConfigBillPostinf"
QT_MOC_LITERAL(277, 3409, 20), // "setConfigBillPostinf"
QT_MOC_LITERAL(278, 3430, 20), // "getConfigDockversion"
QT_MOC_LITERAL(279, 3451, 20), // "setConfigDockversion"
QT_MOC_LITERAL(280, 3472, 7), // "version"
QT_MOC_LITERAL(281, 3480, 20), // "getConfigPrintersize"
QT_MOC_LITERAL(282, 3501, 20), // "setConfigPrintersize"
QT_MOC_LITERAL(283, 3522, 8), // "pagesize"
QT_MOC_LITERAL(284, 3531, 19), // "getUserEnableConfig"
QT_MOC_LITERAL(285, 3551, 19), // "setUserEnableConfig"
QT_MOC_LITERAL(286, 3571, 10), // "enableconf"
QT_MOC_LITERAL(287, 3582, 21), // "getConfigRebootDatePi"
QT_MOC_LITERAL(288, 3604, 21), // "setConfigRebootDatePi"
QT_MOC_LITERAL(289, 3626, 9), // "dayofweek"
QT_MOC_LITERAL(290, 3636, 2), // "on"
QT_MOC_LITERAL(291, 3639, 21), // "getConfigRebootTimePi"
QT_MOC_LITERAL(292, 3661, 21), // "setConfigRebootTimePi"
QT_MOC_LITERAL(293, 3683, 5), // "value"
QT_MOC_LITERAL(294, 3689, 14), // "getRestartTime"
QT_MOC_LITERAL(295, 3704, 14), // "getCurrentTime"
QT_MOC_LITERAL(296, 3719, 17), // "getConfigUsername"
QT_MOC_LITERAL(297, 3737, 16), // "getConfigUserpwd"
QT_MOC_LITERAL(298, 3754, 22), // "getConfigSearchadvance"
QT_MOC_LITERAL(299, 3777, 22), // "setConfigSearchadvance"
QT_MOC_LITERAL(300, 3800, 13), // "searchadvance"
QT_MOC_LITERAL(301, 3814, 23), // "getConfigShowBaocaoDate"
QT_MOC_LITERAL(302, 3838, 23), // "setConfigShowBaocaoDate"
QT_MOC_LITERAL(303, 3862, 8), // "showDate"
QT_MOC_LITERAL(304, 3871, 22), // "getConfigCenterService"
QT_MOC_LITERAL(305, 3894, 22), // "setConfigCenterService"
QT_MOC_LITERAL(306, 3917, 15), // "centerServiceIp"
QT_MOC_LITERAL(307, 3933, 17), // "getConfigIdletime"
QT_MOC_LITERAL(308, 3951, 17), // "setConfigIdletime"
QT_MOC_LITERAL(309, 3969, 11), // "setIdCoupon"
QT_MOC_LITERAL(310, 3981, 11), // "getIdCoupon"
QT_MOC_LITERAL(311, 3993, 18), // "setIdCouponPercent"
QT_MOC_LITERAL(312, 4012, 7), // "percent"
QT_MOC_LITERAL(313, 4020, 18), // "getIdCouponPercent"
QT_MOC_LITERAL(314, 4039, 15), // "doPlaceOrderErr"
QT_MOC_LITERAL(315, 4055, 10), // "saveConfig"
QT_MOC_LITERAL(316, 4066, 16), // "sendCancelBillUI"
QT_MOC_LITERAL(317, 4083, 20), // "getBaocaoCurrentTime"
QT_MOC_LITERAL(318, 4104, 8), // "inBaocao"
QT_MOC_LITERAL(319, 4113, 4), // "date"
QT_MOC_LITERAL(320, 4118, 6), // "bcType"
QT_MOC_LITERAL(321, 4125, 9), // "userLogin"
QT_MOC_LITERAL(322, 4135, 18), // "uiFoodupdateStatus"
QT_MOC_LITERAL(323, 4154, 6), // "uiType"
QT_MOC_LITERAL(324, 4161, 10), // "getAccount"
QT_MOC_LITERAL(325, 4172, 14), // "getDiskPrepare"
QT_MOC_LITERAL(326, 4187, 14), // "getDiskReserve"
QT_MOC_LITERAL(327, 4202, 11), // "idleClearup"
QT_MOC_LITERAL(328, 4214, 9), // "idleReset"
QT_MOC_LITERAL(329, 4224, 14), // "getProductCode"
QT_MOC_LITERAL(330, 4239, 8), // "pro_name"
QT_MOC_LITERAL(331, 4248, 9), // "prod_size"
QT_MOC_LITERAL(332, 4258, 16), // "prod_plavor_code"
QT_MOC_LITERAL(333, 4275, 14), // "getPriceCoupon"
QT_MOC_LITERAL(334, 4290, 10), // "pizza_size"
QT_MOC_LITERAL(335, 4301, 23), // "removeItemInPaymentView"
QT_MOC_LITERAL(336, 4325, 14) // "closeThanhtoan"

    },
    "MainController\0startPlaceOrder\0\0"
    "showPopupAfterPrint\0dominoInvoiceCode\0"
    "foodReset\0foodUpdate\0menus\0foodSearching\0"
    "srchtxt\0paySucc\0invcecode\0qrcode\0"
    "discount\0oripay\0discpay\0payError\0msg\0"
    "notifySucc\0errcode\0invcetime\0barcode\0"
    "balance\0addItem\0type\0code_name\0name\0"
    "size\0debanh\0phomai\0quantity\0price\0"
    "amount\0oriprice\0promtype\0cancelBillItem\0"
    "cancellBillCloseQRDialog\0updateAmount\0"
    "scanDockDone\0listDock\0dockConnectionChange\0"
    "connected\0pingDone\0data\0loadingDone\0"
    "telnetDone\0telnetResult\0result\0"
    "wifiStatusDone\0showMessage\0"
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
    "closePopup\0popupid\0closePopupSelectPizza\0"
    "onCancelDone\0onCancelError\0onRejectDone\0"
    "onRejectError\0onPayZaloDone\0onPayZaloError\0"
    "error\0onNotify\0message\0onMifareFound\0"
    "id\0onCenterServiceFound\0ip\0port\0"
    "onFoodsDone\0onFoodsError\0onUpdatedFoodsData\0"
    "onCheckUpdateFoodsData\0"
    "onCheckUpdateFoodsDataError\0onLogin\0"
    "uname\0pwd\0isBaocao\0onLoginDone\0"
    "onLoginError\0onBaocao\0onBaocaoDone\0"
    "onBaocaoError\0onAlertEmailDone\0"
    "onAlertEmailError\0onAlertPhoneDone\0"
    "onAlertPhoneError\0doPayCard\0doGetPmsid\0"
    "merchantCode\0devId\0biId\0payMethod\0"
    "onPmsidDoneZalo\0onPmsidDoneCash\0"
    "onPmsidError\0doPayZalo\0sesId\0doPayCash\0"
    "onPayCashDone\0onPayCashError\0foodsRequest\0"
    "checkUpdateFoodData\0timerStartUpdate\0"
    "timerDoUpdate\0timerReboot\0timerSystemIdle\0"
    "onStoreProducts\0storeProducts\0"
    "onStoreInformation\0storeInformation\0"
    "eventPlaceOrder\0eventPlaceOrderErr\0"
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
    "getDominoServerUrl\0getHostTelnet\0"
    "getPortTelnet\0setHostTelnet\0host\0"
    "setPortTelnet\0getDominoStore\0getListEmail\0"
    "setListEmail\0listemail\0getListPhone\0"
    "setListPhone\0listphone\0getUrlService\0"
    "getTransferProtocol\0setTransferProtocol\0"
    "transpro\0initSocket\0setPayment\0"
    "paymentName\0setDominoServerUrl\0url\0"
    "setDominoStore\0store\0setPaymentMethod\0"
    "paymentMethod\0getPaymentMethod\0"
    "setPaymentMask\0payment\0onoff\0"
    "getPaymentMask\0getDockServer\0setDockServer\0"
    "dockServer\0scanDock\0doAuto\0isConnected\0"
    "connectToDock\0serverIp\0disconnectFromDock\0"
    "testReaderDevice\0run\0updateWifi\0ssid\0"
    "key\0encrypt\0updateWifiPi\0interface\0"
    "scan_ssid\0wifiStatus\0testPing\0testTelnet\0"
    "telnetDominoServer\0killProcessTelnetDomino\0"
    "doAlert\0restartDock\0restartPi\0haltPi\0"
    "checkPrinterStatus\0printTest\0"
    "getPrintStatus\0getLocalIp\0getAppIndex\0"
    "getAppName\0setAppName\0appName\0getAppTitle\0"
    "getTitleEng\0setAppTitle\0getMachineIndex\0"
    "getAppMachine\0getRechargeNum\0"
    "setRechargeNum\0mcNum\0getFoodRefreshTimer\0"
    "setFoodRefreshTimer\0timer\0getBillAlertTimer\0"
    "getGInvoiceCode\0setBillAlertTimer\0"
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
    "percent\0getIdCouponPercent\0doPlaceOrderErr\0"
    "saveConfig\0sendCancelBillUI\0"
    "getBaocaoCurrentTime\0inBaocao\0date\0"
    "bcType\0userLogin\0uiFoodupdateStatus\0"
    "uiType\0getAccount\0getDiskPrepare\0"
    "getDiskReserve\0idleClearup\0idleReset\0"
    "getProductCode\0pro_name\0prod_size\0"
    "prod_plavor_code\0getPriceCoupon\0"
    "pizza_size\0removeItemInPaymentView\0"
    "closeThanhtoan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     230,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      41,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0, 1164,    2, 0x06 /* Public */,
       3,    1, 1165,    2, 0x06 /* Public */,
       5,    0, 1168,    2, 0x06 /* Public */,
       6,    1, 1169,    2, 0x06 /* Public */,
       8,    1, 1172,    2, 0x06 /* Public */,
      10,    5, 1175,    2, 0x06 /* Public */,
      16,    1, 1186,    2, 0x06 /* Public */,
      18,    5, 1189,    2, 0x06 /* Public */,
      23,   11, 1200,    2, 0x06 /* Public */,
      35,    0, 1223,    2, 0x06 /* Public */,
      36,    0, 1224,    2, 0x06 /* Public */,
      37,    1, 1225,    2, 0x06 /* Public */,
      38,    1, 1228,    2, 0x06 /* Public */,
      40,    1, 1231,    2, 0x06 /* Public */,
      42,    1, 1234,    2, 0x06 /* Public */,
      44,    0, 1237,    2, 0x06 /* Public */,
      45,    1, 1238,    2, 0x06 /* Public */,
      46,    1, 1241,    2, 0x06 /* Public */,
      48,    1, 1244,    2, 0x06 /* Public */,
      49,    1, 1247,    2, 0x06 /* Public */,
      50,    1, 1250,    2, 0x06 /* Public */,
      51,    0, 1253,    2, 0x06 /* Public */,
      52,    1, 1254,    2, 0x06 /* Public */,
      53,    1, 1257,    2, 0x06 /* Public */,
      55,    1, 1260,    2, 0x06 /* Public */,
      57,    1, 1263,    2, 0x06 /* Public */,
      59,    1, 1266,    2, 0x06 /* Public */,
      60,    1, 1269,    2, 0x06 /* Public */,
      62,    1, 1272,    2, 0x06 /* Public */,
      64,    2, 1275,    2, 0x06 /* Public */,
      66,    1, 1280,    2, 0x06 /* Public */,
      68,    2, 1283,    2, 0x06 /* Public */,
      71,    0, 1288,    2, 0x06 /* Public */,
      72,    2, 1289,    2, 0x06 /* Public */,
      73,    0, 1294,    2, 0x06 /* Public */,
      74,    0, 1295,    2, 0x06 /* Public */,
      75,    1, 1296,    2, 0x06 /* Public */,
      76,    1, 1299,    2, 0x06 /* Public */,
      78,    5, 1302,    2, 0x06 /* Public */,
      83,    2, 1313,    2, 0x06 /* Public */,
      85,    2, 1318,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      86,    1, 1323,    2, 0x0a /* Public */,
      87,    2, 1326,    2, 0x0a /* Public */,
      88,    1, 1331,    2, 0x0a /* Public */,
      89,    2, 1334,    2, 0x0a /* Public */,
      90,    1, 1339,    2, 0x0a /* Public */,
      91,    2, 1342,    2, 0x0a /* Public */,
      93,    1, 1347,    2, 0x0a /* Public */,
      95,    1, 1350,    2, 0x0a /* Public */,
      97,    2, 1353,    2, 0x0a /* Public */,
     100,    1, 1358,    2, 0x0a /* Public */,
     101,    2, 1361,    2, 0x0a /* Public */,
     102,    1, 1366,    2, 0x0a /* Public */,
     103,    1, 1369,    2, 0x0a /* Public */,
     104,    2, 1372,    2, 0x0a /* Public */,
     105,    3, 1377,    2, 0x0a /* Public */,
     109,    1, 1384,    2, 0x0a /* Public */,
     110,    2, 1387,    2, 0x0a /* Public */,
     111,    0, 1392,    2, 0x0a /* Public */,
     112,    1, 1393,    2, 0x0a /* Public */,
     113,    2, 1396,    2, 0x0a /* Public */,
     114,    1, 1401,    2, 0x0a /* Public */,
     115,    2, 1404,    2, 0x0a /* Public */,
     116,    1, 1409,    2, 0x0a /* Public */,
     117,    2, 1412,    2, 0x0a /* Public */,
     118,    1, 1417,    2, 0x0a /* Public */,
     119,    4, 1420,    2, 0x0a /* Public */,
     124,    1, 1429,    2, 0x0a /* Public */,
     125,    1, 1432,    2, 0x0a /* Public */,
     126,    2, 1435,    2, 0x0a /* Public */,
     127,    2, 1440,    2, 0x0a /* Public */,
     129,    2, 1445,    2, 0x0a /* Public */,
     130,    1, 1450,    2, 0x0a /* Public */,
     131,    2, 1453,    2, 0x0a /* Public */,
     132,    0, 1458,    2, 0x0a /* Public */,
     133,    0, 1459,    2, 0x0a /* Public */,
     134,    0, 1460,    2, 0x0a /* Public */,
     135,    0, 1461,    2, 0x0a /* Public */,
     136,    0, 1462,    2, 0x0a /* Public */,
     137,    0, 1463,    2, 0x0a /* Public */,
     138,    1, 1464,    2, 0x0a /* Public */,
     140,    1, 1467,    2, 0x0a /* Public */,
     142,    1, 1470,    2, 0x0a /* Public */,
     143,    2, 1473,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
     144,    0, 1478,    2, 0x02 /* Public */,
     145,    0, 1479,    2, 0x02 /* Public */,
     146,    0, 1480,    2, 0x02 /* Public */,
     147,    0, 1481,    2, 0x02 /* Public */,
     148,    0, 1482,    2, 0x02 /* Public */,
     149,    2, 1483,    2, 0x02 /* Public */,
     151,    1, 1488,    2, 0x02 /* Public */,
     152,    1, 1491,    2, 0x02 /* Public */,
     153,    5, 1494,    2, 0x02 /* Public */,
     157,   10, 1505,    2, 0x02 /* Public */,
     158,    1, 1526,    2, 0x02 /* Public */,
     160,    1, 1529,    2, 0x02 /* Public */,
     162,    1, 1532,    2, 0x02 /* Public */,
     164,    1, 1535,    2, 0x02 /* Public */,
     165,    1, 1538,    2, 0x02 /* Public */,
     167,    2, 1541,    2, 0x02 /* Public */,
     170,    3, 1546,    2, 0x02 /* Public */,
     173,    0, 1553,    2, 0x02 /* Public */,
     174,    0, 1554,    2, 0x02 /* Public */,
     175,    1, 1555,    2, 0x02 /* Public */,
     177,    0, 1558,    2, 0x02 /* Public */,
     178,    0, 1559,    2, 0x02 /* Public */,
     179,    0, 1560,    2, 0x02 /* Public */,
     180,    0, 1561,    2, 0x02 /* Public */,
     181,    1, 1562,    2, 0x02 /* Public */,
     183,    1, 1565,    2, 0x02 /* Public */,
     184,    0, 1568,    2, 0x02 /* Public */,
     185,    0, 1569,    2, 0x02 /* Public */,
     186,    1, 1570,    2, 0x02 /* Public */,
     188,    0, 1573,    2, 0x02 /* Public */,
     189,    1, 1574,    2, 0x02 /* Public */,
     191,    0, 1577,    2, 0x02 /* Public */,
     192,    0, 1578,    2, 0x02 /* Public */,
     193,    2, 1579,    2, 0x02 /* Public */,
     193,    1, 1584,    2, 0x22 /* Public | MethodCloned */,
     196,    2, 1587,    2, 0x02 /* Public */,
     196,    1, 1592,    2, 0x22 /* Public | MethodCloned */,
     198,    1, 1595,    2, 0x02 /* Public */,
     200,    1, 1598,    2, 0x02 /* Public */,
     202,    1, 1601,    2, 0x02 /* Public */,
     204,    0, 1604,    2, 0x02 /* Public */,
     205,    2, 1605,    2, 0x02 /* Public */,
     208,    0, 1610,    2, 0x02 /* Public */,
     209,    0, 1611,    2, 0x02 /* Public */,
     210,    1, 1612,    2, 0x02 /* Public */,
     212,    1, 1615,    2, 0x02 /* Public */,
     212,    0, 1618,    2, 0x22 /* Public | MethodCloned */,
     214,    0, 1619,    2, 0x02 /* Public */,
     215,    1, 1620,    2, 0x02 /* Public */,
     217,    0, 1623,    2, 0x02 /* Public */,
     218,    1, 1624,    2, 0x02 /* Public */,
     220,    3, 1627,    2, 0x02 /* Public */,
     220,    2, 1634,    2, 0x22 /* Public | MethodCloned */,
     224,    5, 1639,    2, 0x02 /* Public */,
     224,    4, 1650,    2, 0x22 /* Public | MethodCloned */,
     224,    3, 1659,    2, 0x22 /* Public | MethodCloned */,
     227,    1, 1666,    2, 0x02 /* Public */,
     227,    0, 1669,    2, 0x22 /* Public | MethodCloned */,
     228,    1, 1670,    2, 0x02 /* Public */,
     229,    2, 1673,    2, 0x02 /* Public */,
     230,    0, 1678,    2, 0x02 /* Public */,
     231,    0, 1679,    2, 0x02 /* Public */,
     232,    0, 1680,    2, 0x02 /* Public */,
     233,    0, 1681,    2, 0x02 /* Public */,
     234,    0, 1682,    2, 0x02 /* Public */,
     235,    0, 1683,    2, 0x02 /* Public */,
     236,    0, 1684,    2, 0x02 /* Public */,
     237,    1, 1685,    2, 0x02 /* Public */,
     238,    0, 1688,    2, 0x02 /* Public */,
     239,    0, 1689,    2, 0x02 /* Public */,
     240,    0, 1690,    2, 0x02 /* Public */,
     241,    0, 1691,    2, 0x02 /* Public */,
     242,    2, 1692,    2, 0x02 /* Public */,
     242,    1, 1697,    2, 0x22 /* Public | MethodCloned */,
     244,    0, 1700,    2, 0x02 /* Public */,
     245,    0, 1701,    2, 0x02 /* Public */,
     246,    1, 1702,    2, 0x02 /* Public */,
     247,    0, 1705,    2, 0x02 /* Public */,
     248,    0, 1706,    2, 0x02 /* Public */,
     249,    0, 1707,    2, 0x02 /* Public */,
     250,    1, 1708,    2, 0x02 /* Public */,
     252,    0, 1711,    2, 0x02 /* Public */,
     253,    1, 1712,    2, 0x02 /* Public */,
     255,    0, 1715,    2, 0x02 /* Public */,
     256,    0, 1716,    2, 0x02 /* Public */,
     257,    1, 1717,    2, 0x02 /* Public */,
     258,    0, 1720,    2, 0x02 /* Public */,
     259,    1, 1721,    2, 0x02 /* Public */,
     260,    0, 1724,    2, 0x02 /* Public */,
     261,    1, 1725,    2, 0x02 /* Public */,
     263,    0, 1728,    2, 0x02 /* Public */,
     264,    1, 1729,    2, 0x02 /* Public */,
     266,    0, 1732,    2, 0x02 /* Public */,
     267,    1, 1733,    2, 0x02 /* Public */,
     268,    0, 1736,    2, 0x02 /* Public */,
     269,    1, 1737,    2, 0x02 /* Public */,
     271,    0, 1740,    2, 0x02 /* Public */,
     272,    1, 1741,    2, 0x02 /* Public */,
     273,    0, 1744,    2, 0x02 /* Public */,
     274,    1, 1745,    2, 0x02 /* Public */,
     276,    0, 1748,    2, 0x02 /* Public */,
     277,    1, 1749,    2, 0x02 /* Public */,
     278,    0, 1752,    2, 0x02 /* Public */,
     279,    1, 1753,    2, 0x02 /* Public */,
     281,    0, 1756,    2, 0x02 /* Public */,
     282,    1, 1757,    2, 0x02 /* Public */,
     284,    0, 1760,    2, 0x02 /* Public */,
     285,    1, 1761,    2, 0x02 /* Public */,
     287,    0, 1764,    2, 0x02 /* Public */,
     288,    2, 1765,    2, 0x02 /* Public */,
     291,    1, 1770,    2, 0x02 /* Public */,
     291,    0, 1773,    2, 0x22 /* Public | MethodCloned */,
     292,    2, 1774,    2, 0x02 /* Public */,
     292,    1, 1779,    2, 0x22 /* Public | MethodCloned */,
     294,    0, 1782,    2, 0x02 /* Public */,
     295,    1, 1783,    2, 0x02 /* Public */,
     296,    0, 1786,    2, 0x02 /* Public */,
     297,    0, 1787,    2, 0x02 /* Public */,
     298,    0, 1788,    2, 0x02 /* Public */,
     299,    1, 1789,    2, 0x02 /* Public */,
     301,    0, 1792,    2, 0x02 /* Public */,
     302,    1, 1793,    2, 0x02 /* Public */,
     304,    0, 1796,    2, 0x02 /* Public */,
     305,    1, 1797,    2, 0x02 /* Public */,
     307,    0, 1800,    2, 0x02 /* Public */,
     308,    1, 1801,    2, 0x02 /* Public */,
     309,    1, 1804,    2, 0x02 /* Public */,
     310,    0, 1807,    2, 0x02 /* Public */,
     311,    1, 1808,    2, 0x02 /* Public */,
     313,    0, 1811,    2, 0x02 /* Public */,
     314,    0, 1812,    2, 0x02 /* Public */,
     315,    0, 1813,    2, 0x02 /* Public */,
     316,    0, 1814,    2, 0x02 /* Public */,
     317,    0, 1815,    2, 0x02 /* Public */,
     318,    2, 1816,    2, 0x02 /* Public */,
     321,    2, 1821,    2, 0x02 /* Public */,
     322,    1, 1826,    2, 0x02 /* Public */,
     324,    0, 1829,    2, 0x02 /* Public */,
     325,    0, 1830,    2, 0x02 /* Public */,
     326,    0, 1831,    2, 0x02 /* Public */,
     327,    0, 1832,    2, 0x02 /* Public */,
     328,    0, 1833,    2, 0x02 /* Public */,
     329,    3, 1834,    2, 0x02 /* Public */,
     333,    2, 1841,    2, 0x02 /* Public */,
     335,    5, 1846,    2, 0x02 /* Public */,
     336,    1, 1857,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   11,   20,   21,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QStringList,   39,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   19,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   65,   17,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   69,   70,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   65,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   43,
    QMetaType::Void, 0x80000000 | 77,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   79,   80,   81,   82,   29,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   84,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   84,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   17,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   98,   99,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   94,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   94,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  106,  107,  108,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   17,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   94,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   94,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,  120,  121,  122,  123,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  128,  122,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  128,  122,
    QMetaType::Void, QMetaType::QVariant,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   92,   94,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,  139,
    QMetaType::Void, QMetaType::QJsonObject,  141,
    QMetaType::Void, QMetaType::QJsonObject,   47,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   65,   17,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  150,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::QString, QMetaType::QString,   26,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QJsonArray, QMetaType::Int,  154,  155,   32,  156,  123,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Long, QMetaType::QString, QMetaType::QString,   24,   25,   26,   27,   28,   29,   31,   30,   33,   34,
    QMetaType::QString, QMetaType::LongLong,  159,
    QMetaType::LongLong, QMetaType::QString,  161,
    QMetaType::QString, QMetaType::QString,  163,
    QMetaType::Void, QMetaType::LongLong,  159,
    QMetaType::Void, QMetaType::Bool,  166,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  168,  169,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  171,   11,  172,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  176,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,  182,
    QMetaType::Void, QMetaType::Int,   99,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  187,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  190,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  194,  195,
    QMetaType::Void, QMetaType::QString,  194,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  197,  195,
    QMetaType::Void, QMetaType::QString,  197,
    QMetaType::Void, QMetaType::QString,  199,
    QMetaType::Void, QMetaType::Int,  201,
    QMetaType::Void, QMetaType::Int,  203,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  206,  207,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  211,
    QMetaType::Void, QMetaType::Bool,  213,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,  216,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  219,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  221,  222,  223,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  221,  222,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  225,  221,  222,  223,  226,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  225,  221,  222,  223,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,  225,  221,  222,
    QMetaType::Void, QMetaType::QString,  225,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  182,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  182,   99,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,  156,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,  243,  195,
    QMetaType::Void, QMetaType::QString,  243,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  251,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  254,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int,  254,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  262,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  265,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  265,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  270,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  275,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  275,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  280,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  283,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  286,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,  289,  290,
    QMetaType::Int, QMetaType::Int,   24,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  293,   24,
    QMetaType::Void, QMetaType::Int,  293,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Bool,  290,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  300,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,  303,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  306,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  254,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Float,  312,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  319,  320,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  106,  107,
    QMetaType::Void, QMetaType::Int,  323,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  330,  331,  332,
    QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,   31,  334,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   79,   80,   81,   82,   29,
    QMetaType::Void, QMetaType::Int,   84,

       0        // eod
};

void MainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainController *_t = static_cast<MainController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startPlaceOrder(); break;
        case 1: _t->showPopupAfterPrint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->foodReset(); break;
        case 3: _t->foodUpdate((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 4: _t->foodSearching((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->paySucc((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 6: _t->payError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->notifySucc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 8: _t->addItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< long(*)>(_a[7])),(*reinterpret_cast< long long(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11]))); break;
        case 9: _t->cancelBillItem(); break;
        case 10: _t->cancellBillCloseQRDialog(); break;
        case 11: _t->updateAmount((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->scanDockDone((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 13: _t->dockConnectionChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->pingDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->loadingDone(); break;
        case 16: _t->telnetDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->telnetResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->wifiStatusDone((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->cloudConnectionChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->notifyFoodRequest(); break;
        case 22: _t->printDone((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 23: _t->dockStatistics((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->printerReadyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->paymentUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->paymentMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->updateShowthanhtoancungdonhang((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->cardPayment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->errorMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 30: _t->updateTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->onPayZalo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 32: _t->loginRequest(); break;
        case 33: _t->login((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 34: _t->baocaoRequest(); break;
        case 35: _t->idleTimeout(); break;
        case 36: _t->dominosData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 37: _t->dominosSetProdName((*reinterpret_cast< const QSet<QString>(*)>(_a[1]))); break;
        case 38: _t->removeItemPaymentView((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 39: _t->closePopup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 40: _t->closePopupSelectPizza((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 41: _t->onCancelDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 42: _t->onCancelError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 43: _t->onRejectDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 44: _t->onRejectError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 45: _t->onPayZaloDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 46: _t->onPayZaloError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 47: _t->onNotify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->onMifareFound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->onCenterServiceFound((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 50: _t->onFoodsDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 51: _t->onFoodsError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 52: _t->onUpdatedFoodsData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 53: _t->onCheckUpdateFoodsData((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 54: _t->onCheckUpdateFoodsDataError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 55: _t->onLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 56: _t->onLoginDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 57: _t->onLoginError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 58: _t->onBaocao(); break;
        case 59: _t->onBaocaoDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 60: _t->onBaocaoError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 61: _t->onAlertEmailDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 62: _t->onAlertEmailError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 63: _t->onAlertPhoneDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 64: _t->onAlertPhoneError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 65: _t->doPayCard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 66: { bool _r = _t->doGetPmsid((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 67: _t->onPmsidDoneZalo((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 68: _t->onPmsidDoneCash((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 69: _t->onPmsidError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 70: _t->doPayZalo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 71: _t->doPayCash((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 72: _t->onPayCashDone((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 73: _t->onPayCashError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 74: _t->foodsRequest(); break;
        case 75: _t->checkUpdateFoodData(); break;
        case 76: _t->timerStartUpdate(); break;
        case 77: _t->timerDoUpdate(); break;
        case 78: _t->timerReboot(); break;
        case 79: _t->timerSystemIdle(); break;
        case 80: _t->onStoreProducts((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 81: _t->onStoreInformation((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 82: _t->eventPlaceOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 83: _t->eventPlaceOrderErr((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 84: { bool _r = _t->isDebugmode();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 85: { bool _r = _t->isRaspberry();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 86: { bool _r = _t->isCashAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 87: { bool _r = _t->isCardAllowed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 88: _t->appQuit(); break;
        case 89: { bool _r = _t->searchFilter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 90: _t->searchFood((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 91: { QString _r = _t->viet2latin((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 92: { QString _r = _t->pay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonArray(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 93: _t->insertItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< long(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10]))); break;
        case 94: { QString _r = _t->formatMoney((*reinterpret_cast< long long(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 95: { long long _r = _t->getMoneyValue((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = _r; }  break;
        case 96: { QString _r = _t->moneyMoney((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 97: _t->updateTotalMoney((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 98: _t->updateCardWaitingPay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 99: _t->printBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 100: _t->cancelBill((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 101: _t->stopDevice(); break;
        case 102: { QString _r = _t->getPrinter();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 103: _t->setPrinter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 104: { QString _r = _t->getPayment();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 105: { QString _r = _t->getDominoServerUrl();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 106: { QString _r = _t->getHostTelnet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 107: { int _r = _t->getPortTelnet();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 108: _t->setHostTelnet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 109: _t->setPortTelnet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 110: { int _r = _t->getDominoStore();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 111: { QString _r = _t->getListEmail();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 112: _t->setListEmail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 113: { QString _r = _t->getListPhone();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 114: _t->setListPhone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 115: { QString _r = _t->getUrlService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 116: { QString _r = _t->getTransferProtocol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 117: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 118: _t->setTransferProtocol((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 119: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 120: _t->setPayment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 121: _t->setDominoServerUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 122: _t->setDominoStore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 123: _t->setPaymentMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 124: { int _r = _t->getPaymentMethod();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 125: _t->setPaymentMask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 126: { int _r = _t->getPaymentMask();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 127: { QString _r = _t->getDockServer();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 128: _t->setDockServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 129: _t->scanDock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 130: _t->scanDock(); break;
        case 131: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 132: { bool _r = _t->connectToDock((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 133: _t->disconnectFromDock(); break;
        case 134: _t->testReaderDevice((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 135: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 136: _t->updateWifi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 137: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 138: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 139: _t->updateWifiPi((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 140: _t->wifiStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 141: _t->wifiStatus(); break;
        case 142: _t->testPing((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 143: _t->testTelnet((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 144: _t->telnetDominoServer(); break;
        case 145: _t->killProcessTelnetDomino(); break;
        case 146: _t->doAlert(); break;
        case 147: _t->restartDock(); break;
        case 148: _t->restartPi(); break;
        case 149: _t->haltPi(); break;
        case 150: _t->checkPrinterStatus(); break;
        case 151: _t->printTest((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 152: { int _r = _t->getPrintStatus();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 153: { QString _r = _t->getLocalIp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 154: { int _r = _t->getAppIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 155: { QString _r = _t->getAppName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 156: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 157: _t->setAppName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 158: { QString _r = _t->getAppTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 159: { QString _r = _t->getTitleEng();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 160: _t->setAppTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 161: { int _r = _t->getMachineIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 162: { QString _r = _t->getAppMachine();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 163: { int _r = _t->getRechargeNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 164: _t->setRechargeNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 165: { int _r = _t->getFoodRefreshTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 166: _t->setFoodRefreshTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 167: { int _r = _t->getBillAlertTimer();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 168: { QString _r = _t->getGInvoiceCode();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 169: _t->setBillAlertTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 170: { bool _r = _t->getShowThanhtoancungdonhang();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 171: _t->setShowThanhtoancungdonhang((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 172: { QString _r = _t->getConfigQrcodeRatio();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 173: _t->setConfigQrcodeRatio((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 174: { int _r = _t->getConfigFoodItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 175: _t->setConfigFoodItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 176: { int _r = _t->getConfigBillItemFontsize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 177: _t->setConfigBillItemFontsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 178: { int _r = _t->getConfigSobanin();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 179: _t->setConfigSobanin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 180: { QString _r = _t->getConfigTenbanin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 181: _t->setConfigTenbanin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 182: { QString _r = _t->getConfigBillPreinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 183: _t->setConfigBillPreinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 184: { QString _r = _t->getConfigBillPostinf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 185: _t->setConfigBillPostinf((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 186: { QString _r = _t->getConfigDockversion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 187: _t->setConfigDockversion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 188: { QString _r = _t->getConfigPrintersize();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 189: _t->setConfigPrintersize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 190: { bool _r = _t->getUserEnableConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 191: _t->setUserEnableConfig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 192: { int _r = _t->getConfigRebootDatePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 193: _t->setConfigRebootDatePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 194: { int _r = _t->getConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 195: { int _r = _t->getConfigRebootTimePi();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 196: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 197: _t->setConfigRebootTimePi((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 198: { QString _r = _t->getRestartTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 199: { QString _r = _t->getCurrentTime((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 200: { QString _r = _t->getConfigUsername();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 201: { QString _r = _t->getConfigUserpwd();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 202: { bool _r = _t->getConfigSearchadvance();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 203: _t->setConfigSearchadvance((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 204: { bool _r = _t->getConfigShowBaocaoDate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 205: _t->setConfigShowBaocaoDate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 206: { QString _r = _t->getConfigCenterService();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 207: _t->setConfigCenterService((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 208: { int _r = _t->getConfigIdletime();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 209: _t->setConfigIdletime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 210: _t->setIdCoupon((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 211: { QString _r = _t->getIdCoupon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 212: _t->setIdCouponPercent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 213: { QString _r = _t->getIdCouponPercent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 214: _t->doPlaceOrderErr(); break;
        case 215: _t->saveConfig(); break;
        case 216: _t->sendCancelBillUI(); break;
        case 217: { QString _r = _t->getBaocaoCurrentTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 218: _t->inBaocao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 219: _t->userLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 220: _t->uiFoodupdateStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 221: { QString _r = _t->getAccount();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 222: { QString _r = _t->getDiskPrepare();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 223: { QString _r = _t->getDiskReserve();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 224: _t->idleClearup(); break;
        case 225: _t->idleReset(); break;
        case 226: { QString _r = _t->getProductCode((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 227: { long long _r = _t->getPriceCoupon((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< long long*>(_a[0]) = _r; }  break;
        case 228: _t->removeItemInPaymentView((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 229: _t->closeThanhtoan((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 37:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::startPlaceOrder)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::showPopupAfterPrint)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodReset)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::foodSearching)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & , int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paySucc)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::payError)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::notifySucc)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , long , long long , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::addItem)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cancelBillItem)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cancellBillCloseQRDialog)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateAmount)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::scanDockDone)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dockConnectionChange)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::pingDone)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::loadingDone)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::telnetDone)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::telnetResult)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::wifiStatusDone)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::showMessage)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cloudConnectionChange)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::notifyFoodRequest)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::printDone)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dockStatistics)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::printerReadyChanged)) {
                *result = 24;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paymentUpdate)) {
                *result = 25;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::paymentMask)) {
                *result = 26;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateShowthanhtoancungdonhang)) {
                *result = 27;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::cardPayment)) {
                *result = 28;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::errorMessage)) {
                *result = 29;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::updateTitle)) {
                *result = 30;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::onPayZalo)) {
                *result = 31;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::loginRequest)) {
                *result = 32;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::login)) {
                *result = 33;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::baocaoRequest)) {
                *result = 34;
                return;
            }
        }
        {
            typedef void (MainController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::idleTimeout)) {
                *result = 35;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dominosData)) {
                *result = 36;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(const QSet<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::dominosSetProdName)) {
                *result = 37;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::removeItemPaymentView)) {
                *result = 38;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::closePopup)) {
                *result = 39;
                return;
            }
        }
        {
            typedef void (MainController::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainController::closePopupSelectPizza)) {
                *result = 40;
                return;
            }
        }
    }
}

const QMetaObject MainController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainController.data,
      qt_meta_data_MainController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 230)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 230;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 230)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 230;
    }
    return _id;
}

// SIGNAL 0
void MainController::startPlaceOrder()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainController::showPopupAfterPrint(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainController::foodReset()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainController::foodUpdate(const QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainController::foodSearching(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainController::paySucc(const QString & _t1, const QString & _t2, int _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainController::payError(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainController::notifySucc(int _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainController::addItem(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6, long _t7, long long _t8, const QString & _t9, const QString & _t10, const QString & _t11)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainController::cancelBillItem()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void MainController::cancellBillCloseQRDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MainController::updateAmount(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainController::scanDockDone(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainController::dockConnectionChange(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainController::pingDone(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainController::loadingDone()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void MainController::telnetDone(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainController::telnetResult(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainController::wifiStatusDone(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainController::showMessage(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainController::cloudConnectionChange(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainController::notifyFoodRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}

// SIGNAL 22
void MainController::printDone(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainController::dockStatistics(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainController::printerReadyChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void MainController::paymentUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void MainController::paymentMask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void MainController::updateShowthanhtoancungdonhang(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void MainController::cardPayment(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void MainController::errorMessage(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void MainController::updateTitle(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void MainController::onPayZalo(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void MainController::loginRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 32, Q_NULLPTR);
}

// SIGNAL 33
void MainController::login(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void MainController::baocaoRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 34, Q_NULLPTR);
}

// SIGNAL 35
void MainController::idleTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 35, Q_NULLPTR);
}

// SIGNAL 36
void MainController::dominosData(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void MainController::dominosSetProdName(const QSet<QString> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void MainController::removeItemPaymentView(int _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void MainController::closePopup(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void MainController::closePopupSelectPizza(int _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}
QT_END_MOC_NAMESPACE
