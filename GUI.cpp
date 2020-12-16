#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <string>
#include <Windows.h>
#include <sstream>
#include "GUI.h"
#include "BotonGUI.h"
#include "devmenu.h"
#include "claseIngresoTxt.h"
#include "inputGUI.h"
#include "Item.h"
#include "Campeon.h"
#include "Archivo.h"
#include "Conjunto_cabecera.h"
#include "Conjunto_detalle.h"
#include "headerGUI.h"
#include "Leyenda.h"

const char* HEADER_MENUCAMPEONES = "resources/gui/header_champs.jpg";
const char* HEADER_MENUPRINCIPAL = "resources/gui/header_menuprincipal.jpg";
const char* HEADER_MENUITEMS = "resources/gui/header_items.jpg";
const char* HEADER_MENUCONJUNTOS = "resources/gui/header_conjuntos.jpg";


int contarRegistrosTrueConj() {
	Conjunto_cabecera aux;
	int i = 0, cant = 0;
	Archivo arch("resources/conjuntos/conjunto_cabecera.dat", sizeof aux);
	while (arch.leerRegistro(aux, i++)) if (aux.getEstado()) cant++;
	return cant;
}

int contarRegistrosTrueI()
{
	Item aux;
	int i = 0, cant = 0;
	Archivo arch("resources/items/itemsdata.dat", sizeof aux);
	while (arch.leerRegistro(aux, i++)) if (aux.getEstado()) cant++;
	return cant;
}

int contarRegistrosTrueC()
{
	Campeon aux;
	int i = 0, cant = 0;
	Archivo arch("resources/campeones/champsdata.dat", sizeof aux);
	while (arch.leerRegistro(aux, i++)) if (aux.getEstado()) cant++;
	return cant;
}

Menu::Menu()
{
	//Si es la primera vez que se ejecuta el programa, creo los archivos
	FILE* it, * ch, * condet, * concab;
	it = fopen("resources/items/itemsdata.dat", "ab");
	ch = fopen("resources/campeones/champsdata.dat", "ab");
	condet = fopen("resources/conjuntos/conjunto_detalle.dat", "ab");
	concab = fopen("resources/conjuntos/conjunto_cabecera.dat", "ab");

	fclose(it);
	fclose(ch);
	fclose(condet);
	fclose(concab);

	resolucionAlto = resolucionAncho = 0;
	cantidadPagListado = 0;
	actualPage = 1;

	ventana = new sf::RenderWindow;
	mouse = new clsMouse;
	StateMenu = EstadoMenu::MENUPRINCIPAL;

	bordes = new sf::RectangleShape;
	check = new bool[14]{ false };
	item = new Item;
	champ = new Campeon;

	infoEarly = new sf::Text[6];
	infoMid = new sf::Text[6];
	infoLate = new sf::Text[6];
	subtitulos = new sf::Text[4];

	headerMenu = new headerGUI;
	config.antialiasingLevel = 8;

	inputWindow = new inputGUI[20];
	btn = new BotonGUI[6];
	outputWindow = new outputGUI;
	encabezadoOutput = new iconosListado;

	if (mouse == NULL) return;
	if (btn == NULL) return;
}

void Menu::init(int _resAlto, int _resAncho)
{

	cajaTitulo.setSize({ 310, 40 });
	cajaTitulo.setFillColor(sf::Color(14, 22, 33, 255));

	//Crear la ventana del programa
	resolucionAlto = _resAlto;
	resolucionAncho = _resAncho;
	ventana->create(sf::VideoMode(resolucionAncho, resolucionAlto), "League of Builds", sf::Style::Close, config);

	//BORDES PARA EL MENU
	bordes->setSize({ 760, 560 });
	bordes->setFillColor(sf::Color::Transparent);
	bordes->setOutlineThickness(1.0f);
	bordes->setOutlineColor(sf::Color(6, 150, 170, 255));
	bordes->setPosition(20, 20);

	//FRAME RATE
	ventana->setFramerateLimit(30);

	if (fuente.loadFromFile("resources/fuentes/Roboto-Medium.ttf") == 0) return;
	titulo.setFont(fuente);
	titulo.setCharacterSize(23);
	titulo.setFillColor(sf::Color(184, 198, 240, 255));

	//cargarIconos();

	run();

}

void Menu::run()
{
	Menu_Desarrollador* devmenu;
	devmenu = new Menu_Desarrollador;
	sf::Cursor cursor;
	cursor.loadFromSystem(sf::Cursor::Hand);
	ventana->setMouseCursor(cursor);


	while (ventana->isOpen())
	{

		sf::Event evento;
		mouse->actualizarPosicion(*ventana);
		while (ventana->pollEvent(evento))
		{
			if (evento.type == sf::Event::Closed) ventana->close();

			for (int i = 0; i < 20; i++) if (lastIngreso == NULL) inputWindow[i].setSelected(false);

			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUALTA_ITEM) inputWindow[lastIngreso - 1].callEventoIngreso(evento);
			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUALTA_CHAMP) inputWindow[lastIngreso - 1].callEventoIngreso(evento);
			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUALTA_CONJ) inputWindow[lastIngreso - 1].callEventoIngreso(evento);
			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUMOD_ITEM) inputWindow[lastIngreso - 1].callEventoIngreso(evento);
			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUMOD_CHAMP) inputWindow[lastIngreso - 1].callEventoIngreso(evento);
			if (evento.type == sf::Event::TextEntered && StateMenu == EstadoMenu::MENUMOD_CONJ) inputWindow[lastIngreso - 1].callEventoIngreso(evento);

		}
		//INICIALIZACIONES PARA EL MENU PRINCIPAL, CUENTA CON UN BOOL QUE PROTEGE A LA FUNCION PARA QUE SE LLAME SOLO UNA VEZ 
		switch (StateMenu)
		{
		case EstadoMenu::MENUPRINCIPAL:
			menuPrincipal();
			break;
		case EstadoMenu::MENUDEV:

			ventana->clear(sf::Color(14, 22, 33, 255));
			devmenu->menuPrincipal();
			system("cls");
			if(devmenu->menuPrincipal() == 0) StateMenu = EstadoMenu::MENUPRINCIPAL;

			break;
		case EstadoMenu::MENUALTA_CHAMP:
			menualtaChamps();
			break;
		case EstadoMenu::MENUMOSTRAR_CHAMP:
			menumostrarChamps();
			break;
		case EstadoMenu::MENUBAJA_CHAMP:
			menubajaChamp();
			break;
		case EstadoMenu::MENUMOD_CHAMP:
			menumodChamp();
			break;
		case EstadoMenu::MENUCHAMP:
			menuCampeones();
			break;
		case EstadoMenu::MENUMASOPCIONES_CHAMP:
			menumasopcionesChamps();
			break;
		case EstadoMenu::MENUITEM:
			menuItems();
			break;
		case EstadoMenu::MENUALTA_ITEM:
			menualtaItems();
			break;
		case EstadoMenu::MENUBAJA_ITEM:
			menubajaItem();
			break;
		case EstadoMenu::MENUMOD_ITEM:
			menumodItem();
			break;
		case EstadoMenu::MENUMOSTRAR_ITEM:
			menumostrarItems();
			break;
		case EstadoMenu::MENUMASOPCIONES_ITEM:
			menumasopcionesItems();
			break;
		case EstadoMenu::MENUCONJ:
			menuConjuntos();
			break;
		case EstadoMenu::MENUBKP:
			menuBackup();
			break;
		case EstadoMenu::MENUALTA_CONJ:
			menualtaConj();
			break;
		case EstadoMenu::MENUBKP_CREATE:
			if (bkpCreate()) {
				std::cout << "Backups creados con exito" << std::endl;
			}
			else {
				std::cout << "Error creando backups" << std::endl;
			}
			protegido = false;
			StateMenu = EstadoMenu::MENUBKP;
			break;
		case EstadoMenu::MENUBKP_RESTORE:
			if (bkpRestore()) {
				std::cout << "Archivos restaurados con exito" << std::endl;
			}
			else {
				std::cout << "Error restaurando archivos" << std::endl;
			}
			protegido = false;
			StateMenu = EstadoMenu::MENUBKP;
			break;
		case EstadoMenu::MENUMOSTRAR_CONJ:
			menumostrarConjuntos();
			break;
		case EstadoMenu::MENUMASOPCIONES_CONJ:
			menumasopcionesConjuntos();
			break;
		case EstadoMenu::MENUMOD_CONJ:
			menumodConj();
			break;
		case EstadoMenu::MENUBAJA_CONJ:
			menubajaConj();
			break;
		case EstadoMenu::MENUDET_CONJ:
			menudetallesConj();
			break;
		default:
			break;
		}
		ventana->display();
	}

}
//MENU PRINCIPAL

