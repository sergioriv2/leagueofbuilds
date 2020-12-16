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
#include "Archivo.h"

const char* UB_CAMPEONES = "resources/campeones/champsdata.dat";
const char* UB_ITEMS = "resources/items/itemsdata.dat";
const char* UB_CONDET = "resources/conjuntos/conjunto_detalle.dat";
const char* UB_CONCAB = "resources/conjuntos/conjunto_cabecera.dat";


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
	case 4:	menuBackup();
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
		menuPrincipal();
		break;
	}

}

void Menu_Desarrollador::agregarCampeones()
{
	Archivo campeones(UB_CAMPEONES, sizeof(Campeon));
	Campeon champ;
	int x;
	std::cout << "CARGA DE CAMPEONES: " << std::endl;
	if (champ.Cargar())
	{
		x = campeones.grabarRegistro(champ, 0, Agregar);
		if (x == 1) cout << "Campeon cargado" << endl;
		else cout << "Error al cargar campeon" << endl;
	}
	system("pause");
	system("cls");
}

void Menu_Desarrollador::mostrarCampeones()
{
	Archivo campeones(UB_CAMPEONES, sizeof(Campeon));
	Campeon champ;

	if (!campeones.listarArchivo(champ))
	{
		cout << "Error al listar" << endl;
	}

	system("pause");
	return;

}

void Menu_Desarrollador::modificarCampeon() {

	Archivo campeones(UB_CAMPEONES, sizeof(Campeon));
	Campeon champ;
	int i = 0;
	//Mostrar ID y nombres de campeones
	cout << "MENU DE MODIFACION DE CAMPEONES" << endl << endl;
	cout << "CAMPEONES CARGADOS  ------------------" << endl << endl;

	while (campeones.leerRegistro(champ, i))
	{
		if (champ.getEstado())
		{
			cout << "ID: " << champ.getID() << "\t\t" << "Nombre: " << champ.getNombre() << endl;
		}
		i++;
	}
	cout << endl << endl;

	int ID;
	char opc;
	cout << "Ingresar ID del campeon que se desea modificar (-1 para salir): " << endl;

	//Creo un objeto de Campeon dinamico solo para ver si existe

	Campeon* nchamp;
	nchamp = new Campeon;
	cin >> ID;
	nchamp->setID(ID);
	//Verifico si existe el id ingresado
	if (campeones.buscarRegistro(*nchamp) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{	//Si existe, se carga
	    campeones.leerRegistro(champ, ID - 1);
		if(champ.getEstado())cout << endl << "Se encontro el siguiente registro: " << endl;
		else
        {
            cout << "El registro no existe" << endl;
            system("pause");
            system("cls");
        }
	}
	//Borro el objeto
	delete nchamp;

	champ.Mostrar();

	cout << "Desea modificarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		if (champ.Modificar(ID - 1)) cout << "Se modifico correctamente" << endl;
		else cout << "Error al modificar el registro" << endl;
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
	system("pause");
}

void Menu_Desarrollador::eliminarCampeon() {
	Archivo campeones(UB_CAMPEONES, sizeof(Campeon));
	Campeon champ;
	int i = 0;
	//Mostrar ID y nombres de campeones
	cout << "MENU DE BAJA DE CAMPEONES" << endl << endl;
	cout << "CAMPEONES CARGADOS  ------------------" << endl << endl;

	while (campeones.leerRegistro(champ, i))
	{
		if (champ.getEstado()) {
			cout << "ID: " << champ.getID() << "\t\t" << "Nombre: " << champ.getNombre() << endl;
		}
		i++;
	}
	cout << endl << endl;

	int ID;
	char opc;
	cout << "Ingresar ID del campeon que se desea dar de baja (-1 para salir): " << endl;

	//Creo un objeto de Campeon dinamico solo para ver si existe

	Campeon* nchamp;
	nchamp = new Campeon;
	cin >> ID;
    ID -= 1;
	nchamp->setID(ID);
	//Verifico si existe el id ingresado
	if (campeones.buscarRegistro(*nchamp) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl;
		system("cls");
		return;
	}
	else
	{	//Si existe, se carga
		cout << endl << "Se encontro el siguiente registro: " << endl;
		campeones.leerRegistro(champ, ID);
	}
	//Borro el objeto
	delete nchamp;

	champ.Mostrar();

	cout << "Desea darlo de baja? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		if (champ.BajaVirtual(ID)) {
			cout << "Dado de baja correctamente" << endl;
		}
		else cout << "Error al dar de baja" << endl;
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
	system("pause");
}

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
		menuPrincipal();
		break;
	}
}

