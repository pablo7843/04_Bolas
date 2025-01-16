#include "bola.h"
#include <QPaintEvent>
#include <QWidget>

class PanelPosicionBola : public QWidget{
Q_OBJECT
public:
	PanelPosicionBola(Bola *,QWidget * parent = NULL);
	Bola * miBola;
	void paintEvent(QPaintEvent *evento);
	void actualizarDibujo();
	bool botonPulsado;
	int clicX, clicY;
	int nuevoClicX, nuevoClicY;
	
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	
};
