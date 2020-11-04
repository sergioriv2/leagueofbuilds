#pragma once
class Conjunto_detalle
{
private:
	int idDetalle, idConjunto;
	int idEarly[10], idMid[10], idLate[6];// ID DE ITEMS
public:
	//set
	void setDetalle();
	void setidConjunto(int idConjunto);
	void setitemsEarly();
	void setItemsMid();
	void setItemsLate();
	//gets
	int getDetalle() { return idDetalle; }//id
	int getConjunto() { return idConjunto;}//id
	int* getEarly() { return idEarly; }
	int* getMid() { return idMid; }
	int* getLate() { return idLate; }
	//
	int contarRegistros();
};

