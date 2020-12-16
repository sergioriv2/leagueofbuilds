#pragma once

#include "clsMouse.h"
#include "enums.h"
#include "BotonGUI.h"
#include "claseIngresoTxt.h"
#include "Item.h"
#include "Campeon.h"
#include "Conjunto_cabecera.h"
#include "Conjunto_detalle.h"
#include "inputGUI.h"
#include "outputGUI.h"
#include "iconosListado.h"
#include "headerGUI.h"
#include "Leyenda.h"

class Menu
{
private:

	//LA HITBOX DEL MOUSE
	clsMouse* mouse;

	//PROPIEDADES DE LA VENTANA
	sf::RenderWindow* ventana;
	int resolucionAncho;
	int resolucionAlto;
	bool protegido = false;
	//Cantidad de paginas de listado
	int cantidadPagListado;
	//Cantidad de items a mostrar
	int itemsaMostrar;
	//Cantidad de champs a mostrar
	int champsaMostrar;
	//cantidad de conjs a mostrar
	int conjsaMostrar;

	int actualPage;
	int lastIngreso = 0;
	int lastIngresoOutput = 0;

	headerGUI* headerMenu;
	sf::ContextSettings config;

	//Para listar Conjuntos
	sf::Text* infoEarly;
	sf::Text* infoMid;
	sf::Text* infoLate;
	sf::Text* subtitulos;

	sf::Text* nombconj;
	sf::Text* idconj;
	sf::Text* idchamp;

	//LO QUE SE VA A USAR PARA ESCRIBIR EN VENTANA
	sf::Text titulo;
	sf::Font fuente;

	//MENU DE ALTA ITEMS
	inputGUI* inputWindow;

	sf::RectangleShape* bordes;

	sf::RectangleShape cajaTitulo;

	Campeon* champ;
	Item* item;

	Conjunto_cabecera* conjcab;
	Conjunto_detalle* conjdet;

	outputGUI* outputWindow;
	iconosListado* encabezadoOutput;
	//LOS ICONOS A MOSTRAR(ITEMS)
	//sf::RectangleShape iconosT[154];

	sf::Texture tex;

	//ESTADOS DEL MENU
	EstadoMenu StateMenu;

	//BOTONES
	BotonGUI* btn;

	//Texto
	Leyenda* ley;



	//Bools
	bool* check;

public:
	Menu();

	//METODOS
	bool* getCheck() { return check; }

	//Devuelve true si es un num valido;
	bool validarNum(std::string& num);

	//valida los checks// el parametro int es para el tam del for
	bool validarChecks(bool checks[], int tam);

	//INICIALIZA LA VENTANA, CARGA LAS FUENTES Y LLAMA A RUN
	void init(int _resAlto = 600, int _resAncho = 800);
	//CICLO DE LA VENTANA
	void run();

	//METODOS DE LOS MENUS
	void menudetallesConj();
	void mostrarDetalle();


	void menuPrincipal();
	void menuCampeones();
	void menuItems();
	void menuConjuntos();
	void menuBackup();

	void verificacionInputChamps();
	void verificacionInput();
	void verificacionInputConj();

	void menubajaItem();
	void menubajaChamp();
	void menubajaConj();

	void menumodItem();
	void menumodChamp();
	void menumodConj();

	void menumasopcionesItems();
	void menumasopcionesChamps();
	void menumasopcionesConjuntos();

	void menualtaItems();
	void menualtaChamps();
	void menualtaConj();

	void menumostrarConjuntos();
	void menumostrarItems();
	void menumostrarChamps();

	//INICIALIZACION DE BOTONES DEL MENU
	void inicializacionBotones();
	//LEER ARCHIVOS 
	void leerArchivosItems();
	void leerArchivosChamps();
	void leerArchivosConjuntos();
	//INICIALIZACIONES PARA SUBMENUS
	void inicializacionaltaChamps();
	void inicializacionaltaItems();
	void inicializacionaltaConj();
	void inicializacionmodificacionConj();
	void inicializacionmodificacionChamp();
	void inicializacionmodificacionItems();


	void cargarIconos();
	void cmdIcono(int pos);

	bool bkpRestore();
	bool bkpCreate();
	~Menu()
	{
		delete mouse;
		delete ventana;

	}

};





