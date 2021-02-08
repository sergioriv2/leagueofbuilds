#include "Conjuntos_Listado.h"
#include "SubMenu_Conjuntos.h"
#include "Singleton.h"
extern sf::Font* _FUENTE;

int contarRegistros_Conjuntos()
{
	Conjunto_cabecera aux;
	int i = 0, cant = 0;
	Archivo arch("resources/conjuntos/conjunto_cabecera.dat", sizeof aux);
	while (arch.leerRegistro(aux, i++)) if (aux.getEstado()) cant++;
	return cant;
}

Conjuntos_Listado::Conjuntos_Listado()
{
	actualPage = 1;

	nombconj = new sf::Text;
	idconj = new sf::Text;
	idchamp = new sf::Text;
	_Mouse = new clsMouse;
	_Reloj = new sf::Clock;
	_Titulo = new sf::Text;
	_BordeVentana = new sf::RectangleShape;

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	nombconj->setFont(*_FUENTE);
	idconj->setFont(*_FUENTE);
	idchamp->setFont(*_FUENTE);

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

	_Titulo->setFont(*_FUENTE);
	_Titulo->setPosition(60.0f, 30.0f);
	_Titulo->setString("LISTADO DE CONJUNTOS");

	lastIngresoOutput = 0;

	leerArchivos();
}

void Conjuntos_Listado::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Conjuntos);
		}
	}

	// COMANDOS -------------------
	//Algoritmo paginas
	if (cantidadPagListado != 0)
	{
		//Para saber solo imprimo la cantidad de paginas que va a mostrar
		//std::cout << cantidadPagListado << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Sleep(200);
			if (actualPage < cantidadPagListado) actualPage++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Sleep(200);
			if (actualPage != 1) actualPage--;
		}
		//Se habilita la opcion para mostrar otra pagina

		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < conjsaMostrar; i++)
			{
				outputWindow[i].cmdConjuntos(*_Mouse, lastIngresoOutput);
			}
		}

		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].cmdConjuntos(*_Mouse, lastIngresoOutput);
			}
		}
	}

	//btn[2].cmd(*mouse, *ventana, &StateMenu, &protegido);
	//btn[2].update(*ventana);

}

void Conjuntos_Listado::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	if (conjsaMostrar <= 13)
	{
		for (int i = 0; i < conjsaMostrar; i++)
		{
			//std::cout << conjsaMostrar << endl;
			outputWindow[i].drawConjunto(&_Ventana);
		}
	}
	else
	{
		if (actualPage == cantidadPagListado)
		{
			for (int i = 13 * (actualPage - 1); i < conjsaMostrar; i++)
			{
				outputWindow[i].drawConjunto(&_Ventana);
			}
		}
		else
		{
			for (int i = 13 * (actualPage - 1); i < 13 * actualPage; i++)
			{
				outputWindow[i].drawConjunto(&_Ventana);
			}
		}

	}
	

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
	//}

	_Ventana.draw(*nombconj);
	_Ventana.draw(*idconj);
	_Ventana.draw(*idchamp);
	_Ventana.draw(*_BordeVentana);
	_Ventana.draw(*_Titulo);
}

Conjuntos_Listado::~Conjuntos_Listado()
{
	delete nombconj;
	delete idchamp;
	delete idconj;
	delete _BordeVentana;
	delete _Titulo;
	delete _Mouse;
	delete _Reloj;
}

void Conjuntos_Listado::inicializarBotones()
{
	
}

void Conjuntos_Listado::leerArchivos()
{
	Conjunto_cabecera* auxcab;

	auxcab = new Conjunto_cabecera;

	Archivo* archcab;
	archcab = new Archivo("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	float y = 120;
	//Variable j para leer todos los registros, variable k para leer el registro especifico
	int j = 0, k = 0;
	//cuantas paginas voy a mostrar
	conjsaMostrar = contarRegistros_Conjuntos();


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
		outputWindow[i] = outputGUI();
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

	while (archcab->leerRegistro(*auxcab, j) == 1)
	{
		if (auxcab->getEstado())
		{
			//Sobrecarga de operador
			outputWindow[k] = *auxcab;
			k++;
		}
		j++;
	}

	delete archcab;
	delete auxcab;
}
