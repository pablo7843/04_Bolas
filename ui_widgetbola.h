/********************************************************************************
** Form generated from reading UI file 'widgetbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QPushButton *botonParar;
    QPushButton *botonColor;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(400, 300);
        botonParar = new QPushButton(WidgetBola);
        botonParar->setObjectName(QString::fromUtf8("botonParar"));
        botonParar->setGeometry(QRect(60, 80, 80, 25));
        botonColor = new QPushButton(WidgetBola);
        botonColor->setObjectName(QString::fromUtf8("botonColor"));
        botonColor->setGeometry(QRect(60, 150, 80, 25));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QCoreApplication::translate("WidgetBola", "Form", nullptr));
        botonParar->setText(QCoreApplication::translate("WidgetBola", "Parar", nullptr));
        botonColor->setText(QCoreApplication::translate("WidgetBola", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
