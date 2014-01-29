/****************************************************************************
** Meta object code from reading C++ file 'projecttree.h'
**
** Created: Tue 10. Jul 17:38:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/projecttree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projecttree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProjectTree[] = {

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
      30,   13,   12,   12, 0x08,
      82,   62,   57,   12, 0x08,
     126,  120,   12,   12, 0x08,
     153,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProjectTree[] = {
    "ProjectTree\0\0supportedActions\0"
    "startDrag(Qt::DropActions)\0bool\0"
    "index,trigger,event\0"
    "edit(QModelIndex,EditTrigger,QEvent*)\0"
    "index\0doubleClicked(QModelIndex)\0"
    "toggle()\0"
};

const QMetaObject ProjectTree::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_ProjectTree,
      qt_meta_data_ProjectTree, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProjectTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProjectTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProjectTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectTree))
        return static_cast<void*>(const_cast< ProjectTree*>(this));
    return QTreeView::qt_metacast(_clname);
}

int ProjectTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startDrag((*reinterpret_cast< Qt::DropActions(*)>(_a[1]))); break;
        case 1: { bool _r = edit((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< EditTrigger(*)>(_a[2])),(*reinterpret_cast< QEvent*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: toggle(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
