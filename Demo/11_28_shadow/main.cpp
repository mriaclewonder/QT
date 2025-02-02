#include "shadow.h"
#include <QtWidgets/QApplication>
#include "CLoginDlg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLoginDlg w;
    w.show();
    return a.exec();
}
