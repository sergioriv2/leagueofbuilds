#pragma once
#include "SubMenu.h"
#include "inputGUI.h"
#include "Item.h"
#include "Archivo.h"

class Items_Alta :public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	Item* item;
	bool* check;
	int lastIngreso;
private:
	void inicializarBotones();
	void verificacionInput();
	bool validarChecks(bool checks[], int tam);
	bool* getCheck() { return check; }
	bool validarNum(std::string& num);
public:
	Items_Alta();
	void process_event(const sf::Event& e);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Items_Alta();
};

