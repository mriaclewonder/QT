#pragma once

#include <QtWidgets/QWidget>
#include "ui__15_listwiget1.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
class _15_listwiget1 : public QWidget
{
    Q_OBJECT

public:
    _15_listwiget1(QWidget *parent = nullptr);
    ~_15_listwiget1();

private slots:
    void on_PopupRightMenu(const QPoint& pos);

private:
    void initRightMenu();

private:
    Ui::_15_listwiget1Class ui;
    QMenu* p_RightMenu = nullptr;
};