void Menu_Desarrollador::agregarItems()
{
	Archivo architem(UB_ITEMS, sizeof(Item));
	bool w;
	do
	{
		system("cls");
		Item item;
		cout << "Ingresar 0 en Nombre para terminar" << endl << endl;
		w = item.Cargar();
		if (w)
		{
			if (architem.grabarRegistro(item, -1, Modo::Agregar)) cout << "Se guardo sin errores" << endl;
			else cout << "Error al guardar" << endl;

			system("pause");
		}
	} while (w);

	return;
}

void Menu_Desarrollador::bajaItems()
{
	Archivo architem(UB_ITEMS, sizeof(Item));
	Item item;
	int i = 0;
	//Mostrar ID y nombres de items
	cout << "MENU DE BAJA ITEMS" << endl << endl;
	cout << "ITEMS CARGADOS  ------------------" << endl << endl;

	while (architem.leerRegistro(item, i))
	{
		if (item.getEstado()) cout << "ID: " << item.getId() << "\t\t" << "Nombre: " << item.getNombre() << endl;
		i++;
	}
	cout << endl << endl;

	int ID;
	char opc;
	cout << "Ingresar ID del item que se dar de baja (-1 para salir): ";

	//Creo un objeto de item dinamico solo para ver si existe

	Item* nitem;
	nitem = new Item;
	cin >> ID;
    ID-= 1;
	nitem->setID(ID);
	//Verifico si existe el id ingresado
	if (architem.buscarRegistro(*nitem) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl;
		system("cls");
		return;
	}
	else
	{	//Si existe, se carga
		cout << endl << "Se encontro el siguiente registro: " << endl;
		architem.leerRegistro(item, ID);
	}
	//Borro el objeto
	delete nitem;

	item.Mostrar();

	cout << "Desea darlo de baja? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		if (item.BajaVirtual(ID)) cout << "Se elimino correctamente" << endl;
		else cout << "Error al eliminar el registro" << endl;
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
	system("pause");
}

void Menu_Desarrollador::editarItems()
{
	Archivo architem(UB_ITEMS, sizeof(Item));
	Item item;
	int i = 0;
	//Mostrar ID y nombres de items
	cout << "MENU DE MODIFACION DE ITEMS" << endl << endl;
	cout << "ITEMS CARGADOS  ------------------" << endl << endl;

	while (architem.leerRegistro(item, i))
	{
		if (item.getEstado()) cout << "ID: " << item.getId() << "\t\t" << "Nombre: " << item.getNombre() << endl;
		i++;
	}
	cout << endl << endl;

	int ID;
	char opc;
	cout << "Ingresar ID del item que se desea modificar (-1 para salir): ";

	//Creo un objeto de item dinamico solo para ver si existe

	Item* nitem;
	nitem = new Item;
	cin >> ID;
	system("cls");
	nitem->setID(ID);
	//Verifico si existe el id ingresado
	if (architem.buscarRegistro(*nitem) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl;
		system("cls");
		return;
	}
	else
	{	//Si existe, se carga
	    architem.leerRegistro(item, ID -1);
	    if(item.getEstado()) cout << "Se encontro el siguiente registro: " << endl << endl;
		else
        {
        cout << "El registro no existe" << endl;
        system("pause");
		system("cls");
		return;
        }
	}
	//Borro el objeto
	delete nitem;

	item.Mostrar();

	cout << "Desea modificarlo? s/n" << endl;// Confirmo
	cin >> opc;
	if (opc == 's' || opc == 'S') {
		if (item.Modificar(ID - 1)) cout << "Se modifico correctamente" << endl;
		else cout << "Error al modificar el registro" << endl;
	}
	else if (opc == 'n' || opc == 'N') {
		return;
	}
	system("pause");
}

