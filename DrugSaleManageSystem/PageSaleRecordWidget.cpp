#include "PageSaleRecordWidget.h"
#include "ui_PageSaleRecordWidget.h"
#include "DBControl.h"
#include <QTreeWidgetItem>
#include <QDebug>
#include "ui_DrugSaleManageSystemMainWidget.h"
PageSaleRecordWidget::PageSaleRecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSaleRecordWidget)
{
    ui->setupUi(this);
}

PageSaleRecordWidget::~PageSaleRecordWidget()
{
    delete ui;
}

void PageSaleRecordWidget::on_refreshInventoryBtn_clicked()
{
    ui->drugInventoryList->clear();               //清除已经显示的条目
    QString cate_name = ui->label->text();           //获得分区名字，，然后显示相应分区的货物以及记录
    int gid = DBCategories::findId(cate_name);    //获取分区id,物品外键
    DBDrugInfo d(gid);                        //实例化一个物品表对象，传入gid参数

    if(d.first())
    {

        do {

            int count  = DBInventory::findCount(d.id());
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->drugInventoryList);
            item->setText(0, QString::number(d.id()));
            item->setText(1, d.cardid());
            item->setText(2, d.name());
            item->setText(3, QString::number(d.price()));
            item->setText(4, QString::number(count));
        } while(d.next());
    }
}

void PageSaleRecordWidget::on_refreshRecordBtn_clicked()
{
    ui->recordList->clear();              //清除显示

    QString cate_name = ui->label->text();
             //获得分区名字，，然后显示相应分区的货物以及记录
    DBRecord r(cate_name);          //实例化一个记录表对象，传入参数分区名字
    if(r.first())
    {

        do {

            QTreeWidgetItem *item = new QTreeWidgetItem(ui->recordList);
            QString name = DBDrugInfo::findName(r.gid());
            float  price = DBDrugInfo::findPrice(r.gid());
            item->setText(0, QString::number(r.id()));
            item->setText(1, name);
            item->setText(2, QString::number(price));
            item->setText(3, QString::number(r.count()));
            item->setText(4, r.type() ? tr("入库") : tr("出库"));
            item->setText(5, r.date().toString());
        } while(r.next());
    }
}

//同步显示分区名字
void PageSaleRecordWidget::get_cate_from(const QString &name)
{
    ui->label->setText(name);
}
