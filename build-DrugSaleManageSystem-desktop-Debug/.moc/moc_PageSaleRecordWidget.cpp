/****************************************************************************
** Meta object code from reading C++ file 'PageSaleRecordWidget.h'
**
** Created: Thu Dec 3 12:18:20 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/PageSaleRecordWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageSaleRecordWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PageSaleRecordWidget[] = {

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
      27,   22,   21,   21, 0x0a,
      50,   21,   21,   21, 0x08,
      80,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PageSaleRecordWidget[] = {
    "PageSaleRecordWidget\0\0name\0"
    "get_cate_from(QString)\0"
    "on_refreshRecordBtn_clicked()\0"
    "on_refreshInventoryBtn_clicked()\0"
};

const QMetaObject PageSaleRecordWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageSaleRecordWidget,
      qt_meta_data_PageSaleRecordWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PageSaleRecordWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PageSaleRecordWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PageSaleRecordWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageSaleRecordWidget))
        return static_cast<void*>(const_cast< PageSaleRecordWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageSaleRecordWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: get_cate_from((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: on_refreshRecordBtn_clicked(); break;
        case 2: on_refreshInventoryBtn_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
