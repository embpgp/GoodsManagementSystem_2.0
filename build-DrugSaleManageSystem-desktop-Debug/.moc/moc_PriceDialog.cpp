/****************************************************************************
** Meta object code from reading C++ file 'PriceDialog.h'
**
** Created: Thu Dec 3 12:18:26 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/PriceDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PriceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PriceDialog[] = {

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
      15,   13,   12,   12, 0x0a,
      36,   31,   12,   12, 0x0a,
      69,   53,   12,   12, 0x0a,
      94,   90,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PriceDialog[] = {
    "PriceDialog\0\0p\0setPrice(float)\0name\0"
    "setName(QString)\0index,cate_name\0"
    "setCate(int,QString)\0str\0"
    "onSftKeypadNewString(QString)\0"
};

const QMetaObject PriceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PriceDialog,
      qt_meta_data_PriceDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PriceDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PriceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PriceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PriceDialog))
        return static_cast<void*>(const_cast< PriceDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PriceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setPrice((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setCate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: onSftKeypadNewString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
