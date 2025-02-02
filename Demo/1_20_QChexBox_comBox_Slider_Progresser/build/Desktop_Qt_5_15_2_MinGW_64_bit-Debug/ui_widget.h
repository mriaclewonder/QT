/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QProgressBar *progressBar_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(793, 594);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("/* \346\234\252\344\270\213\346\213\211\346\227\266\357\274\214QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox \n"
"{\n"
"    border: 1px solid gray;   /* \350\276\271\346\241\206 */\n"
"    border-radius: 5px;   /* \345\234\206\350\247\222 */\n"
"    padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241\254 */\n"
"    color: white;\n"
"    font: normal normal 24px \"Microsoft YaHei\";\n"
"    background:rgb(54,54,54);\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView \n"
"{\n"
"    outline: 0px solid gray;   /* \351\200\211\345\256\232\351\241\271\347\232\204\350\231\232\346\241\206 */\n"
"    border: 1px solid yellow;   /* \346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\347\232\204\350\276\271\346\241\206 */\n"
"    color: rgb(250,251,252);\n"
"    background-color: rgb(70,80,90);   /* \346\225\264\344"
                        "\270\252\344\270\213\346\213\211\347\252\227\344\275\223\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    selection-background-color: lightgreen;   /* \346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\242\253\351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"/* \351\241\271\347\232\204\351\253\230\345\272\246\357\274\210\350\256\276\347\275\256pComboBox->setView(new QListView(this));\345\220\216\350\257\245\351\241\271\346\211\215\350\265\267\344\275\234\347\224\250\357\274\211 */\n"
"QComboBox QAbstractItemView::item \n"
"{\n"
"    height: 50px;   \n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347"
                        "\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:hover \n"
"{\n"
"    color: rgb(90,100,105);\n"
"    background-color: lightgreen;   /* \346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\242\253\351\200\211\346\213\251\347\232\204\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:selected \n"
"{\n"
"    color: rgb(12, 23, 34);\n"
"    background-color: lightgreen;\n"
"}\n"
"\n"
"/* QComboBox\344\270\255\347\232\204\345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 */\n"
"QComboBox QAbstractScrollArea QScrollBar:vertical \n"
"{\n"
"    width: 13px;\n"
"    background-color: #d0d2d4;   /* \347\251\272\347\231\275\345\214\272\345\237\237\347\232\204\350\203\214\346\231"
                        "\257\350\211\262*/\n"
"}\n"
"\n"
"QComboBox QAbstractScrollArea QScrollBar::handle:vertical \n"
"{\n"
"    border-radius: 5px;   /* \345\234\206\350\247\222 */\n"
"    background: rgb(60,60,60);   /* \345\260\217\346\226\271\345\235\227\347\232\204\350\203\214\346\231\257\350\211\262\346\267\261\347\201\260lightblue */\n"
"}\n"
"\n"
"QComboBox QAbstractScrollArea QScrollBar::handle:vertical:hover \n"
"{\n"
"    background: rgb(90, 91, 93);   /* \350\266\212\350\277\207\345\260\217\346\226\271\345\235\227\347\232\204\350\203\214\346\231\257\350\211\262yellow */\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\345\217\257\347\274\226\350\276\221\357\274\210setEditable(true)\357\274\211editable\346\227\266\357\274\214\347\274\226\350\276\221\345\214\272\345\237\237\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox:editable \n"
"{\n"
"    background: green;\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\351\235\236\347\274\226\350\276\221\357\274\210setEditable(false)\357\274\211!editable\346\227\266"
                        "\357\274\214\346\225\264\344\270\252QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox:!editable \n"
"{\n"
"     background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\345\217\257\347\274\226\350\276\221editable\346\227\266\357\274\214\347\202\271\345\207\273\346\225\264\344\270\252QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox:editable:on \n"
"{\n"
"    background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\351\235\236\347\274\226\350\276\221!editable\346\227\266\357\274\214\347\202\271\345\207\273\346\225\264\344\270\252QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox:!editable:on \n"
"{\n"
"     background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\345\217\257\347\274\226\350\276\221editable\346\227\266\357\274\214\344\270\213\346\213\211\346\241\206\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox::drop-down:editable \n"
"{\n"
"    background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350"
                        "\256\276\347\275\256\344\270\272\345\217\257\347\274\226\350\276\221editable\346\227\266\357\274\214\347\202\271\345\207\273\344\270\213\346\213\211\346\241\206\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox::drop-down:editable:on \n"
"{\n"
"    background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\351\235\236\347\274\226\350\276\221!editable\346\227\266\357\274\214\344\270\213\346\213\211\346\241\206\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox::drop-down:!editable \n"
"{\n"
"    background: rgb(54,54,54);\n"
"}\n"
"\n"
"/* \350\256\276\347\275\256\344\270\272\351\235\236\347\274\226\350\276\221!editable\346\227\266\357\274\214\347\202\271\345\207\273\344\270\213\346\213\211\346\241\206\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox::drop-down:!editable:on \n"
"{\n"
"    background: rgb(54,54,54);\n"
"    image: url(:/resources/up.png); /* \346\230\276\347\244\272\344\270\212\346\213\211\347\256\255\345\244\264 */ \n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\346\241"
                        "\206\346\240\267\345\274\217 */\n"
"QComboBox::drop-down \n"
"{\n"
"    subcontrol-origin: padding;   /* \345\255\220\346\216\247\344\273\266\345\234\250\347\210\266\345\205\203\347\264\240\344\270\255\347\232\204\345\216\237\347\202\271\347\237\251\345\275\242\343\200\202\345\246\202\346\236\234\346\234\252\346\214\207\345\256\232\346\255\244\345\261\236\346\200\247\357\274\214\345\210\231\351\273\230\350\256\244\344\270\272padding\343\200\202 */\n"
"    subcontrol-position: top right;   /* \344\270\213\346\213\211\346\241\206\347\232\204\344\275\215\347\275\256\357\274\210\345\217\263\344\270\212\357\274\211 */\n"
"    width: 32px;   /* \344\270\213\346\213\211\346\241\206\347\232\204\345\256\275\345\272\246 */\n"
"\n"
"    border-left-width: 1px;   /* \344\270\213\346\213\211\346\241\206\347\232\204\345\267\246\350\276\271\347\225\214\347\272\277\345\256\275\345\272\246 */\n"
"    border-left-color: darkgray;   /* \344\270\213\346\213\211\346\241\206\347\232\204\345\267\246\350\276\271\347\225\214\347\272\277"
                        "\351\242\234\350\211\262 */\n"
"    border-left-style: solid;   /* \344\270\213\346\213\211\346\241\206\347\232\204\345\267\246\350\276\271\347\225\214\347\272\277\344\270\272\345\256\236\347\272\277 */\n"
"    border-top-right-radius: 3px;   /* \344\270\213\346\213\211\346\241\206\347\232\204\345\217\263\344\270\212\350\276\271\347\225\214\347\272\277\347\232\204\345\234\206\350\247\222\345\215\212\345\276\204\357\274\210\345\272\224\345\222\214\346\225\264\344\270\252QComboBox\345\217\263\344\270\212\350\276\271\347\225\214\347\272\277\347\232\204\345\234\206\350\247\222\345\215\212\345\276\204\344\270\200\350\207\264\357\274\211 */\n"
"    border-bottom-right-radius: 3px;   /* \345\220\214\344\270\212 */\n"
"    image: url(:/resources/down.png); \n"
"}\n"
"\n"
"/* \350\266\212\350\277\207\344\270\213\346\213\211\346\241\206\346\240\267\345\274\217 */\n"
"QComboBox::drop-down:hover \n"
"{\n"
"    background: rgb(80, 75, 90);\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\347\256\255\345\244\264\346\240\267\345\274"
                        "\217 */ \n"
"QComboBox::down-arrow \n"
"{\343\200\200\343\200\200\n"
"    width: 32px; /* \344\270\213\346\213\211\347\256\255\345\244\264\347\232\204\345\256\275\345\272\246\357\274\210\345\273\272\350\256\256\344\270\216\344\270\213\346\213\211\346\241\206drop-down\347\232\204\345\256\275\345\272\246\344\270\200\350\207\264\357\274\211 */ \343\200\200\343\200\200\n"
"    background: rgb(54,54,54); /* \344\270\213\346\213\211\347\256\255\345\244\264\347\232\204\347\232\204\350\203\214\346\231\257\350\211\262 */ \343\200\200\343\200\200\n"
"    padding: 0px 0px 0px 0px; /* \344\270\212\345\206\205\350\276\271\350\267\235\343\200\201\345\217\263\345\206\205\350\276\271\350\267\235\343\200\201\344\270\213\345\206\205\350\276\271\350\267\235\343\200\201\345\267\246\345\206\205\350\276\271\350\267\235 */\343\200\200\343\200\200\n"
"    image: url(:/resources/down.png); \n"
"} \n"
"\n"
"/* \347\202\271\345\207\273\344\270\213\346\213\211\347\256\255\345\244\264 */ \n"
"QComboBox::down-arrow:on \n"
"{ \343\200\200\343"
                        "\200\200\n"
"    image: url(:/resources/up.png); /* \346\230\276\347\244\272\344\270\212\346\213\211\347\256\255\345\244\264 */ \n"
"}"));

        horizontalLayout->addWidget(comboBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setStyleSheet(QString::fromUtf8("QSlider \n"
"{\n"
"	background-color: rgba(22, 22, 22, 0.7);\n"
"	padding-top: 15px;  /*\344\270\212\351\235\242\347\253\257\347\202\271\347\246\273\351\241\266\351\203\250\347\232\204\350\267\235\347\246\273*/\n"
"	padding-bottom: 15px;\n"
"	border-radius: 5px; /*\345\244\226\350\276\271\346\241\206\347\237\251\345\275\242\345\200\222\350\247\222*/\n"
"}\n"
" \n"
"QSlider::add-page:vertical \n"
"{\n"
"	background-color: #FF7826;\n"
"	width:5px;\n"
"	border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::sub-page:vertical \n"
"{\n"
"	background-color: #7A7B79;\n"
"	width:5px;\n"
"	border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::groove:vertical \n"
"{\n"
"	background:transparent;\n"
"	width:6px;\n"
"}\n"
" \n"
"QSlider::handle:vertical    \n"
"{\n"
"	height: 14px;  \n"
"	width: 14px;\n"
"	margin: 0px -4px 0px -4px;\n"
"	border-radius: 7px;\n"
"	background: white;\n"
"}"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar\n"
"{\n"
"	border-radius:5px;\n"
"	background-color:darkgray;\n"
"	text-align:center\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"	background-color:#1F0FEF;\n"
"	width:6px;\n"
"	margin:5px;\n"
"}"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        progressBar_2 = new QProgressBar(Widget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setStyleSheet(QString::fromUtf8("QProgressBar:vertical\n"
"{\n"
"	border-radius:5px;\n"
"	background-color:darkgray;\n"
"	text-align:center;\n"
"	padding-left: 5px; padding-right: 4px; padding-bottom: 20px; \n"
"}\n"
"\n"
"QProgressBar::chunk:vertical\n"
"{\n"
"	background-color:#06B025;\n"
"	margin:10px;\n"
"}"));
        progressBar_2->setValue(24);

        gridLayout->addWidget(progressBar_2, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\347\273\210\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
