#include "MainWidget.h"
#include <QMessageBox>
#include <QVBoxLayout>
MainWidget::MainWidget(QWidget* parent)
	: CFrameLessWidgetBase(parent)
{
	initUI();
}

void MainWidget::on_closeSolt()
{
    QMessageBox::StandardButton _exit = QMessageBox::warning(this, u8"提示", u8"确定要退出吗");
    if (_exit == QMessageBox::Ok)
    {
        this->close();
    }
}


void MainWidget::initUI()
{
    ctitleBar = new CTitleBar(this);

    QWidget* w = new QWidget(this);
    w->setMinimumSize(800, 600);

    QVBoxLayout* pVlay = new QVBoxLayout(this);
    pVlay->addWidget(ctitleBar);
    pVlay->addWidget(w);

    pVlay->setContentsMargins(0, 0, 0, 0);
    setLayout(pVlay);

    connect(ctitleBar, &CTitleBar::sig_close, this, &MainWidget::on_closeSolt);
}
