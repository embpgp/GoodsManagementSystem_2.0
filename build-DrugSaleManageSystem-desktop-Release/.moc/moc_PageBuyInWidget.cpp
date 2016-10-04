/****************************************************************************
** Meta object code from reading C++ file 'PageBuyInWidget.h'
**
** Created: Thu Dec 3 12:24:34 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/PageBuyInWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageBuyInWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PageBuyInWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   38,   16,   16, 0x0a,
      75,   16,   16,   16, 0x08,
      99,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PageBuyInWidget[] = {
    "PageBuyInWidget\0\0refresh_readcardid()\0"
    "radio,id\0onCardDetected(int,QString)\0"
    "on_storageBtn_clicked()\0on_pushButton_clicked()\0"
};

const QMetaObject PageBuyInWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PageBuyInWidget,
      qt_meta_data_PageBuyInWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PageBuyInWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PageBuyInWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PageBuyInWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PageBuyInWidget))
        return static_cast<void*>(const_cast< PageBuyInWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PageBuyInWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: refresh_readcardid(); break;
        case 1: onCardDetected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: on_storageBtn_clicked(); break;
        case 3: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PageBuyInWidget::refresh_readcardid()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
