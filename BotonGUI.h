#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "enums.h"
#include "clsMouse.h"

class BotonGUI
{
private:
	sf::RectangleShape button;
	sf::Vector2i cordBtn;
	Estado estadoBtn;
	btnType tipoBtn;
	sf::Font fuente;
	sf::Text texto;
public:

	//CONSTRUCTORES
	BotonGUI()
	{
		tipoBtn = btnType::BTN_DEFAULT;
		estadoBtn = Estado::NINGUNO;
		//Pongo todo lo que tenga que ver con texto
		if (fuente.loadFromFile("resources/fuentes/Roboto-Medium.ttf") == 0) return; // SI PASA ESTO, CAMBIA EL PROYECTO DE DEBUG A RELEASE
		texto.setFont(fuente);
		texto.setFillColor(sf::Color::White);
		texto.setCharacterSize(18);

		//Luego todo lo demas con la posicion y color del rectangulo que seria el boton
		
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setSize(sf::Vector2f(180.0f, 50.0f));
		button.setOutlineThickness(2.0f);
		button.setOutlineColor(sf::Color(6, 150, 170, 255));
		button.setPosition(0, 0);
		cordBtn.x = 0;
		cordBtn.y = 0;
	}

	//METODOS
	void cmd(clsMouse &mouse, sf::RenderWindow& window, EstadoMenu* state, bool* p);
	void update(sf::RenderWindow& window);

	//SETS

	//Setea la posicion de el titulo y el texto a la vez
	void setbothPos(float _x, float _y) {
		button.setPosition(_x, _y); 
		texto.setPosition(_x + 10.0f , _y+10.0f);
	}
	void setbtnPos(float _x, float _y) { button.setPosition(_x, _y); }
	void settxtPos(float _x, float _y) { texto.setPosition(_x, _y); }

	void setTextoString(const sf::String& string);
	void setBtnType(btnType _btn) { tipoBtn = _btn; }
	void setBtnEstado(Estado _btnState) { estadoBtn = _btnState; }
	void dibujarBotoncito(sf::RenderWindow& ventana){
		ventana.draw(button);
		ventana.draw(texto);
	}
	void setSize(float x, float y) { button.setSize({ x, y }); }

	
	//GETS

	sf::Text getText() { return texto; }
	sf::Vector2i getVector2i() { return cordBtn; }
	sf::RectangleShape getButton() { return button; }
};
