#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/iconosListado.h"
#include "../hpp/Campeon.h"
#include "../hpp/Archivo.h"
#include "../hpp/outputGUI.h"

class Campeones_Listado : public SubMenu
{
private:
	int _CantidadPaginas;
	int _PagActual;
	int _ChampsAMostrar;
	int* lastIngresoOutput;
	sf::RectangleShape* _BordeVentana;
	iconosListado* _EncabezadoOutput;
	outputGUI* outputWindow;
private:
	void cargarArchivos();
	void inicializarBotones() {};
public:
	Campeones_Listado();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Campeones_Listado();
};

