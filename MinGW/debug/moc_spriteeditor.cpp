/****************************************************************************
** Meta object code from reading C++ file 'spriteeditor.h'
**
** Created: Tue 10. Jul 19:14:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/spriteeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spriteeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorWidget[] = {

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

static const char qt_meta_stringdata_ColorWidget[] = {
    "ColorWidget\0"
};

const QMetaObject ColorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorWidget,
      qt_meta_data_ColorWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorWidget))
        return static_cast<void*>(const_cast< ColorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SpritePainter[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      27,   14,   14,   14, 0x0a,
      37,   14,   14,   14, 0x0a,
      46,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SpritePainter[] = {
    "SpritePainter\0\0keyDelete()\0keyCopy()\0"
    "keyCut()\0keyPaste()\0"
};

const QMetaObject SpritePainter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SpritePainter,
      qt_meta_data_SpritePainter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpritePainter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpritePainter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpritePainter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpritePainter))
        return static_cast<void*>(const_cast< SpritePainter*>(this));
    return QWidget::qt_metacast(_clname);
}

int SpritePainter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: keyDelete(); break;
        case 1: keyCopy(); break;
        case 2: keyCut(); break;
        case 3: keyPaste(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_SpriteEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      26,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      50,   13,   13,   13, 0x08,
      65,   13,   13,   13, 0x08,
      79,   13,   13,   13, 0x08,
      93,   13,   13,   13, 0x08,
     108,   13,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,
     147,   13,   13,   13, 0x08,
     158,   13,   13,   13, 0x08,
     172,   13,   13,   13, 0x08,
     188,   13,   13,   13, 0x08,
     203,   13,   13,   13, 0x08,
     222,   13,   13,   13, 0x08,
     237,   13,   13,   13, 0x08,
     254,   13,   13,   13, 0x08,
     267,   13,   13,   13, 0x08,
     281,   13,   13,   13, 0x08,
     294,   13,   13,   13, 0x08,
     304,   13,   13,   13, 0x08,
     313,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpriteEditor[] = {
    "SpriteEditor\0\0newSprite()\0openSprite()\0"
    "editSave()\0saveAsSprite()\0imageResize()\0"
    "imageZoomIn()\0imageZoomOut()\0paintPencil()\0"
    "paintBrush()\0paintLine()\0paintBox()\0"
    "paintCircle()\0paintRectMark()\0"
    "paintEyeDrop()\0paintChangeColor()\0"
    "paintSetSize()\0paintSetTransp()\0"
    "paintErase()\0paintRotate()\0paintScale()\0"
    "keyCopy()\0keyCut()\0keyPaste()\0"
};

const QMetaObject SpriteEditor::staticMetaObject = {
    { &Editor::staticMetaObject, qt_meta_stringdata_SpriteEditor,
      qt_meta_data_SpriteEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpriteEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpriteEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpriteEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpriteEditor))
        return static_cast<void*>(const_cast< SpriteEditor*>(this));
    return Editor::qt_metacast(_clname);
}

int SpriteEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Editor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newSprite(); break;
        case 1: openSprite(); break;
        case 2: editSave(); break;
        case 3: saveAsSprite(); break;
        case 4: imageResize(); break;
        case 5: imageZoomIn(); break;
        case 6: imageZoomOut(); break;
        case 7: paintPencil(); break;
        case 8: paintBrush(); break;
        case 9: paintLine(); break;
        case 10: paintBox(); break;
        case 11: paintCircle(); break;
        case 12: paintRectMark(); break;
        case 13: paintEyeDrop(); break;
        case 14: paintChangeColor(); break;
        case 15: paintSetSize(); break;
        case 16: paintSetTransp(); break;
        case 17: paintErase(); break;
        case 18: paintRotate(); break;
        case 19: paintScale(); break;
        case 20: keyCopy(); break;
        case 21: keyCut(); break;
        case 22: keyPaste(); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
