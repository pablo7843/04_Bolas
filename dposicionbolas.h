
#ifndef DPOSICIONBOLAS_H
#define DPOSICIONBOLAS_H
#include "ui_dposicionbolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include "widgetposicionbola.h"
#include "bola.h"

class DPosicionBolas : public QDialog, public Ui::DPosicionBolas {
Q_OBJECT

public:
	DPosicionBolas(QVector<Bola *> *, QWidget *parent = NULL);
	QVector<Bola *> * lasBolas;
	void inicializarPestanyas();

public slots:
	void slotBolaImagen(Bola *);
	void slotTemporizador();
	
signals:
	void senyalBolaImagen(Bola *);
};

#endif 
