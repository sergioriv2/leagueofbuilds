#pragma once
#pragma warning(disable : 4996)

class Stat
{
protected:
	char nombre[30];
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
	void setNombre();
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
};

