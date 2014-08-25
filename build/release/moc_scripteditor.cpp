/****************************************************************************
** Meta object code from reading C++ file 'scripteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/scripteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScriptGoTo_t {
    QByteArrayData data[4];
    char stringdata[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptGoTo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptGoTo_t qt_meta_stringdata_ScriptGoTo = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4)
    },
    "ScriptGoTo\0gotoLine\0\0line"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptGoTo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       1,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ScriptGoTo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptGoTo *_t = static_cast<ScriptGoTo *>(_o);
        switch (_id) {
        case 0: _t->gotoLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->gotoLine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptGoTo::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptGoTo::gotoLine)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScriptGoTo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScriptGoTo.data,
      qt_meta_data_ScriptGoTo,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptGoTo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptGoTo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptGoTo.stringdata))
        return static_cast<void*>(const_cast< ScriptGoTo*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScriptGoTo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ScriptGoTo::gotoLine(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ScriptSearch_t {
    QByteArrayData data[14];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptSearch_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptSearch_t qt_meta_stringdata_ScriptSearch = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 7),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 6),
QT_MOC_LITERAL(4, 29, 6),
QT_MOC_LITERAL(5, 36, 7),
QT_MOC_LITERAL(6, 44, 6),
QT_MOC_LITERAL(7, 51, 9),
QT_MOC_LITERAL(8, 61, 10),
QT_MOC_LITERAL(9, 72, 4),
QT_MOC_LITERAL(10, 77, 14),
QT_MOC_LITERAL(11, 92, 15),
QT_MOC_LITERAL(12, 108, 14),
QT_MOC_LITERAL(13, 123, 14)
    },
    "ScriptSearch\0findAll\0\0search\0phrase\0"
    "forward\0regexp\0matchCase\0wholeWords\0"
    "next\0searchForwards\0searchBackwards\0"
    "setNextDefault\0setPrevDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptSearch[] = {

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
       3,    5,   50,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    0,   64,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    4,    5,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScriptSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptSearch *_t = static_cast<ScriptSearch *>(_o);
        switch (_id) {
        case 0: _t->findAll(); break;
        case 1: _t->search((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->next(); break;
        case 3: _t->searchForwards(); break;
        case 4: _t->searchBackwards(); break;
        case 5: _t->setNextDefault(); break;
        case 6: _t->setPrevDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptSearch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::findAll)) {
                *result = 0;
            }
        }
        {
            typedef void (ScriptSearch::*_t)(const QString & , bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::search)) {
                *result = 1;
            }
        }
        {
            typedef void (ScriptSearch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::next)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ScriptSearch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScriptSearch.data,
      qt_meta_data_ScriptSearch,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptSearch.stringdata))
        return static_cast<void*>(const_cast< ScriptSearch*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScriptSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ScriptSearch::findAll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScriptSearch::search(const QString & _t1, bool _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScriptSearch::next()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
struct qt_meta_stringdata_ScriptReplace_t {
    QByteArrayData data[5];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptReplace_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptReplace_t qt_meta_stringdata_ScriptReplace = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 6),
QT_MOC_LITERAL(4, 30, 16)
    },
    "ScriptReplace\0replace\0\0phrase\0"
    "replaceSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptReplace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ScriptReplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptReplace *_t = static_cast<ScriptReplace *>(_o);
        switch (_id) {
        case 0: _t->replace((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->replaceSelection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptReplace::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptReplace::replace)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScriptReplace::staticMetaObject = {
    { &ScriptSearch::staticMetaObject, qt_meta_stringdata_ScriptReplace.data,
      qt_meta_data_ScriptReplace,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptReplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptReplace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptReplace.stringdata))
        return static_cast<void*>(const_cast< ScriptReplace*>(this));
    return ScriptSearch::qt_metacast(_clname);
}

int ScriptReplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScriptSearch::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ScriptReplace::replace(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ScriptEditor_t {
    QByteArrayData data[28];
    char stringdata[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptEditor_t qt_meta_stringdata_ScriptEditor = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 4),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 19),
QT_MOC_LITERAL(5, 44, 4),
QT_MOC_LITERAL(6, 49, 3),
QT_MOC_LITERAL(7, 53, 15),
QT_MOC_LITERAL(8, 69, 14),
QT_MOC_LITERAL(9, 84, 8),
QT_MOC_LITERAL(10, 93, 16),
QT_MOC_LITERAL(11, 110, 6),
QT_MOC_LITERAL(12, 117, 6),
QT_MOC_LITERAL(13, 124, 7),
QT_MOC_LITERAL(14, 132, 6),
QT_MOC_LITERAL(15, 139, 9),
QT_MOC_LITERAL(16, 149, 10),
QT_MOC_LITERAL(17, 160, 8),
QT_MOC_LITERAL(18, 169, 7),
QT_MOC_LITERAL(19, 177, 17),
QT_MOC_LITERAL(20, 195, 16),
QT_MOC_LITERAL(21, 212, 10),
QT_MOC_LITERAL(22, 223, 16),
QT_MOC_LITERAL(23, 240, 21),
QT_MOC_LITERAL(24, 262, 9),
QT_MOC_LITERAL(25, 272, 16),
QT_MOC_LITERAL(26, 289, 5),
QT_MOC_LITERAL(27, 295, 2)
    },
    "ScriptEditor\0save\0\0load\0updatePositionLabel\0"
    "line\0col\0aboutToActivate\0showScriptGoTo\0"
    "gotoLine\0showScriptSearch\0search\0"
    "phrase\0forward\0regexp\0matchCase\0"
    "wholeWords\0findNext\0findAll\0"
    "showScriptReplace\0replaceSelection\0"
    "replaceAll\0toggleBreakpoint\0"
    "Qt::KeyboardModifiers\0modifiers\0"
    "lineCountChanged\0start\0dt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    2,   91,    2, 0x0a /* Public */,
       7,    0,   96,    2, 0x0a /* Public */,
       8,    0,   97,    2, 0x0a /* Public */,
       9,    1,   98,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    5,  102,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    0,  115,    2, 0x0a /* Public */,
      20,    1,  116,    2, 0x0a /* Public */,
      21,    0,  119,    2, 0x0a /* Public */,
      22,    3,  120,    2, 0x0a /* Public */,
      25,    2,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 23,    2,    5,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,

       0        // eod
};

void ScriptEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptEditor *_t = static_cast<ScriptEditor *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->load(); break;
        case 2: _t->updatePositionLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->aboutToActivate(); break;
        case 4: _t->showScriptGoTo(); break;
        case 5: _t->gotoLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->showScriptSearch(); break;
        case 7: _t->search((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 8: _t->findNext(); break;
        case 9: _t->findAll(); break;
        case 10: _t->showScriptReplace(); break;
        case 11: _t->replaceSelection((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->replaceAll(); break;
        case 13: _t->toggleBreakpoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3]))); break;
        case 14: _t->lineCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ScriptEditor::staticMetaObject = {
    { &EditorBase::staticMetaObject, qt_meta_stringdata_ScriptEditor.data,
      qt_meta_data_ScriptEditor,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptEditor.stringdata))
        return static_cast<void*>(const_cast< ScriptEditor*>(this));
    return EditorBase::qt_metacast(_clname);
}

int ScriptEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EditorBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