void Menu::menudetallesConj()
{
	mostrarDetalle();

	btn[2].setBtnType(btnType::BTN_VOLVER);
	btn[2].setbothPos(50, 520);
	btn[2].settxtPos(90, 528);
	btn[2].setTextoString("Volver");
	btn[2].setSize(150.0f, 40.0f);

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			StateMenu = EstadoMenu::MENUMOSTRAR_CONJ;
			protegido = false;
		}
	}

	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));
	ventana->draw(*bordes);


	for (int i = 0; i < 6; i++)
	{
		ventana->draw(infoEarly[i]);
		ventana->draw(infoMid[i]);
		ventana->draw(infoLate[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		ventana->draw(subtitulos[i]);
	}

	outputWindow[lastIngresoOutput - 1].drawConjuntoOPC(ventana);

	ventana->draw(titulo);
	ventana->draw(*nombconj);
	ventana->draw(*idconj);
	ventana->draw(*idchamp);

	btn[2].dibujarBotoncito(*ventana);
}

void Menu::mostrarDetalle()
{
	if(!protegido)
	{

		delete[] infoEarly, infoMid, infoLate, subtitulos;

		titulo.setString("MOSTRANDO DETALLES DEL CONJUNTO");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);


		infoEarly = new sf::Text[6];
		infoMid = new sf::Text[6];
		infoLate = new sf::Text[6];
		subtitulos = new sf::Text[5];


		//ID del detalle
		int id_conjunto;
		std::string id_conjunto_s, stringAux;
		std::stringstream ss;

		//CONVERSION DE STRING A INT ---------------------------------------
		id_conjunto_s = outputWindow[lastIngresoOutput - 1].getId().getString();
		id_conjunto = std::stoi(id_conjunto_s) - 1;

		//Archivo
		Archivo archdet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
		Archivo archcab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
		Archivo architem("resources/items/itemsdata.dat", sizeof(Item));

		Conjunto_detalle* con_aux;
		con_aux = new Conjunto_detalle;
	
		Conjunto_cabecera* con_cab;
		con_cab = new Conjunto_cabecera;

		Item* it_aux;
		it_aux = new Item;

		archcab.leerRegistro(*con_cab, id_conjunto);
		archdet.leerRegistro(*con_aux, id_conjunto);

		for (int i = 0; i < 5; i++)
		{
			subtitulos[i].setFont(fuente);
			subtitulos[i].setFillColor(sf::Color(127, 127, 127, 255));
			subtitulos[i].setStyle(sf::Text::Bold);
			subtitulos[i].setCharacterSize(13);

			if (i < 4)
			{
				subtitulos[i].setOutlineColor(sf::Color::Black);
				subtitulos[i].setOutlineThickness(1.3f);
			}
			
		}
		float y = 230.0f;
		for (int i = 0; i < 6; i++)
		{
			infoEarly[i].setCharacterSize(12);
			infoMid[i].setCharacterSize(12);
			infoLate[i].setCharacterSize(12);

			infoEarly[i].setPosition({ 70, y });
			infoMid[i].setPosition({ 320, y });
			infoLate[i].setPosition({ 520, y });

			infoEarly[i].setFont(fuente);
			infoMid[i].setFont(fuente);
			infoLate[i].setFont(fuente);

			infoEarly[i].setString("");
			infoMid[i].setString("");
			infoLate[i].setString("");

			infoEarly[i].setFillColor(sf::Color::White);
			infoMid[i].setFillColor(sf::Color::White);
			infoLate[i].setFillColor(sf::Color::White);
			y += 20.0f;
		}
			

		//STRING DE SUBTITULOS 
		subtitulos[0].setString("EARLY GAME");
		subtitulos[0].setPosition({ 70, 190 });

		subtitulos[1].setString("MID GAME");
		subtitulos[1].setPosition({ 320, 190 });

		subtitulos[2].setString("LATE GAME");
		subtitulos[2].setPosition({ 520, 190 });

		subtitulos[3].setString("COSTO TOTAL");
		subtitulos[3].setPosition({ 70, 400 });

		//STRING DE LA INFO
		//Early
		for (int i = 0; i < 6; i++)
		{
			if (con_aux->getEarly()[i] > 0)
			{
				if (architem.leerRegistro(*it_aux, con_aux->getEarly()[i] - 1) == 1)
				{
					stringAux = it_aux->getNombre();
					infoEarly[i].setString(stringAux);
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (con_aux->getMid()[i] > 0)
			{
				std::cout << con_aux->getMid()[i] << std::endl;
				if (architem.leerRegistro(*it_aux, con_aux->getMid()[i] - 1) == 1)
				{
					stringAux = it_aux->getNombre();
					infoMid[i].setString(stringAux);
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (con_aux->getLate()[i] > 0)
			{
				std::cout << con_aux->getLate()[i] << std::endl;
				if (architem.leerRegistro(*it_aux, con_aux->getLate()[i] - 1) == 1)
				{
					stringAux = it_aux->getNombre();
					infoLate[i].setString(stringAux);
				}
			}
		}

	

		//Costo 
		ss.str("");
		ss << con_cab->getcostoTotal();
		stringAux = ss.str();

		subtitulos[4].setString(stringAux);
		subtitulos[4].setStyle(sf::Text::Regular);
		subtitulos[4].setColor(sf::Color::White);
		subtitulos[4].setPosition({ 210, 400 });

		delete con_aux, con_cab;
		protegido = true;

	}
}

void Menu::menuPrincipal()
{
	if (!protegido)
	{
		delete headerMenu;
		headerMenu = new headerGUI;
		cajaTitulo.setPosition(40.0f, 190.0f);
		titulo.setPosition(60.0f, 200.0f);
		titulo.setString("MENU PRINCIPAL");
		headerMenu->setTexture(HEADER_MENUPRINCIPAL);
	}

	inicializacionBotones();

	//CMD De cada botoncito
	for (int i = 0; i < 6; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);

	//UPDATE De cada botoncito
	for (int i = 0; i < 6; i++) btn[i].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));

	//DRAW De cada botoncito
	for (int i = 0; i < 6; i++)
	{
		btn[i].dibujarBotoncito(*ventana);
	}

	//DRAW titulo
	ventana->draw(headerMenu->getHeader());
	ventana->draw(cajaTitulo);
	ventana->draw(titulo);
	ventana->draw(*bordes);
}

//MENU DE CAMPEONES
void Menu::menuCampeones()
{
	//Consulto una vez la cantidad de campeones en registros
	if (!protegido) {
		delete headerMenu;
		headerMenu = new headerGUI;
		headerMenu->setTexture(HEADER_MENUCAMPEONES);
		cajaTitulo.setPosition(40.0f, 190.0f);
		titulo.setPosition(60.0f, 200.0f);
		if (!protegido) titulo.setString("MENU DE CAMPEONES");
		champsaMostrar = contarRegistrosTrueC();
	

		ley = new Leyenda;
		ley->leyendaini(fuente);
		ley->setPosition();
		
	}
	

	inicializacionBotones();

	//CMD De cada botoncito

	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	//UPDATE De cada botoncito

	for (int i = 0; i < 3; i++) btn[i].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));

	//DRAW De cada botoncito
	for (int i = 0; i < 3; i++)
	{
		btn[i].dibujarBotoncito(*ventana);
	}

	//DRAW titulo
	ley->draw(ventana);

	ventana->draw(headerMenu->getHeader());
	ventana->draw(cajaTitulo);
	ventana->draw(titulo);
	ventana->draw(*bordes);
}

void Menu::menualtaChamps()
{
	inicializacionaltaChamps();

	ventana->clear(sf::Color(14, 22, 33, 255));

	//Boton volver
	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);
	btn[2].dibujarBotoncito(*ventana);

	for (int i = 0; i < 14; i++) {
		check[i] = false;
	}
	for (int i = 0; i < 9; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}

	//1 nombre 2 ataque 3 velocidad de ataque 4 vida 
	//5 armadura 6 resistencia magica 7 mana 8 estilo 9 tipo danio

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInputChamps();
	}

	if (validarChecks(getCheck(), 9) == true) {
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
		champ->setID(arch.getCantidadRegistros() + 1);

		//Solo agregue esto
		champ->setEstado(true);

		if (arch.grabarRegistro(*champ, -1, Agregar) == 1)
		{
			std::cout << "Registro agregado" << std::endl;
		}
		else {
			std::cout << "Error agregando campeon" << std::endl;
		}
		 
		StateMenu = EstadoMenu::MENUCHAMP;
		protegido = false;
	}

	//DIBUJADO
	for (int i = 0; i < 9; i++)
	{
		inputWindow[i].draw(*ventana);
	}
	ventana->draw(*bordes);
	ventana->draw(titulo);
}

void Menu::menumodChamp()
{
	ventana->clear(sf::Color(14, 22, 33, 255));

	inicializacionmodificacionChamp();

	for (int i = 0; i < 14; i++) {
		check[i] = false;
	}
	for (int i = 0; i < 9; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}

	//1 nombre 2 ataque 3 velocidad de ataque 4 vida 
	//5 armadura 6 resistencia magica 7 mana 8 estilo 9 tipo danio

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInputChamps();
	}

	if (validarChecks(getCheck(), 9) == true) {
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
		std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();

		champ->setEstado(true);
		champ->setID(stoi(auxid));

		arch.grabarRegistro(*champ, stoi(auxid) - 1, LecturaEscritura);

		StateMenu = EstadoMenu::MENUCHAMP;
		protegido = false;
	}

	//DIBUJADO
	for (int i = 0; i < 9; i++)
	{
		inputWindow[i].draw(*ventana);
	}
	ventana->draw(*bordes);
	ventana->draw(titulo);

}

void Menu::menumasopcionesChamps()
{
	ventana->clear(sf::Color(14, 22, 33, 255));

	inicializacionBotones();
	titulo.setString("MAS OPCIONES...");

	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	for (int i = 0; i < 3; i++) btn[i].update(*ventana);

	encabezadoOutput->dibujarIconosC(ventana);
	outputWindow[lastIngresoOutput - 1].drawMenuMoreOPC_C(ventana);

	for (int i = 0; i < 3; i++) btn[i].dibujarBotoncito(*ventana);

	ventana->draw(titulo);
	ventana->draw(*bordes);
}

void Menu::menumostrarChamps()
{
	if (!protegido)
	{
		titulo.setString("LISTADO DE CAMPEONES");
		titulo.setPosition(60.0f, 30.0f);
	}

	leerArchivosChamps();

	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			StateMenu = EstadoMenu::MENUCHAMP;
			protegido = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		StateMenu = EstadoMenu::MENUCHAMP;
		protegido = false;
	}
	//COMANDOS
	//Algoritmo paginas
	if (cantidadPagListado != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout << cantidadPagListado << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Sleep(200);
			if (actualPage < cantidadPagListado) actualPage++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Sleep(200);
			if (actualPage != 1) actualPage--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < champsaMostrar; i++)
			{
				outputWindow[i].cmdC(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].cmdC(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}
	}

	btn[2].setbothPos(50, 520);
	btn[2].settxtPos(90, 528);
	btn[2].setSize(150.0f, 40.0f);


	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));

	//DIBUJADO DE LOS EGRESOS DE LA LISTA
	if (champsaMostrar <= 13)
	{
		for (int i = 0; i < champsaMostrar; i++)
		{
			outputWindow[i].drawC(ventana);
		}
	}
	else
	{
		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < champsaMostrar; i++)
			{
				outputWindow[i].drawC(ventana);
			}
		}
		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].drawC(ventana);
			}
		}

	}

	ventana->draw(titulo);
	ventana->draw(*bordes);
	encabezadoOutput->dibujarIconosC(ventana);
	btn[2].dibujarBotoncito(*ventana);

}

void Menu::menubajaChamp()
{
	std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();
	int pos = std::stoi(auxid) - 1;
	champ->BajaVirtual(pos);
	champsaMostrar--;
	if (champsaMostrar != 0) StateMenu = EstadoMenu::MENUMOSTRAR_CHAMP;
	else StateMenu = EstadoMenu::MENUCHAMP;
}

//MENU DE ITEMS
void Menu::menuItems()
{
	if (!protegido)
	{
		delete headerMenu;
		headerMenu = new headerGUI;
		headerMenu->setTexture(HEADER_MENUITEMS);
		cajaTitulo.setPosition(40.0f, 190.0f);
		titulo.setPosition(60.0f, 200.0f);
		titulo.setString("MENU DE ITEMS");
		itemsaMostrar = contarRegistrosTrueI();
	}

	inicializacionBotones();

	//CMD De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	//UPDATE De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));

	//DRAW De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].dibujarBotoncito(*ventana);


	//DRAW titulo
	ventana->draw(headerMenu->getHeader());
	ventana->draw(cajaTitulo);
	ventana->draw(titulo);
	ventana->draw(*bordes);
}

