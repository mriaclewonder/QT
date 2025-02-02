#pragma once
#include <QDialog>
#include <QWidget>
#include <QMouseEvent>
#include "shadow.h"

class CLoginDlg:public QDialog
{
	Q_OBJECT
public:
	CLoginDlg(QWidget* parent = Q_NULLPTR);
	~CLoginDlg() {}

private:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

private:
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;

private:
	shadow* aaa = nullptr;
};

