/****************************************************************************
** Meta object code from reading C++ file 'downloadfileman.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../domino_v2/downloadfileman.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadfileman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CDownloadFileMan_t {
    QByteArrayData data[10];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDownloadFileMan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDownloadFileMan_t qt_meta_stringdata_CDownloadFileMan = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CDownloadFileMan"
QT_MOC_LITERAL(1, 17, 22), // "NotifyDownloadNextFile"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 18), // "NotifyDownloadDone"
QT_MOC_LITERAL(4, 60, 14), // "NotifyComplete"
QT_MOC_LITERAL(5, 75, 4), // "data"
QT_MOC_LITERAL(6, 80, 13), // "HttpReadyRead"
QT_MOC_LITERAL(7, 94, 20), // "HttpDownloadFinished"
QT_MOC_LITERAL(8, 115, 16), // "DownloadNextFile"
QT_MOC_LITERAL(9, 132, 12) // "DownloadDone"

    },
    "CDownloadFileMan\0NotifyDownloadNextFile\0"
    "\0NotifyDownloadDone\0NotifyComplete\0"
    "data\0HttpReadyRead\0HttpDownloadFinished\0"
    "DownloadNextFile\0DownloadDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDownloadFileMan[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CDownloadFileMan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CDownloadFileMan *_t = static_cast<CDownloadFileMan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NotifyDownloadNextFile(); break;
        case 1: _t->NotifyDownloadDone(); break;
        case 2: _t->NotifyComplete((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->HttpReadyRead(); break;
        case 4: _t->HttpDownloadFinished(); break;
        case 5: _t->DownloadNextFile(); break;
        case 6: _t->DownloadDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CDownloadFileMan::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CDownloadFileMan::NotifyDownloadNextFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CDownloadFileMan::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CDownloadFileMan::NotifyDownloadDone)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CDownloadFileMan::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CDownloadFileMan::NotifyComplete)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CDownloadFileMan::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CDownloadFileMan.data,
      qt_meta_data_CDownloadFileMan,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CDownloadFileMan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDownloadFileMan::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CDownloadFileMan.stringdata0))
        return static_cast<void*>(const_cast< CDownloadFileMan*>(this));
    return QObject::qt_metacast(_clname);
}

int CDownloadFileMan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CDownloadFileMan::NotifyDownloadNextFile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CDownloadFileMan::NotifyDownloadDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CDownloadFileMan::NotifyComplete(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
