#include "ventanaprincipal.h"
#include <QPainter>
#include <math.h>
#include <stdlib.h>

#include <QColor>
#include <QDebug>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QStringLiteral>
#include <QIODevice>
#include <QJsonArray>

VentanaPrincipal::VentanaPrincipal(QWidget * parent) : QMainWindow(parent) {
	
	QTimer * temporizador;
	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	
	temporizador->start();
	
	dListaBolas = NULL;
	dTablaBolas = NULL;
	dControlBolas = NULL;
	dPosicionBolas = NULL;
	
	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotTemporizador()));
	incializarBolas();
	
	crearActions();
	crearMenus();
	
	resize(800,600);
	
	//indicamos a las bolas la anchura del juego
	
	for(int i = 0; i < bolas.size(); i++){
		bolas.at(i)->anchuraJuego = width();
		bolas.at(i)->alturaJuego = height();
	}

}

void VentanaPrincipal::crearActions(){

 	accionListaBolas  = new QAction("listarBolas",this);
        connect(accionListaBolas,SIGNAL(triggered()),this,SLOT(slotListaBolas()));
       		
	accionTablaBolas  = new QAction("TablaBolas",this);
        connect(accionTablaBolas,SIGNAL(triggered()),this,SLOT(slotTablaBolas()));
       		
       	accionControlBolas = new QAction("ControlPelotas",this);
       	connect(accionControlBolas,SIGNAL(triggered()),this,SLOT(slotControlBolas()));     
       	
       	accionGuardarPartida = new QAction("Guardar Partida",this);
       	connect(accionGuardarPartida,SIGNAL(triggered()),this,SLOT(slotGuardarPartida()));
       	
       	accionCargarPartida = new QAction("Cargar Partida",this);
       	connect(accionCargarPartida,SIGNAL(triggered()),this,SLOT(slotCargarPartida()));
       	
       	accionPosicionBolas = new QAction("PosicionBolas",this);
       	connect(accionPosicionBolas,SIGNAL(triggered()),this,SLOT(slotPosicionBolas()));
       	  		
}

void VentanaPrincipal::crearMenus(){
	QMenu *menuInfo = menuBar()->addMenu("Informasion");
	
	menuInfo->addAction(accionListaBolas);
	menuInfo->addAction(accionTablaBolas);
	menuInfo->addAction(accionControlBolas);
	menuInfo->addAction(accionPosicionBolas);
	
	QMenu *menuPartida = menuBar()->addMenu("Partida");
	menuPartida->addAction(accionGuardarPartida);
	menuPartida->addAction(accionCargarPartida);

}


void VentanaPrincipal::incializarBolas() {

     QStringList nombres = {"Ampersand","perico","andres","Jordi","juanito","Daniel","Jose",
     	"elpepe","pol", " pilila"};


	for (int i = 0; i < 10 ; i++ ) {
		int posIniX = random() % 800 ;
		int posIniY = random() % 600 ;
	
		
		float velX = (float)(random()%100) / 50 - 1;
		velX = velX * 3 ;
		float velY = (float)(random()%100) / 50 - 1;

		Bola *nueva = new Bola (posIniX,posIniY,velX,velY);
		
		nueva->nombre = nombres.at(i % nombres.length());	
		bolas.append(nueva);	
		
	}
	
	bolaJugador = new Bola(400,400,0.5,0.5);
	

}

void VentanaPrincipal::paintEvent(QPaintEvent * e) {
	QPainter pintor(this);
	

	pintor.fillRect(10,10,50,50,"Red");

	for (int i=0; i < bolas.length() ; i++ ) {	
	
		pintor.setBrush(bolas[i]->color);
		pintor.drawEllipse(bolas[i]->posX, bolas[i]->posY,
							Bola::diametro,
							Bola::diametro);
		pintor.drawText(bolas[i]->posX ,
				bolas[i]-> posY + Bola::diametro + 20 ,
				 bolas[i]-> nombre);
				 
		pintor.drawText(bolas[i]->posX ,
				bolas[i]-> posY - 10 ,
				QString("vidas:  ") + QString::number(bolas[i]->vidas));
				
/********************** barra VERDA ***************************************/				
		pintor.setBrush(QColor("Green"));
		
		int anchoBarra = Bola::diametro;
		float division = (float) bolas[i]->vidas / (float) Bola::vidasIniciales;
		
		anchoBarra = anchoBarra * division;
		pintor.drawRect(bolas.at(i)->posX,
						bolas.at(i)->posY - 20,
						anchoBarra,
						5);
		float acabaVerda = bolas.at(i)->posX  + anchoBarra ;
		
/********************** barra ROJA ***************************************/
						
		int mortes = Bola::vidasIniciales  -  bolas.at(i)->vidas; 
		division = (float)mortes / (float)Bola::vidasIniciales ;
		anchoBarra = Bola::diametro * division;
						
		pintor.setBrush(QColor("red"));
		pintor.drawRect(acabaVerda,
				bolas.at(i)->posY - 20,
				anchoBarra,
				5);
		
	}
	
	QColor colorJugador = QColor(255,0,0);
	pintor.setBrush(colorJugador);
	pintor.drawEllipse(bolaJugador->posX, bolaJugador->posY,Bola::diametro,Bola::diametro);
}

