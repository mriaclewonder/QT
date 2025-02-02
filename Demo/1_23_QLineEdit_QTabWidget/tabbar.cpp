#include "tabbar.h"
#include <QStyleOptionTab>
#include <QStylePainter>
TabBar::TabBar(QWidget* parent)
    : QTabBar(parent)
{
}

QSize TabBar::tabSizeHint(int index) const
{
    QSize s = QTabBar::tabSizeHint(index);
    s.transpose();

    // 设置每个tabBar中item的大小
    // 注意在qss QTabBar::tab里不能设置tab的大小，否则自定义的TabBar无效
    s.rwidth() = 90;
    s.rheight() = 44;
    return s;
}

void TabBar::paintEvent(QPaintEvent* event)
{
    QStylePainter painter(this);
    QStyleOptionTab opt;

    for (int i = 0; i < count(); i++) {
        initStyleOption(&opt, i);
        painter.drawControl(QStyle::CE_TabBarTabShape, opt);
        painter.save();

        QSize s = opt.rect.size();
        s.transpose();
        QRect r(QPoint(), s);
        r.moveCenter(opt.rect.center());
        opt.rect = r;

        QPoint c = tabRect(i).center();
        painter.translate(c);
        painter.rotate(90);
        painter.translate(-c);
        painter.drawControl(QStyle::CE_TabBarTabLabel, opt);
        painter.restore();
    }
}
