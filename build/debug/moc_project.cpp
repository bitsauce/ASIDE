/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/project.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Project_t {
    QByteArrayData data[1];
    char stringdata[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Project_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Project_t qt_meta_stringdata_Project = {
    {
QT_MOC_LITERAL(0, 0, 7)
    },
    "Project"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Project[] = {

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

void Project::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Project::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Project.data,
      qt_meta_data_Project,  qt_static_metacall, 0, 0}
};


const QMetaObject *Project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Project::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Project.stringdata))
        return static_cast<void*>(const_cast< Project*>(this));
    return QObject::qt_metacast(_clname);
}

int Project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ProjectItemDelegate_t {
    QByteArrayData data[1];
    char stringdata[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProjectItemDelegate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProjectItemDelegate_t qt_meta_stringdata_ProjectItemDelegate = {
    {
QT_MOC_LITERAL(0, 0, 19)
    },
    "ProjectItemDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjectItemDelegate[] = {

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

void ProjectItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ProjectItemDelegate::staticMetaObject = {
    { &QItemDelegate::staticMetaObject, qt_meta_stringdata_ProjectItemDelegate.data,
      qt_meta_data_ProjectItemDelegate,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProjectItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectItemDelegate.stringdata))
        return static_cast<void*>(const_cast< ProjectItemDelegate*>(this));
    return QItemDelegate::qt_metacast(_clname);
}

int ProjectItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ProjectDialog_t {
    QByteArrayData data[12];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProjectDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProjectDialog_t qt_meta_stringdata_ProjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 11),
QT_MOC_LITERAL(4, 41, 11),
QT_MOC_LITERAL(5, 53, 4),
QT_MOC_LITERAL(6, 58, 14),
QT_MOC_LITERAL(7, 73, 3),
QT_MOC_LITERAL(8, 77, 11),
QT_MOC_LITERAL(9, 89, 9),
QT_MOC_LITERAL(10, 99, 9),
QT_MOC_LITERAL(11, 109, 9)
    },
    "ProjectDialog\0createProject\0\0openProject\0"
    "loadProject\0path\0removeListItem\0idx\0"
    "repaintList\0setupList\0clearList\0"
    "clickList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void ProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProjectDialog *_t = static_cast<ProjectDialog *>(_o);
        switch (_id) {
        case 0: _t->createProject(); break;
        case 1: _t->openProject(); break;
        case 2: _t->loadProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->removeListItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->repaintList(); break;
        case 5: _t->setupList(); break;
        case 6: _t->clearList(); break;
        case 7: _t->clickList((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProjectDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProjectDialog::createProject)) {
                *result = 0;
            }
        }
        {
            typedef void (ProjectDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProjectDialog::openProject)) {
                *result = 1;
            }
        }
        {
            typedef void (ProjectDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProjectDialog::loadProject)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ProjectDialog.data,
      qt_meta_data_ProjectDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectDialog.stringdata))
        return static_cast<void*>(const_cast< ProjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ProjectDialog::createProject()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ProjectDialog::openProject()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ProjectDialog::loadProject(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_NewProjectDialog_t {
    QByteArrayData data[5];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewProjectDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewProjectDialog_t qt_meta_stringdata_NewProjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 17),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 12),
QT_MOC_LITERAL(4, 49, 12)
    },
    "NewProjectDialog\0browseProjectPath\0\0"
    "acceptDialog\0cancelDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewProjectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewProjectDialog *_t = static_cast<NewProjectDialog *>(_o);
        switch (_id) {
        case 0: _t->browseProjectPath(); break;
        case 1: _t->acceptDialog(); break;
        case 2: _t->cancelDialog(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NewProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProjectDialog.data,
      qt_meta_data_NewProjectDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewProjectDialog.stringdata))
        return static_cast<void*>(const_cast< NewProjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