void Menu_Desarrollador::mostrarItems()
{
	Archivo architem(UB_ITEMS, sizeof(Item));
	Item item;
	int i = 0;
	while (architem.leerRegistro(item, i))
	{
		if (item.getEstado()) item.Mostrar();
		i++;
	}

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
		menuPrincipal();
		break;
	}
}

void Menu_Desarrollador::bajaConjunto(){

	Archivo archcab(UB_CONCAB, sizeof(Conjunto_cabecera));
	Archivo archdet(UB_CONDET, sizeof(Conjunto_detalle));

	cout << "CONJUNTOS CARGADOS" << endl << endl;

	//Creo las variables para mostrar

	Conjunto_cabecera c;
	Conjunto_detalle cd;

	int opc;
	char opc2;

	//Muestro por pantalla todos los conjuntos activos

	c.MostrarCabecera();

	cout << endl << "Ingresa el ID para dar de baja (-1 para salir): ";

	//Pido ID del conjunto, que basicamente es la posicion del registro asi que mas adelante lo uso para el fseek
	cin >> opc;
	system("cls");
	if (opc == -1) return;

	//Creo un objeto dinamico solo para la verificacion
	Conjunto_cabecera* nc;
	nc = new Conjunto_cabecera;

	nc->setID(opc);
	if (archcab.buscarRegistro(*nc) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl << endl;
		system("pause");
		return;
	}
	else
	{	//Si existe, se carga
        opc -=1;
		archcab.leerRegistro(c, opc);
	}
	//Borro el objeto
	delete nc;
	cout << "MENU DE BAJA CONJUNTOS " << endl;
	cout << "CONJUNTO DETALLADO ------------------" << endl << endl;
	//Fin de verificacion -------------

	//Cabecera: Muestro Estado, Nombre y Costo
	cout << "Se encontro el siguiente registro: " << endl << endl;
	cout << "ESTADO " << c.getEstado() << endl;
	cout << "NOMBRE: " << c.getNombre() << endl;
	cout << "PRECIO TOTAL: " << c.getcostoTotal() << "g" << endl << endl;

	cout << "Desea darlo de baja? s/n" << endl;// Confirmo
	cin >> opc2;
	if (opc2 == 's' || opc2 == 'S') {
		if (c.BajaVirtual(opc))
		{
			cout << "Baja exitosa" << endl;
			system("pause");
		}
		else cout << "Error al dar de baja " << endl;

	}
	else if (opc2 == 'n' || opc2 == 'N') {
		return;
	}
	system("pause");
}

void Menu_Desarrollador::editarConjunto()
{
	Archivo archcab(UB_CONCAB, sizeof(Conjunto_cabecera));
	Archivo archdet(UB_CONDET, sizeof(Conjunto_detalle));
	cout << "MENU DE EDICION CONJUNTOS " << endl << endl;
	cout << "CONJUNTOS CARGADOS" << endl << endl;

	//Creo las variables para mostrar

	Conjunto_cabecera c;
	Conjunto_detalle cd;

	int opc;

	//Muestro por pantalla todos los conjuntos activos

	c.MostrarCabecera();

	cout << endl << "Ingresa el ID para editar (-1 para salir): ";

	//Pido ID del conjunto, que basicamente es la posicion del registro asi que mas adelante lo uso para el fseek
	cin >> opc;
	system("cls");

	if (opc == -1) return;

	//Creo un objeto dinamico solo para la verificacion
	Conjunto_cabecera* nc;
	nc = new Conjunto_cabecera;
	nc->setID(opc);
	if (archcab.buscarRegistro(*nc) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl << endl;
		system("pause");
		return;
	}
	else
	{	//Si existe, se carga
		archcab.leerRegistro(c, opc);
		archdet.leerRegistro(cd, opc);
		if(c.getEstado() == false)
        {

        cout << "El registro no existe" << endl << endl;
		system("pause");
		return;
        }
	}
	//Borro el objeto
	delete nc;
	cout << "MENU DE EDICION CONJUNTOS " << endl << endl;
	cout << "CONJUNTO DETALLADO ------------------" << endl << endl;
	//Fin de verificacion -------------
	cout << "Se encontro el siguiente registro: " << endl << endl;
	//Cabecera: Muestro Estado, Nombre y Costo
	cout << "ESTADO " << c.getEstado() << endl;
	cout << "NOMBRE: " << c.getNombre() << endl;
	cout << "PRECIO TOTAL: " << c.getcostoTotal() << "g" << endl << endl;
	cd.Mostrar();
	c.Modificar(opc);

}

