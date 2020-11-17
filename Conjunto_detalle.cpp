
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
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
	int pos = 0;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (idEarly[i] != -1 && idEarly[i] != -2)
		{
			it.setID(idEarly[i]);
			pos = architem.buscarRegistro(it);

			if (pos == -2)
			{
				std::cout << "Error abrir archivo (early)" << std::endl;

			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error encontrar el item (early)" << std::endl;
				}
				else
				{
					architem.leerRegistro(it, pos);
					std::cout << i+1 << "." << it.getNombre() << std::endl;
				}
			}
		}
	}
}

void Conjunto_detalle::imprimirMid()
{
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Item it;
	int pos = 0;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (idMid[i] != -1 && idMid[i] != -2)
		{
			it.setID(idMid[i]);
			pos = architem.buscarRegistro(it);

			if (pos == -2)
			{
				std::cout << "Error abrir archivo (Mid)" << std::endl;

			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error encontrar el item (Mid)" << std::endl;
				}
				else
				{
					architem.leerRegistro(it, pos);
					std::cout << i+1 << "."<< it.getNombre() << std::endl;
				}
			}
		}
	}
		
}

void Conjunto_detalle::imprimirLate()
{
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Item it;
	int pos = 0;
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		if (idLate[i] != -1 && idLate[i] != -2)
		{
			it.setID(idLate[i]);
			pos = architem.buscarRegistro(it);

			if (pos == -2)
			{
				std::cout << "Error abrir archivo (Late)" << std::endl;

			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error encontrar el item (Late)" << std::endl;
				}
				else
				{
					architem.leerRegistro(it, pos);
					std::cout << i+1 << "." <<  it.getNombre() << std::endl;
				}
			}
		}
	}
	
}

void Conjunto_detalle::Mostrar()
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


bool Conjunto_detalle::Cargar()
{
	setitemsEarly();
	setItemsMid();
	setItemsLate();
	return true;
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

bool Conjunto_detalle::Modificar(int ID)
{
	return true;
}

bool Conjunto_detalle::BajaVirtual(int ID)
{
	return true;
}