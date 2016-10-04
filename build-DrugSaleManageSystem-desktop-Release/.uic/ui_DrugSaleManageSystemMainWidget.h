/********************************************************************************
** Form generated from reading UI file 'DrugSaleManageSystemMainWidget.ui'
**
** Created: Thu Dec 3 12:23:57 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRUGSALEMANAGESYSTEMMAINWIDGET_H
#define UI_DRUGSALEMANAGESYSTEMMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "PageBuyInWidget.h"
#include "PageSaleOutWidget.h"
#include "PageSaleRecordWidget.h"

QT_BEGIN_NAMESPACE

class Ui_DrugSaleManageSystemMainWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *serialPortList;
    QPushButton *refreshSerialPortList;
    QPushButton *openCloseBtn;
    QWidget *contentWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *refreshBtn;
    QTabWidget *opListTable;
    PageSaleOutWidget *saleOutPage;
    PageBuyInWidget *buyInPage;
    PageSaleRecordWidget *recordPage;

    void setupUi(QWidget *DrugSaleManageSystemMainWidget)
    {
        if (DrugSaleManageSystemMainWidget->objectName().isEmpty())
            DrugSaleManageSystemMainWidget->setObjectName(QString::fromUtf8("DrugSaleManageSystemMainWidget"));
        DrugSaleManageSystemMainWidget->resize(799, 490);
        verticalLayout_2 = new QVBoxLayout(DrugSaleManageSystemMainWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        titleLabel = new QLabel(DrugSaleManageSystemMainWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setPixmap(QPixmap(QString::fromUtf8(":/pic/title.png")));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(DrugSaleManageSystemMainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serialPortList = new QComboBox(DrugSaleManageSystemMainWidget);
        serialPortList->setObjectName(QString::fromUtf8("serialPortList"));

        horizontalLayout->addWidget(serialPortList);

        refreshSerialPortList = new QPushButton(DrugSaleManageSystemMainWidget);
        refreshSerialPortList->setObjectName(QString::fromUtf8("refreshSerialPortList"));

        horizontalLayout->addWidget(refreshSerialPortList);

        openCloseBtn = new QPushButton(DrugSaleManageSystemMainWidget);
        openCloseBtn->setObjectName(QString::fromUtf8("openCloseBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/shut_down_grayed.png"), QSize(), QIcon::Normal, QIcon::Off);
        openCloseBtn->setIcon(icon);
        openCloseBtn->setIconSize(QSize(32, 32));
        openCloseBtn->setCheckable(true);
        openCloseBtn->setFlat(true);

        horizontalLayout->addWidget(openCloseBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        contentWidget = new QWidget(DrugSaleManageSystemMainWidget);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        verticalLayout = new QVBoxLayout(contentWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(contentWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(contentWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        refreshBtn = new QPushButton(contentWidget);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));

        horizontalLayout_2->addWidget(refreshBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        opListTable = new QTabWidget(contentWidget);
        opListTable->setObjectName(QString::fromUtf8("opListTable"));
        saleOutPage = new PageSaleOutWidget();
        saleOutPage->setObjectName(QString::fromUtf8("saleOutPage"));
        opListTable->addTab(saleOutPage, QString());
        buyInPage = new PageBuyInWidget();
        buyInPage->setObjectName(QString::fromUtf8("buyInPage"));
        opListTable->addTab(buyInPage, QString());
        recordPage = new PageSaleRecordWidget();
        recordPage->setObjectName(QString::fromUtf8("recordPage"));
        opListTable->addTab(recordPage, QString());

        verticalLayout->addWidget(opListTable);


        verticalLayout_2->addWidget(contentWidget);


        retranslateUi(DrugSaleManageSystemMainWidget);

        opListTable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DrugSaleManageSystemMainWidget);
    } // setupUi

    void retranslateUi(QWidget *DrugSaleManageSystemMainWidget)
    {
        DrugSaleManageSystemMainWidget->setWindowTitle(QApplication::translate("DrugSaleManageSystemMainWidget", "\344\273\223\345\272\223\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DrugSaleManageSystemMainWidget", "\344\270\262\345\217\243\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        refreshSerialPortList->setText(QApplication::translate("DrugSaleManageSystemMainWidget", "\345\210\267\346\226\260\344\270\262\345\217\243\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        openCloseBtn->setText(QApplication::translate("DrugSaleManageSystemMainWidget", "Closed", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DrugSaleManageSystemMainWidget", "\344\273\223\345\272\223\345\210\206\345\214\272\357\274\232", 0, QApplication::UnicodeUTF8));
        refreshBtn->setText(QApplication::translate("DrugSaleManageSystemMainWidget", "\351\207\215\346\226\260\350\257\273\345\215\241", 0, QApplication::UnicodeUTF8));
        opListTable->setTabText(opListTable->indexOf(saleOutPage), QApplication::translate("DrugSaleManageSystemMainWidget", "\345\207\272\345\272\223\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        opListTable->setTabText(opListTable->indexOf(buyInPage), QApplication::translate("DrugSaleManageSystemMainWidget", "\345\205\245\345\272\223\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        opListTable->setTabText(opListTable->indexOf(recordPage), QApplication::translate("DrugSaleManageSystemMainWidget", "\345\207\272\345\205\245\345\272\223\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DrugSaleManageSystemMainWidget: public Ui_DrugSaleManageSystemMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRUGSALEMANAGESYSTEMMAINWIDGET_H
