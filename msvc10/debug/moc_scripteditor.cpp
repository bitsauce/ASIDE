/****************************************************************************
** Meta object code from reading C++ file 'scripteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/scripteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScriptTextEdit_t {
    QByteArrayData data[24];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptTextEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScriptTextEdit_t qt_meta_stringdata_ScriptTextEdit = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 4),
QT_MOC_LITERAL(4, 38, 17),
QT_MOC_LITERAL(5, 56, 4),
QT_MOC_LITERAL(6, 61, 8),
QT_MOC_LITERAL(7, 70, 15),
QT_MOC_LITERAL(8, 86, 13),
QT_MOC_LITERAL(9, 100, 13),
QT_MOC_LITERAL(10, 114, 16),
QT_MOC_LITERAL(11, 131, 9),
QT_MOC_LITERAL(12, 141, 2),
QT_MOC_LITERAL(13, 144, 16),
QT_MOC_LITERAL(14, 161, 5),
QT_MOC_LITERAL(15, 167, 6),
QT_MOC_LITERAL(16, 174, 14),
QT_MOC_LITERAL(17, 189, 18),
QT_MOC_LITERAL(18, 208, 20),
QT_MOC_LITERAL(19, 229, 21),
QT_MOC_LITERAL(20, 251, 3),
QT_MOC_LITERAL(21, 255, 16),
QT_MOC_LITERAL(22, 272, 14),
QT_MOC_LITERAL(23, 287, 12)
    },
    "ScriptTextEdit\0toggleBreakpoint\0\0line\0"
    "showDebugVariable\0name\0position\0"
    "insertPerformed\0undoPerformed\0"
    "redoPerformed\0lineCountChanged\0startLine\0"
    "dt\0insertCompletion\0index\0string\0"
    "stopCompletion\0checkForCompletion\0"
    "updateLineNumberArea\0lineNumberAreaClicked\0"
    "pos\0undoCommandAdded\0setMatchFormat\0"
    "matchSymbols\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptTextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x05,
       4,    2,   92,    2, 0x05,
       7,    0,   97,    2, 0x05,
       8,    0,   98,    2, 0x05,
       9,    0,   99,    2, 0x05,
      10,    2,  100,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      13,    1,  105,    2, 0x08,
      13,    1,  108,    2, 0x08,
      16,    0,  111,    2, 0x08,
      17,    0,  112,    2, 0x08,
      18,    0,  113,    2, 0x08,
      19,    1,  114,    2, 0x08,
      21,    0,  117,    2, 0x08,
      22,    1,  118,    2, 0x08,
      23,    0,  121,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QPoint,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

       0        // eod
};

void ScriptTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptTextEdit *_t = static_cast<ScriptTextEdit *>(_o);
        switch (_id) {
        case 0: _t->toggleBreakpoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->showDebugVariable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 2: _t->insertPerformed(); break;
        case 3: _t->undoPerformed(); break;
        case 4: _t->redoPerformed(); break;
        case 5: _t->lineCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->insertCompletion((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->insertCompletion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->stopCompletion(); break;
        case 9: _t->checkForCompletion(); break;
        case 10: _t->updateLineNumberArea(); break;
        case 11: _t->lineNumberAreaClicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->undoCommandAdded(); break;
        case 13: _t->setMatchFormat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->matchSymbols(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScriptTextEdit::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::toggleBreakpoint)) {
                *result = 0;
            }
        }
        {
            typedef void (ScriptTextEdit::*_t)(QString , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::showDebugVariable)) {
                *result = 1;
            }
        }
        {
            typedef void (ScriptTextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::insertPerformed)) {
                *result = 2;
            }
        }
        {
            typedef void (ScriptTextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::undoPerformed)) {
                *result = 3;
            }
        }
        {
            typedef void (ScriptTextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::redoPerformed)) {
                *result = 4;
            }
        }
        {
            typedef void (ScriptTextEdit::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScriptTextEdit::lineCountChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject ScriptTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_ScriptTextEdit.data,
      qt_meta_data_ScriptTextEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptTextEdit.stringdata))
        return static_cast<void*>(const_cast< ScriptTextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int ScriptTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ScriptTextEdit::toggleBreakpoint(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScriptTextEdit::showDebugVariable(QString _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScriptTextEdit::insertPerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ScriptTextEdit::undoPerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ScriptTextEdit::redoPerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ScriptTextEdit::lineCountChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_LineNumberArea_t {
    QByteArrayData data[4];
    char stringdata[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LineNumberArea_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LineNumberArea_t qt_meta_stringdata_LineNumberArea = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 7),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 3)
    },
    "LineNumberArea\0clicked\0\0pos\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineNumberArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void LineNumberArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineNumberArea *_t = static_cast<LineNumberArea *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LineNumberArea::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineNumberArea::clicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LineNumberArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineNumberArea.data,
      qt_meta_data_LineNumberArea,  qt_static_metacall, 0, 0}
};


const QMetaObject *LineNumberArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineNumberArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineNumberArea.stringdata))
        return static_cast<void*>(const_cast< LineNumberArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int LineNumberArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void LineNumberArea::clicked(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CompleterDelegate_t {
    QByteArrayData data[1];
    char stringdata[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CompleterDelegate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CompleterDelegate_t qt_meta_stringdata_CompleterDelegate = {
    {
QT_MOC_LITERAL(0, 0, 17)
    },
    "CompleterDelegate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompleterDelegate[] = {

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

void CompleterDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CompleterDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_CompleterDelegate.data,
      qt_meta_data_CompleterDelegate,  qt_static_metacall, 0, 0}
};


const QMetaObject *CompleterDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompleterDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CompleterDelegate.stringdata))
        return static_cast<void*>(const_cast< CompleterDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int CompleterDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ScriptGoTo_t {
    QByteArrayData data[4];
    char stringdata[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptGoTo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScriptGoTo_t qt_meta_stringdata_ScriptGoTo = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4)
    },
    "ScriptGoTo\0gotoLine\0\0line\0"
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
       1,    1,   24,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       1,    0,   27,    2, 0x08,

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
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptSearch_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
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
    "setNextDefault\0setPrevDefault\0"
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
       1,    0,   39,    2, 0x05,
       3,    0,   40,    2, 0x05,
       4,    0,   41,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08,
       6,    0,   43,    2, 0x08,

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
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptReplace_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
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
    "setPrevDefault\0"
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
       1,    0,   44,    2, 0x05,
       3,    0,   45,    2, 0x05,
       4,    0,   46,    2, 0x05,
       5,    0,   47,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08,
       7,    0,   49,    2, 0x08,

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
    QByteArrayData data[31];
    char stringdata[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
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
QT_MOC_LITERAL(8, 75, 11),
QT_MOC_LITERAL(9, 87, 8),
QT_MOC_LITERAL(10, 96, 8),
QT_MOC_LITERAL(11, 105, 19),
QT_MOC_LITERAL(12, 125, 11),
QT_MOC_LITERAL(13, 137, 15),
QT_MOC_LITERAL(14, 153, 20),
QT_MOC_LITERAL(15, 174, 4),
QT_MOC_LITERAL(16, 179, 22),
QT_MOC_LITERAL(17, 202, 14),
QT_MOC_LITERAL(18, 217, 8),
QT_MOC_LITERAL(19, 226, 4),
QT_MOC_LITERAL(20, 231, 16),
QT_MOC_LITERAL(21, 248, 8),
QT_MOC_LITERAL(22, 257, 8),
QT_MOC_LITERAL(23, 266, 7),
QT_MOC_LITERAL(24, 274, 17),
QT_MOC_LITERAL(25, 292, 16),
QT_MOC_LITERAL(26, 309, 10),
QT_MOC_LITERAL(27, 320, 16),
QT_MOC_LITERAL(28, 337, 16),
QT_MOC_LITERAL(29, 354, 5),
QT_MOC_LITERAL(30, 360, 2)
    },
    "ScriptEditor\0fileOpened\0\0filePath\0"
    "fileSaved\0fileClosed\0save\0resetSaveState\0"
    "textChanged\0textUndo\0textRedo\0"
    "updatePositionLabel\0updateIntel\0"
    "aboutToActivate\0functionIndexChanged\0"
    "text\0namedScopeIndexChanged\0showScriptGoTo\0"
    "gotoLine\0line\0showScriptSearch\0findNext\0"
    "findPrev\0findAll\0showScriptReplace\0"
    "replaceSelection\0replaceAll\0"
    "toggleBreakpoint\0lineCountChanged\0"
    "start\0dt\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x05,
       4,    1,  137,    2, 0x05,
       5,    1,  140,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,  143,    2, 0x0a,
       7,    0,  144,    2, 0x0a,
       8,    0,  145,    2, 0x0a,
       9,    0,  146,    2, 0x0a,
      10,    0,  147,    2, 0x0a,
      11,    0,  148,    2, 0x0a,
      12,    0,  149,    2, 0x0a,
      13,    0,  150,    2, 0x0a,
      14,    1,  151,    2, 0x0a,
      16,    1,  154,    2, 0x0a,
      17,    0,  157,    2, 0x0a,
      18,    1,  158,    2, 0x0a,
      20,    0,  161,    2, 0x0a,
      21,    0,  162,    2, 0x0a,
      22,    0,  163,    2, 0x0a,
      23,    0,  164,    2, 0x0a,
      24,    0,  165,    2, 0x0a,
      25,    0,  166,    2, 0x0a,
      26,    0,  167,    2, 0x0a,
      27,    1,  168,    2, 0x0a,
      28,    2,  171,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   29,   30,

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
        case 5: _t->textChanged(); break;
        case 6: _t->textUndo(); break;
        case 7: _t->textRedo(); break;
        case 8: _t->updatePositionLabel(); break;
        case 9: _t->updateIntel(); break;
        case 10: _t->aboutToActivate(); break;
        case 11: _t->functionIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->namedScopeIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->showScriptGoTo(); break;
        case 14: _t->gotoLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->showScriptSearch(); break;
        case 16: _t->findNext(); break;
        case 17: _t->findPrev(); break;
        case 18: _t->findAll(); break;
        case 19: _t->showScriptReplace(); break;
        case 20: _t->replaceSelection(); break;
        case 21: _t->replaceAll(); break;
        case 22: _t->toggleBreakpoint((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 23: _t->lineCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
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
    char stringdata[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AngelScriptPraser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AngelScriptPraser_t qt_meta_stringdata_AngelScriptPraser = {
    {
QT_MOC_LITERAL(0, 0, 17)
    },
    "AngelScriptPraser\0"
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
