#ifndef SALEITEMWIDGET_H
#define SALEITEMWIDGET_H

#include <QWidget>

namespace Ui {
    class SaleItemWidget;
}

class SaleItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SaleItemWidget(QWidget *parent = 0);
    SaleItemWidget(const QString &id, const QString &drugName, float price,\
                   const QString &cate_name, int count, QWidget *parent = 0);
    ~SaleItemWidget();

    QString id() const;
    QString drugName() const;
    float drugPrice() const;
    int count() const ;
    int maxCount() const;
    QString cate_name()const;
    void disable_combox(void);
    void disable_delButton(void);
signals:
    void countChaned(int count);

public slots:
    void setID(const QString &id);
    void setDrugName(const QString &name);
    void setDrugPrice(float price);
    void setCount(int count);
    void setMaxCount(int maxCount);
    void setCate_name(const QString &cate_name);
    void setCurrentCount(int count);
    int  getCurrentCount(void);
    void remove() {this->deleteLater();}
//   void setCate_name(const QString &name);
private:
    Ui::SaleItemWidget *ui;

private slots:
    void on_delBtn_clicked();
};

#endif // SALEITEMWIDGET_H
