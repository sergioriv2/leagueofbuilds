#pragma once
#include <SFML/Graphics.hpp>
#include "claseIngresoTxt.h"
#include "clsMouse.h"
//CLASE QUE CUMPLE CON LA FUNCION DE CREAR UNA CAJA DE TEXTO CON UN SUBTITULO

class inputGUI
{
private:

	sf::RectangleShape cajaInput;
	sf::Text subtitulo;
	TextBox ingreso;
	int id;
	float offset = 30; // Offset entre el subtitulo y la caja
	int idlastSelected = -1;

public:
	inputGUI() {};
	inputGUI(float posY);

	//GETS

	sf::RectangleShape getRectangleShape() { return cajaInput; }
	sf::Text getText() { return subtitulo; }
	int getlastSelected() { return idlastSelected; }
	std::string getTextoIngreso() { return ingreso.getText().c_str(); }

	//SETS
	void setSizeRectangulo(float x, float y) { cajaInput.setSize({ x, y }); }
	//SETEA LA POSICION TANTO DEL SUBTITULO COMO DE LA CAJA EN LA VENTANA SEGUN LOS PARAMETROS QUE SE LE MANDEN
	void setPos(float x, float y)
	{
		subtitulo.setPosition(x, y);
		cajaInput.setPosition(x, y + 30);
		ingreso.setPosition({ x + 5, y + 38 });
	}

	void setStringSubtitulo(const char* _subtitulo) { subtitulo.setString(_subtitulo); }
	void setID(int _id) { id = _id; }
	void setLimiteIngreso(int lim);
	void setSelected(bool sel) { ingreso.setSelected(sel); }
	void setTextoIngreso(std::string _textIng) { ingreso.setTexto(_textIng); }

	//METODOS

	void draw(sf::RenderWindow& ventana)
	{
		ventana.draw(cajaInput);
		ventana.draw(subtitulo);
		ingreso.drawTo(ventana);
	}
	void setColor(sf::Color colorcito);
	void callEventoIngreso(sf::Event evento);
	void comandoInput(clsMouse* mouse, int*);
};
