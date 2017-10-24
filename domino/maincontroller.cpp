#include "maincontroller.h"
#include "commonfunction.h"
#include "../common/prntdataformat.h"
#include "../common/configsetting.h"
#include <QDebug>
#include <QUrl>
#include <QThread>
#include <QMessageBox>
#include <QtConcurrent>
#include <QNetworkInterface>
#include <QGuiApplication>
#include <QJsonObject>
#include <QSet>
#ifdef Q_OS_ANDROID
#include <QtAndroidExtras>
#endif

// gia lap thanh toan zalopay
// http://dev.zing.vn:8585/vpos/payment/callback/?iv=1612140004

#define REBOOT_INTERVAL 5   // 5 minutes

MainController::MainController(QObject *parent)
    : QObject(parent)
    , deviceService(Q_NULLPTR)
    , m_tmCheckUpdateFood(this)
    , machineName("DOMINOS PIZZA")
    , cardWaitingPay(false)
    , httpTranspro("")
    , m_progstatus(LOGIN_NONE)
    , m_fupdatestatus(FUPDATE_NONE)
    , wscssClient(Q_NULLPTR)
{
    cmd_apiitem         = QString("/api/item/?");
    cmd_appinvce        = QString("/api/invoice/");
    cmd_getlist         = QString("getlist");
    cmd_getsession      = QString("get_session");
    cmd_paymentsuccess  = QString("payment_success");
    cmd_getlastupdate   = QString("get_last_update");

    cmd_token = CommonFunction::gVPOS1();

    httppmsid = NULL;
    http2 = NULL;
    httpBaocao = NULL;

    wsClient = 0;
    deviceId = QString(QUuid::createUuid().toRfc4122().toHex());

    setting = new ConfigSetting(false, this);
    setTransferProtocol(setting->transProtocol, false);
    merchantCode = setting->appName;
    appTitle = setting->appTitle;

    if (!setting->dockServer.isEmpty()) {
        qDebug() << "Found dock server config: " << setting->dockServer;
        connectToDock(setting->dockServer);
    } else {
        qDebug() << "Not found dock server config, do auto scan Dock ...";
        doScanDockAutosetting();
    }

//    machineName = QString("MAY-%1").arg(getRechargeNum()+1);
    machineName = "DOMINOS PIZZA";

    httpfood = NULL;
    payZalo = NULL;
    httpcancel = NULL;

    m_qullLUT = 0;
    m_httpCheckUpdate = NULL;
    dominoStore = setting->dominoStore;
    qDebug() << "domino store: " << QString::number(dominoStore);
    QObject::connect(this, SIGNAL(notifyFoodRequest()), this, SLOT(foodsRequest()), Qt::QueuedConnection);
    QObject::connect(&m_tmCheckUpdateFood, SIGNAL(timeout()), this, SLOT(timerDoUpdate()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(onPayZalo(QString,QString)), this, SLOT(doPayZalo(QString,QString)));
    QObject::connect(this, SIGNAL(baocaoRequest()), this, SLOT(onBaocao()), Qt::QueuedConnection);

    QObject::connect(&dominoCtrl, SIGNAL(eventStoreProducts(QJsonObject)), this, SLOT(onStoreProducts(QJsonObject)), Qt::UniqueConnection);
    QObject::connect(&dominoCtrl, SIGNAL(eventStoreInformation(QJsonObject)), this, SLOT(onStoreInformation(QJsonObject)), Qt::UniqueConnection);
    dominoUrl = setting->dominoServerUrl; //http://113.161.67.179:59101
    dominoCtrl.initizalize("TestingAndSupport", "supp0rtivemeasures", dominoUrl);
    dominoCtrl.getStoreProducts(dominoStore);
    dominoCtrl.getStoreInformation(dominoStore);

    if (!isDebugmode()) {
        m_tmCheckUpdateFood.start(setting->foodRefreshTimer*1000);
    }

    m_startTime = QDateTime::currentDateTimeUtc().toTimeZone(QTimeZone("Asia/Ho_Chi_Minh"));

    if( setting->rebootDate )
    {      
        QObject::connect(&m_rebootTimer, SIGNAL(timeout()), SLOT(timerReboot()));
        m_rebootTimer.start(REBOOT_INTERVAL * 60000);
    }

    qDebug() << "Local IP:" << getLocalIp();

    initialWebSocket();
    initialWsCssClient();

    emit notifyFoodRequest();

    // catch event filter
    qGuiApp->installEventFilter(this);

    QObject::connect(&m_idleTimer, SIGNAL(timeout()), this, SLOT(timerSystemIdle()));
    m_idleTimer.start(3000); // 3000 = 3 second
    m_lastTimeActivity = QDateTime::currentMSecsSinceEpoch();
}

MainController::~MainController()
{
    if ( setting ) {
        delete setting;
    }

    m_tmCheckUpdateFood.stop();

    if (deviceService) {
        deviceService->stopService();
        delete deviceService;
    }

    if (wsClient)
    {
        wsClient->stop();
        wsClient->wait();
    }
}

bool MainController::isDebugmode()
{
#ifdef QT_DEBUG
    return true;
#endif

    return false;
}

bool MainController::isRaspberry()
{
#ifdef USE_VT_KB
    return true;
#endif

    return false;
}

bool MainController::isCashAllowed()
{
    return ((merchantCode.compare("vpos") == 0) ||
            (merchantCode.compare("mqshops") == 0));
}

bool MainController::isCardAllowed()
{
    return ((merchantCode.compare("vpos") == 0));
}

void MainController::appQuit()
{
    qApp->quit();
}

QString MainController::getAccount()
{
    QList<QPair<QString, QString> > acclist;

//    acclist.append(QPair<QString, QString>("vpos",          "Máy Bán Hàng"));
//    acclist.append(QPair<QString, QString>("canteenvng",    "Căn Tin VNG"));
//    acclist.append(QPair<QString, QString>("maybanhangtudong", "Máy Bán Hàng Tự Động"));

    acclist.append(QPair<QString, QString>("ffbanhmique",   "Bánh Mì Que"));
    acclist.append(QPair<QString, QString>("ffcobonla",     "Cỏ Bốn Lá"));
    acclist.append(QPair<QString, QString>("ffcomtamcali",  "Cơm Tấm Cali"));
    acclist.append(QPair<QString, QString>("ffcomngon",     "Cơm Ngon"));
    acclist.append(QPair<QString, QString>("ffcomnieu",     "Cơm Niêu"));
    acclist.append(QPair<QString, QString>("ffcool",        "COoooL"));
    acclist.append(QPair<QString, QString>("ffdorayaki",    "Dorayaki"));
    acclist.append(QPair<QString, QString>("ffphongoon",    "Phở Ngon"));
    acclist.append(QPair<QString, QString>("fftapicocup",   "Tapico Cup"));
    acclist.append(QPair<QString, QString>("fftokyobowl",   "Tokyo Bowl"));
    acclist.append(QPair<QString, QString>("ffvietthai",    "Việt Thái"));

    acclist.append(QPair<QString, QString>("ffhvbunsaigon", "Bún Sài Gòn"));
    acclist.append(QPair<QString, QString>("ffhvcomngon",   "Cơm Ngon"));
    acclist.append(QPair<QString, QString>("ffhvhighland",  "Hightland"));
    acclist.append(QPair<QString, QString>("ffhvlaucongchua","Lẩu Công Chúa"));
    acclist.append(QPair<QString, QString>("ffhvreddot",    "Reddot"));
    acclist.append(QPair<QString, QString>("ffhvreddot02",  "Reddot 02"));
    acclist.append(QPair<QString, QString>("ffhvtapio",     "Tapico"));
    acclist.append(QPair<QString, QString>("ffhvvietsin",   "Vietsin"));
    acclist.append(QPair<QString, QString>("ffhvinoodi",    "Vinoodi"));
    acclist.append(QPair<QString, QString>("ffhvsavoure",   "Savoure"));
    acclist.append(QPair<QString, QString>("ffhvnhatthienyen","Nhatthienyen"));
    acclist.append(QPair<QString, QString>("ffhvcomtamcali","Cơm Tấm Cali"));
    acclist.append(QPair<QString, QString>("ffhvbanhmyque", "Bánh Mì Que"));
    acclist.append(QPair<QString, QString>("ffhvphongon",   "Phở Ngon"));
    acclist.append(QPair<QString, QString>("ffhvdorayaki",  "Dorayaki"));
    acclist.append(QPair<QString, QString>("ffhvhotto01",   "Hotto"));
    acclist.append(QPair<QString, QString>("ffhvmochi",     "Mochi"));
    acclist.append(QPair<QString, QString>("ffhvvietthai",  "Việt Thái"));
    acclist.append(QPair<QString, QString>("ffhvfutayaki",  "Futayaki"));
    acclist.append(QPair<QString, QString>("ffhvbudsicecream","Budsicecream"));
    acclist.append(QPair<QString, QString>("ffhvpepperlunch","Pepper Lunch"));
    acclist.append(QPair<QString, QString>("ffhvothuong",   "Vothuong"));
    acclist.append(QPair<QString, QString>("ffhv99juice",   "99 Juice"));
    acclist.append(QPair<QString, QString>("ffhvcocosushi", "Coco Sushi"));
    acclist.append(QPair<QString, QString>("ffhvtokyo",     "Tokyo"));
    acclist.append(QPair<QString, QString>("ffhvbap",       "Bắp"));
    acclist.append(QPair<QString, QString>("ffhvyetgol",    "Yeygol"));
    acclist.append(QPair<QString, QString>("ffhvcool",      "Cool"));
    acclist.append(QPair<QString, QString>("ffhvmrdee01",   "Mr Dee"));
    acclist.append(QPair<QString, QString>("fhvlavida",     "Lavida"));
    acclist.append(QPair<QString, QString>("maybanhangtudong",     "Máy bán hàng"));
    acclist.append(QPair<QString, QString>("dominos",     "Máy bán hàng"));

    sortPairList(acclist);

    QJsonArray jsarr;
    QJsonObject jso;

    for (int i=0; i<acclist.size(); i++) {
        jso["accid"] = acclist.at(i).first;
        jso["accname"] = acclist.at(i).second;
        jsarr.append(jso);
    }

    QJsonDocument doc(jsarr);
    return QString::fromUtf8(doc.toJson().data());
}

bool MainController::searchFilter(const QString& foodname, const QString& srchtxt)
{
    //qDebug() << "searchFilter:" << srchtxt;

    bool bret = foodname.contains(srchtxt);

    if ( !bret && setting->searchAdvance )
    {
        // tiếp tục tìm nâng cao nếu chưa tìm thấy ...
        QStringList fdnmlst = foodname.split(QRegExp(" "));

        bool bfound = true;

        // duyệt từng ký tự chuỗi tìm kiếm, ngưng khi không tìm thấy
        for (int i=0; i<srchtxt.length() && bfound; i++)
        {
            if (srchtxt[i] != ' ')
            {
                bfound = false;

                // duyệt tên món ăn, ngưng khi đã tìm thấy rồi
                for (int j=0; j<fdnmlst.length(); j++)
                {
                    QString word = fdnmlst.at(j);
                    if ( !word.isEmpty() )
                    {
                        if (word[0] == srchtxt[i])
                        {
                            // bỏ từ tìm thấy ra khỏi foodname
                            fdnmlst.removeAt(j);
                            bfound = true;
                            break;
                        }
                    }
                }
            }
        }

        bret = bfound;
    }

    return bret;
}

void MainController::searchFood(const QString& srchtxt)
{
    emit foodSearching(srchtxt);
}

QString MainController::viet2latin(const QString &name)
{
    QString txt = CommonFunction::ViettoLatin(name).toLower();

    while ( (txt.length() > 0) && (txt.at(0) == ' ') ) {
        txt = txt.remove(0, 1);
    }
    while ( (txt.length() > 0) && (txt.at(txt.length()-1) == ' ') ) {
        txt = txt.remove(txt.length()-1, 1);
    }

    return txt;
}

void MainController::timerStartUpdate()
{
    if (!m_tmCheckUpdateFood.isActive() ) {
        m_tmCheckUpdateFood.start(setting->foodRefreshTimer*1000);
    } else {
        // nếu thời gian refresh thay đổi thì lấy lại thời gian mới
        if (m_tmCheckUpdateFood.interval() != setting->foodRefreshTimer*1000) {
            m_tmCheckUpdateFood.setInterval(setting->foodRefreshTimer*1000);
        }
    }
}

void MainController::timerDoUpdate()
{
    if ( (m_httpCheckUpdate == NULL) &&
         (m_fupdatestatus == FUPDATE_NONE) )
    {
        checkUpdateFoodData();
    }
}

void MainController::timerReboot()
{   
    QDateTime dt = QDateTime::currentDateTimeUtc().toTimeZone(QTimeZone("Asia/Ho_Chi_Minh"));

    int dayreboot = 1 << (dt.date().dayOfWeek() % 7);
    if( dayreboot == (dayreboot & setting->rebootDate) )
    {
        int t1 = dt.time().hour()*60 + dt.time().minute();
        int t2 = t1 + REBOOT_INTERVAL;

        if( (setting->rebootTime >= t1) && (setting->rebootTime < t2) )
        {
            qDebug() << "schedule to restart Pi, " << QTime::currentTime();
            restartPi();
        }
    }
}

void MainController::timerSystemIdle()
{
    if( (setting->idleTimer > 0) &&
        ((QDateTime::currentMSecsSinceEpoch() - m_lastTimeActivity) > setting->idleTimer) )
    {
        emit idleTimeout();
    }
}

// lấy menu foods từ máy chủfoodsRequest
void MainController::foodsRequest()
{
    //qDebug() << "=============== Food menu request ...";

    m_fupdatestatus |= FUPDATE_BUSY;

    httpfood = new HttpBase(QString(""),this);
    QObject::connect(httpfood, SIGNAL(done(QVariant)), this, SLOT(onFoodsDone(QVariant)), Qt::UniqueConnection);
    QObject::connect(httpfood, SIGNAL(error(int,QString)), this, SLOT(onFoodsError(int, QString)), Qt::UniqueConnection);

    httpfood->setUrl(QUrl(httpTranspro + "://" + getPayment() + cmd_apiitem));
    httpfood->addParameter("cm", cmd_getlist, true);
    httpfood->addParameter("dt", CommonFunction::formatRequestFoods(merchantCode));
    httpfood->process();
}

void MainController::onFoodsDone(const QVariant &data)
{
    //qDebug() << "Food Menu:" + data.toString();
    CommonFunction::parseDataFoods(data.toString(), m_DFMan, m_qullLUT);
    QObject::connect(&m_DFMan, SIGNAL(NotifyComplete(QString)), this, SLOT(onUpdatedFoodsData(QString)), Qt::UniqueConnection);
    m_DFMan.SetData(data.toString());
    m_DFMan.StartDownload();

    httpfood->deleteLater();
    httpfood = NULL;
    m_fupdatestatus &= ~FUPDATE_BUSY;
}

void MainController::onFoodsError(const int &error, const QString &message)
{
    // query menu food list from server fail
    qDebug() << "Food Menu error:" << error << ", msg:" << message;

    httpfood->deleteLater();
    httpfood = NULL;
    m_fupdatestatus &= ~FUPDATE_BUSY;
}

void MainController::onUpdatedFoodsData(const QString &data)
{
    QString dataUpdated = CommonFunction::updateDataFoods(data, m_DFMan);

    //qDebug() << "Begin update items UI, time:" << QDateTime::currentMSecsSinceEpoch();

    emit foodUpdate(QVariant(dataUpdated));
}

void MainController::uiFoodupdateStatus(int uiType)
{
    if (m_fupdatestatus >= uiType) {
        m_fupdatestatus -= uiType;

        //if (uiType < 3 && m_fupdatestatus == 0) {
        //    qDebug() << "Done update items UI, time:" << QDateTime::currentMSecsSinceEpoch();
        //}
    }
    else {
        m_fupdatestatus = FUPDATE_NONE;

        static bool bfirst = true;

        if (bfirst && !isConnected()) {
            doScanDockAutosetting();
        }

        bfirst = false;
    }
}

void MainController::checkUpdateFoodData()
{
    //qDebug() << "==== Check update food data ...";

    if ( (m_httpCheckUpdate == NULL) &&
         (m_fupdatestatus == FUPDATE_NONE) )
    {
        m_fupdatestatus |= FUPDATE_BUSY;

        m_httpCheckUpdate = new HttpBase(QString(""),this);
        m_httpCheckUpdate->setUrl(QUrl(httpTranspro + "://" + getPayment() + cmd_apiitem));
        m_httpCheckUpdate->addParameter("cm", cmd_getlastupdate, true);
        m_httpCheckUpdate->addParameter("dt", CommonFunction::formatRequestFoods(merchantCode));

        QObject::connect(m_httpCheckUpdate, SIGNAL(done(QVariant)), this, SLOT(onCheckUpdateFoodsData(QVariant)));
        QObject::connect(m_httpCheckUpdate, SIGNAL(error(int,QString)), this, SLOT(onCheckUpdateFoodsDataError(int, QString)), Qt::UniqueConnection);

        m_httpCheckUpdate->process();
    }
}

void MainController::onCheckUpdateFoodsData(const QVariant &data)
{
    m_httpCheckUpdate->deleteLater();
    m_httpCheckUpdate = NULL;
    m_fupdatestatus &= ~FUPDATE_BUSY;

    qulonglong qullLastUpdateTime = 0;
    CommonFunction::getLastUpdateTime(data.toString(), qullLastUpdateTime);
    if (qullLastUpdateTime != 0 && qullLastUpdateTime != m_qullLUT)
    {
        emit notifyFoodRequest();
    }
}

void MainController::onCheckUpdateFoodsDataError(const int &error, const QString &message)
{
    m_httpCheckUpdate->deleteLater();
    m_httpCheckUpdate = NULL;
    m_fupdatestatus &= ~FUPDATE_BUSY;
}

// send msg pay to payment server
QString MainController::pay(const QString &customer_name, const QString &customer_hinhthuc, const QString& amount, const QJsonArray &foods, int payMethod)
{
    m_customer_hinhthuc = customer_hinhthuc;
    m_customer_name = customer_name;
    m_foods = foods;
    if ( (payMethod == PAY_ZALO) ||
         (merchantCode.compare("mqshops") == 0) ||
         (merchantCode.compare("vpos") == 0) )
    {
        BillInfo bi;
        bi.Create(amount, foods);

        // get session id from server ...
        if (doGetPmsid(merchantCode, deviceId, bi.id, payMethod))
        {
            m_Bills.addBill(bi);
	        return bi.id;
        }
    }
    else {
        qDebug() << "Do not support pay by cash or card, payid:" << payMethod;
        emit cancellBillCloseQRDialog();
    }

    return QString("");
}

void MainController::updateCardWaitingPay(bool waiting)
{
    cardWaitingPay = waiting;
}

void MainController::doPayCard(const QString &cardId)
{
    if (cardWaitingPay == true) {
        qDebug() << "gui tin hieu thanh toan";
        emit cardPayment(cardId);
    }
    else {
        qDebug() << "khong co dialog cho thanh toan, bo qua";
    }
}

bool MainController::doGetPmsid(const QString &merchantCode, const QString &devId, const QString& biId, int payMethod)
{
    if (http2 == NULL)
    {
        http2 = new HttpBase2(QString(httpTranspro + "://" + getPayment() + cmd_appinvce), this);

		if (payMethod == PAY_ZALO) {
		    QObject::connect(http2, SIGNAL(done(QVariant)), this, SLOT(onPmsidDoneZalo(QVariant)) );
		}
		else if (payMethod == PAY_CASH) {
		    QObject::connect(http2, SIGNAL(done(QVariant)), this, SLOT(onPmsidDoneCash(QVariant)) );
		}

		QObject::connect(http2, SIGNAL(error(int,QString)), this, SLOT(onPmsidError(int, QString)));

		http2->addParameter("cm", cmd_getsession, true);
		http2->addParameter("dt", CommonFunction::formatSession(merchantCode, devId, biId));
		http2->process(POST);

        return true;
    }

    return false;
}

void MainController::onPmsidDoneZalo(const QVariant &data)
{
    QString msg, sesId, biId;
    int err = CommonFunction::parsePmsid(data.toString(), &msg, &sesId, &biId);

    if (err == 0) {
		QObject::disconnect(http2, SIGNAL(done(QVariant)), this, SLOT(onPmsidDoneZalo(QVariant)));
		QObject::disconnect(http2, SIGNAL(error(int,QString)), this, SLOT(onPmsidError(int, QString)));

        doPayZalo(sesId, biId);
    }
    else {
        emit errorMessage(err, msg);

        http2->deleteLater();
        http2 = NULL;
    }
}

void MainController::onPmsidDoneCash(const QVariant &data)
{
    QString msg, sesId, biId;
    int err = CommonFunction::parsePmsid(data.toString(), &msg, &sesId, &biId);

    if (err == 0) {
	    QObject::disconnect(http2, SIGNAL(done(QVariant)), this, SLOT(onPmsidDoneCash(QVariant)));
    	QObject::disconnect(http2, SIGNAL(error(int,QString)), this, SLOT(onPmsidError(int, QString)));

        doPayCash(sesId, biId);
    }
    else {
        emit errorMessage(err, msg);

        http2->deleteLater();
        http2 = NULL;
    }
}

void MainController::onPmsidError(const int error, const QString &msg)
{
    qDebug() << "pmsid error:" << error << ", msg:" << msg;

    emit cancellBillCloseQRDialog();
    emit cancelBillItem();
    emit errorMessage(error, msg);

    http2->deleteLater();
    http2 = NULL;
}

void MainController::doPayZalo(const QString &sesId, const QString &biId)
{
    BillInfo bi;
    if( m_Bills.getById(biId, bi, sesId) )
    {
        QString dt = CommonFunction::formatRequestCreateInvoice(
                    merchantCode, machineName, bi.getAmount(),
                    deviceId, bi.id, bi.foods, getTitleEng(), PAY_ZALO);

        qDebug() << "zalopay dt:" << dt;


        QString token = CommonFunction::HMacSha256HexStringEncode(QString("%1%2")
                                                  .arg(dt)
                                                  .arg(sesId), cmd_token);
        m_Bills.setToken(biId, token);

        QObject::connect(http2, SIGNAL(done(QVariant)), this, SLOT(onPayZaloDone(QVariant)), Qt::UniqueConnection);
        QObject::connect(http2, SIGNAL(error(int,QString)), this, SLOT(onPayZaloError(int, QString)), Qt::UniqueConnection);

        QString dt2 = QString::fromUtf8(QUrl::toPercentEncoding(dt).data());
        http2->addParameter("cm", "create", true);
        http2->addParameter("tk", token);
        http2->addParameter("dt", dt2);
        http2->process(POST);
    }
}

void MainController::onPayZaloDone(const QVariant &data)
{
    QString qrcode;
    quint16 appId;
    QString token, msg;
    QString invceCode, invceSess, invceDate;
    QString oripay, discpay;
    int discount;

    if (CommonFunction::parseResponseZalopay(data.toString(), msg,
                qrcode, &token, &appId,
                &invceCode, &invceSess, &invceDate,
                &oripay, &discount, &discpay) == 0)
    {

        BillInfo bi;
        if (m_Bills.getBySessId(invceSess, bi, invceCode) == true)
        {
            //qDebug() << "found the foID ...";

            QString qrPicture = CommonFunction::generateQRCode(token, appId);

            // (QR responed) send QR & ID to GUI
            emit paySucc(invceCode, qrPicture, discount, oripay, discpay);
    #if 0
    #ifdef Q_OS_ANDROID
            //"Amount 4 bytes " "appid 2 bytes" "transaction token 16 bytes" "crc 2 bytes"
            QByteArray dataArray = CommonFunction::parseDataToReaderDevice(bi.getAmount(), appId, token);
            QAndroidJniObject jstrqrcode = QAndroidJniObject::fromString(QString(dataArray.toHex()));
            QtAndroid::androidActivity().callMethod<void>("sendToDevice", "(Ljava/lang/String;)V",  jstrqrcode.object<jstring>());
    #endif
    #endif
            if (deviceService->isConnected()) {
                deviceService->startReaderDevice(CommonFunction::parseDataToRemoteReaderDevice(bi.getAmount(), appId, token));
            } else {
                //qDebug() << "Device not connected";
            }
        } else {
            qDebug() << "not found the foID ...";
        }

    }
    else {
        // payment error, show message here
        qDebug() << "Pay by Zalopay error, message:" << msg;
        emit payError(QString("Lỗi:%1").arg(msg));
    }

    http2->deleteLater();
    http2 = NULL;
}

void MainController::onPayZaloError(const int &error, const QString &msg)
{
    qDebug() << "on PayZalo Error: " << error << ", msg:" + msg;

    emit cancellBillCloseQRDialog();
    emit cancelBillItem();
    emit errorMessage(error, msg);

    http2->deleteLater();
    http2 = NULL;
}

void MainController::doPayCash(const QString &sesId, const QString &biId)
{
    BillInfo bi;
    if( m_Bills.getById(biId, bi, sesId) )
    {
        QString dt = CommonFunction::formatRequestCreateInvoice(
                    merchantCode, machineName, bi.getAmount(),
                    deviceId, bi.id, bi.foods, getTitleEng(), PAY_CASH);

        QString token = CommonFunction::HMacSha256HexStringEncode(QString("%1%2")
                                                  .arg(dt)
                                                  .arg(sesId), cmd_token);
        m_Bills.setToken(biId, token);

        QObject::connect(http2, SIGNAL(done(QVariant)), this, SLOT(onPayCashDone(QVariant)), Qt::UniqueConnection);
        QObject::connect(http2, SIGNAL(error(int,QString)), this, SLOT(onPayCashError(int, QString)), Qt::UniqueConnection);

        QString dt2 = QString::fromUtf8(QUrl::toPercentEncoding(dt).data());
        http2->addParameter("cm", "create", true);
        http2->addParameter("tk", token);
        http2->addParameter("dt", dt2);
        http2->process(POST);
    }
}

void MainController::onPayCashDone(const QVariant &data)
{
    QString msg, invceCode, invceDate, barcode, balance, discount, payment;
    int err = CommonFunction::parseResponsePayCash(data.toString(), &msg, &invceCode, &invceDate, &barcode, &balance);

    if (m_Bills.checkInvceCode(""))
    {
        if (1)//notifymsg == cmd_paymentsuccess)
        {
            BillInfo bi;
            if( m_Bills.getBill("", bi) == true )
            {
                // tạo nội dung xuất ra máy in
                QString printdata = bi.toPrinter(barcode,
                                                 invceCode,
                                                 invceDate,
                                                 getAppMachine(),
                                                 getTitleEng(),
                                                 discount, payment);
                printBill(invceCode, printdata);
            }

            emit notifySucc(0, invceCode, invceDate, barcode, balance); // send notify error code = 0
        }
        else {
            emit notifySucc(1, invceCode, invceDate, barcode, balance); // send notify error code = 1
        }

        // remove the bill out of list
        m_Bills.removeBill(invceCode);
    }
    else {
        emit notifySucc(err, invceCode, invceDate, barcode, balance);
    }

    http2->deleteLater();
    http2 = NULL;
}

void MainController::onPayCashError(const int &error, const QString &message)
{
    emit errorMessage(error, message);
    emit cancelBillItem();

    http2->deleteLater();
    http2 = NULL;
}

void MainController::insertItem(const QString& type, const QString& code_name, const QString& name, const QString& size, const QString& debanh, const QString& phomai, const QString& price, long quantity, const QString &oriprice, const QString &promtype)
{
    long long priceNum = getMoneyValue(price);
    emit addItem(type, code_name, name, size, debanh, phomai, quantity, priceNum, price, oriprice, promtype);
}

void MainController::printTest(const QJsonArray &foods)
{
    QString dt = QString("\"dt\":{%1,%2,%3,%4,%5,%6,%7}")
            .arg("\"invoice_code\":\"0000000000000000\"")
            .arg("\"invoice_datetime\":\"201701100080808\"")
            .arg("\"barcode\":\"362589764568\"")
            .arg("\"amount\":780228")       //tong tien
            .arg("\"discount\":10")         //giam gia
            .arg("\"payment\":702205")      //thuc thu
            .arg(QString("\"appuser\":\"%1\"").arg(merchantCode));

    QString msg =
            QString("{%1,%2,%3}")
            .arg("\"type\":1")
            .arg("\"msg\":\"payment_success\"")
            .arg(dt);

    onNotify(msg);
}

void MainController::onNotify(const QString &message)
{
    qDebug() << "onNotify:" << message;

    QString notifymsg = CommonFunction::getNotifyValue(message, "msg");

    if (notifymsg.compare(QString("broadcast"), Qt::CaseInsensitive) == 0)
    {
        // Just logging for Bep print data
        qDebug() << "BEP print data:" << CommonFunction::getNotifyValue(message, "data");
    }
    else if (notifymsg.compare(QString("update_item"), Qt::CaseInsensitive) == 0)
    {
        // server force update foods.
        // -- do not call checkUpdateFoodData();
        timerStartUpdate();
    }
    else if (notifymsg.compare(cmd_paymentsuccess, Qt::CaseInsensitive) == 0)
    {                   // cmd = 'payment_success'

        // reset timer checking idle!
        idleReset();

        QString invceCode, invceDate, barcode, balance="", discount, amount, payment;

        if (CommonFunction::parseNotifyInfo(message, &invceCode, &invceDate, &barcode, &discount, &amount, &payment) == true)
        {
            bool payDone = false;

            if( invceCode == "0000000000000000" )
            {
                // test printer
                BillInfo bi;
                QJsonArray jsarr;
                QJsonObject jso;

                jso["item_name"] = "Test-Test-1";
                jso["quantity"] = 8;
                jso["price"] = 12345;
                jso["amount"] = 98760;
                jsarr.append(jso);

                jso["item_name"] = "Com trua";
                jso["quantity"] = 1;
                jso["price"] = 32145;
                jso["amount"] = 32145;
                jsarr.append(jso);

                jso["item_name"] = "Test-Test-2";
                jso["quantity"] = 12;
                jso["price"] = 56789;
                jso["amount"] = 681468;
                for (int i=0; i<1; i++)
                {
                    jsarr.append(jso);
                }

                // ---
                QJsonArray jsarrext;
                QJsonObject namevalue;

                int thucthu = payment.toInt();
                int dct = 10;

                namevalue["name"] = QString("GIAM %1\%").arg(dct);
                namevalue["value"] = CommonFunction::formatMoney( 56789 );
                jsarrext.append(namevalue);

                namevalue["name"] = QString("THANH TOAN");
                namevalue["value"] = CommonFunction::formatMoney(thucthu);
                jsarrext.append(namevalue);

                jso["ext"] = jsarrext;
                // ---

                bi.Create(amount, jsarr);

                // tạo nội dung xuất ra máy in
                QString printdata = bi.toPrinter(barcode,
                                                 invceCode,
                                                 invceDate,
                                                 getAppMachine(),
                                                 getTitleEng(),
                                                 discount, payment);
                printBill(invceCode, printdata);

                emit notifySucc(0, invceCode, invceDate, barcode, balance); // send notify error code = 0
            }

            if (m_Bills.checkInvceCode(invceCode))
            {
                //qDebug() << "==== notify to print current invoice code";
                payDone = true;
                if (notifymsg == cmd_paymentsuccess)
                {
                    BillInfo bi;
                    if( m_Bills.getBill(invceCode, bi) == true )
                    {
                        //push data to domino server
                        QObject::connect(&dominoCtrl, SIGNAL(eventPlaceOrder(QJsonObject)), this, SLOT(eventPlaceOrder(QJsonObject)), Qt::UniqueConnection);
                        QObject::connect(&dominoCtrl, SIGNAL(eventPlaceOrderErr(QString)), this, SLOT(eventPlaceOrderErr(QString)), Qt::UniqueConnection);
                        this->placeorder2dominoserver();

                        // tạo nội dung xuất ra máy in
                        QString printdata = bi.toPrinter(barcode,
                                                         invceCode,
                                                         invceDate,
                                                         getAppMachine(),
                                                         getTitleEng(),
                                                         discount, payment);
                        g_invceCode = invceCode;
                        g_printdata = printdata;
                        g_invceDate = invceDate;
                        g_barcode   = barcode;
                        g_balance   = balance;
                        emit notifySucc(0, g_invceCode, g_invceDate, g_barcode, g_balance); // send notify error code = 0
                    }
                }
                else {
                    emit notifySucc(1, invceCode, invceDate, barcode, balance); // send notify error code = 1
                }

                // remove the bill out of list
                m_Bills.removeBill(invceCode);
            }
            else {
                // gửi thông tin lên server báo là không in hóa đơn vừa nhận
                qDebug() << "reject the invoice:" << invceCode;
                rejectInvoice(invceCode);

                // không cần gọi đóng dialog hay xóa food items bởi chỉ là tín hiệu báo về
            }

            if (payDone == true && wsClient)
            {
                QString msg = CommonFunction::formatPayDone(invceCode, deviceId, 1000, merchantCode);
                wsClient->sendTextMessage(msg);
            }
        }
    }
}

void MainController::eventPlaceOrderErr(const QString &err) {
    qDebug() << "eventPlaceOrder Err: " << err;
    g_storeOrderID = "#";
    printBill(g_invceCode, g_printdata);
}

void MainController::eventPlaceOrder(const QJsonObject &result) {
    qDebug() << "eventPlaceOrder: " << result;
    QJsonObject order_reply;
    QString storeOrderID = "";
    QString order_status = "";
    bool result_response = false;
    QJsonObject dt = result;
    if(dt.contains("OrderReply")) {
        order_reply = dt["OrderReply"].toObject();
        if(order_reply.contains("Status")) {
            order_status = order_reply["Status"].toString();
        }
        if(order_reply.contains("StoreOrderID")) {
            storeOrderID = order_reply["StoreOrderID"].toString();
            storeOrderID = storeOrderID.split("#").length() > 1 ? storeOrderID.split("#")[1] : "#";
            g_storeOrderID = storeOrderID;
        }

        if(order_status == "0") {
            result_response = true;
        }
    }

    if(result_response) {
        // printbill
        qDebug() << "start print bill";
        printBill(g_invceCode, g_printdata);
//        emit notifySucc(0, g_invceCode, g_invceDate, g_barcode, g_balance); // send notify error code = 0
    } else {
        //thong bao loi - gui request len server de hoan tien
        g_storeOrderID = "#";
        printBill(g_invceCode, g_printdata);
//        emit notifySucc(1, g_invceCode, g_invceDate, g_barcode, g_balance);
    }
}

void MainController::onMifareFound(const QString id)
{
    qDebug() << "on mifare found:" << id;
}

void MainController::onCenterServiceFound(const QString &ip, const int &port)
{
    setting->centerService = QString("%1:%2").arg(ip).arg(port);
}

void MainController::rejectInvoice(const QString invceCode)
{
    httpreject = new HttpBase(QUrl(httpTranspro + "://" + getPayment() + cmd_appinvce), this);
    QObject::connect(httpreject, SIGNAL(done(QVariant)), this, SLOT(onRejectDone(QVariant)), Qt::UniqueConnection);
    QObject::connect(httpreject, SIGNAL(error(int,QString)), this, SLOT(onRejectError(int, QString)), Qt::UniqueConnection);
    httpreject->addParameter("cm", "reject", true);
    httpreject->addParameter("dt", CommonFunction::formatInvoiceCancel(invceCode, merchantCode));
    httpreject->process();
}

void MainController::onRejectDone(const QVariant &)
{
    httpreject->deleteLater();
    httpreject = NULL;
}

void MainController::onRejectError(const int&, const QString&)
{
    httpreject->deleteLater();
    httpreject = NULL;
}

int MainController::getAppIndex()
{
    QStringList appnames;
    appnames << "canteenvng" << "ffbanhmique" << "ffcomngon" << "ffcomtamcali" << "ffcomnieu" << "fftapicocup" << "fftokyobowl" << "ffvietthai" << "ffphongoon" << "ffcool" << "ffcobonla" << "ffdorayaki" << "dominos" << "maybanhangtudong" << "mqshops" << "vpos";

    return appnames.indexOf(merchantCode);
}

QString MainController::getAppName()
{
    return merchantCode;
}

void MainController::setAppName(const QString &appName, bool initSocket)
{
    if (appName.isEmpty() || (merchantCode.compare(appName) == 0)) {
        // Merchant ID is empty or the same current
        return;
    }

    merchantCode = appName;
    setting->setAppName(appName);
    appTitle = setting->appTitle;

    emit updateTitle("DOMINOS PIZZA");

    if (initSocket) {
        // re-initial websocket for new session
        initialWebSocket(initSocket);

        emit foodReset();
        checkUpdateFoodData();
    }
}

void MainController::setIdCoupon(const QString & id) {
    setting->setIdCoupon(id);
}

QString MainController::getIdCoupon() {
    return setting->idcoupon;
}

void MainController::setIdCouponPercent(float percent) {
    setting->setIdCouponPercent(percent);
}

QString MainController::getIdCouponPercent() {
    QString _per = QString::number(setting->couponpercent, 'f', 1);
    return _per;
}

QString MainController::getAppTitle()
{
    return appTitle;
}

QString MainController::getTitleEng()
{
    return CommonFunction::ViettoLatin(appTitle);
}

void MainController::setAppTitle(const QString &title)
{
    setting->setAppTitle(title);

    appTitle = title;
    emit updateTitle("DOMINOS PIZZA");
}

int MainController::getMachineIndex()
{
    return getRechargeNum();
}

QString MainController::getAppMachine()
{
    return machineName;
}

int MainController::getRechargeNum()
{
    return setting->idRecharge;
}

void MainController::setRechargeNum(int mcNum)
{
    setting->setRecharge(mcNum);
    machineName = "DOMINOS PIZZA";

//    emit updateTitle(QString("%1").arg(machineName));
    emit updateTitle(machineName);
}

int MainController::getFoodRefreshTimer()
{
    return setting->foodRefreshTimer;
}

void MainController::setFoodRefreshTimer(int timer)
{
    setting->setRefreshTimer(timer);

    // cập nhật lại timer nếu session đang chạy
    m_tmCheckUpdateFood.setInterval(timer*1000);
}

int MainController::getBillAlertTimer()
{
    int build_timer = setting->billAlertTimer;
    return build_timer;
}

void MainController::setBillAlertTimer(int timer)
{
    setting->setBillAlertTimer(timer);
}

int MainController::getConfigIdletime()
{
    return (setting->idleTimer/1000);
}

void MainController::setConfigIdletime(int timer)
{
    setting->setIdletimer(timer);
}

bool MainController::getShowThanhtoancungdonhang()
{
    return setting->showThanhtoancunghoadon;
}

QString MainController::getConfigQrcodeRatio()
{
    return QString::number(setting->qrcodeRatio, 'f', 1);
}

void MainController::setConfigQrcodeRatio(float ratio)
{
    if (ratio > 0) {
        setting->setQrcodeRatio(ratio);
    }
}

int MainController::getConfigFoodItemFontsize()
{
    return setting->foodItemFontsize;
}

void MainController::setConfigFoodItemFontsize(int fntsize)
{
    if (fntsize > 1) {
        setting->setFoodItemFontsize(fntsize);
    }
}

int MainController::getConfigBillItemFontsize()
{
    return setting->billItemFontsize;
}

void MainController::setConfigBillItemFontsize(int fntsize)
{
    if (fntsize > 1) {
        setting->setBillItemFontsize(fntsize);
    }
}

int MainController::getConfigSobanin()
{
    return setting->sobanin;
}

void MainController::setConfigSobanin(int num)
{
    if (num > 0 && num <= 5) {
        setting->setSobanin(num);
    }
}

QString MainController::getConfigTenbanin()
{
    QStringList txts = setting->tenbanin.split(";");

    QString name = "";
    for (int i=0; i<qMax(txts.size(), setting->sobanin); i++)
    {
        if ( i < txts.size() )
        {
            name = name + (i>0? ";":"") + txts[i];
        }
        else
        {
            name = name + (i>0? ";":"");
        }
    }

    return name;
}

void MainController::setConfigTenbanin(const QString &name)
{
    setting->setTenbanin(name);
}

QString MainController::getConfigBillPreinf()
{
    return setting->billPreinf;
}

void MainController::setConfigBillPreinf(const QString &info)
{
    setting->setBillPreinf(info);
}

QString MainController::getConfigBillPostinf()
{
    return setting->billPostinf;
}

void MainController::setConfigBillPostinf(const QString &info)
{
    setting->setBillPostinf(info);
}

QString MainController::getConfigDockversion()
{
    return setting->dockVersion;
}

void MainController::setConfigDockversion(const QString &version)
{
    setting->setDockVersion(version);
}

QString MainController::getConfigPrintersize()
{
    return setting->printerSize;
}

void MainController::setConfigPrintersize(const QString &pagesize)
{
    setting->setPrintersize(pagesize);
}

bool MainController::getUserEnableConfig()
{
    return setting->userEnableConf;
}

void MainController::setUserEnableConfig(bool enableconf)
{
    setting->setUserenableConfig(enableconf);
}

int MainController::getConfigRebootDatePi()
{
    return setting->rebootDate;
}

void MainController::setConfigRebootDatePi(int dayofweek, bool on)
{
    if( on ) {
        setting->rebootDate |= (1 << dayofweek);
    }
    else {
        setting->rebootDate &= ~(1 << dayofweek);
    }

    if( setting->rebootDate && !m_rebootTimer.isActive() ) {
        m_rebootTimer.start(REBOOT_INTERVAL * 60000);
    }
    else if( !setting->rebootDate && m_rebootTimer.isActive() ) {
        m_rebootTimer.stop();
    }

    setting->saveRebootDatetime(1);
}

// type=0:all go&phut, type=1:gio, type=2:phut
int MainController::getConfigRebootTimePi(int type)
{
    if( type == 2 ) {
        return (setting->rebootTime % 60);
    }
    else if( type == 1 ) {
        return (setting->rebootTime / 60);
    }

    return setting->rebootTime;
}

void MainController::setConfigRebootTimePi(int value, int type)
{
    if( value < 0 ) {
        value = 0;
    }

    if( type == 2 ) {
        // minute
        if ( value > 59 ) {
            value = 59;
        }

        setting->rebootTime = (setting->rebootTime / 60)*60 + value;
    }
    else if( type == 1 ) {
        // hour
        if( value > 23 ) {
            value = 23;
        }
        setting->rebootTime = value*60 + (setting->rebootTime % 60);
    }
    else {
        // 23*60 + 59 = 1439
        if( value > 1439) {
            value = 1436;
        }
        setting->rebootTime = value;
    }

    // reboot time range: 00:03 - 23:56
    if( setting->rebootTime < 3 ) {
        setting->rebootTime = 3;
    }
    else if( setting->rebootTime > 1436 ) {
        setting->rebootTime = 1436;
    }

    setting->saveRebootDatetime(0);
}

QString MainController::getRestartTime()
{
    return m_startTime.toString(QString("yyyy/MM/dd - hh:mm:ss"));
}

QString MainController::getCurrentTime(bool on)
{
    QDateTime dt = QDateTime::currentDateTimeUtc().toTimeZone(QTimeZone("Asia/Ho_Chi_Minh"));

    if( on )
        return dt.toString(QString("yyyy/MM/dd - hh:mm:ss"));
    else
        return dt.toString(QString("yyyy/MM/dd - hh:mm ss"));
}

QString MainController::getConfigUsername()
{
    return setting->userName;
}

QString MainController::getConfigUserpwd()
{
    return setting->userPwd;
}

bool MainController::getConfigSearchadvance()
{
    return setting->searchAdvance;
}

void MainController::setConfigSearchadvance(bool searchadvance)
{
    setting->setSearchadvance(searchadvance);
}

bool MainController::getConfigShowBaocaoDate()
{
    return setting->showBaocaoDate;
}

void MainController::setConfigShowBaocaoDate(bool showDate)
{
    setting->showBaocaoDate = showDate;
}

QString MainController::getConfigCenterService()
{
    return setting->centerService;
}

void MainController::setConfigCenterService(const QString &centerServiceIp)
{
    if( setting->setCenterService(centerServiceIp) == true ) {
        initialWsCssClient();
    }
}

void MainController::saveConfig()
{
    setting->Save();
}

void MainController::setShowThanhtoancungdonhang(bool isShow)
{
    setting->setShowThanhtoancunghoadon(isShow);

    emit updateShowthanhtoancungdonhang(isShow);
}

void MainController::sendCancelBillUI()
{
    emit cancelBillItem();
}

QString MainController::getBaocaoCurrentTime()
{
    if (setting->showBaocaoDate) {
        return QDateTime::currentDateTime().toString("yyyy-MM-dd");
    }

    return "";
}

// bcType: baocaoX=0, baocaoZ=1, baocaoDetail=2
void MainController::inBaocao(const QString &date, int bcType)
{    
    m_bcDate = date;
    m_bcType = bcType;
    onLogin(setting->userName, m_usrPwd, true);
}

void MainController::userLogin(const QString &uname, const QString &pwd)
{
    setting->setUsername(uname, pwd);
    m_usrPwd = pwd; // keep this password for InBaocao (InBaocao need login run under-ground)

    onLogin(uname, m_usrPwd, false);
}

QString MainController::getLocalIp()
{
    //QString localIp("");
    //foreach (const QNetworkInterface& interface, QNetworkInterface::allInterfaces())
    //{
    //    foreach (const QNetworkAddressEntry& address, interface.addressEntries())
    //    {
    //        if (address.ip() != QHostAddress::LocalHost)
    //        {
    //            if (address.ip().protocol() == QAbstractSocket::IPv4Protocol) {
    //                if( localIp.isEmpty() ) {
    //                    localIp += address.ip().toString();
    //                }
    //                else {
    //                    localIp += + "," + address.ip().toString();
    //                }
    //            }
    //        }
    //    }
    //}

    //return localIp;

    QString ip;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            if( ip.isEmpty() ) {
                ip = address.toString();
            }
            else {
                ip += "," + address.toString();
            }
        }
    }

    return ip;
}

