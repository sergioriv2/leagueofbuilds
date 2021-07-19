#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/inputGUI.h"
#include "../hpp/outputGUI.h"
#include "../hpp/Conjunto_cabecera.h"
#include "../hpp/Conjunto_detalle.h"
#include "../hpp/Archivo.h"

class Conjuntos_Mod : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	inputGUI* _InputWindow;
	outputGUI* _AuxConj;
	Campeon* champ;
	bool* check;
	int lastIngreso;
	Conjunto_cabecera* conjcab;
	Conjunto_detalle* conjdet;

private:
	void inicializarBotones();
	void verificacionInput();
	bool validarChecks(bool checks[], int tam);
	bool* getCheck() { return check; }
	bool validarNum(std::string& num);
public:
	Conjuntos_Mod() {};
	Conjuntos_Mod(outputGUI& _Conj);
	void process_event(const sf::Event& e);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~Conjuntos_Mod();
};




