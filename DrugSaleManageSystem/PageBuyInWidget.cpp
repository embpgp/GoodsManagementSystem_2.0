#include "PageBuyInWidget.h"
#include "ui_PageBuyInWidget.h"
#include "SaleItemWidget.h"
#include "PriceDialog.h"
#include "DBControl.h"
#include <QDebug>
#include <QMessageBox>
#include "UHF900MPackage.h"
#include "informationdialog.h"
PageBuyInWidget::PageBuyInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageBuyInWidget)
{
    ui->setupUi(this);

}

PageBuyInWidget::~PageBuyInWidget()
{
    delete ui;
}


//每当有货物入库便执行到这里，，因此需要在这进行控制计数
void PageBuyInWidget::onCardDetected(int radio, const QString &id)
{

    //计数控制
    //这里如果if语句不执行表示只是第一次的入库清单时候，防止重复地清单，这是我自己做的，他提供的
    //代码中没有对这个进行控制，，，可能会导致人思维不一致，也可能导致程序错误
    if(!ui->storageBtn->isEnabled())
    {

        int i = ui->sailListLayout->count();
        bool flag = false;
        for(i = i - 1; i >= 0; i--)
        {
            SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
            item->disable_combox();    //禁止更改数量按钮
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
                      //下面这个对话框是我自己加的，目的就是为了显示我想显示的信息
                      //为什么要自己写一个而不用QT提供的呢？这是为了继续完成交互
                      //设置对话框为非模态的，QT的总是一闪而过，因此我在堆里申请了一个
                      InformationDialog *indlg = new InformationDialog(this);
                      indlg->setText(tr("%1入库完成，数量为%2").arg(item->drugName()).arg(count));
                      indlg->setModal(false);   //非模态
                      indlg->show();           //显示
                      //入库
                      DBDrugInfo::buyIn(item->id(), item->drugName(), item->cate_name(), item->drugPrice(), count);
                      item->deleteLater();      //删除已经满足数量的条目
                      emit refresh_readcardid(); //发出重新读卡的信号
                      return;                      //直接返回，完成本次读卡

                }

            }

        }

        i = ui->sailListLayout->count();
        if(i == 0)        //这里表示所有的清单完全没有了，即入库完成
        {
             ui->storageBtn->setEnabled(true);
             return;
        }

        //标志位表示清单没有的货物，经过for循环没有被改变就知道是不存在清单中的货物了
        if(!flag)
        {
            QMessageBox::information(this,tr("入库提示"),tr("入库清单中没有这种货物"));
            emit refresh_readcardid();
            return;
        }




    }
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

        //这是第一次预入库为了省事儿自己不用输入而用一个样品来获得属性并确定清单
        QString name = DBDrugInfo::findName(id);
        float price = DBDrugInfo::findPrice(id);
        QString cate_name = DBCategories::findName(DBDrugInfo::findCatid(id));
        if(name.isEmpty())
        {
            PriceDialog dlg;
            if(dlg.exec() == QDialog::Rejected)
                return;
            name = dlg.name();
            price = dlg.price();
            cate_name = dlg.cate_name();
        }
        SaleItemWidget *item = new SaleItemWidget(id, name, price,cate_name, 1, this);
        item->setMaxCount(10000);
        ui->sailListLayout->addWidget(item);
    }

    emit refresh_readcardid();


}

void PageBuyInWidget::on_storageBtn_clicked()
{
    /*
    int i = ui->sailListLayout->count(); 
    for(i = i - 1; i >= 0; i--)
    {
        SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
        if(item == NULL)
            continue;

//参数  1、卡片的标签id   2、物品的名字  3、物品所存放的区域名字（类别名字）  4、价格 5、数量
 //       DBDrugInfo::buyIn(item->id(), item->drugName(), item->cate_name(), item->drugPrice(), item->count());

    }

    */
    ui->storageBtn->setEnabled(false);          //根据按键的状态进行控制
    emit refresh_readcardid();

}


//中断直接入库了
void PageBuyInWidget::on_pushButton_clicked()
{
    int i = ui->sailListLayout->count();
    for(i = i - 1; i >= 0; i--)
    {
        SaleItemWidget *item = qobject_cast<SaleItemWidget *>(ui->sailListLayout->itemAt(i)->widget());
        if(item == NULL)
            continue;
        int count = item->getCurrentCount();
//参数  1、卡片的标签id   2、物品的名字  3、物品所存放的区域名字（类别名字）  4、价格 5、数量
        DBDrugInfo::buyIn(item->id(), item->drugName(), item->cate_name(), item->drugPrice(), count);

        item->deleteLater();
    }
    ui->storageBtn->setEnabled(true);     //使能入库按钮，为下一次入库做准备

    QMessageBox::information(this,tr("入库提示"),tr("中断入库完成"));
}
