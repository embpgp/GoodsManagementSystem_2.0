#include "DrugSaleManageSystemMainWidget.h"
#include "ui_DrugSaleManageSystemMainWidget.h"
#include "DBControl.h"
#include "ioportManager.h"
#include <qextserialport.h>
#include <qextserialenumerator.h>
#include <QMessageBox>
#include <QDebug>
#include "aboutdialog.h"
DrugSaleManageSystemMainWidget::DrugSaleManageSystemMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrugSaleManageSystemMainWidget),
    commPort(NULL),
    isNormalPackage(true)
{
    trans = new QTranslator(this);                //进行中文支持国际化
    trans->load(":/zh_CN.qm");
    qApp->installTranslator(trans);
    DBControl::Create();                       //创建数据库
    ui->setupUi(this);

    IOPortManager::setMode(Mode900M);         //设置读写器为900M的工作频段
    //连接信号与槽，收包处理函数    读卡处理函数   获取分区名字处理函数等
    connect(this, SIGNAL(recvPackage(UHF900MPackage*)), this, SLOT(onRecvedPackage(UHF900MPackage*)));
    connect(this, SIGNAL(cardDetected(int,QString)), this, SLOT(onCardDetected(int,QString)));
    connect(this,SIGNAL(get_cate(QString)),ui->recordPage,SLOT(get_cate_from(QString)));
          //实时刷新读卡信号
    connect(ui->buyInPage,SIGNAL(refresh_readcardid()),this,SLOT(onApplySettingBtnClicked()));
    connect(ui->saleOutPage,SIGNAL(refresh_readcardid()),this,SLOT(onApplySettingBtnClicked()));

    on_openCloseBtn_clicked(false);
    on_refreshSerialPortList_clicked();
    //显示分区
    int nCount = DBCategories::CountCate();
    QStringList strlist;
    for(int i = 1; i<nCount + 1; ++i)
    {
        strlist<<DBCategories::findName(i);

    }
    ui->comboBox->addItems(strlist);

   //加载背景图片
   // this->setStyleSheet("backgroud-image:url(./pic/backgroud.png)");
    this->setAutoFillBackground(true);
    QPalette palette;
  //  palette.setColor(QPalette::Background, QColor(192,253,123));
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/pic/backgroud.png")));
    this->setPalette(palette);


}

DrugSaleManageSystemMainWidget::~DrugSaleManageSystemMainWidget()
{
    DBControl::Destroy();
    delete ui;
}


//串口工作参数配置
bool DrugSaleManageSystemMainWidget::start(const QString &port)
{
    if(commPort != NULL)
        return false;
    commPort = new QextSerialPort(port,  QextSerialPort::EventDriven);
    commPort->setBaudRate(BAUD9600);
    commPort->setFlowControl(FLOW_OFF);
    commPort->setParity(PAR_NONE);
    commPort->setDataBits(DATA_8);
    commPort->setStopBits(STOP_1);

    if (commPort->open(QIODevice::ReadWrite) == true) {
        connect(commPort, SIGNAL(readyRead()), this, SLOT(onPortDataReady()));
        onApplySettingBtnClicked();
        return true;
    }
    else {
        qDebug() << "device failed to open:" << commPort->errorString();
        delete commPort;
        commPort = NULL;
        return false;
    }
}

bool DrugSaleManageSystemMainWidget::stop()
{
    if(commPort != NULL)
    {
        commPort->close();
        delete commPort;
    }
    commPort = NULL;
    return true;
}



void DrugSaleManageSystemMainWidget::onPortDataReady()
{
    QByteArray bytes;
    int a = commPort->bytesAvailable();
    bytes.resize(a);
    quint8 *p = (quint8 *)bytes.data();
    int len = bytes.size();
    commPort->read((char*)p, len);
    while(len--)
    {
        bool fullPackage = false;
        lastRecvedPackage.append(*p);
        switch(lastRecvedPackage.size())
        {
        case 1:
            if(*p == 0x00)
                isNormalPackage = false;
            else
                isNormalPackage = true;
            break;
        case 2:
            break;
        default:
            if(isNormalPackage)
            {
                if(lastRecvedPackage.size() == (lastRecvedPackage.at(1) + 2))   //此处的+2表示前面的type + length
                {
                    fullPackage = true;
                }
            }
            else
            {
                if(lastRecvedPackage.size() == 17)
                {
                    fullPackage = true;
                }
            }
            break;
        }
        if(fullPackage)
        {

            UHF900MPackage *pkg = new UHF900MPackage(lastRecvedPackage);
            if(pkg->isValid())
                emit this->recvPackage(pkg);
            lastRecvedPackage.clear();
        }
        p++;
    }
}

