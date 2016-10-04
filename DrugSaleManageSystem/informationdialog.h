#ifndef INFORMATIONDIALOG_H
#define INFORMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class InformationDialog;
}

class InformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformationDialog(QWidget *parent = 0);
    ~InformationDialog();


    QString getText(void);
    void setText(const QString &text);
private:
    Ui::InformationDialog *ui;
};

#endif // INFORMATIONDIALOG_H
