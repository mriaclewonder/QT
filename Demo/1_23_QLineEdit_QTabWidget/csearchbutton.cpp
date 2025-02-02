#include "csearchbutton.h"
#include <QPixmap>
#include <string>
using namespace std;

CSearchButton::CSearchButton(QWidget* parent)
    : QPushButton(parent)
{
    this->setAttribute(Qt::WA_StyledBackground);

    this->setFixedHeight(40);

    onNormalStyle();
}

void CSearchButton::onNormalStyle()
{
    string qss = R"(QPushButton{
            background-color:#148AFF;
            background-image: url(:/resources/search.png);
            background-repeat: no-repeat;
            background-position: center;
            border-radius:20px;
        })";

    this->setStyleSheet(QString::fromStdString(qss));

    this->setFixedWidth(60);
    this->setText(u8"");
}

void CSearchButton::enterEvent(QEvent* event)
{
    string qss = R"(QPushButton{
            background-color:#148AFF;
            background-image: url(:/resources/search.png);
            background-repeat: no-repeat;
            background-position:left;
            background-origin:content;
            padding-left:15px; /*图片相对于左边的偏移*/
            text-align:right;  /*文本的对齐方式*/
            padding-right:15px; /*文本相对于右边的偏移*/
            border-radius:20px;
            color:#FFFFFF;
            font-family: \"Microsoft YaHei\";
            font-size: 20px;
        })";

    this->setStyleSheet(QString::fromStdString(qss));

    this->setFixedWidth(130);
    this->setText(u8"搜全网");
}

void CSearchButton::leaveEvent(QEvent* event)
{
    onNormalStyle();
}
