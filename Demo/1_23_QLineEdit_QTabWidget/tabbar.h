#ifndef TABBAR_H
#define TABBAR_H

#include <QObject>
#include <QTabBar>
#include <QWidget>

class TabBar : public QTabBar {
    Q_OBJECT
public:
    TabBar(QWidget* parent = nullptr);
    QSize tabSizeHint(int index) const override;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // TABBAR_H
