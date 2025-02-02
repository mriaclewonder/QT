#include "cserachlineedit.h"
#include <QHBoxLayout>
#include <string>
using namespace std;

CSerachLineedit::CSerachLineedit(QWidget* parent)
    : QLineEdit(parent)
{
    QHBoxLayout* pHLay = new QHBoxLayout(this);
    m_pBtn = new CSearchButton(this);

    this->setAttribute(Qt::WA_StyledBackground);

    string qss = R"(
            QLineEdit{
                background-color:#33373E;     /* 背景颜色 */
                border: 1px solid #33373E;      /* 边框宽度为1px，颜色为#A0A0A0 */
                border-radius: 20px;         /* 边框圆角 */
                padding-left: 10px;           /* 文本距离左边界有5px */
                color: #FFFFFF;     /* 文本颜色 */
                selection-background-color: #A0A0A0;     /* 选中文本的背景颜色 */
                selection-color: #F2F2F2;    /* 选中文本的颜色 */
                font-family: \"Microsoft YaHei\";    /* 文本字体族 */
                font-size:18px;    /* 文本字体大小 */
            }
        )";

    this->setFixedHeight(40);
    this->setMinimumWidth(400);

    this->setStyleSheet(QString::fromStdString(qss));
    this->setPlaceholderText(u8"请输入搜素内容");

    pHLay->addStretch();
    pHLay->addWidget(m_pBtn);

    pHLay->setContentsMargins(0, 0, 0, 0);

    this->setTextMargins(10, 0, 130 + 5, 0);

    connect(m_pBtn, &QPushButton::clicked, this, [=] {
        emit sig_Search(this->text());
    });
}
