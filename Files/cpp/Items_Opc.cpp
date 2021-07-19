#include "../hpp/Items_Opc.h"
#include "../hpp/Singleton.h"
#include "../hpp/Item_Mod.h"
#include "../hpp/Items_Listado.h"

extern sf::Font* _FUENTE;

void Items_Opc::inicializarBotones()
{
	//1 Borrar item
	_Botones[0].setbothPos(50.0f, 300.0f);
	_Botones[0].setBtnType(btnType::BTN_DEL_ITEM);
	_Botones[0].setTextoString("Borrar Item");
	//2 Editar item
	_Botones[1].setbothPos(250.0f, 300.0f);
	_Botones[1].setBtnType(btnType::BTN_MOD_ITEM);
	_Botones[1].setTextoString("Editar Item");
	//2 Volver
	_Botones[2].setbothPos(500.0f, 300.0f);
	_Botones[2].setBtnType(btnType::BTN_VOLVER);
	_Botones[2].setTextoString("Volver");
}

Items_Opc::Items_Opc(outputGUI& _Item)
{
	_Titulo = new sf::Text;
	encabezadoOutput = new iconosListado();
	_BordeVentana = new sf::RectangleShape;
	_Botones = new BotonGUI[3];
	_Mouse = new clsMouse;
	_ItemAux = new outputGUI;
	_Reloj = new sf::Clock;

	_Reloj->restart();
	*_ItemAux = _Item;

	_Titulo->setFont(*_FUENTE);
	_Titulo->setString("MAS OPCIONES...");
	_Titulo->setPosition(60.0f, 30.0f);

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	encabezadoOutput->setFuente(_FUENTE);
	encabezadoOutput->setPosY(90.0f);

	inicializarBotones();
}

void Items_Opc::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 3; i++) _Botones[i].cmd(*_Mouse);

	// CAMBIO

	if (_Botones[0].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->baja();
	}
	if (_Botones[1].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Singleton::getInstancia().cambiar_Menu(new Item_Mod(*_ItemAux));
	}
	//volver
	if (_Botones[2].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Items_Listado);
		}
	}

	for (int i = 0; i < 3; i++) _Botones[i].update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Items_Listado);
		}
	}
}

void Items_Opc::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	encabezadoOutput->dibujarIconos(&_Ventana);

	_ItemAux->drawMenuMoreOPC(&_Ventana);

	for (int i = 0; i < 3; i++) _Botones[i].dibujarBotoncito(_Ventana);

	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

void Items_Opc::baja()
{
	std::string auxid = _ItemAux->getId().getString();
	int pos = std::stoi(auxid) - 1;
	// Variable que solo se usa para dar de baja
	Item* item;
	item = new Item;

	if (item->BajaVirtual(pos))
	{
		std::cout << "Se dio de baja correctamente" << std::endl;
	}
	else
	{
		std::cout << "Error al dar de baja" << std::endl;
	}


	delete item;
}

Items_Opc::~Items_Opc()
{
	delete[] _Botones;
	delete _Titulo;
	delete _BordeVentana;
	delete encabezadoOutput;
	delete _Mouse;
	delete _ItemAux;
	delete _Reloj;
}
