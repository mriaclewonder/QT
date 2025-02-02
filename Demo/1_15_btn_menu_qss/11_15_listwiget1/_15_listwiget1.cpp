#include "_15_listwiget1.h"

/*
    1.QListWidget 怎么设置菜单栏
    2.怎么把 QListWidgetItem 添加到 QListWidget
    3.设置菜单策略 setContextMenuPolicy
    4.动作 QAction
    5.删除 动作 QAction 的菜单的选项
*/


_15_listwiget1::_15_listwiget1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    QListWidgetItem* pItem1 = new QListWidgetItem(QIcon(":/_15_listwiget1/resources/editor.png"),u8"编辑");
    QListWidgetItem* pItem2 = new QListWidgetItem(QIcon(":/_15_listwiget1/resources/env.png"),u8"环境");
    QListWidgetItem* pItem3 = new QListWidgetItem(QIcon(":/_15_listwiget1/resources/help.png"),u8"帮助");
    QListWidgetItem* pItem4 = new QListWidgetItem(QIcon(":/_15_listwiget1/resources/kits.png"),"Kits");
    QListWidgetItem* pItem5 = new QListWidgetItem(QIcon(":/_15_listwiget1/resources/vim.png"),"vim");

    ui.listWidget->addItem(pItem1);
    ui.listWidget->addItem(pItem2);
    ui.listWidget->addItem(pItem3);
    ui.listWidget->addItem(pItem4);
    ui.listWidget->addItem(pItem5);

    initRightMenu();

    //设置菜单策略，必须设置，不然无法显示菜单
    ui.listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    //  连接信号槽
    connect(ui.listWidget, &QListWidget::customContextMenuRequested, this, &_15_listwiget1::on_PopupRightMenu);

}

_15_listwiget1::~_15_listwiget1()
{}

void _15_listwiget1::on_PopupRightMenu(const QPoint& pos) {
    QListWidgetItem* pItem = ui.listWidget->itemAt(pos);
    if (!pItem)
        return;
    
    p_RightMenu->exec(QCursor::pos());
}

void _15_listwiget1::initRightMenu()
{
    p_RightMenu = new QMenu(this);

    QAction* action1 = new QAction(u8"动作1", this);
    QAction* action2 = new QAction(u8"动作2", this);
    QAction* action3 = new QAction(u8"动作3", this);
    QAction* action4 = new QAction(u8"删除", this);

    p_RightMenu->addAction(action1);
    p_RightMenu->addAction(action2);
    p_RightMenu->addAction(action3);
    p_RightMenu->addAction(action4);

    connect(action1, &QAction::triggered, [=] {
        QMessageBox::information(this, "title", "ac1");
        });

    connect(action4, &QAction::triggered, [=] {
        QListWidgetItem* pItem = ui.listWidget->currentItem();
        ui.listWidget->removeItemWidget(pItem);
        delete pItem;
        });
}
