#include "WPSDemo.h"
#include <QtWidgets/QApplication>
#include "CTabTitleWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WPSDemo w;
    w.show();
    return a.exec();
}