void Menu_Desarrollador::agregarConjunto()
{
	Conjunto_cabecera conjunto;
	Archivo arch(UB_CONCAB, sizeof(Conjunto_cabecera));

	//Cargo cabecera, si se carga correctamente se guarda detalle
	if (conjunto.Cargar())
	{
		if (arch.grabarRegistro(conjunto, -1, Modo::Agregar))
		{
			cout << "El conjunto se agrego correctamente" << endl;
		}
		else
		{
			cout << "Error al agregar el conjunto " << endl;
		}
	}
	else
	{
		return;
	}
	system("pause");
	return;

}

void Menu_Desarrollador::mostrarConjunto()
{
	Archivo archdet(UB_CONDET, sizeof(Conjunto_detalle));
	Archivo archcab(UB_CONCAB, sizeof(Conjunto_cabecera));
	cout << "LISTA DE CONJUNTOS" << endl << endl;
	cout << "CONJUNTOS CARGADOS" << endl << endl;

	//Creo las variables para mostrar

	Conjunto_cabecera c;
	Conjunto_detalle cd;

	int opc;

	//Muestro por pantalla todos los conjuntos activos

	c.MostrarCabecera();

	cout << endl << "Ingresa el ID para mostrar mas detalles (-1 para salir): ";

	//Pido ID del conjunto, que basicamente es la posicion del registro asi que mas adelante lo uso para el fseek
	cin >> opc;
	system("cls");

	if (opc == -1) return;

	//Creo un objeto dinamico solo para la verificacion

	Conjunto_cabecera* nc;
	nc = new Conjunto_cabecera;

	nc->setID(opc);

	//Verifico si existe el id ingresado
	if (archcab.buscarRegistro(*nc) == -1)
	{	//Si no, chau
		cout << "El registro no existe" << endl << endl;
		system("pause");
		return;
	}
	else
	{	//Si existe, se carga
		cout << "Se encontro el siguiente registro: " << endl << endl;
		archcab.leerRegistro(c, opc);
	}
	//Borro el objeto
	delete nc;

	cout << "CONJUNTO DETALLADO ------------------" << endl << endl;

	//Cabecera: Muestro Estado, Nombre y Costo
	cout << "ESTADO " << c.getEstado() << endl;
	cout << "NOMBRE: " << c.getNombre() << endl;
	cout << "PRECIO TOTAL: " << c.getcostoTotal() << "g" << endl << endl;

	//Cargo detalles de DETALLES en la posicion que mandaron
	archdet.leerRegistro(cd, opc - 1);
	cd.Mostrar();
	system("pause");

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
			cout << "Hubo un error al crear el backup, regresando a menu principal" << endl;
		}
		break;
	case 2:
		if (restoreFiles() == true) {
			cout << "Archivos restaurados con exito." << endl;
		}
		else {
			cout << "Hubo un error al restaurar el archivo, regresando a menu principal" << endl;
		}
		  break;
	case 0:
		menuPrincipal();
		break;
	}
	system("pause");

}


