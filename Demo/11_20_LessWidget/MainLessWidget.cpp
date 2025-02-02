#include "MainLessWidget.h"
#include <QMouseEvent>

// 主要设置无边框窗口  和  怎么去移动它

/*
*  mouse_pos = event->globalPos();
C4996 错误是由于您使用了过时的方法 QMouseEvent::globalPos，
而在 Qt 6 及以上版本中建议改用 globalPosition() 方法。这是因为 Qt 6 对事件处理进行了现代化调整，支持更精准的浮点数坐标。

修复方法如下：

使用 globalPosition() 替代 globalPos()。
globalPosition() 返回的是 QPointF 类型，因此需要显式转换为 QPoint。
*/
MainLessWidget::MainLessWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint); // 隐藏
}

MainLessWidget::~MainLessWidget()
{}

void MainLessWidget::mousePressEvent(QMouseEvent * event)
{
    mouse_pos = event->globalPosition().toPoint();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void MainLessWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPosition().toPoint();
    //this->move(pos);
    this->move(pos - diff_pos);
}
