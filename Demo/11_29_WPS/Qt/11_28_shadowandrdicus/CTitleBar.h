#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>

class CTitleBar : public QWidget
{
	Q_OBJECT
public:
	CTitleBar(QWidget* parent = Q_NULLPTR);
	~CTitleBar() {}

private:
	void initUI();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;

private slots:
	void on_Clicked();

signals:
	void sig_close();
	void sig_max(bool isMax);

private:
	QLabel* m_pTitleLabel;
	QPushButton* m_pSetBtn;
	QPushButton* m_pMaxBtn;
	QPushButton* m_pMinBtn;
	QPushButton* m_pCloseBtn;
};

