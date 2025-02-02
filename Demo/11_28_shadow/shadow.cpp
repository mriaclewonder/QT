#include "shadow.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QGridLayout>

shadow::shadow(QWidget* parent)
    : QWidget(parent)
{
    // 设置窗口属性
    setAttribute(Qt::WA_StyledBackground);
    setWindowFlags(Qt::FramelessWindowHint);

    QHBoxLayout* pMainLay = new QHBoxLayout(this);
    QSpacerItem* pHSpacer = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);

    QLabel* pImageLabel = new QLabel(this);
    QPixmap pixmap(":/shadow/resource/user_image.png");
    pImageLabel->setFixedSize(150, 150);
    pImageLabel->setPixmap(pixmap);
    pImageLabel->setScaledContents(true);

    // 用户名
    QLineEdit* pUserNameLineEdit = new QLineEdit(this);
    pUserNameLineEdit->setFixedSize(300, 50);
    pUserNameLineEdit->setPlaceholderText(QStringLiteral("QQ号码/手机/邮箱"));

    // 密码
    QLineEdit* pPasswordEdit = new QLineEdit(this);
    pPasswordEdit->setFixedSize(300, 50);
    pPasswordEdit->setPlaceholderText(QStringLiteral("密码"));
    pPasswordEdit->setEchoMode(QLineEdit::Password);

    QPushButton* pForgetBtn = new QPushButton(this);
    pForgetBtn->setText(QStringLiteral("找回密码"));
    pForgetBtn->setFixedHeight(80);

    QCheckBox* pRememberCheBox = new QCheckBox(this);
    pRememberCheBox->setText(QStringLiteral("记住密码"));

    QCheckBox* pAutoLoginCheckBox = new QCheckBox(this);
    pAutoLoginCheckBox->setText(QStringLiteral("自动登录"));

    QPushButton* pLoginBtn = new QPushButton(this);
    pLoginBtn->setFixedHeight(48);
    pLoginBtn->setText(QStringLiteral("登录"));

    QPushButton* pRegisterBtn = new QPushButton(this);
    pRegisterBtn->setFixedHeight(48);
    pRegisterBtn->setText(QStringLiteral("注册"));

    pMainLay->addSpacerItem(pHSpacer);

    QGridLayout* pGridLayout = new QGridLayout(this);

    // 头像 第0行，第0列开始，占3行1列
    pGridLayout->addWidget(pImageLabel, 0, 0, 3, 1);
    pGridLayout->addWidget(pUserNameLineEdit, 0, 1, 1, 2);
    pGridLayout->addWidget(pPasswordEdit, 1, 1, 1, 2);
    pGridLayout->addWidget(pForgetBtn, 2, 1, 1, 1);

    // 记住密码 第2行，第2列开始，占1行1列 水平居中 垂直居中
    pGridLayout->addWidget(pRememberCheBox, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
    pGridLayout->addWidget(pAutoLoginCheckBox, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignCenter);

    pGridLayout->addWidget(pLoginBtn, 3, 1, 1, 2);
    pGridLayout->addWidget(pRegisterBtn, 4, 1, 1, 2);

    pGridLayout->setHorizontalSpacing(10);
    pGridLayout->setVerticalSpacing(10);

    pMainLay->addLayout(pGridLayout);
    pMainLay->setContentsMargins(5, 5, 5, 5);

    setLayout(pMainLay);
}

shadow::~shadow()
{}
