#include "../hpp/Conjuntos_Mod.h"
#include "../hpp/Singleton.h"
#include "../hpp/Conjuntos_Listado.h"

extern sf::Font* _FUENTE;

void Conjuntos_Mod::inicializarBotones()
{
}

void Conjuntos_Mod::verificacionInput()
{
	std::string algo;
	int auxi = 0;
	char auxc[30] = {};

	/*
	0 ID CHAMP
	1 ID ITEM E 1
	2 ID ITEM E 2
	3 ID ITEM E 3
	4 ID ITEM E 4
	5 ID ITEM E 5
	6 ID ITEM E 6
	7 ID ITEM M 1
	8 ID ITEM M 2
	9 ID ITEM M 3
	10 ID ITEM M 4
	11 ID ITEM M 5
	12 ID ITEM M 6
	13 ID ITEM L 1
	14 ID ITEM L 2
	15 ID ITEM L 3
	16 ID ITEM L 4
	17 ID ITEM L 5
	18 ID ITEM L 6
	19 NOMBRE CONJUNTO
	*/
	//IDCHAMP

	algo = _InputWindow[0].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[0].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjcab->setidCampeon(auxi);
		if (conjcab->idchampcheck(conjcab->getidCampeon()))
		{
			check[0] = true;
			_InputWindow[0].setColor(sf::Color::Green);
		}
		else _InputWindow[0].setColor(sf::Color::Red);
	}
	//NOMBRE
	algo = _InputWindow[19].getTextoIngreso();
	for (int i = 0; i < algo.length(); i++) {
		auxc[i] = algo[i];
	}
	std::cout << "Nombre ingresado: " << std::endl;
	conjcab->setNombre(auxc);
	std::cout << conjcab->getNombre() << std::endl;
	if (conjcab->validarNombre(auxc) == true) {
		check[19] = true;
		_InputWindow[19].setColor(sf::Color::Green);
	}
	else _InputWindow[19].setColor(sf::Color::Red);
	//ID ITEMS EARLY 1 
	algo = _InputWindow[1].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[1].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);

		conjdet->setidEarly(auxi, 0);//iditem,pos del vec
		std::cout << "EARLY INGRESADO " << conjdet->getidEarly(0) << std::endl;
		if (conjdet->iditemcheck(conjdet->getidEarly(0))) {
			check[1] = true;
			_InputWindow[1].setColor(sf::Color::Green);
		}
		else _InputWindow[1].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 2
	algo = _InputWindow[2].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[2].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(1))) {
			check[2] = true;
			_InputWindow[2].setColor(sf::Color::Green);
		}
		else _InputWindow[2].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 3
	algo = _InputWindow[3].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[3].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(2))) {
			check[3] = true;
			_InputWindow[3].setColor(sf::Color::Green);
		}
		else _InputWindow[3].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 4
	algo = _InputWindow[4].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[4].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidEarly(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(3))) {
			check[4] = true;
			_InputWindow[4].setColor(sf::Color::Green);
		}
		else _InputWindow[4].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 5
	algo = _InputWindow[5].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[5].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidEarly(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(4))) {
			check[5] = true;
			_InputWindow[5].setColor(sf::Color::Green);
		}
		else _InputWindow[5].setColor(sf::Color::Red);
	}
	//ID ITEMS EARLY 6
	algo = _InputWindow[6].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[6].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidEarly(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidEarly(5))) {
			check[6] = true;
			_InputWindow[6].setColor(sf::Color::Green);
		}
		else _InputWindow[6].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 1
	algo = _InputWindow[7].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[7].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 0);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(0))) {
			check[7] = true;
			_InputWindow[7].setColor(sf::Color::Green);
		}
		else _InputWindow[7].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 2
	algo = _InputWindow[8].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[8].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(1))) {
			check[8] = true;
			_InputWindow[8].setColor(sf::Color::Green);
		}
		else _InputWindow[8].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 3
	algo = _InputWindow[9].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[9].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(2))) {
			check[9] = true;
			_InputWindow[9].setColor(sf::Color::Green);
		}
		else _InputWindow[9].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 4
	algo = _InputWindow[10].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[10].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidMid(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(3))) {
			check[10] = true;
			_InputWindow[10].setColor(sf::Color::Green);
		}
		else _InputWindow[10].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 5
	algo = _InputWindow[11].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[11].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidMid(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(4))) {
			check[11] = true;
			_InputWindow[11].setColor(sf::Color::Green);
		}
		else _InputWindow[11].setColor(sf::Color::Red);
	}
	//ID ITEMS MID 6
	algo = _InputWindow[12].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[12].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidMid(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidMid(5))) {
			check[12] = true;
			_InputWindow[12].setColor(sf::Color::Green);
		}
		else _InputWindow[12].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 1
	algo = _InputWindow[13].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[13].setColor(sf::Color::Red);
	}
	else
	{
		auxi = stoi(algo);
		conjdet->setidLate(auxi, 0);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(0))) {
			check[13] = true;
			_InputWindow[13].setColor(sf::Color::Green);
		}
		else _InputWindow[13].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 2
	algo = _InputWindow[14].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[14].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 1);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(1))) {
			check[14] = true;
			_InputWindow[14].setColor(sf::Color::Green);
		}
		else _InputWindow[14].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 3
	algo = _InputWindow[15].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[15].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 2);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(2))) {
			check[15] = true;
			_InputWindow[15].setColor(sf::Color::Green);
		}
		else _InputWindow[15].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 4
	algo = _InputWindow[16].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[16].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 3);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(3))) {
			check[16] = true;
			_InputWindow[16].setColor(sf::Color::Green);
		}
		else _InputWindow[16].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 5
	algo = _InputWindow[17].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[17].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 4);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(4))) {
			check[17] = true;
			_InputWindow[17].setColor(sf::Color::Green);
		}
		else _InputWindow[17].setColor(sf::Color::Red);
	}
	//ID ITEMS LATE 6
	algo = _InputWindow[18].getTextoIngreso();
	if (!validarNum(algo)) {
		_InputWindow[18].setColor(sf::Color::Red);
	}
	else
	{
		auxi = std::stoi(algo);
		conjdet->setidLate(auxi, 5);//iditem,pos del vec
		if (conjdet->iditemcheck(conjdet->getidLate(5))) {
			check[18] = true;
			_InputWindow[18].setColor(sf::Color::Green);
		}
		else _InputWindow[18].setColor(sf::Color::Red);
	}
}

