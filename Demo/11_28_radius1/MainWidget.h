#pragma once

#include <QtWidgets/QWidget>
#include <QPainter>
#include <QMouseEvent>
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
private:
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};
