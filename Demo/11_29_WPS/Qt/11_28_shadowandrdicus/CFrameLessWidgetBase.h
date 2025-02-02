#pragma once
#include <Qwidget>
#include <QByteArray>

class CFrameLessWidgetBase :public QWidget
{
	Q_OBJECT

public:
	CFrameLessWidgetBase(QWidget* parent = Q_NULLPTR);
	~CFrameLessWidgetBase();

protected:
	bool nativeEvent(const QByteArray eventType, void* message, qintptr* result);

private:
	int mouse_margin = 5;
};

