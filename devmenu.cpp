#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "devmenu.h"
#include "Stat.h"
#include "Campeon.h"
#include "Item.h"
#include "Conjunto_detalle.h"
#include "Conjunto_cabecera.h"

int Menu_Desarrollador::menuPrincipal()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE DESARROLLADOR" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Datos campeones" << endl;
	cout << "2. Datos items " << endl;
	cout << "3. Datos conjuntos" << endl;
	cout << "4. Backup files" << endl;
	cout << "0. Salir" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 0:
		return 0;
		break;
	case 1: menuCampeones();
		break;
	case 2: menuItems();
		break;
	case 3:	menuConjuntos();
		break;
	case 4:
		menuBackup();

		break;
	}
	return opc;
}

//CAMPEONES

void Menu_Desarrollador::menuCampeones()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE CAMPEONES" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar campeones" << endl;
	cout << "2. Borrar campeones " << endl;
	cout << "3. Editar campeones" << endl;
	cout << "4. Mostrar campeones" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarCampeones();
		break;
	case 2:
		eliminarCampeon();
		break;
	case 3:
		modificarCampeon();
		break;
	case 4:
		mostrarCampeones();
		break;
	case 0:
		return;
		break;
	}

}

void Menu_Desarrollador::agregarCampeones()
{
	bool w;
	do
	{
		system("cls");
		Campeon champ;
		cout << "Ingresar 0 en Nombre para terminar" << endl << endl;
		w = champ.cargarCampeon();
		if (w)
		{
			if (champ.guardarCampeon())
			{
				cout << "Se guardo sin errores" << endl;
			}
			else
			{
				cout << "Error al guardar" << endl;
			}
		}
	} while (w);

	return;

}

void Menu_Desarrollador::mostrarCampeones()
{
	Campeon champ;

	champ.mostrarCampeones();

	system("pause");
	return;
}

void Menu_Desarrollador::modificarCampeon() {

	Campeon champ;

	//Mostrar ID y nombres de campeones
	cout << "CAMPEONES CARGADOS  ------------------" << endl << endl;
	FILE* pf;
	pf = fopen("resources/campeones/champsdata.dat", "rb");
	if (pf == NULL) return;
	while (fread(&champ, sizeof champ, 1, pf))
	{
		if (champ.getEstado())
			cout << "ID: " << champ.getID() << "\t\t" << "Nombre: " << champ.getNombre() << endl;
	}
	fclose(pf);

	cout << endl << endl;

	int ID, POS, opc2;
	char opc;
	cout << "Inresar -1 para salir " << endl;
	cout << "Ingresar ID del campeon que se desea modificar: " << endl;
	cin >> ID;
	POS = champ.searchPos(ID);//Busco si existe;
	if (POS == -1) {
		cout << "No se ha encontrado un campeon con esa ID" << endl;// Si no existe me salgo
		return;
	}
	if (champ.leerCampeon(POS) == false) {
		cout << "No se pudo leer el registro" << endl;
		return;
	}

	champ.mostrarCampeon();

	cout << "Desea modificarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		cout << "Elija lo que desea modificar " << endl;

		cout << "1 NOMBRE" << endl;
		cout << "2 ATAQUE" << endl;
		cout << "3 VELOCIDAD DE ATAQ" << endl;
		cout << "4 PODER DE HABILIDAD" << endl;
		cout << "5 VIDA" << endl;
		cout << "6 ARMOR" << endl;
		cout << "7 RESISTENCIA MAGICA" << endl;
		cout << "8 PROBABILIDAD DE CRITICO" << endl;
		cout << "9 MANA" << endl;
		cin >> opc2;
		champ.modify(POS, opc2);
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
}

void Menu_Desarrollador::eliminarCampeon() {
	Campeon champ;
	int ID, POS;
	char opc;
	cout << "Ingresar ID del campeon que se desea modificar: " << endl;
	cin >> ID;
	POS = champ.searchPos(ID);//Busco si existe;
	if (POS == -1) {
		cout << "No se ha encontrado un campeon con esa ID" << endl;// Si no existe me salgo
		return;
	}
	cout << "Se encontro el siguiente campeon " << endl;
	champ.mostrarCampeon();

	cout << "Desea eliminarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		FILE* p;

		p = fopen("resources/campeones/champsdata.dat", "rb+");
		if (p == NULL) {
			cout << "Error abriendo champsdata.dat " << endl;
			return;
		}
		fseek(p, sizeof(Campeon) * POS, 0);
		champ.setEstadoFalse();
		fwrite(&champ, sizeof(Campeon), 1, p);
		fclose(p);
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
}