void MainController::doScanDock()
{
    QStringList listServerIp;
    QList<QHostAddress> listServer;
    DeviceClient::discoverDeviceServerBroadcast(listServer);

    foreach (const QHostAddress& address, listServer) {
        qDebug() << "Found: " << address.toString();
        listServerIp << address.toString();
    }

    emit scanDockDone(listServerIp);
}

void MainController::doScanDockAutosetting()
{
    if (!isConnected())
    {
        QList<QHostAddress> listServer;
        DeviceClient::discoverDeviceServerBroadcast(listServer);

        foreach (const QHostAddress& address, listServer)
        {
            QString srvIp = address.toString();
            connectToDock(srvIp);

            break;
        }
    }
}

void MainController::doPing(const QString& host)
{
#ifndef Q_OS_IOS
    QProcess ps;
    QByteArray ba;
    ps.start("ping -c 4 " + host);
    if (ps.waitForStarted(-1)) {
        while(ps.waitForReadyRead(-1)) {
            ba += ps.readAllStandardOutput();
        }
    }

    emit pingDone(QString(ba));
#endif
}

void MainController::doWifiStatus(const QString &interface)
{
#ifndef Q_OS_IOS
    QProcess ps;
    QByteArray ba;
    QString programs = QString("%1 %2").arg("./vposwifi.sh status").arg(interface);
    ps.start(programs);
    if (ps.waitForStarted(-1)) {
        while(ps.waitForReadyRead(-1)) {
            ba += ps.readAllStandardOutput();
        }
    }
    qDebug() << "Call: " << programs;
    emit wifiStatusDone(QString(ba));
#endif
}