void VentanaPrincipal::slotTemporizador() {

	for (int i=0; i < bolas.length() ; i++ ) {			
		bolas[i]->mover(this->width(), this->height());
	}
	
	bolaJugador->mover(this->width(),this->height());
	//qDebug() << "revisar choques";
	for (int i = 0; i < bolas.length() ; i++ ) {			
		for (int j = i + 1; j < bolas.length() ; j++ ) {			
			if (i != j )
				if (bolas[i]->choca(bolas[j])) {
					bolas[i]->vidas--;
					bolas[j]->vidas--;
					//qDebug() << "vida quitada "<< i << " " << j ;
				}
		}
	}

	
	/* bola jugador rebota contra otras */
	for (int i = 0; i < bolas.length() ; i++ ) 			
		bolaJugador->choca(bolas.at(i));


	for (int i = 0; i < bolas.length() ; i++ ) 			
		if (bolas.at(i)->vidas < 0 ) 
			bolas.at(i)->vidas = 0;
	
	
	for (int i=0; i < bolas.length() && false ; i++ )
		if ( bolas.at(i)->vidas <=0 ) {
			emit senyalBolaMuerta(i);
			delete bolas.at(i) ;
			bolas.remove(i);
			break;
					
		}
		
	this->update();  // estoy llamando a paintEvent
}



void VentanaPrincipal::keyPressEvent(QKeyEvent *evento){

	int tecla = evento->key();

	   switch (tecla) {
                case Qt::Key_Up : 
                        bolaJugador->velY = bolaJugador->velY - 0.1 ;
                        break;
                case Qt::Key_Down : 
                        bolaJugador->velY = bolaJugador->velY + 0.1 ;
                        break;
                case Qt::Key_Right : 
                        bolaJugador->velX = bolaJugador->velX + 0.1 ;
                        break;
                case Qt::Key_Left : 
                        bolaJugador->velX = bolaJugador->velX - 0.1 ;
                        break;
        }
}


void VentanaPrincipal::mousePressEvent(QMouseEvent *event){

	
	float empujeX = event->x() - bolaJugador->posX; 
	empujeX = empujeX / 250;

	float empujeY = event->y() - bolaJugador->posY; 
	empujeY = empujeY / 250;

	
	bolaJugador->velX += empujeX;
	bolaJugador->velY += empujeY;	


}



void VentanaPrincipal::slotListaBolas(){

	if (dListaBolas == NULL)
		dListaBolas = new DListaBolas( &bolas );
		
	dListaBolas->show();
}



void VentanaPrincipal::slotTablaBolas(){

	if (dTablaBolas == NULL)
		dTablaBolas = new DTablaBolas( &bolas );
		
	dTablaBolas->show();
}

void VentanaPrincipal::slotControlBolas(){
	
	if(dControlBolas == NULL){
		dControlBolas = new DControlBolas( &bolas );
		connect(this,SIGNAL(senyalBolaMuerta()),dControlBolas,SLOT(slotBolaMuerta())); 
	}
	dControlBolas->show();
}

