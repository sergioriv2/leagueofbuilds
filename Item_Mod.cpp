#include "Item_Mod.h"
#include "Singleton.h"
#include "SubMenu_Items.h"
#include "Items_Listado.h"

extern sf::Font* Fuente;

void Item_Mod::inicializarBotones()
{
}

void Item_Mod::verificacionInput()
{
	std::string algo;
	char auxc[30] = {};
	float auxf = 0;
	int auxi = 0;

	//voy poniendolos true mientras se vayan validando y se va a poder guardar cuando los 14 esten en true;
	//1 nombre //_InputWindow[num-1]
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
	algo = _InputWindow[0].getTextoIngreso();
	for (int i = 0; i < algo.length(); i++) {
		auxc[i] = algo[i];
	}
	std::cout << "Nombre ingresado: " << std::endl;
	item->setNombre(auxc);
	std::cout << item->getNombre() << std::endl;
	if (item->validarNombre(auxc) == true) {
		check[0] = true;
		_InputWindow[0].setColor(sf::Color::Green);
	}
	else _InputWindow[0].setColor(sf::Color::Red);

	//ATAQUE
	algo = _InputWindow[1].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[1].setColor(sf::Color::Red);
	}
	else
	{
		auxf = stof(algo);
		item->setAtaque(auxf);
		std::cout << "Ataque ingresado: " << std::endl;
		std::cout << item->getAtaque() << std::endl;
		if (item->validarAtaque(auxf)) {
			check[1] = true;
			_InputWindow[1].setColor(sf::Color::Green);
		}
		else _InputWindow[1].setColor(sf::Color::Red);
	}
	//VEL. ATAQUE
	algo = _InputWindow[2].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[2].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setVel_ataque(auxf);
		std::cout << "Velocidad de ataque: " << std::endl;
		std::cout << item->getVel_ataque() << std::endl;
		if (item->validarVa(auxf)) {
			check[2] = true;
			_InputWindow[2].setColor(sf::Color::Green);
		}
		else _InputWindow[2].setColor(sf::Color::Red);
	}

	//AP
	algo = _InputWindow[3].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[3].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setPoder_habilidad(auxf);
		std::cout << "Poder de habilidad: " << std::endl;
		std::cout << item->getPoder_habilidad() << std::endl;
		if (item->validarPh(auxf)) {
			check[3] = true;
			_InputWindow[3].setColor(sf::Color::Green);
		}
		else _InputWindow[3].setColor(sf::Color::Red);
	}

	//MANA
	algo = _InputWindow[4].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[4].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setMana(auxf);
		std::cout << "Mana: " << std::endl;
		std::cout << item->getMana() << std::endl;
		if (item->validarMana(auxf)) {
			check[4] = true;
			_InputWindow[4].setColor(sf::Color::Green);
		}
		else _InputWindow[4].setColor(sf::Color::Red);
	}

	//REG. MANA
	algo = _InputWindow[5].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[5].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setregMana(auxf);
		std::cout << "Reg mana: " << std::endl;
		std::cout << item->getregMana() << std::endl;
		if (item->validarRegmana(auxf)) {
			check[5] = true;
			_InputWindow[5].setColor(sf::Color::Green);
		}
		else _InputWindow[5].setColor(sf::Color::Red);
	}

	//VIDA
	algo = _InputWindow[6].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[6].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setVida(auxf);
		std::cout << "Vida: " << std::endl;
		std::cout << item->getVida() << std::endl;
		if (item->validarVida(auxf)) {
			check[6] = true;
			_InputWindow[6].setColor(sf::Color::Green);
		}
		else _InputWindow[6].setColor(sf::Color::Red);
	}

	//REG DE VIDA
	algo = _InputWindow[7].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[7].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setregVida(auxf);
		std::cout << "Reg de vida: " << std::endl;
		std::cout << item->getregVida() << std::endl;
		if (item->validarRegvida(auxf)) {
			check[7] = true;
			_InputWindow[7].setColor(sf::Color::Green);
		}
		else _InputWindow[7].setColor(sf::Color::Red);
	}

	//ARMADURA
	algo = _InputWindow[8].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[8].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setArmor(auxf);
		std::cout << "Armadura: " << std::endl;
		std::cout << item->getArmor() << std::endl;
		if (item->validarArmor(auxf)) {
			check[8] = true;
			_InputWindow[8].setColor(sf::Color::Green);
		}
		else _InputWindow[8].setColor(sf::Color::Red);
	}

	//RES. MAGICA
	algo = _InputWindow[9].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[9].setColor(sf::Color::Red);
	else
	{
		auxf = std::stof(algo);
		item->setResistencia_magica(auxf);
		std::cout << "Resistencia magica: " << std::endl;
		std::cout << item->getResistencia_magica() << std::endl;
		if (item->validarRM(auxf)) {
			check[9] = true;
			_InputWindow[9].setColor(sf::Color::Green);
		}
		else _InputWindow[9].setColor(sf::Color::Red);
	}

	//ROBO DE VIDA
	algo = _InputWindow[10].getTextoIngreso();
	if (!validarNum(algo)) _InputWindow[10].setColor(sf::Color::Red);
	else
	{
		auxf = stof(algo);
		item->setlifeSteal(auxf);
		std::cout << "Robo de vida: " << std::endl;
		std::cout << item->getlifeSteal() << std::endl;
		if (item->validarRobovida(auxf)) {
			check[10] = true;
			_InputWindow[10].setColor(sf::Color::Green);
		}
		else _InputWindow[10].setColor(sf::Color::Red);
	}

	//CRITICO
	algo = _InputWindow[11].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[11].setColor(sf::Color::Red);
	}
	else
	{
		auxf = std::stof(algo);
		item->setCrit_chance(auxf);
		std::cout << "Critico: " << std::endl;
		std::cout << (float)item->getCrit_chance() << std::endl;
		if (item->validarCrit(auxf)) {
			check[11] = true;
			_InputWindow[11].setColor(sf::Color::Green);
		}
		else _InputWindow[11].setColor(sf::Color::Red);
	}

	//REDUCCION DE ENFRIAMIENTO
	algo = _InputWindow[12].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[12].setColor(sf::Color::Red);
	}
	else
	{
		auxf = std::stof(algo);
		item->setCDR(auxf);
		std::cout << "Reduccion enfriamiento: " << std::endl;
		std::cout << item->getCDR() << std::endl;
		if (item->validarCDR(auxf)) {
			check[12] = true;
			_InputWindow[12].setColor(sf::Color::Green);
		}
		else _InputWindow[12].setColor(sf::Color::Red);
	}

	//COSTO
	algo = _InputWindow[13].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[13].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		item->setCosto(auxi);
		std::cout << "Costo: " << std::endl;
		std::cout << item->getCosto() << std::endl;
		if (item->validarCosto(auxi)) {
			check[13] = true;
			_InputWindow[13].setColor(sf::Color::Green);
		}
		else _InputWindow[13].setColor(sf::Color::Red);
	}
}

