/****************************************************************************
** Meta object code from reading C++ file 'dominocontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../domino/dominocontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dominocontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DominoController_t {
    QByteArrayData data[27];
    char stringdata0[476];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DominoController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DominoController_t qt_meta_stringdata_DominoController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DominoController"
QT_MOC_LITERAL(1, 17, 18), // "eventStoreProducts"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "storeProducts"
QT_MOC_LITERAL(4, 51, 21), // "eventStoreInformation"
QT_MOC_LITERAL(5, 73, 17), // "eventStoreStreets"
QT_MOC_LITERAL(6, 91, 17), // "eventStoreCoupons"
QT_MOC_LITERAL(7, 109, 15), // "eventPlaceOrder"
QT_MOC_LITERAL(8, 125, 18), // "evenPlaceEditOrder"
QT_MOC_LITERAL(9, 144, 14), // "evenPriceOrder"
QT_MOC_LITERAL(10, 159, 18), // "evenGetOrderStatus"
QT_MOC_LITERAL(11, 178, 20), // "evenGetOrderStatuses"
QT_MOC_LITERAL(12, 199, 15), // "evenCancelOrder"
QT_MOC_LITERAL(13, 215, 27), // "onGetStoreInformationFinish"
QT_MOC_LITERAL(14, 243, 4), // "data"
QT_MOC_LITERAL(15, 248, 24), // "onGetStoreProductsFinish"
QT_MOC_LITERAL(16, 273, 23), // "onGetStoreStreetsFinish"
QT_MOC_LITERAL(17, 297, 23), // "onGetStoreCouponsFinish"
QT_MOC_LITERAL(18, 321, 18), // "onPlaceOrderFinish"
QT_MOC_LITERAL(19, 340, 22), // "onPlaceEditOrderFinish"
QT_MOC_LITERAL(20, 363, 18), // "onPriceOrderFinish"
QT_MOC_LITERAL(21, 382, 22), // "onGetOrderStatusFinish"
QT_MOC_LITERAL(22, 405, 24), // "onGetOrderStatusesFinish"
QT_MOC_LITERAL(23, 430, 19), // "onCancelOrderFinish"
QT_MOC_LITERAL(24, 450, 11), // "onPostError"
QT_MOC_LITERAL(25, 462, 5), // "error"
QT_MOC_LITERAL(26, 468, 7) // "message"

    },
    "DominoController\0eventStoreProducts\0"
    "\0storeProducts\0eventStoreInformation\0"
    "eventStoreStreets\0eventStoreCoupons\0"
    "eventPlaceOrder\0evenPlaceEditOrder\0"
    "evenPriceOrder\0evenGetOrderStatus\0"
    "evenGetOrderStatuses\0evenCancelOrder\0"
    "onGetStoreInformationFinish\0data\0"
    "onGetStoreProductsFinish\0"
    "onGetStoreStreetsFinish\0onGetStoreCouponsFinish\0"
    "onPlaceOrderFinish\0onPlaceEditOrderFinish\0"
    "onPriceOrderFinish\0onGetOrderStatusFinish\0"
    "onGetOrderStatusesFinish\0onCancelOrderFinish\0"
    "onPostError\0error\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DominoController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       5,    1,  125,    2, 0x06 /* Public */,
       6,    1,  128,    2, 0x06 /* Public */,
       7,    1,  131,    2, 0x06 /* Public */,
       8,    1,  134,    2, 0x06 /* Public */,
       9,    1,  137,    2, 0x06 /* Public */,
      10,    1,  140,    2, 0x06 /* Public */,
      11,    1,  143,    2, 0x06 /* Public */,
      12,    1,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  149,    2, 0x0a /* Public */,
      15,    1,  152,    2, 0x0a /* Public */,
      16,    1,  155,    2, 0x0a /* Public */,
      17,    1,  158,    2, 0x0a /* Public */,
      18,    1,  161,    2, 0x0a /* Public */,
      19,    1,  164,    2, 0x0a /* Public */,
      20,    1,  167,    2, 0x0a /* Public */,
      21,    1,  170,    2, 0x0a /* Public */,
      22,    1,  173,    2, 0x0a /* Public */,
      23,    1,  176,    2, 0x0a /* Public */,
      24,    2,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::QVariant,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   25,   26,

       0        // eod
};

void DominoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DominoController *_t = static_cast<DominoController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->eventStoreProducts((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->eventStoreInformation((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 2: _t->eventStoreStreets((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 3: _t->eventStoreCoupons((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 4: _t->eventPlaceOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 5: _t->evenPlaceEditOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 6: _t->evenPriceOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 7: _t->evenGetOrderStatus((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 8: _t->evenGetOrderStatuses((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 9: _t->evenCancelOrder((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 10: _t->onGetStoreInformationFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 11: _t->onGetStoreProductsFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 12: _t->onGetStoreStreetsFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 13: _t->onGetStoreCouponsFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 14: _t->onPlaceOrderFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 15: _t->onPlaceEditOrderFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 16: _t->onPriceOrderFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 17: _t->onGetOrderStatusFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 18: _t->onGetOrderStatusesFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 19: _t->onCancelOrderFinish((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 20: _t->onPostError((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::eventStoreProducts)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::eventStoreInformation)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::eventStoreStreets)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::eventStoreCoupons)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::eventPlaceOrder)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::evenPlaceEditOrder)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::evenPriceOrder)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::evenGetOrderStatus)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::evenGetOrderStatuses)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (DominoController::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DominoController::evenCancelOrder)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject DominoController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DominoController.data,
      qt_meta_data_DominoController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DominoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DominoController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DominoController.stringdata0))
        return static_cast<void*>(const_cast< DominoController*>(this));
    return QObject::qt_metacast(_clname);
}

int DominoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void DominoController::eventStoreProducts(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DominoController::eventStoreInformation(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DominoController::eventStoreStreets(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DominoController::eventStoreCoupons(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DominoController::eventPlaceOrder(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DominoController::evenPlaceEditOrder(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DominoController::evenPriceOrder(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DominoController::evenGetOrderStatus(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DominoController::evenGetOrderStatuses(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DominoController::evenCancelOrder(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
