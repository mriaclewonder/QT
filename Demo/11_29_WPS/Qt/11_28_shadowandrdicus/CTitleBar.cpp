#include "CTitleBar.h"
#include <QHBoxLayout>
#include <QStyleOption>
#include <qt_windows.h>
CTitleBar::CTitleBar(QWidget* parent)
	:QWidget(parent)
{
	this->setAttribute(Qt::WA_DeleteOnClose); // 如果没有设置这个属性 那么close() 将和 hide() 的作用一样
	initUI();
}

void CTitleBar::initUI()
{

	this->setFixedHeight(60);  // 调整标题栏高度	

	setAttribute(Qt::WA_StyledBackground); //禁止父窗口影响子窗口样式

	//左上，右上圆角10；左下，右下圆角0
	this->setStyleSheet("QWidget{background-color:rgb(54,54,54); \
        border-top-left-radius:10px; \
        border-top-right-radius:10px; \
		border-bottom-left-radius:0px; \
		border-bottom-right-radius:0px;}");

	m_pTitleLabel = new QLabel(this);
	m_pTitleLabel->setFixedWidth(120);
	m_pTitleLabel->setText(u8"我是标题");
	m_pTitleLabel->setStyleSheet("QLabel{font-family: Microsoft YaHei; \
		font-size:18px; \
		color:#BDC8E2;background-color:rgb(54,54,54);}");

	m_pSetBtn = new QPushButton(this);
	m_pSetBtn->setFixedSize(32, 32);
	m_pSetBtn->setText("");
	m_pSetBtn->setFlat(true);
	m_pSetBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/set.png);border:none}" \
		"QPushButton:hover{" \
		"background-color:rgb(99, 99, 99);" \
		"background-image:url(:/new/prefix1/resource/titlebar/set_hover.png);border:none;}");

	m_pMinBtn = new QPushButton(this);
	m_pMinBtn->setFixedSize(32, 32);
	m_pMinBtn->setText("");
	m_pMinBtn->setFlat(true);
	m_pMinBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/min.png);border:none}" \
			"QPushButton:hover{" \
			"background-color:rgb(99, 99, 99);" \
			"background-image:url(:/new/prefix1/resource/titlebar/min_hover.png);border:none;}");

	m_pMaxBtn = new QPushButton(this);
	m_pMaxBtn->setFixedSize(35, 35);
	m_pMaxBtn->setFlat(true);
	m_pMaxBtn->setText("");
	m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/normal.png);border:none; \
		background-position:center; \
		background-repeat:no-repeat;}  \
		QPushButton:hover{ \
		background-color:rgb(99, 99, 99); \
		background-image:url(:/new/prefix1/resource/titlebar/normal_hover.png);border:none;}");

	m_pCloseBtn = new QPushButton(this);
	m_pCloseBtn->setFixedSize(32, 32);
	m_pCloseBtn->setFlat(true);
	m_pCloseBtn->setText("");
	m_pCloseBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/close.png);border:none}" \
		"QPushButton:hover{" \
		"background-color:rgb(99, 99, 99);" \
		"background-image:url(:/new/prefix1/resource/titlebar/close_hover.png);border:none;}");
	
	QHBoxLayout* pHlay = new QHBoxLayout(this);
	pHlay->addWidget(m_pTitleLabel);

	pHlay->addStretch();

	pHlay->addWidget(m_pSetBtn);
	pHlay->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

	pHlay->addWidget(m_pMinBtn);
	pHlay->addSpacerItem(new QSpacerItem(8, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

	pHlay->addWidget(m_pMaxBtn);
	pHlay->addSpacerItem(new QSpacerItem(8, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

	pHlay->addWidget(m_pCloseBtn);

	pHlay->setContentsMargins(0, 0, 0, 0);

	connect(m_pMaxBtn, SIGNAL(clicked(bool)), this, SLOT(on_Clicked()));
	connect(m_pMinBtn, SIGNAL(clicked(bool)), this, SLOT(on_Clicked()));
	connect(m_pCloseBtn, SIGNAL(clicked(bool)), this, SLOT(on_Clicked()));
}

void CTitleBar::mousePressEvent(QMouseEvent* event)
{
	// 如果捕获成功，允许窗口移动
	if (ReleaseCapture())  // 释放当前的鼠标捕获（允许鼠标事件继续传递给父窗口）
	{
		// 获取当前窗口对象
		QWidget* pWindow = this->window();

		// 检查窗口是否是顶层窗口（即独立的窗口，不是嵌套在其他窗口中的）
		if (pWindow->isWindow())
		{
			// 发送 Windows 消息，使窗口开始拖动
			// HTCAPTION 表示鼠标点击的是标题栏
			// WM_SYSCOMMAND 是一个系统命令消息，SC_MOVE 用于通知窗口开始移动
			// 该消息将由系统处理，并启动窗口的拖动功能

			SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}

	// 忽略当前的鼠标事件，确保事件不会进一步传递给其他控件
	event->ignore();
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	emit m_pMaxBtn->clicked();
}

void CTitleBar::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	QWidget::paintEvent(event);
}


void CTitleBar::on_Clicked() 
{
	QPushButton* pBtn = qobject_cast<QPushButton*>(sender());

	QWidget* pWindow = this->window();

	if (pWindow->isWindow())
	{
		if (pBtn == m_pMaxBtn)
		{
			if (pWindow->isMaximized())
			{
				pWindow->showNormal();
				m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/normal.png);border:none;  \
					background-position:center; \
					background-repeat:no-repeat;}  \
					QPushButton:hover{ \
					background-color:rgb(99, 99, 99); \
					background-image:url(:/new/prefix1/resource/titlebar/normal_hover.png);border:none;}");
				emit sig_max(false);
			}
			else
			{
				pWindow->showMaximized();
				m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resource/titlebar/max.png);border:none;  \
					background-position:center; \
					background-repeat:no-repeat;}  \
					QPushButton:hover{ \
					background-color:rgb(99, 99, 99);  \
					background-image:url(:/new/prefix1/resource/titlebar/max_hover.png);border:none;}");
				emit sig_max(true);
			}
		}
		else if (pBtn == m_pMinBtn)
		{
			pWindow->showMinimized();
		}
		else if (pBtn == m_pCloseBtn)
		{
			emit sig_close();
		}
	}
}
