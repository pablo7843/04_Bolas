
#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H
#include "ui_widgetbola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include "bola.h"

class WidgetBola : public QWidget, public Ui::WidgetBola {
Q_OBJECT

public:
	WidgetBola(Bola *bola, QWidget *parent = NULL);
	Bola *miBola;
public slots:
	void slotEjemplo();
	void slotParar();

};

#endif 
