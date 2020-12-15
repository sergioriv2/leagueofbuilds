#pragma once
#include "Stat.h"
#include "Registro.h"

class Campeon : public Stat, public Registro
{
private:
	int estilo;
	int dmg_type;
	int id;
	bool estado;
public:
	Campeon(int _estilo, int _dmgtype);
	Campeon() {};
	~Campeon();
	//metodos registro
	bool Cargar();
	void Mostrar();
	bool Modificar(int ID);
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

		this->estilo = aux->estilo;
		this->dmg_type = aux->dmg_type;
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
	bool BajaVirtual(int ID);
	//sets
	void setEstilo();
	void setdmgType();
	void setEstadoFalse();
	void setEstado(bool estado) { this->estado = estado; }
	void setID(int _id) { id = _id; }
	//sobrecarga sets
	void setEstilo(int estilo) { this->estilo = estilo; }
	void setdmgType(int dmgtype) { this->dmg_type = dmgtype; }
	//gets
	int getID() { return id; }
	int getEstilo() { return estilo; }
	int getDmg() { return dmg_type; }
	int getSize() { return sizeof * this; }
	bool getEstado() { return estado; }


	bool validarEstilo(int estilo);
	bool validarTipodmg(int tipodmg);

};

