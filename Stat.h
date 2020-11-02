#pragma once
#pragma warning(disable : 4996)

class Stat
{
protected:
	char nombre[15];
	float ataque;
	float vel_ataque;
	float poder_habilidad;
	float vida;
	float armor;
	float resistencia_magica;
	float crit_chance;
	float mana;
	//RectangleShape icono;
	//Vector2i cord_img;
	//Texture textura;
public:
	Stat(const char* _nombre = "None");
	~Stat();
	//sets
	void setNombre();
	void setAtaque();
	void setVel_ataque();
	void setPoder_habilidad();
	void setVida();
	void setArmor();
	void setResistencia_magica();
	void setCrit_chance();
	void setMana();
	//gets
	const char* getNombre();
	float getAtaque();
	float getVel_ataque();
	float getPoder_habilidad();
	float getVida();
	float getArmor();
	float getResistencia_magica();
	float getCrit_chance();
	float getMana();
};

