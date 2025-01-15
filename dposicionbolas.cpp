
#include "dposicionbolas.h"
#include <QDebug>
#include <QTimer>
#include <QFrame>
#include <QLayout>
#include <QLayoutItem>
#include "panelposicionbola.h"



DPosicionBolas::DPosicionBolas(QVector<Bola *> * bolasPasadas, QWidget *parent): QDialog(parent){
	setupUi(this);
	
	lasBolas = bolasPasadas;
	
	inicializarPestanyas();
	
	QTimer * temporizador;
	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	
	temporizador->start();
	
	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotTemporizador()));
	
}


void DPosicionBolas::inicializarPestanyas(){
	tabBolas->clear();
	for(int i=0; i<lasBolas->length();i++){
		WidgetPosicionBola *unWidget = new WidgetPosicionBola((*lasBolas)[i]);
		tabBolas->addTab(unWidget,lasBolas->at(i)->nombre);
	}

}

void DPosicionBolas::slotTemporizador(){

	QWidget * widgetActual;
	widgetActual = tabBolas->currentWidget();
	
	WidgetPosicionBola *wPB;
	wPB = qobject_cast<WidgetPosicionBola*>(widgetActual);
	
	QFrame *frame = wPB->framePosicionBola;
	
	QLayout * layoutFrame = frame->layout();
	
	int numElementos = layoutFrame->count();
	if(numElementos != 1){
		return; // a tomar por culo
	}
	
	QLayoutItem * itemDelLayout = layoutFrame->itemAt(0);
	
	QWidget *widgetPanel = itemDelLayout->widget();
	
	PanelPosicionBola *panel;
	panel = qobject_cast<PanelPosicionBola*>(widgetPanel);
	
	panel->actualizarDibujo();
	
}
