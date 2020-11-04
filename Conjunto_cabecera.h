#pragma once

class Conjunto_cabecera
{
private:
	int idConjunto, idCampeon;
	float costoTotal;
	Conjunto_detalle det;
	char nombre[30];
public:
	Conjunto_cabecera();
	//metodos
	int buscaridChamp(int);
	//set
	void setidConjunto();
	void setidCampeon();
	void setCostototal();
	void setNombre();
	//get
	void getDetalle();
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	float getcostoTotal() { return costoTotal; }
	char* getNombre() { return nombre; }
	//
	int contarRegistros();
};

