/********************************************************************************
** Form generated from reading UI file 'PageSaleOutWidget.ui'
**
** Created: Thu Dec 3 12:17:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGESALEOUTWIDGET_H
#define UI_PAGESALEOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageSaleOutWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QScrollArea *saleList;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *sailListLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *totalAmountEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *saleBtn;

    void setupUi(QWidget *PageSaleOutWidget)
    {
        if (PageSaleOutWidget->objectName().isEmpty())
            PageSaleOutWidget->setObjectName(QString::fromUtf8("PageSaleOutWidget"));
        PageSaleOutWidget->resize(492, 351);
        verticalLayout_3 = new QVBoxLayout(PageSaleOutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(PageSaleOutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        saleList = new QScrollArea(groupBox);
        saleList->setObjectName(QString::fromUtf8("saleList"));
        saleList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 452, 268));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sailListLayout = new QVBoxLayout();
        sailListLayout->setObjectName(QString::fromUtf8("sailListLayout"));

        verticalLayout_2->addLayout(sailListLayout);

        verticalSpacer = new QSpacerItem(20, 242, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        saleList->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(saleList);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PageSaleOutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        totalAmountEdit = new QLineEdit(PageSaleOutWidget);
        totalAmountEdit->setObjectName(QString::fromUtf8("totalAmountEdit"));

        horizontalLayout->addWidget(totalAmountEdit);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(PageSaleOutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(PageSaleOutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        saleBtn = new QPushButton(PageSaleOutWidget);
        saleBtn->setObjectName(QString::fromUtf8("saleBtn"));

        horizontalLayout->addWidget(saleBtn);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(PageSaleOutWidget);

        QMetaObject::connectSlotsByName(PageSaleOutWidget);
    } // setupUi

    void retranslateUi(QWidget *PageSaleOutWidget)
    {
        groupBox->setTitle(QApplication::translate("PageSaleOutWidget", "\345\207\272\345\272\223\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PageSaleOutWidget", "\345\275\223\345\211\215\345\207\272\345\272\223\346\200\273\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("PageSaleOutWidget", "\350\216\267\345\217\226\345\272\223\345\255\230\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PageSaleOutWidget", "\344\270\255\346\226\255\345\207\272\345\272\223", 0, QApplication::UnicodeUTF8));
        saleBtn->setText(QApplication::translate("PageSaleOutWidget", "\345\274\200\345\247\213\345\207\272\345\272\223", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PageSaleOutWidget);
    } // retranslateUi

};

namespace Ui {
    class PageSaleOutWidget: public Ui_PageSaleOutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGESALEOUTWIDGET_H