//ITEMS

void Menu_Desarrollador::menuItems()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE ITEMS" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar items" << endl;
	cout << "2. Borrar items " << endl;
	cout << "3. Editar items" << endl;
	cout << "4. Mostrar items" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarItems();
		break;
	case 2:
		bajaItems();
		break;
	case 3:
		editarItems();
		break;
	case 4:
		mostrarItems();
		break;
	case 0:
		return;
		break;
	}
}

void Menu_Desarrollador::agregarItems()
{
	bool w;
	do
	{
		system("cls");
		Item obj;
		cout << "Ingresar 0 en Nombre para terminar" << endl << endl;
		w = obj.cargarItem();
		if (w)
		{
			if (obj.guardar())
			{
				cout << "Se guardo sin errores" << endl;
			}
			else
			{
				cout << "Error al guardar" << endl;
			}
			system("pause");
		}
	} while (w);

	return;
}

void Menu_Desarrollador::bajaItems()
{
	Item obj;

	if (obj.baja())
	{
		cout << "Se dio de baja correctamente" << endl;
	}
	else
	{
		cout << "Error al dar de baja " << endl;
	}

	system("pause");
}

void Menu_Desarrollador::editarItems()
{
	Item obj;

	obj.editar();
	system("pause");
}

void Menu_Desarrollador::mostrarItems()
{
	Item obj;

	// PARA MOSTRAR SOLO EL NOMBRE, IR A LA DEFINICION DE ESTA FUNCION Y EN LA LINEA 92 PONE EN TRUE
	obj.mostrar_registros();
	system("pause");
	return;
}

//CONJUNTOS

void Menu_Desarrollador::menuConjuntos()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE CONJUNTOS" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar conjunto" << endl;
	cout << "2. Mostrar conjunto" << endl;
	cout << "3. Editar conjunto" << endl;
	cout << "4. Borrar conjunto" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarConjunto();
		break;
	case 2:
		mostrarConjunto();
		break;
	case 3:
		editarConjunto();
		break;
	case 4:
		bajaConjunto();
		break;
	case 0:
		return;
		break;
	}
}

void Menu_Desarrollador::bajaConjunto()
{
	Conjunto_cabecera* c;
	c = new Conjunto_cabecera;

	c->modificar(true);

	delete c;
	system("pause");
}

void Menu_Desarrollador::editarConjunto()
{
	//Creo un objeto y llamo al metodo
	//Lo puse en un metodo aparte porque era mucho texto(?

	Conjunto_cabecera* c;
	c = new Conjunto_cabecera;

	c->modificar();

	delete c;
	system("pause");
}

void Menu_Desarrollador::agregarConjunto()
{
	Conjunto_cabecera* c;
	c = new Conjunto_cabecera;

	// Se piden los datos y desp guardo

	if (c->ingresarCabecera())
	{
		if (c->guardarCabecera())
		{
			cout << "Conjunto guardado" << endl;
		}
		else
		{
			cout << "Error al guardar el conjunto" << endl;
		}
	}
	else
	{
		cout << "Error al guardar el conjunto" << endl;
	}
	system("pause");
	delete c;

}

