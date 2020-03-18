/****************************************************************************
** Meta object code from reading C++ file 'Assignment10.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assignment10.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Assignment10.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Assignment10_t {
    QByteArrayData data[10];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Assignment10_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Assignment10_t qt_meta_stringdata_Assignment10 = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Assignment10"
QT_MOC_LITERAL(1, 13, 3), // "add"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "remove"
QT_MOC_LITERAL(4, 25, 6), // "update"
QT_MOC_LITERAL(5, 32, 14), // "saveIdToMyList"
QT_MOC_LITERAL(6, 47, 5), // "modeA"
QT_MOC_LITERAL(7, 53, 5), // "modeB"
QT_MOC_LITERAL(8, 59, 4), // "next"
QT_MOC_LITERAL(9, 64, 15) // "filterMaterials"

    },
    "Assignment10\0add\0\0remove\0update\0"
    "saveIdToMyList\0modeA\0modeB\0next\0"
    "filterMaterials"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Assignment10[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

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

void Assignment10::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Assignment10 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add(); break;
        case 1: _t->remove(); break;
        case 2: _t->update(); break;
        case 3: _t->saveIdToMyList(); break;
        case 4: _t->modeA(); break;
        case 5: _t->modeB(); break;
        case 6: _t->next(); break;
        case 7: _t->filterMaterials(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Assignment10::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Assignment10.data,
    qt_meta_data_Assignment10,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Assignment10::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assignment10::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Assignment10.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Assignment10::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
