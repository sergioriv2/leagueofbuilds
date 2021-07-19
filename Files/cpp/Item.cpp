#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "../hpp/Item.h"
#include "../hpp/Archivo.h"

const char* UBICACION_ITEMS = "resources/items/itemsdata.dat";

Item::Item() :Stat()
{
	costo = 0, id = 0;
	estado = true;
}

Item::Item(const char* _nombre) :Stat(_nombre)
{
	costo = id = 0;
	estado = true;
}

void Item::setEstado(bool _estado)
{
	estado = _estado;
}

void Item::setCosto()
{
	do
	{
		cout << "Costo: ";
		cin >> costo;
	} while (!validarCosto(costo));
}

bool Item::Cargar()
{
	Archivo arch(UBICACION_ITEMS, sizeof(Item));

	setStats(0);
	if (nombre[0] == '0') return false;
	setCosto();

	id = arch.getCantidadRegistros() + 1;

	estado = true;
	return true;
}

void Item::Mostrar()
{
	if (estado)
	{
		getStats(0);
		cout << "Costo: " << costo << endl;
		cout << "ID: " << id << endl;
		cout << "-------------------------" << endl << endl;
	}
}

bool Item::BajaVirtual(int ID)
{
	int b;
	Archivo arch("resources/items/itemsdata.dat", sizeof(Item));
	Item item;
	arch.leerRegistro(item, ID);

	item.setEstado(false);

	b = arch.grabarRegistro(item, ID, LecturaEscritura);
	if (b)return true;
	else return false;
}

bool Item::Modificar(int pos)
{
	Archivo arch(UBICACION_ITEMS, sizeof(Item));
	Item item;
	arch.leerRegistro(item, pos);

	int opc;
	cout << endl;
	cout << "0 SALIR" << endl;
	cout << "1 NOMBRE" << endl;
	cout << "2 ATAQUE" << endl;
	cout << "3 VELOCIDAD DE ATAQ" << endl;
	cout << "4 PODER DE HABILIDAD" << endl;
	cout << "5 VIDA" << endl;
	cout << "6 ARMOR" << endl;
	cout << "7 RESISTENCIA MAGICA" << endl;
	cout << "8 PROBABILIDAD DE CRITICO" << endl;
	cout << "9 MANA" << endl;
	cout << "10 COSTO" << endl << endl;
	cout << "Elegir que modificar: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 0: return false;
	case 1:
		item.setNombre();
		break;
	case 2:
		item.setAtaque();
		break;
	case 3:
		item.setVel_ataque();
		break;
	case 4:
		item.setPoder_habilidad();
		break;
	case 5:
		item.setVida();
		break;
	case 6:
		item.setArmor();
		break;
	case 7:
		item.setResistencia_magica();
		break;
	case 8:
		item.setCrit_chance();
		break;
	case 9:
		item.setMana();
		break;
	case 10:
		item.setCosto();
		break;
	default:return false;
	}
	int b = arch.grabarRegistro(item, pos, LecturaEscritura);
	if (b == -1) return false;
	else
	{
		if (b) return true;
		else return false;
	}
}

bool Item::validarCosto(int costo) {
	if (costo < 0) {
		cout << "No se permiten costo negativo" << endl;
		return false;
	}
	return true;
}