/****************************************************************************
** Meta object code from reading C++ file 'PageSaleOutWidget.h'
**
** Created: Thu Dec 3 12:24:36 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/PageSaleOutWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageSaleOutWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PageSaleOutWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   40,   18,   18, 0x0a,
      77,   18,   18,   18, 0x08,
     104,   98,   18,   18, 0x08,
     132,   18,   18,   18, 0x08,
     152,   18,   18,   18, 0x08,
     167,   18,   18,   18, 0x08,
     191,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PageSaleOutWidget[] = {
    "PageSaleOutWidget\0\0refresh_readcardid()\0"
    "radio,id\0onCardDetected(int,QString)\0"
    "on_saleBtn_clicked()\0count\0"
    "onSaleItemCountChanged(int)\0"
    "onSaleItemDeleted()\0updateAmount()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject PageSaleOutWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageSaleOutWidget,
      qt_meta_data_PageSaleOutWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PageSaleOutWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PageSaleOutWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PageSaleOutWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageSaleOutWidget))
        return static_cast<void*>(const_cast< PageSaleOutWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageSaleOutWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: refresh_readcardid(); break;
        case 1: onCardDetected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: on_saleBtn_clicked(); break;
        case 3: onSaleItemCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: onSaleItemDeleted(); break;
        case 5: updateAmount(); break;
        case 6: on_pushButton_clicked(); break;
        case 7: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PageSaleOutWidget::refresh_readcardid()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
