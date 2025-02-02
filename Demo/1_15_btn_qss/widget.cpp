#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton_2->setText(u8"会员");
    ui->pushButton_2->setFixedSize(80,64);
    ui->pushButton_2->setIcon(QIcon(":/resources/vip_yes.png"));
    ui->pushButton_2->setLayoutDirection(Qt::LeftToRight);

    ui->pushButton_4->setFixedSize(200,64);
    ui->pushButton_4->setText(u8"非会员");
    QString btnStyle = "QPushButton{"
                       "background-image: url(:/resources/vip_no.png);"
                       "background-repeat: no-repeat;"
                       "background-origin: padding;"
                       "background-position: left;"
                       "padding-left:65px;"
                       "border: none;"
                       "background-color: rgb(0, 255, 255);"
                       "color:rgb(0, 0, 0);"
                       "text-align:left;"
                       "font: bold italic 30px \"Microsoft YaHei\";"
                       "}";
    ui->pushButton_4->setStyleSheet(btnStyle);
}

Widget::~Widget()
{
    delete ui;
}
