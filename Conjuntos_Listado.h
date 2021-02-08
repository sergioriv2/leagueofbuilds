#pragma once
#include "SubMenu.h"
#include "Conjunto_cabecera.h"
#include "Conjunto_detalle.h"
#include "Archivo.h"
#include "outputGUI.h"
#include <iostream>
#include <string>

class Conjuntos_Listado : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	outputGUI* outputWindow;
	sf::Text* nombconj;
	sf::Text* idconj;
	sf::Text* idchamp;
	int lastIngresoOutput;
	int actualPage;
	int cantidadPagListado;
	int conjsaMostrar;
private:
	void inicializarBotones();
	void leerArchivos();
public:
	Conjuntos_Listado();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Conjuntos_Listado();
};

