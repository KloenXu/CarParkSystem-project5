/****************************************************************************
** Meta object code from reading C++ file 'managerpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "managerpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ManagerPage_t {
    QByteArrayData data[10];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManagerPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManagerPage_t qt_meta_stringdata_ManagerPage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ManagerPage"
QT_MOC_LITERAL(1, 12, 21), // "on_backHomeBt_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_displayInf_clicked"
QT_MOC_LITERAL(4, 57, 20), // "on_changeInf_clicked"
QT_MOC_LITERAL(5, 78, 26), // "on_tableWidget_itemClicked"
QT_MOC_LITERAL(6, 105, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(7, 123, 4), // "item"
QT_MOC_LITERAL(8, 128, 20), // "on_deleteInf_clicked"
QT_MOC_LITERAL(9, 149, 23) // "on_passwdChange_clicked"

    },
    "ManagerPage\0on_backHomeBt_clicked\0\0"
    "on_displayInf_clicked\0on_changeInf_clicked\0"
    "on_tableWidget_itemClicked\0QTableWidgetItem*\0"
    "item\0on_deleteInf_clicked\0"
    "on_passwdChange_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManagerPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManagerPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManagerPage *_t = static_cast<ManagerPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_backHomeBt_clicked(); break;
        case 1: _t->on_displayInf_clicked(); break;
        case 2: _t->on_changeInf_clicked(); break;
        case 3: _t->on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_deleteInf_clicked(); break;
        case 5: _t->on_passwdChange_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ManagerPage::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ManagerPage.data,
      qt_meta_data_ManagerPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ManagerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManagerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ManagerPage.stringdata0))
        return static_cast<void*>(const_cast< ManagerPage*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ManagerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
