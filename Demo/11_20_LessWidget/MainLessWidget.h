#pragma once

#include <QtWidgets/QWidget>
#define _CRT_SECURE_NO_WARNINGS

class MainLessWidget : public QWidget
{
    Q_OBJECT

public:
    MainLessWidget(QWidget *parent = nullptr);
    ~MainLessWidget();

private:
    void mousePressEvent(QMouseEvent* event) override;  // ������¼�
    void mouseMoveEvent(QMouseEvent* event) override;   // ����ƶ��¼�

private:
    QPoint diff_pos;    // ��Ծ���
    QPoint window_pos;  // ����λ��
    QPoint mouse_pos;   // ���λ��

};