void Menu::menualtaItems()
{
	//devmenu->agregarItems();

	inicializacionaltaItems();

	ventana->clear(sf::Color(14, 22, 33, 255));

	//Boton volver
	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);
	btn[2].dibujarBotoncito(*ventana);

	//COMANDOS

	for (int i = 0; i < 14; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}

	//btn[5].cmd(*mouse, *ventana, &StateMenu, protegido);
	//btn[5].update(*ventana);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInput();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			protegido = false;
			StateMenu = EstadoMenu::MENUITEM;
		}
	}

	//Si todos los datos ingresados son validos se habilitaria la opcion de guardar
	if (validarChecks(getCheck(), 14) == true) {
		Archivo arch("resources/items/itemsdata.dat", sizeof(Item));
		item->setID(arch.getCantidadRegistros() + 1);
		if (arch.grabarRegistro(*item, -1, Agregar) == 1)
		{
			std::cout << "Registro agregado" << std::endl;
		}
		StateMenu = EstadoMenu::MENUITEM;
		protegido = false;
	}

	//DIBUJADOS

	for (int i = 0; i < 14; i++)
	{
		inputWindow[i].draw(*ventana);
	}

	//btn[5].dibujarBotoncito(*ventana);
	ventana->draw(*bordes);
	ventana->draw(titulo);
}

void Menu::menumodItem()
{
	inicializacionmodificacionItems();

	ventana->clear(sf::Color(14, 22, 33, 255));

	//COMANDOS

	for (int i = 0; i < 14; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInput();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			protegido = false;
			StateMenu = EstadoMenu::MENUITEM;
		}
	}

	//Si todos los datos ingresados son validos se habilitaria la opcion de guardar
	if (validarChecks(getCheck(), 14) == true) {
		Archivo arch("resources/items/itemsdata.dat", sizeof(Item));
		std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();

		item->setEstado(true);
		item->setID(stoi(auxid));
		arch.grabarRegistro(*item, stoi(auxid) - 1, LecturaEscritura);
		protegido = false;
		StateMenu = EstadoMenu::MENUITEM;
	}

	//DIBUJADOS

	for (int i = 0; i < 14; i++)
	{
		inputWindow[i].draw(*ventana);
	}

	//btn[5].dibujarBotoncito(*ventana);
	ventana->draw(*bordes);
	ventana->draw(titulo);
}

void Menu::menubajaItem()
{
	std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();
	int pos = stoi(auxid) - 1;
	item->BajaVirtual(pos);
	itemsaMostrar--;
	if (itemsaMostrar != 0) StateMenu = EstadoMenu::MENUMOSTRAR_ITEM;
	else StateMenu = EstadoMenu::MENUITEM;
}

void Menu::menumostrarItems()
{

	if (!protegido)
	{
		titulo.setPosition(60.0f, 30.0f);
		titulo.setString("LISTADO DE ITEMS");
	}

	leerArchivosItems();


	btn[2].setbothPos(50, 520);
	btn[2].settxtPos(90, 528);
	btn[2].setSize(150.0f, 40.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			StateMenu = EstadoMenu::MENUITEM;
			protegido = false;
		}
	}

	//13 registros seria lo ideal para mostrar por pantalla

	// COMANDOS -------------------

	//Algoritmo paginas
	if (cantidadPagListado != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout << cantidadPagListado << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Sleep(200);
			if (actualPage < cantidadPagListado) actualPage++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Sleep(200);
			if (actualPage != 1) actualPage--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < itemsaMostrar; i++)
			{
				outputWindow[i].cmd(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].cmd(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}
	}

	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);

	// UPDATE ---------------------

	//DIBUJOS ---------------------
	ventana->clear(sf::Color(14, 22, 33, 255));

	

	//DIBUJADO DE LOS EGRESOS DE LA LISTA
	if (itemsaMostrar <= 13)
	{
		for (int i = 0; i < itemsaMostrar; i++)
		{
			outputWindow[i].draw(ventana);
		}
	}
	else
	{
		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < itemsaMostrar; i++)
			{
				outputWindow[i].draw(ventana);
			}
		}
		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].draw(ventana);
			}
		}

	}

	encabezadoOutput->dibujarIconos(ventana);
	ventana->draw(titulo);
	ventana->draw(*bordes);
	btn[2].dibujarBotoncito(*ventana);
}

void Menu::menumasopcionesItems()
{
	ventana->clear(sf::Color(14, 22, 33, 255));
	inicializacionBotones();
	titulo.setString("MAS OPCIONES...");

	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	for (int i = 0; i < 3; i++) btn[i].update(*ventana);

	encabezadoOutput->dibujarIconos(ventana);
	outputWindow[lastIngresoOutput - 1].drawMenuMoreOPC(ventana);

	for (int i = 0; i < 3; i++) btn[i].dibujarBotoncito(*ventana);

	ventana->draw(titulo);
	ventana->draw(*bordes);
	
}

//MENU DE BKP
void Menu::menuBackup()
{
	if (!protegido)
	{
		titulo.setPosition(60.0f, 200.0f);
		titulo.setString("MENU DE BACKUP");
	}
	inicializacionBotones();
	//CMD De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	//UPDATE De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].update(*ventana);
	//clear
	ventana->clear(sf::Color(14, 22, 33, 255));
	//DRAW
	for (int i = 0; i < 3; i++)
	{
		btn[i].dibujarBotoncito(*ventana);
	}
	ventana->draw(*bordes);
}

bool Menu::bkpRestore() {
	//files
	Archivo archChamp("resources/campeones/champsdata.dat", sizeof(Campeon));
	Archivo archItem("resources/items/itemsdata.dat", sizeof(Item));
	Archivo archCab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	Archivo archDet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//bkp files
	Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
	Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
	Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
	Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

	champ = new Campeon;
	item = new Item;
	conjcab = new Conjunto_cabecera;
	conjdet = new Conjunto_detalle;

	if (archChampbkp.restoreBackup(*champ, archChamp) == false)return false;
	if (archItembkp.restoreBackup(*item, archItem) == false)return false;
	if (archCabbkp.restoreBackup(*conjcab, archCab) == false)return false;
	if (archDetbkp.restoreBackup(*conjdet, archDet) == false)return false;

	delete(champ);
	delete(item);
	delete(conjcab);
	delete(conjdet);
	return true;
}

bool Menu::bkpCreate() {
	//files
	Archivo archChamp("resources/campeones/champsdata.dat", sizeof(Campeon));
	Archivo archItem("resources/items/itemsdata.dat", sizeof(Item));
	Archivo archCab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	Archivo archDet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//bkp files
	Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
	Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
	Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
	Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

	champ = new Campeon;
	item = new Item;
	conjcab = new Conjunto_cabecera;
	conjdet = new Conjunto_detalle;

	if (archChamp.crearBackup(*champ, archChampbkp) == false)return false;
	if (archItem.crearBackup(*item, archItembkp) == false)return false;
	if (archCab.crearBackup(*conjcab, archCabbkp) == false)return false;
	if (archDet.crearBackup(*conjdet, archDetbkp) == false)return false;

	delete(champ);
	delete(item);
	delete(conjcab);
	delete(conjdet);
	return true;
}

//MENU DE CONJ

void Menu::menuConjuntos()
{
	if (!protegido)
	{
		delete headerMenu;
		headerMenu = new headerGUI;
		headerMenu->setTexture(HEADER_MENUCONJUNTOS);
		cajaTitulo.setPosition(40.0f, 190.0f);
		titulo.setPosition(60.0f, 200.0f);
		titulo.setString("MENU DE CONJUNTOS");
		conjsaMostrar = contarRegistrosTrueConj();
	}
	inicializacionBotones();
	//CMD De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	//UPDATE De cada botoncito
	for (int i = 0; i < 3; i++) btn[i].update(*ventana);
	//clear
	ventana->clear(sf::Color(14, 22, 33, 255));
	//draw
	for (int i = 0; i < 3; i++)
	{
		btn[i].dibujarBotoncito(*ventana);
	}
	ventana->draw(headerMenu->getHeader());
	ventana->draw(cajaTitulo);
	ventana->draw(titulo);
	ventana->draw(*bordes);
}

void Menu::menualtaConj() {
	inicializacionaltaConj();
	ventana->clear(sf::Color(14, 22, 33, 255));

	//Boton volver

	btn[2].setbothPos(600, 530);
	btn[2].settxtPos(640, 538);
	btn[2].setSize(150.0f, 40.0f);


	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);
	

	//COMANDOS

	for (int i = 0; i < 20; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}
	//IFENTERPRESSED
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInputConj();
	}
	//VALIDARGUARDAR acordarse de setear la id de conjcab
	if (validarChecks(getCheck(), 20) == true)
	{
		Archivo archdetalle("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
		Archivo archcab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
		//Seteo el ID de ccab
		conjcab->setidConjunto();
		//ID cdet
		conjdet->setDetalle(conjcab->getidConjunto());

		conjcab->setEstado(true);
		conjdet->setEstado(true);

		//guardo y seteo el costo
		if (archdetalle.grabarRegistro(*conjdet, -1, Agregar))
		{
			conjcab->setCostototal(conjcab->getCosto());
			archcab.grabarRegistro(*conjcab, -1, Agregar);
			std::cout << "Conjunto agregado" << std::endl;
		}
		StateMenu = EstadoMenu::MENUCONJ;
		protegido = false;

	}
	//DRAW
	for (int i = 0; i < 20; i++)
	{
		inputWindow[i].draw(*ventana);
	}
	ventana->draw(*bordes);
	btn[2].dibujarBotoncito(*ventana);
}

void Menu::menubajaConj()
{
	std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();
	Archivo arch("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));

	delete conjcab;
	conjcab = new Conjunto_cabecera;
	int pos = stoi(auxid) - 1;

	conjcab->BajaVirtual(pos);

	conjsaMostrar--;
	if (conjsaMostrar != 0) StateMenu = EstadoMenu::MENUMOSTRAR_CONJ;
	else StateMenu = EstadoMenu::MENUCONJ;
}

void Menu::menumodConj()
{
	inicializacionmodificacionConj();
	ventana->clear(sf::Color(14, 22, 33, 255));

	//COMANDOS

	for (int i = 0; i < 20; i++)
	{
		inputWindow[i].comandoInput(mouse, &lastIngreso);
	}
	//IFENTERPRESSED
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInputConj();
	}
	//VALIDARGUARDAR acordarse de setear la id de conjcab
	if (validarChecks(getCheck(), 20) == true)
	{
		Archivo archdetalle("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
		Archivo archcab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));

		std::string auxid = outputWindow[lastIngresoOutput - 1].getId().getString();

		//Seteo el ID 
		conjcab->setID(stoi(auxid));
		conjdet->setDetalle(stoi(auxid));
		
		conjcab->setEstado(true);
		conjdet->setEstado(true);

		//guardo y seteo el costo
		if (archdetalle.grabarRegistro(*conjdet, stoi (auxid) -1,LecturaEscritura))
		{
			conjcab->setCostototal(conjcab->getCosto());
			archcab.grabarRegistro(*conjcab, stoi(auxid) - 1, LecturaEscritura);
			std::cout << "Conjunto modificado" << std::endl;
		}
		StateMenu = EstadoMenu::MENUCONJ;
		protegido = false;

	}
	//DRAW
	for (int i = 0; i < 20; i++)
	{
		inputWindow[i].draw(*ventana);
	}
	ventana->draw(*bordes);
}

