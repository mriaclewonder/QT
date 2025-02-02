#include "CTabTitleWidget.h"
#include <qt_windows.h>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
CTabTitleWidget::CTabTitleWidget(QWidget* parent)
	: QWidget(parent)
{
	setStyleSheet("background-color:#E3E4E7");

	m_pAddBtn = new QPushButton(this);
	m_pAddBtn->setFlat(true);
	m_pAddBtn->setFixedSize(32, 32);
	m_pAddBtn->setStyleSheet("background-image:url(:/WPSDemo/resources/add.png)");

	m_pEmptyWidget = new QWidget(this);

	m_pUserBtn = new QPushButton(this);
	m_pUserBtn->setFlat(true);
	m_pUserBtn->setFixedSize(32, 32);
	m_pUserBtn->setStyleSheet("background-image:url(:/WPSDemo/resources/user.png)");

	m_pMinBtn = new QPushButton(this);
	m_pMinBtn->setFlat(true);
	m_pMinBtn->setFixedSize(32, 32);
	m_pMinBtn->setStyleSheet("background-image:url(:/WPSDemo/resources/min.png)");


	m_pMaxBtn  = new QPushButton(this);
	m_pMaxBtn ->setFlat(true);
	m_pMaxBtn ->setFixedSize(32, 32);
	m_pMaxBtn ->setStyleSheet("background-image:url(:/WPSDemo/resources/max.png)");

	m_pCloseBtn = new QPushButton(this);
	m_pCloseBtn->setFlat(true);
	m_pCloseBtn->setFixedSize(32, 32);
	m_pCloseBtn->setStyleSheet("background-image:url(:/WPSDemo/resources/close.png)");

	QHBoxLayout* pHLay = new  QHBoxLayout(this);
	pHLay->addWidget(m_pAddBtn);
	pHLay->addWidget(m_pEmptyWidget);
	this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
	pHLay->addWidget(m_pUserBtn);
	pHLay->addSpacing(8);
	pHLay->addWidget(m_pMinBtn);
	pHLay->addWidget(m_pMaxBtn);
	pHLay->addWidget(m_pCloseBtn);
	pHLay->setContentsMargins(1, 0, 1, 3);
	setLayout(pHLay);
	
	connect(m_pAddBtn, &QPushButton::clicked, this, &CTabTitleWidget::on_Clicked);
	connect(m_pMinBtn, &QPushButton::clicked, this, &CTabTitleWidget::on_Clicked);
	connect(m_pMaxBtn, &QPushButton::clicked, this, &CTabTitleWidget::on_Clicked);
	connect(m_pCloseBtn, &QPushButton::clicked, this, &CTabTitleWidget::on_Clicked);
}

CTabTitleWidget::~CTabTitleWidget()
{
}

void CTabTitleWidget::setEmptyWidgetWidth(int w)
{
	m_pEmptyWidget->setMinimumWidth(w);
}

void CTabTitleWidget::mousePressEvent(QMouseEvent* event)
{
	if (ReleaseCapture)
	{
		QWidget* pWidget = this->window();
		if (pWidget->isWindow())
		{
			SendMessage(HWND(pWidget->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();
}

void CTabTitleWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	emit m_pMaxBtn->clicked();
}

void CTabTitleWidget::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	QWidget::paintEvent(event);
}

void CTabTitleWidget::on_Clicked() 
{
	QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();
	if (pWindow->isWindow())
	{
		if (pBtn == m_pAddBtn)
		{
			emit sig_addtab();
		}
		else if (pBtn == m_pMinBtn)
		{
			pWindow->showMinimized();
		}
		else if (pBtn == m_pMaxBtn)
		{
			pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
		}
		else if (pBtn == m_pCloseBtn)
		{
			emit sig_close();
		}
	}
}