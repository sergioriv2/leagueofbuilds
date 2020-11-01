#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <string>

using namespace sf;
using namespace std;

#include "GUI.h"

///-------------------
//	METODOS MENU
///------------------

// PARTE GRAFICA CON SFML

/*Menu::Menu(int _resAlto, int _resAncho)
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
///	METODOS CAMPEON
/// -----------------



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
}*/