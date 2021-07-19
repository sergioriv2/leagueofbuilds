#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/inputGUI.h"
#include "../hpp/outputGUI.h"
#include "../hpp/Campeon.h"

class Campeones_Mod :public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	outputGUI* outputWindow;
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
	Campeones_Mod() {};
	Campeones_Mod(outputGUI& _Champ);
	void process_event(const sf::Event& e);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Campeones_Mod();
};

