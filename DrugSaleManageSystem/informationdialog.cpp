#include "informationdialog.h"
#include "ui_informationdialog.h"

InformationDialog::InformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationDialog)
{
    ui->setupUi(this);
}

InformationDialog::~InformationDialog()
{
    delete ui;
}

QString InformationDialog::getText()
{
    return ui->label->text();
}

void InformationDialog::setText(const QString &text)
{
    ui->label->setText(text);
}
