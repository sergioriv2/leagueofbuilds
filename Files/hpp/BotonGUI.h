#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "../hpp/enums.h"
#include "../hpp/clsMouse.h"

extern sf::Font* _FUENTE;


class BotonGUI
{
private:
	sf::RectangleShape button;
	sf::Vector2i cordBtn;
	Estado estadoBtn;
	btnType tipoBtn;
	sf::Text texto;
	sf::Clock _Reloj;

	sf::SoundBuffer buffer; //Donde se carga el sonido
	sf::Sound sound; //Desde donde reproduzco el sonido

public:

	//CONSTRUCTORES
	BotonGUI();

	//METODOS
	void cmd(clsMouse& mouse);
	void update();

	//SETS

	//Setea la posicion de el titulo y el texto a la vez
	void setbothPos(float _x, float _y) {
		button.setPosition(_x, _y);
		texto.setPosition(_x + 10.0f, _y + 10.0f);
	}
	void setbtnPos(float _x, float _y) { button.setPosition(_x, _y); }
	void settxtPos(float _x, float _y) { texto.setPosition(_x, _y); }

	void setTextoString(const sf::String& string);
	void setBtnType(btnType _btn) { tipoBtn = _btn; }
	void setBtnEstado(Estado _btnState) { estadoBtn = _btnState; }
	void dibujarBotoncito(sf::RenderWindow& ventana) {
		ventana.draw(button);
		ventana.draw(texto);
	}
	void setSize(float x, float y) { button.setSize({ x, y }); }

	//GETS

	sf::Text getText() { return texto; }
	sf::Vector2i getVector2i() { return cordBtn; }
	sf::RectangleShape& getButton() { return button; }

	~BotonGUI();
};
