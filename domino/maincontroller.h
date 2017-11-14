#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QJsonArray>
#include <QEvent>
#include <QProcess>
#include <QSet>
#include "http/httpbase.h"
#include "http/httpbase2.h"
#include "../common/wscssclient.h"
#include "../common/deviceclientservice.h"
#include "wsclient.h"
#include "downloadfileman.h"
#include "dominocontroller.h"
#include "billdetail.h"

#define PAY_ZALO 1
#define PAY_CARD 2
#define PAY_CASH 4

#define LOGIN_NONE          0
#define LOGIN_WAITLOGIN     1
#define LOGIN_READY         2
#define BAOCAO_WAITING      3
#define BAOCAO_READY        4
#define FUPDATE_NONE        0
#define FUPDATE_PROG1       1
#define FUPDATE_PROG2       2
#define FUPDATE_BUSY        (FUPDATE_NONE + FUPDATE_PROG1 + FUPDATE_PROG2)
#define FOOD_SEARCHING      4

//login & baocao processing status ...
//0: do not login
//1: loging and waiting respone from server
//2: already logined
//3: bao cao waiting respone from server
//4: bao cao respone

class ConfigSetting;
class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = 0);
    ~MainController();

    Q_INVOKABLE bool    isDebugmode();
    Q_INVOKABLE bool    isRaspberry();
    Q_INVOKABLE bool    isCashAllowed();
    Q_INVOKABLE bool    isCardAllowed();
    Q_INVOKABLE void    appQuit();

    Q_INVOKABLE bool searchFilter(const QString& foodname, const QString& srchtxt);
    Q_INVOKABLE void searchFood(const QString& srchtxt);
    Q_INVOKABLE QString viet2latin(const QString &name);

    Q_INVOKABLE QString pay(const QString &customer_name, const QString &customer_hinhthuc, const QString& amount, const QJsonArray &foods, int payMethod);

    // thêm món ăn vào danh sách hóa đơn
    Q_INVOKABLE void insertItem(const QString& type, const QString& code_name, const QString& name, const QString& size, const QString& debanh, const QString& phomai, const QString& price, long quantity, const QString &oriprice, const QString &promtype);

    Q_INVOKABLE QString formatMoney(long long moneyValue);
    Q_INVOKABLE long long getMoneyValue(const QString &moneyString);
    // format string tiền, thêm dấu ','
    Q_INVOKABLE QString moneyMoney(QString money);

    Q_INVOKABLE void updateTotalMoney(long long moneyValue);
    Q_INVOKABLE void updateCardWaitingPay(bool waiting);

    Q_INVOKABLE void printBill(const QString& ivcode, const QString &printData);
    Q_INVOKABLE void cancelBill(const QString& foId, const QString &invcecode, const QString& total);

    Q_INVOKABLE void stopDevice();

    Q_INVOKABLE QString getPrinter();
    Q_INVOKABLE void setPrinter(QString prnName);
    Q_INVOKABLE QString getPayment();
    Q_INVOKABLE QString getDominoServerUrl();
    Q_INVOKABLE QString getHostTelnet();
    Q_INVOKABLE int  getPortTelnet();
    Q_INVOKABLE void setHostTelnet(QString host);
    Q_INVOKABLE void setPortTelnet(int port);
    Q_INVOKABLE int getDominoStore();
    Q_INVOKABLE QString getListEmail();
    Q_INVOKABLE void setListEmail(QString listemail);
    Q_INVOKABLE QString getListPhone();
    Q_INVOKABLE void setListPhone(QString listphone);
    Q_INVOKABLE QString getUrlService();
    Q_INVOKABLE QString getTransferProtocol();
    Q_INVOKABLE void setTransferProtocol(const QString& transpro, bool initSocket=true);
    Q_INVOKABLE void setPayment(QString paymentName, bool initSocket=true);
    Q_INVOKABLE void setDominoServerUrl(QString url);
    Q_INVOKABLE void setDominoStore(int store);
    Q_INVOKABLE void setPaymentMethod(int paymentMethod); // 1:zalopay; 2:card; 4:cash
    Q_INVOKABLE int  getPaymentMethod();
    Q_INVOKABLE void setPaymentMask(int payment, bool onoff);
    Q_INVOKABLE int  getPaymentMask();

    Q_INVOKABLE QString getDockServer();
    Q_INVOKABLE void setDockServer(QString dockServer);

    Q_INVOKABLE void scanDock(bool doAuto=false);
    Q_INVOKABLE bool isConnected();
    Q_INVOKABLE bool connectToDock(const QString& serverIp);
    Q_INVOKABLE void disconnectFromDock();
    Q_INVOKABLE void testReaderDevice(bool run);
    Q_INVOKABLE void updateWifi(const QString &ssid, const QString &key, const QString &encrypt = QString("psk2-mixed"));
    Q_INVOKABLE void updateWifiPi(const QString& interface, const QString &ssid, const QString &key, const QString &encrypt = QString("psk2-mixed"), bool scan_ssid = false);
    Q_INVOKABLE void wifiStatus(const QString& interface = QString("wlan0"));
    Q_INVOKABLE void testPing(const QString& host);
    Q_INVOKABLE void testTelnet(const QString& host, int port);
    Q_INVOKABLE void telnetDominoServer();
    Q_INVOKABLE void killProcessTelnetDomino();
    Q_INVOKABLE void doAlert();
    Q_INVOKABLE void restartDock();
    Q_INVOKABLE void restartPi();
    Q_INVOKABLE void haltPi();
    Q_INVOKABLE void checkPrinterStatus();

    Q_INVOKABLE void printTest(const QJsonArray &foods);

    Q_INVOKABLE QString getLocalIp();

    Q_INVOKABLE int     getAppIndex();
    Q_INVOKABLE QString getAppName();
    Q_INVOKABLE void    setAppName(const QString &appName, bool initSocket=true);
    Q_INVOKABLE QString getAppTitle();
    Q_INVOKABLE QString getTitleEng();
    Q_INVOKABLE void    setAppTitle(const QString &title);
    Q_INVOKABLE int     getMachineIndex();
    Q_INVOKABLE QString getAppMachine();
    Q_INVOKABLE int     getRechargeNum();
    Q_INVOKABLE void    setRechargeNum(int mcNum);

    Q_INVOKABLE int     getFoodRefreshTimer();
    Q_INVOKABLE void    setFoodRefreshTimer(int timer);
    Q_INVOKABLE int     getBillAlertTimer();
    Q_INVOKABLE void    setBillAlertTimer(int timer);
    Q_INVOKABLE bool    getShowThanhtoancungdonhang();
    Q_INVOKABLE void    setShowThanhtoancungdonhang(bool isShow);
    Q_INVOKABLE QString getConfigQrcodeRatio();
    Q_INVOKABLE void    setConfigQrcodeRatio(float ratio);
    Q_INVOKABLE int     getConfigFoodItemFontsize();
    Q_INVOKABLE void    setConfigFoodItemFontsize(int fntsize);
    Q_INVOKABLE int     getConfigBillItemFontsize();
    Q_INVOKABLE void    setConfigBillItemFontsize(int fntsize);
    Q_INVOKABLE int     getConfigSobanin();
    Q_INVOKABLE void    setConfigSobanin(int num);
    Q_INVOKABLE QString getConfigTenbanin();
    Q_INVOKABLE void    setConfigTenbanin(const QString &name);
    Q_INVOKABLE QString getConfigBillPreinf();
    Q_INVOKABLE void    setConfigBillPreinf(const QString &info);
    Q_INVOKABLE QString getConfigBillPostinf();
    Q_INVOKABLE void    setConfigBillPostinf(const QString &info);
    Q_INVOKABLE QString getConfigDockversion();
    Q_INVOKABLE void    setConfigDockversion(const QString &version);
    Q_INVOKABLE QString getConfigPrintersize();
    Q_INVOKABLE void    setConfigPrintersize(const QString &pagesize);
    Q_INVOKABLE bool    getUserEnableConfig();
    Q_INVOKABLE void    setUserEnableConfig(bool enableconf);
    Q_INVOKABLE int     getConfigRebootDatePi();
    Q_INVOKABLE void    setConfigRebootDatePi(int dayofweek, bool on);
    Q_INVOKABLE int     getConfigRebootTimePi(int type=0);
    Q_INVOKABLE void    setConfigRebootTimePi(int value, int type=0);
    Q_INVOKABLE QString getRestartTime();
    Q_INVOKABLE QString getCurrentTime(bool on);
    Q_INVOKABLE QString getConfigUsername();
    Q_INVOKABLE QString getConfigUserpwd();
    Q_INVOKABLE bool    getConfigSearchadvance();
    Q_INVOKABLE void    setConfigSearchadvance(bool searchadvance);
    Q_INVOKABLE bool    getConfigShowBaocaoDate();
    Q_INVOKABLE void    setConfigShowBaocaoDate(bool showDate);
    Q_INVOKABLE QString getConfigCenterService();
    Q_INVOKABLE void    setConfigCenterService(const QString &centerServiceIp);
    Q_INVOKABLE int     getConfigIdletime();
    Q_INVOKABLE void    setConfigIdletime(int timer);
    Q_INVOKABLE void    setIdCoupon(const QString & id);
    Q_INVOKABLE QString getIdCoupon();
    Q_INVOKABLE void    setIdCouponPercent(float percent);
    Q_INVOKABLE QString getIdCouponPercent();

    Q_INVOKABLE void saveConfig();
    Q_INVOKABLE void sendCancelBillUI();

    Q_INVOKABLE QString getBaocaoCurrentTime();
    Q_INVOKABLE void inBaocao(const QString &date, int bcType);
    Q_INVOKABLE void userLogin(const QString &uname, const QString &pwd);
    Q_INVOKABLE void uiFoodupdateStatus(int uiType);

    Q_INVOKABLE QString getAccount();

    // funcs for Kitchen ...
    Q_INVOKABLE QString getDiskPrepare();
    Q_INVOKABLE QString getDiskReserve();

    Q_INVOKABLE void    idleClearup() { emit cancelBillItem(); }
    Q_INVOKABLE void    idleReset() { m_lastTimeActivity = (QDateTime::currentMSecsSinceEpoch()); }
    Q_INVOKABLE QString getProductCode(const QString &pro_name, const QString &prod_size, const QString &prod_plavor_code);
    Q_INVOKABLE long long getPriceCoupon(long long price, const QString& pizza_size);
    Q_INVOKABLE void    removeItemInPaymentView(int row, const QString& prod_type, const QString& size_banh, const QString& de_banh, const QString& phomai);
    Q_INVOKABLE void    closeThanhtoan(int popupid);
    virtual bool eventFilter(QObject *watched, QEvent *event) {
        if( event->type() == QEvent::KeyPress ||
            event->type() == QEvent::MouseMove )
        {
            // reset event timer!
            m_lastTimeActivity = (QDateTime::currentMSecsSinceEpoch());

            return QObject::eventFilter(watched, event);
        }
    }

