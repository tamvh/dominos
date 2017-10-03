#include "dominocontroller.h"
#include <QDebug>
#include "http/httpbase2.h"
#include "functionutils.h"

DominoController::DominoController(QObject *parent) :
    _domainMessage("http://www.dominos.com/message/"),
    _domainAction("http://www.dominos.com/action/%1"),
    QObject(parent)
{

}

bool DominoController::initizalize(const QString &username, const QString &password, const QString &domain)
{
    _username = username;
    _password = password;
    _serverDomain = domain + "/remotepulseapi/remotepulseapi.wsdl";
    return true;
}

QJsonDocument DominoController::getSoapJson(const QString &bodyName, QJsonObject &bodyJson)
{
    QJsonObject soapRoot;
    QJsonObject soapRootInfo;
    soapRootInfo["@xmlns:SOAP-ENVELOPE"] = "http://schemas.xmlsoap.org/soap/envelope/";
    soapRootInfo["SOAP-ENVELOPE:Header"] = getSoapHeader(1);
    soapRootInfo["SOAP-ENVELOPE:Body"] = getSoapBody(bodyName, bodyJson);
    soapRoot["SOAP-ENVELOPE:Envelope"] = soapRootInfo;
    return QJsonDocument(soapRoot);

}

QJsonObject DominoController::getSoapHeader(int temp)
{
    QJsonObject soapHeader;
    QJsonObject authorization;

    authorization["FromURI"] = "dominos.com";
    authorization["User"] = _username;
    authorization["Password"] = _password;
    authorization["TimeStamp"] = "";
    soapHeader["Authorization"] = authorization;
    return soapHeader;
}

QJsonObject DominoController::getSoapBody(const QString &bodyName, QJsonObject &bodyJson)
{
    QJsonObject soapBody;
    soapBody["@SOAP-ENVELOPE:encodingStyle"] = "http://schemas.xmlsoap.org/soap/encoding/";
    soapBody[bodyName] = bodyJson;
    return soapBody;

}

bool DominoController::getStoreInformation(int storeId)
{
    QJsonObject bodyJson;
    bodyJson["@xmlns:DOMINOS"] = _domainMessage;
    bodyJson["StoreID"] = storeId;

    QJsonDocument soapJson = getSoapJson("DOMINOS:GetStoreInformation", bodyJson);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetStoreInformationFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", "http://www.dominos.com/action/GetStoreInformation");
    http->process(POST, nullptr, doc.toString(0).toUtf8());

    return true;
}

bool DominoController::GetStoreStreets(int storeId, bool getAll)
{
    QJsonObject bodyJson;
    bodyJson["@xmlns:DOMINOS"] = _domainMessage;
    bodyJson["StoreID"] = storeId;
    bodyJson["AllStreets"] = getAll;

    QJsonDocument soapJson = getSoapJson("DOMINOS:GetStoreStreets", bodyJson);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetStoreStreetsFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);


    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", "http://www.dominos.com/action/GetStoreInformation");
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::getStoreProducts(int storeId)
{
    QJsonObject bodyJson;
    bodyJson["@xmlns:DOMINOS"] = _domainMessage;
    bodyJson["StoreID"] = storeId;

    QJsonDocument soapJson = getSoapJson("DOMINOS:GetStoreProducts", bodyJson);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetStoreProductsFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);


    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", "http://www.dominos.com/action/GetStoreProducts");
    http->process(POST, nullptr, doc.toString(0).toUtf8());

    return false;
}

