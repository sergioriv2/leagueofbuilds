#include "../hpp/Conjuntos_Opc.h"
#include "../hpp/Conjuntos_Listado.h"
#include "../hpp/Conjuntos_Mod.h"
#include "../hpp/Singleton.h"

extern sf::Font* _FUENTE;

void Conjuntos_Opc::inicializarBotones()
{
	_Botones[0].setbothPos(80.0f, 300.0f);
	_Botones[0].setBtnType(btnType::BTN_DET_CONJ);
	_Botones[0].setTextoString("Mostrar Detalles");
	//1 Borrar 
	_Botones[1].setbothPos(500.0f, 420.0f);
	_Botones[1].setBtnType(btnType::BTN_DEL_CONJ);
	_Botones[1].setTextoString("Borrar conjunto");
	//2 Editar
	_Botones[2].setbothPos(500.0f, 300.0f);
	_Botones[2].setBtnType(btnType::BTN_MOD_CONJ);
	_Botones[2].setTextoString("Editar conjunto");
	//2 Volver
	_Botones[3].setbothPos(80.0f, 420.0f);
	_Botones[3].setBtnType(btnType::BTN_VOLVER);
	_Botones[3].setTextoString("Volver");
}

Conjuntos_Opc::Conjuntos_Opc(outputGUI& _Conj)
{
	_ConjAux = new outputGUI;
	_BordeVentana = new sf::RectangleShape;
	_Titulo = new sf::Text;
	_Botones = new BotonGUI[4];
	_Mouse = new clsMouse;
	_Reloj = new sf::Clock;
	nombconj = new sf::Text;
	idconj = new sf::Text;
	idchamp = new sf::Text;

	*_ConjAux = _Conj;

	_Detalles = false;

	_Titulo->setFont(*_FUENTE);
	_Titulo->setString("MAS OPCIONES...");
	_Titulo->setPosition(60.0f, 30.0f);

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	nombconj->setPosition(62.0f, 90.0f);
	idconj->setPosition(300.0f, 90.0f);
	idchamp->setPosition(500.0f, 90.0f);

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

	_Reloj->restart();

	inicializarBotones();
}

void Conjuntos_Opc::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 4; i++) _Botones[i].cmd(*_Mouse);

	// CAMBIO
	if (_Botones[0].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->detalles();
			_Detalles = true;
		}

	}

	if (_Botones[1].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->baja();
	}

	if (_Botones[2].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Singleton::getInstancia().cambiar_Menu(new Conjuntos_Mod(*_ConjAux));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)	// RELOJ PARA EVITAR BUGS
		{
			if (_Detalles) _Detalles = false;
			else
			{
				Singleton::getInstancia().cambiar_Menu(new Conjuntos_Listado);
			}
			_Reloj->restart();
		}
	
	}

	if (_Botones[3].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Conjuntos_Listado);
		}
	}

	for (int i = 0; i < 4; i++) _Botones[i].update();
}

void Conjuntos_Opc::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	if (!_Detalles)
	{
		for (int i = 0; i < 4; i++) _Botones[i].dibujarBotoncito(_Ventana);

		_ConjAux->drawConjuntoOPC(&_Ventana);
		_Ventana.draw(*nombconj);
		_Ventana.draw(*idconj);
		_Ventana.draw(*idchamp);
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			_Ventana.draw(infoEarly[i]);
			_Ventana.draw(infoMid[i]);
			_Ventana.draw(infoLate[i]);
		}
		for (int i = 0; i < 5; i++)
		{
			_Ventana.draw(subtitulos[i]);
		}
	}
	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

void Conjuntos_Opc::baja()
{
	std::string auxid = _ConjAux->getId().getString();
	Archivo arch("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));

	Conjunto_cabecera* conjcab;
	conjcab = new Conjunto_cabecera;
	int pos = stoi(auxid) - 1;

	if (conjcab->BajaVirtual(pos))
	{
		std::cout << "El registro se dio de baja correctamente" << std::endl;
	}
	else
	{
		std::cout << "Error al dar de baja el registro" << std::endl;
	}
}

Conjuntos_Opc::~Conjuntos_Opc()
{
	delete[] infoMid;
	delete[] infoEarly;
	delete[] infoLate;
	delete[] subtitulos;

	delete _Titulo;
	delete _ConjAux;
	delete _BordeVentana;
	delete[] _Botones;
	delete _Mouse;
	delete _Reloj;
	delete nombconj;
	delete idchamp;
	delete idconj;
}

void Conjuntos_Opc::detalles()
{
	_Titulo->setString("MOSTRANDO DETALLES DEL CONJUNTO");
	_Titulo->setCharacterSize(23);
	_Titulo->setPosition(60, 30);

	infoEarly = new sf::Text[6];
	infoMid = new sf::Text[6];
	infoLate = new sf::Text[6];
	subtitulos = new sf::Text[5];

	//ID del detalle
	int id_conjunto;
	std::string id_conjunto_s, stringAux;
	std::stringstream ss;

	//CONVERSION DE STRING A INT ---------------------------------------
	id_conjunto_s = _ConjAux->getId().getString();
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
		subtitulos[i].setFont(*_FUENTE);
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

		infoEarly[i].setFont(*_FUENTE);
		infoMid[i].setFont(*_FUENTE);
		infoLate[i].setFont(*_FUENTE);

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
			//std::cout << con_aux->getMid()[i] << std::endl;
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
			//std::cout << con_aux->getLate()[i] << std::endl;
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
}