void MainController::updateWSServerIp()
{
    HttpBase httpIpServer;
    httpIpServer.setUrl(QUrl(httpTranspro + "://" + getPayment() + "/api/common?cm=getip"));
    httpIpServer.process(GET);
}

void MainController::initialWebSocket(bool forceStop)
{
    qDebug() << "initialWebSocket ... forcestop = " << forceStop;

    if( forceStop && wsClient )
    {
        wsClient->stop();
        wsClient->wait(10000);

        delete wsClient;
        wsClient = 0;
    }

    if (wsClient == 0)
    {
        //QUrl wsUrl = QUrl(wsTranspro + "192.168.102.201:8686/vpos" + "/ntf/");
        QUrl wsUrl = QUrl(wsTranspro + getPayment() + "/ntf/");
        qDebug() << "wsUrl: " << wsUrl;
        QUrl httpUrl = QUrl(httpTranspro + "://" + getPayment() + "/api/common/");
        qDebug() << "httpUrl: " << httpUrl;
        wsClient = new WSClient(wsUrl, httpUrl, merchantCode, deviceId, true, 0);

        QObject::connect(wsClient, SIGNAL(textMessageReceived(QString)), this, SLOT(onNotify(const QString&)));
        QObject::connect(wsClient, &WSClient::connected, this, [=](){emit cloudConnectionChange(true);});
        QObject::connect(wsClient, &WSClient::closed, this, [=](){emit cloudConnectionChange(false);});
        wsClient->start();
    }
}

