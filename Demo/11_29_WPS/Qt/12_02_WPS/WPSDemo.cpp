#include "WPSDemo.h"
#include "tabbrowser.h"
#include <QHBoxLayout>

#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windows.h>
#include <windowsx.h>
#endif

#pragma comment(lib, "user32.lib")
#pragma comment(lib,"dwmapi.lib")

WPSDemo::WPSDemo(QWidget *parent)
    : QWidget(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setStyleSheet("background-color:#E3E4E7");

	tabbrowser* pTab = new tabbrowser(this);

	QHBoxLayout* pHLay = new QHBoxLayout(this);
	pHLay->addWidget(pTab);
	pHLay->setContentsMargins(6, 6, 6, 6);
	setLayout(pHLay);

	connect(pTab, &tabbrowser::sig_close, this, &WPSDemo::on_close);
}

WPSDemo::~WPSDemo()
{}


void WPSDemo::on_close() 
{
}

bool WPSDemo::nativeEvent(const QByteArray & eventType, void* message, qintptr * result)
{
	// Q_UNUSED(eventType)
	MSG* param = static_cast<MSG*>(message);

	switch (param->message)
	{
	case WM_NCHITTEST:
	{
		int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
		int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

		// 如果鼠标位于子控件上，则不进行处理
		if (childAt(nX, nY) != nullptr)
			return QWidget::nativeEvent(eventType, message, result);

		// 鼠标区域位于窗体边框，进行缩放
		if ((nX > 0) && (nX < m_BorderWidth))
			*result = HTLEFT;

		if ((nX > this->width() - m_BorderWidth) && (nX < this->width()))
			*result = HTRIGHT;

		if ((nY > 0) && (nY < m_BorderWidth))
			*result = HTTOP;

		if ((nY > this->height() - m_BorderWidth) && (nY < this->height()))
			*result = HTBOTTOM;

		if ((nX > 0) && (nX < m_BorderWidth) && (nY > 0)
			&& (nY < m_BorderWidth))
			*result = HTTOPLEFT;

		if ((nX > this->width() - m_BorderWidth) && (nX < this->width())
			&& (nY > 0) && (nY < m_BorderWidth))
			*result = HTTOPRIGHT;

		if ((nX > 0) && (nX < m_BorderWidth)
			&& (nY > this->height() - m_BorderWidth) && (nY < this->height()))
			*result = HTBOTTOMLEFT;

		if ((nX > this->width() - m_BorderWidth) && (nX < this->width())
			&& (nY > this->height() - m_BorderWidth) && (nY < this->height()))
			*result = HTBOTTOMRIGHT;

		return true;
	}
	}

	return QWidget::nativeEvent(eventType, message, result);
}
