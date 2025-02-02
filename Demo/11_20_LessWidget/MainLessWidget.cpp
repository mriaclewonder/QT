#include "MainLessWidget.h"
#include <QMouseEvent>

// ��Ҫ�����ޱ߿򴰿�  ��  ��ôȥ�ƶ���

/*
*  mouse_pos = event->globalPos();
C4996 ������������ʹ���˹�ʱ�ķ��� QMouseEvent::globalPos��
���� Qt 6 �����ϰ汾�н������ globalPosition() ������������Ϊ Qt 6 ���¼�����������ִ���������֧�ָ���׼�ĸ��������ꡣ

�޸��������£�

ʹ�� globalPosition() ��� globalPos()��
globalPosition() ���ص��� QPointF ���ͣ������Ҫ��ʽת��Ϊ QPoint��
*/
MainLessWidget::MainLessWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint); // ����
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
