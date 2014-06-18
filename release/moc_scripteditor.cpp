/****************************************************************************
** Meta object code from reading C++ file 'scripteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/scripteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
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
    QByteArrayData data[7];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptSearch_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptSearch_t qt_meta_stringdata_ScriptSearch = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 8),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 8),
QT_MOC_LITERAL(4, 32, 7),
QT_MOC_LITERAL(5, 40, 14),
QT_MOC_LITERAL(6, 55, 14)
    },
    "ScriptSearch\0findNext\0\0findPrev\0findAll\0"
    "setNextDefault\0setPrevDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptSearch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScriptSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptSearch *_t = static_cast<ScriptSearch *>(_o);
        switch (_id) {
        case 0: _t->findNext(); break;
        case 1: _t->findPrev(); break;
        case 2: _t->findAll(); break;
        case 3: _t->setNextDefault(); break;
        case 4: _t->setPrevDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptSearch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::findNext)) {
                *result = 0;
            }
        }
        {
            typedef void (ScriptSearch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::findPrev)) {
                *result = 1;
            }
        }
        {
            typedef void (ScriptSearch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptSearch::findAll)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ScriptSearch::findNext()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScriptSearch::findPrev()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ScriptSearch::findAll()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
struct qt_meta_stringdata_ScriptReplace_t {
    QByteArrayData data[8];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptReplace_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptReplace_t qt_meta_stringdata_ScriptReplace = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 8),
QT_MOC_LITERAL(4, 33, 7),
QT_MOC_LITERAL(5, 41, 10),
QT_MOC_LITERAL(6, 52, 14),
QT_MOC_LITERAL(7, 67, 14)
    },
    "ScriptReplace\0findNext\0\0findPrev\0"
    "replace\0replaceAll\0setNextDefault\0"
    "setPrevDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptReplace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScriptReplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptReplace *_t = static_cast<ScriptReplace *>(_o);
        switch (_id) {
        case 0: _t->findNext(); break;
        case 1: _t->findPrev(); break;
        case 2: _t->replace(); break;
        case 3: _t->replaceAll(); break;
        case 4: _t->setNextDefault(); break;
        case 5: _t->setPrevDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptReplace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptReplace::findNext)) {
                *result = 0;
            }
        }
        {
            typedef void (ScriptReplace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptReplace::findPrev)) {
                *result = 1;
            }
        }
        {
            typedef void (ScriptReplace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptReplace::replace)) {
                *result = 2;
            }
        }
        {
            typedef void (ScriptReplace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptReplace::replaceAll)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ScriptReplace::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScriptReplace.data,
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
    return QDialog::qt_metacast(_clname);
}

int ScriptReplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ScriptReplace::findNext()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScriptReplace::findPrev()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ScriptReplace::replace()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ScriptReplace::replaceAll()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
struct qt_meta_stringdata_ScriptEditor_t {
    QByteArrayData data[30];
    char stringdata[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptEditor_t qt_meta_stringdata_ScriptEditor = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 8),
QT_MOC_LITERAL(4, 34, 9),
QT_MOC_LITERAL(5, 44, 10),
QT_MOC_LITERAL(6, 55, 4),
QT_MOC_LITERAL(7, 60, 14),
QT_MOC_LITERAL(8, 75, 15),
QT_MOC_LITERAL(9, 91, 8),
QT_MOC_LITERAL(10, 100, 11),
QT_MOC_LITERAL(11, 112, 19),
QT_MOC_LITERAL(12, 132, 4),
QT_MOC_LITERAL(13, 137, 3),
QT_MOC_LITERAL(14, 141, 15),
QT_MOC_LITERAL(15, 157, 14),
QT_MOC_LITERAL(16, 172, 8),
QT_MOC_LITERAL(17, 181, 16),
QT_MOC_LITERAL(18, 198, 8),
QT_MOC_LITERAL(19, 207, 8),
QT_MOC_LITERAL(20, 216, 7),
QT_MOC_LITERAL(21, 224, 17),
QT_MOC_LITERAL(22, 242, 16),
QT_MOC_LITERAL(23, 259, 10),
QT_MOC_LITERAL(24, 270, 16),
QT_MOC_LITERAL(25, 287, 21),
QT_MOC_LITERAL(26, 309, 9),
QT_MOC_LITERAL(27, 319, 16),
QT_MOC_LITERAL(28, 336, 5),
QT_MOC_LITERAL(29, 342, 2)
    },
    "ScriptEditor\0fileOpened\0\0filePath\0"
    "fileSaved\0fileClosed\0save\0resetSaveState\0"
    "updateSaveState\0modified\0textChanged\0"
    "updatePositionLabel\0line\0col\0"
    "aboutToActivate\0showScriptGoTo\0gotoLine\0"
    "showScriptSearch\0findNext\0findPrev\0"
    "findAll\0showScriptReplace\0replaceSelection\0"
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
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       5,    1,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  123,    2, 0x0a /* Public */,
       7,    0,  124,    2, 0x0a /* Public */,
       8,    1,  125,    2, 0x0a /* Public */,
      10,    0,  128,    2, 0x0a /* Public */,
      11,    2,  129,    2, 0x0a /* Public */,
      14,    0,  134,    2, 0x0a /* Public */,
      15,    0,  135,    2, 0x0a /* Public */,
      16,    1,  136,    2, 0x0a /* Public */,
      17,    0,  139,    2, 0x0a /* Public */,
      18,    0,  140,    2, 0x0a /* Public */,
      19,    0,  141,    2, 0x0a /* Public */,
      20,    0,  142,    2, 0x0a /* Public */,
      21,    0,  143,    2, 0x0a /* Public */,
      22,    0,  144,    2, 0x0a /* Public */,
      23,    0,  145,    2, 0x0a /* Public */,
      24,    3,  146,    2, 0x0a /* Public */,
      27,    2,  153,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 25,    2,   12,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   28,   29,

       0        // eod
};

void ScriptEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptEditor *_t = static_cast<ScriptEditor *>(_o);
        switch (_id) {
        case 0: _t->fileOpened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->fileSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->fileClosed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->save(); break;
        case 4: _t->resetSaveState(); break;
        case 5: _t->updateSaveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->textChanged(); break;
        case 7: _t->updatePositionLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->aboutToActivate(); break;
        case 9: _t->showScriptGoTo(); break;
        case 10: _t->gotoLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->showScriptSearch(); break;
        case 12: _t->findNext(); break;
        case 13: _t->findPrev(); break;
        case 14: _t->findAll(); break;
        case 15: _t->showScriptReplace(); break;
        case 16: _t->replaceSelection(); break;
        case 17: _t->replaceAll(); break;
        case 18: _t->toggleBreakpoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3]))); break;
        case 19: _t->lineCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptEditor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptEditor::fileOpened)) {
                *result = 0;
            }
        }
        {
            typedef void (ScriptEditor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptEditor::fileSaved)) {
                *result = 1;
            }
        }
        {
            typedef void (ScriptEditor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptEditor::fileClosed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ScriptEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScriptEditor.data,
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
    return QWidget::qt_metacast(_clname);
}

int ScriptEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void ScriptEditor::fileOpened(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScriptEditor::fileSaved(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScriptEditor::fileClosed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_AngelScriptPraser_t {
    QByteArrayData data[1];
    char stringdata[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AngelScriptPraser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AngelScriptPraser_t qt_meta_stringdata_AngelScriptPraser = {
    {
QT_MOC_LITERAL(0, 0, 17)
    },
    "AngelScriptPraser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AngelScriptPraser[] = {

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

void AngelScriptPraser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AngelScriptPraser::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_AngelScriptPraser.data,
      qt_meta_data_AngelScriptPraser,  qt_static_metacall, 0, 0}
};


const QMetaObject *AngelScriptPraser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AngelScriptPraser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AngelScriptPraser.stringdata))
        return static_cast<void*>(const_cast< AngelScriptPraser*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int AngelScriptPraser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