bool Menu_Desarrollador::backupFiles() {

	char opc;

	cout << "Desea hacer una copia de seguridad completa? presione 'S'" << endl;
	cout << "Para hacer una copia de campeones 'C'" << endl;
	cout << "Para una copia de items 'I'" << endl;
	cout << "Para una copia de conjuntos 'D' " << endl;
	cout << "Para volver al menu principal 'N'" << endl;
	cin >> opc;

	if (opc == 's' || opc == 'S')
	{
		//files
		Archivo archChamp(UB_CAMPEONES, sizeof(Campeon));
		Archivo archItem(UB_ITEMS, sizeof(Item));
		Archivo archCab(UB_CONCAB, sizeof(Conjunto_cabecera));
		Archivo archDet(UB_CONDET, sizeof(Conjunto_detalle));
		//bkp files
		Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
		Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
		Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
		Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

		Campeon champ;
		Item item;
		Conjunto_cabecera CCAB;
		Conjunto_detalle CDET;

		if (archChamp.crearBackup(champ, archChampbkp) == false)return false;

		if (archItem.crearBackup(item, archItembkp)==false)return false;

		if (archCab.crearBackup(CCAB, archCabbkp)==false)return false;

		if (archDet.crearBackup(CDET, archDetbkp)==false)return false;



		return true;
	}
	else if (opc == 'i' || opc == 'I')
	{
		//files
		Archivo archItem(UB_ITEMS, sizeof(Item));
		//bkp file

		Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));

		Item item;

		if (archItem.crearBackup(item, archItembkp) == false)return false;

		return true;
	}
	else if (opc == 'c' || opc == 'C')
	{
		//files
		Archivo archChamp(UB_CAMPEONES, sizeof(Campeon));
		//bkp file
		Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));

		Campeon champ;

		if (archChamp.crearBackup(champ, archChampbkp) == false)return false;

		return true;

	}
	else if (opc == 'd' || opc == 'D')
	{
		//files
		Archivo archCab(UB_CONCAB, sizeof(Conjunto_cabecera));
		Archivo archDet(UB_CONDET, sizeof(Conjunto_detalle));
		//bkp files
		Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
		Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

		Conjunto_cabecera CCAB;
		Conjunto_detalle CDET;

		if (archCab.crearBackup(CCAB, archCabbkp) == false)return false;

		if (archDet.crearBackup(CDET, archDetbkp) == false)return false;

		return true;
	}


	return false;
}

bool Menu_Desarrollador::restoreFiles()
{

	char opc;

	cout << "Desea hacer una restauracion completa? presione 'S'" << endl;
	cout << "Para hacer una restauracion de campeones 'C'" << endl;
	cout << "Para una restauracion de items 'I'" << endl;
	cout << "Para una restauracion de conjuntos 'D' " << endl;
	cout << "Para volver al menu principal 'N'" << endl;
	cin >> opc;

	if (opc == 's' || opc == 'S')
	{
		//files
		Archivo archChamp(UB_CAMPEONES, sizeof(Campeon));
		Archivo archItem(UB_ITEMS, sizeof(Item));
		Archivo archCab(UB_CONCAB, sizeof(Conjunto_cabecera));
		Archivo archDet(UB_CONDET, sizeof(Conjunto_detalle));
		//bkp files
		Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
		Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
		Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
		Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

		Campeon champ;
		Item item;
		Conjunto_cabecera CCAB;
		Conjunto_detalle CDET;

		if (archChampbkp.restoreBackup(champ, archChamp) == false)return false;

		if (archItembkp.restoreBackup(item, archItem) == false)return false;

		if (archCabbkp.restoreBackup(CCAB, archCab) == false)return false;

		if (archDetbkp.restoreBackup(CDET, archDet) == false)return false;


		return true;
	}
	else if (opc == 'i' || opc == 'I')
	{
		//files
		Archivo archItem(UB_ITEMS, sizeof(Item));
		//bkp file

		Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));

		Item item;

		if (archItembkp.restoreBackup(item, archItem) == false)return false;

		return true;
	}
	else if (opc == 'c' || opc == 'C')
	{
		//files
		Archivo archChamp(UB_CAMPEONES, sizeof(Campeon));
		//bkp file
		Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));

		Campeon champ;

		if (archChampbkp.restoreBackup(champ, archChamp) == false)return false;

		return true;
	}
	else if (opc == 'd' || opc == 'D')
	{
		//files
		Archivo archCab(UB_CONCAB, sizeof(Conjunto_cabecera));
		Archivo archDet(UB_CONDET, sizeof(Conjunto_detalle));
		//bkp files
		Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
		Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

		Conjunto_cabecera CCAB;
		Conjunto_detalle CDET;

		if (archCabbkp.restoreBackup(CCAB, archCab) == false)return false;

		if (archDetbkp.restoreBackup(CDET, archDet) == false)return false;

		return true;
	}
	else return false;


}