void MainController::initialWsCssClient()
{
    if( wscssClient ) {
        delete wscssClient;
        wscssClient = NULL;
    }

    wscssClient = new WsCssClient( APPID::VPOS, APPID::PRINTER );
    QObject::connect(wscssClient, SIGNAL(textMessageReceived(QString)), this, SLOT(onNotify(QString)));
    QObject::connect(wscssClient, SIGNAL(foundServer(QString,int)), this, SLOT(onCenterServiceFound(QString,int)));
}

QString MainController::formatMoney(long long moneyValue)
{
    long long absVal = abs(moneyValue);
    QString money = QString::number(absVal);
    int loop = money.length() / 3;
    if (loop > 0)
    {
        if (money.length() % 3 == 0)
        {
            loop = loop - 1;
        }

        int index = money.length();
        for (int i = 0; i < loop ; i++)
        {
            index = index - 3;
            money.insert(index,  QString(","));
        }
    }

    if (moneyValue < 0)
        money.insert(0,  QString("-"));

    return money;
}

long long MainController::getMoneyValue(const  QString &moneyString)
{
    QString money = moneyString;
    money = money.replace(QString(","),QString::null);
    if (money.isEmpty())
    {
        return 0;
    }
    else
    {
        return money.toLongLong();
    }
}

