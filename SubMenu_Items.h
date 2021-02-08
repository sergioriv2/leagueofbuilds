#pragma once
#include "SubMenu.h"
class SubMenu_Items : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	void inicializarBotones();
public:
	SubMenu_Items();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~SubMenu_Items();
};

