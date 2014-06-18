/****************************************************************************
** Meta object code from reading C++ file 'projecttree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/projecttree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projecttree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileSystemSortProxyModel_t {
    QByteArrayData data[1];
    char stringdata[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileSystemSortProxyModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileSystemSortProxyModel_t qt_meta_stringdata_FileSystemSortProxyModel = {
    {
QT_MOC_LITERAL(0, 0, 24)
    },
    "FileSystemSortProxyModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSystemSortProxyModel[] = {

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

void FileSystemSortProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject FileSystemSortProxyModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_FileSystemSortProxyModel.data,
      qt_meta_data_FileSystemSortProxyModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *FileSystemSortProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSystemSortProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileSystemSortProxyModel.stringdata))
        return static_cast<void*>(const_cast< FileSystemSortProxyModel*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int FileSystemSortProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ProjectTree_t {
    QByteArrayData data[12];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProjectTree_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProjectTree_t qt_meta_stringdata_ProjectTree = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 11),
QT_MOC_LITERAL(4, 33, 12),
QT_MOC_LITERAL(5, 46, 13),
QT_MOC_LITERAL(6, 60, 14),
QT_MOC_LITERAL(7, 75, 11),
QT_MOC_LITERAL(8, 87, 10),
QT_MOC_LITERAL(9, 98, 11),
QT_MOC_LITERAL(10, 110, 9),
QT_MOC_LITERAL(11, 120, 12)
    },
    "ProjectTree\0newFile\0\0defaultPath\0"
    "cutSelection\0copySelection\0pasteClipboard\0"
    "deleteItems\0renameItem\0newFileItem\0"
    "addFolder\0browseFolder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjectTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
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

       0        // eod
};

void ProjectTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProjectTree *_t = static_cast<ProjectTree *>(_o);
        switch (_id) {
        case 0: _t->newFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cutSelection(); break;
        case 2: _t->copySelection(); break;
        case 3: _t->pasteClipboard(); break;
        case 4: _t->deleteItems(); break;
        case 5: _t->renameItem(); break;
        case 6: _t->newFileItem(); break;
        case 7: _t->addFolder(); break;
        case 8: _t->browseFolder(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProjectTree::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProjectTree::newFile)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ProjectTree::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_ProjectTree.data,
      qt_meta_data_ProjectTree,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProjectTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectTree.stringdata))
        return static_cast<void*>(const_cast< ProjectTree*>(this));
    return QTreeView::qt_metacast(_clname);
}

int ProjectTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ProjectTree::newFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