void Menu::menumasopcionesConjuntos()
{
	
	inicializacionBotones();
	titulo.setString("MAS OPCIONES...");

	for (int i = 0; i < 4; i++) btn[i].cmd(*mouse, *ventana, &StateMenu, &protegido);
	for (int i = 0; i < 4; i++) btn[i].update(*ventana);

	ventana->clear(sf::Color(14, 22, 33, 255));
	//encabezadoOutput->dibujarIconos(ventana);
	outputWindow[lastIngresoOutput - 1].drawConjuntoOPC(ventana);

	for (int i = 0; i < 4; i++) btn[i].dibujarBotoncito(*ventana);

	ventana->draw(titulo);
	ventana->draw(*nombconj);
	ventana->draw(*idconj);
	ventana->draw(*idchamp);
	ventana->draw(*bordes);
}

void Menu::menumostrarConjuntos() {
	ventana->clear(sf::Color(14, 22, 33, 255));
	if (!protegido)
	{
		titulo.setPosition(60.0f, 30.0f);
		titulo.setString("LISTADO DE CONJUNTOS");
	}

	leerArchivosConjuntos();

	btn[2].setBtnType(btnType::BTN_VOLVER);
	btn[2].setTextoString("Volver");
	btn[2].setbothPos(50, 520);
	btn[2].settxtPos(90, 528);
	btn[2].setSize(150.0f, 40.0f);

	// COMANDOS -------------------
	//Algoritmo paginas
	if (cantidadPagListado != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout << cantidadPagListado << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Sleep(200);
			if (actualPage < cantidadPagListado) actualPage++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Sleep(200);
			if (actualPage != 1) actualPage--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < conjsaMostrar; i++)
			{
				outputWindow[i].cmdConjuntos(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].cmdConjuntos(mouse, &protegido, &StateMenu, &lastIngresoOutput);
			}
		}
	}

	btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	btn[2].update(*ventana);

	if (conjsaMostrar <= 13)
	{
		for (int i = 0; i < conjsaMostrar; i++)
		{
			//std::cout << conjsaMostrar << endl;
			outputWindow[i].drawConjunto(ventana);
		}
	}
	else
	{
		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < conjsaMostrar; i++)
			{
				outputWindow[i].drawConjunto(ventana);
			}
		}
		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].drawConjunto(ventana);
			}
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		StateMenu = EstadoMenu::MENUCONJ;
		protegido = false;
	}
	btn[2].dibujarBotoncito(*ventana);
	ventana->draw(*nombconj);
	ventana->draw(*idconj);
	ventana->draw(*idchamp);
	ventana->draw(*bordes);
	ventana->draw(titulo);

}

void Menu::leerArchivosConjuntos() {
	if (!protegido) {
		actualPage = 1;

		delete(nombconj);
		delete(idconj);
		delete(idchamp);

		nombconj = new sf::Text;
		idconj = new sf::Text;
		idchamp = new sf::Text;

		nombconj->setFont(fuente);
		idconj->setFont(fuente);
		idchamp->setFont(fuente);

		nombconj->setCharacterSize(12);
		idconj->setCharacterSize(12);
		idchamp->setCharacterSize(12);

		nombconj->setFillColor(sf::Color::White);
		idconj->setFillColor(sf::Color::White);
		idchamp->setFillColor(sf::Color::White);

		nombconj->setString("NOMBRE DEL CONJUNTO");
		idconj->setString("ID CONJUNTO");
		idchamp->setString("CHAMP");

		nombconj->setPosition(62.0f, 90.0f);
		idconj->setPosition(300.0f, 90.0f);
		idchamp->setPosition(500.0f, 90.0f);

		Conjunto_cabecera auxcab;
		Conjunto_detalle auxdet;

		Archivo* archcab;
		archcab = new Archivo("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
		float y = 120;
		//Variable j para leer todos los registros, variable k para leer el registro especifico
		int j = 0, k = 0;
		//cuantas paginas voy a mostrar
		conjsaMostrar = contarRegistrosTrueConj();


		//Declaro un float auxiliar para saber los decimales y le hago los casteos
		float auxFloat = (float)conjsaMostrar / (float)13;
		//Entero sin decimales
		cantidadPagListado = conjsaMostrar / 13;

		//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
		auxFloat = auxFloat - (float)cantidadPagListado;
		if (auxFloat != 0.0) cantidadPagListado++;

		//La cantidad de registros es igual a la cantidad de egresos
		if (cantidadPagListado == 0) outputWindow = new outputGUI;
		else outputWindow = new outputGUI[conjsaMostrar];

		//Inicializacion de la clase
		for (int i = 0; i < conjsaMostrar; i++)
		{
			outputWindow[i] = outputGUI(&fuente);


		}
		//Seteos de la posicion


		for (int i = 0; i < conjsaMostrar; i++)
		{
			outputWindow[i].setidOutput(i + 1);
			if (i % 13 == 0) {
				y = 120.0f;
				outputWindow[i].setPosicionConj(y);
				y += 30.0f;
			}
			else {
				outputWindow[i].setPosicionConj(y);
				y += 30.0f;
			}

		}

		//Ahora queda pasar los datos de los registros a los egresos

		while (archcab->leerRegistro(auxcab, j) == 1)
		{
			if (auxcab.getEstado())
			{
				//Sobrecarga de operador
				outputWindow[k] = auxcab;
				k++;
			}
			j++;
		}
		protegido = true;
	}
}

// -----------------

void Menu::inicializacionmodificacionConj()
{
	if (!protegido)
	{
		delete conjcab;
		conjcab = new Conjunto_cabecera;
		delete check;
		check = new bool[20]{ false };
		delete conjdet;
		conjdet = new Conjunto_detalle;

		//Cargo en las variables de conjunto lo que hay en el archivo

		Archivo* archdet, *archcab;
		archcab = new Archivo("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
		archdet = new Archivo("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));

		archcab->leerRegistro(*conjcab, lastIngresoOutput - 1);
		archdet->leerRegistro(*conjdet, lastIngresoOutput - 1);

		//btn[5].setBtnType(btnType::BTN_GUARDAR);
		//btn[5].setbtnPos(510, 500);
		//btn[5].setTextoString("GUARDAR");

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("MODIFICACION CONJUNTO");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);
		// ---------------------------------------------

		for (int i = 0; i < 20; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 30);
		inputWindow[0].setStringSubtitulo("ID CAMPEON");


		inputWindow[1].setPos(55, 110);
		inputWindow[1].setStringSubtitulo("ID ITEM EARLY 1");

		inputWindow[2].setPos(55, 190);
		inputWindow[2].setStringSubtitulo("ID ITEM EARLY 2");

		inputWindow[3].setPos(55, 270);
		inputWindow[3].setStringSubtitulo("ID ITEM EARLY 3");

		inputWindow[4].setPos(55, 350);
		inputWindow[4].setStringSubtitulo("ID ITEM EARLY 4");

		inputWindow[5].setPos(55, 430);
		inputWindow[5].setStringSubtitulo("ID ITEM EARLY 5");

		inputWindow[6].setPos(55, 510);
		inputWindow[6].setStringSubtitulo("ID ITEM EARLY 6");

		inputWindow[7].setPos(235, 110);
		inputWindow[7].setStringSubtitulo("ID ITEM MID 1");

		inputWindow[8].setPos(235, 190);
		inputWindow[8].setStringSubtitulo("ID ITEM MID 2");

		inputWindow[9].setPos(235, 270);
		inputWindow[9].setStringSubtitulo("ID ITEM MID 3");

		inputWindow[10].setPos(235, 350);
		inputWindow[10].setStringSubtitulo("ID ITEM MID 4");

		inputWindow[11].setPos(235, 430);
		inputWindow[11].setStringSubtitulo("ID ITEM MID 5");

		inputWindow[12].setPos(235, 510);
		inputWindow[12].setStringSubtitulo("ID ITEM MID 6");

		inputWindow[13].setPos(415, 110);
		inputWindow[13].setStringSubtitulo("ID ITEM LATE 1");

		inputWindow[14].setPos(415, 190);
		inputWindow[14].setStringSubtitulo("ID ITEM LATE 2");

		inputWindow[15].setPos(415, 270);
		inputWindow[15].setStringSubtitulo("ID ITEM LATE 3");

		inputWindow[16].setPos(415, 350);
		inputWindow[16].setStringSubtitulo("ID ITEM LATE 4");

		inputWindow[17].setPos(415, 430);
		inputWindow[17].setStringSubtitulo("ID ITEM LATE 5");

		inputWindow[18].setPos(415, 510);
		inputWindow[18].setStringSubtitulo("ID ITEM LATE 6");

		inputWindow[19].setPos(235, 30);
		inputWindow[19].setStringSubtitulo("NOMBRE DEL CONJUNTO");
		inputWindow[19].setSizeRectangulo(280, 30);
		inputWindow[19].setLimiteIngreso(30);

		protegido = true;
		delete archcab;
		delete archdet;
	}
	
}

void Menu::inicializacionmodificacionItems()
{
	if (!protegido)
	{
		delete item;
		item = new Item;
		delete check;

		Archivo* arch;
		arch = new Archivo("resources/items/itemsdata.dat", sizeof(Item));
		arch->leerRegistro(*item, lastIngresoOutput - 1);

		check = new bool[14]{ false };

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("EDITAR ITEM");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);
		// ---------------------------------------------

		for (int i = 0; i < 14; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 80);
		inputWindow[0].setStringSubtitulo("NOMBRE DEL ITEM");
		inputWindow[0].setSizeRectangulo(280, 30);
		inputWindow[0].setLimiteIngreso(30);

		inputWindow[1].setPos(55, 160);
		inputWindow[1].setStringSubtitulo("ATAQUE");

		inputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
		inputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

		inputWindow[3].setPos(55, 240);
		inputWindow[3].setStringSubtitulo("PODER DE HABILIDAD");

		inputWindow[4].setPos(55, 320);
		inputWindow[4].setStringSubtitulo("MANA");

		inputWindow[5].setPos(235, 320);
		inputWindow[5].setStringSubtitulo("REGENERACION MANA");

		inputWindow[6].setPos(55, 400);
		inputWindow[6].setStringSubtitulo("VIDA");

		inputWindow[7].setPos(235, 400);
		inputWindow[7].setStringSubtitulo("REGENERACION VIDA");

		inputWindow[8].setPos(55, 480);
		inputWindow[8].setStringSubtitulo("ARMADURA");

		inputWindow[9].setPos(235, 480);
		inputWindow[9].setStringSubtitulo("RESISTENCIA MAGICA");

		inputWindow[10].setPos(510, 80);
		inputWindow[10].setStringSubtitulo("ROBO DE VIDA");

		inputWindow[11].setPos(510, 160);
		inputWindow[11].setStringSubtitulo("PROBABILIDAD DE CRITICO");

		inputWindow[12].setPos(510, 240);
		inputWindow[12].setStringSubtitulo("ACELERACION DE HABILIDAD");

		inputWindow[13].setPos(510, 320);
		inputWindow[13].setStringSubtitulo("COSTO");

		protegido = true;
		delete arch;
	}

}

void Menu::verificacionInputConj() {

	std::string algo;
	int auxi = 0;
	char auxc[30] = {};

	/*
	0 ID CHAMP
	1 ID ITEM E 1
	2 ID ITEM E 2
	3 ID ITEM E 3
	4 ID ITEM E 4
	5 ID ITEM E 5
	6 ID ITEM E 6
	7 ID ITEM M 1
	8 ID ITEM M 2
	9 ID ITEM M 3
	10 ID ITEM M 4
	11 ID ITEM M 5
	12 ID ITEM M 6
	13 ID ITEM L 1
	14 ID ITEM L 2
	15 ID ITEM L 3
	16 ID ITEM L 4
	17 ID ITEM L 5
	18 ID ITEM L 6
	19 NOMBRE CONJUNTO
	*/
	//IDCHAMP

	algo = inputWindow[0].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[0].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjcab->setidCampeon(auxi);
		if (conjcab->idchampcheck(conjcab->getidCampeon()))
		{
			check[0] = true;
			inputWindow[0].setColor(sf::Color::Green);
		}
		else inputWindow[0].setColor(sf::Color::Red);
	}
	//NOMBRE
	algo = inputWindow[19].getTextoIngreso();
	for (int i = 0; i < algo.length(); i++) {
		auxc[i] = algo[i];
	}
	std::cout << "Nombre ingresado: " << std::endl;
	conjcab->setNombre(auxc);
	std::cout << conjcab->getNombre() << std::endl;
	if (conjcab->validarNombre(auxc) == true) {
		check[19] = true;
		inputWindow[19].setColor(sf::Color::Green);
	}
	else inputWindow[19].setColor(sf::Color::Red);
	//ID ITEMS EARLY 1 
	algo = inputWindow[1].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[1].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);

		conjdet->setidEarly(auxi, 0);//iditem,pos del vec
		std::cout << "EARLY INGRESADO " << conjdet->getidEarly(0) << std::endl;
		if (conjdet->iditemcheck(conjdet->getidEarly(0))) {
			check[1] = true;
			inputWindow[1].setColor(sf::Color::Green);
		}
		else inputWindow[1].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 2
	algo = inputWindow[2].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[2].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(1))) {
			check[2] = true;
			inputWindow[2].setColor(sf::Color::Green);
		}
		else inputWindow[2].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 3
	algo = inputWindow[3].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[3].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(2))) {
			check[3] = true;
			inputWindow[3].setColor(sf::Color::Green);
		}
		else inputWindow[3].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 4
	algo = inputWindow[4].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[4].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidEarly(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(3))) {
			check[4] = true;
			inputWindow[4].setColor(sf::Color::Green);
		}
		else inputWindow[4].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 5
	algo = inputWindow[5].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[5].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidEarly(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(4))) {
			check[5] = true;
			inputWindow[5].setColor(sf::Color::Green);
		}
		else inputWindow[5].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 6
	algo = inputWindow[6].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[6].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(5))) {
			check[6] = true;
			inputWindow[6].setColor(sf::Color::Green);
		}
		else inputWindow[6].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 1
	algo = inputWindow[7].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[7].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 0);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(0))) {
			check[7] = true;
			inputWindow[7].setColor(sf::Color::Green);
		}
		else inputWindow[7].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 2
	algo = inputWindow[8].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[8].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(1))) {
			check[8] = true;
			inputWindow[8].setColor(sf::Color::Green);
		}
		else inputWindow[8].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 3
	algo = inputWindow[9].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[9].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(2))) {
			check[9] = true;
			inputWindow[9].setColor(sf::Color::Green);
		}
		else inputWindow[9].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 4
	algo = inputWindow[10].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[10].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(3))) {
			check[10] = true;
			inputWindow[10].setColor(sf::Color::Green);
		}
		else inputWindow[10].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 5
	algo = inputWindow[11].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[11].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidMid(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(4))) {
			check[11] = true;
			inputWindow[11].setColor(sf::Color::Green);
		}
		else inputWindow[11].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 6
	algo = inputWindow[12].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[12].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidMid(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(5))) {
			check[12] = true;
			inputWindow[12].setColor(sf::Color::Green);
		}
		else inputWindow[12].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 1
	algo = inputWindow[13].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[13].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidLate(auxi, 0);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(0))) {
			check[13] = true;
			inputWindow[13].setColor(sf::Color::Green);
		}
		else inputWindow[13].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 2
	algo = inputWindow[14].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[14].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(1))) {
			check[14] = true;
			inputWindow[14].setColor(sf::Color::Green);
		}
		else inputWindow[14].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 3
	algo = inputWindow[15].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[15].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(2))) {
			check[15] = true;
			inputWindow[15].setColor(sf::Color::Green);
		}
		else inputWindow[15].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 4
	algo = inputWindow[16].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[16].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(3))) {
			check[16] = true;
			inputWindow[16].setColor(sf::Color::Green);
		}
		else inputWindow[16].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 5
	algo = inputWindow[17].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[17].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(4))) {
			check[17] = true;
			inputWindow[17].setColor(sf::Color::Green);
		}
		else inputWindow[17].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 6
	algo = inputWindow[18].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[18].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(5))) {
			check[18] = true;
			inputWindow[18].setColor(sf::Color::Green);
		}
		else inputWindow[18].setColor(sf::Color::Red);
	}
}

