#include "widget.h"
#include "ui_widget.h"
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include "qss.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(54,54,54)");
    // 主菜单
    QMenu* pMenu = new QMenu;

    // 文件菜单
    QMenu* fileMenuItems = new QMenu;
    fileMenuItems->setTitle(u8"文件");
    fileMenuItems->setIcon(QIcon(":/resources/file.png"));
    fileMenuItems->setStyleSheet(QString::fromStdString(menuItemQss));

    // 文件菜单子菜单
    QList<QAction*> acList;
    QAction* openFile = new QAction(QIcon(":/resources/file.png"),u8"打开文件",this);
    openFile->setShortcut(QKeySequence("Ctrl+8"));
    QAction* saveFile = new QAction(u8"保存文件",this);
    QAction* exitFile = new QAction(u8"退出文件",this);

    acList<< openFile << saveFile << exitFile;
    fileMenuItems->addActions(acList);

    QAction *play = new QAction(QIcon(":/resources/play.png"), u8"播放", this);
    QAction *tools = new QAction(QIcon(":/resources/tools.png"), u8"工具", this);

    // 设置副菜单
    QMenu* setMenu = new QMenu;
    setMenu->setTitle(u8"设置");
    setMenu->setIcon(QIcon(":/resources/set.png"));
    setMenu->setStyleSheet(QString::fromStdString(menuItemQss));

    QList<QAction*> setList;
    QAction* playset = new QAction(u8"播放设置",this);
    QAction* systemset = new QAction(u8"系统设置",this);
    QAction* liset = new QAction(u8"字幕设置",this);

    setList << playset << systemset << liset;
    setMenu->addActions(setList);

    QMenu* exitMenu = new QMenu;
    exitMenu->setTitle(u8"退出");
    exitMenu->setIcon(QIcon(":/resources/exit.png"));

    QAction *exit1 = new QAction(QIcon(":/resources/exit.png"), u8"退出", this);

    // 将副菜单加入到子菜单
    pMenu->addMenu(fileMenuItems);
    pMenu->addAction(play);
    pMenu->addAction(tools);
    pMenu->addSeparator();
    pMenu->addMenu(setMenu);
    pMenu->addSeparator();
    pMenu->addAction(exit1);

    ui->pushButton->setMenu(pMenu);

    ui->pushButton->setText(u8"QQ视频");
    ui->pushButton->setStyleSheet(QString::fromStdString(button_qss));
    ui->pushButton->setFixedSize(100,50);

    pMenu->setStyleSheet(QString::fromStdString(menuQss));


    connect(openFile,&QAction::triggered,[=]{
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        u8"请选择视频文件",
                                                        "D:/",
                                                        "视频(*.mp4 *.flv);;");
        if(fileName.isEmpty())
        {
            return;
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
