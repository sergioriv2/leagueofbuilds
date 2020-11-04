#pragma once
class Conjunto_detalle
{
private:
	int idDetalle;
	int idEarly[10], idMid[10], idLate[6];// ID DE ITEMS
public:
	Conjunto_detalle();
	void imprimirEarly();
	void imprimirMid();
	void imprimirLate();
	void imprimirDetalle();
	//set
	void setDetalle();
	void setItems();
	void setitemsEarly();
	void setItemsMid();
	void setItemsLate();
	//gets
	int getDetalle() { return idDetalle; }//id
	int* getEarly() { return idEarly; }
	int* getMid() { return idMid; }
	int* getLate() { return idLate; }
	//
	int contarRegistros();
};