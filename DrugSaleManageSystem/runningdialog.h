#ifndef RUNNINGDIALOG_H
#define RUNNINGDIALOG_H

#include <QDialog>

namespace Ui {
class RunningDialog;
}

class RunningDialog : public QDialog
{
    Q_OBJECT

public:

    QString name() const;
    int currentValue()const;
    int Sum_value()const;
    explicit RunningDialog(QWidget *parent = 0);
    ~RunningDialog();

private:
    Ui::RunningDialog *ui;

public slots:
    void get_sum(QString stringid[],int arraycount[],int n);
};

#endif // RUNNINGDIALOG_H
