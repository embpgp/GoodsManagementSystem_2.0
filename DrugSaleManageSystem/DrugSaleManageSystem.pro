#-------------------------------------------------
#
# Project created by QtCreator 2012-07-06T14:34:44
#
#-------------------------------------------------

QT       += core gui sql

TARGET = DrugSaleManageSystem
TEMPLATE = app

OBJECTS_DIR = .obj
MOC_DIR = .moc
UI_DIR = .uic

INCLUDEPATH += .\
            ../DrugSaleManageSystem/include \
            ../DrugSaleManageSystem/qhexedit \

!win32 {
LIBS +=  -L../DrugSaleManageSystem/lib  \
         -lqextserialport
} else {
LIBS +=  -L../DrugSaleManageSystem/lib  \
         -lqextserialportd1
}

SOURCES += main.cpp\
        DrugSaleManageSystemMainWidget.cpp \
    UHF900MPackage.cpp \
    ioportmanager.cpp \
    DBControl.cpp \
    PageBuyInWidget.cpp \
    PageSaleOutWidget.cpp \
    PageSaleRecordWidget.cpp \
    SaleItemWidget.cpp \
    BigSpinBoxEdit.cpp \
    PriceDialog.cpp \
    t9keyboard/t9widget.cpp \
    aboutdialog.cpp \
    informationdialog.cpp

HEADERS  += DrugSaleManageSystemMainWidget.h \
    UHF900MPackage.h \
    ioportManager.h \
    DBControl.h \
    PageBuyInWidget.h \
    PageSaleOutWidget.h \
    PageSaleRecordWidget.h \
    SaleItemWidget.h \
    BigSpinBoxEdit.h \
    PriceDialog.h \
    t9keyboard/t9widget.h \
    aboutdialog.h \
    informationdialog.h

FORMS    += DrugSaleManageSystemMainWidget.ui \
    PageBuyInWidget.ui \
    PageSaleOutWidget.ui \
    PageSaleRecordWidget.ui \
    SaleItemWidget.ui \
    BigSpinBoxEdit.ui \
    PriceDialog.ui \
    t9keyboard/t9widget.ui \
    aboutdialog.ui \
    informationdialog.ui

RESOURCES += \
    res.qrc

TRANSLATIONS += zh_CN.ts


RC_FILE += MainIcon.rc
