/********************************************************************************
** Form generated from reading UI file 'BigSpinBoxEdit.ui'
**
** Created: Thu Dec 3 12:23:58 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIGSPINBOXEDIT_H
#define UI_BIGSPINBOXEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BigSpinBoxEdit
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QGridLayout *mainLayout;

    void setupUi(QWidget *BigSpinBoxEdit)
    {
        if (BigSpinBoxEdit->objectName().isEmpty())
            BigSpinBoxEdit->setObjectName(QString::fromUtf8("BigSpinBoxEdit"));
        BigSpinBoxEdit->resize(142, 70);
        vboxLayout = new QVBoxLayout(BigSpinBoxEdit);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(BigSpinBoxEdit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        mainLayout = new QGridLayout(groupBox);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));

        vboxLayout->addWidget(groupBox);


        retranslateUi(BigSpinBoxEdit);

        QMetaObject::connectSlotsByName(BigSpinBoxEdit);
    } // setupUi

    void retranslateUi(QWidget *BigSpinBoxEdit)
    {
        Q_UNUSED(BigSpinBoxEdit);
    } // retranslateUi

};

namespace Ui {
    class BigSpinBoxEdit: public Ui_BigSpinBoxEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIGSPINBOXEDIT_H
