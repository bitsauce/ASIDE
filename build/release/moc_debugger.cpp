/****************************************************************************
** Meta object code from reading C++ file 'debugger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/debugger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Debugger_t {
    QByteArrayData data[25];
    char stringdata[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Debugger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Debugger_t qt_meta_stringdata_Debugger = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 15),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 15),
QT_MOC_LITERAL(4, 42, 8),
QT_MOC_LITERAL(5, 51, 4),
QT_MOC_LITERAL(6, 56, 11),
QT_MOC_LITERAL(7, 68, 9),
QT_MOC_LITERAL(8, 78, 9),
QT_MOC_LITERAL(9, 88, 6),
QT_MOC_LITERAL(10, 95, 4),
QT_MOC_LITERAL(11, 100, 8),
QT_MOC_LITERAL(12, 109, 8),
QT_MOC_LITERAL(13, 118, 7),
QT_MOC_LITERAL(14, 126, 13),
QT_MOC_LITERAL(15, 140, 12),
QT_MOC_LITERAL(16, 153, 17),
QT_MOC_LITERAL(17, 171, 3),
QT_MOC_LITERAL(18, 175, 3),
QT_MOC_LITERAL(19, 179, 13),
QT_MOC_LITERAL(20, 193, 9),
QT_MOC_LITERAL(21, 203, 3),
QT_MOC_LITERAL(22, 207, 20),
QT_MOC_LITERAL(23, 228, 6),
QT_MOC_LITERAL(24, 235, 18)
    },
    "Debugger\0execInitialized\0\0execInterrupted\0"
    "filePath\0line\0execResumed\0execEnded\0"
    "interrupt\0resume\0stop\0stepOver\0stepInto\0"
    "stepOut\0startProfiler\0stopProfiler\0"
    "cellDoubleClicked\0row\0col\0processPacket\0"
    "gameEnded\0ret\0QProcess::ExitStatus\0"
    "status\0sendAllBreakpoints"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Debugger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    2,   95,    2, 0x06 /* Public */,
       6,    0,  100,    2, 0x06 /* Public */,
       7,    0,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  102,    2, 0x0a /* Public */,
       9,    0,  103,    2, 0x0a /* Public */,
      10,    0,  104,    2, 0x0a /* Public */,
      11,    0,  105,    2, 0x0a /* Public */,
      12,    0,  106,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,
      16,    2,  110,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,
      20,    2,  116,    2, 0x08 /* Private */,
      24,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 22,   21,   23,
    QMetaType::Void,

       0        // eod
};

void Debugger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Debugger *_t = static_cast<Debugger *>(_o);
        switch (_id) {
        case 0: _t->execInitialized(); break;
        case 1: _t->execInterrupted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->execResumed(); break;
        case 3: _t->execEnded(); break;
        case 4: _t->interrupt(); break;
        case 5: _t->resume(); break;
        case 6: _t->stop(); break;
        case 7: _t->stepOver(); break;
        case 8: _t->stepInto(); break;
        case 9: _t->stepOut(); break;
        case 10: _t->startProfiler(); break;
        case 11: _t->stopProfiler(); break;
        case 12: _t->cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->processPacket(); break;
        case 14: _t->gameEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 15: _t->sendAllBreakpoints(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Debugger::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Debugger::execInitialized)) {
                *result = 0;
            }
        }
        {
            typedef void (Debugger::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Debugger::execInterrupted)) {
                *result = 1;
            }
        }
        {
            typedef void (Debugger::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Debugger::execResumed)) {
                *result = 2;
            }
        }
        {
            typedef void (Debugger::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Debugger::execEnded)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Debugger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Debugger.data,
      qt_meta_data_Debugger,  qt_static_metacall, 0, 0}
};


const QMetaObject *Debugger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Debugger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Debugger.stringdata))
        return static_cast<void*>(const_cast< Debugger*>(this));
    return QObject::qt_metacast(_clname);
}

int Debugger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Debugger::execInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Debugger::execInterrupted(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Debugger::execResumed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Debugger::execEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
struct qt_meta_stringdata_OutputWidget_t {
    QByteArrayData data[1];
    char stringdata[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OutputWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OutputWidget_t qt_meta_stringdata_OutputWidget = {
    {
QT_MOC_LITERAL(0, 0, 12)
    },
    "OutputWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OutputWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void OutputWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject OutputWidget::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_OutputWidget.data,
      qt_meta_data_OutputWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *OutputWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OutputWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OutputWidget.stringdata))
        return static_cast<void*>(const_cast< OutputWidget*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int OutputWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
