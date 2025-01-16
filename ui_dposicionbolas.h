/********************************************************************************
** Form generated from reading UI file 'dposicionbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPOSICIONBOLAS_H
#define UI_DPOSICIONBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DPosicionBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabBolas;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *DPosicionBolas)
    {
        if (DPosicionBolas->objectName().isEmpty())
            DPosicionBolas->setObjectName(QString::fromUtf8("DPosicionBolas"));
        DPosicionBolas->resize(604, 425);
        buttonBox = new QDialogButtonBox(DPosicionBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabBolas = new QTabWidget(DPosicionBolas);
        tabBolas->setObjectName(QString::fromUtf8("tabBolas"));
        tabBolas->setGeometry(QRect(10, 20, 581, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabBolas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabBolas->addTab(tab_2, QString());

        retranslateUi(DPosicionBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DPosicionBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DPosicionBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DPosicionBolas);
    } // setupUi

    void retranslateUi(QDialog *DPosicionBolas)
    {
        DPosicionBolas->setWindowTitle(QCoreApplication::translate("DPosicionBolas", "Dialog", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab), QCoreApplication::translate("DPosicionBolas", "Tab 1", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab_2), QCoreApplication::translate("DPosicionBolas", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPosicionBolas: public Ui_DPosicionBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPOSICIONBOLAS_H
