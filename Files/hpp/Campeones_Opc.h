#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/outputGUI.h"
#include "../hpp/iconosListado.h"
#include "../hpp/Campeon.h"
class Campeones_Opc : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	iconosListado* encabezadoOutput;
	outputGUI* _ChampAux;
	void inicializarBotones();
public:
	Campeones_Opc() {};
	Campeones_Opc(outputGUI& _Champ);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	void baja();
	~Campeones_Opc();
};

