/****************************************************************************
** Meta object code from reading C++ file 'httpbase2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../domino_v2/http/httpbase2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpbase2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HttpBase2_t {
    QByteArrayData data[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpBase2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpBase2_t qt_meta_stringdata_HttpBase2 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HttpBase2"
QT_MOC_LITERAL(1, 10, 4), // "done"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "outputObject"
QT_MOC_LITERAL(4, 29, 5), // "error"
QT_MOC_LITERAL(5, 35, 9), // "errorCode"
QT_MOC_LITERAL(6, 45, 12), // "errorMessage"
QT_MOC_LITERAL(7, 58, 7), // "process"
QT_MOC_LITERAL(8, 66, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 81, 12), // "HTTP_PROCESS"
QT_MOC_LITERAL(10, 94, 11), // "processType"
QT_MOC_LITERAL(11, 106, 10), // "QIODevice*"
QT_MOC_LITERAL(12, 117, 8), // "iostream"
QT_MOC_LITERAL(13, 126, 8) // "finished"

    },
    "HttpBase2\0done\0\0outputObject\0error\0"
    "errorCode\0errorMessage\0process\0"
    "QNetworkReply*\0HTTP_PROCESS\0processType\0"
    "QIODevice*\0iostream\0finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpBase2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   52,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   60,    2, 0x2a /* Public | MethodCloned */,
      13,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,

 // slots: parameters
    0x80000000 | 8, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    0x80000000 | 8, 0x80000000 | 9,   10,
    0x80000000 | 8,
    QMetaType::Void,

       0        // eod
};

void HttpBase2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpBase2 *_t = static_cast<HttpBase2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: { QNetworkReply* _r = _t->process((*reinterpret_cast< const HTTP_PROCESS(*)>(_a[1])),(*reinterpret_cast< QIODevice*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 3: { QNetworkReply* _r = _t->process((*reinterpret_cast< const HTTP_PROCESS(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 4: { QNetworkReply* _r = _t->process();
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 5: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpBase2::*_t)(const QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpBase2::done)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HttpBase2::*_t)(const int & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpBase2::error)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject HttpBase2::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpBase2.data,
      qt_meta_data_HttpBase2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpBase2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpBase2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpBase2.stringdata0))
        return static_cast<void*>(const_cast< HttpBase2*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpBase2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HttpBase2::done(const QVariant & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpBase2::error(const int & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
