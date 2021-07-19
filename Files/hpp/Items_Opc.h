#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/iconosListado.h"
#include "../hpp/outputGUI.h"
#include "../hpp/Item.h"

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

