#include "Campeones_Mod.h"
#include "Singleton.h"
#include "SubMenu_Campeones.h"
#include "Campeones_Listado.h"

extern sf::Font* _FUENTE;

void Campeones_Mod::inicializarBotones()
{
}

void Campeones_Mod::verificacionInput()
{
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

bool Campeones_Mod::validarChecks(bool checks[], int tam)
{
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

bool Campeones_Mod::validarNum(std::string& num)
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

Campeones_Mod::Campeones_Mod(outputGUI& _Champ)
{
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	_Botones = new BotonGUI[2];
	_InputWindow = new inputGUI[14];
	_Titulo = new sf::Text;
	outputWindow = new outputGUI;
	_Reloj = new sf::Clock;

	champ = new Campeon;
	check = new bool[14]{ false };


	*outputWindow = _Champ;

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

	// INICIALIZACION PARA EL INGRESO POR VENTANA 
	for (int i = 0; i < 9; i++)
	{
		_InputWindow[i] = inputGUI(80.0f);
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

}

void Campeones_Mod::process_event(const sf::Event& e)
{
	for (int i = 0; i < 9; i++) if (lastIngreso == NULL) _InputWindow[i].setSelected(false);
	if (e.type == sf::Event::TextEntered)
	{
		_InputWindow[lastIngreso - 1].callEventoIngreso(e);
	}
}

void Campeones_Mod::update(sf::RenderWindow& _Ventana)
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
	if (validarChecks(getCheck(), 9) == true) {
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
		std::string auxid = outputWindow->getId().getString();

		champ->setEstado(true);
		champ->setID(stoi(auxid));
		if (arch.grabarRegistro(*champ, stoi(auxid) - 1, LecturaEscritura))
		{
			std::cout << "Registro editado" << std::endl;
		}
		else
		{
			std::cout << "Error al editar registro" << std::endl;
		}
		Singleton::getInstancia().cambiar_Menu(new SubMenu_Campeones);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Campeones_Listado);
		}
	}
}

void Campeones_Mod::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	for (int i = 0; i < 9; i++)
	{
		_InputWindow[i].draw(_Ventana);
	}

	//btn[5].dibujarBotoncito(*ventana);
	_Ventana.draw(*_BordeVentana);
	_Ventana.draw(*_Titulo);
}

Campeones_Mod::~Campeones_Mod()
{
	delete _BordeVentana ;
	delete _Mouse;
	delete[] _Botones;
	delete[] _InputWindow;
	delete _Titulo;
	delete outputWindow;

	delete champ;
	delete[] check;
	delete _Reloj;
}