QString MainController::moneyMoney(QString money)
{
    // convert money string "12345" >> "12,345"
    return formatMoney(getMoneyValue(money));
}

void MainController::updateTotalMoney(long long moneyValue)
{
    emit updateAmount(formatMoney(moneyValue));
}

// print bill detail to printer
void MainController::printBill(const QString& ivcode, const QString &printData)
{
    qDebug() << "printData: " + printData;

    // call printing function to sending bill-Detail to printer
    // ...
#if 0
#ifdef Q_OS_ANDROID
    QString newData = CommonFunction::ViettoLatin(printData);
    QAndroidJniObject billText = QAndroidJniObject::fromString(newData);
    QtAndroid::androidActivity().callMethod<void>("printBill", "(Ljava/lang/String;)V",  billText.object<jstring>());
#endif
#endif

    if (deviceService)
    {
        QString fooddata = CommonFunction::ViettoLatin(printData);
        qDebug() << "fooddata: " + fooddata;

        if (setting->dockVersion.compare("1.0") == 0) {
            // original print server service
            deviceService->print(QString(""), ivcode, fooddata, DeviceClient::VPOS_Payment);
        }
        else
        {
            // format print data for Dock Print Server 2.0
            if (setting->sobanin < 2)
            {
                QByteArray prntcode = createPrintFoodcourt(fooddata, setting->billPreinf, setting->billPostinf);
                QString prntdata = Prntdataformat::makePrintDataFromPrncode(prntcode);
                deviceService->print(QString(""), ivcode, prntdata, DeviceClient::VPOS_Payment);
            }
            else
            {
                QByteArray prntcode;
                QStringList namelist = setting->tenbanin.split(";");

                for (int i=0; i<setting->sobanin; i++)
                {
                    QString namebanin;

                    if (i < namelist.size()) {
                        namebanin = QString("#%1 %2").arg(i+1).arg(namelist[i]);
                    } else {
                        namebanin = QString("#%1").arg(i+1);
                    }

                    prntcode = createPrintFoodcourt(fooddata, setting->billPreinf, setting->billPostinf, namebanin, (i+1)==setting->sobanin);
                    QString prntdata = Prntdataformat::makePrintDataFromPrncode(prntcode);
                    deviceService->print(QString(""), ivcode, prntdata, DeviceClient::VPOS_Payment);
                }
            }
        }

        // send broadcase bill to printer-machine ...
        if( wscssClient && setting->printBep ) {
            wscssClient->sendMsg(CommonFunction::formatBroadcast(fooddata));
        }
    }

#ifdef Q_OS_WIN32
    // xprinter58 is printer name

    qDebug() << "Printer name:" + getPrinter();

    ReceiptPrinter printer(getPrinter(), printData);
    printer.print();
#endif
}

void MainController::cancelBill(const QString& foId, const QString& invcecode, const QString& total)
{
    qDebug() << "cancelBill, foId:" << foId << ", invoice code:" << invcecode << ", total:" << total;

    cardWaitingPay = false; // đóng dialog chờ thanh toán thẻ

    if (http2) {
        // 2017-02-28, fix bug user cancel while waiting the network respone
        // delete on the onNetwork respone object
        http2->deleteLater();
        http2 = NULL;
    }

    // remove food order bill
    m_Bills.removeById(foId);

    if (!invcecode.isEmpty()) {
        // chỉ gửi cancel lên server nếu đã có hóa đơn.
        // ngược lại, cancel trong lúc chờ mã hóa đơn thì không cần gửi cancel lên server nữa
        httpcancel = new HttpBase(QUrl(httpTranspro + "://" + getPayment() + cmd_appinvce), this);
        QObject::connect(httpcancel, SIGNAL(done(QVariant)), this, SLOT(onCancelDone(QVariant)), Qt::UniqueConnection);
        QObject::connect(httpcancel, SIGNAL(error(int,QString)), this, SLOT(onCancelError(int, QString)), Qt::UniqueConnection);
        httpcancel->addParameter("cm", "cancel", true);
        httpcancel->addParameter("dt", CommonFunction::formatInvoiceCancel(invcecode, merchantCode));
        httpcancel->process();

    } else {

        // close QR dialog
        emit cancellBillCloseQRDialog();

        // bỏ backup theo yêu cầu, vẫn gọi emit cancelBiiItem để clean hóa đơn
        emit cancelBillItem();
    }
}

void MainController::onCancelDone(const QVariant &data)
{
    // close QR dialog
    emit cancellBillCloseQRDialog();

    // bỏ backup theo yêu cầu, vẫn gọi emit cancelBiiItem để clean hóa đơn
    emit cancelBillItem();

    httpcancel->deleteLater();
    httpcancel = NULL;
}

void MainController::onCancelError(const int&, const QString&)
{
    // close QR dialog
    emit cancellBillCloseQRDialog();

    // bỏ backup theo yêu cầu, vẫn gọi emit cancelBiiItem để clean hóa đơn
    emit cancelBillItem();

    httpcancel->deleteLater();
    httpcancel = NULL;
}

void MainController::stopDevice()
{
    //qDebug() << "MainController::stopDevice";
#if 0
#ifdef Q_OS_ANDROID
    QByteArray dataArray = CommonFunction::parseCmdStopToReaderDevice();
    QAndroidJniObject jstrqrcode = QAndroidJniObject::fromString(QString(dataArray.toHex()));
    QtAndroid::androidActivity().callMethod<void>("stopDevice", "(Ljava/lang/String;)V",  jstrqrcode.object<jstring>());
#endif
#endif

    if (deviceService && deviceService->isConnected()) {
        deviceService->stopReaderDevice();
    }
}

QString MainController::getPrinter()
{
    return setting->printerName;
}

void MainController::setPrinter(QString prnName)
{
    setting->setPrinter(prnName);
}

QString MainController::getPayment()
{
    return setting->paymentName;
}

int MainController::getDominoStore() {
    return setting->dominoStore;
}

QString MainController::getDominoServerUrl() {
    return setting->dominoServerUrl;
}

QString MainController::getUrlService()
{
    QStringList urls = setting->paymentName.split(".");
    if (urls.size() > 0) {
        return urls.at(0);
    }

    return setting->paymentName;
}

QString MainController::getTransferProtocol()
{
    return httpTranspro;
}

void MainController::setTransferProtocol(const QString& transpro, bool initSocket)
{
    if (transpro.isEmpty() || (httpTranspro.compare(transpro) == 0)) {
        return;
    }

    setting->setTransProtocol(transpro);

    if (transpro.compare("http") == 0) {
        httpTranspro = "http";
        wsTranspro = "ws://";
    } else {
        httpTranspro = "https";
        wsTranspro = "wss://";
    }

    if( initSocket ) {
        initialWebSocket(initSocket);
    }
}

void MainController::setPayment(QString paymentName, bool initSocket)
{
    if ( setting->setPaymentName(paymentName) &&
         initSocket )
    {
        // re-initial websocket for new session
        initialWebSocket(initSocket);

        emit foodReset();
        checkUpdateFoodData();
    }
}

void MainController::setDominoServerUrl(QString url) {
    setting->setDominoServerUrl(url);
}

void MainController::setDominoStore(int store) {
    setting->setDominoStore(store);
}

void MainController::setPaymentMethod(int paymentMethod)
{
    // chọn phương thức thanh toán từ UI
    // 1:zalopay; 2:card; 4:cash
    setting->setPaymentMethod(paymentMethod);

    emit paymentUpdate(paymentMethod);
}

int MainController::getPaymentMethod()
{
    return setting->paymentMethod;
}

void MainController::setPaymentMask(int payment, bool onoff)
{
    if (onoff == true) {
        //setting->paymentMask |= payment;
        setting->setPaymentMask(setting->paymentMask | payment);

        if ((setting->paymentMethod & setting->paymentMask) == 0) {
            // cập nhật payment method nếu nó là phương thức duy nhất
            setPaymentMethod(payment);
        }
    }
    else {
        //setting->paymentMask &= ~payment;
        setting->setPaymentMask(setting->paymentMask & ~payment);

        if ((setting->paymentMethod & setting->paymentMask) == 0) {
            // tìm phương thức khác để chọn
            if ((setting->paymentMask & 1) == 1) {
                setPaymentMethod(1);
            }
            else if ((setting->paymentMask & 2) == 2) {
                setPaymentMethod(2);
            }
            else if ((setting->paymentMask & 4) == 4) {
                setPaymentMethod(4);
            }
        }
    }

    emit paymentMask(setting->paymentMask);
}

