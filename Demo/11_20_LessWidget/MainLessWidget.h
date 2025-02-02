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
    void mousePressEvent(QMouseEvent* event) override;  // 鼠标点击事件
    void mouseMoveEvent(QMouseEvent* event) override;   // 鼠标移动事件

private:
    QPoint diff_pos;    // 相对距离
    QPoint window_pos;  // 窗口位置
    QPoint mouse_pos;   // 鼠标位置

};
