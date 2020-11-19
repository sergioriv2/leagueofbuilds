#include <SFML/Graphics.hpp>
#include <iostream>
#include "BotonGUI.h"
#include "GUI.h"

void BotonGUI::cmd(sf::RenderWindow& window)
{
	//Esto imprime donde esta el mouse en la ventana, con esto me puedo guiar para poder acomodar distintas cosas en pantalla
	std::cout << "X: " << sf::Mouse::getPosition(window).x << "\t\t";
	std::cout << sf::Mouse::getPosition(window).y << std::endl;

	//Animaciones e inputs de los botones
	//Dependiendo que tipo de boton va a mostrar distintos comportamientos 
	switch (tipoBtn)
	{
	case DEFAULT:
		break;
	case CHAMPS:
		texto.setPosition(5.0f, 113.0f);
		if (sf::Mouse::getPosition(window).y >= 100 && sf::Mouse::getPosition(window).y <= 150)
		{
			if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 200)
			{
				estadoBtn = Estado::CAMBIO_COLOR;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//Codigo ------
				}
			}
		}
		break;
	case ITEMS:
		texto.setPosition(7.0f, 193.0f);
		if (sf::Mouse::getPosition(window).y >= 180 && sf::Mouse::getPosition(window).y <= 230)
		{
			if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 200)
			{
				estadoBtn = Estado::CAMBIO_COLOR;
			}
		}
		break;
	case CONJ:
		texto.setPosition(9.0f, 273.0f);
		if (sf::Mouse::getPosition(window).y >= 260 && sf::Mouse::getPosition(window).y <= 310)
		{
			if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 200)
			{
				estadoBtn = Estado::CAMBIO_COLOR;
			}
		}
		break;
	case BACKUP:
		texto.setPosition(11.0f, 353.0f);
		if (sf::Mouse::getPosition(window).y >= 340 && sf::Mouse::getPosition(window).y <= 390)
		{
			if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 200)
			{
				estadoBtn = Estado::CAMBIO_COLOR;
			}
		}
		break;
	case SALIR:
		if (sf::Mouse::getPosition(window).y >= 420 && sf::Mouse::getPosition(window).y <= 470)
		{
			if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).x <= 200)
			{
				estadoBtn = Estado::CAMBIO_COLOR;
			}
		}
		break;
	case ADD_CHAMP:
		break;
	case MOD_CHAMP:
		break;
	case DEL_CHAMP:
		break;
	case LIST_CHAMP:
		break;
	case ADD_ITEM:
		break;
	case MOD_ITEM:
		break;
	case DEL_ITEM:
		break;
	case LIST_ITEM:
		break;
	default:
		break;
	}
}

void BotonGUI::update()
{
	switch (estadoBtn)
	{
	case CAMBIO_COLOR:
		button.setFillColor(sf::Color(39, 46, 52, 255));
		estadoBtn = Estado::NINGUNO;
		break;
	case NINGUNO:
		button.setFillColor(sf::Color(30, 35, 40, 255));
		break;
	}
}

void BotonGUI::setTextoString(const sf::String& string)
{
	texto.setString(string);
}