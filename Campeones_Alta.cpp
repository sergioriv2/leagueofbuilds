#include "Campeones_Alta.h"
#include "Singleton.h"
#include "SubMenu_Campeones.h"

extern sf::Font* _FUENTE;

void Campeones_Alta::process_event(const sf::Event& e)
{
	for (int i = 0; i < 9; i++) if (lastIngreso == NULL) _InputWindow[i].setSelected(false);
	if (e.type == sf::Event::TextEntered)
	{
		_InputWindow[lastIngreso - 1].callEventoIngreso(e);
	}
}

Campeones_Alta::Campeones_Alta()
{
	_BordeVentana = new sf::RectangleShape;

	_Mouse = new clsMouse;
	_Botones = new BotonGUI[2];
	_InputWindow = new inputGUI[9];
	_Titulo = new sf::Text;
	champ = new Campeon;
	_Reloj = new sf::Clock;
	check = new bool[14]{ false };

	lastIngreso = 0;
	_Reloj->restart();

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	//TITULO DEL SUBMENU -------------------------

	_Titulo->setFont(*_FUENTE);
	_Titulo->setString("AGREGAR CAMPEONES");
	_Titulo->setCharacterSize(23);
	_Titulo->setPosition(60, 30);

	// INICIALIZACION PARA EL INGRESO POR VENTANA 
	for (int i = 0; i < 9; i++)
	{
		_InputWindow[i] = inputGUI(80);
		_InputWindow[i].setID(i + 1);
		_InputWindow[i].setLimiteIngreso(5);
	}

	_InputWindow[0].setPos(55, 80);
	_InputWindow[0].setStringSubtitulo("NOMBRE DEL CAMPEON");
	_InputWindow[0].setSizeRectangulo(280, 30);
	_InputWindow[0].setLimiteIngreso(30);

	_InputWindow[1].setPos(55, 160);
	_InputWindow[1].setStringSubtitulo("ATAQUE");

	_InputWindow[2].setPos(235, 160); // Y VA BAJANDO DE 80 EN 80, PERO X CUANDO COMPARTE ESPACIO AUMENTA EN 180
	_InputWindow[2].setStringSubtitulo("VELOCIDAD DE ATAQUE");

	_InputWindow[3].setPos(55, 240);
	_InputWindow[3].setStringSubtitulo("VIDA");

	_InputWindow[4].setPos(55, 320);
	_InputWindow[4].setStringSubtitulo("ARMADURA");

	_InputWindow[5].setPos(235, 320);
	_InputWindow[5].setStringSubtitulo("RESISTENCIA MAGICA");

	_InputWindow[6].setPos(55, 400);
	_InputWindow[6].setStringSubtitulo("MANA ");

	_InputWindow[7].setPos(235, 400);
	_InputWindow[7].setStringSubtitulo("ESTILO");
	_InputWindow[7].setLimiteIngreso(10);

	_InputWindow[8].setPos(55, 480);
	_InputWindow[8].setStringSubtitulo("TIPO DE DAÑO");
	_InputWindow[8].setLimiteIngreso(3);

	inicializarBotones();
}

void Campeones_Alta::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 14; i++) {
		check[i] = false;
	}

	for (int i = 0; i < 9; i++)
	{
		_InputWindow[i].comandoInput(_Mouse, &lastIngreso);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInput();
	}

	if (validarChecks(getCheck(), 9) == true) {
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
		champ->setID(arch.getCantidadRegistros() + 1);

		//Solo agregue esto
		champ->setEstado(true);

		if (arch.grabarRegistro(*champ, -1, Agregar) == 1)
		{
			std::cout << "Registro agregado" << std::endl;
		}
		else {
			std::cout << "Error agregando campeon" << std::endl;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Campeones);
			_Reloj->restart();
		}
	}

}

void Campeones_Alta::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	for (int i = 0; i < 2; i++)
	//{
	//	_Botones[i].dibujarBotoncito(_Ventana);
	//}

	//DIBUJADO
	for (int i = 0; i < 9; i++)
	{
		_InputWindow[i].draw(_Ventana);
	}


	_Ventana.draw(*_BordeVentana);
	_Ventana.draw(*_Titulo);
}

