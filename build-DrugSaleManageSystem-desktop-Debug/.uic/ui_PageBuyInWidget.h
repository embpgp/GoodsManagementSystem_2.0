/********************************************************************************
** Form generated from reading UI file 'PageBuyInWidget.ui'
**
** Created: Thu Dec 3 12:17:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEBUYINWIDGET_H
#define UI_PAGEBUYINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageBuyInWidget
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
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *storageBtn;

    void setupUi(QWidget *PageBuyInWidget)
    {
        if (PageBuyInWidget->objectName().isEmpty())
            PageBuyInWidget->setObjectName(QString::fromUtf8("PageBuyInWidget"));
        PageBuyInWidget->resize(492, 351);
        verticalLayout_3 = new QVBoxLayout(PageBuyInWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(PageBuyInWidget);
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
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(PageBuyInWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        storageBtn = new QPushButton(PageBuyInWidget);
        storageBtn->setObjectName(QString::fromUtf8("storageBtn"));

        horizontalLayout->addWidget(storageBtn);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(PageBuyInWidget);

        QMetaObject::connectSlotsByName(PageBuyInWidget);
    } // setupUi

    void retranslateUi(QWidget *PageBuyInWidget)
    {
        groupBox->setTitle(QApplication::translate("PageBuyInWidget", "\345\205\245\345\272\223\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PageBuyInWidget", "\344\270\255\346\226\255\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        storageBtn->setText(QApplication::translate("PageBuyInWidget", "\345\274\200\345\247\213\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PageBuyInWidget);
    } // retranslateUi

};

namespace Ui {
    class PageBuyInWidget: public Ui_PageBuyInWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEBUYINWIDGET_H
