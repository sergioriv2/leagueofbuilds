#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "clases.h"
#include "menu_desarrollador.h"

int Menu_Desarrollador::menuPrincipal()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE DESARROLLADOR" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Datos campeones" << endl;
	cout << "2. Datos items " << endl;
	cout << "3. Datos conjuntos" << endl;
	cout << "0. Salir" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 0:
		return 0;
		break;
	case 1: menuCampeones();
		break;
	case 2:
		break;
	}
	return opc;
}

void Menu_Desarrollador::menuCampeones()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE CAMPEONES" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar campeones" << endl;
	cout << "2. Borrar campeones " << endl;
	cout << "3. Editar campeones" << endl;
	cout << "4. Mostrar campeones" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarCampeones();
		break;
	case 2:
		break;
	case 0:
		return;
		break;
	}

}

void Menu_Desarrollador::agregarCampeones()
{
	Campeon* champ;
	champ = new Campeon;

	champ->setNombre();
	champ->setEstilo();
	champ->setDmg();
	champ->setStats();

	
	// TODO: Ver alguna forma de como guardar obj champ con la clase archivo
	return;
	delete(champ);
}