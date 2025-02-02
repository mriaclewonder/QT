#include "MainWidget.h"
#include <QStyleOption>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // resize(600, 400);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

    // 第二种方式 样式表
    this->setStyleSheet("QWidget{background-color:#FFFFFF;  \
        border-top-left-radius:15px;   \
        border-bottom-right-radius:15px; \
        }");
}

MainWidget::~MainWidget()
{}

void MainWidget::paintEvent(QPaintEvent * event)
{
    // 第一种方式  通过QPainter绘制
    //QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing); // 反锯齿
    //painter.setBrush(QBrush(QColor(255, 255, 255, 255)));
    //painter.setPen(Qt::transparent);
    //QRect rect = this->rect();
    //painter.drawRoundedRect(rect, 15, 15);

    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MainWidget::mousePressEvent(QMouseEvent* event)
{
    windowPos = this->pos();
    mousePos = event->globalPosition().toPoint();
    dPos = mousePos - windowPos;
}

void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
    this->move(event->globalPosition().toPoint() - dPos);
}
