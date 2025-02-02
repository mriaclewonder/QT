#include "cmybutton.h"
#include <QVBoxLayout>
#include <QPixmap>

CMyButton::CMyButton(QWidget *parent)
    :QPushButton(parent)
{
    this->setFixedSize(64,88);
    this->setText("");
    QVBoxLayout* Layout = new QVBoxLayout(this);

    p_pictureLabel = new QLabel(this);
    p_pictureLabel->setFixedSize(64,64);
    p_pictureLabel->setPixmap(QPixmap(":/resources/save.png"));

    p_textLabel = new QLabel(this);
    p_textLabel->setFixedSize(64,24);
    p_textLabel->setText("保存");

    Layout->addWidget(p_pictureLabel);
    Layout->addWidget(p_textLabel);

    Layout->setContentsMargins(0,0,0,0);
}

void CMyButton::set_Text(const QString& text)
{
    p_textLabel->setText(text);
}


