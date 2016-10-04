/********************************************************************************
** Form generated from reading UI file 'PageSaleRecordWidget.ui'
**
** Created: Thu Dec 3 12:17:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGESALERECORDWIDGET_H
#define UI_PAGESALERECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageSaleRecordWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshInventoryBtn;
    QTreeWidget *drugInventoryList;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *refreshRecordBtn;
    QTreeWidget *recordList;

    void setupUi(QWidget *PageSaleRecordWidget)
    {
        if (PageSaleRecordWidget->objectName().isEmpty())
            PageSaleRecordWidget->setObjectName(QString::fromUtf8("PageSaleRecordWidget"));
        PageSaleRecordWidget->resize(574, 343);
        horizontalLayout_3 = new QHBoxLayout(PageSaleRecordWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(PageSaleRecordWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refreshInventoryBtn = new QPushButton(groupBox_2);
        refreshInventoryBtn->setObjectName(QString::fromUtf8("refreshInventoryBtn"));

        horizontalLayout->addWidget(refreshInventoryBtn);


        verticalLayout->addLayout(horizontalLayout);

        drugInventoryList = new QTreeWidget(groupBox_2);
        drugInventoryList->setObjectName(QString::fromUtf8("drugInventoryList"));

        verticalLayout->addWidget(drugInventoryList);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(PageSaleRecordWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        refreshRecordBtn = new QPushButton(groupBox);
        refreshRecordBtn->setObjectName(QString::fromUtf8("refreshRecordBtn"));

        horizontalLayout_2->addWidget(refreshRecordBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        recordList = new QTreeWidget(groupBox);
        recordList->setObjectName(QString::fromUtf8("recordList"));

        verticalLayout_2->addWidget(recordList);


        horizontalLayout_3->addWidget(groupBox);


        retranslateUi(PageSaleRecordWidget);

        QMetaObject::connectSlotsByName(PageSaleRecordWidget);
    } // setupUi

    void retranslateUi(QWidget *PageSaleRecordWidget)
    {
        groupBox_2->setTitle(QApplication::translate("PageSaleRecordWidget", "\345\272\223\345\255\230", 0, QApplication::UnicodeUTF8));
        refreshInventoryBtn->setText(QApplication::translate("PageSaleRecordWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = drugInventoryList->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251\345\272\223\345\255\230\351\207\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251\345\220\215\345\255\227", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251\346\240\207\347\255\276ID", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251ID\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PageSaleRecordWidget", "\345\207\272\345\205\245\345\272\223\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PageSaleRecordWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        refreshRecordBtn->setText(QApplication::translate("PageSaleRecordWidget", "Refresh", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = recordList->headerItem();
        ___qtreewidgetitem1->setText(5, QApplication::translate("PageSaleRecordWidget", "\344\272\244\346\230\223\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(4, QApplication::translate("PageSaleRecordWidget", "\345\207\272\345\205\245\345\272\223\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("PageSaleRecordWidget", "\350\277\233\345\207\272\350\264\247\347\211\251\351\207\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("PageSaleRecordWidget", "\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("PageSaleRecordWidget", "\350\264\247\347\211\251\345\220\215\345\255\227", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("PageSaleRecordWidget", "\350\256\260\345\275\225ID\345\217\267", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PageSaleRecordWidget);
    } // retranslateUi

};

namespace Ui {
    class PageSaleRecordWidget: public Ui_PageSaleRecordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGESALERECORDWIDGET_H
