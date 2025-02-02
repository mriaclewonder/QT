#pragma once

#include <QtWidgets/QWidget>
#include <QListWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QStringList>
#include <string>
#include <QString>
#include <QScrollBar>
#include "CBaseSetWidget.h"
#include "GaojiSetWidget.h"

#include <vector>

using namespace std;

class _16_XunleiDemo : public QWidget
{
    Q_OBJECT

public:
    _16_XunleiDemo(QWidget *parent = nullptr);
    ~_16_XunleiDemo();

private slots:
    void slotItemClicked(QListWidgetItem* item);
    void slotValueChanged(int value);

private:
    QListWidget* m_pListWidget = nullptr;
    QScrollArea* m_pScrollArea = nullptr;

    QStringList textList;

    CBaseSetWidget* m_pBaseSetWidget;
    QWidget* m_pYunpanSetWidget;
    QWidget* m_pDownloadWidget;
    QWidget* m_pJieguanWidget;
    QWidget* m_pRenwuWidget;
    QWidget* m_pTixingWidget;
    QWidget* m_pXuanfuWidget;
    GaojiSetWidget* m_pGaojiWidget;

    vector<QWidget*> m_vecWidget;

    bool signFlag = false;
};
