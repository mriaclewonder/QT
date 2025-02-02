#include "widget.h"

#include "cserachlineedit.h"
#include "tabwidget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QHBoxLayout>
Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout* pHLay = new QHBoxLayout(this);
    // this->setStyleSheet("background-color:#1A1E21");

    TabWidget* tabWidget = new TabWidget(this);

    QWidget* w1 = new QWidget;
    w1->setStyleSheet("background-color:rgb(54,54,54)");
    tabWidget->insertTab(0, w1, u8"参数设置");

    QWidget* w2 = new QWidget;
    w2->setStyleSheet("background-color:rgb(154,54,54)");
    tabWidget->insertTab(1, w2, u8"设备管理");

    QWidget* w3 = new QWidget;
    w3->setStyleSheet("background-color:rgb(154,54,154)");
    tabWidget->insertTab(2, w3, u8"设备管理");

    pHLay->addWidget(tabWidget);

    // m_pLine = new CSerachLineedit(this);
    // pHLay->addWidget(m_pLine);

    // connect(m_pLine, &CSerachLineedit::sig_Search, this, &Widget::onSearch);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSearch(const QString& text)
{
    qDebug() << u8"搜索到的内容是" << text;
}
