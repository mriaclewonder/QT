#include "MainLessWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainLessWidget w;
    w.show();
    return a.exec();
}
