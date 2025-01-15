
#include "dtablabolas.h"
#include <QDebug>
#include <QTimer>



DTablaBolas::DTablaBolas( QVector<Bola*>* pBolas, QWidget *parent): QDialog(parent){
		setupUi(this);

	ModeloTabla * modelo = new ModeloTabla(pBolas);
	vista -> setModel(modelo);	
	
	
	
}


void DTablaBolas::slotEjemplo(){

}


ModeloTabla::ModeloTabla(QVector<Bola * > * bolasPasadas, QObject *parent ) : QAbstractTableModel(parent) {

	pBolas = bolasPasadas;


	QTimer * temporizador;
	temporizador = new QTimer();
	temporizador->setInterval(500);
	temporizador->setSingleShot(false);
	
	//temporizador->start();

	connect(temporizador,SIGNAL(timeout()),
		this, SLOT(slotTemporizador()));

}


int ModeloTabla::columnCount(const QModelIndex &parent ) const{
	return 4; // posx, posy, velx, vely 
}

int ModeloTabla::rowCount(const QModelIndex &parent ) const {
	return pBolas->length();

}

QVariant ModeloTabla::data(const QModelIndex &index, int role ) const {

	

	 if ( role != Qt::DisplayRole ) return QVariant();

    int fila = index.row();
    int columna = index.column();
    Bola * bola = pBolas->at(fila);

    QString resultado;
    switch (columna) {
   	 case 0:
   		  resultado = QString::number(bola ->posX);
   		  break;
   	 case 1:
   		  resultado = QString::number(bola ->posY);
   		  break;
   	 case 2:
   		  resultado = QString::number(bola ->velX);
   		  break;
   	 case 3:
   		  resultado = QString::number(bola ->velY);
   		  break;
    };
    return QVariant(resultado);

}


void ModeloTabla::slotTemporizador(){
	
	QModelIndex topLeft = index(0,0);
	QModelIndex bottomRight = index(-1,3 );
	
	beginResetModel();
	
	emit layoutChanged();
	emit dataChanged(topLeft,bottomRight);

}

Qt::ItemFlags ModeloTabla::flags(const QModelIndex &index) const
{
	if (index.column() <= 1 ) 
	    return Qt::ItemIsEditable | QAbstractTableModel::flags(index) ;

	return QAbstractTableModel::flags(index);
}

bool ModeloTabla::setData(const QModelIndex &index, const QVariant &value, int role ){

	float dato;
	int fila = index.row();
	Bola * bola = pBolas->at(fila);
	dato = value.toString().toFloat();

	int columna = index.column();

	switch( columna){
		case 0: // posicion X
			bola->posX = dato;
			break;
		case 1: //
			bola->posY = dato;
			break;
		default:
			qDebug() << "Tratando de establecer un dato inválido en bola " << fila;
	}

	bola->posX = dato;
	bola->posY = dato;

	return true;
}

  QVariant ModeloTabla::headerData(int section, Qt::Orientation orientation, int role ) const {
  		
  		if (role == Qt::BackgroundColorRole && orientation == Qt::Vertical)
  			return pBolas->at(section)->color;
  	
  		if (role != Qt::DisplayRole ) 
			return QVariant() ;

		QStringList lista = {"PosX","PosY","VelX","Vely"};			
		
		if (orientation == Qt::Horizontal) 
			 return lista[section];
		
		if (orientation == Qt::Vertical) {
			return pBolas->at(section)->nombre;
		}	
  
  
  }


















