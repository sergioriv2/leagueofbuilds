
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"
#include "Item.h"

Conjunto_detalle::Conjunto_detalle()
{
	for (int i = 0; i < 10; i++)
	{
		idEarly[i] = -2;
		idMid[i] = -2;
	}

	for (int i = 0; i < 6; i++)
	{
		idLate[i] = -2;
	}
	setDetalle();
}

void Conjunto_detalle::setDetalle() {
	idDetalle = contarRegistros();
}

void Conjunto_detalle::imprimirEarly()
{
	Item it;
	int i = 0, pos = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : imprimirdetalle";
		return;
	}
	while (fread(&it, sizeof(Item), 1, pf))
	{
		if (idEarly[i] != -1 && idEarly[i] != -2)
		{
			pos = it.buscar_reg(idEarly[i]);
			it.mostrar_reg(pos, true);
		}
		i++;
	}
	fclose(pf);
}

void Conjunto_detalle::imprimirMid()
{
	Item it;
	int i = 0, pos = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : imprimirdetalle";
		return;
	}
	while (fread(&it, sizeof(Item), 1, pf))
	{
		if (idMid[i] != -1 && idMid[i] != -2)
		{
			pos = it.buscar_reg(idMid[i]);
			it.mostrar_reg(pos, true);
		}
		i++;
	}
	fclose(pf);
}

void Conjunto_detalle::imprimirLate()
{
	Item it;
	int i = 0, pos = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : imprimirdetalle";
		return;
	}
	while (fread(&it, sizeof(Item), 1, pf))
	{
		if (idLate[i] != -1 && idLate[i] != -2)
		{
			pos = it.buscar_reg(idLate[i]);
			it.mostrar_reg(pos, true);
		}
		i++;
	}
	fclose(pf);
}

void Conjunto_detalle::imprimirDetalle()
{
	imprimirEarly();
	imprimirMid();
	imprimirLate();
}


void Conjunto_detalle::setItems()
{
	setitemsEarly();
	setItemsMid();
	setItemsLate();
}

/*
void Conjunto_detalle::setidConjunto(int idConjunto) {
	this->idConjunto = idConjunto;
}
*/


void Conjunto_detalle::setitemsEarly() {
	std::cout << "Ingresar ID de items early game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idEarly[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}
void Conjunto_detalle::setItemsMid() {
	std::cout << "Ingresar ID de items mid game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idMid[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}
void Conjunto_detalle::setItemsLate() {
	std::cout << "Ingresar ID de items late game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> idLate[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}

int Conjunto_detalle::contarRegistros() {
	{
		
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
}
