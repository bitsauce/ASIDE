/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created: Tue 10. Jul 19:14:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/project.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Project[] = {

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
       9,    8,    8,    8, 0x08,
      22,    8,    8,    8, 0x08,
      41,   36,    8,    8, 0x08,
      70,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Project[] = {
    "Project\0\0newProject()\0openProject()\0"
    "item\0recentOpen(QListWidgetItem*)\0"
    "clearRecent()\0"
};

const QMetaObject Project::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Project,
      qt_meta_data_Project, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Project::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Project::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Project))
        return static_cast<void*>(const_cast< Project*>(this));
    return QWidget::qt_metacast(_clname);
}

int Project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newProject(); break;
        case 1: openProject(); break;
        case 2: recentOpen((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: clearRecent(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_NewProject[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewProject[] = {
    "NewProject\0\0browseProject()\0okProject()\0"
    "cancelProject()\0"
};

const QMetaObject NewProject::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProject,
      qt_meta_data_NewProject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewProject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewProject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewProject))
        return static_cast<void*>(const_cast< NewProject*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: browseProject(); break;
        case 1: okProject(); break;
        case 2: cancelProject(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
