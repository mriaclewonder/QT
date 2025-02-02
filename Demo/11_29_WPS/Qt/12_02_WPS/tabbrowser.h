#pragma once
#include <QMenu>
#include <QTabWidget>

#include "CTabTitleWidget.h"

class tabbrowser :public QTabWidget
{
	Q_OBJECT

public:
	// explicit�ؼ����������ι��캯�����Է�ֹ������ֻ��һ������������±���ʽ���á�ʹ��explicit�Ĺؼ�������ϣ��ȷ�����͵���ʽת�����Ӷ�������ܵ����ͻ������߼�����
	explicit tabbrowser(QWidget* parent = 0);

	// tab������־
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

