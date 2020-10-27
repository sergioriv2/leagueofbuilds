#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <string>

using namespace sf;
using namespace std;

#include "clases.h"

///-------------------
//	METODOS MENU
///------------------

// PARTE GRAFICA CON SFML

Menu::Menu(int _resAlto, int _resAncho)
{
	setOffsetTitulo();

	resolucionAlto = _resAlto;
	resolucionAncho = _resAncho;
	ventana = new RenderWindow(VideoMode(resolucionAncho, resolucionAlto), "League of Builds");

	for (int i = 0; i < 2; i++)
	{
		botones[i].setSize(Vector2f(80, 50));
		botones[i].setOutlineColor(Color::Cyan);
		botones[i].setOutlineThickness(4);
	}

	botones[0].setPosition(Vector2f(5, 110));
	botones[1].setPosition(Vector2f(5, 220));
	

	while (ventana->isOpen())
	{
		Event eventos;

		while (ventana->pollEvent(eventos))
		{
			if (eventos.type == Event::Closed)
			{
				ventana->close();
			}
		}

		// Codigo

		ventana->clear(Color(1, 10, 19, 0));
		ventana->draw(titulo);

		for (int i = 0; i < 2; i++)
		{
			ventana->draw(botones[i]);
		}

		ventana->display();
	}
}

void Menu::setOffsetTitulo(float x, float y, int chSize)
{
	fuente.loadFromFile("resources/fuentes/Roboto-Medium.ttf");

	titulo.setString("League of Builds");
	titulo.setCharacterSize(chSize);
	titulo.setFont(fuente);
	titulo.setPosition(x, y);
	titulo.setLetterSpacing(1.2f);
	titulo.setOutlineColor(Color::Black);
	titulo.setOutlineThickness(2.0f);
}

Menu::~Menu()
{
	delete(ventana);
}

/// -----------------
///	METODOS ARCHIVO
/// -----------------


//TODO: Faltan definiciones de metodos



/// -----------------
///	METODOS STATS
/// -----------------

void Stat::setAtaque() 
{ 
	cout << "Ataque: ";
	cin >> ataque; 
}
void Stat::setVel_ataque() 
{ 
	cout << "Velocidad de ataque: ";
	cin >> vel_ataque;
}
void Stat::setPoder_habilidad()
{
	cout << "Poder de habilidad: ";
	cin >> poder_habilidad;
}
void Stat::setVida() {
	cout << "Vida: ";
	cin >> vida; 
}
void Stat::setArmor() {
	cout << "Armor: ";
	cin >> armor; 
}
void Stat::setResistencia_magica() {
	cout << "Resistencia magica: ";
	cin >> resistencia_magica; 
}

float Stat::getAtaque() { return ataque; };
float Stat::getVel_ataque() { return vel_ataque; }
float Stat::getPoder_habilidad() { return poder_habilidad; }
float Stat::getVida(){return vida;}
float Stat::getArmor(){return armor;}
float Stat::getResistencia_magica(){return resistencia_magica;}

/// -----------------
///	METODOS CAMPEON
/// -----------------

Campeon::Campeon() {
	Stat();

}


void Campeon::setUbicacionArchivo()
{
	archivo_dat.setUbicacion("resources/campeones.dat");
}

void Campeon::setNombre()
{
	cout << "Nombre: ";
	cin.ignore();
	cin.getline(nombre, 15);

}
void Campeon::setEstilo()
{
	cout << "Estilo: ";
	//cin.ignore();
	cin.getline(estilo, 20);

}
void Campeon::setDmg()
{
	cout << "Tipo de danio: ";
	//cin.ignore();
	cin.getline(dmg_type, 15);
}

void Campeon::setStats()
{
	setAtaque();
	setVel_ataque();
	setPoder_habilidad();
	setVida();
	setArmor();
	setResistencia_magica();
}

char* Campeon::getNombre() { return nombre; }
char* Campeon:: getEstilo() { return estilo; }
char* Campeon::getDmg() { return dmg_type; }


/// -----------------
///	METODOS ITEMS
/// -----------------

Items::Items()
{
	rectangulo.setSize(Vector2f(64.0f, 64.0f));
	textura.loadFromFile("resources/items_iniciales.png");
	sizeTex = textura.getSize();
	sizeTex.x /= 4;
	sizeTex.y /= 1;

	rectangulo.setTexture(&textura);
	rectangulo.setTextureRect(IntRect(sizeTex.x * 3, sizeTex.y * 0, sizeTex.x, sizeTex.y));
}