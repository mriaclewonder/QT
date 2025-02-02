/********************************************************************************
** Form generated from reading UI file 'loadqss.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADQSS_H
#define UI_LOADQSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadQss
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *LoadQss)
    {
        if (LoadQss->objectName().isEmpty())
            LoadQss->setObjectName(QString::fromUtf8("LoadQss"));
        LoadQss->resize(643, 468);
        gridLayout = new QGridLayout(LoadQss);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(LoadQss);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(LoadQss);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(LoadQss);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(LoadQss);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        pushButton_2 = new QPushButton(LoadQss);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(LoadQss);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        calendarWidget = new QCalendarWidget(LoadQss);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        horizontalLayout->addWidget(calendarWidget);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(LoadQss);

        QMetaObject::connectSlotsByName(LoadQss);
    } // setupUi

    void retranslateUi(QWidget *LoadQss)
    {
        LoadQss->setWindowTitle(QCoreApplication::translate("LoadQss", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoadQss", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("LoadQss", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoadQss", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoadQss", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadQss: public Ui_LoadQss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADQSS_H
