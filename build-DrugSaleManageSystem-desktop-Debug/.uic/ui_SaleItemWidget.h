/********************************************************************************
** Form generated from reading UI file 'SaleItemWidget.ui'
**
** Created: Thu Dec 3 12:17:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEITEMWIDGET_H
#define UI_SALEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaleItemWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *idLabel;
    QLineEdit *nameEdit;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *priceEdit;
    QLabel *label_2;
    QSpinBox *countEdit;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *delBtn;

    void setupUi(QWidget *SaleItemWidget)
    {
        if (SaleItemWidget->objectName().isEmpty())
            SaleItemWidget->setObjectName(QString::fromUtf8("SaleItemWidget"));
        SaleItemWidget->resize(597, 42);
        horizontalLayout = new QHBoxLayout(SaleItemWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        idLabel = new QLabel(SaleItemWidget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        horizontalLayout->addWidget(idLabel);

        nameEdit = new QLineEdit(SaleItemWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setReadOnly(true);

        horizontalLayout->addWidget(nameEdit);

        label = new QLabel(SaleItemWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_4 = new QLabel(SaleItemWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(SaleItemWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        priceEdit = new QLineEdit(SaleItemWidget);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));
        priceEdit->setReadOnly(true);

        horizontalLayout->addWidget(priceEdit);

        label_2 = new QLabel(SaleItemWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        countEdit = new QSpinBox(SaleItemWidget);
        countEdit->setObjectName(QString::fromUtf8("countEdit"));

        horizontalLayout->addWidget(countEdit);

        label_5 = new QLabel(SaleItemWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(SaleItemWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        delBtn = new QPushButton(SaleItemWidget);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        delBtn->setIcon(icon);

        horizontalLayout->addWidget(delBtn);


        retranslateUi(SaleItemWidget);

        QMetaObject::connectSlotsByName(SaleItemWidget);
    } // setupUi

    void retranslateUi(QWidget *SaleItemWidget)
    {
        label->setText(QApplication::translate("SaleItemWidget", "<html><head/><body><p><span style=\" color:#000000;\">\345\210\206\345\214\272\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SaleItemWidget", "<html><head/><body><p>TextLabel</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SaleItemWidget", "<html><head/><body><p><span style=\" color:#000000;\">\344\273\267\346\240\274\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SaleItemWidget", "<html><head/><body><p><span style=\" color:#000000;\">\346\200\273\346\225\260\351\207\217\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SaleItemWidget", "<html><head/><body><p><span style=\" color:#000000;\">\345\275\223\345\211\215\346\225\260\351\207\217\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        Q_UNUSED(SaleItemWidget);
    } // retranslateUi

};

namespace Ui {
    class SaleItemWidget: public Ui_SaleItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEITEMWIDGET_H
