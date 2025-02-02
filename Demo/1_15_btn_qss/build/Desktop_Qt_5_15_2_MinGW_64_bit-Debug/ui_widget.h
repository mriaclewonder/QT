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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 80, 221, 91));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{  \n"
"    /* \345\211\215\346\231\257\350\211\262 */  \n"
"    color:green;  \n"
" \n"
"    /* \350\203\214\346\231\257\350\211\262 */  \n"
"    background-color:rgb(223,223,223);  \n"
" \n"
"    /* \350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:outset;  \n"
" \n"
"    /* \350\276\271\346\241\206\345\256\275\345\272\246 */  \n"
"    border-width:0.5px;  \n"
" \n"
"    /* \350\276\271\346\241\206\351\242\234\350\211\262 */  \n"
"    border-color:rgb(10,45,110);  \n"
" \n"
"    /* \350\276\271\346\241\206\345\200\222\350\247\222 */  \n"
"    border-radius:10px;  \n"
" \n"
"    /* \345\255\227\344\275\223 */  \n"
"    font:bold 22px;  \n"
" \n"
"    /* \346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246 */  \n"
"    min-width:100px;  \n"
" \n"
"    /* \346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246 */  \n"
"    min-height:20px;  \n"
" \n"
"    /* \345\206\205\350\276\271\350\267\235 */  \n"
"    padding:4px;  \n"
"} \n"
" "
                        "\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\347\232\204\346\225\210\346\236\234 */ \n"
"QPushButton#pushButton:pressed \n"
"{  \n"
"    /* \346\224\271\345\217\230\350\203\214\346\231\257\350\211\262 */  \n"
"    background-color:rgb(40,85,20);  \n"
" \n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
" \n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:6px;  \n"
"    padding-top:6px;  \n"
"}\n"
" \n"
"/* \346\214\211\351\222\256\346\240\267\345\274\217 */ \n"
"QPushButton:flat \n"
"{  \n"
"    border:2px solid red;  \n"
"} \n"
" \n"
"/*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\347\232\204\346\225\210\346\236\234*/\n"
"QPushButton:hover\n"
"{\n"
"    color:#0000ff;\n"
"    background-color:rgb(210, 205, 205); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:inset;/*\346\224\271"
                        "\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    padding-left:8px;\n"
"    padding-top:8px;\n"
"}"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 300, 151, 51));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 220, 101, 81));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-image:url(\":/resources/vip_yes.png\");\n"
"	background-position:center;\n"
"	background-repeat: no-repeat;\n"
"	border:none\n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(10,210,210);\n"
"	background-image:url(\":/resources/vip_yes.png\");\n"
"}\n"
" \n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(255, 0, 0);\n"
"	background-image:url(\":/resources/vip_yes.png\");\n"
"}\n"
""));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 470, 80, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\344\274\232\345\221\230", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
