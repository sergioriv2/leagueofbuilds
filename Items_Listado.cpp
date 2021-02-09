#include "Items_Listado.h"
#include "Singleton.h"
#include "SubMenu_Items.h"

extern sf::Font* _FUENTE;

int contarRegistros_Items()
{
	Item* aux;
	aux = new Item;

	int i = 0, cant = 0;
	Archivo arch("resources/items/itemsdata.dat", sizeof * aux);
	while (arch.leerRegistro(*aux, i++)) if (aux->getEstado()) cant++;

	delete aux;
	return cant;
}

void Items_Listado::cargarArchivos()
{
	Item* aux;
	aux = new Item;

	Archivo* arch;
	arch = new Archivo("resources/items/itemsdata.dat", sizeof(Item));

	float y = 120;

	//Variable j para leer todos los registros, variable k para leer el registro especifico
	int j = 0, k = 0;

	//Borro lo que habia antes en la clase 
	if (_CantidadPaginas == 0) delete outputWindow;
	else delete[] outputWindow;
	//Consulto cuantos registros de item hay con true

	//Tambien veo cuantas paginas voy a tener
	_ItemsAMostrar = contarRegistros_Items();
	///////////////////////////////////////////////////////////
	// Esto es para saber cuantas paginas va a tener la lista
	///////////////////////////////////////////////////////////

	//Declaro un float auxiliar para saber los decimales y le hago los casteos
	float auxFloat = (float)_ItemsAMostrar / (float)13;
	//Entero sin decimales

	_CantidadPaginas = _ItemsAMostrar / 13;

	//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
	auxFloat = auxFloat - (float)_CantidadPaginas;
	if (auxFloat != 0.0) _CantidadPaginas++;

	//La cantidad de registros es igual a la cantidad de egresos
	if (_CantidadPaginas == 0) outputWindow = new outputGUI;
	else outputWindow = new outputGUI[_ItemsAMostrar];

	//Inicializacion de la clase
	for (int i = 0; i < _ItemsAMostrar; i++)
	{
		outputWindow[i] = outputGUI();
	}
	//Seteos de la posicion

	for (int i = 0; i < _ItemsAMostrar; i++)
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


	while (arch->leerRegistro(*aux, j++) == 1)
	{
		if (aux->getEstado())
		{
			//Sobrecarga de operador
			outputWindow[k] = *aux;
			k++;
		}
	}

	delete arch;
	delete aux;
}

Items_Listado::Items_Listado()
{
	_EncabezadoOutput = new iconosListado;
	_Titulo = new sf::Text;
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	lastIngresoOutput = new int;
	_Reloj = new sf::Clock;

	*lastIngresoOutput = 0;
	_PagActual = 1;
	_CantidadPaginas = 0;
	_ItemsAMostrar = 0;
	_Reloj->restart();

	_EncabezadoOutput->setFuente(_FUENTE);

	_Titulo->setFont(*_FUENTE);
	_Titulo->setString("LISTADO DE CAMPEONES");
	_Titulo->setPosition(60.0f, 30.0f);

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	_EncabezadoOutput->setPosY(90.0f);

	cargarArchivos();
}

void Items_Listado::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	//Algoritmo paginas
	if (_CantidadPaginas != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout << _CantidadPaginas << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Sleep(200);
			if (_PagActual < _CantidadPaginas) _PagActual++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Sleep(200);
			if (_PagActual != 1) _PagActual--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (_PagActual == _CantidadPaginas)
		{
			for (int i = 13 * (_PagActual - 1); i < _ItemsAMostrar; i++)
			{
				outputWindow[i].cmd(*_Mouse, *lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (_PagActual - 1); i < 13 * _PagActual; i++)
			{
				outputWindow[i].cmd(*_Mouse, *lastIngresoOutput);
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Items);
		}
	}
}
	
void Items_Listado::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	//DIBUJOS ---------------------

	_Ventana.clear(sf::Color(14, 22, 33, 255));

	//DIBUJADO DE LOS EGRESOS DE LA LISTA
	if (_ItemsAMostrar <= 13)
	{
		for (int i = 0; i < _ItemsAMostrar; i++)
		{
			outputWindow[i].draw(&_Ventana);
		}
	}
	else
	{
		if (_PagActual == _CantidadPaginas)
		{
			for (int i = 13 * (_PagActual - 1); i < _ItemsAMostrar; i++)
			{
				outputWindow[i].draw(&_Ventana);
			}
		}
		else
		{
			for (int i = 13 * (_PagActual - 1); i < 13 * _PagActual; i++)
			{
				outputWindow[i].draw(&_Ventana);
			}
		}

	}

	_EncabezadoOutput->dibujarIconos(&_Ventana);

	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
	//btn[2].dibujarBotoncito(*ventana);
}

Items_Listado::~Items_Listado()
{
	delete lastIngresoOutput;
	delete _Mouse;
	delete _BordeVentana;
	delete _Titulo;
	delete _EncabezadoOutput;
	delete _Reloj;
}

