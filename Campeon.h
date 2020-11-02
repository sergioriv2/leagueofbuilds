#pragma once
#include "Stat.h"

class Campeon : public Stat
{
private:
	char estilo[20];
	char dmg_type[15];
	int id;
	bool estado;
public:
	Campeon(const char* _estilo = "None", const char* _dmgtype = "None");
	~Campeon();
	//metodos
	void cargarCampeon();
	void mostrarCampeon();
	// operaciones archivo
	bool guardarCampeon(int pos = -1);
	int contar_reg();
	void mostrarCampeones();
	int searchPos(int ID);
	bool modify(int POS, int OPC);//OPC Es mandado a un switch donde se elije la varaible a modificar
	bool leerCampeon(int POS);//Lee un campeon del archivo depende la pos.
	//sets
	void setEstilo();
	void setdmgType();
	void setEstadoFalse();
	//gets
	int getID() { return id; }
	const char* getEstilo() { return estilo; }
	const char* getDmg() { return dmg_type; }
	bool getEstado() { return estado; }
};

