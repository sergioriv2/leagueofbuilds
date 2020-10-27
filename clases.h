#pragma once
#pragma warning(disable : 4996)

class Archivo
{
	FILE* pf;
	int pos;
	char* ubicacion;
public:
	void setUbicacion(const char* _u)
	{
		ubicacion = new char(sizeof(_u));
		strcpy(ubicacion, _u);
		delete(_u);
	}
	//TODO: Que recibiria como parametros? idk
	//bool leerArchivo(Campeon obj);
	bool guardarArchivo();
	int buscarRegistro();
	bool sobreEscribir(int);
};

class Stat
{
private:
	float ataque;
	float vel_ataque;
	float poder_habilidad;
	float vida;
	float armor;
	float resistencia_magica;
public:
	Stat()
	{
		ataque = vel_ataque = poder_habilidad = vida = armor = resistencia_magica = 0;
	}
	//sets
	void setAtaque();
	void setVel_ataque();
	void setPoder_habilidad();
	void setVida();
	void setArmor();
	void setResistencia_magica();
	
	//gets
	float getAtaque();
	float getVel_ataque();
	float getPoder_habilidad();
	float getVida();
	float getArmor();
	float getResistencia_magica();
};

class Campeon : public Stat
{
private:
	// Cambie de string a char, pense que iba a ser mas facil copiar strings pero nop
	char nombre[15]={};
	Archivo archivo_dat = {};
	Vector2i cordImg = {};
	char estilo[20] = {};
	char dmg_type[15]={};
public:
	Campeon();
	//metodos
	// TODO: Falta definicion de guardarCampeon()
	bool guardarCampeon();
	//sets
	void setStats();
	void setUbicacionArchivo();
	void setNombre();
	void setEstilo();
	void setDmg();
	//gets
	char* getNombre();
	char* getEstilo();
	char* getDmg();
};

class Items : public Stat
{
private:
	RectangleShape rectangulo;
	Texture textura;
	Vector2u sizeTex;
public:
	Items();

	RectangleShape getRectangulo()
	{
		return rectangulo;
	}
};

class Conjunto
{
private:
	Campeon champ_conj;
	Items item_conj;
	int costo_total;

public:
	
	
};

class Menu
{
private:
	RenderWindow* ventana;
	int resolucionAncho;
	int resolucionAlto;
	Text titulo;
	Font fuente;
	RectangleShape botones[2];
public:
	Menu(int _resAlto = 600, int _resAncho = 800);

	void setOffsetTitulo(float x = 250, float y = 10, int chSize = 30);

	~Menu();

};





