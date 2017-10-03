#ifndef DOMINOAPI_H
#define DOMINOAPI_H

#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

class DominoController : public QObject
{
    Q_OBJECT
public:
    explicit DominoController(QObject *parent = 0);
    bool initizalize(const QString &username, const QString &password, const QString &domain);
signals:
    void eventStoreProducts(const QJsonObject &storeProducts);
    void eventStoreInformation(const QJsonObject &storeProducts);
    void eventStoreStreets(const QJsonObject &storeProducts);
    void eventStoreCoupons(const QJsonObject &storeProducts);
    void eventPlaceOrder(const QJsonObject &storeProducts);
    void eventPlaceOrderErr(const QString &err);
    void evenPlaceEditOrder(const QJsonObject &storeProducts);
    void evenPriceOrder(const QJsonObject &storeProducts);
    void evenGetOrderStatus(const QJsonObject &storeProducts);
    void evenGetOrderStatuses(const QJsonObject &storeProducts);
    void evenCancelOrder(const QJsonObject &storeProducts);

public slots:
    void onGetStoreInformationFinish(const QVariant &data);
    void onGetStoreProductsFinish(const QVariant &data);
    void onGetStoreStreetsFinish(const QVariant &data);
    void onGetStoreCouponsFinish(const QVariant &data);
    void onPlaceOrderFinish(const QVariant &data);
    void onPlaceEditOrderFinish(const QVariant &data);
    void onPriceOrderFinish(const QVariant &data);
    void onGetOrderStatusFinish(const QVariant &data);
    void onGetOrderStatusesFinish(const QVariant &data);
    void onCancelOrderFinish(const QVariant &data);
    void onPostError(const int &error, const QString &message);

public:
    bool getStoreInformation(int storeId);
    bool GetStoreStreets(int storeId, bool getAll);
    bool getStoreProducts(int storeId);
    bool getStoreCoupons(int storeId);
    bool placeOrder(QJsonObject& requestInfo);
    bool PlaceEditedOrder(QJsonObject& requestInfo);
    bool PriceOrder(QJsonObject& requestInfo);
    bool GetOrderStatus(QJsonObject& requestInfo);
    bool GetOrderStatuses(QJsonObject& requestInfo);
    bool CancelOrder(QJsonObject& requestInfo);

private:
    QJsonDocument getSoapJson(const QString &bodyName, QJsonObject &bodyJson);
    QJsonObject getSoapHeader(int temp);
    QJsonObject getSoapBody(const QString &bodyName, QJsonObject &bodyJson);

    QJsonObject parseStoreProducts(const QString &productText);

private:
    QString _username;
    QString _password;
    QString _serverDomain;
    QString _domainMessage;
    QString _domainAction;
};

#endif // DOMINOAPI_H