void Menu::inicializacionaltaConj() {
	if (!protegido)
	{
		delete conjcab;
		conjcab = new Conjunto_cabecera;
		delete check;
		check = new bool[20]{ false };
		delete conjdet;
		conjdet = new Conjunto_detalle;

		conjsaMostrar = contarRegistrosTrueConj();

		//volver
		btn[2].setbothPos(600.0f, 520.0f);
		btn[2].settxtPos(640.0f, 530.0f);
		btn[2].setBtnType(btnType::BTN_VOLVER);
		btn[2].setTextoString("Volver");

		//btn[5].setBtnType(btnType::BTN_GUARDAR);
		//btn[5].setbtnPos(510, 500);
		//btn[5].setTextoString("GUARDAR");

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("AGREGAR CONJUNTO");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);
		// ---------------------------------------------

		for (int i = 0; i < 20; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 30);
		inputWindow[0].setStringSubtitulo("ID CAMPEON");


		inputWindow[1].setPos(55, 110);
		inputWindow[1].setStringSubtitulo("ID ITEM EARLY 1");

		inputWindow[2].setPos(55, 190);
		inputWindow[2].setStringSubtitulo("ID ITEM EARLY 2");

		inputWindow[3].setPos(55, 270);
		inputWindow[3].setStringSubtitulo("ID ITEM EARLY 3");

		inputWindow[4].setPos(55, 350);
		inputWindow[4].setStringSubtitulo("ID ITEM EARLY 4");

		inputWindow[5].setPos(55, 430);
		inputWindow[5].setStringSubtitulo("ID ITEM EARLY 5");

		inputWindow[6].setPos(55, 510);
		inputWindow[6].setStringSubtitulo("ID ITEM EARLY 6");

		inputWindow[7].setPos(235, 110);
		inputWindow[7].setStringSubtitulo("ID ITEM MID 1");

		inputWindow[8].setPos(235, 190);
		inputWindow[8].setStringSubtitulo("ID ITEM MID 2");

		inputWindow[9].setPos(235, 270);
		inputWindow[9].setStringSubtitulo("ID ITEM MID 3");

		inputWindow[10].setPos(235, 350);
		inputWindow[10].setStringSubtitulo("ID ITEM MID 4");

		inputWindow[11].setPos(235, 430);
		inputWindow[11].setStringSubtitulo("ID ITEM MID 5");

		inputWindow[12].setPos(235, 510);
		inputWindow[12].setStringSubtitulo("ID ITEM MID 6");

		inputWindow[13].setPos(415, 110);
		inputWindow[13].setStringSubtitulo("ID ITEM LATE 1");

		inputWindow[14].setPos(415, 190);
		inputWindow[14].setStringSubtitulo("ID ITEM LATE 2");

		inputWindow[15].setPos(415, 270);
		inputWindow[15].setStringSubtitulo("ID ITEM LATE 3");

		inputWindow[16].setPos(415, 350);
		inputWindow[16].setStringSubtitulo("ID ITEM LATE 4");

		inputWindow[17].setPos(415, 430);
		inputWindow[17].setStringSubtitulo("ID ITEM LATE 5");

		inputWindow[18].setPos(415, 510);
		inputWindow[18].setStringSubtitulo("ID ITEM LATE 6");

		inputWindow[19].setPos(235, 30);
		inputWindow[19].setStringSubtitulo("NOMBRE DEL CONJUNTO");
		inputWindow[19].setSizeRectangulo(280, 30);
		inputWindow[19].setLimiteIngreso(30);

		protegido = true;
	}
}

void Menu::leerArchivosItems()
{
	//13 registros seria lo ideal para mostrar por pantalla


	if (!protegido)
	{
		delete encabezadoOutput;
		encabezadoOutput = new iconosListado;

		encabezadoOutput->setFuente(&fuente);
		encabezadoOutput->setPosY(90.0f);

		actualPage = 1;
		Item aux;
		Archivo* arch;
		arch = new Archivo("resources/items/itemsdata.dat", sizeof(Item));
		float y = 120;

		//Variable j para leer todos los registros, variable k para leer el registro especifico
		int j = 0, k = 0;

		//Borro lo que habia antes en la clase 
		if (cantidadPagListado == 0) delete outputWindow;
		else delete[] outputWindow;
		//Consulto cuantos registros de item hay con true

		//Tambien veo cuantas paginas voy a tener
		itemsaMostrar = contarRegistrosTrueI();
		///////////////////////////////////////////////////////////
		// Esto es para saber cuantas paginas va a tener la lista
		///////////////////////////////////////////////////////////

		//Declaro un float auxiliar para saber los decimales y le hago los casteos
		float auxFloat = (float)itemsaMostrar / (float)13;
		//Entero sin decimales

		cantidadPagListado = itemsaMostrar / 13;

		//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
		auxFloat = auxFloat - (float)cantidadPagListado;
		if (auxFloat != 0.0) cantidadPagListado++;

		//La cantidad de registros es igual a la cantidad de egresos
		if (cantidadPagListado == 0) outputWindow = new outputGUI;
		else outputWindow = new outputGUI[itemsaMostrar];

		//Inicializacion de la clase
		for (int i = 0; i < itemsaMostrar; i++)
		{
			outputWindow[i] = outputGUI(&fuente);
		}
		//Seteos de la posicion
		//TODO: Faltaria fixear la posicion en cada pagina (Listo)
		for (int i = 0; i < itemsaMostrar; i++)
		{
			outputWindow[i].setidOutput(i + 1);
			if (i % 13 == 0)
			{
				y = 120.0f;
				outputWindow[i].setPosicion(y, false);
				y += 30.0f;

			}
			else
			{
				outputWindow[i].setPosicion(y, false);
				y += 30.0f;
			}

		}

		//Ahora queda pasar los datos de los registros a los egresos


		while (arch->leerRegistro(aux, j) == 1)
		{
			if (aux.getEstado())
			{
				//Sobrecarga de operador
				outputWindow[k] = aux;
				k++;
			}
			j++;
		}

		protegido = true;


		delete arch;
	}
}