void Menu_Desarrollador::mostrarConjunto()
{
	cout << "CONJUNTOS CARGADOS" << endl << endl;

	//Creo las variables para mostrar

	Conjunto_cabecera* c;
	Conjunto_detalle* cd;

	c = new Conjunto_cabecera;
	cd = new Conjunto_detalle;

	int opc;

	//Muestro por pantalla todos los conjuntos activos
	c->cargarCabecera();

	cout << endl << "Ingresa el ID para mostrar mas detalles (-1 para salir): ";

	//Pido ID del conjunto, que basicamente es la posicion del registro asi que mas adelante lo uso para el fseek
	cin >> opc;
	system("cls");

	if (opc == -1) return;

	//Verifico que exista el conjunto 
	if (c->buscaridConjunto(opc) == -1)
	{
		std::cout << "El conjunto ingresado no existe" << std::endl;
		system("pause");
		return;
	}
	//Abro el archivo para las propiedades de CABECERA
	FILE* pf;
	pf = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
	if (pf == NULL) return;
	fseek(pf, (sizeof * c) * opc, 0);
	fread(c, sizeof * c, 1, pf);

	cout << "CONJUNTO DETALLADO ------------------" << endl << endl;

	//Cabecera: Muestro Estado, Nombre y Costo
	cout << "ESTADO " << c->getEstado() << endl;
	cout << "NOMBRE: " << c->getNombre() << endl;
	cout << "PRECIO TOTAL: " << c->getcostoTotal() << "g" << endl << endl;

	//Cierro el archivo
	fclose(pf);

	//Cargo detalles de DETALLES en la posicion que mandaron
	cd->cargarDetalle(opc);

	system("pause");

	delete c;
	delete cd;
}

void Menu_Desarrollador::menuBackup() {

	int opc;
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE BACKUP" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. CREAR BACKUP" << endl;
	cout << "2. RESTAURAR BACKUP " << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc;
	system("cls");
	switch (opc) {
	case 1:
		if (backupFiles() == true) {
			cout << "Backup creado con exito." << endl;
		}
		else {
			cout << "Hubo un error al crear el backup" << endl;
		}
		break;
	case 2:if (restoreFiles() == true) {
		cout << "Archivos restaurados con exito." << endl;
	}
		  else {
		cout << "Hubo un error al restaurar el archivo" << endl;
	}

		  break;
	}
	system("pause");

}

bool Menu_Desarrollador::backupFiles() {
	FILE* pIt, * pCa, * pCo1, * pCo2;
	FILE* pbIt, * pbCa, * pbCo1, * pbCo2;
	Campeon champ;
	Item item;
	Conjunto_cabecera Ccab;//TODO: Hacer algo con el conj cabecera para que me deje usarlo aca
	Conjunto_detalle Cdet;

	char opcion;
	cout << "Desea hacer una copia de seguridad S/N " << endl;
	cin >> opcion;
	if (opcion == 's' || opcion == 'S')
	{

		pIt = fopen("resources/items/itemsdata.dat", "rb");
		pCa = fopen("resources/campeones/champsdata.dat", "rb");
		pCo1 = fopen("resources/conjuntos/conjunto_cabecera.dat", "rb");
		pCo2 = fopen("resources/conjuntos/conjunto_detalle.dat", "rb");
		pbIt = fopen("resources/backups/itemsdata.bkp", "wb");
		pbCa = fopen("resources/backups/champsdata.bkp", "wb");
		pbCo1 = fopen("resources/backups/conjunto_cabecera.bkp", "wb");
		pbCo2 = fopen("resources/backups/conjunto_detalle.bkp", "wb");

		//Me aseguro de que se hayan abierto correctamente

		if (pIt == NULL)
		{
			cout << "Items " << endl;
			system("pause");
			return false;
		}
		if (pCa == NULL)
		{
			cout << "Campeones " << endl;
			system("pause");
			fclose(pIt);
			return false;
		}

		if (pCo1 == NULL)
		{
			cout << "Conjunto cabecera " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			return false;
		}

		if (pCo2 == NULL)
		{
			cout << "Conjunto detalle " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			return false;
		}

		if (pbIt == NULL)
		{
			cout << "Items bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			return false;
		}
		if (pbCa == NULL)
		{
			cout << "Champ bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
		}
		if (pbCo1 == NULL)
		{
			cout << "Ccab bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
			fclose(pbCa);
		}
		if (pbCo2 == NULL)
		{
			cout << "C det bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
			fclose(pbCa);
			fclose(pbCo1);
		}

		//Mientras pueda leer los .dat escribo en los .bkp
		while (fread(&champ, sizeof(Campeon), 1, pCa))
		{
			fwrite(&champ, sizeof(Campeon), 1, pbCa);
		}

		while (fread(&item, sizeof(Item), 1, pIt))
		{
			fwrite(&item, sizeof(Item), 1, pbIt);
		}

		while (fread(&Ccab, sizeof(Conjunto_cabecera), 1, pCo1))
		{
			fwrite(&Ccab, sizeof(Conjunto_cabecera), 1, pbCo1);
		}

		while (fread(&Cdet, sizeof(Conjunto_detalle), 1, pCo2))
		{
			fwrite(&Cdet, sizeof(Conjunto_detalle), 1, pbCo2);
		}

		fclose(pCa);
		fclose(pbCa);
		fclose(pIt);
		fclose(pbIt);
		fclose(pCo1);
		fclose(pbCo1);
		fclose(pCo2);
		fclose(pbCo2);

		return true;
	}
	return false;

}

