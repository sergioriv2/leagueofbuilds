#include "Campeones_Opc.h"
#include "Singleton.h"
#include "Campeones_Mod.h"
#include "Campeones_Listado.h"

extern sf::Font* _FUENTE;

void Campeones_Opc::inicializarBotones()
{
	//1 Borrar item
	_Botones[0].setbothPos(50.0f, 300.0f);
	_Botones[0].setBtnType(btnType::BTN_DEL_CHAMP);
	_Botones[0].setTextoString("Borrar Campeon");
	//2 Editar item
	_Botones[1].setbothPos(250.0f, 300.0f);
	_Botones[1].setBtnType(btnType::BTN_MOD_CHAMP);
	_Botones[1].setTextoString("Editar Campeon");
	//2 Volver
	_Botones[2].setbothPos(500.0f, 300.0f);
	_Botones[2].setBtnType(btnType::BTN_VOLVER);
	_Botones[2].setTextoString("Volver");
}

Campeones_Opc::Campeones_Opc(outputGUI& _Champ)
{
	_Titulo = new sf::Text;
	encabezadoOutput = new iconosListado;
	_BordeVentana = new sf::RectangleShape;
	_Botones = new BotonGUI[3];
	_Mouse = new clsMouse;
	_ChampAux = new outputGUI;
	_Reloj = new sf::Clock;

	*_ChampAux = _Champ;

	_Reloj->restart();

	_Titulo->setFont(*_FUENTE);
	_Titulo->setString("MAS OPCIONES...");
	_Titulo->setPosition(60.0f, 30.0f);

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	encabezadoOutput->setFuente(_FUENTE);

	inicializarBotones();
}

void Campeones_Opc::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 3; i++) _Botones[i].cmd(*_Mouse);

	// CAMBIO
	if (_Botones[0].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->baja();
	}

	if (_Botones[1].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Singleton::getInstancia().cambiar_Menu(new Campeones_Mod(*_ChampAux));
	}

	for (int i = 0; i < 3; i++) _Botones[i].update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
				Singleton::getInstancia().cambiar_Menu(new Campeones_Listado);
		}
		
	}

	//Volver
	if (_Botones[2].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Campeones_Listado);
		}
	}
}

void Campeones_Opc::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	encabezadoOutput->dibujarIconosC(&_Ventana);
	_ChampAux->drawMenuMoreOPC_C(&_Ventana);

	for (int i = 0; i < 3; i++) _Botones[i].dibujarBotoncito(_Ventana);

	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

void Campeones_Opc::baja()
{
	std::string auxid = _ChampAux->getId().getString();
	int pos = std::stoi(auxid) - 1;
	// Variable que solo se usa para dar de baja
	Campeon* champ;
	champ = new Campeon;

	if (champ->BajaVirtual(pos))
	{
		std::cout << "Se dio de baja correctamente" << std::endl;
	}
	else
	{
		std::cout << "Error al dar de baja" << std::endl;
	}


	delete champ;
}

Campeones_Opc::~Campeones_Opc()
{
	delete _Titulo;
	delete encabezadoOutput;
	delete _BordeVentana;
	delete[] _Botones;
	delete _Mouse;
	delete _ChampAux;
	delete _Reloj;
}
