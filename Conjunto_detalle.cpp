
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
	setDetalle(0);
	estado = true;
}

bool Conjunto_detalle::guardarDetalle()
{
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_detalle.dat", "ab");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : guardarDetalle";
		return 0;
	}
	bool write = fwrite(this, sizeof * this, 1, pf);
	fclose(pf);
	return write;
}

void Conjunto_detalle::cargarDetalle(int id)
{
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_detalle.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : cargarDetalle";
		return;
	}
	fseek(pf, (sizeof * this) * id, 0);
	fread(this, sizeof * this, 1, pf);
	imprimirDetalle();
	fclose(pf);
}

void Conjunto_detalle::setDetalle(int n) {
	idDetalle = n;
	//idDetalle = contarRegistros();
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
	std::cout << "Early:" <<std::endl;
	imprimirEarly();
	std::cout << std::endl;
	std::cout << "Mid:" << std::endl;
	imprimirMid();
	std::cout << std::endl;
	std::cout << "Late:" << std::endl;
	imprimirLate();
}

void Conjunto_detalle::setItems()
{
	setitemsEarly();
	setItemsMid();
	setItemsLate();
}

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
		if (idMid[i] == -1) {
			return;
		}
	}
}

void Conjunto_detalle::setItemsLate() {
	std::cout << "Ingresar ID de items late game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> idLate[i];
		if (idLate[i] == -1) {
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

int Conjunto_detalle::getCostoEarly()
{
	Item it;
	int i = 0, pos = 0, costo = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostoEarly";
		return 0;
	}
	while (fread(&it, sizeof it, 1, pf))
	{
		if (idEarly[i] != -1 && idEarly[i] != -2)
		{
			pos = it.buscar_reg(idEarly[i]);
			costo += it.getCosto(pos);
		}
		i++;
	}
	fclose(pf);
	return costo;
}

int Conjunto_detalle::getCostoMid()
{
	Item it;
	int i = 0, pos = 0, costo = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostoEarly";
		return 0;
	}
	while (fread(&it, sizeof it, 1, pf))
	{
		if (idMid[i] != -1 && idMid[i] != -2)
		{
			pos = it.buscar_reg(idMid[i]);
			costo += it.getCosto(pos);
		}
		i++;
	}
	fclose(pf);
	return costo;
}

int Conjunto_detalle::getCostoLate()
{
	Item it;
	int i = 0, pos = 0, costo = 0;
	FILE* pf;
	pf = fopen("resources/items/itemsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostoEarly";
		return 0;
	}
	while (fread(&it, sizeof it, 1, pf))
	{
		if (idLate[i] != -1 && idLate[i] != -2)
		{
			pos = it.buscar_reg(idLate[i]);
			costo += it.getCosto(pos);
		}
		i++;
	}
	fclose(pf);
	return costo;
}

int Conjunto_detalle::getCostoTotal()
{
	int costoTotal = 0;
	costoTotal += getCostoEarly();
	costoTotal += getCostoMid();
	costoTotal += getCostoLate();
	return costoTotal;
}