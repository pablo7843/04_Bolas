#ifndef _BOLA_H
#define _BOLA_H
#include <QString>
#include <QColor>

class Bola {

public:

	static const int diametro = 50;
	static const int vidasIniciales = 10;
	
	QColor color;
	
	float anchuraJuego, alturaJuego;
	
	float posX, posY;
	float velX, velY;
	QString nombre;
	int vidas;
	
	Bola(float px, float py , float vx, float vy);
	Bola();
	
	void mover(int, int);
	
	float distancia(Bola *otra);
	bool choca(Bola *);

};


#endif
