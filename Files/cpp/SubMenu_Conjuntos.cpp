#include "../hpp/SubMenu_Conjuntos.h"
#include "../hpp/SubMenu_Principal.h"
#include "../hpp/Singleton.h"

const char* HEADER_MENUCONJUNTOS = "resources/gui/header_conjuntos.jpg";
extern sf::Font* _FUENTE;


SubMenu_Conjuntos::SubMenu_Conjuntos()
{
	_Botones = new BotonGUI[3];
	_Banner = new headerGUI;
	_Titulo = new sf::Text;
	_BordeTitulo = new sf::RectangleShape;
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	_Reloj = new sf::Clock;

	_Reloj->restart();
	_BordeTitulo->setPosition(40.0f, 190.0f);
	_Titulo->setPosition(60.0f, 200.0f);
	_Titulo->setString("MENU CONJUNTOS");
	_Banner->setTexture(HEADER_MENUCONJUNTOS);

	//BORDES PARA EL MENU
	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	//BORDE TITULO
	_BordeTitulo->setSize({ 310, 40 });
	_BordeTitulo->setFillColor(sf::Color(14, 22, 33, 255));

	//FUENTE
	_Titulo->setFont(*_FUENTE);
	_Titulo->setCharacterSize(23);
	_Titulo->setFillColor(sf::Color(184, 198, 240, 255));

	inicializarBotones();
}

void SubMenu_Conjuntos::inicializarBotones()
{
	_Botones[0].setbothPos(80.0f, 280.0f);
	_Botones[0].setBtnType(BTN_ADD_CONJ);
	_Botones[0].setTextoString("Agregar Conjunto");

	_Botones[1].setbothPos(480.0f, 280.0f);
	_Botones[1].setBtnType(BTN_LIST_CONJ);
	_Botones[1].setTextoString("Mostrar Conjuntos");

	_Botones[2].setbothPos(80.0f, 480.0f);
	_Botones[2].settxtPos(140.0f, 490.0f);
	_Botones[2].setBtnType(BTN_VOLVER);
	_Botones[2].setTextoString("Volver");
}


void SubMenu_Conjuntos::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	//CMD De cada botoncito
	for (int i = 0; i < 3; i++) _Botones[i].cmd(*_Mouse);
	//UPDATE De cada botoncito
	for (int i = 0; i < 3; i++) _Botones[i].update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Principal);
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

void SubMenu_Conjuntos::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	//clear
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	//draw
	for (int i = 0; i < 3; i++)
	{
		_Botones[i].dibujarBotoncito(_Ventana);
	}
	_Ventana.draw(_Banner->getHeader());
	_Ventana.draw(*_BordeTitulo);
	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

SubMenu_Conjuntos::~SubMenu_Conjuntos()
{
	delete[] _Botones;
	delete _Reloj;
	delete _BordeVentana;
	delete _Banner;
	delete _Titulo;
	delete _Mouse;
	delete _BordeTitulo;
}
