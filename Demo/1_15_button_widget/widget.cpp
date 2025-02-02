#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include "cvolumebutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800, 600);

    QHBoxLayout *pHlay = new QHBoxLayout(this);

    CVolumeButton* pVolumeButton = new CVolumeButton(this);
    pHlay->addWidget(pVolumeButton);
}

Widget::~Widget()
{
    delete ui;
}
