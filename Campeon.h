#pragma once
#include "Stat.h"
#include "Registro.h"

class Campeon : public Stat, public Registro
{
private:
	char estilo[20];
	char dmg_type[15];
	int id;
	bool estado;
public:
	Campeon(const char* _estilo = "None", const char* _dmgtype = "None");
	~Campeon();
	//metodos registro
	bool Cargar();
	void Mostrar();
	bool Modificar(int ID);
	bool BajaVirtual(int ID);
	Campeon& operator = (Registro* temp)
	{
		Campeon* aux = (Campeon*)temp;

		this->setNombre(aux->getNombre());
		ataque = aux->getAtaque();
		vel_ataque = aux->getVel_ataque();
		vida = aux->getVida();
		armor = aux->getArmor();
		mana = aux->getMana();
		resistencia_magica = aux->getResistencia_magica();

		strcpy(this->estilo, aux->estilo);
		strcpy(this->dmg_type, aux->dmg_type);
		id = aux->id;
		estado = aux->estado;
		return *this;
	}
	bool comparaID(Registro* temp)
	{
		Campeon* aux = (Campeon*)temp;
		if (aux->id == id) return true;
		return false;
	}
	//sets
	void setEstilo();
	void setdmgType();
	void setEstadoFalse();
	void setID(int _id) { id = _id; }
	//gets
	int getID() { return id; }
	const char* getEstilo() { return estilo; }
	const char* getDmg() { return dmg_type; }
	int getSize() { return sizeof *this; }
	bool getEstado() { return estado; }
};

