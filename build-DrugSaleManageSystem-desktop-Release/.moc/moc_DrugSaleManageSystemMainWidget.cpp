/****************************************************************************
** Meta object code from reading C++ file 'DrugSaleManageSystemMainWidget.h'
**
** Created: Thu Dec 3 12:24:32 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/DrugSaleManageSystemMainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrugSaleManageSystemMainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DrugSaleManageSystemMainWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   32,   31,   31, 0x05,
      74,   65,   31,   31, 0x05,
     105,  100,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     133,  128,  123,   31, 0x0a,
     148,   31,  123,   31, 0x0a,
     163,  155,   31,   31, 0x08,
     193,   31,   31,   31, 0x08,
     217,   31,   31,   31, 0x08,
     235,   32,   31,   31, 0x08,
     268,   32,   31,   31, 0x08,
     289,   31,   31,   31, 0x08,
     315,   32,   31,   31, 0x08,
     340,   31,   31,   31, 0x08,
     364,   31,   31,   31, 0x08,
     389,   31,   31,   31, 0x08,
     412,   31,   31,   31, 0x08,
     460,  437,   31,   31, 0x08,
     518,  490,   31,   31, 0x08,
     560,   31,   31,   31, 0x08,
     587,   65,   31,   31, 0x08,
     615,   31,   31,   31, 0x08,
     650,   31,   31,   31, 0x08,
     681,  676,   31,   31, 0x08,
     712,  676,   31,   31, 0x08,
     753,  676,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DrugSaleManageSystemMainWidget[] = {
    "DrugSaleManageSystemMainWidget\0\0pkg\0"
    "recvPackage(UHF900MPackage*)\0radio,id\0"
    "cardDetected(int,QString)\0name\0"
    "get_cate(QString)\0bool\0port\0start(QString)\0"
    "stop()\0checked\0on_openCloseBtn_clicked(bool)\0"
    "on_refreshBtn_clicked()\0onPortDataReady()\0"
    "onRecvedPackage(UHF900MPackage*)\0"
    "sendData(QByteArray)\0onScanReGetIdBtnClicked()\0"
    "sendData(UHF900MPackage)\0"
    "onScanResetBtnClicked()\0"
    "onScanSingleBtnClicked()\0"
    "onScanStopBtnClicked()\0onScanReScanBtnClicked()\0"
    "section,address,length\0"
    "onReadBtnClicked(int,int,int)\0"
    "section,address,length,data\0"
    "onWriteBtnClicked(int,int,int,QByteArray)\0"
    "onApplySettingBtnClicked()\0"
    "onCardDetected(int,QString)\0"
    "on_refreshSerialPortList_clicked()\0"
    "on_openCloseBtn_clicked()\0arg1\0"
    "on_comboBox_activated(QString)\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_opListTable_selected(QString)\0"
};

const QMetaObject DrugSaleManageSystemMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrugSaleManageSystemMainWidget,
      qt_meta_data_DrugSaleManageSystemMainWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DrugSaleManageSystemMainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DrugSaleManageSystemMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DrugSaleManageSystemMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrugSaleManageSystemMainWidget))
        return static_cast<void*>(const_cast< DrugSaleManageSystemMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrugSaleManageSystemMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: recvPackage((*reinterpret_cast< UHF900MPackage*(*)>(_a[1]))); break;
        case 1: cardDetected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: get_cate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { bool _r = start((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = stop();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: on_openCloseBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_refreshBtn_clicked(); break;
        case 7: onPortDataReady(); break;
        case 8: onRecvedPackage((*reinterpret_cast< UHF900MPackage*(*)>(_a[1]))); break;
        case 9: sendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 10: onScanReGetIdBtnClicked(); break;
        case 11: sendData((*reinterpret_cast< const UHF900MPackage(*)>(_a[1]))); break;
        case 12: onScanResetBtnClicked(); break;
        case 13: onScanSingleBtnClicked(); break;
        case 14: onScanStopBtnClicked(); break;
        case 15: onScanReScanBtnClicked(); break;
        case 16: onReadBtnClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: onWriteBtnClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QByteArray(*)>(_a[4]))); break;
        case 18: onApplySettingBtnClicked(); break;
        case 19: onCardDetected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: on_refreshSerialPortList_clicked(); break;
        case 21: on_openCloseBtn_clicked(); break;
        case 22: on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: on_opListTable_selected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void DrugSaleManageSystemMainWidget::recvPackage(UHF900MPackage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrugSaleManageSystemMainWidget::cardDetected(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DrugSaleManageSystemMainWidget::get_cate(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
