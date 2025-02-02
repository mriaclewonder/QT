#ifndef CSEARCHBUTTON_H
#define CSEARCHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

class CSearchButton : public QPushButton {
    Q_OBJECT
public:
    CSearchButton(QWidget* parent = nullptr);

    void onNormalStyle();

protected:
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
};

#endif // CSEARCHBUTTON_H