void Menu::leerArchivosChamps()
{
	if (!protegido)
	{
		delete encabezadoOutput;

		encabezadoOutput = new iconosListado;
		encabezadoOutput->setFuente(&fuente);

		//Cada vez que se llame a esta funcion, el encabezado se seteara aca
		encabezadoOutput->setposxAtaque(222.0f);
		encabezadoOutput->setposxvelAtaque(287.0f);
		encabezadoOutput->setposxVida(352.0f);
		encabezadoOutput->setposxArmor(417.0f);
		encabezadoOutput->setposxresMagica(482.0f);
		encabezadoOutput->setposxMana(547.0f);
		encabezadoOutput->setposxDmg(597.0f);
		encabezadoOutput->setposxEstilo(692.0f);

		actualPage = 1;

		//ARCHIVO DE CAMPEONES
		Campeon aux;
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));

		float y = 120;

		//Variable j para leer todos los registros, variable k para leer el registro especifico
		int j = 0, k = 0;

		//Borro lo que habia antes en la clase 
		if (cantidadPagListado == 0) delete outputWindow;
		else delete[] outputWindow;

		//Consulto cuantos registros de item hay con true

		//Tambien veo cuantas paginas voy a tener
		champsaMostrar = contarRegistrosTrueC();
		///////////////////////////////////////////////////////////
		// Esto es para saber cuantas paginas va a tener la lista
		///////////////////////////////////////////////////////////

		//Declaro un float auxiliar para saber los decimales y le hago los casteos
		float auxFloat = (float)champsaMostrar / (float)13;
		//Entero sin decimales

		cantidadPagListado = champsaMostrar / 13;

		//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
		auxFloat = auxFloat - (float)cantidadPagListado;
		if (auxFloat != 0.0) cantidadPagListado++;

		//La cantidad de registros es igual a la cantidad de egresos

		if (cantidadPagListado == 0)outputWindow = new outputGUI;
		else outputWindow = new outputGUI[champsaMostrar];

		//Inicializacion de la clase
		for (int i = 0; i < champsaMostrar; i++)
		{
			outputWindow[i] = outputGUI(&fuente, 12);
		}

		//Seteos de la posicion
		//TODO: Faltaria fixear la posicion en cada pagina (Listo)

		for (int i = 0; i < champsaMostrar; i++)
		{
			outputWindow[i].setidOutput(i + 1);

			if (i % 13 == 0)
			{
				y = 120.0f;
				outputWindow[i].setPosicion(y, true);
				y += 30.0f;

			}
			else
			{
				outputWindow[i].setPosicion(y, true);
				y += 30.0f;
			}

		}

		//Ahora queda pasar los datos de los registros a los egresos


		while (arch.leerRegistro(aux, j++) == 1)
		{
			if (aux.getEstado())
			{
				//Sobrecarga de operador
				outputWindow[k] = aux;
				k++;
			}
		}
		protegido = true;

	}
}

void Menu::verificacionInputChamps() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		std::string algo;
		char auxc[30] = {};
		float auxf = 0;
		int auxi = 0;
		std::cout << lastIngreso << std::endl;

		//NOMBRE
		algo = inputWindow[0].getTextoIngreso();
		for (int i = 0; i < algo.length(); i++) {
			auxc[i] = algo[i];
		}
		std::cout << "Nombre ingresado: " << std::endl;
		champ->setNombre(auxc);
		std::cout << champ->getNombre() << std::endl;
		if (champ->validarNombre(auxc) == true) {
			check[0] = true;
			inputWindow[0].setColor(sf::Color::Green);
		}
		else inputWindow[0].setColor(sf::Color::Red);
		//ATAQUE
		algo = inputWindow[1].getTextoIngreso();
		if (!validarNum(algo)) {
			inputWindow[1].setColor(sf::Color::Red);
		}
		else
		{
			auxf = stof(algo);
			champ->setAtaque(auxf);
			std::cout << "Ataque ingresado: " << std::endl;
			std::cout << champ->getAtaque() << std::endl;
			if (champ->validarAtaque(auxf)) {
				check[1] = true;
				inputWindow[1].setColor(sf::Color::Green);
			}
			else inputWindow[1].setColor(sf::Color::Red);
		}
		//VEL. ATAQUE
		algo = inputWindow[2].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[2].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setVel_ataque(auxf);
			std::cout << "Velocidad de ataque: " << std::endl;
			std::cout << champ->getVel_ataque() << std::endl;
			if (champ->validarVa(auxf)) {
				check[2] = true;
				inputWindow[2].setColor(sf::Color::Green);
			}
			else inputWindow[2].setColor(sf::Color::Red);
		}
		//VIDA
		algo = inputWindow[3].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[3].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setVida(auxf);
			std::cout << "Vida: " << std::endl;
			std::cout << champ->getVida() << std::endl;
			if (champ->validarVida(auxf)) {
				check[3] = true;
				inputWindow[3].setColor(sf::Color::Green);
			}
			else inputWindow[3].setColor(sf::Color::Red);
		}
		//ARMOR
		algo = inputWindow[4].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[4].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setArmor(auxf);
			std::cout << "Armadura: " << std::endl;
			std::cout << champ->getArmor() << std::endl;
			if (champ->validarArmor(auxf)) {
				check[4] = true;
				inputWindow[4].setColor(sf::Color::Green);
			}
			else inputWindow[4].setColor(sf::Color::Red);
		}
		//RES. MAGICA
		algo = inputWindow[5].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[5].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setResistencia_magica(auxf);
			std::cout << "Resistencia magica: " << std::endl;
			std::cout << champ->getResistencia_magica() << std::endl;
			if (champ->validarRM(auxf)) {
				check[5] = true;
				inputWindow[5].setColor(sf::Color::Green);
			}
			else inputWindow[5].setColor(sf::Color::Red);
		}
		//MANA
		algo = inputWindow[6].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[6].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setMana(auxf);
			std::cout << "Mana: " << std::endl;
			std::cout << champ->getMana() << std::endl;
			if (champ->validarMana(auxf)) {
				check[6] = true;
				inputWindow[6].setColor(sf::Color::Green);
			}
			else inputWindow[6].setColor(sf::Color::Red);
		}
		//ESTILO
		algo = inputWindow[7].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[7].setColor(sf::Color::Red);
		else
		{
			auxi = stoi(algo);
			champ->setEstilo(auxi);
			std::cout << "Estilo: " << std::endl;
			switch (champ->getEstilo()) {
			case 1:
				std::cout << "Rol: Luchador" << std::endl;
				break;
			case 2:
				std::cout << "Rol: Mago" << std::endl;
				break;
			case 3:
				std::cout << "Rol: Asesino" << std::endl;
				break;
			case 4:
				std::cout << "Rol: Soporte" << std::endl;
				break;
			case 5:
				std::cout << "Rol: Tanque" << std::endl;
				break;
			case 6:
				std::cout << "Rol: Tirador" << std::endl;
				break;
			default:
				std::cout << "ERROR CARGANDO ROL" << std::endl;
			}
			if (champ->validarEstilo(auxi)) {
				check[7] = true;
				inputWindow[7].setColor(sf::Color::Green);
			}
			else inputWindow[7].setColor(sf::Color::Red);
		}
		//TIPODMG8
		algo = inputWindow[8].getTextoIngreso();
		if (!validarNum(algo)) inputWindow[8].setColor(sf::Color::Red);
		else
		{
			auxi = stoi(algo);
			champ->setdmgType(auxi);
			std::cout << "Tipo dmg: " << std::endl;
			switch (champ->getDmg()) {
			case 1:
				std::cout << "Tipo de danio: AD" << std::endl;
				break;
			case 2:
				std::cout << "Tipo de danio: AP" << std::endl;
				break;
			default:
				std::cout << "ERROR CARGANDO ESTILO" << std::endl;
			}
			if (champ->validarTipodmg(auxi)) {
				check[8] = true;
				inputWindow[8].setColor(sf::Color::Green);
			}
			else inputWindow[8].setColor(sf::Color::Red);
		}
	}
}

bool Menu::validarNum(std::string& num) {
	if (num[0] == '0' || num[0] == '1' || num[0] == '2' || num[0] == '3' || num[0] == '4' || num[0] == '5' || num[0] == '6' || num[0] == '7' || num[0] == '8' || num[0] == '9') {
		std::cout << "Num valido" << std::endl;
		return true;
	}
	std::cout << "Num invalido" << std::endl;
	return false;
}

