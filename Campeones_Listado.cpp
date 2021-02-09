#include "Campeones_Listado.h"
#include "Singleton.h"
#include "SubMenu_Campeones.h"

extern sf::Font* _FUENTE;

int contarRegistros_Campeones()
{
	Campeon* aux;
	aux = new Campeon;

	int i = 0, cant = 0;
	Archivo arch("resources/campeones/champsdata.dat", sizeof * aux);
	while (arch.leerRegistro(*aux, i++)) if (aux->getEstado()) cant++;

	delete aux;
	return cant;
}

Campeones_Listado::Campeones_Listado()
{
	_Titulo = new sf::Text;
	_EncabezadoOutput = new iconosListado;
	outputWindow = new outputGUI;
	_Mouse = new clsMouse;
	lastIngresoOutput = new int;
	_BordeVentana = new sf::RectangleShape;
	_Reloj = new sf::Clock;

	_ChampsAMostrar = 0;
	_CantidadPaginas = 0;
	_PagActual = 1;

	*lastIngresoOutput = 0;

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

	cargarArchivos();
}

void Campeones_Listado::cargarArchivos()
{
	//ARCHIVO DE CAMPEONES
	Campeon* aux;
	aux = new Campeon;

	Archivo* arch;
	arch = new Archivo("resources/campeones/champsdata.dat", sizeof(Campeon));

	float y = 120;

	//Variable j para leer todos los registros, variable k para leer el registro especifico
	int j = 0, k = 0;

	//Consulto cuantos registros de item hay con true

	//Tambien veo cuantas paginas voy a tener
	_ChampsAMostrar = contarRegistros_Campeones();

	///////////////////////////////////////////////////////////
	// Esto es para saber cuantas paginas va a tener la lista
	///////////////////////////////////////////////////////////

	//Declaro un float auxiliar para saber los decimales y le hago los casteos
	float auxFloat = (float)_ChampsAMostrar / (float)13;
	//Entero sin decimales

	_CantidadPaginas = _ChampsAMostrar / 13;

	//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
	auxFloat = auxFloat - (float)_CantidadPaginas;
	if (auxFloat != 0.0) _CantidadPaginas++;

	//La cantidad de registros es igual a la cantidad de egresos

	if (_CantidadPaginas == 0)outputWindow = new outputGUI;
	else outputWindow = new outputGUI[_ChampsAMostrar];

	//Inicializacion de la clase
	for (int i = 0; i < _ChampsAMostrar; i++)
	{
		outputWindow[i] = outputGUI(12);
	}

	//Seteos de la posicion

	for (int i = 0; i < _ChampsAMostrar; i++)
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
	while (arch->leerRegistro(*aux, j++) == 1)
	{
		if (aux->getEstado())
		{
			//Sobrecarga de operador
			outputWindow[k] = *aux;
			k++;
		}
	}

	delete aux;
	delete arch;
}

void Campeones_Listado::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	//Algoritmo paginas
	if (_CantidadPaginas != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout <<"PAGS A MOSTRAR:" << _CantidadPaginas << std::endl;
		//std::cout << "PAGS ACTUAL:" << _PagActual << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Sleep(200);
			if (_PagActual < _CantidadPaginas) (_PagActual)++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Sleep(200);
			if (_PagActual != 1) (_PagActual)--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (_PagActual == _CantidadPaginas)
		{
			for (int i = 13 * (_PagActual - 1); i < _ChampsAMostrar; i++)
			{
				outputWindow[i].cmdC(*_Mouse, *lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (_PagActual - 1); i < 13 * _PagActual; i++)
			{
				outputWindow[i].cmdC(*_Mouse, *lastIngresoOutput);
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Campeones);
		}
	}
}

void Campeones_Listado::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	//DIBUJADO DE LOS EGRESOS DE LA LISTA
	if (_ChampsAMostrar <= 13)
	{
		for (int i = 0; i < _ChampsAMostrar; i++)
		{
			outputWindow[i].drawC(&_Ventana);
		}
	}
	else
	{
		if (_PagActual == _CantidadPaginas)
		{
			for (int i = 13 * (_PagActual - 1); i < _ChampsAMostrar; i++)
			{
				outputWindow[i].drawC(&_Ventana);
			}
		}
		else
		{
			for (int i = 13 * (_PagActual - 1); i < 13 * _PagActual; i++)
			{
				outputWindow[i].drawC(&_Ventana);
			}
		}

	}

	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
	_EncabezadoOutput->dibujarIconosC(&_Ventana);
	//btn[2].dibujarBotoncito(*ventana);
}

Campeones_Listado::~Campeones_Listado()
{
	delete _Titulo;
	delete _EncabezadoOutput;
	//delete outputWindow;
	delete _Mouse;
	delete _BordeVentana;
	delete lastIngresoOutput;
	delete _Reloj;
}