void VentanaPrincipal::slotCargarPartida(){

	for (int i=0; i< bolas.size(); i++)
		delete bolas[i];
	bolas.clear();

	QFile loadFile(QStringLiteral("partida.json"));
	if(! loadFile.open(QIODevice::ReadOnly))
		return;
	
	QByteArray savedData = loadFile.readAll();
	QJsonDocument documento( QJsonDocument::fromJson(savedData));
	QJsonObject jsonPrincipal = documento.object();	
	
	QStringList listaClaves = jsonPrincipal.keys();
	
	qDebug() << "Lista de claves " << listaClaves;
	
	if(listaClaves.contains("miNombre")){
		QJsonValue valormiNombre = jsonPrincipal["miNombre"];
		QString stringmiNombre;
		if (valormiNombre.isString() ){
			stringmiNombre = valormiNombre.toString();
			qDebug()<< " Nombre es " << stringmiNombre;
		}
	}
	
	
	QJsonValue valorBolas = jsonPrincipal["bolas"];
	
	if(!valorBolas.isArray()){
		qDebug() << "error, las bolas no son un array";
		return;
	}
	
	QJsonArray arrayBolas = valorBolas.toArray();
	
	for(int i = 0; i< arrayBolas.size(); i++){
		QJsonValue elemento = arrayBolas[i];
		
		crearBolaJson(elemento);
		if(!crearBolaJson(elemento)){
			qDebug() << "no se puede crear la bola" << i ;
			return ;
		}
		
	}
	
	
}
void VentanaPrincipal::slotGuardarPartida(){

	QJsonObject jsonPrincipal;
	/*INICIO crear JSON con datos del juego*/

	jsonPrincipal["miNombre"] = QString("Pablo");
	jsonPrincipal["edad"] = 21;
	
	/*QJsonArray versiones;
	versiones.append(2);
	versiones.append(2.1);
	versiones.append(2.2);
	jsonPrincipal["versiones"] = versiones;*/
	
	/*Bola del jugador*/
	QJsonObject jsonJugador;
	
	jsonJugador["posX"] = bolaJugador->posX;
	jsonJugador["posY"] = bolaJugador->posY;
	
	jsonPrincipal["BolaJugador"] = jsonJugador;

	
	QJsonArray coloresJugador;
	
	coloresJugador.append(bolaJugador->color.red());
	coloresJugador.append(bolaJugador->color.blue());
	coloresJugador.append(bolaJugador->color.green());	
	jsonJugador["color"] = coloresJugador;	
	
	jsonPrincipal["coloresBolaJugador"] = coloresJugador;
	
	QJsonObject bolaJson;
	QJsonArray arrayBolas;
	for( Bola* b: bolas ){
		bolaJson["nombre"] = b->nombre;
		bolaJson["posX"] = b->posX;
		bolaJson["posY"] = b->posY;
		bolaJson["velX"] = b->velX;
		bolaJson["velY"] = b->velY;
		
		QJsonArray coloresJugador;
	
		coloresJugador.append(b->color.red());
		coloresJugador.append(b->color.blue());
		coloresJugador.append(b->color.green());	
		bolaJson["color"] = coloresJugador;

		arrayBolas.append(bolaJson);
	}
	jsonPrincipal["bolas"] = arrayBolas;

	/*FIN crear JSON con datos del juego. Guardo el archivo*/
	QFile saveFile(QStringLiteral("partida.json"));

	saveFile.open(QIODevice::WriteOnly);

	QJsonDocument saveDoc(jsonPrincipal);
	
	saveFile.write(saveDoc.toJson());
}


bool VentanaPrincipal::crearBolaJson(QJsonValue &elemento){

	if(! elemento.isObject()){
		qDebug() << "No objecto en array de bolingas";
		return false;
	}
		
	QJsonObject objetoBola = elemento.toObject();
	QJsonValue valorPosX = objetoBola["posX"];	
	if(!valorPosX.isDouble()){
		qDebug() << "error, posX no es un numero";
		return false;	
	}
		
	float posX = valorPosX.toDouble();
	float posY = objetoBola["posY"].toDouble();
	float velX = objetoBola["velX"].toDouble();
	float velY = objetoBola["velY"].toDouble();
	
	QString nombre = objetoBola["nombre"].toString(); 
	int rojo, verde, azul;
	
	QJsonValue colores = objetoBola["color"];
	if(!colores.isArray()){
		qDebug() << "el color no esta bien";
		return false;
	}
	
	QJsonArray arrayColores = colores.toArray();
	
	rojo = arrayColores[0].toInt();
	verde = arrayColores[1].toInt();
	azul = arrayColores[2].toInt();
	
	Bola * nueva = new Bola(posX,posY,velX,velY);
	nueva->nombre = nombre;
	nueva->color = QColor(rojo,verde,azul);

	bolas.append(nueva);

	return true;
}


void VentanaPrincipal::slotPosicionBolas(){
	
	if(dPosicionBolas == NULL)
		dPosicionBolas = new DPosicionBolas( &bolas );
	
	dPosicionBolas->show();
}