bool Menu::validarChecks(bool checks[], int tam) {
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

void Menu::verificacionInput()
{
	std::string algo;
	char auxc[30] = {};
	float auxf = 0;
	int auxi = 0;
	//voy poniendolos true mientras se vayan validando y se va a poder guardar cuando los 14 esten en true;
	//1 nombre //inputWindow[num-1] 
	//2 ataque
	//3 vel de ataque
	//4 ap
	//5 mana
	//6 reg mana
	//7 vida
	//8 reg vida
	//9 armadura
	//10 resistencia mag
	//11 robo de vida
	//12 prob critico
	//13 cooldown
	//14 costo

		//NOMBRE
	algo = inputWindow[0].getTextoIngreso();
	for (int i = 0; i < algo.length(); i++) {
		auxc[i] = algo[i];
	}
	std::cout << "Nombre ingresado: " << std::endl;
	item->setNombre(auxc);
	std::cout << item->getNombre() << std::endl;
	if (item->validarNombre(auxc) == true) {
		check[0] = true;
		inputWindow[0].setColor(sf::Color::Green);
	}
	else inputWindow[0].setColor(sf::Color::Red);


	//ATAQUE
	algo = inputWindow[1].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[1].setColor(sf::Color::Red);
	}
	else
	{
		auxf = stof(algo);
		item->setAtaque(auxf);
		std::cout << "Ataque ingresado: " << std::endl;
		std::cout << item->getAtaque() << std::endl;
		if (item->validarAtaque(auxf)) {
			check[1] = true;
			inputWindow[1].setColor(sf::Color::Green);
		}
		else inputWindow[1].setColor(sf::Color::Red);
	}
	//VEL. ATAQUE
	algo = inputWindow[2].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[2].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setVel_ataque(auxf);
		std::cout << "Velocidad de ataque: " << std::endl;
		std::cout << item->getVel_ataque() << std::endl;
		if (item->validarVa(auxf)) {
			check[2] = true;
			inputWindow[2].setColor(sf::Color::Green);
		}
		else inputWindow[2].setColor(sf::Color::Red);
	}

	//AP
	algo = inputWindow[3].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[3].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setPoder_habilidad(auxf);
		std::cout << "Poder de habilidad: " << std::endl;
		std::cout << item->getPoder_habilidad() << std::endl;
		if (item->validarPh(auxf)) {
			check[3] = true;
			inputWindow[3].setColor(sf::Color::Green);
		}
		else inputWindow[3].setColor(sf::Color::Red);
	}

	//MANA
	algo = inputWindow[4].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[4].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setMana(auxf);
		std::cout << "Mana: " << std::endl;
		std::cout << item->getMana() << std::endl;
		if (item->validarMana(auxf)) {
			check[4] = true;
			inputWindow[4].setColor(sf::Color::Green);
		}
		else inputWindow[4].setColor(sf::Color::Red);
	}

	//REG. MANA
	algo = inputWindow[5].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[5].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setregMana(auxf);
		std::cout << "Reg mana: " << std::endl;
		std::cout << item->getregMana() << std::endl;
		if (item->validarRegmana(auxf)) {
			check[5] = true;
			inputWindow[5].setColor(sf::Color::Green);
		}
		else inputWindow[5].setColor(sf::Color::Red);
	}

	//VIDA
	algo = inputWindow[6].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[6].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setVida(auxf);
		std::cout << "Vida: " << std::endl;
		std::cout << item->getVida() << std::endl;
		if (item->validarVida(auxf)) {
			check[6] = true;
			inputWindow[6].setColor(sf::Color::Green);
		}
		else inputWindow[6].setColor(sf::Color::Red);
	}

	//REG DE VIDA
	algo = inputWindow[7].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[7].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setregVida(auxf);
		std::cout << "Reg de vida: " << std::endl;
		std::cout << item->getregVida() << std::endl;
		if (item->validarRegvida(auxf)) {
			check[7] = true;
			inputWindow[7].setColor(sf::Color::Green);
		}
		else inputWindow[7].setColor(sf::Color::Red);
	}

	//ARMADURA
	algo = inputWindow[8].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[8].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setArmor(auxf);
		std::cout << "Armadura: " << std::endl;
		std::cout << item->getArmor() << std::endl;
		if (item->validarArmor(auxf)) {
			check[8] = true;
			inputWindow[8].setColor(sf::Color::Green);
		}
		else inputWindow[8].setColor(sf::Color::Red);
	}

	//RES. MAGICA
	algo = inputWindow[9].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[9].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setResistencia_magica(auxf);
		std::cout << "Resistencia magica: " << std::endl;
		std::cout << item->getResistencia_magica() << std::endl;
		if (item->validarRM(auxf)) {
			check[9] = true;
			inputWindow[9].setColor(sf::Color::Green);
		}
		else inputWindow[9].setColor(sf::Color::Red);
	}

	//ROBO DE VIDA
	algo = inputWindow[10].getTextoIngreso();
	if (!validarNum(algo)) inputWindow[10].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setlifeSteal(auxf);
		std::cout << "Robo de vida: " << std::endl;
		std::cout << item->getlifeSteal() << std::endl;
		if (item->validarRobovida(auxf)) {
			check[10] = true;
			inputWindow[10].setColor(sf::Color::Green);
		}
		else inputWindow[10].setColor(sf::Color::Red);

	}

	//CRITICO
	algo = inputWindow[11].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[11].setColor(sf::Color::Red);
	}
	else
	{
		auxf = std::stof(algo);
		item->setCrit_chance(auxf);
		std::cout << "Critico: " << std::endl;
		std::cout << (float)item->getCrit_chance() << std::endl;
		if (item->validarCrit(auxf)) {
			check[11] = true;
			inputWindow[11].setColor(sf::Color::Green);
		}
		else inputWindow[11].setColor(sf::Color::Red);
	}


	//REDUCCION DE ENFRIAMIENTO
	algo = inputWindow[12].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[12].setColor(sf::Color::Red);
	}
	else
	{
		auxf = std::stof(algo);
		item->setCDR(auxf);
		std::cout << "Reduccion enfriamiento: " << std::endl;
		std::cout << item->getCDR() << std::endl;
		if (item->validarCDR(auxf)) {
			check[12] = true;
			inputWindow[12].setColor(sf::Color::Green);
		}
		else inputWindow[12].setColor(sf::Color::Red);
	}

	//COSTO
	algo = inputWindow[13].getTextoIngreso();
	if (!validarNum(algo)) {
		inputWindow[13].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		item->setCosto(auxi);
		std::cout << "Costo: " << std::endl;
		std::cout << item->getCosto() << std::endl;
		if (item->validarCosto(auxi)) {
			check[13] = true;
			inputWindow[13].setColor(sf::Color::Green);
		}
		else inputWindow[13].setColor(sf::Color::Red);
	}

}

void Menu::inicializacionaltaChamps()
{
	if (protegido == false)
	{

		btn[2].setbothPos(510.0f, 500.0f);
		btn[2].settxtPos(550.0f, 510.0f);
		btn[2].setBtnType(btnType::BTN_VOLVER);
		btn[2].setTextoString("Volver");

		//BORDES PARA EL MENU
		bordes->setSize({ 760, 560 });
		bordes->setFillColor(sf::Color::Transparent);
		bordes->setOutlineThickness(1.0f);
		bordes->setOutlineColor(sf::Color(6, 150, 170, 255));
		bordes->setPosition(20, 20);

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("AGREGAR CAMPEONES");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);

		for (int i = 0; i < 9; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 80);
		inputWindow[0].setStringSubtitulo("NOMBRE DEL CAMPEON");
		inputWindow[0].setSizeRectangulo(280, 30);
		inputWindow[0].setLimiteIngreso(30);

		inputWindow[1].setPos(55, 160);
		inputWindow[1].setStringSubtitulo("ATAQUE");

		inputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
		inputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

		inputWindow[3].setPos(55, 240);
		inputWindow[3].setStringSubtitulo("VIDA");

		inputWindow[4].setPos(55, 320);
		inputWindow[4].setStringSubtitulo("ARMADURA");

		inputWindow[5].setPos(235, 320);
		inputWindow[5].setStringSubtitulo("RESISTENCIA MAGICA");

		inputWindow[6].setPos(55, 400);
		inputWindow[6].setStringSubtitulo("MANA ");

		inputWindow[7].setPos(235, 400);
		inputWindow[7].setStringSubtitulo("ESTILO");
		inputWindow[7].setLimiteIngreso(10);

		inputWindow[8].setPos(55, 480);
		inputWindow[8].setStringSubtitulo("TIPO DE DAÑO");
		inputWindow[8].setLimiteIngreso(3);
		protegido = true;
	}
}

void Menu::inicializacionaltaItems()
{

	if (!protegido)
	{
		delete item;
		item = new Item;
		delete check;
		check = new bool[14]{ false };

		btn[2].setbothPos(510.0f, 500.0f);
		btn[2].settxtPos(550.0f, 510.0f);
		btn[2].setBtnType(btnType::BTN_VOLVER);
		btn[2].setTextoString("Volver");

		//btn[5].setBtnType(btnType::BTN_GUARDAR);
		//btn[5].setbtnPos(510, 500);
		//btn[5].setTextoString("GUARDAR");

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("AGREGAR ITEMS");
		titulo.setFont(fuente);
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);
		// ---------------------------------------------

		for (int i = 0; i < 14; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 80);
		inputWindow[0].setStringSubtitulo("NOMBRE DEL ITEM");
		inputWindow[0].setSizeRectangulo(280, 30);
		inputWindow[0].setLimiteIngreso(30);

		inputWindow[1].setPos(55, 160);
		inputWindow[1].setStringSubtitulo("ATAQUE");

		inputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
		inputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

		inputWindow[3].setPos(55, 240);
		inputWindow[3].setStringSubtitulo("PODER DE HABILIDAD");

		inputWindow[4].setPos(55, 320);
		inputWindow[4].setStringSubtitulo("MANA");

		inputWindow[5].setPos(235, 320);
		inputWindow[5].setStringSubtitulo("REGENERACION MANA");

		inputWindow[6].setPos(55, 400);
		inputWindow[6].setStringSubtitulo("VIDA");

		inputWindow[7].setPos(235, 400);
		inputWindow[7].setStringSubtitulo("REGENERACION VIDA");

		inputWindow[8].setPos(55, 480);
		inputWindow[8].setStringSubtitulo("ARMADURA");

		inputWindow[9].setPos(235, 480);
		inputWindow[9].setStringSubtitulo("RESISTENCIA MAGICA");

		inputWindow[10].setPos(510, 80);
		inputWindow[10].setStringSubtitulo("ROBO DE VIDA");

		inputWindow[11].setPos(510, 160);
		inputWindow[11].setStringSubtitulo("PROBABILIDAD DE CRITICO");

		inputWindow[12].setPos(510, 240);
		inputWindow[12].setStringSubtitulo("ACELERACION DE HABILIDAD");

		inputWindow[13].setPos(510, 320);
		inputWindow[13].setStringSubtitulo("COSTO");

		protegido = true;

	}

}

