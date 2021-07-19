#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "../hpp/claseIngresoTxt.h"
#include "../hpp/clsMouse.h"
#include "../hpp/Item.h"
#include "../hpp/Campeon.h"
#include "../hpp/clsMouse.h"
#include "../hpp/enums.h"
#include <Windows.h>
#include "../hpp/Archivo.h"
#include "../hpp/Conjunto_cabecera.h"
#include "../hpp/Conjunto_detalle.h"

class Leyenda
{
private:
	sf::RectangleShape cajita;
	sf::Text renglon1;
	sf::Text renglon2;
	sf::Text renglon3;
public:
	Leyenda() {
	}
	void leyendaini(sf::Font& fuente)
	{
		renglon1.setFont(fuente);
		renglon2.setFont(fuente);
		renglon3.setFont(fuente);

		renglon1.setCharacterSize(15);
		renglon2.setCharacterSize(15);
		renglon3.setCharacterSize(15);

		renglon1.setFillColor(sf::Color::White);
		renglon2.setFillColor(sf::Color::White);
		renglon3.setFillColor(sf::Color::White);
	}
	void draw(sf::RenderWindow* ventana)
	{
		ventana->draw(cajita);
		ventana->draw(renglon1);
		ventana->draw(renglon2);
		ventana->draw(renglon3);
	}

	void setPosition() {
		cajita.setSize({ 400, 200 });
		cajita.setFillColor(sf::Color(11, 17, 26, 255));
		cajita.setOutlineColor(sf::Color::White);
		cajita.setOutlineThickness(1.0f);
		cajita.setPosition(330.0f, 350.0f);

		renglon1.setString("TIPOS DE DANIO: 1.AD, 2.AP");
		renglon2.setString("TIPOS DE ESTILO: 1.LUCHADOR 2.MAGO");
		renglon3.setString("3.ASESINO 4.SOPORTE 5.TANQUE 6.TIRADOR");

		renglon1.setPosition(340.0f, 380.0f);
		renglon2.setPosition(340.0f, 440.0f);
		renglon3.setPosition(340.0f, 460.0f);
	}
};