int MainController::getPaymentMask()
{
    return setting->paymentMask;
}

QString MainController::getDockServer()
{
    return setting->dockServer;
}

void MainController::setDockServer(QString dockServer)
{
    setting->setDocServer(dockServer);
}

void MainController::scanDock(bool doAuto)
{
    if ( doAuto ) {
        doScanDockAutosetting();
    }
    else {
        // Start the computation.
        QFuture<void> future = QtConcurrent::run(this, &MainController::doScanDock);
    }
}

bool MainController::isConnected()
{
    if (deviceService && deviceService->isConnected()) {
        return true;
    }

    return false;
}

bool MainController::connectToDock(const QString &serverIp)
{
    if (Q_NULLPTR == deviceService) {
        deviceService = new DeviceClientService();
        connect(deviceService, &DeviceClientService::connectionChanged, [=](int iConnect) {
            qDebug() << "Device client notify to main";
            if (iConnect == DeviceClient::Connected) {
                emit dockConnectionChange(true);
            } else {
                emit dockConnectionChange(false);
            }
        });

        connect(deviceService, &DeviceClientService::printDone, [=](quint16 errcode, const QString& ivcode) {
            //qDebug() << "On print done";
            if (!ivcode.isEmpty() && m_Bills.checkInvceCode(ivcode)) {
                emit printDone(errcode);
            }
            else {
                //qDebug() << "Not current invoice code " << ivcode;
            }
        });

        connect(deviceService, &DeviceClientService::printerReadyChanged, [=](bool ready) {
            qDebug() << "On printer status change";
            emit printerReadyChanged(ready);
        });

        connect(deviceService, &DeviceClientService::dockStat, [=](const QString& stat) {
            emit dockStatistics(stat);
        });

        connect(deviceService, &DeviceClientService::mifareFound, [=](const QString& mfdata) {
            //qDebug() << "Main controller receive card: " << mfdata;

            doPayCard(mfdata);

            /*
            if (setting->appType == 0) {
                // quẹt thẻ thanh toán đơn hàng
                doCardPayment(mfdata);
            }
            else if (setting->appType == 1) {
                // check-in
                doCardCheckin(mfdata);
            }
            else if (setting->appType == 2) {
                // nap tien
                 qDebug() << "doCardRecharge: " << mfdata;
                 //test
                 //doCardRecharge("A001");
                 doCardRecharge(mfdata);
            } //*/
        });
    }

    deviceService->startService(serverIp);
    setting->setDocServer(serverIp);
    return true;
}

void MainController::disconnectFromDock()
{
    deviceService->disconnectFromServer();
}

void MainController::testReaderDevice(bool run)
{
    if (run) {
        qDebug() << "Start reader device";
        QByteArray data = CommonFunction::parseDataToRemoteReaderDevice(10000, 10, "dT-mf_jKeD9ZHlrmKJxooA");
        deviceService->startReaderDevice(data);
    } else {
        qDebug() << "Stop reader device";
        deviceService->stopReaderDevice();
    }
}

void MainController::updateWifi(const QString &ssid, const QString &key, const QString &encrypt)
{
    qDebug() << "updateWifi, ssid=" << ssid << ", key=" << key << ", encrypt=" << encrypt;

    if (key.isEmpty()) {
        deviceService->updateWifi(ssid, key, "none");
    } else {
        deviceService->updateWifi(ssid, key, encrypt);
    }
}

void MainController::updateWifiPi(const QString& interface, const QString &ssid, const QString &key, const QString &encrypt, bool scan_ssid)
{
#ifndef Q_OS_IOS

    // ./vposwifi.sh update interface ssid key psk2-mixed false
    // ./vposwifi.sh update wlan0 csmrouter gbc@vng2017 psk2-mixed false

    QString programs = QString("sudo ./vposwifi.sh update \"%1\" \"%2\" \"%3\"").arg(interface, ssid, key);
    QProcess::startDetached(programs);
#endif
}

void MainController::wifiStatus(const QString &interface)
{
    QFuture<void> future = QtConcurrent::run(this, &MainController::doWifiStatus, interface);
}

void MainController::testPing(const QString& host)
{
    QFuture<void> future = QtConcurrent::run(this, &MainController::doPing, host);
}

void MainController::restartDock()
{
    if (deviceService) {
        deviceService->restartService();
    }
}

void MainController::restartPi()
{
#ifndef Q_OS_IOS
    QString programs = QString("sudo reboot");
    qDebug() << "Call: " << programs;
    QProcess::startDetached(programs);
#endif
}

void MainController::haltPi()
{
#ifndef Q_OS_IOS
    QString programs = QString("sudo halt");
    qDebug() << "Call: " << programs;
    QProcess::startDetached(programs);
#endif
}

void MainController::checkPrinterStatus()
{
    if (deviceService && deviceService->isConnected()) {
        deviceService->checkPrinterStatus();
    }
}

bool MainController::checkToken(const QString& data, const QString& token, const QString key)
{
    QString tk = CommonFunction::HMacSha256HexStringEncode(data, key);
    return (tk.compare(token) == 0);
}

QString MainController::xorstr(const QString& s)
{
    QString res = "";

    for( int i=0; i<s.length(); i++ )
    {
        res += (s[i].toLatin1() ^ 128);
    }

    return res;
}

void MainController::sortPairList(QList<QPair<QString, QString> > &pl)
{
    QList<QPair<QString, QString> > source = pl;

    QList<QString> keys;
    for( int i=0; i<source.size(); i++ )
    {
        keys.append( source.at(i).first);
    }
    qSort(keys);

    pl.clear();
    for( int i=0; i<keys.size(); i++ )
    {
        const QString key = keys.at(i);
        int idx = -1;

        for( int j=0; j<source.size(); j++ )
        {
            if( key == source.at(j).first )
            {
                pl.append( source.at(j) );
                idx = j;
                break;
            }
        }

        if( idx >= 0 ) {
            source.removeAt(idx);
        }
    }
}

void MainController::onLogin(const QString &uname, const QString &pwd, bool isBaocao)
{
    m_login4Baocao = isBaocao;

    if (m_progstatus == LOGIN_NONE)
    {
        m_progstatus = LOGIN_WAITLOGIN;

        if (httpBaocao == NULL) {
            httpBaocao = new HttpBase2(QString(""), this);
            QObject::connect(httpBaocao, SIGNAL(done(QVariant)), this, SLOT(onLoginDone(QVariant)));
            QObject::connect(httpBaocao, SIGNAL(error(int,QString)), this, SLOT(onLoginError(int,QString)));

            httpBaocao->setUrl(QUrl(httpTranspro + "://" + getPayment() + QString("/api/login/?")));
            httpBaocao->addParameter("cm", "client_login", true);
            httpBaocao->addParameter("dt", CommonFunction::formatLogin(merchantCode, uname, pwd));

            // request login ...
            httpBaocao->process();
        }
    }
    else if (m_progstatus == LOGIN_READY)
    {
        //Already login, do baocao ...
        emit baocaoRequest();
    }
}

void MainController::onLoginDone(const QVariant &data)
{
    QString msg, merchantId;
    int err = CommonFunction::parseErrcode(data.toString(), msg, &merchantId);

    if (merchantCode.isEmpty() ) {
        // lần đầu login, cập nhật lại appId
        setAppName(merchantId, true);
    }

    if ((err == 0) && (m_login4Baocao == true))
    {
        m_progstatus = LOGIN_READY;
        emit baocaoRequest();
    }
    else
    {
        emit login(err, msg);

        // reset login to begining
        m_progstatus = LOGIN_NONE;
        httpBaocao->deleteLater();
        httpBaocao = NULL;
    }
}

void MainController::onLoginError(const int &error, const QString &msg)
{
    // reset login to begining
    m_progstatus = LOGIN_NONE;
    httpBaocao->deleteLater();
    httpBaocao = NULL;

    emit login(error, msg);
}

void MainController::onBaocao()
{
    if (m_progstatus >= LOGIN_READY)
    {
        // process pre-request baocao here ...
        if (m_progstatus == LOGIN_READY) {
            QObject::disconnect(httpBaocao, SIGNAL(done(QVariant)), this, SLOT(onLoginDone(QVariant)));
            QObject::disconnect(httpBaocao, SIGNAL(error(int,QString)), this, SLOT(onLoginError(int,QString)));

            QObject::connect(httpBaocao, SIGNAL(done(QVariant)), this, SLOT(onBaocaoDone(QVariant)));
            QObject::connect(httpBaocao, SIGNAL(error(int,QString)), this, SLOT(onBaocaoError(int,QString)));
        }

        if ((m_progstatus == LOGIN_READY) || (m_progstatus == BAOCAO_READY))
        {
            m_progstatus = BAOCAO_WAITING;

            // request bao cao here ...
            httpBaocao->setUrl(QUrl(httpTranspro + "://" + getPayment() + QString("/api/report/?")));
            httpBaocao->addParameter("cm", "report_by_shift", true); // "report_by_item"
            httpBaocao->addParameter("dt", CommonFunction::formatBaocao(merchantCode, m_bcType, m_bcDate, m_bcDate));

            httpBaocao->process();
        }
    }
    else if (m_progstatus == LOGIN_NONE)
    {
        // request login before do baocao
        emit loginRequest();
    }
}

void MainController::onBaocaoDone(const QVariant &data)
{
    // reset login to begining
    m_progstatus = BAOCAO_READY;

    if (deviceService && (setting->dockVersion.compare("1.0") != 0))
    {
        QString bclatin = CommonFunction::ViettoLatin(data.toString());

        QByteArray prntcode;

        prntcode = createPrintBaocao( bclatin, m_bcType, false );
        printBigData(prntcode);

        prntcode = createPrintBaocao( bclatin, m_bcType, true );
        printBigData(prntcode);
    }
    else {
        qDebug() << "Baocao done, but printer not ready or dock version is 1.0";
    }

    httpBaocao->deleteLater();
    httpBaocao = NULL;
    m_progstatus = LOGIN_NONE;
}

void MainController::onBaocaoError(const int &error, const QString &msg)
{
    httpBaocao->deleteLater();
    httpBaocao = NULL;
    m_progstatus = LOGIN_NONE;
}


QString MainController::getDiskPrepare()
{
    QJsonArray jsarr;

    QJsonObject jso;

    jso["idx"] = 1;
    jso["name"] = "-- Cháo đậu thập cẩm";
    jso["amout"] = 2;
    jso["time"] = QDateTime::currentDateTime().toString("hh:mm:ss");
    jsarr.append(jso);

    for( int i=1; i<40; i++) {
        jso["idx"] = i+1;
        jso["name"] = "++ Cháo đậu thập cẩm";
        jso["amout"] = i;
        jso["time"] = QDateTime::currentDateTime().toString("hh:mm:ss");
        jsarr.append(jso);
    }

    QJsonDocument doc(jsarr);
    QString rest = QString::fromUtf8(doc.toJson().data());

    return rest;
}

QString MainController::getDiskReserve()
{
    QJsonArray jsarr;

    QJsonObject jso;

    jso["idx"] = 1;
    jso["name"] = "-- Canh cải bẹ xanh";
    jso["amout"] = 2;
    jso["time"] = QDateTime::currentDateTime().toString("hh:mm:ss");
    jsarr.append(jso);

    for( int i=1; i<30; i++) {
        jso["idx"] = i+1;
        jso["name"] = "++ Canh cải bẹ xanh";
        jso["amout"] = i;
        jso["time"] = QDateTime::currentDateTime().toString("hh:mm:ss");
        jsarr.append(jso);
    }

    QJsonDocument doc(jsarr);
    QString rest = QString::fromUtf8(doc.toJson().data());

    return rest;
}