bool DominoController::getStoreCoupons(int storeId)
{
    QJsonObject bodyJson;
    bodyJson["@xmlns:DOMINOS"] = _domainMessage;
    bodyJson["StoreID"] = storeId;

    QJsonDocument soapJson = getSoapJson("DOMINOS:GetStoreCoupons", bodyJson);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetStoreCouponsFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", "http://www.dominos.com/action/GetStoreInformation");
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::placeOrder(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:PlaceOrder", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onPlaceOrderFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("PlaceOrder"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::PlaceEditedOrder(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:PlaceEditedOrder", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onPlaceEditOrderFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("PlaceEditedOrder"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::PriceOrder(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:PriceOrder", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onPriceOrderFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("PriceOrder"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::GetOrderStatus(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:GetOrderStatus", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetOrderStatusFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("GetOrderStatus"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::GetOrderStatuses(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:GetOrderStatuses", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onGetOrderStatusesFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("GetOrderStatuses"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

bool DominoController::CancelOrder(QJsonObject &requestInfo)
{
    requestInfo["@xmlns:DOMINOS"] = _domainMessage;
    QJsonDocument soapJson = getSoapJson("DOMINOS:CancelOrder", requestInfo);
    QDomDocument doc = FunctionUtils::convertJsonToXml(soapJson);

    HttpBase *http = new HttpBase(QString(""), this);
    QObject::connect(http, SIGNAL(done(QVariant)), this, SLOT(onCancelOrderFinish(QVariant)), Qt::UniqueConnection);
    QObject::connect(http, SIGNAL(error(int,QString)), this, SLOT(onPostError(int, QString)), Qt::UniqueConnection);

    http->setContentType(CONTENT_TYPE_TEXT_XML);
    http->setUrl(QUrl(_serverDomain));
    http->addHeader("SOAPAction", _domainAction.arg("CancelOrder"));
    http->process(POST, nullptr, doc.toString(0).toUtf8());
    return true;
}

void DominoController::onGetStoreInformationFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "StoreInformation");
    emit eventStoreInformation(result);
}

void DominoController::onGetStoreProductsFinish(const QVariant &data)
{
    QDomDocument doc;
    doc.setContent(data.toString());
    QDomNodeList nodeList = doc.elementsByTagName("Products");
    if (nodeList.size() > 0) {
        QJsonObject products = parseStoreProducts(nodeList.at(0).childNodes().at(0).nodeValue().replace("-", ""));
        emit eventStoreProducts(products);
    }

}

void DominoController::onGetStoreStreetsFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "StoreStreets");
    emit eventStoreStreets(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onGetStoreCouponsFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "StoreCoupons");
    emit eventStoreCoupons(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onPlaceOrderFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderReply");
    emit eventPlaceOrder(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onPlaceEditOrderFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderReply");
    emit evenPlaceEditOrder(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onPriceOrderFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderReply");
    emit evenPriceOrder(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onGetOrderStatusFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderReply");
    emit evenGetOrderStatus(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onGetOrderStatusesFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderStatuses");
    emit evenGetOrderStatuses(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onCancelOrderFinish(const QVariant &data)
{
    QJsonObject result = FunctionUtils::convertXmlToJson(data.toString(), "OrderReply");
    emit evenCancelOrder(result);

    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

void DominoController::onPostError(const int &error, const QString &message)
{
    qDebug() << "on post error " << error << ", message = " << message;
    emit eventPlaceOrderErr(QString::number(error));
    HttpBase *http = qobject_cast<HttpBase*>(sender());
    http->deleteLater();
}

QJsonObject DominoController::parseStoreProducts(const QString &productText)
{
    QJsonObject rootJson;
    QJsonObject storeProducts;
    QJsonArray productsJson;
    QJsonArray categoryCodes;

    QStringList eleList = productText.split("\r\n");
    if (eleList.length() <= 0) {
        return {};
    }

    QStringList colNameList = eleList.at(0).split("\t");
    QStringList colValueList;
    int colLength = 0;

    for (int i = 1; i < eleList.size(); i++) {
        QJsonObject product;
        colValueList = eleList.at(i).split("\t");
        colLength = colValueList.length() <= colNameList.length() ? colValueList.length() : colNameList.length();
        for (int j = 0; j < colLength; j++) {
            product[colNameList.at(j)] = colValueList.at(j);

            if (j == 0) {
                bool exist = false;
                for (QJsonArray::iterator it = categoryCodes.begin(); it != categoryCodes.end(); ++it) {
                    if (it->toString().compare(product[colNameList.at(j)].toString()) == 0) {
                        exist = true;
                    }
                }
                if (!exist) {
                    categoryCodes.append(colValueList.at(j));
                }
            }
        }
        productsJson.push_back(product);
    }

    storeProducts["Products"] = productsJson;
    storeProducts["Categories"] = categoryCodes;
    rootJson["StoreProducts"] = storeProducts;

    return rootJson;
}


