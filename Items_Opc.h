#pragma once
#include "SubMenu.h"
#include "iconosListado.h"
#include "outputGUI.h"
#include "Item.h"

class Items_Opc: public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	iconosListado* encabezadoOutput;
	outputGUI* _ItemAux;
	void inicializarBotones();
public:
	Items_Opc() {};
	Items_Opc(outputGUI& _Item);
	void update(sf::RenderWindow& _Ventana) override;
	void baja();
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Items_Opc();
};

