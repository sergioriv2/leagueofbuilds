#pragma once
class Conjunto_detalle
{
private:
	int idDetalle;
	int idEarly[10], idMid[10], idLate[6];// ID DE ITEMS
	bool estado;
public:
	Conjunto_detalle();
	void imprimirEarly();
	void imprimirMid();
	void imprimirLate();
	void imprimirDetalle();
	bool guardarDetalle(int pos = -1);
	void cargarDetalle(int);
	//set
	void setDetalle(int);
	void setItems();
	void setitemsEarly();
	void setItemsMid();
	void setItemsLate();
	void setEstado(bool _estado) { estado = _estado; }
	//gets
	bool getEstado() { return estado; }
	int getDetalle() { return idDetalle; }//id
	int* getEarly() { return idEarly; }
	int* getMid() { return idMid; }
	int* getLate() { return idLate; }
	//
	int contarRegistros();
};