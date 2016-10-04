#include "PageSaleOutWidget.h"
#include "ui_PageSaleOutWidget.h"
#include "SaleItemWidget.h"
#include "DBControl.h"
#include <QMessageBox>
#include <QDebug>
#include "informationdialog.h"
PageSaleOutWidget::PageSaleOutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSaleOutWidget)
{
    ui->setupUi(this);
}

PageSaleOutWidget::~PageSaleOutWidget()
{
    delete ui;
}
//更新左下角的计费显示框
void PageSaleOutWidget::updateAmount()
{
    float totAmount = 0.0;
    int i;
    for(i = ui->sailListLayout->count() - 1; i >= 0; i--)
    {
        SaleItemWidget *w = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
        if(w == NULL)
            continue;

        totAmount += w->drugPrice() * w->getCurrentCount();
    }
    ui->totalAmountEdit->setText(QString::number(totAmount));
}
//直接调用上面的，但是并没有去调用
void PageSaleOutWidget::onSaleItemCountChanged(int count)
{
    updateAmount();
}

void PageSaleOutWidget::onSaleItemDeleted()
{
    updateAmount();
}




//每当有货物出库便执行到这里，，因此需要在这进行控制计数
void PageSaleOutWidget::onCardDetected(int radio, const QString &id)
{



    if(!ui->saleBtn->isEnabled())
    {

        int i = ui->sailListLayout->count();
        bool flag = false;
        for(i = i - 1; i >= 0; i--)
        {
            SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
            item->disable_combox();
            item->disable_delButton();//禁止删除按钮

            if(item == NULL)
            {
                  continue;
            }
            if(id == item->id())
            {
                flag = true;
                int count = item->getCurrentCount();  //先获取当前计数
                ++count;    //计数++
                item->setCurrentCount(count);    //立即更新当前计数
                if(count == item->count())   //货物数量够了
                {


                    InformationDialog *indlg = new InformationDialog(this);
                    indlg->setText(tr("%1入库完成，数量为%2").arg(item->drugName()).arg(count));
                    indlg->setModal(false);   //设置为非模态，使得入库可以继续交互
                    indlg->show();
                    DBDrugInfo::saleOut(item->id(), count);

                    item->deleteLater();
                    emit refresh_readcardid();
                    updateAmount();
                    i = ui->sailListLayout->count();
                    qDebug()<<"area empty"<<i;
                    if(i == 0)        //这里表示所有的清单完全没有了，即入库完成
                    {
                         ui->saleBtn->setEnabled(true);
                         ui->pushButton_2->setEnabled(true);
                         return;
                    }

                }

            }

        }



        //标志位表示清单没有的货物，经过for循环没有被改变就知道是不存在清单中的货物了
        if(!flag)
        {
            QMessageBox::information(this,tr("出库提示"),tr("出库清单中没有这种货物"));
            emit refresh_readcardid();
            return;
        }

        updateAmount();


    }
     //应老师的要求改成了“推送”，即出库前罗列出仓库所有的货物，因此这里的刷卡加载不需要了
    /*
    else
    {
    //防止重复识别
        int i = ui->sailListLayout->count();
        for(i = i - 1; i >= 0; i--)
           {
             SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
             if(item == NULL)
                continue;
             if(id == item->id())
               {

                  return ;
               }
           }


      QString name = DBDrugInfo::findName(id);
      if(name.isEmpty())
        {
          QMessageBox::information(this, tr("警告"), tr("仓库中没有这样的货物!"));
          return;
        }

        float price = DBDrugInfo::findPrice(id);
        int gid = DBDrugInfo::findId(id);
        int count = DBInventory::findCount(gid);
        QString cate_name = DBCategories::findName(DBDrugInfo::findCatid(id));


        SaleItemWidget *item = new SaleItemWidget(id, name, price, cate_name, 1, this);

        connect(item, SIGNAL(countChaned(int)), this, SLOT(onSaleItemCountChanged(int)));
        connect(item, SIGNAL(destroyed()), this, SLOT(onSaleItemDeleted()));
        item->setMaxCount(count);     //最大允许出库数量，已经从库存表中拿出来了
        ui->sailListLayout->addWidget(item);
        updateAmount();    //更新左下角的钱数目
    }
     */
    refresh_readcardid();
}

void PageSaleOutWidget::on_saleBtn_clicked()
{

    ui->saleBtn->setEnabled(false);    //灰化出库按钮，禁止再次点击出库
    ui->pushButton_2->setEnabled(false); //禁止重新获取库存清单按钮
    emit refresh_readcardid();          //刷新读卡信号
}


//中断出库
void PageSaleOutWidget::on_pushButton_clicked()
{
    //获得显示框中总条目数
    int i = ui->sailListLayout->count();
    for(i = i - 1; i >= 0; i--)
    {
        //用指针强制转换成自定义所需要的单条目类型
        SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
        if(item == NULL)
            continue;

        int count = item->getCurrentCount();   //将已经出库的数量获得，然后去更新数据库
        DBDrugInfo::saleOut(item->id(), count);
        item->deleteLater();             //删除显示的条目
    }

    ui->saleBtn->setEnabled(true);       //使能出库按钮
    ui->pushButton_2->setEnabled(true); //使能重新获取库存清单按钮
    updateAmount();                        //更新计费
    QMessageBox::information(this,tr("出库提示"),tr("中断出库完成"));

}

void PageSaleOutWidget::on_pushButton_2_clicked()
{
    //先清除所有的显示项目
    int i = ui->sailListLayout->count();
    for(i = i - 1; i >= 0; i--)
    {
        //用指针强制转换成自定义所需要的单条目类型
        SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
        if(item == NULL)
            continue;

        item->deleteLater();             //删除显示的条目
    }




    DBDrugInfo d;         //实例化一个物品对象

    if(d.first())                  //循环索引出所有的库存非0的货物清单
    {

        do {

            int count  = DBInventory::findCount(d.id());
            qDebug()<<"count:"<<count;
            if(0 == count)
            {                //库存为空就不列在清单中
                continue;
            }
            QString cate_name = DBCategories::findName( d.catid());


            SaleItemWidget *item = new SaleItemWidget(d.cardid(), d.name(), d.price(), cate_name, 1, this);

        //    connect(item, SIGNAL(countChaned(int)), this, SLOT(onSaleItemCountChanged(int)));
          //  connect(item, SIGNAL(destroyed()), this, SLOT(onSaleItemDeleted()));
            item->setMaxCount(count);     //最大允许出库数量，已经从库存表中拿出来了
            ui->sailListLayout->addWidget(item);

        } while(d.next());
    }
}
