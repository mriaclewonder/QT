#include "loadqss.h"
#include "ui_loadqss.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
LoadQss::LoadQss(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadQss)
{
    ui->setupUi(this);

    QFile file(":/resources/skin.qss");

    QString lineStr;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textIn(&file);
        while(!textIn.atEnd())
        {
            lineStr += textIn.readLine();   // qss逐行读取
        }
    }
    file.close();
    this->setStyleSheet(lineStr);
}

LoadQss::~LoadQss()
{
    delete ui;
}