// 接收到完整数据包
void DrugSaleManageSystemMainWidget::onRecvedPackage(UHF900MPackage *pkg)
{
    // TODO: switch package type
    if(pkg->isValid())
    {
        if(pkg->isNormalPackage())
        {
            switch(pkg->command())
            {
            case UHF900MPackage::IdentifyEPC:
                if(pkg->data().size() == 13)
                {
                    emit cardDetected(int(pkg->data().at(0)), pkg->data().mid(1).toHex());
                }

                break;

            case UHF900MPackage::WriteSetting:
                switch(settingStatus)
                {
                case GetScanMode:
                    {
                        settingStatus = GetMode;
                        QByteArray regData;
                        regData.append((char)0x00);
                        regData.append((char)0x70);        //配置读卡器为定时器模式工作
                        regData.append((char)2);        //1 for C/S, 2 for timer, 3 for trigger
//                        regData.append((char)ui->uhf900mSettingTab->mode());
                        UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::WriteSetting, 0, regData);
                        sendData(pkg);
                    }
                    break;
                case GetMode:
                    {
                        settingStatus = GetTimeDelay;
                        QByteArray regData;
                        regData.append((char)0x00);
                        regData.append((char)0x71);
                        regData.append((char)15);     //时间间隔为N*10 ms，N从10~100    15
//                        regData.append((char)ui->uhf900mSettingTab->delay());
                        UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::WriteSetting, 0, regData);
                        sendData(pkg);
                    }
                    break;
                case GetTimeDelay:
                    {
                        settingStatus = GetCommIf;
                        QByteArray regData;
                        regData.append((char)0x00);
                        regData.append((char)0x72);
                        regData.append((char)3);//1 for RS485,2 for Wiegand, 3 for RS232
//                        regData.append((char)ui->uhf900mSettingTab->commIf());
                        UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::WriteSetting, 0, regData);
                        sendData(pkg);
                    }
                    break;
                case GetCommIf:
                    {
                        settingStatus = Idle;
                        sendData(UHF900MPackage(UHF900MPackage::CommandPkg, UHF900MPackage::ResetDevice, 0));
                    }
                    break;
                case Idle:
                    break;
                }
                break;
            }
        }
        else
        {
            emit cardDetected(int(pkg->data().right(1).at(0)), pkg->data().left(12).toHex());



  //          qDebug()<<tr("天线号：")<<(int)(pkg->data().right(1).at(0));
   //         qDebug()<<tr("卡号：")<<pkg->data().left(12).toHex();           //直接打印出卡号了

        }
    }
    delete pkg;
}

void DrugSaleManageSystemMainWidget::sendData(const QByteArray &pkg)
{

    if(commPort)
        commPort->write(pkg);
}

void DrugSaleManageSystemMainWidget::sendData(const UHF900MPackage &pkg)
{
    if(commPort)
        commPort->write(pkg.toRawPackage());
}

void DrugSaleManageSystemMainWidget::onScanResetBtnClicked()
{
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::ResetDevice, 0);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onScanSingleBtnClicked()
{
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::IdentifyEPC, 0);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onScanStopBtnClicked()
{
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::StopIdentifyEPC, 0);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onScanReScanBtnClicked()
{
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::ReIdentifyEPC, 0);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onScanReGetIdBtnClicked()
{
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::ReGetEPC, 0);
    sendData(pkg);
}
//其实下面的我们并没用到
// 界面处理函数
void DrugSaleManageSystemMainWidget::onReadBtnClicked(int section, int address, int length)
{
    QByteArray readInfo;
    readInfo.append((char)section);
    readInfo.append((char)address);
    readInfo.append((char)length);
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::ReadEPC, 0, readInfo);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onWriteBtnClicked(int section, int address, int length, const QByteArray &data)
{
    QByteArray writeInfo;
    if(length == 1)
        writeInfo.append((char)0x00);
    else
        writeInfo.append((char)0x01);
    writeInfo.append((char)section);
    writeInfo.append((char)address);
    writeInfo.append((char)length);
    writeInfo.append(data);
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::WriteEPC, 0, writeInfo);
    sendData(pkg);
}

