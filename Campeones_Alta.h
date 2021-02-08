#pragma once
#include "Archivo.h"
#include "SubMenu.h"
#include "inputGUI.h"
#include "Campeon.h"

class Campeones_Alta : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	Campeon* champ;
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
	Campeones_Alta();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Campeones_Alta();
};

