#include "PriceDialog.h"
#include "ui_PriceDialog.h"
#include "DBControl.h"
PriceDialog::PriceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PriceDialog)
{
    ui->setupUi(this);

    ui->sftKeypad->changeRecver(ui->nameEdit);
//    ui->sftKeypad->setAllMethodEnabled(false);
//    ui->sftKeypad->setMethodEnabled(T9Widget::english, true);
//    ui->sftKeypad->setMethod(T9Widget::english);
    connect(ui->sftKeypad, SIGNAL(newString(QString)), this, SLOT(onSftKeypadNewString(QString)));
    int nCount = DBCategories::CountCate();
    QStringList strlist;
    for(int i = 1; i<nCount + 1; ++i)
    {
        strlist<<DBCategories::findName(i);

    }
    ui->comboBox->addItems(strlist);
}

PriceDialog::~PriceDialog()
{
    delete ui;
}

void PriceDialog::onSftKeypadNewString(const QString &str)
{
    ui->nameEdit->insert(str);
}

float PriceDialog::price() const
{
    return ui->priceWidget->value();
}

QString PriceDialog::name() const
{
    return ui->nameEdit->text();
}

QString PriceDialog::cate_name()const
{
    return ui->comboBox->currentText();
}
void PriceDialog::setPrice(float p)
{
    ui->priceWidget->setValue(p);
}

void PriceDialog::setName(const QString &name)
{
    ui->nameEdit->setText(name);
}
void PriceDialog::setCate(int index,const QString &cate_name)
{
    ui->comboBox->setItemText(index,cate_name);
}
