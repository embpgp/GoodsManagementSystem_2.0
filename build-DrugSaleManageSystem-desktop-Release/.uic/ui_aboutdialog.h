/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Thu Dec 3 12:23:58 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 345);
        AboutDialog->setMinimumSize(QSize(400, 345));
        AboutDialog->setMaximumSize(QSize(400, 345));
        AboutDialog->setLayoutDirection(Qt::LeftToRight);
        AboutDialog->setSizeGripEnabled(false);
        AboutDialog->setModal(true);
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 321, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 341, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 180, 261, 51));
        label_3->setFont(font1);
        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 250, 201, 16));
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 280, 251, 16));
        label_6 = new QLabel(AboutDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 310, 91, 16));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\347\211\210\346\235\203\346\211\200\346\234\211", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "\346\254\242\350\277\216\344\275\277\347\224\250\344\273\223\345\272\223\347\256\241\347\220\206\347\263\273\347\273\237!", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutDialog", "\344\275\234\350\200\205\357\274\232\345\264\224\346\231\227\345\256\201 \345\275\255\350\211\272\345\250\207 \350\203\241\346\264\213 \350\231\236\346\226\207\351\276\231", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AboutDialog", "\346\275\230\351\253\230\351\271\217 \351\251\254\346\230\214\351\224\213 \345\210\230\346\272\220", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AboutDialog", "\347\211\210\346\235\203\346\211\200\346\234\211\357\274\232\351\225\277\346\262\231\347\220\206\345\267\245\345\244\247\345\255\246", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AboutDialog", "\350\256\241\347\256\227\346\234\272\344\270\216\351\200\232\344\277\241\345\267\245\347\250\213\345\255\246\351\231\242\347\275\221\347\273\234\345\267\245\347\250\2131301\347\217\255", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AboutDialog", "2015\345\271\26412\346\234\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
