#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/Archivo.h"
#include "../hpp/Campeon.h"
#include "../hpp/Item.h"
#include "../hpp/Conjunto_detalle.h"
#include "../hpp/Conjunto_cabecera.h"

class SubMenu_Backup : public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	Campeon* champ;
	Item* item;
	Conjunto_cabecera* conjcab;
	Conjunto_detalle* conjdet;
private:
	void inicializarBotones();
public:
	SubMenu_Backup();
	bool Create_Bkp();
	bool Restore_Bkp();
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	~SubMenu_Backup();
};

