#include "SubMenu_Campeones.h"
#include "Singleton.h"
#include "SubMenu_Principal.h"

#include "BotonGUI.h"

const char* HEADER_MENUCAMPEONES = "resources/gui/header_champs.jpg";
extern sf::Font* _FUENTE;

SubMenu_Campeones::SubMenu_Campeones()
{
	_Botones = new BotonGUI[3];
	_Banner = new headerGUI;
	_Titulo = new sf::Text;
	_BordeTitulo = new sf::RectangleShape;
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	_Reloj = new sf::Clock;

	_BordeTitulo->setPosition(40.0f, 190.0f);
	_Titulo->setPosition(60.0f, 200.0f);
	_Titulo->setString("MENU CAMPEONES");
	_Banner->setTexture(HEADER_MENUCAMPEONES);
	_Reloj->restart();

	//BORDES PARA EL MENU
	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	//BORDE TITULO
	_BordeTitulo->setSize({ 310, 40 });
	_BordeTitulo->setFillColor(sf::Color(14, 22, 33, 255));

	_Titulo->setFont(*_FUENTE);
	_Titulo->setCharacterSize(23);
	_Titulo->setFillColor(sf::Color(184, 198, 240, 255));

	inicializarBotones();
}

void SubMenu_Campeones::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);
	for (int i = 0; i < 3; i++) _Botones[i].cmd(*_Mouse);
	//UPDATE De cada botoncito

	for (int i = 0; i < 3; i++) _Botones[i].update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Principal);
			_Reloj->restart();
		}
	}
	//volver
	if (_Botones[2].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Principal);
		}
	}
}

void SubMenu_Campeones::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	for (int i = 0; i < 3; i++)
	{
		_Botones[i].dibujarBotoncito(_Ventana);
	}

	//DRAW titulo
	_Ventana.draw(_Banner->getHeader());
	_Ventana.draw(*_BordeTitulo);
	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

void SubMenu_Campeones::inicializarBotones()
{
	_Botones[0].setbothPos(80.0f, 280.0f);
	_Botones[0].settxtPos(95.0f, 290.0f);
	_Botones[0].setBtnType(BTN_ADD_CHAMP);
	_Botones[0].setTextoString("Agregar Campeon");

	//1 Mostrar campeones
	//Si no hay nada para mostrar deshabilito la opcion de listado

	//if (contarRegistros_Campeones() == 0) _Botones[1].setBtnEstado(DESHABILITADO);
	//else  _Botones[1].setBtnEstado(NINGUNO);

	_Botones[1].setbothPos(80.0f, 380.0f);
	_Botones[1].settxtPos(95.0f, 390.0f);
	_Botones[1].setBtnType(BTN_LIST_CHAMP);
	_Botones[1].setTextoString("Listar Campeones");

	//2 Volver
	_Botones[2].setbothPos(80.0f, 480.0f);
	_Botones[2].settxtPos(140.0f, 490.0f);
	_Botones[2].setBtnType(BTN_VOLVER);
	_Botones[2].setTextoString("Volver");
}

SubMenu_Campeones::~SubMenu_Campeones()
{
	delete[] _Botones;
	delete _BordeVentana;
	delete _Banner;
	delete _Titulo;
	delete _Mouse;
	delete _BordeTitulo;
	delete _Reloj;
}
