/********************************************************************************
** Form generated from reading UI file 'PriceDialog.ui'
**
** Created: Thu Dec 3 12:17:32 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRICEDIALOG_H
#define UI_PRICEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include "BigSpinBoxEdit.h"
#include "t9keyboard/t9widget.h"

QT_BEGIN_NAMESPACE

class Ui_PriceDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    BigSpinBoxEdit *priceWidget;
    QLabel *label;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *nameEdit;
    T9Widget *sftKeypad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PriceDialog)
    {
        if (PriceDialog->objectName().isEmpty())
            PriceDialog->setObjectName(QString::fromUtf8("PriceDialog"));
        PriceDialog->resize(174, 244);
        verticalLayout_2 = new QVBoxLayout(PriceDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(PriceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        priceWidget = new BigSpinBoxEdit(groupBox);
        priceWidget->setObjectName(QString::fromUtf8("priceWidget"));

        horizontalLayout->addWidget(priceWidget);


        verticalLayout_2->addWidget(groupBox);

        label = new QLabel(PriceDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        comboBox = new QComboBox(PriceDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        groupBox_2 = new QGroupBox(PriceDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout->addWidget(nameEdit);

        sftKeypad = new T9Widget(groupBox_2);
        sftKeypad->setObjectName(QString::fromUtf8("sftKeypad"));

        verticalLayout->addWidget(sftKeypad);


        verticalLayout_2->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(PriceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(PriceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PriceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PriceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PriceDialog);
    } // setupUi

    void retranslateUi(QDialog *PriceDialog)
    {
        PriceDialog->setWindowTitle(QApplication::translate("PriceDialog", "\344\277\241\346\201\257\346\240\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PriceDialog", "\344\273\267\346\240\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PriceDialog", "\345\210\206\345\214\272\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("PriceDialog", "\350\264\247\347\211\251\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PriceDialog: public Ui_PriceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRICEDIALOG_H
