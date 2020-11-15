
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"
#include "Item.h"
/*
Conjunto_detalle::Conjunto_detalle()
{
	setDetalle(0);
	estado = true;
}

bool Conjunto_detalle::guardarDetalle(int pos)
{
	FILE* pf;
	bool write;
	if (pos == -1)
	{
		pf = fopen("resources/conjuntos/conjunto_detalle.dat", "ab");
		if (pf == NULL)
		{
			std::cout << "conjunto detalle : guardarDetalle";
			return 0;
		}
		write = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
	}
	else
	{
		pf = fopen("resources/conjuntos/conjunto_detalle.dat", "rb+");
		if (pf == NULL)
		{
			std::cout << "conjunto detalle : guardarDetalle";
			return 0;
		}
		fseek(pf, (sizeof * this) * pos, 0);
		write = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
	}

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
	if(this->estado) this->imprimirDetalle();
	fclose(pf);
}

void Conjunto_detalle::setDetalle(int n) {
	idDetalle = n;
	//idDetalle = contarRegistros();
}

void Conjunto_detalle::imprimirEarly()
{
	Item it;
	int pos = 0;
	for(int i=0; i<10; i++)
	{
		if (idEarly[i] != -1 && idEarly[i] != -2)
		{
			pos = it.buscar_reg(idEarly[i]);
			it.mostrar_reg(pos, true);
		}
	}
}

void Conjunto_detalle::imprimirMid()
{
	Item it;
	int pos = 0;

	for (int i = 0; i < 10; i++)
	{

		if (idMid[i] != -1 && idMid[i] != -2)
		{
			pos = it.buscar_reg(idMid[i]);
			it.mostrar_reg(pos, true);
		}
	}
		
}

void Conjunto_detalle::imprimirLate()
{
	Item it;
	int pos = 0;

	for (int i = 0; i < 6; i++)
	{
		if (idLate[i] != -1 && idLate[i] != -2)
		{
			pos = it.buscar_reg(idLate[i]);
			it.mostrar_reg(pos, true);
		}
	}
	
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

	for (int i = 0; i < 10; i++)
	{
		idEarly[i] = -2;
	}

	std::cout << "Ingresar ID de items early game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idEarly[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}

void Conjunto_detalle::setItemsMid() {

	for (int i = 0; i < 10; i++)
	{
		idMid[i] = -2;
	}

	std::cout << "Ingresar ID de items mid game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idMid[i];
		if (idMid[i] == -1) {
			return;
		}
	}
}

void Conjunto_detalle::setItemsLate() {

	for (int i = 0; i < 6; i++)
	{
		idLate[i] = -2;
	}

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
*/