#pragma once
#include "SubMenu.h"
#include "inputGUI.h"
#include "Conjunto_cabecera.h"
#include "Conjunto_detalle.h"
#include "Archivo.h"

class Conjuntos_Alta :public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	Conjunto_cabecera* conjcab;
	Conjunto_detalle* conjdet;
	bool* check;
	int lastIngreso;
private:
	void inicializarBotones();
	void verificacionInput();
	bool validarChecks(bool checks[], int tam);
	bool* getCheck() { return check; }
	bool validarNum(std::string& num);
public:
	void process_event(const sf::Event& e);
	Conjuntos_Alta();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Conjuntos_Alta();
};


