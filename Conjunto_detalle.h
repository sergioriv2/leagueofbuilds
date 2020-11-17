#pragma once

#include "Registro.h"

class Conjunto_detalle : public Registro
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
	bool Cargar();
	void Mostrar();
	bool Modificar(int ID);
	bool BajaVirtual(int ID);
	//Wea
	Conjunto_detalle& operator = (Registro* temp)
	{
		Conjunto_detalle* aux = (Conjunto_detalle*)temp;
		idDetalle = aux->idDetalle;
		for (int i = 0; i < 10; i++)
		{
			idEarly[i] = aux->idEarly[i];
			idMid[i] = aux->idMid[i];
		}
		for (int i = 0; i < 6; i++)
		{
			idLate[i] = aux->idLate[i];
		}
		estado = aux->estado;
		return *this;
	}
	bool comparaID(Registro* temp)
	{
		Conjunto_detalle* aux = (Conjunto_detalle*)temp;
		if (aux->idDetalle == idDetalle) return true;
		return false;
	}
	//set
	void setDetalle(int);
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
	int getSize() { return sizeof * this; }
	//
	int contarRegistros();
};