#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"
#include "Campeon.h"
#include "Item.h"

Conjunto_cabecera::Conjunto_cabecera()
{
	const char* n = "n/a";
	estado = true;
	strcpy(nombre, n);
	idCampeon = idConjunto = costoTotal = 0;
}

//Archivos

bool Conjunto_cabecera::guardarCabecera(int pos)
{
	FILE* pf;
	bool write;

	//Parametro por omision -1, solo guardo

	if (pos == -1)
	{
		pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "ab");
		if (pf == NULL)
		{
			std::cout << "conjunto cabecera : guardarCabecera()";
			return 0;
		}
		write = fwrite(this, sizeof * this, 1, pf);
	}
	else // Si se manda pos se modifica el archivo
	{
		pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb+");
		if (pf == NULL)
		{
			std::cout << "conjunto cabecera : guardarCabecera()";
			return 0;
		}
		fseek(pf, (sizeof * this) * pos, 0);
		write = fwrite(this, sizeof * this, 1, pf);
	}
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
		if(estado) std::cout << "ID: " << idConjunto  << "\t\t"  << "Nombre: " << nombre << std::endl;
	}
	fclose(pf);
}

void Conjunto_cabecera::modificar(bool borrar)
{
	//Declaracion de variables
	int opc, opc2 = 0, posChamp;
	Conjunto_detalle* cd;
	cd = new Conjunto_detalle;

	std::cout << "CONJUNTOS CARGADOS" << std::endl << std::endl;
	//Cargo cabecera
	this->cargarCabecera();

	//Condicional para saber si modifico o no
	//
	//MODIFICO
	if (!borrar)
	{
		std::cout << std::endl << "Ingresa el ID para editar (-1 para salir): ";
		//Pido el ID de conjunto
		std::cin >> opc;
		if (opc == -1) return;

		//Verifico que exista el ID

		if (buscaridConjunto(opc) == -1)
		{
			std::cout << "El conjunto ingresado no existe" << std::endl;
			return;
		}

		system("cls");

		//Abro
		FILE* pf;
		pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
		if (pf == NULL) return;

		//Me voy al registro del ID que me mandaron
		fseek(pf, (sizeof * this) * opc, 0);
		fread(this, sizeof * this, 1, pf);


		//Pregunto si esta disponible
		if (this->getEstado())
		{
			//Muestro propiedades
			std::cout << "CONJUNTO DETALLADO ------------------" << std::endl << std::endl;
			std::cout << "NOMBRE CONJUNTO: " << this->getNombre() << std::endl;
			Campeon* champ;
			champ = new Campeon;
			//Creo un obj de campeon solo para mostrar el nombre

			posChamp = champ->searchPos(this->getidCampeon());
			champ->leerCampeon(posChamp);
			std::cout << "CAMPEON: " << champ->getNombre() << std::endl;
			delete champ;

			std::cout << "PRECIO TOTAL: " << this->getcostoTotal() << "g" << std::endl << std::endl;

			//Cierro archivo de cabecera
			fclose(pf);
			//Muestro en lista los detalles del ID que me mandaron 
			cd->cargarDetalle(opc);

			std::cout << std::endl << std::endl;

			std::cout << "ELEGIR UNA OPCION " << std::endl;
			std::cout << "0. Salir" << std::endl;
			std::cout << "1. Nombre conjunto" << std::endl;
			std::cout << "2. Campeon conjunto" << std::endl;
			std::cout << "3. Editar Conjunto completo" << std::endl;
			std::cout << "4. Editar Conjunto early" << std::endl;
			std::cout << "5. Editar Conjunto mid" << std::endl;
			std::cout << "6. Editar Conjunto late" << std::endl;
			std::cin >> opc2;
			system("cls");
			switch (opc2)
			{
			case 1:
				setNombre();
				break;
			case 2:
				setidConjunto();
				break;
			case 3:
				cd->setitemsEarly();
				cd->setItemsMid();
				cd->setItemsLate();
				break;
			case 4:
				cd->setitemsEarly();
				break;
			case 5:
				cd->setItemsMid();
				break;
			case 6:
				cd->setItemsLate();
				break;
			case 0: return;
			default: return;
			}
			//Guardo primero detalles
			if (cd->guardarDetalle(opc))
			{
				//De ahi calculo el costo
				std::cout << "Conjunto modificado" << std::endl;
				this->setCostototal();

				if (this->guardarCabecera(opc))
				{
					std::cout << "Conjunto modificado" << std::endl;
				}
				else
				{
					std::cout << "Error al editar cabecera" << std::endl;
				}
			}
			else
			{
				std::cout << "Error al editar detalle" << std::endl;
			}
		}
		else //Si el conjunto esta dado de baja
		{
			std::cout << "No se encontro el conjunto" << std::endl;
		}
		
	}
	//BORRO
	else
	{
		//Copy paste de la modificacion
		std::cout << std::endl << "Ingresa el ID para dar de baja (-1 para salir): ";
		//Pido ID
		std::cin >> opc;
		system("cls");
		if (opc == -1) return;
		//Verifico que exista
		if (buscaridConjunto(opc) == -1)
		{
			std::cout << "El conjunto ingresado no existe" << std::endl;
			return;
		}

		//Abro
		FILE* pf;
		pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
		if (pf == NULL) return;
		fseek(pf, (sizeof * this) * opc, 0);
		fread(this, sizeof * this, 1, pf);

		std::cout << "CONJUNTO DETALLADO ------------------" << std::endl << std::endl;
		std::cout << "NOMBRE CONJUNTO: " << this->getNombre() << std::endl;
		Campeon* champ;
		champ = new Campeon;

		posChamp = champ->searchPos(this->getidCampeon());
		champ->leerCampeon(posChamp);
		std::cout << "CAMPEON: " << champ->getNombre() << std::endl << std::endl;

		delete champ;
		//Cierro
		fclose(pf);

		std::cout << "ELEGIR UNA OPCION " << std::endl << std::endl;
		std::cout << "0. Salir" << std::endl;
		std::cout << "1. Borrar" << std::endl << std::endl;
		std::cin >> opc2;
		switch (opc2)
		{
		case 1:
			this->setEstado(false);
			cd->setEstado(false);
			//std::cout << "Cabecera "<<this->getEstado() << std::endl;
			//std::cout << "Detalle "<<cd->getEstado() << std::endl;
			break;
		case 0: return;
		}
		//Doy de baja y verifico
		if (cd->guardarDetalle(opc))
		{
			if (this->guardarCabecera(opc))
			{
				std::cout << "Conjunto dado de baja" << std::endl;
			}
			else
			{
				std::cout << "Error al dar de baja" << std::endl;
			}
			
		}
	}
	
	delete cd;
	return;
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

bool Conjunto_cabecera::ingresarCabecera()
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

	//Despues cargo el detalle con un loop
	do
	{
		system("cls");
		//Detalle: Cargo el array 
		detalle->setitemsEarly();
		detalle->setItemsMid();
		detalle->setItemsLate();
		system("cls");
		//Cuando se termina de cargar, muestro 
		std::cout << "Detalles del conjunto: " << nombre << std::endl << std::endl;
		detalle->imprimirDetalle();
		std::cout << std::endl << std::endl;
		//Muestro las opciones disponibles
		std::cout << "OPCIONES" << std::endl;
		std::cout << "0. Guardar y salir " << std::endl;
		std::cout << "1. Editar " << std::endl;
		std::cout << "2. Salir sin guardar " << std::endl << std::endl;
		std::cin >> opc;
	} while (opc == 1);

	this->setEstado(true);
	detalle->setEstado(true);

	//Opcion salir
	if (opc == 2) return false;

	//Verifico que se guarde bien
	if (detalle->guardarDetalle())
	{
		//Calculo el costo total y lo guardo
		setCostototal();

		delete detalle;
		return true;
		system("cls");
	}
	//Si no aviso 
	else
	{
		std::cout << "Error al guardar el detalle" << std::endl;
		delete detalle;
		system("true");
		return false;
	}
	
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

int Conjunto_cabecera::buscaridConjunto(int ID)
{
	int pos = 0;
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
	if (pf == NULL) return -1;
	while (fread(this, sizeof * this, 1, pf))
	{
		if (this->getEstado())
		{
			if (this->getidConjunto() == ID)
			{
				return pos;
			}
		}
		else pos++;
	}
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
	costoTotal = 0;
	costoTotal += getCostoEarly();
	costoTotal += getCostoMid();
	costoTotal += getCostoLate();

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

int Conjunto_cabecera::getCostoEarly()
{
	int pos, costoT = 0;

	Item item;
	Conjunto_detalle* cd;
	cd = new Conjunto_detalle;

	FILE* pf, *pcd;
	
	pf = fopen("resources/items/itemsdata.dat", "rb"); // Item
	pcd = fopen("resources/conjuntos/conjunto_detalle.dat", "rb"); // Conjunto detalle 

	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostoearly" << std::endl;
		return -1;
	}
	if (pcd == NULL)
	{
		fclose(pf);
		std::cout << "conjunto detalle : getcostoearly" << std::endl;
		return -1;
	}

	fseek(pcd, (sizeof(Conjunto_detalle) * idConjunto), 0);
	fread(cd, sizeof(Conjunto_detalle), 1, pcd);

	for (int i = 0; i < 10; i++)
	{
		if (cd->getEarly()[i] != -2 && cd->getEarly()[i] != -1)
		{
			//Busco la posicion del item correspondiente al id de la lista
			pos = item.buscar_reg(cd->getEarly()[i]);
			//Muevo el puntero para leer el registro
			fseek(pf, (sizeof item) * pos, 0);
			//Leo el registro
			fread(&item, sizeof item, 1, pf);
			costoT += item.getCosto();
		}
		
	}


	fclose(pf);
	fclose(pcd);
	delete cd;
	return costoT;
}

int Conjunto_cabecera::getCostoMid()
{
	int pos, costoT = 0;

	Item item;
	Conjunto_detalle* cd;
	cd = new Conjunto_detalle;

	FILE* pf, * pcd;

	pf = fopen("resources/items/itemsdata.dat", "rb"); // Item
	pcd = fopen("resources/conjuntos/conjunto_detalle.dat", "rb"); // Conjunto detalle 

	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostomid" << std::endl;
		return -1;
	}
	if (pcd == NULL)
	{
		fclose(pf);
		std::cout << "conjunto detalle : getcostomid" << std::endl;
		return -1;
	}

	fseek(pcd, (sizeof(Conjunto_detalle) * idConjunto), 0);
	fread(cd, sizeof(Conjunto_detalle), 1, pcd);

	for (int i = 0; i < 10; i++)
	{
		if (cd->getMid()[i] != -2 && cd->getMid()[i] != -1)
		{
			//Busco la posicion del item correspondiente al id de la lista
			pos = item.buscar_reg(cd->getMid()[i]);
			//Muevo el puntero para leer el registro
			fseek(pf, (sizeof item) * pos, 0);
			//Leo el registro
			fread(&item, sizeof item, 1, pf);
			costoT += item.getCosto();
		}

	}


	fclose(pf);
	fclose(pcd);
	delete cd;
	return costoT;
}

