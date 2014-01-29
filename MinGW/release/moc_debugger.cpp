/****************************************************************************
** Meta object code from reading C++ file 'debugger.h'
**
** Created: Tue 10. Jul 17:38:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/debugger.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Debugger[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      73,    9,    9,    9, 0x08,
      89,    9,    9,    9, 0x08,
     105,    9,    9,    9, 0x08,
     121,    9,    9,    9, 0x08,
     136,    9,    9,    9, 0x08,
     149,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Debugger[] = {
    "Debugger\0\0state\0"
    "stateChanged(QAbstractSocket::SocketState)\0"
    "processData()\0debugContinue()\0"
    "debugStepOver()\0debugStepInto()\0"
    "debugStepOut()\0debugPause()\0debugStop()\0"
};

const QMetaObject Debugger::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Debugger,
      qt_meta_data_Debugger, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Debugger::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Debugger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Debugger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Debugger))
        return static_cast<void*>(const_cast< Debugger*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Debugger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 1: processData(); break;
        case 2: debugContinue(); break;
        case 3: debugStepOver(); break;
        case 4: debugStepInto(); break;
        case 5: debugStepOut(); break;
        case 6: debugPause(); break;
        case 7: debugStop(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
