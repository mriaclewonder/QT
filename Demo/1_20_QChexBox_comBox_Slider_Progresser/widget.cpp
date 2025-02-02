#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListView>
#include "qss.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->checkBox->setFixedSize(128,64);

    QString qss = "QCheckBox::indicator:unchecked{ \
    image:url(:/resources/status_close.png); \
    } \
    QCheckBox::indicator:checked { \
    image: url(:/resources/status_open.png); \
    }";

    ui->checkBox->setStyleSheet(qss);
    ui->checkBox->setChecked(true);

    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    // QComBox
    QStringList stringlist;
    stringlist << "item1" << "item2" << "item3" << "item4"
            << "item1" << "item2" << "item3" << "item4"
            << "item1" << "item2" << "item3" << "item4"
            << "item1" << "item2" << "item3" << "item4";
    ui->comboBox->addItems(stringlist);
    ui->comboBox->setView(new QListView(this));
    ui->comboBox->insertSeparator(10);


    // QProgresser
    p_Timer = new QTimer();
    p_Timer->setInterval(1000);

    ui->progressBar->setRange(0,100);
    ui->progressBar->setOrientation(Qt::Vertical);
    ui->progressBar->setFormat("%p%");
    ui->progressBar->setValue(0);


    connect(p_Timer,&QTimer::timeout,[=]{
        static int step = 0;
        ui->progressBar->setValue(step++);
    });

    // QSlider
    ui->horizontalSlider->setStyleSheet(QString::fromStdString(hslider_qss));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // start
    p_Timer->start(50);
}


void Widget::on_pushButton_2_clicked()
{
    // end
    p_Timer->stop();
}

