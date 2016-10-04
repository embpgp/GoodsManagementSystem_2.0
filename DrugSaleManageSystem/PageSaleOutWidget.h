#ifndef PAGESALEOUTWIDGET_H
#define PAGESALEOUTWIDGET_H

#include <QWidget>

namespace Ui {
    class PageSaleOutWidget;
}

class PageSaleOutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PageSaleOutWidget(QWidget *parent = 0);
    ~PageSaleOutWidget();

public slots:
    void onCardDetected(int radio, const QString &id);
signals:
     void refresh_readcardid();    //刷新读卡信号
private:
    Ui::PageSaleOutWidget *ui;

private slots:
    void on_saleBtn_clicked();
    void onSaleItemCountChanged(int count);
    void onSaleItemDeleted();
    void updateAmount();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // PAGESALEOUTWIDGET_H
