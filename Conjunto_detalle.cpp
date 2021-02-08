#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include <string>
#include "Conjunto_detalle.h"
#include "Item.h"
#include "Archivo.h"

Conjunto_detalle::Conjunto_detalle()
{
	setDetalle(0);
	estado = true;
}

void Conjunto_detalle::setDetalle(int n) {
	idDetalle = n;
	//idDetalle = contarRegistros();
}

void Conjunto_detalle::imprimirEarly()
{
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Item it;
	for (int i = 0; i < 6; i++) {
		if (idEarly[i] > 0)
		{
			architem.leerRegistro(it, idEarly[i] - 1);
			std::cout << i + 1 << "." << it.getNombre() << std::endl;
		}
	}
}

void Conjunto_detalle::imprimirMid()
{
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Item it;
	for (int i = 0; i < 6; i++) {
		if (idMid[i] > 0)
		{
			architem.leerRegistro(it, idMid[i] - 1);
			std::cout << i + 1 << "." << it.getNombre() << std::endl;
		}
	}
}

void Conjunto_detalle::imprimirLate()
{
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Item it;
	for (int i = 0; i < 6; i++) {
		if (idLate[i] > 0)
		{
			architem.leerRegistro(it, idLate[i] - 1);
			std::cout << i + 1 << "." << it.getNombre() << std::endl;
		}
	}
}

void Conjunto_detalle::Mostrar()
{
	std::cout << "Early:" << std::endl;
	imprimirEarly();

	std::cout << std::endl;
	std::cout << "Mid:" << std::endl;
	imprimirMid();
	std::cout << std::endl;
	std::cout << "Late:" << std::endl;
	imprimirLate();
}

bool Conjunto_detalle::Cargar()
{
	setitemsEarly();
	setItemsMid();
	setItemsLate();

	return true;
}

void Conjunto_detalle::setitemsEarly() {
	for (int i = 0; i < 6; i++)
	{
		idEarly[i] = 0;
	}
	std::cout << "Ingresar ID de items early game(0 Para finalizar): " << std::endl;

	for (int i = 0; i < 6; i++) {
		std::cin >> idEarly[i];
		if (idEarly[i] == 0) {
			return;
		}
	}
}

void Conjunto_detalle::setItemsMid() {
	for (int i = 0; i < 6; i++)
	{
		idMid[i] = 0;
	}

	std::cout << "Ingresar ID de items mid game(0 Para finalizar): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> idMid[i];
		if (idMid[i] == 0) {
			return;
		}
	}
}

void Conjunto_detalle::setItemsLate() {
	for (int i = 0; i < 6; i++)
	{
		idLate[i] = 0;
	}

	std::cout << "Ingresar ID de items late game(0 Para finalizar): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> idLate[i];
		if (idLate[i] == 0) {
			return;
		}
	}
}

int Conjunto_detalle::contarRegistros() {
	FILE* pf;
	int c = 0;
	pf = fopen("resources/conjuntos/conjunto_detalle.dat", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	while (fread(this, sizeof(*this), 1, pf) == 1) c++;
	fclose(pf);
	return c;
}
bool Conjunto_detalle::iditemcheck(int iditem) {
	Archivo architems("resources/items/itemsdata.dat", sizeof(Item));
	int i = 0;
	Item items;

	if (iditem == 0) return true;
	while (architems.leerRegistro(items, i++))
	{
		if (items.getId() == iditem && items.getEstado()) return true;
	}

	std::cout << "ID INCORRECTO" << std::endl;
	return false;
}

bool Conjunto_detalle::Modificar(int ID)
{
	return true;
}

bool Conjunto_detalle::BajaVirtual(int ID)
{
	return true;
}