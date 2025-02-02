#include "CTopWidget.h"
#include <QVBoxLayout>
#include "CTitleBar.h"

CTopWidget::CTopWidget(QWidget* parent)
	:QWidget(parent)
{
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	setAttribute(Qt::WA_StyledBackground);   // 表明使用 setStyleSheet 里面的样式
	this->setStyleSheet("QWidget{background-color:rgb(255,254,253);border-ridius:10px;}");

	QVBoxLayout* pVlay = new QVBoxLayout(this);

	CTitleBar* cTitleBar = new CTitleBar(this);
	QWidget* pWidget = new QWidget(this);
	
	pWidget->setMinimumSize(600, 400);
	pVlay->addWidget(cTitleBar);
	pVlay->addWidget(pWidget);

	pVlay->setContentsMargins(0, 0, 0, 0);

	setLayout(pVlay);

	connect(cTitleBar, &CTitleBar::sig_close, this, &CTopWidget::sig_close);
	connect(cTitleBar, &CTitleBar::sig_max, this, &CTopWidget::sig_max);
}

CTopWidget::~CTopWidget()
{
}