void DrugSaleManageSystemMainWidget::onApplySettingBtnClicked()
{
    settingStatus = GetScanMode;
    QByteArray regData;
    regData.append((char)0x00);
    regData.append((char)0x87);
    regData.append((char)1);    // 0 for single scan, 1 for multi scan
//    regData.append((char)ui->uhf900mSettingTab->scanMode());
    UHF900MPackage pkg(UHF900MPackage::CommandPkg, UHF900MPackage::WriteSetting, 0, regData);
    sendData(pkg);
}


//根据index索引将收到的卡号提示转发至相应的窗口
void DrugSaleManageSystemMainWidget::onCardDetected(int radio, const QString &id)
{
    // TODO:
    switch(ui->opListTable->currentIndex())
    {
    case 0:
        // sale
        ui->saleOutPage->onCardDetected(radio, id);
        break;
    case 1:
        // buy
        ui->buyInPage->onCardDetected(radio, id);
        break;
    case 2:
        // manage
        break;
    }
}

void DrugSaleManageSystemMainWidget::on_openCloseBtn_clicked(bool checked)
{
    if(checked)
    {
        //qDebug()<<"set mode success";
        IOPortManager::setMode(Mode900M);

        if(start(ui->serialPortList->itemData(ui->serialPortList->currentIndex()).toString()))
        {
            AboutDialog *aboutdlg = new AboutDialog(this);    //显示版权所有
           // aboutdlg->setModal(false);
            ui->openCloseBtn->setText(tr("Opened"));
            ui->openCloseBtn->setIcon(QIcon(":/pic/shut_down_normal.png"));
            ui->contentWidget->setEnabled(true);
            aboutdlg->show();
            return;
        }
    }



    this->stop();
    ui->openCloseBtn->setText(tr("Closed"));
    ui->openCloseBtn->setIcon(QIcon(":/pic/shut_down_grayed.png"));
    ui->contentWidget->setEnabled(false);
    ui->openCloseBtn->setChecked(false);
}

void DrugSaleManageSystemMainWidget::on_refreshBtn_clicked()
{
    onApplySettingBtnClicked();
//    onScanResetBtnClicked();
}

void DrugSaleManageSystemMainWidget::on_refreshSerialPortList_clicked()
{
    if(commPort != NULL)
    {
        ui->refreshSerialPortList->setEnabled(false);
        return;
    }
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    ui->serialPortList->clear();
#ifndef _WIN32
    ui->serialPortList->addItem("serial0", "/dev/s3c2410_serial0");
    ui->serialPortList->addItem("serial1", "/dev/s3c2410_serial1");
    ui->serialPortList->addItem("serial2", "/dev/s3c2410_serial2");
    ui->serialPortList->addItem("serial3", "/dev/s3c2410_serial3");
#endif
    for(int i = 0; i < ports.count(); i++)
    {
        const QextPortInfo &info = ports.at(i);
        qDebug()<<info.portName<<info.physName<<info.friendName<<info.enumName;
        if(info.portName.contains("LPT"))
            continue;
#ifdef _WIN32
        ui->serialPortList->addItem(info.portName, info.portName);
#else
        ui->serialPortList->addItem(info.portName, info.physName);
#endif
    }
}

void DrugSaleManageSystemMainWidget::on_openCloseBtn_clicked()
{

}

void DrugSaleManageSystemMainWidget::on_comboBox_activated(const QString &arg1)
{

}
void DrugSaleManageSystemMainWidget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    emit get_cate(ui->comboBox->currentText());
}

void DrugSaleManageSystemMainWidget::on_opListTable_selected(const QString &arg1)
{

}
