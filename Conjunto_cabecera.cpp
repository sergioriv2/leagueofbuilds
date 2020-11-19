#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>

#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"
#include "Campeon.h"
#include "Item.h"
#include "Archivo.h"

const char* UB_CABECERA = "resources/conjuntos/conjunto_cabecera.dat";
const char* UB_DET = "resources/conjuntos/conjunto_detalle.dat";

Conjunto_cabecera::Conjunto_cabecera()
{
	const char* n = "n/a";
	estado = false;
	strcpy(nombre, n);
	idCampeon = idConjunto = costoTotal = 0;
}

void Conjunto_cabecera::Mostrar()
{

}

void Conjunto_cabecera::MostrarCabecera()
{
	Archivo arch(UB_CABECERA, sizeof(Conjunto_cabecera));
	Archivo arch2("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	Conjunto_cabecera con;
	int i = 0;
	while (arch.leerRegistro(con, i)==1)
	{
		if (con.getEstado()) {

			arch2.leerRegistro(champ, con.getidCampeon());

			std::cout << "ID: " << con.getidConjunto() << "\t\t" << "Campeon: " << champ.getNombre() << "\t\t" << "Nombre conjunto: " << con.getNombre() << std::endl;
		}
		i++;
	}

}

bool Conjunto_cabecera::Cargar()
{
	int opc;
	Archivo archdetalle("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//ID Autonumerico
	setidConjunto();
	//Pido ID, -1 para salir
	setidCampeon();
	//Pido nombre del conjunto
	setNombre();

	Conjunto_detalle detalle;

	//Detalle tiene el mismo id que cabecera
	detalle.setDetalle(idConjunto);

	//Despues cargo el detalle con un loop
	do
	{
		system("cls");
		//Detalle: Cargo el array 
		detalle.Cargar();
		system("cls");
		//Cuando se termina de cargar, muestro 
		std::cout << "Detalles del conjunto: " << nombre << std::endl << std::endl;
		detalle.Mostrar();
		std::cout << std::endl << std::endl;
		//Muestro las opciones disponibles
		std::cout << "OPCIONES" << std::endl;
		std::cout << "0. Guardar y salir " << std::endl;
		std::cout << "1. Editar " << std::endl;
		std::cout << "2. Salir sin guardar " << std::endl << std::endl;
		std::cin >> opc;
	} while (opc == 1);

	this->setEstado(true);
	detalle.setEstado(true);

	//Opcion salir
	if (opc == 2) return false;

	//Guardo detalle
	if (archdetalle.grabarRegistro(detalle, -1, Modo::Agregar))
	{
		//Calculo el costo total
		setCostototal();
		system("cls");
		return true;

	}
	else
	{
		std::cout << "Error al guardar el detalle" << std::endl;
		system("cls");
		return false;
	}
}

bool Conjunto_cabecera::Modificar(int ID)
{
	Archivo archdet(UB_DET, sizeof(Conjunto_detalle));
	Archivo archcab(UB_CABECERA, sizeof(Conjunto_cabecera));
	int opc2;
	Conjunto_detalle cd;
	//Leo detalle en la posicion que me mandaron
	archdet.leerRegistro(cd, ID);
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
		setidCampeon();
		break;
	case 3:
		cd.setitemsEarly();
		cd.setItemsMid();
		cd.setItemsLate();
		break;
	case 4:
		cd.setitemsEarly();
		break;
	case 5:
		cd.setItemsMid();
		break;
	case 6:
		cd.setItemsLate();
		break;
	case 0: return false;
	default: return false;
	}
	//Guardo primero detalles
	if (archdet.grabarRegistro(cd, ID, Modo::LecturaEscritura))
	{
		//Calculo el costo
		this->setCostototal();

		if (archcab.grabarRegistro(*this, ID, LecturaEscritura))
		{
			std::cout << "Conjunto modificado" << std::endl;
			system("pause");
			return true;
		}
		else
		{
			std::cout << "Error al editar cabecera" << std::endl;
			system("pause");
			return false;
		}
	}
	else
	{
		std::cout << "Error al editar detalle" << std::endl;
		system("pause");
		return false;
	}


}

//Metodos

void Conjunto_cabecera::setidConjunto() {

	Archivo arch(UB_CABECERA, sizeof(Conjunto_cabecera));
	idConjunto = arch.getCantidadRegistros();
}

void Conjunto_cabecera::setidCampeon() { //Conchadetumadre
	Archivo archchamp("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	bool ciclo = true;
	std::cout << "Ingresar ID campeon:" << std::endl;
	std::cin >> idCampeon;
	if (archchamp.leerRegistro(champ, idCampeon) == 0)	// Devuelve 0 si no lee
	{
		do
		{
			system("cls");
			std::cout << "ID incorrecto, ingresa otro:" << std::endl;
			std::cin >> idCampeon;
			if (archchamp.leerRegistro(champ, idCampeon) == 1 && champ.getEstado())
			{
				ciclo = false;
			}
		} while (ciclo);
	}
	else
	{
		if (champ.getEstado() == false)
		{
			do
			{
				system("cls");
				std::cout << "ID incorrecto, ingresa otro:" << std::endl;
				std::cin >> idCampeon;
			} while (ciclo);
		}
	}

}

void Conjunto_cabecera::setCostototal()
{
	costoTotal = 0;
	costoTotal += getCosto();
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

bool Conjunto_cabecera::BajaVirtual(int ID)
{
	//lpmmmm por que no guardasssssssssss
	/*
	Archivo archdet(UB_DET, sizeof(Conjunto_detalle));
	Archivo archcab(UB_CABECERA, sizeof(Conjunto_cabecera));
	Conjunto_detalle cd;
	Conjunto_cabecera c;
	//Leo detalle en la posicion que me mandaron
	archdet.leerRegistro(cd, ID);
	archcab.leerRegistro(c, ID);
	c.setEstado(false);
	archdet.grabarRegistro(c, ID, LecturaEscritura);
	return true
	*/
	return false;
}


int Conjunto_cabecera::getCosto()
{
	//Creo objeto item, para saber el precio
	Item it;
	int pos, costoT = 0;
	//Creo nuevo objeto, donde voy a almacenar todo
	Conjunto_detalle conDet;
	//Abro archivos
	Archivo architem("resources/items/itemsdata.dat", sizeof(Item));
	Archivo archdet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//Leo detalle
	archdet.leerRegistro(conDet, idConjunto);

	//1. Costo Early
	//--------------------------------------------------------
	for (int i = 0; i < 10; i++)
	{
		if (conDet.getEarly()[i] != -1 && conDet.getEarly()[i] != -2)
		{
			//Seteo el id de item con el detalle de early en la posicion i
			it.setID(conDet.getEarly()[i]);
			//Busco la pos del item
			pos = architem.buscarRegistro(it);
			if (pos == -2)
			{
				std::cout << "Error al abrir archivo, getCosto conjunto cabecera" << std::endl;
				system("pause");
				return -1;
			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error al encontrar item, getCosto conjunto cabecera " << std::endl;
					system("pause");
					return -1;
				}
				else
				{
					//Cargo de disco a memoria en la variable it
					architem.leerRegistro(it, pos);
					costoT += it.getCosto();
				}
			}
		}

	}
	//2. Costo Mid
	for (int i = 0; i < 10; i++)
	{
		if (conDet.getMid()[i] != -1 && conDet.getMid()[i] != -2)
		{
			//Seteo el id de item con el detalle de Mid en la posicion i
			it.setID(conDet.getMid()[i]);
			//Busco la pos del item
			pos = architem.buscarRegistro(it);
			if (pos == -2)
			{
				std::cout << "Error al abrir archivo, getCosto conjunto cabecera" << std::endl;
				system("pause");
				return -1;
			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error al encontrar item, getCosto conjunto cabecera " << std::endl;
					system("pause");
					return -1;
				}
				else
				{
					//Cargo de disco a memoria en la variable it
					architem.leerRegistro(it, pos);
					costoT += it.getCosto();
				}
			}
		}

	}
	//3. Costo Late
	for (int i = 0; i < 6; i++)
	{
		if (conDet.getLate()[i] != -1 && conDet.getLate()[i] != -2)
		{
			//Seteo el id de item con el detalle de Late en la posicion i
			it.setID(conDet.getLate()[i]);
			//Busco la pos del item
			pos = architem.buscarRegistro(it);
			if (pos == -2)
			{
				std::cout << "Error al abrir archivo, getCosto conjunto cabecera" << std::endl;
				system("pause");
				return -1;
			}
			else
			{
				if (pos == -1)
				{
					std::cout << "Error al encontrar item, getCosto conjunto cabecera " << std::endl;
					system("pause");
					return -1;
				}
				else
				{
					//Cargo de disco a memoria en la variable it
					architem.leerRegistro(it, pos);
					costoT += it.getCosto();
				}
			}
		}

	}

	return costoT;
}

