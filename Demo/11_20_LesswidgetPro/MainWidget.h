#pragma once
#include <QtWidgets/QWidget>
#include "CTitleBar.h"
#include "CFrameLessWidgetBase.h"

class MainWidget:public CFrameLessWidgetBase
{
	Q_OBJECT

public:
	MainWidget(QWidget* parent = Q_NULLPTR);

private slots:
	void on_closeSolt();

private:
	void initUI();

private:
	CTitleBar* ctitleBar = nullptr;
};

