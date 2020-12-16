#pragma once
#pragma warning(disable : 4996)

class Stat
{
protected:
	char nombre[30] = "";
	float ataque;
	float vel_ataque;
	float poder_habilidad;
	float vida;
	float armor;
	float resistencia_magica;
	float crit_chance;
	float mana;
	float regmana; // Nuevo -----
	float regvida;
	float CDR;
	float lifeSteal;
	//RectangleShape icono;
	//Vector2i cord_img;
	//Texture textura;
public:
	Stat(const char* _nombre = "None");
	//~Stat();
	//sets
	// True para cargar Campeones, False  para cargar items
	void setStats(bool basicStats);
	bool setNombre();
	void setAtaque();
	void setVel_ataque();
	void setPoder_habilidad();
	void setVida();
	void setArmor();
	void setResistencia_magica();
	void setCrit_chance();
	void setMana();
	void setregMana();
	void setregVida();
	void setlifeSteal();
	void setCDR();
	//Sobrecarga
	void setNombre(const char* _nombre) { strcpy(nombre, _nombre); }
	void setAtaque(float _ataque) { ataque = _ataque; }
	void setVel_ataque(float _vataque) { vel_ataque = _vataque; }
	void setPoder_habilidad(float _ap) { poder_habilidad = _ap; }
	void setVida(float _vida) { vida = _vida; }
	void setArmor(float _armor) { armor = _armor; }
	void setResistencia_magica(float _mr) { resistencia_magica = _mr; }
	void setCrit_chance(float _critc) { crit_chance = _critc; }
	void setMana(float _mana) { mana = _mana; }
	void setregMana(float _rmana) { regmana = _rmana; }
	void setregVida(float _rvida) { regvida = _rvida; }
	void setlifeSteal(float _ls) { lifeSteal = _ls; }
	void setCDR(float _cdr) { CDR = _cdr; }
	//gets
	// True para cargar Campeones, False  para cargar items
	void getStats(bool basicStats);
	const char* getNombre() { return nombre; }
	float getAtaque();
	float getVel_ataque();
	float getPoder_habilidad();
	float getVida();
	float getArmor();
	float getResistencia_magica();
	float getCrit_chance();
	float getMana();
	float getregMana() { return regmana; }
	float getregVida() { return regvida; }
	float getCDR() { return CDR; }
	float getlifeSteal() { return lifeSteal; }

	//validaciones a la hora de ingresar datos
	bool validarNombre(char* nombre);
	bool validarAtaque(float ataque);
	bool validarVa(float va);
	bool validarPh(float ph);
	bool validarVida(float vida);
	bool validarArmor(float armor);
	bool validarRM(float rm);
	bool validarCrit(float crit);
	bool validarMana(float mana);
	bool validarRegmana(float regmana);
	bool validarRegvida(float regvida);
	bool validarCDR(float cdr);
	bool validarRobovida(float lifesteal);
};

