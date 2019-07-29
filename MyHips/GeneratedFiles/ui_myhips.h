/********************************************************************************
** Form generated from reading UI file 'myhips.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYHIPS_H
#define UI_MYHIPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyHipsClass
{
public:

    void setupUi(QWidget *MyHipsClass)
    {
        if (MyHipsClass->objectName().isEmpty())
            MyHipsClass->setObjectName(QString::fromUtf8("MyHipsClass"));
        MyHipsClass->resize(600, 400);

        retranslateUi(MyHipsClass);

        QMetaObject::connectSlotsByName(MyHipsClass);
    } // setupUi

    void retranslateUi(QWidget *MyHipsClass)
    {
        MyHipsClass->setWindowTitle(QCoreApplication::translate("MyHipsClass", "MyHips", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyHipsClass: public Ui_MyHipsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYHIPS_H
