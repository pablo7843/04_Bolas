
#include "widgetposicionbola.h"
#include "panelposicionbola.h"
#include <QDebug>
#include <QHBoxLayout>

WidgetPosicionBola::WidgetPosicionBola(Bola * bolaPasada, QWidget *parent): QWidget(parent){
		setupUi(this);
		
		Bola * bola = bolaPasada;
		PanelPosicionBola *widget = new PanelPosicionBola(bola);
		QHBoxLayout * layout = new QHBoxLayout;
		layout->addWidget(widget);
		framePosicionBola->setLayout(layout);
		
		connect(widget,SIGNAL(senyalBolaImagen(Bola*)),this,SLOT(slotBolaImagen(Bola*)));
	
}

void WidgetPosicionBola::slotBolaImagen(Bola *bola){
	
	emit senyalBolaImagen(bola);
}
