/********************************************************************************
** Form generated from reading UI file 'widgetposicionbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPOSICIONBOLA_H
#define UI_WIDGETPOSICIONBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPosicionBola
{
public:
    QFrame *framePosicionBola;
    QLabel *label;
    QCheckBox *checkBox;

    void setupUi(QWidget *WidgetPosicionBola)
    {
        if (WidgetPosicionBola->objectName().isEmpty())
            WidgetPosicionBola->setObjectName(QString::fromUtf8("WidgetPosicionBola"));
        WidgetPosicionBola->resize(400, 300);
        framePosicionBola = new QFrame(WidgetPosicionBola);
        framePosicionBola->setObjectName(QString::fromUtf8("framePosicionBola"));
        framePosicionBola->setGeometry(QRect(10, 10, 231, 251));
        framePosicionBola->setFrameShape(QFrame::StyledPanel);
        framePosicionBola->setFrameShadow(QFrame::Raised);
        label = new QLabel(WidgetPosicionBola);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 30, 54, 17));
        checkBox = new QCheckBox(WidgetPosicionBola);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 70, 82, 23));

        retranslateUi(WidgetPosicionBola);

        QMetaObject::connectSlotsByName(WidgetPosicionBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetPosicionBola)
    {
        WidgetPosicionBola->setWindowTitle(QCoreApplication::translate("WidgetPosicionBola", "Form", nullptr));
        label->setText(QCoreApplication::translate("WidgetPosicionBola", "TextLabel", nullptr));
        checkBox->setText(QCoreApplication::translate("WidgetPosicionBola", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPosicionBola: public Ui_WidgetPosicionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPOSICIONBOLA_H