signals:
    void foodReset();
    void foodUpdate(const QVariant menus);
    void foodSearching(const QString& srchtxt);
    void paySucc(const QString& invcecode, const QString& qrcode, int discount, const QString& oripay, const QString& discpay);
    void payError(const QString& msg);
    void notifySucc(int errcode, const QString& invcecode, const QString& invcetime, const QString& barcode, const QString &balance);
    void addItem(const QString& type, const QString& code_name, const QString& name, const QString& size, const QString& debanh, const QString& phomai, long quantity, long long price, const QString& amount, const QString &oriprice, const QString &promtype);
    void cancelBillItem();
    void cancellBillCloseQRDialog();
    void updateAmount(const QString& amount);
    void scanDockDone(const QStringList& listDock);
    void dockConnectionChange(bool connected);
    void pingDone(const QString& data);
    void loadingDone();
    void telnetDone(const QString& data);
    void telnetResult(bool result);
    void wifiStatusDone(const QString& data);

    void showMessage(const QString& msg);
    void cloudConnectionChange(bool connected);
    void notifyFoodRequest();
    void printDone(quint16 errcode);
    void dockStatistics(const QString& stat);

    void printerReadyChanged(bool ready);

    // update payment method UI
    void paymentUpdate(int methods);
    void paymentMask(int paymentMask);
    void updateShowthanhtoancungdonhang(bool isShow);

    void cardPayment(const QString &cardId);
    void errorMessage(int err, const QString &msg);
    void updateTitle(const QString &title);

    void onPayZalo(const QString &sesid, const QString &biid);

    void loginRequest();
    void login(int err, const QString& msg);
    void baocaoRequest();

    void idleTimeout();


    void dominosData(const QJsonObject &data);
    void dominosSetProdName(const QSet<QString> &data);
    void removeItemPaymentView(int row, const QString& prod_type, const QString& size_banh, const QString& de_banh, const QString& phomai);
    void closePopup(int popupid, const QString& msg);
    void closePopupSelectPizza(int popupid, const QString& msg);
