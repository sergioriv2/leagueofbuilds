#pragma once
#include "Stat.h"
#include "Registro.h"

class Item : public Stat, public Registro
{
private:
	int costo;
	int id;
	bool estado;
public:
	Item(const char* _nombre);
	Item();
	Item& operator = (Registro* temp)
	{
		Item* aux = (Item*)temp;

		this->setNombre(aux->getNombre());
		ataque = aux->getAtaque();
		vel_ataque = aux->getVel_ataque();
		vida = aux->getVida();
		armor = aux->getArmor();
		resistencia_magica = aux->getResistencia_magica();
		poder_habilidad = aux->getPoder_habilidad();
		CDR = aux->getCDR();
		crit_chance = aux->getCrit_chance();
		mana = aux->getMana();
		regvida = aux->getregVida();
		regmana = aux->getregMana();
		lifeSteal = aux->getlifeSteal();
		id = aux->id;
		estado = aux->estado;
		costo = aux->costo;
		return *this;
	}
	bool comparaID(Registro* temp)
	{
		Item* aux = (Item*)temp;
		if (aux->id == id) return true;
		return false;
	}
	//metodos
	bool Cargar();
	void Mostrar();
	bool Modificar(int ID);
	bool BajaVirtual(int ID);
	bool validarCosto(int costo);
	//set
	void setID(int _id) { id = _id; }
	void setEstado(bool);
	void setCosto();
	void setCosto(int costo) { this->costo = costo; }
	//get
	bool getEstado() { return estado; }
	int getId() { return id; }
	int getSize() { return sizeof * this; }
	int getCosto() { return costo; }
};