// tạo bản in cho foodcourt
QByteArray MainController::createPrintFoodcourt(const QString& fooddata,
                                                const QString &billPreinf,
                                                const QString &billPostinf,
                                                const QString &banin, bool cutpageSeperate)
{
    int PAGESZ = 33;
    int TAB1, TAB2, TAB3, TAB4;

    if (setting->printerSize == "small") {
        PAGESZ = 33;
        TAB1 = 10;
        TAB2 = 12;
        TAB3 = 23;
        TAB4 = 33;
    }
    else {
        PAGESZ = 48;
        TAB1 = 12;
        TAB2 = 27;
        TAB3 = 38;
        TAB4 = 48;
    }

    QJsonDocument jsd = QJsonDocument::fromJson(fooddata.toUtf8());
    if (!jsd.isObject()) {
        return "";
    }

    QJsonObject jso = jsd.object();

    Prntdataformat pdf;

    pdf.codeFontType(pdf.font_A);
    pdf.codeFontBold(true);
    pdf.codeLine(CommonFunction::ViettoLatin(jso["title"].toString()), pdf.Justify_center);
    pdf.codeFontBold(false);

    if ( !billPreinf.isEmpty() ) {
        QStringList infs = billPreinf.split(";");
        for (int i=0; i<infs.length(); i++) {
            pdf.codeLine(infs.at(i));
        }
        //pdf.codeLine("Tang 5-TTTM Flemington");
        //pdf.codeLine("184 Le Dai Hanh, P.15, Q.11");
    }

    pdf.codeFeedline();

    // Ban In #1
    if( setting->printBep )
    {
        pdf.codeFontBold(true);

        QString billcode = jso["receiptNum"].toString().right(4);

        if( banin.isEmpty() ) {
            pdf.codeLine(QString("#%1").arg(billcode));
        }
        else {
            pdf.codeLine(QString("%1 #%2").arg(banin).arg(billcode));
        }

        pdf.codeFontBold(false);
        pdf.codeFeedline();
    }
    QString vposInvoice = jso["receiptNum"].toString();
//    pdf.codeLine(QString("May:\t%1").arg(jso["machine"].toString()), pdf.Justify_left, TAB1);
//    pdf.codeLine(QString("Hoa don VPOS:\t%1").arg(jso["receiptNum"].toString()), pdf.Justify_left, TAB2);
    pdf.codeLine(QString("Hoa don:\t%1").arg(g_storeOrderID), pdf.Justify_left, TAB1);
    pdf.codeLine(QString("Ten KH:\t%1").arg(m_customer_name), pdf.Justify_left, TAB1);
    pdf.codeLine(QString("Ngay:\t%1").arg(jso["datetime"].toString()), pdf.Justify_left, TAB1);

    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

    pdf.codeText("TEN", pdf.Justify_left);
    pdf.codeText("\tSL", pdf.Justify_none, TAB2);
    pdf.codeText("\tD.GIA", pdf.Justify_right, TAB3);
    pdf.codeLine("\tT.TIEN", pdf.Justify_right, TAB4);
    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

    // ...
    if (jso["item"].isArray())
    {
        QJsonArray receiptItem = jso["item"].toArray();
        for (int i = 0; i < receiptItem.size(); i++)
        {
            QJsonObject item = receiptItem[i].toObject();

            QString name = item["item_name"].toString();

            int isBold = QString::compare(name, "com trua", Qt::CaseInsensitive);
            if (isBold == 0) {
                pdf.emphasized_on();
                name = name.toUpper();
                pdf.prntUnderline(Prntdataformat::udl_1dot);
            }

            if (name.length() >= TAB2)
                pdf.codeLine(name, pdf.Justify_left);
            else
                pdf.codeText(name, pdf.Justify_left);

            if (isBold == 0) {
                pdf.prntUnderline(Prntdataformat::udl_none);
            }

            pdf.codeText("\t" + item["quantity"].toString(), pdf.Justify_left, TAB2);
            pdf.codeText("\t" + item["price"].toString(), pdf.Justify_right, TAB3);
            pdf.codeLine("\t" + item["amount"].toString(), pdf.Justify_right, TAB4);

            if (isBold == 0) {
                pdf.emphasized_off();
            }
        }
    }

    pdf.codeChars('-', PAGESZ, pdf.Justify_left);

    QString total = "\t" + jso["total"].toString();

    if (jso["ext"].isArray()) {
        pdf.codeLine(QString("TONG:%1").arg(total), pdf.Justify_left, TAB4-total.length());
    }
    else {
        pdf.emphasized_on();
        pdf.codeLine(QString("TONG:%1").arg(total), pdf.Justify_left, TAB4-total.length());
        pdf.emphasized_off();
    }

    // Extended field
    if (jso["ext"].isArray())
    {
        QJsonArray extItems = jso["ext"].toArray();
        for (int i = 0; i < extItems.size(); i++)
        {
            QJsonObject item = extItems[i].toObject();

            QString name = item["name"].toString();
            QString value = "\t" + item["value"].toString();

            if( (i+1) == extItems.size() ) {
                pdf.codeChars('-', PAGESZ, pdf.Justify_left);
            }

            if( (i+1) < extItems.size() )
            {
                pdf.codeLine(QString("%1%2").arg(name).arg(value), pdf.Justify_left, TAB4-value.length());
            }
            else
            {
                pdf.emphasized_on();
                pdf.codeLine(QString("%1%2").arg(name).arg(value), pdf.Justify_left, TAB4-value.length());
                pdf.emphasized_off();
            }
        }
    }
    // Extended field

    pdf.codeChars('-', PAGESZ, pdf.Justify_left);
    pdf.codeFeedline(1);

    pdf.codeLine(QString("%1").arg(vposInvoice), pdf.Justify_center);

    pdf.codeBarcode(jso["barcode"].toString(), 2, 80, pdf.Justify_center);
    pdf.codeFeedline(1);

    if ( !billPostinf.isEmpty() ) {
        QStringList infs = billPostinf.split(";");
        for (int i=0; i<infs.length(); i++) {
            pdf.codeLine(infs.at(i));
        }
        //pdf.codeLine("Cam on quy khach");
        //pdf.codeLine("Hen gap lai");
    }

    pdf.codeFeedline(PAGESZ < 40 ? 2 : 1);

    if (!cutpageSeperate) {
        pdf.codeChars('-', PAGESZ, pdf.Justify_left);
        pdf.codeFeedline(2);
    }
    else {
        pdf.codeFeedline(0);
    }

    pdf.codeCutpage(cutpageSeperate);

    return pdf.getPrintDeviceCode();
}

QByteArray MainController::createPrintBaocao(const QString& baocao, int bcType, bool bDetail)
{
    int PAGESZ = 33;
    int TAB3, TAB4;

    if (setting->printerSize == "small") {
        PAGESZ = 33;
        TAB3 = 23;
        TAB4 = 33;
    }
    else {
        PAGESZ = 48;
        TAB3 = 38;
        TAB4 = 48;
    }

    Prntdataformat pdf;

    pdf.codeFontType(pdf.font_A);
    pdf.codeFontBold(true);
    pdf.codeLine(getTitleEng(), pdf.Justify_center);
    pdf.codeFontBold(false);

    if ( !setting->billPreinf.isEmpty() ) {
        QStringList infs = setting->billPreinf.split(";");
        for (int i=0; i<infs.length(); i++) {
            pdf.codeLine(infs.at(i));
        }
    }

    pdf.codeFeedline();
    pdf.codeLine(bcType == 0 ? "BAO CAO  X" : "BAO CAO Z", pdf.Justify_center);

    // bao cao data
    QJsonDocument jsd = QJsonDocument::fromJson(baocao.toUtf8());
    if (jsd.isObject())
    {
        QJsonObject jso = jsd.object();

        QString slMonan;
        QString sDoanhthu, sGiamgia, sThucthu;
        int iDoanhthu=0, iGiamgia=0, iThucthu=0;

        if (jso.contains("dt"))
        {
            QJsonObject jdt = jso["dt"].toObject();

            QString beginTime, endTime;

            if (jdt.contains("begin_datetime")) {
                beginTime = jdt["begin_datetime"].toString();
            }

            if (jdt.contains("end_datetime")) {
                endTime = jdt["end_datetime"].toString();
            }

            pdf.codeLine(QString("tu : %1").arg(beginTime));
            pdf.codeLine(QString("den: %1").arg(endTime));

            // lấy giờ server hoặc ngày nhập trùng ngày server
            if (!m_bcDate.isEmpty() && endTime.left(10) != m_bcDate)
            {
                pdf.codeFeedline();
                pdf.codeLine(QString("(Ngay in: %1)").arg(endTime));
            }

            pdf.codeFeedline();

            if (jdt.contains("dataSummary"))
            {
                QJsonObject jsum = jdt["dataSummary"].toObject();

                if (jsum.contains("total_revenue_summary"))
                {
                    iDoanhthu = jsum["total_revenue_summary"].toInt();
                    sDoanhthu = "\t" + moneyMoney( QString::number( iDoanhthu ) );
                }

                if (jsum.contains("total_real_revenue_summary"))
                {
                    iThucthu = jsum["total_real_revenue_summary"].toInt();
                    iGiamgia = iDoanhthu - iThucthu;

                    sGiamgia = "\t" + moneyMoney( QString::number( iGiamgia ) );
                    sThucthu = "\t" + moneyMoney( QString::number( iThucthu ) );
                }

                if (bDetail == false )
                {
                    // bao cao rut gon

                    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

                    pdf.codeText(QString("DOANH THU:"), pdf.Justify_left);
                    pdf.codeLine(sDoanhthu, pdf.Justify_left, TAB4-sDoanhthu.length());

                    pdf.codeText(QString("GIAM GIA:"), pdf.Justify_left);
                    pdf.codeLine(sGiamgia, pdf.Justify_left, TAB4-sGiamgia.length());

                    pdf.codeText(QString("THUC THU:"), pdf.Justify_left);
                    pdf.codeLine(sThucthu, pdf.Justify_left, TAB4-sThucthu.length());

                    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

                    pdf.codeFeedline(PAGESZ < 40 ? 2 : 1);
                    pdf.codeCutpage();
                }
                else
                {
                    // bao cao chi tiet

                    if (jsum.contains("total_items_summary")) {
                        slMonan = "\t" + QString::number(jsum["total_items_summary"].toInt());
                    }

                    if (jdt.contains("listData"))
                    {
                        QJsonArray jlstdata = jdt["listData"].toArray();

                        if (jlstdata.size() > 0 )
                        {
                            pdf.codeChars('-', PAGESZ, pdf.Justify_center);
                            pdf.codeText("TEN MON AN", pdf.Justify_left);
                            pdf.codeText("\tSL", pdf.Justify_left, TAB3-3);
                            pdf.codeLine("\tT.TIEN", pdf.Justify_left, TAB4-7);
                            pdf.codeChars('-', PAGESZ, pdf.Justify_center);
                        }

                        for( int i=0; i<jlstdata.size(); i++)
                        {
                            QJsonObject item = jlstdata[i].toObject();

                            QString name = QString("%1 %2").arg(QString("%1").arg(i+1, 2, 10, QChar(' '))).arg(item["item_name"].toString());
                            if (name.length() < TAB3)
                                pdf.codeText(name, pdf.Justify_left);
                            else
                                pdf.codeLine(name, pdf.Justify_left);

                            name = "\t" + item["total_items"].toString();
                            pdf.codeText(name, pdf.Justify_left, TAB3-name.length());

                            name = "\t" + moneyMoney( item["total_revenue"].toString() );
                            pdf.codeLine(name, pdf.Justify_left, TAB4-name.length());
                        }
                    }

                    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

                    pdf.codeText("TONG:", pdf.Justify_left, 0);
                    pdf.codeText(slMonan, pdf.Justify_left, TAB3-slMonan.length());
                    pdf.codeLine(sDoanhthu, pdf.Justify_left, TAB4-sDoanhthu.length());

                    pdf.codeText(QString("GIAM GIA:"), pdf.Justify_left);
                    pdf.codeLine(sGiamgia, pdf.Justify_left, TAB4-sGiamgia.length());

                    pdf.codeText(QString("THUC THU:"), pdf.Justify_left);
                    pdf.codeLine(sThucthu, pdf.Justify_left, TAB4-sThucthu.length());

                    pdf.codeChars('-', PAGESZ, pdf.Justify_center);

                    // In chi tiet hoa don
                    if (jdt.contains("listInvoice"))
                    {
                        QJsonArray jlstdata = jdt["listInvoice"].toArray();

                        if (jlstdata.size() > 0)
                        {
                            pdf.codeFeedline(1);
                            pdf.codeLine("THONG TIN CHI TIET", pdf.Justify_center);
                            pdf.codeFeedline(1);
                        }

                        for( int i=0; i<jlstdata.size(); i++)
                        {
                            QJsonObject jsoIvce = jlstdata[i].toObject();

                            pdf.codeLine(QString("Ngay: %1").arg(jsoIvce["payment_date_time"].toString()), pdf.Justify_left);
                            pdf.codeLine(QString("HD  : %1").arg(jsoIvce["invoice_code"].toString()), pdf.Justify_left);

                            if (jsoIvce["listInvoiceDetail"].isArray())
                            {
                                QJsonArray receiptItem = jsoIvce["listInvoiceDetail"].toArray();
                                for (int i = 0; i < receiptItem.size(); i++)
                                {
                                    QJsonObject item = receiptItem[i].toObject();

                                    QString name = QString("%1 %2").arg(QString("%1").arg(i+1, 2, 10, QChar(' '))).arg(item["item_name"].toString());
                                    if (name.length() >= TAB3)
                                        pdf.codeLine(name, pdf.Justify_left);
                                    else
                                        pdf.codeText(name, pdf.Justify_left);

                                    name = "\t" + QString::number( item["quantity"].toInt() );
                                    pdf.codeText(name, pdf.Justify_left, TAB3-name.length());

                                    name = "\t" + moneyMoney( QString::number( item["amount"].toInt() ));
                                    pdf.codeLine(name, pdf.Justify_left, TAB4-name.length());
                                }
                            }

                            int iThanhtien = jsoIvce["amount"].toInt();
                            QString sThanhtien = "\t" + moneyMoney( QString::number( iThanhtien ) );
                            pdf.codeText("TONG:", pdf.Justify_left, 0);
                            pdf.codeText(sThanhtien, pdf.Justify_left, TAB4-sThanhtien.length());

                            int iThucthu = jsoIvce["real_amount"].toInt();
                            if (iThanhtien > iThucthu)
                            {
                                int iGiamgia = iThanhtien - iThucthu;
                                QString sGiamgia = "\t" + moneyMoney( QString::number( iGiamgia ) );
                                pdf.codeText("GIAM GIA:", pdf.Justify_left, 0);
                                pdf.codeText(sGiamgia, pdf.Justify_left, TAB4-sGiamgia.length());

                                QString sThucthu = "\t" + moneyMoney( QString::number( iThucthu ) );
                                pdf.codeText("THUC THU:", pdf.Justify_left, 0);
                                pdf.codeText(sThucthu, pdf.Justify_left, TAB4-sThucthu.length());
                            }
                            pdf.codeChars('-', PAGESZ, pdf.Justify_center);
                        }
                    }

                    pdf.codeFeedline(1);
                    pdf.codeText("Thank You!", pdf.Justify_center);
                    pdf.codeFeedline(2);

                    pdf.codeFeedline(PAGESZ < 40 ? 2 : 1);
                    pdf.codeCutpage();
                }
            }

            // tra ket qua pdf ve
            return pdf.getPrintDeviceCode();
        }
        else {
            pdf.codeChars('-', PAGESZ, pdf.Justify_center);
            pdf.codeLine("KHONG CO DU LIEU HOP LE");
            pdf.codeChars('-', PAGESZ, pdf.Justify_center);
        }
    }
    else {
        pdf.codeChars('-', PAGESZ, pdf.Justify_center);
        pdf.codeLine("DU LIEU KHONG HOP LE");
        pdf.codeChars('-', PAGESZ, pdf.Justify_center);
    }
    // bao cao data

    pdf.codeFeedline(PAGESZ < 40 ? 2 : 1);
    pdf.codeCutpage();

    return pdf.getPrintDeviceCode();
}

