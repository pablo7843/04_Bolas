#include "bola.h"
#include <QPaintEvent>
#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

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
	
	void dropEvent(QDropEvent *);
	void dragEnterEvent(QDragEnterEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	
	
};