bool Conjuntos_Mod::validarNum(std::string& num)
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

bool Conjuntos_Mod::validarChecks(bool checks[], int tam)
{
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

Conjuntos_Mod::Conjuntos_Mod(outputGUI& _Conj)
{
	conjcab = new Conjunto_cabecera;
	check = new bool[20]{ false };
	conjdet = new Conjunto_detalle;
	_AuxConj = new outputGUI;
	_Titulo = new sf::Text;
	_Mouse = new clsMouse;
	_InputWindow = new inputGUI[20];
	_BordeVentana = new sf::RectangleShape;
	_Reloj = new sf::Clock;

	*_AuxConj = _Conj;
	_Reloj->restart();
	//Cargo en las variables de conjunto lo que hay en el archivo

	Archivo* archdet, * archcab;
	archcab = new Archivo("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	archdet = new Archivo("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));

	std::string aux = _AuxConj->getId().getString();

	archcab->leerRegistro(*conjcab, stoi(aux));
	archdet->leerRegistro(*conjdet, stoi(aux));

	//TITULO DEL SUBMENU -------------------------

	_Titulo->setString("MODIFICACION CONJUNTO");
	_Titulo->setFont(*_FUENTE);
	_Titulo->setCharacterSize(23);
	_Titulo->setPosition(60, 30);

	// ---------------------------------------------

	for (int i = 0; i < 20; i++)
	{
		_InputWindow[i] = inputGUI(80);
		_InputWindow[i].setID(i + 1);
		_InputWindow[i].setLimiteIngreso(5);
	}

	_InputWindow[0].setPos(55, 30);
	_InputWindow[0].setStringSubtitulo("ID CAMPEON");


	_InputWindow[1].setPos(55, 110);
	_InputWindow[1].setStringSubtitulo("ID ITEM EARLY 1");

	_InputWindow[2].setPos(55, 190);
	_InputWindow[2].setStringSubtitulo("ID ITEM EARLY 2");

	_InputWindow[3].setPos(55, 270);
	_InputWindow[3].setStringSubtitulo("ID ITEM EARLY 3");

	_InputWindow[4].setPos(55, 350);
	_InputWindow[4].setStringSubtitulo("ID ITEM EARLY 4");

	_InputWindow[5].setPos(55, 430);
	_InputWindow[5].setStringSubtitulo("ID ITEM EARLY 5");

	_InputWindow[6].setPos(55, 510);
	_InputWindow[6].setStringSubtitulo("ID ITEM EARLY 6");

	_InputWindow[7].setPos(235, 110);
	_InputWindow[7].setStringSubtitulo("ID ITEM MID 1");

	_InputWindow[8].setPos(235, 190);
	_InputWindow[8].setStringSubtitulo("ID ITEM MID 2");

	_InputWindow[9].setPos(235, 270);
	_InputWindow[9].setStringSubtitulo("ID ITEM MID 3");

	_InputWindow[10].setPos(235, 350);
	_InputWindow[10].setStringSubtitulo("ID ITEM MID 4");

	_InputWindow[11].setPos(235, 430);
	_InputWindow[11].setStringSubtitulo("ID ITEM MID 5");

	_InputWindow[12].setPos(235, 510);
	_InputWindow[12].setStringSubtitulo("ID ITEM MID 6");

	_InputWindow[13].setPos(415, 110);
	_InputWindow[13].setStringSubtitulo("ID ITEM LATE 1");

	_InputWindow[14].setPos(415, 190);
	_InputWindow[14].setStringSubtitulo("ID ITEM LATE 2");

	_InputWindow[15].setPos(415, 270);
	_InputWindow[15].setStringSubtitulo("ID ITEM LATE 3");

	_InputWindow[16].setPos(415, 350);
	_InputWindow[16].setStringSubtitulo("ID ITEM LATE 4");

	_InputWindow[17].setPos(415, 430);
	_InputWindow[17].setStringSubtitulo("ID ITEM LATE 5");

	_InputWindow[18].setPos(415, 510);
	_InputWindow[18].setStringSubtitulo("ID ITEM LATE 6");

	_InputWindow[19].setPos(235, 30);
	_InputWindow[19].setStringSubtitulo("NOMBRE DEL CONJUNTO");
	_InputWindow[19].setSizeRectangulo(280, 30);
	_InputWindow[19].setLimiteIngreso(30);
}

