#pragma once

#include "Registro.h"

class Conjunto_cabecera: public Registro
{
private:
	int idConjunto, idCampeon;
	int costoTotal;
	char nombre[30];
	bool estado;
public:
	Conjunto_cabecera();
	//metodos
	bool Cargar();
	bool Modificar(int ID);
	bool BajaVirtual(int ID);
	void Mostrar();
	void MostrarCabecera();
	Conjunto_cabecera& operator = (Registro* temp)
	{
		Conjunto_cabecera* aux = (Conjunto_cabecera*)temp;

		idConjunto = aux->idConjunto;
		idCampeon = aux->idCampeon;
		costoTotal = aux->costoTotal;
		strcpy(nombre, aux->nombre);
		estado = aux->estado;
		return *this;
	}
	bool comparaID(Registro* temp)
	{
		Conjunto_cabecera* aux = (Conjunto_cabecera*)temp;
		if (aux->idConjunto == idConjunto) return true;
		return false;
	}
	//set
	void setidConjunto();
	void setID(int _id) { idConjunto = _id; }
	void setidCampeon();
	void setCostototal();
	void setNombre();
	void setEstado(bool _estado) { estado = _estado; }
	//get
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	int getCosto();
	int getcostoTotal() { return costoTotal; }
	bool getEstado() { return estado; }
	char* getNombre() { return nombre; }
	int getSize() { return sizeof *this; }
	//
	int contarRegistros();
};