public slots:
    void onCancelDone(const QVariant &data);
    void onCancelError(const int&, const QString&);
    void onRejectDone(const QVariant &data);
    void onRejectError(const int&, const QString&);
    void onPayZaloDone(const QVariant &data);
    void onPayZaloError(const int &error, const QString &msg);
    void onNotify(const QString &message);
    void onMifareFound(const QString id);
    void onCenterServiceFound(const QString &ip, const int &port);
    void onFoodsDone(const QVariant &data);
    void onFoodsError(const int &error, const QString &message);
    void onUpdatedFoodsData(const QString &message);
    void onCheckUpdateFoodsData(const QVariant &data);
    void onCheckUpdateFoodsDataError(const int &error, const QString &message);

    void onLogin(const QString &uname, const QString &pwd, bool isBaocao);
    void onLoginDone(const QVariant &data);
    void onLoginError(const int &error, const QString &msg);
    void onBaocao();
    void onBaocaoDone(const QVariant &data);
    void onBaocaoError(const int &error, const QString &msg);
    void onAlertEmailDone(const QVariant &data);
    void onAlertEmailError(const int &error, const QString &message);
    void onAlertPhoneDone(const QVariant &data);
    void onAlertPhoneError(const int &error, const QString &message);

    // vpos: nhận tín hiệu quẹt thẻ thanh toán
    void doPayCard(const QString &cardId);

    // get payment sid
    bool doGetPmsid(const QString &merchantCode, const QString& devId, const QString& biId, int payMethod);
    void onPmsidDoneZalo(const QVariant &data);
    void onPmsidDoneCash(const QVariant &data);
    void onPmsidError(const int error, const QString &msg);
    void doPayZalo(const QString &sesId, const QString &biId);
    void doPayCash(const QString &sesId, const QString &biId);
    void onPayCashDone(const QVariant &data);
    void onPayCashError(const int &error, const QString &message);

    // cập nhật danh sách foods từ máy chủ
    void foodsRequest();
    void checkUpdateFoodData();

    void timerStartUpdate();
    void timerDoUpdate();
    void timerReboot();
    void timerSystemIdle();

    void onStoreProducts(const QJsonObject &storeProducts);
    void onStoreInformation(const QJsonObject &storeInformation);
    void eventPlaceOrder(const QJsonObject &result);
    void eventPlaceOrderErr(const QString &err);
