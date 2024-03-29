#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/iconosListado.h"
#include "../hpp/outputGUI.h"
#include "../hpp/Item.h"

class Items_Listado : public SubMenu
{
private:
	int _CantidadPaginas;
	int _PagActual;
	int _ItemsAMostrar;
	int* lastIngresoOutput;
	sf::RectangleShape* _BordeVentana;
	iconosListado* _EncabezadoOutput;
	outputGUI* outputWindow;
private:
	void cargarArchivos();
	void inicializarBotones() {};
public:
	Items_Listado();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Items_Listado();
};