void MainController::printBigData(const QByteArray &data)
{
    int buffsize = 2048;
    int pos = 0;

    while( pos < data.size() )
    {
        int prntsize;

        if ( (pos + buffsize) < data.size() ) {
            prntsize = buffsize;
        }
        else {
            prntsize = data.size() - pos;
        }

        QString prncode = Prntdataformat::makePrintDataFromPrncode(data.mid(pos, prntsize));
        deviceService->print(QString(""), "", prncode, DeviceClient::VPOS_Payment);

        pos += prntsize;
    }
}

void MainController::onStoreProducts(const QJsonObject &storeProducts)
{
    QJsonObject jsonObject = storeProducts["StoreProducts"].toObject();
    QJsonArray categories = jsonObject["Categories"].toArray();
    categories.removeAt(0);
    QJsonArray products = jsonObject["Products"].toArray();
    m_prods_from_dominos = products;
    QJsonObject root;
    foreach (const QJsonValue & category, categories) {
        QJsonArray root_category;
        QString str_category = category.toString();
        foreach (const QJsonValue & product, products) {
            QJsonObject obj_product = product.toObject();
            QString flavorCode = obj_product.value("FlavorCode").toString();
            QString categoryCode = obj_product.value("CategoryCode").toString();
            QString productName = CommonFunction::filterPizzaName(obj_product.value("ProductName").toString()).trimmed();
            obj_product["ProductName"] = productName;
            QString options = obj_product.value("Options").toString();

            if(flavorCode.compare("TCC") != 0 && flavorCode.compare("CC") != 0 && options.compare("OPTION") != 0) {
                if(str_category.compare(categoryCode) == 0) {
                    root_category.insert(0, obj_product);
                }
            }
        }
        root[str_category] = root_category;
    }


    QJsonObject data;
    data["Categories"] = categories;
    data["Products"] = root;
    emit dominosData(data);
}

QString MainController::getProductCode(const QString &pro_name, const QString &prod_size, const QString &prod_plavor_code) {
    QString prod_code = "";
    foreach (const QJsonValue & product, m_prods_from_dominos) {
        QJsonObject obj_product = product.toObject();
//        qDebug() << "obj prod: " << obj_product;
        QString local_flavorCode = obj_product.value("FlavorCode").toString();
        QString local_productName = CommonFunction::filterPizzaName(obj_product.value("ProductName").toString()).trimmed().toUpper();
        QString local_prod_size = obj_product.value("SizeCode").toString();

        if(local_productName.compare(pro_name) == 0 &&
                local_flavorCode.compare(prod_plavor_code) == 0 &&
                local_prod_size.compare(prod_size) == 0) {
            prod_code = obj_product.value("ProductCode").toString();
            break;
        }
    }
    return prod_code;
}

void MainController::onStoreInformation(const QJsonObject &storeInformation)
{
//    qDebug() << "store product list = " << QString::fromStdString(storeInformation.dump());
}

void MainController::placeorder2dominoserver() {
    QJsonObject json_order;
    QJsonObject order;
    json_order["@language"] = "en-USA";
    json_order["@currency"]  = "en-USD";
    json_order["StoreID"] = QString::number(dominoStore);
    json_order["ServiceMethod"] = m_customer_hinhthuc;
    json_order["OrderTakeSeconds"] = "37";
    json_order["DeliveryInstructions"] = "";

    QJsonObject json_OrderSource;
    json_OrderSource["OrganizationURI"] = "dominos.com";
    json_OrderSource["OrderMethod"] = "Zalo";
    json_OrderSource["OrderTaker"] = "Mike";
    json_order["OrderSource"] = json_OrderSource;

    QJsonObject json_Customer;
    json_Customer["@type"] = "Customer-Standard";
    QJsonObject json_CustomerAddress;
    json_CustomerAddress["@type"] = "Address-US";
    json_CustomerAddress["StreetNumber"] = "";
    json_CustomerAddress["StreetName"] = "";
    json_CustomerAddress["AddressLine2"] = "";
    json_CustomerAddress["AddressLine3"] = "";
    json_CustomerAddress["AddressLine4"] = "";
    json_CustomerAddress["UnitType"] = "";
    json_CustomerAddress["UnitNumber"] = "";
    json_CustomerAddress["City"] = "";
    json_CustomerAddress["Region"] = "";
    json_CustomerAddress["PostalCode"] = "";
    json_Customer["CustomerAddress"] = json_CustomerAddress;
    QJsonObject json_Name;
    json_Name["@type"] = "Name-US";
    json_Name["FirstName"] = m_customer_name;
    json_Name["LastName"] =  " - ZALOPAY";
    json_Customer["Name"] = json_Name;
    QJsonObject json_CustomerTypeInfo;
    json_CustomerTypeInfo["@type"] = "";
    json_CustomerTypeInfo["OrganizationName"] = "";
    json_CustomerTypeInfo["Department"] = "";
    json_Customer["CustomerTypeInfo"] = json_CustomerTypeInfo;
    json_Customer["Phone"] = "7345555555";
    json_Customer["Extension"] = "";
    json_Customer["Email"] = "zagreb.glomski@deadletteroffice.com";
    json_Customer["DeliveryInstructions"] = "";
    json_Customer["CustomerTax"] = "";
    json_Customer["LoyaltyNumber"] = "1234567891234567899";
    json_order["Customer"] = json_Customer;

    QJsonArray json_arr_OrderItems;
    QJsonObject json_OrderItems;
    bool find_pizza_discount_40 = false;
    for(int i = 0; i< m_foods.count(); i++) {
        QJsonObject json_OrderItem;
        QJsonObject item = m_foods.at(i).toObject();
        json_OrderItem["ProductCode"] = item["code_name"];
        if(item["size"] == "9\"" || item["size"] == "12\"") {
            json_OrderItem["ProductName"] = item["size"];
            find_pizza_discount_40 = true;
        } else {
            json_OrderItem["ProductName"] = item["item_name"].toString().split("/")[0];
        }

        json_OrderItem["ItemQuantity"] = item["quantity"];
        json_arr_OrderItems.insert(i, json_OrderItem);
    }


    if(find_pizza_discount_40) {
        QJsonObject obj_coupon;
        QJsonObject obj_code;
        QString coupon = this->getIdCoupon();
        obj_code["Code"] = coupon;
        obj_coupon["Coupon"] = obj_code;
        json_order["Coupons"] = obj_coupon;
    }


    json_OrderItems["OrderItem"] = json_arr_OrderItems;
    json_order["OrderItems"] = json_OrderItems;

    QJsonObject json_CashPayment;
    json_CashPayment["CashPayment"] = "";
    json_order["Payment"] = json_CashPayment;

    json_order["LoyaltyNumber"] = "1234567891234567899";

    order["Order"] = json_order;

    dominoCtrl.placeOrder(order);
//    m_customer_hinhthuc = "";
//    m_customer_name = "";
}

long long MainController::getPriceCoupon(long long price, const QString &pizza_size) {
    float _percent  = this->getIdCouponPercent().toFloat();
    long long promote_price = 0;
    if(pizza_size.compare("9") == 0 || pizza_size.compare("12") == 0) {
        promote_price = price * (1 - _percent);
    }
    return promote_price;
}

void MainController::removeItemInPaymentView(int row, const QString& prod_type, const QString& size_banh, const QString& de_banh, const QString& phomai) {
    emit removeItemPaymentView(row, prod_type, size_banh, de_banh, phomai);
}

void MainController::closeThanhtoan(int popupid) {
    qDebug() << "begin close";
    if(popupid == 0) {
        emit closePopup(popupid, "");
    }
    if(popupid == 1) {
        emit closePopupSelectPizza(popupid, "");
    }
}

