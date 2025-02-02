#include "CTitleBar.h"
#include <QHBoxLayout>

#pragma comment(lib, "user32.lib")
#include <qt_windows.h>

CTitleBar::CTitleBar(QWidget* p):
	QWidget(p)
{
	this->setAttribute(Qt::WA_DeleteOnClose);
	initUI();
}

CTitleBar::~CTitleBar()
{
}

void CTitleBar::initUI()
{
    setAttribute(Qt::WA_StyledBackground);
    this->setFixedHeight(40);  // 调整标题栏高度
    this->setStyleSheet("background-color:rgb(50,50,50);border-bottom:2px solid rgb(80,80,80);");

    // Logo
    m_plogo = new QLabel(this);
    m_plogo->setFixedSize(32, 32);
    m_plogo->setStyleSheet("background-image:url(:/new/prefix1/resources/titlebar/title_icon.png);border:none;");

    // 标题文本
    pTextTitleLabel = new QLabel(this);
    pTextTitleLabel->setText(u8"我是标题");
    pTextTitleLabel->setFixedWidth(120);
    pTextTitleLabel->setStyleSheet("QLabel{font-family: Microsoft YaHei; \
                                    font-size:18px; \
                                    color:#BDC8E2; \
                                    background-color:transparent;}");

    // 设置按钮
    m_pSetBtn = new QPushButton(this);
    m_pSetBtn->setFixedSize(32, 32);
    m_pSetBtn->setStyleSheet(
        "QPushButton{background-image:url(:/new/prefix1/resources/titlebar/set.png);border:none;} \
         QPushButton:hover{background-color:rgb(80, 80, 80); \
         background-image:url(:/new/prefix1/resources/titlebar/set_hover.png);border:none;}");

    // 最小化按钮
    m_pMinBtn = new QPushButton(this);
    m_pMinBtn->setFixedSize(32, 32);
    m_pMinBtn->setStyleSheet(
        "QPushButton{background-image:url(:/new/prefix1/resources/titlebar/min.png);border:none;} \
         QPushButton:hover{background-color:rgb(80, 80, 80); \
         background-image:url(:/new/prefix1/resources/titlebar/min_hover.png);border:none;}");

    // 最大化按钮
    m_pMaxBtn = new QPushButton(this);
    m_pMaxBtn->setFixedSize(32, 32);
    m_pMaxBtn->setStyleSheet(
        "QPushButton{background-image:url(:/new/prefix1/resources/titlebar/normal.png);border:none;} \
         QPushButton:hover{background-color:rgb(80, 80, 80); \
         background-image:url(:/new/prefix1/resources/titlebar/normal_hover.png);border:none;}");

    // 关闭按钮
    m_pCloseBtn = new QPushButton(this);
    m_pCloseBtn->setFixedSize(32, 32);
    m_pCloseBtn->setStyleSheet(
        "QPushButton{background-image:url(:/new/prefix1/resources/titlebar/close.png);border:none;} \
         QPushButton:hover{background-color:rgb(255, 0, 0); \
         background-image:url(:/new/prefix1/resources/titlebar/close_hover.png);border:none;}");

    // 布局
    QHBoxLayout* pHlay = new QHBoxLayout(this);
    pHlay->addWidget(m_plogo);
    pHlay->addWidget(pTextTitleLabel);
    pHlay->addStretch();

    pHlay->addWidget(m_pSetBtn);
    pHlay->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

    pHlay->addWidget(m_pMinBtn);
    pHlay->addSpacerItem(new QSpacerItem(8, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

    pHlay->addWidget(m_pMaxBtn);
    pHlay->addSpacerItem(new QSpacerItem(8, 10, QSizePolicy::Fixed, QSizePolicy::Fixed));

    pHlay->addWidget(m_pCloseBtn);

    pHlay->setContentsMargins(5, 5, 5, 5);

    connect(m_pMinBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
    connect(m_pMaxBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
    connect(m_pCloseBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
}

void CTitleBar::mousePressEvent(QMouseEvent* event)
{
	if (ReleaseCapture())
	{
		QWidget* pWindow = this->window();
		if (pWindow->isWindow())
		{
			SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	emit m_pMaxBtn->clicked();
}


void CTitleBar::onClicked() 
{
	QPushButton* pButtton = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();

	if (pButtton == m_pMinBtn)
	{
		pWindow->showMinimized();
	}
	else if (pButtton == m_pMaxBtn)
	{
		if (pWindow->isMaximized())
		{
			pWindow->showNormal();
			pWindow->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resources/titlebar/normal.png);border:none}"
				"QPushButton:hover{"
				"background-color:rgb(99, 99, 99);"
				"background-image:url(:/new/prefix1/resources/titlebar/normal_hover.png);border:none;}");
		}
		else {
			pWindow->showMaximized();
			m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/new/prefix1/resources/titlebar/max.png);border:none}"
				"QPushButton:hover{"
				"background-color:rgb(99, 99, 99);"
				"background-image:url(:/new/prefix1/resources/titlebar/max_hover.png);border:none;}");
		}
	}
	else if (pButtton == m_pCloseBtn)
	{
		emit sig_close();
	}

}