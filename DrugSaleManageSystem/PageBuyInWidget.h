#ifndef PAGEBUYINWIDGET_H
#define PAGEBUYINWIDGET_H

#include <QWidget>
#include <runningdialog.h>
namespace Ui {
    class PageBuyInWidget;
}

class PageBuyInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PageBuyInWidget(QWidget *parent = 0);
    ~PageBuyInWidget();

public slots:
    void onCardDetected(int radio, const QString &id);

private:
    Ui::PageBuyInWidget *ui;

signals:

    void refresh_readcardid();   //刷新读卡器的信号
private slots:
    void on_storageBtn_clicked();
    void on_pushButton_clicked();
};

#endif // PAGEBUYINWIDGET_H
