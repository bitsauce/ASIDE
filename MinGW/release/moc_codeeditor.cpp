/****************************************************************************
** Meta object code from reading C++ file 'codeeditor.h'
**
** Created: Tue 10. Jul 17:38:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/codeeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AngelScriptHL[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_AngelScriptHL[] = {
    "AngelScriptHL\0"
};

const QMetaObject AngelScriptHL::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_AngelScriptHL,
      qt_meta_data_AngelScriptHL, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AngelScriptHL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AngelScriptHL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AngelScriptHL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AngelScriptHL))
        return static_cast<void*>(const_cast< AngelScriptHL*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int AngelScriptHL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CodeTextEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   53,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeTextEdit[] = {
    "CodeTextEdit\0\0var,pos\0"
    "requestCompletion(QString,int)\0str\0"
    "insertCompletion(QString)\0"
};

const QMetaObject CodeTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_CodeTextEdit,
      qt_meta_data_CodeTextEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeTextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeTextEdit))
        return static_cast<void*>(const_cast< CodeTextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int CodeTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestCompletion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: insertCompletion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CodeTextEdit::requestCompletion(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_CodeFind[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      21,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeFind[] = {
    "CodeFind\0\0findNext()\0findPrevious()\0"
};

const QMetaObject CodeFind::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CodeFind,
      qt_meta_data_CodeFind, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeFind::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeFind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeFind::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeFind))
        return static_cast<void*>(const_cast< CodeFind*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CodeFind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: findNext(); break;
        case 1: findPrevious(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_CodeFindReplace[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeFindReplace[] = {
    "CodeFindReplace\0\0replaceAll()\0"
};

const QMetaObject CodeFindReplace::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CodeFindReplace,
      qt_meta_data_CodeFindReplace, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeFindReplace::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeFindReplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeFindReplace::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeFindReplace))
        return static_cast<void*>(const_cast< CodeFindReplace*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CodeFindReplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: replaceAll(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_CodeEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     124,  120,   11,   11, 0x08,
     146,  120,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditor[] = {
    "CodeEditor\0\0editSave()\0codeChanged()\0"
    "codeFind()\0codeReplace()\0inteliUpdate()\0"
    "inteliUpdateDone()\0inteliProgressChanged()\0"
    "idx\0namespaceChanged(int)\0methodChanged(int)\0"
    "findNamespace()\0findCurrentScope()\0"
    "findCurrentScopeDone()\0showCompletion()\0"
};

const QMetaObject CodeEditor::staticMetaObject = {
    { &Editor::staticMetaObject, qt_meta_stringdata_CodeEditor,
      qt_meta_data_CodeEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditor))
        return static_cast<void*>(const_cast< CodeEditor*>(this));
    return Editor::qt_metacast(_clname);
}

int CodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Editor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: editSave(); break;
        case 1: codeChanged(); break;
        case 2: codeFind(); break;
        case 3: codeReplace(); break;
        case 4: inteliUpdate(); break;
        case 5: inteliUpdateDone(); break;
        case 6: inteliProgressChanged(); break;
        case 7: namespaceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: methodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: findNamespace(); break;
        case 10: findCurrentScope(); break;
        case 11: findCurrentScopeDone(); break;
        case 12: showCompletion(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
