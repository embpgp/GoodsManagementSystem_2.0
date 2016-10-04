#include <QtGui/QApplication>
#include "DrugSaleManageSystemMainWidget.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    DrugSaleManageSystemMainWidget w;
    w.show();

    return a.exec();
}
