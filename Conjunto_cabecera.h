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
	bool ingresarCabecera();
	int buscaridChamp(int);
	int buscaridConjunto(int);
	bool guardarCabecera(int pos = -1);
	void cargarCabecera();
	void modificar(bool borrar = false);
	//set
	void setidConjunto();
	void setidCampeon();
	void setCostototal();
	void setNombre();
	void setEstado(bool _estado) { estado = _estado; }
	//get
	int getidConjunto() { return idConjunto; }
	int getidCampeon() { return idCampeon; }
	int getCostoEarly();
	int getCostoMid();
	int getCostoLate();
	int getcostoTotal() { return costoTotal; }
	bool getEstado() { return estado; }
	char* getNombre() { return nombre; }
	//
	int contarRegistros();
};

