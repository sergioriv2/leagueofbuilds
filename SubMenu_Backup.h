#pragma once
#include "SubMenu.h"
#include "Archivo.h"
#include "Campeon.h"
#include "Item.h"
#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"

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

