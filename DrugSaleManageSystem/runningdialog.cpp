#include "runningdialog.h"
#include "ui_runningdialog.h"
#include <DBControl.h>
RunningDialog::RunningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunningDialog)
{
    ui->setupUi(this);
}

QString RunningDialog::name()const
{
    return ui->label->text();
}
int RunningDialog::currentValue()const
{


}

RunningDialog::~RunningDialog()
{
    delete ui;
}

void RunningDialog::get_sum(QString stringid[], int arraycount[], int n)
{
    for(int i = 0; i<n; i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);

        item->setText(0, DBDrugInfo::findName(stringid[i]));
        item->setText(1, QString::number(0));
        item->setText(2, QString::number(arraycount[i]));

    }

}
