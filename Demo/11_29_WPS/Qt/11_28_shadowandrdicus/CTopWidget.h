#pragma once
#include <QWidget>
class CTopWidget : public QWidget
{
	Q_OBJECT

public:
	CTopWidget(QWidget* parent = nullptr);
	~CTopWidget();

signals:
	void sig_close();
	void sig_max(bool isMax);
};

