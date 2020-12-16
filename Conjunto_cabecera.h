#pragma once

#include "Registro.h"
#include <cstring>

class Conjunto_cabecera : public Registro
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
	bool idchampcheck(int IDCAMPEON);
	void setCostototal();
	void setNombre();
	void setEstado(bool _estado) { estado = _estado; }
	void setidCampeon(int idchamp) { idCampeon = idchamp; }
	void setNombre(char* nombre) { strcpy(this->nombre, nombre); }
	void setCostototal(int cost) { costoTotal = cost; }
	//get
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	int getCosto();
	int getcostoTotal() { return costoTotal; }
	bool getEstado() { return estado; }
	char* getNombre() { return nombre; }
	int getSize() { return sizeof * this; }

	//
	bool validarNombre(char* nombre) {
		if (nombre[0] == '\0' || nombre[0] == ' ') {
			std::cout << "No ingresar espacios en blanco." << std::endl;
			return false;
		}
		return true;
	}
};

