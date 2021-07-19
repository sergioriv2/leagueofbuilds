#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/inputGUI.h"
#include "../hpp/Conjunto_cabecera.h"
#include "../hpp/Conjunto_detalle.h"
#include "../hpp/Archivo.h"
#include "../hpp/Campeon.h"
#include "../hpp/outputGUI.h"

class Conjuntos_Alta :public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	Conjunto_cabecera* conjcab;
	Conjunto_detalle* conjdet;
	bool* check;
	int lastIngreso;

	// Ventana champs -------

	sf::Text* _Titulo2;
	sf::RectangleShape* _BordeVentana2;
	outputGUI* outputWindow;
	sf::RenderWindow* g;
	sf::RenderWindow* ventana_Nueva;
	bool Champs;

	// Ventana items -------
	bool Items;
	int _ItemsAMostrar;

	int _CantidadPaginas;
	int _ChampsAMostrar;
	int _PagActual;

private:
	void inicializarBotones();
	void verificacionInput();
	bool validarChecks(bool checks[], int tam);
	bool* getCheck() { return check; }
	bool validarNum(std::string& num);
public:
	Conjuntos_Alta();

	void init_campeones();
	void update_campeones();
	void init_items();
	void update_items();

	void process_event(const sf::Event& e);

	void update(sf::RenderWindow& _Ventana) override;

	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Conjuntos_Alta();
};


