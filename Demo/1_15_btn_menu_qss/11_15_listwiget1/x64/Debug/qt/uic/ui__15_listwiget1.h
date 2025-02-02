/********************************************************************************
** Form generated from reading UI file '_15_listwiget1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__15_LISTWIGET1_H
#define UI__15_LISTWIGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__15_listwiget1Class
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *_15_listwiget1Class)
    {
        if (_15_listwiget1Class->objectName().isEmpty())
            _15_listwiget1Class->setObjectName("_15_listwiget1Class");
        _15_listwiget1Class->resize(766, 755);
        listWidget = new QListWidget(_15_listwiget1Class);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(230, 160, 271, 361));

        retranslateUi(_15_listwiget1Class);

        QMetaObject::connectSlotsByName(_15_listwiget1Class);
    } // setupUi

    void retranslateUi(QWidget *_15_listwiget1Class)
    {
        _15_listwiget1Class->setWindowTitle(QCoreApplication::translate("_15_listwiget1Class", "_15_listwiget1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _15_listwiget1Class: public Ui__15_listwiget1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__15_LISTWIGET1_H