void Menu::inicializacionmodificacionChamp()
{
	if (!protegido)
	{
		delete champ;
		champ = new Campeon;
		delete check;

		Archivo* arch;
		arch = new Archivo("resources/campeones/champsdata.dat", sizeof(Campeon));
		arch->leerRegistro(*item, lastIngresoOutput - 1);

		check = new bool[14]{ false };

		//TITULO DEL SUBMENU -------------------------

		titulo.setString("EDITAR CAMPEON");
		titulo.setCharacterSize(23);
		titulo.setPosition(60, 30);
		// ---------------------------------------------



		for (int i = 0; i < 9; i++)
		{
			inputWindow[i] = inputGUI(&fuente);
			inputWindow[i].setID(i + 1);
			inputWindow[i].setLimiteIngreso(5);
		}

		inputWindow[0].setPos(55, 80);
		inputWindow[0].setStringSubtitulo("NOMBRE DEL CAMPEON");
		inputWindow[0].setSizeRectangulo(280, 30);
		inputWindow[0].setLimiteIngreso(30);

		inputWindow[1].setPos(55, 160);
		inputWindow[1].setStringSubtitulo("ATAQUE");

		inputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
		inputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

		inputWindow[3].setPos(55, 240);
		inputWindow[3].setStringSubtitulo("VIDA");

		inputWindow[4].setPos(55, 320);
		inputWindow[4].setStringSubtitulo("ARMADURA");

		inputWindow[5].setPos(235, 320);
		inputWindow[5].setStringSubtitulo("RESISTENCIA MAGICA");

		inputWindow[6].setPos(55, 400);
		inputWindow[6].setStringSubtitulo("MANA ");

		inputWindow[7].setPos(235, 400);
		inputWindow[7].setStringSubtitulo("ESTILO");
		inputWindow[7].setLimiteIngreso(10);

		inputWindow[8].setPos(55, 480);
		inputWindow[8].setStringSubtitulo("TIPO DE DAÑO");
		inputWindow[8].setLimiteIngreso(3);

		protegido = true;
		delete arch;
	}
}

void Menu::inicializacionBotones()
{
	if (!protegido)
	{
		delete[] btn;
		btn = new BotonGUI[6];

		switch (StateMenu)
		{
		case EstadoMenu::MENUPRINCIPAL:
			//0: MENU CHAMPS
			btn[0].setbothPos(80.0f, 280.0f);
			btn[0].settxtPos(100.0f, 290.0f);
			btn[0].setBtnEstado(Estado::NINGUNO);
			btn[0].setBtnType(btnType::BTN_CHAMPS);
			btn[0].setTextoString("Menu Campeones");
			//1: MENU ITEMS
			btn[1].setbothPos(80.0f, 380.0f);
			btn[1].settxtPos(110.0f, 390.0f);
			btn[1].setBtnEstado(Estado::NINGUNO);
			btn[1].setBtnType(btnType::BTN_ITEMS);
			btn[1].setTextoString("Menu Items");
			//2: MENU CONJUNTOS
			btn[2].setbothPos(80.0f, 480.0f);
			btn[2].settxtPos(100.0f, 490.0f);
			btn[2].setBtnEstado(Estado::NINGUNO);
			btn[2].setBtnType(btnType::BTN_CONJ);
			btn[2].setTextoString("Menu Conjuntos");
			//3: BACKUP
			btn[3].setbothPos(480.0f, 280.0f);
			btn[3].settxtPos(510.0f, 290.0f);
			btn[3].setBtnEstado(Estado::NINGUNO);
			btn[3].setBtnType(btnType::BTN_BACKUP);
			btn[3].setTextoString("Menu Backups");
			//4: DEVMENU
			btn[4].setbothPos(480.0f, 380.0f);
			btn[4].settxtPos(525.0f, 390.0f);
			btn[4].setBtnEstado(Estado::NINGUNO);
			btn[4].setBtnType(btnType::BTN_DEVMENU);
			btn[4].setTextoString("DevMenu");
			//5: SALIR
			btn[5].setbothPos(480.0f, 480.0f);
			btn[5].settxtPos(540.0f, 490.0f);
			btn[5].setBtnType(btnType::BTN_SALIR);
			btn[5].setTextoString("Salir");
			break;

		case EstadoMenu::MENUCHAMP:
			//0 Agregar campeon
			btn[0].setbothPos(80.0f, 280.0f);
			btn[0].setBtnType(btnType::BTN_ADD_CHAMP);
			btn[0].setTextoString("Agregar Campeon");
			//1 Mostrar campeones

			//Si no hay nada para mostrar deshabilito la opcion de listado

			if (champsaMostrar == 0) btn[1].setBtnEstado(Estado::DESHABILITADO);
			else btn[1].setBtnEstado(Estado::NINGUNO);

			btn[1].setbothPos(80.0f, 390.0f);
			btn[1].setBtnType(btnType::BTN_LIST_CHAMP);
			btn[1].setTextoString("Listar Campeones");

			//2 Volver
			btn[2].setbothPos(80.0f, 480.0f);
			btn[2].settxtPos(140.0f, 490.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;

		case EstadoMenu::MENUITEM:
			//0 Agregar item
			btn[0].setbothPos(80.0f, 280.0f);
			btn[0].setBtnType(btnType::BTN_ADD_ITEM);
			btn[0].setTextoString("Agregar Items");
			//1 Mostrar items
			if (itemsaMostrar == 0) btn[1].setBtnEstado(Estado::DESHABILITADO);
			else btn[1].setBtnEstado(Estado::NINGUNO);
			btn[1].setbothPos(480.0f, 280.0f);
			btn[1].setBtnType(btnType::BTN_LIST_ITEM);
			btn[1].setTextoString("Mostrar Items");
			//2 Volver
			btn[2].setbothPos(80.0f, 480.0f);
			btn[2].settxtPos(140.0f, 490.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;
		case EstadoMenu::MENUMASOPCIONES_ITEM:
			//1 Borrar item
			btn[0].setbothPos(50.0f, 300.0f);
			btn[0].setBtnType(btnType::BTN_DEL_ITEM);
			btn[0].setTextoString("Borrar Item");
			//2 Editar item
			btn[1].setbothPos(250.0f, 300.0f);
			btn[1].setBtnType(btnType::BTN_MOD_ITEM);
			btn[1].setTextoString("Editar Item");
			//2 Volver
			btn[2].setbothPos(500.0f, 300.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;
		case EstadoMenu::MENUMASOPCIONES_CHAMP:
			//1 Borrar item
			btn[0].setbothPos(50.0f, 300.0f);
			btn[0].setBtnType(btnType::BTN_DEL_CHAMP);
			btn[0].setTextoString("Borrar Campeon");
			//2 Editar item
			btn[1].setbothPos(250.0f, 300.0f);
			btn[1].setBtnType(btnType::BTN_MOD_CHAMP);
			btn[1].setTextoString("Editar Campeon");
			//2 Volver
			btn[2].setbothPos(500.0f, 300.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;
		case EstadoMenu::MENUMASOPCIONES_CONJ:
			btn[0].setbothPos(80.0f, 300.0f);
			btn[0].setBtnType(btnType::BTN_DET_CONJ);
			btn[0].setTextoString("Mostrar Detalles");
			//1 Borrar 
			btn[1].setbothPos(500.0f, 420.0f);
			btn[1].setBtnType(btnType::BTN_DEL_CONJ);
			btn[1].setTextoString("Borrar conjunto");
			//2 Editar
			btn[2].setbothPos(500.0f, 300.0f);
			btn[2].setBtnType(btnType::BTN_MOD_CONJ);
			btn[2].setTextoString("Editar conjunto");
			//2 Volver
			btn[3].setbothPos(80.0f, 420.0f);
			btn[3].setBtnType(btnType::BTN_VOLVER);
			btn[3].setTextoString("Volver");
			break;
		case EstadoMenu::MENUCONJ:

			btn[0].setbothPos(80.0f, 280.0f);
			btn[0].setBtnType(btnType::BTN_ADD_CONJ);
			btn[0].setTextoString("Agregar Conjunto");

			if (conjsaMostrar == 0) btn[1].setBtnEstado(Estado::DESHABILITADO);
			else btn[1].setBtnEstado(Estado::NINGUNO);

			btn[1].setbothPos(480.0f, 280.0f);
			btn[1].setBtnType(btnType::BTN_LIST_CONJ);
			btn[1].setTextoString("Mostrar Conjunto");

			btn[2].setbothPos(80.0f, 480.0f);
			btn[2].settxtPos(140.0f, 490.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;

		case EstadoMenu::MENUBKP:
			btn[0].setbothPos(80.0f, 280.0f);
			btn[0].setBtnType(btnType::BTN_CREATE_BKP);
			btn[0].setTextoString("Crear Backup");

			btn[1].setbothPos(480.0f, 480.0f);
			btn[1].setBtnType(btnType::BTN_RESTORE_BKP);
			btn[1].setTextoString("Restaurar Backup");

			btn[2].setbothPos(500.0f, 300.0f);
			btn[2].setBtnType(btnType::BTN_VOLVER);
			btn[2].setTextoString("Volver");
			break;
		}
		protegido = true;

	}

}

//Asi se copia de string a un char array
//strcpy(nombre, textbox.getText().c_str());

/*void Menu::cargarIconos()
{
	if (!(tex.loadFromFile("resources/items/items.png")))return;
	tex.setSmooth(true);
	int j, k, l, m, n, o, p, q, r, s;
	j = k = l = m = n = o = p = q = r = s = 0;

	for (int i = 0; i < 154; i++)
	{
		iconosT[i].setSize({ 42, 42 });
		iconosT[i].setTexture(&tex);
		if (i <= 14)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * i, 64 * 0, 64, 64));
			iconosT[i].setPosition({ 42.0f * i,  42.0f * 0.0f });
		}
		if (i >= 15 && i < 30)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * j, 64 * 1, 64, 64));
			iconosT[i].setPosition({ 42.0f * j,  42.0f * 1.0f });
			j++;
		}
		if (i >= 30 && i < 45)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * k, 64 * 2, 64, 64));
			iconosT[i].setPosition({ 42.0f * k,  42.0f * 2.0f });
			k++;
		}
		if (i >= 45 && i < 60)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * l, 64 * 3, 64, 64));
			iconosT[i].setPosition({ 42.0f * l,  42.0f * 3.0f });
			l++;
		}
		if (i >= 60 && i < 75)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * m, 64 * 4, 64, 64));
			iconosT[i].setPosition({ 42.0f * m,  42.0f * 4.0f });
			m++;
		}
		if (i >= 75 && i < 90)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * n, 64 * 5, 64, 64));
			iconosT[i].setPosition({ 42.0f * n,  42.0f * 5.0f });
			n++;
		}
		if (i >= 90 && i < 105)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * o, 64 * 6, 64, 64));
			iconosT[i].setPosition({ 42.0f * o,  42.0f * 6.0f });
			o++;
		}
		if (i >= 105 && i < 120)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * p, 64 * 7, 64, 64));
			iconosT[i].setPosition({ 42.0f * p,  42.0f * 7.0f });
			p++;
		}
		if (i >= 120 && i < 135)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * q, 64 * 8, 64, 64));
			iconosT[i].setPosition({ 42.0f * q,  42.0f * 8.0f });
			q++;
		}
		if (i >= 135 && i < 150)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * r, 64 * 9, 64, 64));
			iconosT[i].setPosition({ 42.0f * r,  42.0f * 9.0f });
			r++;
		}
		if (i >= 150 && i < 154)
		{
			iconosT[i].setTextureRect(sf::IntRect(64 * s, 64 * 10, 64, 64));
			iconosT[i].setPosition({ 42.0f * s,  42.0f * 10.0f });
			s++;
		}

		tex.setSmooth(true);
	}

}*/