private:
    void alertPhone(const QString & listphone, const QString & content);
    void alertEmail(const QString & listemail, const QString & branch, const QString & host, int port);
    void placeorder2dominoserver();
    void doScanDock();
    void doScanDockAutosetting();
    void doPing(const QString& host);
    void doTelnet(const QString& host, int port);
    void doTelnetDomino(const QString& host, int port);
    void doWifiStatus(const QString& interface);
    void updateWSServerIp();
    void initialWebSocket(bool forceStop=false);
    void initialWsCssClient();
    void rejectInvoice(const QString invceCode);
    bool checkToken(const QString& data, const QString& token, const QString key);

    QString xorstr(const QString& s);

    void sortPairList(QList<QPair<QString, QString> > &pl);

    // tạo bản in cho foodcourt
    QByteArray createPrintFoodcourt(const QString& fooddata,
                                    const QString &billPreinf="",
                                    const QString &billPostinf="",
                                    const QString &banin="",
                                    bool cutpageSeperate=true);
    QByteArray createPrintBaocao(const QString& baocao, int bcType, bool bDetail);
    void printBigData(const QByteArray& data);

private:
    DominoController    dominoCtrl;
    HttpBase*           payZalo;
    HttpBase*           httppayCash;
    HttpBase*           httpcancel;
    HttpBase*           httpreject;
    HttpBase*           httpfood;
    HttpBase*           httpalertemail;
    HttpBase*           httpalertphone;
    HttpBase*           httppmsid;
    HttpBase2*          http2;
    HttpBase2*          httpBaocao;

    WSClient            *wsClient;
    WsCssClient         *wscssClient;

    QString             m_cardID;

    DeviceClientService *deviceService;
    ConfigSetting       *setting;
    QString             deviceId;

    CDownloadFileMan    m_DFMan;
    qulonglong          m_qullLUT;
    QTimer              m_tmCheckUpdateFood;
    QTimer              m_rebootTimer;

    HttpBase*           m_httpCheckUpdate;
    int                 m_fupdatestatus;

    QDateTime           m_startTime;

    qint64              m_lastTimeActivity;
    QTimer              m_idleTimer;

    CBillDetail m_Bills;    // ds hoa don cho thanh toan

    QString sid_amount;
    QString sid_cardid;
    int sid_paymod;
    int     m_progstatus;   // login & baocao processing status
    QString m_bcDate;       // date bao cao "" or "2017-03-24"
    int     m_bcType;       // baocaoX=0, baocaoZ=1, baocaoDetail=2
    QString m_usrPwd;       // user's login password
    bool    m_login4Baocao;
    QProcess* ps_telnet_domino;
public:
    QString httpTranspro;   // http / https
    QString wsTranspro;     // ws / wss
    QString appTitle;       // "Canteen VNG"
    QString merchantCode;   // "vpos"
    QString machineName;    // "May-1"
    bool    cardWaitingPay; // đang chờ thanh toán ...

private:
    QString cmd_apiitem;
    QString cmd_appinvce;
    QString cmd_getlastupdate;
    QString cmd_getlist;
    QString cmd_getsession;
    QString cmd_paymentsuccess;
    QString cmd_token;

    QString gVPOS1();
private:
    QString m_customer_name;
    QString m_customer_hinhthuc;
    QJsonArray m_foods;
    QJsonArray m_prods_from_dominos;
    QString dominoUrl;
    int     dominoStore;
private:
    QString g_invceCode;
    QString g_printdata;
    QString g_invceDate;
    QString g_barcode;
    QString g_balance;
    QString g_storeOrderID;
};

#endif // MAINCONTROLLER_H
