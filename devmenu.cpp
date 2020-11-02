#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "devmenu.h"
#include "Stat.h"
#include "Campeon.h"
#include "Item.h"

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
	case 2: menuItems();
		break;
	case 3:// menuConjuntos();
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
		eliminarCampeon();
		break;
	case 3:
		modificarCampeon();
		break;
	case 4:
		mostrarCampeones();
		break;
	case 0:
		return;
		break;
	}
	
}

void Menu_Desarrollador::agregarCampeones()
{
	Campeon champ;

	
	champ.cargarCampeon();

	if (champ.guardarCampeon())
	{
		cout << "Se guardo sin errores" << endl;
	}
	else
	{
		cout << "Error al guardar" << endl;
	}

	system("pause");
	return;
	
}

void Menu_Desarrollador::mostrarCampeones()
{
	Campeon champ;
	
	champ.mostrarCampeones();

	system("pause");
	return;
}

void Menu_Desarrollador::modificarCampeon() {
	
	Campeon champ;
	int ID,POS,opc2;
	char opc;
	cout << "Ingresar ID del campeon que se desea modificar: " << endl;
	cin >> ID;
	POS = champ.searchPos(ID);//Busco si existe;
	if (POS == -1) {
		cout << "No se ha encontrado un campeon con esa ID" << endl;// Si no existe me salgo
		return;
	}
	if (champ.leerCampeon(POS)==false) {
		cout << "No se pudo leer el registro" << endl;
		return;
	}
	cout << "Se encontro el siguiente campeon " << endl;
	champ.mostrarCampeon();

	cout << "Desea modificarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		cout << "Elija lo que desea modificar " << endl;

		cout << "1 NOMBRE" << endl;
		cout << "2 ATAQUE" << endl;
		cout << "3 VELOCIDAD DE ATAQ"<< endl;
		cout << "4 PODER DE HABILIDAD" << endl;
		cout << "5 VIDA" << endl;
		cout << "6 ARMOR" << endl;
		cout << "7 RESISTENCIA MAGICA" << endl;
		cout << "8 PROBABILIDAD DE CRITICO" << endl;
		cout << "9 MANA" << endl;
		cin >> opc2;
		champ.modify(POS, opc2);
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
	
}

void Menu_Desarrollador::eliminarCampeon() {
	Campeon champ;
	int ID, POS;
	char opc;
	cout << "Ingresar ID del campeon que se desea modificar: " << endl;
	cin >> ID;
	POS = champ.searchPos(ID);//Busco si existe;
	if (POS == -1) {
		cout << "No se ha encontrado un campeon con esa ID" << endl;// Si no existe me salgo
		return;
	}
	cout << "Se encontro el siguiente campeon " << endl;
	champ.mostrarCampeon();

	cout << "Desea eliminarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		FILE* p;

		p = fopen("resources/campeones/champsdata.dat", "rb+");
		if (p == NULL) {
			cout << "Error abriendo champsdata.dat " << endl;
			return;
		}
		fseek(p, sizeof(Campeon) * POS, 0);
		champ.setEstadoFalse(); 
		fwrite(&champ, sizeof(Campeon), 1, p);
		fclose(p);
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
}

void Menu_Desarrollador::menuItems()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE ITEMS" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar items" << endl;
	cout << "2. Borrar items " << endl;
	cout << "3. Editar items" << endl;
	cout << "4. Mostrar items" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarItems();
		break;
	case 2:
		bajaItems();
		break;
	case 3:
		editarItems();
		break;
	case 4:
		mostrarItems();
		break;
	case 0:
		return;
		break;
	}
}

void Menu_Desarrollador::agregarItems()
{
	Item obj;

	obj.cargarItem();
	if (obj.guardar())
	{
		cout << "Se guardo sin errores" << endl;
	}
	else
	{
		cout << "Error al guardar" << endl;
	}
	system("pause");
	return;
}

void Menu_Desarrollador::bajaItems()
{
	Item obj;

	if (obj.baja())
	{
		cout << "Se dio de baja correctamente" << endl;
	}
	else
	{
		cout << "Error al dar de baja " << endl;
	}

	system("pause");
}

void Menu_Desarrollador::editarItems()
{
	Item obj;
	
	obj.editar();
	system("pause");
}

void Menu_Desarrollador::mostrarItems()
{
	Item obj;

	obj.mostrar_registros();
	system("pause");
	return;
}
