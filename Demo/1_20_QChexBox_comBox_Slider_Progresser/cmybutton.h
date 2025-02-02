#ifndef CMYBUTTON_H
#define CMYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
class CMyButton : public QPushButton
{
    Q_OBJECT
public:
    CMyButton(QWidget *parent = nullptr);
    void set_Text(const QString& text);
private:
    QLabel* p_pictureLabel = nullptr;
    QLabel* p_textLabel = nullptr;


};

#endif // CMYBUTTON_H
