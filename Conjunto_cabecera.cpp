#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"
#include "Campeon.h"




Conjunto_cabecera::Conjunto_cabecera()
{
	setidCampeon();
	setidConjunto();
	det.setItems();

	//setCostototal();
}


void Conjunto_cabecera::getDetalle()
{
	det.imprimirDetalle();
}

int Conjunto_cabecera::buscaridChamp(int _id)
{
	FILE* pf;
	int pos = 0;
	Campeon* pchamp;
	pchamp = new Campeon;
	pf = fopen("resources/campeones/champsdata.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto cabecera : buscarnombrechamp";
		return -1;
	}
	while (fread(pchamp, sizeof(Campeon), 1, pf))
	{
		if (_id == pchamp->getID() && pchamp->getEstado())
		{
			return pos;
		}
		pos++;
	}
	fclose(pf);
	delete pchamp;
	return -1;
}

void Conjunto_cabecera::setidConjunto() {
	idConjunto = contarRegistros();
}

void Conjunto_cabecera::setidCampeon() {
	std::cout << "Ingresar ID campeon:" << std::endl;
	std::cin >> idCampeon;
	//Verificacion
	while (buscaridChamp(idCampeon) == -1)
	{
		system("cls");
		std::cout << "ID Incorrecto, ingresa otro: " << std::endl;
		std::cin >> idCampeon;
	}
}

void Conjunto_cabecera::setCostototal() {
	//TODO: Busco el archivo de detalle para ver que items pidio, despues busco el archivo de items para buscar el valor de c/u. 

}
void Conjunto_cabecera::setNombre() {

	std::cin.ignore();
	std::cout << "Nombre: " << std::endl;
	std::cin.getline(nombre, 30);
}

int Conjunto_cabecera::contarRegistros() {
	{

		FILE* pf;
		int c = 0;
		pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
		if (pf == NULL)
		{
			return 0;
		}
		while (fread(this, sizeof(*this), 1, pf) == 1) c++;
		fclose(pf);
		return c;
	}
}

