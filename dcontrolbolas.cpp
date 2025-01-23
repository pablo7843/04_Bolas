#include "dcontrolbolas.h"
#include <QDebug>

DControlBolas::DControlBolas(QVector<Bola*> *bolasPasadas,QWidget *parent): QDialog(parent){
	
	setupUi(this);
	
	lasBolas = bolasPasadas;
	
	inicializarPestanyas();
	
}

void DControlBolas::inicializarPestanyas(){
	
	tabWidget->clear();
	for(int i=0; i<lasBolas->length();i++){
		WidgetBola *unWidget = new WidgetBola((*lasBolas)[i]);
		tabWidget->addTab(unWidget,lasBolas->at(i)->nombre);
	}

}

void DControlBolas::slotEjemplo(){

}


void DControlBolas::slotBolaMuerta(int iMuerta){
	Bola *bolaMuerta = lasBolas->at(iMuerta);
	for(int i = 0; i < tabWidget->count(); i++){
		
		QWidget *widgetBuscando = tabWidget->widget(i);
		WidgetBola *wBola = qobject_cast<WidgetBola*> (widgetBuscando);
		if(wBola->miBola == bolaMuerta){
			tabWidget->removeTab(i);
			return;
		}
	}
	
}

