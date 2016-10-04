#ifndef BIGSPINBOXEDIT_H
#define BIGSPINBOXEDIT_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>

namespace Ui {
    class BigSpinBoxEdit;
}

class AddSubButton : public QPushButton
{
    Q_OBJECT

private:
    int _i;
    int _n;

private slots:
    void onClicked() {
        emit clicked(this->_i, this->_n);
    }

signals:
    void clicked(int idx, int neg);

public:
    explicit AddSubButton(QWidget *parent = 0)
        : QPushButton(parent)
    {
        connect(this, SIGNAL(clicked()), this, SLOT(onClicked()));
    }

    ~AddSubButton() {}

    int index() const           { return _i; }
    int neg() const             { return _n; }
public slots:
    void setIndex(int i)        { this->_i = i; }
    void setNeg(int neg)        { this->_n = neg; }
};

class BigSpinBoxEdit : public QWidget
{
    Q_OBJECT

public:
    explicit BigSpinBoxEdit(QWidget *parent = 0);
    ~BigSpinBoxEdit();

    float value() const;

public slots:
    void setValue(float value);
    void setEditable(bool editable = true);

private:
    Ui::BigSpinBoxEdit *ui;
    bool floatMode;
    int numDigit;
    int numFloat;
    float currentValue;
    bool isNeg;

    // ������ʾ����λ
    QLabel *negLabel;
    // ������ʾ���е�����
    QLCDNumber *numContainer;
    // ������ʾÿһ�����ֵļӺͼ�
    AddSubButton *numOpBtn;
    // ����С��ģʽʱ������ʾС����
    QLabel *pntLabel;

private slots:
    void createUI(void);
    void updateUI(bool reCreate = true);
    void destroyUI(void);
    void onNumberOpBtnClicked(int idx, int neg);
};

#endif // BIGSPINBOXEDIT_H
