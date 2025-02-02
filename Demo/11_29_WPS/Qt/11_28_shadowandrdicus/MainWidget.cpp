#include "MainWidget.h"
#include <QVBoxLayout>
MainWidget::MainWidget(QWidget *parent)
    : CFrameLessWidgetBase(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground,true); // 设置窗口透明

    m_pMainVLay = new QVBoxLayout(this);
    m_pTopWidget = new CTopWidget(this);
    m_pMainVLay->addWidget(m_pTopWidget);

    int shadow_width = 30;

    m_pMainVLay->setContentsMargins(shadow_width, shadow_width, shadow_width, shadow_width);
    setLayout(m_pMainVLay);

    // 给顶层widget设置背景颜色,不然看不见
    m_pTopWidget->setStyleSheet("background-color:rgb(255,254,253)");
    m_pShadow = new QGraphicsDropShadowEffect(this);

    m_pShadow->setOffset(0, 0);
    m_pShadow->setColor(QColor("#006400"));

    m_pShadow->setBlurRadius(shadow_width - 5);

    m_pTopWidget->setGraphicsEffect(m_pShadow);

    connect(m_pTopWidget, &CTopWidget::sig_close, this, &MainWidget::onClose);
    connect(m_pTopWidget, &CTopWidget::sig_max, this, &MainWidget::onDoMax);
}

MainWidget::~MainWidget()
{}

void MainWidget::onDoMax(bool isMax)
{
    int shaow_width = 25;
    if (isMax)
    {
        shaow_width = 0;
    }
    else
    {

    }
    m_pMainVLay->setContentsMargins(shaow_width, shaow_width, shaow_width, shaow_width);

    //设置阴影区域
    m_pShadow->setBlurRadius(shaow_width);

    //给顶层QWidget设置阴影
    m_pTopWidget->setGraphicsEffect(m_pShadow);
}

void MainWidget::onClose()
{
    close();
}

