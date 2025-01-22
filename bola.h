#ifndef _BOLA_H
#define _BOLA_H
#include <QString>
#include <QPainter>
#include <QColor>
#include <QImage>

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
	void pintar(QPainter &pintor);
	
	//Para imagenes
	QImage imagen;
	bool esImagen;
	
	void establecerImagen();
	void establecerImagen(QString);

};


#endif
