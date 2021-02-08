#pragma once
#include "SubMenu.h"
#include "inputGUI.h"
#include "Item.h"
#include "Archivo.h"
#include "outputGUI.h"
class Item_Mod : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	outputGUI* outputWindow;
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
	Item_Mod() {};
	Item_Mod(outputGUI& _Item);
	void process_event(const sf::Event& e);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Item_Mod();
};

