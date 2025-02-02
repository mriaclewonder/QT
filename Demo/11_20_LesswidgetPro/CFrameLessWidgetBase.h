#pragma once
#include <QWidget>

class CFrameLessWidgetBase : public QWidget
{
    Q_OBJECT
public:
    CFrameLessWidgetBase(QWidget* parent = nullptr);
    ~CFrameLessWidgetBase() {}

protected:
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result);

private:
    int m_nBorderWidth = 5;
};
