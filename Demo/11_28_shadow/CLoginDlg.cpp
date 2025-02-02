#include "CLoginDlg.h"
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

CLoginDlg::CLoginDlg(QWidget* parent)
{
	
	// 设置窗体透明
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMaximizeButtonHint | Qt::Window);
	QVBoxLayout* pMainlay = new QVBoxLayout(this);
	aaa = new shadow(this);
	pMainlay->addWidget(aaa);
	setLayout(pMainlay);

	aaa->setStyleSheet("background-color:rgb(255,254,253)");

	QGraphicsDropShadowEffect* shadowa = new QGraphicsDropShadowEffect(this);

	shadowa->setOffset(0, 0); // 设置阴影距离
	shadowa->setColor(QColor("#686868")); // 设置阴影颜色 
	shadowa->setBlurRadius(30); // 设置阴影区域

	aaa->setGraphicsEffect(shadowa);
}

void CLoginDlg::mousePressEvent(QMouseEvent* event)
{
	this->windowPos = this->pos();
	this->mousePos = event->globalPosition().toPoint();
	this->dPos = mousePos - windowPos;
}

void CLoginDlg::mouseMoveEvent(QMouseEvent* event)
{
	this->move(event->globalPosition().toPoint() - this->dPos);
}
