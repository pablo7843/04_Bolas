
#include "dlistabolas.h"
#include <QDebug>
#include <QTimer>

DListaBolas::DListaBolas(QVector<Bola*>* bolasPasadas, QWidget *parent): QDialog(parent){
		setupUi(this);

	pbolas = bolasPasadas ;
	
	
	QTimer * temporizador;
	temporizador = new QTimer();
	temporizador->setInterval(500);
	temporizador->setSingleShot(false);
	
	temporizador->start();
	
	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotTemporizador()));	
	
}


void DListaBolas::slotEjemplo(){

}

void DListaBolas::slotTemporizador(){

	listaBolas->clear();
	for( int i=0; i< pbolas->length() ; i++) {

		QString cadena = QString("PosX = " ) + QString::number( pbolas->at(i)->posX) +
				QString(" PosY= " ) + QString::number(pbolas->at(i)->posY) +
				QString(" Vel X = " ) + QString::number( pbolas->at(i)->velX) +
				QString(" Vel Y= " ) + QString::number(pbolas->at(i)->velY);
		listaBolas->addItem(cadena);
	}	
}







