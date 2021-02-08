#pragma once
#include "SubMenu.h"

class SubMenu_Campeones : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	void inicializarBotones();
public:
	SubMenu_Campeones();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~SubMenu_Campeones();
};

