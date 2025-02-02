#ifndef CSERACHLINEEDIT_H
#define CSERACHLINEEDIT_H

#include "csearchbutton.h"
#include <QLineEdit>
#include <QObject>
#include <QWidget>

class CSerachLineedit : public QLineEdit {
    Q_OBJECT
public:
    explicit CSerachLineedit(QWidget* parent = nullptr);

private:
    CSearchButton* m_pBtn = nullptr;

signals:
    void sig_Search(const QString& text);
};

#endif // CSERACHLINEEDIT_H
