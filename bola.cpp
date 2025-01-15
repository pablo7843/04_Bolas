#include "bola.h"
#include  <QDebug>
#include <math.h>
#include <stdlib.h>


Bola::Bola() : Bola(0,0,0,0){

}

Bola::Bola(float px, float py, float vx, float vy) :
	posX(px), posY(py), velX(vx),velY(vy) {
	
	vidas = vidasIniciales;
	color  = QColor(random()%256, random()%256, random()%256);

}

void Bola::mover(int anchura, int altura) {

	this->posX = posX + velX ;
	posY = posY + velY ;
		
		
	if ( (posX + diametro) >= anchura )
		velX = - ( fabs( velX ) ) ; 
		
	if (posX <= 0 )
		velX = fabs(velX); 
		
	if ( posY + diametro > altura )
		velY = - fabs (velY) ;

	if (posY < 0 )
		velY = fabs(velY) ;
}

float Bola::distancia(Bola *otra) {
	
	float dist;
	
	dist = sqrtf(  powf( (otra->posX - this->posX) , 2) + powf( (otra->posY - this->posY) , 2) );

	return dist;

}


bool Bola::choca(Bola *otra) {

	if (this->distancia(otra) > diametro )  return false;
	
	Bola *derecha ;
	Bola *izquierda;
	Bola *arriba ;
	Bola *abajo;
	
	bool chocado = false;
	
	if ( this->posX < otra->posX) {
		izquierda = this;
		derecha = otra;
	} else {
		izquierda = otra;
		derecha = this;	
	}
	
	
	if (izquierda-> velX > derecha->velX  ) {
		float aux = izquierda->velX;
		izquierda->velX = derecha->velX ;
		derecha->velX = aux;
		chocado = true;

	}


	if ( this->posY < otra->posY) {
		arriba = this;
		abajo = otra;
	} else {
		arriba = otra;
		abajo = this;	
	}
	
	
	if (arriba-> velY > abajo->velY  ) {
		float aux = arriba->velY;
		arriba->velY = abajo->velY ;
		abajo->velY = aux;
		chocado = true;
	}

	return chocado;

}


























