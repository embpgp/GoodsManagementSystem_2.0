/****************************************************************************
** Meta object code from reading C++ file 'SaleItemWidget.h'
**
** Created: Thu Dec 3 12:18:22 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/SaleItemWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SaleItemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SaleItemWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   39,   15,   15, 0x0a,
      62,   57,   15,   15, 0x0a,
      89,   83,   15,   15, 0x0a,
     109,   16,   15,   15, 0x0a,
     132,  123,   15,   15, 0x0a,
     159,  149,   15,   15, 0x0a,
     181,   16,   15,   15, 0x0a,
     206,   15,  202,   15, 0x0a,
     224,   15,   15,   15, 0x0a,
     233,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SaleItemWidget[] = {
    "SaleItemWidget\0\0count\0countChaned(int)\0"
    "id\0setID(QString)\0name\0setDrugName(QString)\0"
    "price\0setDrugPrice(float)\0setCount(int)\0"
    "maxCount\0setMaxCount(int)\0cate_name\0"
    "setCate_name(QString)\0setCurrentCount(int)\0"
    "int\0getCurrentCount()\0remove()\0"
    "on_delBtn_clicked()\0"
};

const QMetaObject SaleItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SaleItemWidget,
      qt_meta_data_SaleItemWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SaleItemWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SaleItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SaleItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SaleItemWidget))
        return static_cast<void*>(const_cast< SaleItemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SaleItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: countChaned((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setDrugName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: setDrugPrice((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: setCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setMaxCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setCate_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: setCurrentCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { int _r = getCurrentCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: remove(); break;
        case 10: on_delBtn_clicked(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SaleItemWidget::countChaned(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
