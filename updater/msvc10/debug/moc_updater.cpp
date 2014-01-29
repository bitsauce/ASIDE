/****************************************************************************
** Meta object code from reading C++ file 'updater.h'
**
** Created: Mon 24. Dec 01:47:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/updater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Updater[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,    9,    8, 0x0a,
      37,    8,    9,    8, 0x0a,
      51,    8,    8,    8, 0x0a,
      92,   67,    8,    8, 0x08,
     124,    8,    8,    8, 0x08,
     143,    8,    8,    8, 0x08,
     169,  163,    8,    8, 0x08,
     232,  228,  212,    8, 0x08,
     251,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Updater[] = {
    "Updater\0\0bool\0version\0hasUpdate(int)\0"
    "fetchUpdate()\0installUpdate()\0"
    "bytesReceived,bytesTotal\0"
    "downloadProgress(qint64,qint64)\0"
    "downloadFinished()\0downloadReadyRead()\0"
    "error\0downloadError(QNetworkReply::NetworkError)\0"
    "QTemporaryFile*\0url\0downloadFile(QUrl)\0"
    "closeEvent(QCloseEvent*)\0"
};

void Updater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Updater *_t = static_cast<Updater *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->hasUpdate((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->fetchUpdate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->installUpdate(); break;
        case 3: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->downloadFinished(); break;
        case 5: _t->downloadReadyRead(); break;
        case 6: _t->downloadError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 7: { QTemporaryFile* _r = _t->downloadFile((*reinterpret_cast< QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTemporaryFile**>(_a[0]) = _r; }  break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Updater::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Updater::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Updater,
      qt_meta_data_Updater, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Updater::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Updater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Updater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Updater))
        return static_cast<void*>(const_cast< Updater*>(this));
    return QDialog::qt_metacast(_clname);
}

int Updater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
