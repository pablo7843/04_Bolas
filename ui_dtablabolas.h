/********************************************************************************
** Form generated from reading UI file 'dtablabolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLABOLAS_H
#define UI_DTABLABOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DTablaBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *vista;

    void setupUi(QDialog *DTablaBolas)
    {
        if (DTablaBolas->objectName().isEmpty())
            DTablaBolas->setObjectName(QString::fromUtf8("DTablaBolas"));
        DTablaBolas->resize(844, 674);
        buttonBox = new QDialogButtonBox(DTablaBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(440, 610, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        vista = new QTableView(DTablaBolas);
        vista->setObjectName(QString::fromUtf8("vista"));
        vista->setGeometry(QRect(10, 10, 801, 591));

        retranslateUi(DTablaBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaBolas);
    } // setupUi

    void retranslateUi(QDialog *DTablaBolas)
    {
        DTablaBolas->setWindowTitle(QCoreApplication::translate("DTablaBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaBolas: public Ui_DTablaBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLABOLAS_H
