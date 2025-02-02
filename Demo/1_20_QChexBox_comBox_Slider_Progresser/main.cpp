#include "widget.h"
#include "loadqss.h"
#include "form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    // w.show();

    // LoadQss l;
    // l.show();

    Form f;
    f.show();
    return a.exec();
}
