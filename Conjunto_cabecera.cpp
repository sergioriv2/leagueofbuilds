#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"
#include "Campeon.h"


Conjunto_cabecera::Conjunto_cabecera()
{
	const char* n = "n/a";
	estado = true;
	strcpy(nombre, n);
	idCampeon = idConjunto = costoTotal = 0;
}

//Archivos

bool Conjunto_cabecera::guardarCabecera()
{
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "ab");
	if (pf == NULL)
	{
		std::cout << "conjunto cabecera : guardarCabecera()";
		return 0;
	}
	bool write = fwrite(this, sizeof * this, 1, pf);
	fclose(pf);
	return write;
}

void Conjunto_cabecera::cargarCabecera()
{
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto cabecera : cargarCabecera()";
		return;
	}
	while (fread(this, sizeof * this, 1, pf))
	{
		std::cout << "ID: " << idConjunto  << "\t\t"  << "Nombre: " << nombre << std::endl;
	}
	fclose(pf);
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

//Metodos

void Conjunto_cabecera::ingresarCabecera()
{
	int opc;

	//ID Autonumerico
	setidConjunto();
	//Pido ID, -1 para salir
	setidCampeon();
	//Pido nombre del conjunto
	setNombre();

	Conjunto_detalle* detalle;
	detalle = new Conjunto_detalle;

	//Detalle tiene el mismo id que cabecera
	detalle->setDetalle(idConjunto);

	do
	{
		system("cls");
		detalle->setitemsEarly();
		detalle->setItemsMid();
		detalle->setItemsLate();
		system("cls");
		std::cout << "Detalles del conjunto: " << nombre << std::endl << std::endl;
		detalle->imprimirDetalle();
		std::cout << std::endl << std::endl;
		std::cout << "OPCIONES" << std::endl;
		std::cout << "0. Guardar y salir " << std::endl;
		std::cout << "1. Editar " << std::endl;
		std::cout << "2. Salir sin guardar " << std::endl << std::endl;
		std::cin >> opc;
	} while (opc == 1);

	if (opc == 2) return;

	detalle->guardarDetalle();

	//Calculo el costo total y lo guardo
	setCostototal();

	delete detalle;
	system("cls");
}

int Conjunto_cabecera::calcularCosto(int pos)
{
	Conjunto_detalle det;
	int costo;
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_detalle.dat", "rb");
	if (pf == NULL)
	{
		std::cout << "conjunto_cabecera : calcularCosto()";
		return -1;
	}
	fseek(pf, (sizeof det) * pos, 0);
	fread(&det, sizeof det, 1, pf);
	costo = det.getCostoTotal();
	fclose(pf);
	return costo;
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

void Conjunto_cabecera::setCostototal() 
{

	costoTotal = calcularCosto(idConjunto);

}

void Conjunto_cabecera::setNombre() {

	std::cin.ignore();
	std::cout << "Nombre del conjunto: " << std::endl;

	int i;
	fflush(stdin);
	for (i = 0; i < 30; i++) {
		nombre[i] = std::cin.get();
		if (nombre[i] == '\n') break;
	}
	nombre[i] = '\0';
	fflush(stdin);
}


