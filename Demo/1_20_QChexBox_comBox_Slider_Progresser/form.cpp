#include "form.h"
#include "ui_form.h"
#include "cmybutton.h"
Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->pushButton->setText("");
    ui->pushButton->setFixedSize(64, 88);
    connect(ui->pushButton_2,&QPushButton::clicked,[=]{
        ui->pushButton->set_Text(u8"不保存");
    });
}

Form::~Form()
{
    delete ui;
}
