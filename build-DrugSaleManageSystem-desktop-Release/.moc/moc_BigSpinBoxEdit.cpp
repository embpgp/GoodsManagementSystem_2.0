/****************************************************************************
** Meta object code from reading C++ file 'BigSpinBoxEdit.h'
**
** Created: Thu Dec 3 12:24:43 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrugSaleManageSystem/BigSpinBoxEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BigSpinBoxEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddSubButton[] = {

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
      22,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   13,   13,   13, 0x08,
      53,   51,   13,   13, 0x0a,
      71,   67,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddSubButton[] = {
    "AddSubButton\0\0idx,neg\0clicked(int,int)\0"
    "onClicked()\0i\0setIndex(int)\0neg\0"
    "setNeg(int)\0"
};

const QMetaObject AddSubButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_AddSubButton,
      qt_meta_data_AddSubButton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddSubButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddSubButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddSubButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddSubButton))
        return static_cast<void*>(const_cast< AddSubButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int AddSubButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: onClicked(); break;
        case 2: setIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setNeg((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddSubButton::clicked(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_BigSpinBoxEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x0a,
      47,   38,   15,   15, 0x0a,
      65,   15,   15,   15, 0x2a,
      79,   15,   15,   15, 0x08,
      99,   90,   15,   15, 0x08,
     114,   15,   15,   15, 0x28,
     125,   15,   15,   15, 0x08,
     145,  137,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BigSpinBoxEdit[] = {
    "BigSpinBoxEdit\0\0value\0setValue(float)\0"
    "editable\0setEditable(bool)\0setEditable()\0"
    "createUI()\0reCreate\0updateUI(bool)\0"
    "updateUI()\0destroyUI()\0idx,neg\0"
    "onNumberOpBtnClicked(int,int)\0"
};

const QMetaObject BigSpinBoxEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BigSpinBoxEdit,
      qt_meta_data_BigSpinBoxEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BigSpinBoxEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BigSpinBoxEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BigSpinBoxEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BigSpinBoxEdit))
        return static_cast<void*>(const_cast< BigSpinBoxEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int BigSpinBoxEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: setEditable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setEditable(); break;
        case 3: createUI(); break;
        case 4: updateUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: updateUI(); break;
        case 6: destroyUI(); break;
        case 7: onNumberOpBtnClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
