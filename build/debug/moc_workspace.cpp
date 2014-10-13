/****************************************************************************
** Meta object code from reading C++ file 'workspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/workspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Workspace_t {
    QByteArrayData data[12];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Workspace_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Workspace_t qt_meta_stringdata_Workspace = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 17),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 14),
QT_MOC_LITERAL(4, 44, 7),
QT_MOC_LITERAL(5, 52, 11),
QT_MOC_LITERAL(6, 64, 8),
QT_MOC_LITERAL(7, 73, 9),
QT_MOC_LITERAL(8, 83, 8),
QT_MOC_LITERAL(9, 92, 11),
QT_MOC_LITERAL(10, 104, 10),
QT_MOC_LITERAL(11, 115, 23)
    },
    "Workspace\0promptSaveChanges\0\0"
    "promptCloseAll\0saveAll\0saveCurrent\0"
    "openFile\0fileSaved\0filePath\0fileChanged\0"
    "fileClosed\0removeFromRecentlySaved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Workspace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,
      10,    1,   70,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void Workspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Workspace *_t = static_cast<Workspace *>(_o);
        switch (_id) {
        case 0: { int _r = _t->promptSaveChanges();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->promptCloseAll();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->saveAll(); break;
        case 3: _t->saveCurrent(); break;
        case 4: _t->openFile(); break;
        case 5: _t->fileSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->fileClosed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->removeFromRecentlySaved(); break;
        default: ;
        }
    }
}

const QMetaObject Workspace::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Workspace.data,
      qt_meta_data_Workspace,  qt_static_metacall, 0, 0}
};


const QMetaObject *Workspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Workspace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Workspace.stringdata))
        return static_cast<void*>(const_cast< Workspace*>(this));
    return QWidget::qt_metacast(_clname);
}

int Workspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
struct qt_meta_stringdata_WorkspaceToolbar_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkspaceToolbar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkspaceToolbar_t qt_meta_stringdata_WorkspaceToolbar = {
    {
QT_MOC_LITERAL(0, 0, 16)
    },
    "WorkspaceToolbar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkspaceToolbar[] = {

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

void WorkspaceToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject WorkspaceToolbar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_WorkspaceToolbar.data,
      qt_meta_data_WorkspaceToolbar,  qt_static_metacall, 0, 0}
};


const QMetaObject *WorkspaceToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkspaceToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WorkspaceToolbar.stringdata))
        return static_cast<void*>(const_cast< WorkspaceToolbar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int WorkspaceToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
