
#include "widgetbola.h"
#include <QDebug>

WidgetBola::WidgetBola(Bola *bola,QWidget *parent): QWidget(parent), miBola(bola){
		setupUi(this);

	connect(botonParar,SIGNAL(clicked()),
       		this,SLOT(slotParar()));
	
}


void WidgetBola::slotEjemplo(){

}

void WidgetBola::slotParar(){

	if(miBola){
		miBola->velY = 0;
		miBola->velX = 0;
	}
}
