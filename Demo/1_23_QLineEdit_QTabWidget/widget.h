#ifndef WIDGET_H
#define WIDGET_H

#include "cserachlineedit.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
private slots:
    void onSearch(const QString& text);

private:
    Ui::Widget* ui;
    CSerachLineedit* m_pLine = nullptr;
};
#endif // WIDGET_H