bool Menu_Desarrollador::restoreFiles()
{
	FILE* pIt, * pCa, * pCo1, * pCo2;
	FILE* pbIt, * pbCa, * pbCo1, * pbCo2;
	Campeon champ;
	Item item;
	Conjunto_cabecera Ccab;
	Conjunto_detalle Cdet;
	char opcion;

	cout << "Desea restaurar los datos? S/N " << endl;
	cin >> opcion;
	if (opcion == 's' || opcion == 'S')
	{
		pIt = fopen("resources/items/itemsdata.dat", "wb");
		pCa = fopen("resources/campeones/champsdata.dat", "wb");
		pCo1 = fopen("resources/conjuntos/conjunto_cabecera.dat", "wb");
		pCo2 = fopen("resources/conjuntos/conjunto_detalle.dat", "wb");
		pbIt = fopen("resources/backups/itemsdata.bkp", "rb");
		pbCa = fopen("resources/backups/champsdata.bkp", "rb");
		pbCo1 = fopen("resources/backups/conjunto_cabecera.bkp", "rb");
		pbCo2 = fopen("resources/backups/conjunto_detalle.bkp", "rb");

		//Me aseguro de que se hayan abierto correctamente
		if (pIt == NULL)
		{
			cout << "Items " << endl;
			system("pause");
			return false;
		}
		if (pCa == NULL)
		{
			cout << "Campeones " << endl;
			system("pause");
			fclose(pIt);
			return false;
		}

		if (pCo1 == NULL)
		{
			cout << "Conjunto cabecera " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			return false;
		}

		if (pCo2 == NULL)
		{
			cout << "Conjunto detalle " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			return false;
		}

		if (pbIt == NULL)
		{
			cout << "Items bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			return false;
		}
		if (pbCa == NULL)
		{
			cout << "Champ bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
			return false;
		}
		if (pbCo1 == NULL)
		{
			cout << "Ccab bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
			fclose(pbCa);
			return false;
		}
		if (pbCo2 == NULL)
		{
			cout << "C det bkp " << endl;
			system("pause");
			fclose(pIt);
			fclose(pCa);
			fclose(pCo1);
			fclose(pCo2);
			fclose(pbIt);
			fclose(pbCa);
			fclose(pbCo1);
			return false;
		}


		//Mientras pueda leer los .dat escribo en los .bkp
		while (fread(&champ, sizeof(Campeon), 1, pbCa))
		{
			fwrite(&champ, sizeof(Campeon), 1, pCa);
		}

		while (fread(&item, sizeof(Item), 1, pbIt))
		{
			fwrite(&item, sizeof(Item), 1, pIt);
		}

		while (fread(&Ccab, sizeof(Conjunto_cabecera), 1, pbCo1))
		{
			fwrite(&Ccab, sizeof(Conjunto_cabecera), 1, pCo1);
		}

		while (fread(&Cdet, sizeof(Conjunto_detalle), 1, pbCo2))
		{
			fwrite(&Cdet, sizeof(Conjunto_detalle), 1, pCo2);
		}


		fclose(pCa);
		fclose(pbCa);
		fclose(pIt);
		fclose(pbIt);
		fclose(pCo1);
		fclose(pbCo1);
		fclose(pCo2);
		fclose(pbCo2);
		return true;
	}

	return false;
}