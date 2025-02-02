#pragma once
#include <QWidget>
#include <QPushButton>

class CTabTitleWidget:public QWidget
{
	 Q_OBJECT

public:
	CTabTitleWidget(QWidget* parent = nullptr);
	~CTabTitleWidget();

	void setEmptyWidgetWidth(int w);

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;

signals:
	void sig_close();
	void sig_addtab();

private slots:
	void on_Clicked();

private:
	QPushButton* m_pAddBtn = nullptr;
	QWidget* m_pEmptyWidget = nullptr;
	QPushButton* m_pUserBtn = nullptr;
	QPushButton* m_pMinBtn = nullptr;
	QPushButton* m_pMaxBtn = nullptr;
	QPushButton* m_pCloseBtn = nullptr;
};

