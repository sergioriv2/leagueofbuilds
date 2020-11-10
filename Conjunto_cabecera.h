#pragma once

class Conjunto_cabecera
{
private:
	int idConjunto, idCampeon;
	int costoTotal;
	char nombre[30];
	bool estado;
public:
	Conjunto_cabecera();
	//metodos
	void ingresarCabecera();
	int calcularCosto(int);
	int buscaridChamp(int);
	bool guardarCabecera();
	void cargarCabecera();
	//set
	void setidConjunto();
	void setidCampeon();
	void setCostototal();
	void setNombre();
	//get
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	int getcostoTotal() { return costoTotal; }
	char* getNombre() { return nombre; }
	//
	int contarRegistros();
};