void Campeones_Alta::verificacionInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		std::string algo;
		char auxc[30] = {};
		float auxf = 0;
		int auxi = 0;

		//NOMBRE
		algo = _InputWindow[0].getTextoIngreso();
		for (int i = 0; i < algo.length(); i++) {
			auxc[i] = algo[i];
		}
		std::cout << "Nombre ingresado: " << std::endl;
		champ->setNombre(auxc);
		std::cout << champ->getNombre() << std::endl;
		if (champ->validarNombre(auxc) == true) {
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
			champ->setAtaque(auxf);
			std::cout << "Ataque ingresado: " << std::endl;
			std::cout << champ->getAtaque() << std::endl;
			if (champ->validarAtaque(auxf)) {
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
			champ->setVel_ataque(auxf);
			std::cout << "Velocidad de ataque: " << std::endl;
			std::cout << champ->getVel_ataque() << std::endl;
			if (champ->validarVa(auxf)) {
				check[2] = true;
				_InputWindow[2].setColor(sf::Color::Green);
			}
			else _InputWindow[2].setColor(sf::Color::Red);
		}
		//VIDA
		algo = _InputWindow[3].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[3].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setVida(auxf);
			std::cout << "Vida: " << std::endl;
			std::cout << champ->getVida() << std::endl;
			if (champ->validarVida(auxf)) {
				check[3] = true;
				_InputWindow[3].setColor(sf::Color::Green);
			}
			else _InputWindow[3].setColor(sf::Color::Red);
		}
		//ARMOR
		algo = _InputWindow[4].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[4].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setArmor(auxf);
			std::cout << "Armadura: " << std::endl;
			std::cout << champ->getArmor() << std::endl;
			if (champ->validarArmor(auxf)) {
				check[4] = true;
				_InputWindow[4].setColor(sf::Color::Green);
			}
			else _InputWindow[4].setColor(sf::Color::Red);
		}
		//RES. MAGICA
		algo = _InputWindow[5].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[5].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setResistencia_magica(auxf);
			std::cout << "Resistencia magica: " << std::endl;
			std::cout << champ->getResistencia_magica() << std::endl;
			if (champ->validarRM(auxf)) {
				check[5] = true;
				_InputWindow[5].setColor(sf::Color::Green);
			}
			else _InputWindow[5].setColor(sf::Color::Red);
		}
		//MANA
		algo = _InputWindow[6].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[6].setColor(sf::Color::Red);
		else
		{
			auxf = stof(algo);
			champ->setMana(auxf);
			std::cout << "Mana: " << std::endl;
			std::cout << champ->getMana() << std::endl;
			if (champ->validarMana(auxf)) {
				check[6] = true;
				_InputWindow[6].setColor(sf::Color::Green);
			}
			else _InputWindow[6].setColor(sf::Color::Red);
		}
		//ESTILO
		algo = _InputWindow[7].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[7].setColor(sf::Color::Red);
		else
		{
			auxi = stoi(algo);
			champ->setEstilo(auxi);
			std::cout << "Estilo: " << std::endl;
			switch (champ->getEstilo()) {
			case 1:
				std::cout << "Rol: Luchador" << std::endl;
				break;
			case 2:
				std::cout << "Rol: Mago" << std::endl;
				break;
			case 3:
				std::cout << "Rol: Asesino" << std::endl;
				break;
			case 4:
				std::cout << "Rol: Soporte" << std::endl;
				break;
			case 5:
				std::cout << "Rol: Tanque" << std::endl;
				break;
			case 6:
				std::cout << "Rol: Tirador" << std::endl;
				break;
			default:
				std::cout << "ERROR CARGANDO ROL" << std::endl;
			}
			if (champ->validarEstilo(auxi)) {
				check[7] = true;
				_InputWindow[7].setColor(sf::Color::Green);
			}
			else _InputWindow[7].setColor(sf::Color::Red);
		}
		//TIPODMG8
		algo = _InputWindow[8].getTextoIngreso();
		if (!validarNum(algo)) _InputWindow[8].setColor(sf::Color::Red);
		else
		{
			auxi = stoi(algo);
			champ->setdmgType(auxi);
			std::cout << "Tipo dmg: " << std::endl;
			switch (champ->getDmg()) {
			case 1:
				std::cout << "Tipo de danio: AD" << std::endl;
				break;
			case 2:
				std::cout << "Tipo de danio: AP" << std::endl;
				break;
			default:
				std::cout << "ERROR CARGANDO ESTILO" << std::endl;
			}
			if (champ->validarTipodmg(auxi)) {
				check[8] = true;
				_InputWindow[8].setColor(sf::Color::Green);
			}
			else _InputWindow[8].setColor(sf::Color::Red);
		}
	}
}

bool Campeones_Alta::validarChecks(bool checks[], int tam)
{
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

bool Campeones_Alta::validarNum(std::string& num)
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

void Campeones_Alta::inicializarBotones()
{
	//_Botones[0].setbothPos(510.0f, 500.0f);
	//_Botones[0].settxtPos(550.0f, 510.0f);
	//_Botones[0].setBtnType(BTN_VOLVER);
	//_Botones[0].setTextoString("Volver");
	//
	//_Botones[1].setBtnType(BTN_GUARDAR);
	//_Botones[1].setbtnPos(410, 500);
	//_Botones[1].setTextoString("GUARDAR");
}

Campeones_Alta::~Campeones_Alta()
{
	delete[] _InputWindow;
	delete[] _Botones;
	delete[] check;

	delete _BordeVentana;
	delete _Banner;
	delete _Titulo;
	delete _Mouse;
	delete _BordeTitulo;
	delete champ;
	delete _Banner;
	delete _Reloj;
}