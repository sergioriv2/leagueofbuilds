#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <string>

using namespace sf;
using namespace std;

#include "GUI.h"
#include "BotonGUI.h"

///-------------------
//	METODOS MENU
///------------------

// PARTE GRAFICA CON SFML
Menu::Menu(int _resAlto, int _resAncho)
{
	titulo.setString("League of Builds");
	if(fuente.loadFromFile("resources/fuentes/Roboto-Medium.ttf") == 0) return;
	titulo.setFont(fuente);
	titulo.setCharacterSize(40);
	titulo.setStyle(sf::Text::Bold);
	titulo.setPosition(250.0f, 10.0f);
	titulo.setFillColor(sf::Color::White);

	//setOffsetTitulo();

	//Inicializaciones

	BotonGUI* btn;
	btn = new BotonGUI[5];

	//Tener en cuenta que cada boton es de 200x50, 20px de offset entre cada boton
	resolucionAlto = _resAlto;
	resolucionAncho = _resAncho;

	//0: MENU CHAMPS
	btn[0].setbothPos(280.0f, 100.0f);
	btn[0].setBtnType(btnType::CHAMPS);
	btn[0].setTextoString("Menu Campeones");
	//1: MENU ITEMS
	btn[1].setbothPos(280.0f,180.0f);
	btn[1].setBtnType(btnType::ITEMS);
	btn[1].setTextoString("Menu Items");
	//2: MENU CONJUNTOS
	btn[2].setbothPos(280.0f,260.0f);
	btn[2].setBtnType(btnType::CONJ);
	btn[2].setTextoString("Menu Conjuntos");
	//3: BACKUP
	btn[3].setbothPos(280.0f,340.0f);
	btn[3].setBtnType(btnType::BACKUP);
	btn[3].setTextoString("Menu Backups");
	//4: SALIR
	btn[4].setbothPos(280.0f,420.0f);
	btn[4].setBtnType(btnType::SALIR);
	btn[4].setTextoString("Salir");

	RenderWindow ventana(VideoMode(resolucionAncho, resolucionAlto), "League of Builds");

	while (ventana.isOpen())
	{
		Event eventos;

		while (ventana.pollEvent(eventos))
		{
			if (eventos.type == Event::Closed)
			{
				ventana.close();
			}
		}

		// Codigo

		//CMD De cada botoncito
		for (int i = 0; i < 4; i++)
		{
			btn[i].cmd(ventana);
		}

		//UPDATE De cada botoncito
		for (int i = 0; i < 4; i++)
		{
			btn[i].update();
		}

		ventana.clear(Color(14, 22, 33, 255));

		//DRAW De cada botoncito
		for (int i = 0; i < 4; i++)
		{
			ventana.draw(btn[i].getButton());
			ventana.draw(btn[i].getText());
		}

		ventana.draw(titulo);

		ventana.display();
	}
}

/*void Menu::setOffsetTitulo(float x, float y, int chSize)
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
*/
/*Items::Items()
{
	rectangulo.setSize(Vector2f(64.0f, 64.0f));
	textura.loadFromFile("resources/items_iniciales.png");
	sizeTex = textura.getSize();
	sizeTex.x /= 4;
	sizeTex.y /= 1;

	rectangulo.setTexture(&textura);
	rectangulo.setTextureRect(IntRect(sizeTex.x * 3, sizeTex.y * 0, sizeTex.x, sizeTex.y));
}*/