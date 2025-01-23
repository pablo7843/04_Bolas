#ifndef _VENTANAPRINCIPAL_H_
#define  _VENTANAPRINCIPAL_H_

#include <QPaintEvent>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <QVariant>
#include <QMenu>
#include <QMenuBar>
#include <QJsonValue>
#include "bola.h"
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dcontrolbolas.h"
#include "dposicionbolas.h"

class VentanaPrincipal : public QMainWindow {
Q_OBJECT


public :

	// float posX,posY,velX,velY;

//	QTimer temporizador;
	QVector<Bola*> bolas;
	Bola * bolaJugador;
	
	QAction *accionListaBolas, *accionTablaBolas, *accionControlBolas, *accionPosicionBolas,
		*accionQuitarImagen;
	QAction *accionCargarPartida, *accionGuardarPartida;
	
	DListaBolas * dListaBolas;
	DTablaBolas * dTablaBolas;
	DControlBolas * dControlBolas;
	DPosicionBolas * dPosicionBolas;
	
	QMenu *menuBolaImagenes;
	
	bool crearBolaJson(QJsonValue &elemento);
	void crearActions();
	void crearMenus();
	
	VentanaPrincipal(QWidget * parent = NULL);
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void incializarBolas();
public slots:
	void slotTemporizador();
	void slotListaBolas();
	void slotTablaBolas();
	void slotControlBolas();
	void slotCargarPartida();
	void slotGuardarPartida();
	void slotPosicionBolas();
	void slotEliminarImagen();
	void slotBolaImagen(Bola *bola);
	
signals:
	void senyalBolaMuerta(int);
};


#endif








