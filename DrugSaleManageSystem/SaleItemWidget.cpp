#include "SaleItemWidget.h"
#include "ui_SaleItemWidget.h"

SaleItemWidget::SaleItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaleItemWidget)
{
    ui->setupUi(this);
}

SaleItemWidget::SaleItemWidget(const QString &id, const QString &drugName, float price, \
                               const QString &cate_name, int count, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::SaleItemWidget)
{
    ui->setupUi(this);

    ui->idLabel->setText(id);
    ui->nameEdit->setText(drugName);
    ui->priceEdit->setText(QString::number(price));
    ui->countEdit->setValue(count);
    ui->label_4->setText(cate_name);
    connect(ui->countEdit, SIGNAL(valueChanged(int)), this, SIGNAL(countChaned(int)));
}

SaleItemWidget::~SaleItemWidget()
{
    delete ui;
}

void SaleItemWidget::on_delBtn_clicked()
{
    this->deleteLater();
}

QString SaleItemWidget::id() const
{
    return ui->idLabel->text();
}

QString SaleItemWidget::drugName() const
{
    return ui->nameEdit->text();
}

float SaleItemWidget::drugPrice() const
{
    return ui->priceEdit->text().toFloat();
}

int SaleItemWidget::count() const
{
    return ui->countEdit->value();
}

int SaleItemWidget::maxCount() const
{
    return ui->countEdit->maximum();
}
QString SaleItemWidget::cate_name() const
{
    return ui->label_4->text();
}

void SaleItemWidget::disable_combox()
{
    ui->countEdit->setEnabled(false);
}

void SaleItemWidget::disable_delButton()
{
    ui->delBtn->setEnabled(false);
}

void SaleItemWidget::setID(const QString &id)
{
    ui->idLabel->setText(id);
}

void SaleItemWidget::setDrugName(const QString &name)
{
    ui->nameEdit->setText(name);
}

void SaleItemWidget::setDrugPrice(float price)
{
    ui->priceEdit->setText(QString::number(price));
}

void SaleItemWidget::setCount(int count)
{
    ui->countEdit->setValue(count);
}
void SaleItemWidget::setCurrentCount(int count)
{
    ui->label_6->setText(QString::number(count));
}

int SaleItemWidget::getCurrentCount()
{
    return ui->label_6->text().toInt();
}

void SaleItemWidget::setMaxCount(int maxCount)
{
    ui->countEdit->setMaximum(maxCount);
}

void SaleItemWidget::setCate_name(const QString &cate_name)
{
    ui->label_4->setText(cate_name);
}
