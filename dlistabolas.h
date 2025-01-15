
#ifndef DLISTABOLAS_H
#define DLISTABOLAS_H
#include "ui_dlistabolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

#include "bola.h"

class DListaBolas : public QDialog, public Ui::DListaBolas {
Q_OBJECT

public:
	DListaBolas(QVector<Bola*> *bolas,QWidget *parent = NULL);
	QVector<Bola*> *pbolas;
public slots:
	void slotEjemplo();
	void slotTemporizador();

};

#endif 