bool Item_Mod::validarChecks(bool checks[], int tam)
{
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

bool Item_Mod::validarNum(std::string& num)
{
	if (num[0] == '0' || num[0] == '1' || num[0] == '2' || num[0] == '3'
		|| num[0] == '4' || num[0] == '5' || num[0] == '6' || num[0] == '7'
		|| num[0] == '8' || num[0] == '9') {
		std::cout << "Num valido" << std::endl;
		return true;
	}
	std::cout << "Num invalido" << std::endl;
	return false;
}

Item_Mod::Item_Mod(outputGUI& _Item)
{
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	_Botones = new BotonGUI[2];
	_InputWindow = new inputGUI[14];
	_Titulo = new sf::Text;
	outputWindow = new outputGUI;
	_Reloj = new sf::Clock;

	item = new Item;
	check = new bool[14]{ false };

	_Reloj->restart();
	*outputWindow = _Item;

	lastIngreso = 0;
	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	check = new bool[14]{ false };

	//TITULO DEL SUBMENU -------------------------

	_Titulo->setString("EDITAR ITEM");
	_Titulo->setCharacterSize(23);
	_Titulo->setPosition(60, 30);
	_Titulo->setFont(*_FUENTE);

	// ---------------------------------------------

	for (int i = 0; i < 14; i++)
	{
		_InputWindow[i] = inputGUI(80);
		_InputWindow[i].setID(i + 1);
		_InputWindow[i].setLimiteIngreso(5);
	}

	_InputWindow[0].setPos(55, 80);
	_InputWindow[0].setStringSubtitulo("NOMBRE DEL ITEM");
	_InputWindow[0].setSizeRectangulo(280, 30);
	_InputWindow[0].setLimiteIngreso(30);

	_InputWindow[1].setPos(55, 160);
	_InputWindow[1].setStringSubtitulo("ATAQUE");

	_InputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
	_InputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

	_InputWindow[3].setPos(55, 240);
	_InputWindow[3].setStringSubtitulo("PODER DE HABILIDAD");

	_InputWindow[4].setPos(55, 320);
	_InputWindow[4].setStringSubtitulo("MANA");

	_InputWindow[5].setPos(235, 320);
	_InputWindow[5].setStringSubtitulo("REGENERACION MANA");

	_InputWindow[6].setPos(55, 400);
	_InputWindow[6].setStringSubtitulo("VIDA");

	_InputWindow[7].setPos(235, 400);
	_InputWindow[7].setStringSubtitulo("REGENERACION VIDA");

	_InputWindow[8].setPos(55, 480);
	_InputWindow[8].setStringSubtitulo("ARMADURA");

	_InputWindow[9].setPos(235, 480);
	_InputWindow[9].setStringSubtitulo("RESISTENCIA MAGICA");

	_InputWindow[10].setPos(510, 80);
	_InputWindow[10].setStringSubtitulo("ROBO DE VIDA");

	_InputWindow[11].setPos(510, 160);
	_InputWindow[11].setStringSubtitulo("PROBABILIDAD DE CRITICO");

	_InputWindow[12].setPos(510, 240);
	_InputWindow[12].setStringSubtitulo("ACELERACION DE HABILIDAD");

	_InputWindow[13].setPos(510, 320);
	_InputWindow[13].setStringSubtitulo("COSTO");
}

void Item_Mod::process_event(const sf::Event& e)
{
	for (int i = 0; i < 9; i++) if (lastIngreso == NULL) _InputWindow[i].setSelected(false);
	if (e.type == sf::Event::TextEntered)
	{
		_InputWindow[lastIngreso - 1].callEventoIngreso(e);
	}
}

void Item_Mod::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 14; i++)
	{
		_InputWindow[i].comandoInput(_Mouse, &lastIngreso);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInput();
	}

	//Si todos los datos ingresados son validos se habilitaria la opcion de guardar
	if (validarChecks(getCheck(), 14) == true) {
		Archivo arch("resources/items/itemsdata.dat", sizeof(Item));
		std::string auxid = outputWindow->getId().getString();

		item->setEstado(true);
		item->setID(stoi(auxid));
		if (arch.grabarRegistro(*item, stoi(auxid) - 1, LecturaEscritura))
		{
			std::cout << "Registro editado" << std::endl;
		}
		else
		{
			std::cout << "Error al editar registro" << std::endl;
		}
		Singleton::getInstancia().cambiar_Menu(new SubMenu_Items);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Items_Listado);
		}
	}
}

void Item_Mod::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	for (int i = 0; i < 14; i++)
	{
		_InputWindow[i].draw(_Ventana);
	}

	//btn[5].dibujarBotoncito(*ventana);
	_Ventana.draw(*_BordeVentana);
	_Ventana.draw(*_Titulo);

}

Item_Mod::~Item_Mod()
{
	delete _BordeVentana ;
	delete _Mouse;
	delete[] _Botones;
	delete[] _InputWindow;
	delete _Titulo;
	delete outputWindow;

	delete item;
	delete[] check;
	delete _Reloj;
}
