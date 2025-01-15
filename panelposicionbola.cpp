#include "panelposicionbola.h"
#include <QPainter>
#include <QTimer>

PanelPosicionBola::PanelPosicionBola(Bola * bolaPasada ,QWidget *parent): QWidget(parent){

	miBola = bolaPasada;
		
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
