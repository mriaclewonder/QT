#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "tabbar.h"
#include <QObject>
#include <QTabWidget>
#include <QWidget>
class TabWidget : public QTabWidget {
    Q_OBJECT
public:
    TabWidget(QWidget* parent = nullptr);
};

#endif // TABWIDGET_H
