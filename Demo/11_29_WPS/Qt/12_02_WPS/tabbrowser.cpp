#include "tabbrowser.h"
#include <QDebug>  
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTabBar>
#include <QAction>

QString qss0 = "QTabBar::tab{ \
            font: 75 12pt Arial; \
            text-align:left; \
            width:184px; \
            height:32; \
            background:#FFFFFF; \
            border:2px solid #FFFFFF; \
            border-bottom-color:#FFFFFF; \
            border-top-left-radius:4px; \
            border-top-right-radius:4px; \
            padding:2px; \
            margin-top:0px; \
            margin-right:1px; \
            margin-left:1px;  \
            margin-bottom:0px;} \
        QTabBar::tab:selected{  \
            color:#333333; /*文字颜色*/  \
            background-color:#FFFFFF;} \
        QTabBar::tab:!selected{ \
            color:#B2B2B2; \
            border-color:#FFFFFF;} \
        QTabBar::scroller{width: 0px;}";

QString qss1 = "QTabBar::tab{ \
            font: 75 12pt Arial; \
            text-align:left; \
            width:184px; \
            height:32; \
            background:#FFFFFF; \
            border:2px solid #FFFFFF; \
            border-bottom-color:#FFFFFF; \
            border-top-left-radius:4px; \
            border-top-right-radius:4px; \
            padding:2px; \
            margin-top:0px; \
            margin-right:1px; \
            margin-left:1px;  \
            margin-bottom:0px;} \
        QTabBar::tab:selected{  \
            color:#333333; /*文字颜色*/  \
            background-color:#FFFFFF;} \
        QTabBar::tab:!selected{ \
            color:#B2B2B2; \
            border-color:#FFFFFF;} \
        QTabBar::scroller{width: 36px;}";

tabbrowser::tabbrowser(QWidget* parent):
    QTabWidget(parent)
{
    this->addTab(new QWidget, u8"稻壳");

    this->setUsesScrollButtons(true); // 滚动鼠标可切换tab
    this->setTabsClosable(true);
    this->setMovable(true);

    initTabWidget();
    setTabBarFlag(NORMAL);

    this->setStyleSheet(qss0);

    connect(this, &QTabWidget::tabCloseRequested, this, &tabbrowser::on_closeTab);
}

void tabbrowser::resizeEvent(QResizeEvent* event)
{
    setTabBarFlag(NORMAL);
    QTabWidget::resizeEvent(event);
}

void tabbrowser::initTabWidget()
{
    // 修改菜单策略
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QTabWidget::customContextMenuRequested, this, &tabbrowser::on_MenuShow);
    createTabMenu();

    m_pRightWidget = new CTabTitleWidget(this);
    this->setCornerWidget(m_pRightWidget, Qt::TopRightCorner);

    connect(m_pRightWidget, &CTabTitleWidget::sig_addtab, this, &tabbrowser::on_newTab);
    connect(m_pRightWidget, &CTabTitleWidget::sig_close, this, &tabbrowser::sig_close);

}

void tabbrowser::setTabBarFlag(TAB_FLAG flag)
{
    int w = this->width();

    int tabWidth = 0; // 所有的tab的宽度
    int index = this->count();

    if (flag == NEW || flag == NORMAL)
    {
        for (int i = 0; i < index; i++)
        {
            tabWidth += tabBar()->tabRect(i).width();
        }
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            tabWidth += tabBar()->tabRect(i).width();
        }
    }

    if (w > tabWidth)
    {
        m_pRightWidget->setEmptyWidgetWidth(w - tabWidth - 32 * 5 - 15);
        this->setStyleSheet(qss0);
    }
    else
    {
        //当所有tab的宽度大于整个tabWidget的宽时
        m_pRightWidget->setEmptyWidgetWidth(150);
        this->setStyleSheet(qss1);
    }
}

void tabbrowser::createTabMenu()
{
    m_pMenu = new QMenu(this);
    QAction* pAcSave = new QAction(QIcon(":/WPSDemo/resources/save.png"), u8"保存", m_pMenu);
    m_pMenu->addAction(pAcSave);

    connect(pAcSave, &QAction::triggered, [=] {
        QMessageBox::information(this, u8"提示", u8"你点击了保存");
        });

    QAction* pAcSaveAs = new QAction(QString(u8"另存为"), m_pMenu);
    m_pMenu->addAction(pAcSaveAs);

    m_pMenu->addSeparator();

    QAction* pAcShareDoc = new QAction(QIcon(":/WPSDemo/resources/share.png"), QString(u8"分享文档"), m_pMenu);
    m_pMenu->addAction(pAcShareDoc);

    QAction* pAcSendToDevice = new QAction(QString(u8"发送到设备"), m_pMenu);
    m_pMenu->addAction(pAcSendToDevice);

    m_pMenu->addSeparator();

    QAction* pAcNewName = new QAction(QString(u8"重命名"), m_pMenu);
    m_pMenu->addAction(pAcNewName);

    QAction* pAcSaveToWPSCloud = new QAction(QString(u8"保存到WPS云文档"), m_pMenu);
    m_pMenu->addAction(pAcSaveToWPSCloud);

    QAction* pAcCloseAll = new QAction(QString(u8"关闭所有文件"), m_pMenu);
    m_pMenu->addAction(pAcCloseAll);

    connect(pAcCloseAll, &QAction::triggered, this, &tabbrowser::on_closeAllTab);
}

void tabbrowser::on_newTab() 
{
    int nCount = this->count();
    QString title = QString::number(nCount);
    title = "page" + title;

    this->addTab(new QWidget, title);
    if (!tabsClosable())
    {
        setTabsClosable(true);
    }
    setTabBarFlag(NEW);
}

void tabbrowser::on_closeTab(int index)
{
    widget(index)->deleteLater();
    setTabBarFlag(CLOSE);

    if (count() == 1)
    {
        setTabsClosable(false);
        setTabBarFlag(SPECIAL);
    }
}

void tabbrowser::on_MenuShow(const QPoint& ops)
{
    int index = this->tabBar()->tabAt(ops);
#ifdef _DEBUG
    qDebug() << u8"当前tab为：" << QString::number(index);
    this->setCurrentIndex(index);
#endif // _DEBUG
    if (index != -1)
    {
        m_pMenu->exec(QCursor::pos());
    }
}

void tabbrowser::on_closeAllTab()
{
}
