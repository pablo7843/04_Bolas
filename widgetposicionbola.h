
#ifndef WIDGETPOSICIONBOLA_H
#define WIDGETPOSICIONBOLA_H
#include "ui_widgetposicionbola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include "bola.h"

class WidgetPosicionBola : public QWidget, public Ui::WidgetPosicionBola {
Q_OBJECT

public:
	WidgetPosicionBola(Bola *, QWidget *parent = NULL);

public slots:
	void slotBolaImagen(Bola*);
	
signals:
	void senyalBolaImagen(Bola *);

};

#endif 
