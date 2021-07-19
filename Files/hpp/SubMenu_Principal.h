#pragma once
#include "../hpp/SubMenu.h"
class SubMenu_Principal : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	void inicializarBotones();
public:
	SubMenu_Principal();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~SubMenu_Principal();
};

