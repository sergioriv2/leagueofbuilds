#pragma once

class Conjunto_cabecera
{
private:
	int idConjunto, idCampeon;
	float costoTotal;
	char nombre[30];
public:
	//set
	void setidConjunto();
	void setidCampeon();
	void setCostototal();
	void setNombre();
	//get
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	float getcostoTotal() { return costoTotal; }
	char* getNombre() { return nombre; }
	//
	int contarRegistros();
};

