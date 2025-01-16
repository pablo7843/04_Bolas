/********************************************************************************
** Form generated from reading UI file 'dcontrolbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONTROLBOLAS_H
#define UI_DCONTROLBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DControlBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *bPararTodas;

    void setupUi(QDialog *DControlBolas)
    {
        if (DControlBolas->objectName().isEmpty())
            DControlBolas->setObjectName(QString::fromUtf8("DControlBolas"));
        DControlBolas->resize(570, 392);
        buttonBox = new QDialogButtonBox(DControlBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(DControlBolas);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(60, 50, 441, 241));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        bPararTodas = new QPushButton(DControlBolas);
        bPararTodas->setObjectName(QString::fromUtf8("bPararTodas"));
        bPararTodas->setGeometry(QRect(60, 330, 121, 25));

        retranslateUi(DControlBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DControlBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DControlBolas, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DControlBolas);
    } // setupUi

    void retranslateUi(QDialog *DControlBolas)
    {
        DControlBolas->setWindowTitle(QCoreApplication::translate("DControlBolas", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DControlBolas", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DControlBolas", "Tab 2", nullptr));
        bPararTodas->setText(QCoreApplication::translate("DControlBolas", "Parar todas ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DControlBolas: public Ui_DControlBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONTROLBOLAS_H
