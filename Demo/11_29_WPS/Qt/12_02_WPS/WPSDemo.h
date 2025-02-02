#pragma once

#include <QtWidgets/QWidget>

class WPSDemo : public QWidget
{
    Q_OBJECT

public:
    WPSDemo(QWidget *parent = nullptr);
    ~WPSDemo();

protected:
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result);

private slots:
    void on_close();

private:
    int m_BorderWidth = 5; //表示鼠标位于边框缩放范围的宽度
};