int Conjunto_cabecera::getCostoLate()
{
	int pos, costoT = 0;

	Item item;
	Conjunto_detalle* cd;
	cd = new Conjunto_detalle;

	FILE* pf, * pcd;

	pf = fopen("resources/items/itemsdata.dat", "rb"); // Item
	pcd = fopen("resources/conjuntos/conjunto_detalle.dat", "rb"); // Conjunto detalle 

	if (pf == NULL)
	{
		std::cout << "conjunto detalle : getcostoLate" << std::endl;
		return -1;
	}
	if (pcd == NULL)
	{
		fclose(pf);
		std::cout << "conjunto detalle : getcostoLate" << std::endl;
		return -1;
	}

	fseek(pcd, (sizeof(Conjunto_detalle) * idConjunto), 0);
	fread(cd, sizeof(Conjunto_detalle), 1, pcd);

	for (int i = 0; i < 6; i++)
	{
		if (cd->getLate()[i] != -2 && cd->getLate()[i] != -1)
		{
			//Busco la posicion del item correspondiente al id de la lista
			pos = item.buscar_reg(cd->getLate()[i]);
			//Muevo el puntero para leer el registro
			fseek(pf, (sizeof item) * pos, 0);
			//Leo el registro
			fread(&item, sizeof item, 1, pf);
			costoT += item.getCosto();
		}

	}


	fclose(pf);
	fclose(pcd);
	delete cd;
	return costoT;
}


