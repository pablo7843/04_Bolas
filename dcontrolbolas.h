
#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H
#include "ui_dcontrolbolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include "widgetbola.h"
#include "bola.h"

class DControlBolas : public QDialog, public Ui::DControlBolas {
Q_OBJECT

public:
	DControlBolas(QVector<Bola *> *,QWidget *parent = NULL);
	QVector<Bola *> * lasBolas;
	void inicializarPestanyas();

public slots:
	void slotEjemplo();
	void slotBolaMuerta(int);

};

#endif 
