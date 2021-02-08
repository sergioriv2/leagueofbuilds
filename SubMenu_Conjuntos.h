#pragma once
#include <SFML/Graphics.hpp>
#include "SubMenu.h"

class SubMenu_Conjuntos : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	void inicializarBotones();
public:
	SubMenu_Conjuntos();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~SubMenu_Conjuntos();
};

