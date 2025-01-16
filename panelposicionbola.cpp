#include "panelposicionbola.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

PanelPosicionBola::PanelPosicionBola(Bola * bolaPasada ,QWidget *parent): QWidget(parent){

	miBola = bolaPasada;
	
	botonPulsado = false;
	
	setAcceptDrops(true);

		
}

void PanelPosicionBola::paintEvent(QPaintEvent * evento){

	QPainter pintor(this);
	//pintor.drawRect(10,20,30,40);	
	
	
	float posXenPanel, posYenPanel;
	
	posXenPanel = miBola->posX * ( (float)width() / miBola->anchuraJuego );
	
	posYenPanel = miBola->posY * ( (float)height() / miBola->alturaJuego );

		
	
	pintor.drawLine(0,posYenPanel,width(),posYenPanel);
	pintor.drawLine(posXenPanel,0,posXenPanel,height());
	
	
}

void PanelPosicionBola::actualizarDibujo(){

	this->update();
}

void PanelPosicionBola::mousePressEvent(QMouseEvent *event){
	botonPulsado= true;
	qDebug() << "has pulsado";
	clicX = event->x();
	clicY = event->y();

}

void PanelPosicionBola::mouseReleaseEvent(QMouseEvent *event){
	botonPulsado = false;
	qDebug() << "has soltado";
	miBola->posX = clicX * (miBola->anchuraJuego / width());
	miBola->posY = clicY * (miBola->alturaJuego / height());
	
	nuevoClicX = event->x();
	
	float velocidadX = nuevoClicX -clicX;
	
	miBola->velX = velocidadX / 10;
	
	nuevoClicY = event->y();
	
	float velocidadY = nuevoClicY - clicY;
	
	miBola->velY = velocidadY / 10;
}















