
#ifndef DTABLABOLAS_H
#define DTABLABOLAS_H
#include "ui_dtablabolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>

class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT

public:
	DTablaBolas(QVector<Bola*>*, QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

class ModeloTabla : public QAbstractTableModel {
Q_OBJECT

public:

	QVector<Bola * > * pBolas; 

	ModeloTabla(QVector<Bola * > * pBolasPasadas, QObject *parent = nullptr);
	
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const ;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
Qt::ItemFlags flags(const QModelIndex &index) const ;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	
  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;


public slots:
	void slotTemporizador();

};








#endif 
