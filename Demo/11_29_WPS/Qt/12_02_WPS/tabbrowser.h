#pragma once
#include <QMenu>
#include <QTabWidget>

#include "CTabTitleWidget.h"

class tabbrowser :public QTabWidget
{
	Q_OBJECT

public:
	// explicit关键字用于修饰构造函数，以防止它们在只有一个参数的情况下被隐式调用。使用explicit的关键在于你希望确保类型的显式转换，从而避免可能的类型混淆或逻辑错误。
	explicit tabbrowser(QWidget* parent = 0);

	// tab操作标志
	enum TAB_FLAG
	{
		NEW,
		CLOSE,
		NORMAL,
		SPECIAL
	};
protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	void initTabWidget();
	void setTabBarFlag(TAB_FLAG flag);
	void createTabMenu();

signals:
	void sig_close();

private slots:
	void on_newTab();
	void on_closeTab(int index);
	void on_MenuShow(const QPoint& ops);
	void on_closeAllTab();

private:
	CTabTitleWidget* m_pRightWidget = nullptr;
	QMenu* m_pMenu = nullptr;
};