void Conjuntos_Mod::process_event(const sf::Event& e)
{
	for (int i = 0; i < 20; i++) if (lastIngreso == NULL) _InputWindow[i].setSelected(false);
	if (e.type == sf::Event::TextEntered)
	{
		_InputWindow[lastIngreso - 1].callEventoIngreso(e);
	}
}

void Conjuntos_Mod::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	for (int i = 0; i < 20; i++)
	{
		_InputWindow[i].comandoInput(_Mouse, &lastIngreso);
	}
	//IFENTERPRESSED
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		verificacionInput();
	}
	//VALIDARGUARDAR acordarse de setear la id de conjcab
	if (validarChecks(getCheck(), 20) == true)
	{
		Archivo archdetalle("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
		Archivo archcab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));

		std::string auxid = _AuxConj->getId().getString();

		//Seteo el ID 
		conjcab->setID(stoi(auxid));
		conjdet->setDetalle(stoi(auxid));

		conjcab->setEstado(true);
		conjdet->setEstado(true);

		//guardo y seteo el costo
		if (archdetalle.grabarRegistro(*conjdet, stoi(auxid) - 1, LecturaEscritura))
		{
			conjcab->setCostototal(conjcab->getCosto());
			archcab.grabarRegistro(*conjcab, stoi(auxid) - 1, LecturaEscritura);
			std::cout << "Conjunto modificado" << std::endl;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new Conjuntos_Listado);
		}
	}
}

void Conjuntos_Mod::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	//DRAW
	for (int i = 0; i < 20; i++)
	{
		_InputWindow[i].draw(_Ventana);
	}

	_Ventana.draw(*_BordeVentana);
	_Ventana.draw(*_Titulo);
}

Conjuntos_Mod::~Conjuntos_Mod()
{
	delete conjcab;
	delete[] check;
	delete  conjdet;
	delete  _Titulo;
	delete _AuxConj;
	delete[] _InputWindow;
	delete _BordeVentana;
	delete _Mouse;
	delete _Reloj;

}

