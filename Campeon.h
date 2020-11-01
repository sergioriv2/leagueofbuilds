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
	//sets
	void setStats();
	void setEstilo();
	void setdmgType();
	//gets
	const char* getEstilo() { return estilo; }
	const char* getDmg() { return dmg_type; }
	void getStats();
};

