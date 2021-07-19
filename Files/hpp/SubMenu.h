#pragma once
#include "../hpp/BotonGUI.h"
#include "../hpp/headerGUI.h"
#include "../hpp/clsMouse.h"
#include "../hpp/enums.h"
#include <SFML/Graphics.hpp>

class SubMenu
{
protected:
	BotonGUI* _Botones;
	headerGUI* _Banner;
	sf::Text* _Titulo;
	clsMouse* _Mouse;
	sf::Clock* _Reloj;
	sf::RectangleShape* _BordeTitulo;
protected:
	virtual void inicializarBotones() = 0;
public:
	SubMenu();
	virtual void process_event(const sf::Event& e) {};
	virtual void update(sf::RenderWindow& _Ventana) = 0;
	virtual void dibujarEnVentana(sf::RenderWindow& _Ventana) = 0;
	virtual ~SubMenu();
};

