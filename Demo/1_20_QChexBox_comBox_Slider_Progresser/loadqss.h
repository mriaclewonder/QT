#ifndef LOADQSS_H
#define LOADQSS_H

#include <QWidget>

namespace Ui {
class LoadQss;
}

class LoadQss : public QWidget
{
    Q_OBJECT

public:
    explicit LoadQss(QWidget *parent = nullptr);
    ~LoadQss();

private:
    Ui::LoadQss *ui;
};

#endif // LOADQSS_H
