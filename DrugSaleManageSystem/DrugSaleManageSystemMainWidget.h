#ifndef DRUGSALEMANAGESYSTEMMAINWIDGET_H
#define DRUGSALEMANAGESYSTEMMAINWIDGET_H

#include <QWidget>
#include <QTranslator>
#include <QByteArray>
#include "UHF900MPackage.h"

namespace Ui {
    class DrugSaleManageSystemMainWidget;
}

class QextSerialPort;
class DrugSaleManageSystemMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DrugSaleManageSystemMainWidget(QWidget *parent = 0);
    ~DrugSaleManageSystemMainWidget();

signals:
    void recvPackage(UHF900MPackage *pkg);    //从串口接收数据包
    void cardDetected(int radio, const QString &id);  //卡锁定



    void get_cate(const QString &name);    //获得分区的名字
public slots:
    bool start(const QString &port);         //进行串口的初始化，波特率、检验位等
    bool stop();                            //关闭串口

private:
    Ui::DrugSaleManageSystemMainWidget *ui;   //主界面
    QTranslator *trans;                     //字体转换
    QextSerialPort *commPort;             //串口
    QByteArray lastRecvedPackage;          //回应报文
    bool isNormalPackage;                 //是否正常包
    enum { Idle, GetScanMode, GetMode, GetTimeDelay, GetCommIf } settingStatus;
     //枚举出控制读写器的类型


    //下面的信号与槽可以看英文名字就知道了
private slots:
    void on_openCloseBtn_clicked(bool checked);
    void on_refreshBtn_clicked();

    void onPortDataReady();
    void onRecvedPackage(UHF900MPackage *pkg);
    void sendData(const QByteArray &pkg);
    void onScanReGetIdBtnClicked();
    void sendData(const UHF900MPackage &pkg);

    void onScanResetBtnClicked();
    void onScanSingleBtnClicked();
    void onScanStopBtnClicked();
    void onScanReScanBtnClicked();


    void onReadBtnClicked(int section, int address, int length);
    void onWriteBtnClicked(int section, int address, int length, const QByteArray &data);

    void onApplySettingBtnClicked();

    void onCardDetected(int radio, const QString &id);
    void on_refreshSerialPortList_clicked();
    void on_openCloseBtn_clicked();
    void on_comboBox_activated(const QString &arg1);
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_opListTable_selected(const QString &arg1);
};

#endif // DRUGSALEMANAGESYSTEMMAINWIDGET_H
