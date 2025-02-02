#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "CTitleBar.h"
#include "CFrameLessWidgetBase.h"
#include "CTopWidget.h"

class MainWidget : public CFrameLessWidgetBase
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void onClose();
    void onDoMax(bool isMax);

private:
    QVBoxLayout* m_pMainVLay = nullptr;
    CTopWidget* m_pTopWidget = nullptr;
    QGraphicsDropShadowEffect* m_pShadow = nullptr;
};
