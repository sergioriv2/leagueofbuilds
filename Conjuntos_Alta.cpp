#include "Conjuntos_Alta.h"
#include "Singleton.h"
#include "SubMenu_Conjuntos.h"

extern sf::Font* _FUENTE;

int contarRegistros_Champs()
{
	Campeon* aux;
	aux = new Campeon;

	int i = 0, cant = 0;
	Archivo arch("resources/campeones/champsdata.dat", sizeof * aux);
	while (arch.leerRegistro(*aux, i++)) if (aux->getEstado()) cant++;

	delete aux;
	return cant;
}

int contarRegistros_It()
{
	Item* aux;
	aux = new Item;

	int i = 0, cant = 0;
	Archivo arch("resources/items/itemsdata.dat", sizeof * aux);
	while (arch.leerRegistro(*aux, i++)) if (aux->getEstado()) cant++;

	delete aux;
	return cant;
}

void Conjuntos_Alta::inicializarBotones()
{
	_Botones[0].setbothPos(225, 60);
	_Botones[0].settxtPos(233, 58);
	_Botones[0].setSize(30.0f, 30.0f);
	_Botones[0].setTextoString("...");
	_Botones[0].setBtnType(BTN_DEFAULT);

	_Botones[1].setbothPos(225, 140);
	_Botones[1].settxtPos(233, 138);
	_Botones[1].setSize(30.0f, 30.0f);
	_Botones[1].setTextoString("...");
	_Botones[1].setBtnType(BTN_DEFAULT);

}

void Conjuntos_Alta::verificacionInput()
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

bool Conjuntos_Alta::validarChecks(bool checks[], int tam)
{
	for (int i = 0; i < tam; i++) {
		if (checks[i] != true) {
			return false;
		}
	}
	return true;
}

bool Conjuntos_Alta::validarNum(std::string& num)
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

void Conjuntos_Alta::process_event(const sf::Event& e)
{
	for (int i = 0; i < 20; i++) if (lastIngreso == NULL) _InputWindow[i].setSelected(false);
	if (e.type == sf::Event::TextEntered)
	{
		_InputWindow[lastIngreso - 1].callEventoIngreso(e);
	}

}

Conjuntos_Alta::Conjuntos_Alta()
{

	conjcab = new Conjunto_cabecera;
	check = new bool[20]{ false };
	conjdet = new Conjunto_detalle;
	_Titulo = new sf::Text;
	_InputWindow = new inputGUI[20];
	_BordeVentana = new sf::RectangleShape;
	_Mouse = new clsMouse;
	lastIngreso = 0;
	_Reloj = new sf::Clock;
	_Botones = new BotonGUI[2];

	Champs = false;
	Items = false;

	g = new sf::RenderWindow;
	ventana_Nueva = new sf::RenderWindow;

	//volver
	//btn[2].setbothPos(600.0f, 520.0f);
	//btn[2].settxtPos(640.0f, 530.0f);
	//btn[2].setBtnType(btnType::BTN_VOLVER);
	//btn[2].setTextoString("Volver");

	//btn[5].setBtnType(btnType::BTN_GUARDAR);
	//btn[5].setbtnPos(510, 500);
	//btn[5].setTextoString("GUARDAR");

	inicializarBotones();

	_Reloj->restart();

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	//TITULO DEL SUBMENU -------------------------

	_Titulo->setString("AGREGAR CONJUNTO");
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

	_InputWindow[7].setPos(280, 110);
	_InputWindow[7].setStringSubtitulo("ID ITEM MID 1");

	_InputWindow[8].setPos(280, 190);
	_InputWindow[8].setStringSubtitulo("ID ITEM MID 2");

	_InputWindow[9].setPos(280, 270);
	_InputWindow[9].setStringSubtitulo("ID ITEM MID 3");

	_InputWindow[10].setPos(280, 350);
	_InputWindow[10].setStringSubtitulo("ID ITEM MID 4");

	_InputWindow[11].setPos(280, 430);
	_InputWindow[11].setStringSubtitulo("ID ITEM MID 5");

	_InputWindow[12].setPos(280, 510);
	_InputWindow[12].setStringSubtitulo("ID ITEM MID 6");

	_InputWindow[13].setPos(535, 110);
	_InputWindow[13].setStringSubtitulo("ID ITEM LATE 1");

	_InputWindow[14].setPos(535, 190);
	_InputWindow[14].setStringSubtitulo("ID ITEM LATE 2");

	_InputWindow[15].setPos(535, 270);
	_InputWindow[15].setStringSubtitulo("ID ITEM LATE 3");

	_InputWindow[16].setPos(535, 350);
	_InputWindow[16].setStringSubtitulo("ID ITEM LATE 4");

	_InputWindow[17].setPos(535, 430);
	_InputWindow[17].setStringSubtitulo("ID ITEM LATE 5");

	_InputWindow[18].setPos(535, 510);
	_InputWindow[18].setStringSubtitulo("ID ITEM LATE 6");

	_InputWindow[19].setPos(280, 30);
	_InputWindow[19].setStringSubtitulo("NOMBRE DEL CONJUNTO");
	_InputWindow[19].setSizeRectangulo(280, 30);
	_InputWindow[19].setLimiteIngreso(30);
}

void Conjuntos_Alta::init_campeones()
{
	// MISMA INICIALIZACION QUE EL LISTADO DE CAMPEONES, LO UNICO QUE CAMBIA ES LA INICIALIZACION DE CLASES

	ventana_Nueva->create(sf::VideoMode(500, 800), "Listado Campeones");// con todos los parametros y tal 
	ventana_Nueva->setFramerateLimit(30);

	_Titulo2 = new sf::Text;
	_BordeVentana2 = new sf::RectangleShape;

	_CantidadPaginas = 0;
	_ChampsAMostrar = 0;
	_PagActual = 1;

	_Titulo2->setFont(*_FUENTE);
	_Titulo2->setString("LISTADO DE CAMPEONES (ID Y NOMBRE)");
	_Titulo2->setPosition(50.0f, 30.0f);
	_Titulo2->setCharacterSize(15);

	_BordeVentana2->setSize({ 460, 770 });
	_BordeVentana2->setFillColor(sf::Color::Transparent);
	_BordeVentana2->setOutlineThickness(1.0f);
	_BordeVentana2->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana2->setPosition(20, 20);


	// Prueba ---------

	//ARCHIVO DE CAMPEONES
	Campeon* aux;
	aux = new Campeon;

	Archivo* arch;
	arch = new Archivo("resources/campeones/champsdata.dat", sizeof(Campeon));

	float y = 120;

	//Variable j para leer todos los registros, variable k para leer el registro especifico
	int j = 0, k = 0;

	//Consulto cuantos registros de item hay con true

	//Tambien veo cuantas paginas voy a tener
	_ChampsAMostrar = contarRegistros_Champs();

	///////////////////////////////////////////////////////////
	// Esto es para saber cuantas paginas va a tener la lista
	///////////////////////////////////////////////////////////

	//Declaro un float auxiliar para saber los decimales y le hago los casteos
	float auxFloat = (float)_ChampsAMostrar / (float)44;
	//Entero sin decimales

	_CantidadPaginas = _ChampsAMostrar / 44;

	//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
	auxFloat = auxFloat - (float)_CantidadPaginas;
	if (auxFloat != 0.0) _CantidadPaginas++;

	//La cantidad de registros es igual a la cantidad de egresos

	if (_CantidadPaginas == 0)outputWindow = new outputGUI;
	else outputWindow = new outputGUI[_ChampsAMostrar];

	//Inicializacion de la clase
	for (int i = 0; i < _ChampsAMostrar; i++)
	{
		outputWindow[i] = outputGUI({ 150, 30 });	// ------------ NUEVO CONSTRUCTOR
	}

	//Seteos de la posicion

	bool segndaCol = true;

	for (int i = 0; i < _ChampsAMostrar; i++)		// --------- TAMBIEN ESTO SE CAMBIO PARA MOSTRAR 2 COLUMNAS
													// --------- HACER LO MISMO EN ITEMS
	{
		outputWindow[i].setidOutput(i + 1);

		if (i % 22 == 0)
		{
			if (segndaCol) segndaCol = false;
			else segndaCol = true;

			y = 100.0f;

			if (segndaCol)
			{
				outputWindow[i].setPosicion(y, true, 201.0f);	// Tercer parametro es un offset
			}
			else
			{
				outputWindow[i].setPosicion(y, true, 50.0f);
			}

			y += 30.0f;
		}
		else
		{
			if (segndaCol)
			{
				outputWindow[i].setPosicion(y, true, 201.0f);
			}
			else
			{
				outputWindow[i].setPosicion(y, true, 50.0f);
			}

			y += 30.0f;
		}

	}

	//Ahora queda pasar los datos de los registros a los egresos
	while (arch->leerRegistro(*aux, j++) == 1)
	{
		if (aux->getEstado())
		{
			//Sobrecarga de operador
			outputWindow[k] = *aux;
			k++;
		}
	}

	delete aux;
	delete arch;

	// -------------------
}

void Conjuntos_Alta::update_campeones()
{
	while (ventana_Nueva->hasFocus()) {
		sf::Event e;
		while (ventana_Nueva->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				Champs = false;
				ventana_Nueva->close();
			}
		}

		sf::Event e2;
		while (g->pollEvent(e2))
		{
			if (e2.type == sf::Event::MouseButtonPressed)
			{
				g->requestFocus();
			}
		}
		// ------------

		ventana_Nueva->clear(sf::Color(14, 22, 33, 255));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Sleep(200);
			if (_PagActual < _CantidadPaginas) (_PagActual)++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Sleep(200);
			if (_PagActual != 1) (_PagActual)--;
		}


		//DIBUJADO DE LOS EGRESOS DE LA LISTA
		if (_ChampsAMostrar <= 44)
		{
			for (int i = 0; i < _ChampsAMostrar; i++)
			{
				outputWindow[i].drawChConj(ventana_Nueva);
			}
		}
		else
		{
			if (_PagActual == _CantidadPaginas)
			{
				for (int i = 44 * (_PagActual - 1); i < _ChampsAMostrar; i++)
				{
					outputWindow[i].drawChConj(ventana_Nueva);
				}
			}
			else
			{
				for (int i = 44 * (_PagActual - 1); i < (44 * _PagActual); i++)
				{
					outputWindow[i].drawChConj(ventana_Nueva);
				}
			}

		}

		ventana_Nueva->draw(*_Titulo2);
		ventana_Nueva->draw(*_BordeVentana2);

		// -----------

		ventana_Nueva->display();

	}
}

void Conjuntos_Alta::update(sf::RenderWindow& _Ventana)
{
	g = &_Ventana;

	sf::Event e;
	while (ventana_Nueva->pollEvent(e)) {
		if (e.type == sf::Event::MouseButtonPressed) {
			ventana_Nueva->requestFocus();
		}
	}

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
		//Seteo el ID de ccab
		conjcab->setidConjunto();
		//ID cdet
		conjdet->setDetalle(conjcab->getidConjunto());

		conjcab->setEstado(true);
		conjdet->setEstado(true);

		//guardo y seteo el costo
		if (archdetalle.grabarRegistro(*conjdet, -1, Agregar))
		{
			conjcab->setCostototal(conjcab->getCosto());
			archcab.grabarRegistro(*conjcab, -1, Agregar);
			std::cout << "Conjunto agregado" << std::endl;
			ventana_Nueva->close();
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Conjuntos);
		}

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			ventana_Nueva->close();
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Conjuntos);
		}
	}

	// PRIMER BOTON PARA MOSTRAR CHAMPS POR VENTANA ------------------------------------------------------

	if (_Mouse->getCircleShape().getGlobalBounds().intersects(_Botones[0].getButton().getGlobalBounds()))
	{
		//CLIC DEL MOUSE
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			if (!Champs)	// FILTRO PARA EVITAR MULTIPLES CREACIONES DE VENTANAS
			{
				this->init_campeones();	// LLAMO LA FUNCION PARA INICIALIZAR LAS VARIABLES QUE VOY A USAR
				Champs = true;
			}
			_Reloj->restart();
		}
	}

	// SEGUNDO BOTON PARA MOSTRAR ITEMS POR VENTANA ------------------------------------------------------

	if (_Mouse->getCircleShape().getGlobalBounds().intersects(_Botones[1].getButton().getGlobalBounds()))
	{
		//CLIC DEL MOUSE
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			if (!Items)	// FILTRO PARA EVITAR MULTIPLES CREACIONES DE VENTANAS
			{
				this->init_items();
				Items = true;
			}
			_Reloj->restart();
		}
	}

	if (Champs)
	{
		Items = false;
		this->update_campeones();	// UNA VEZ SE INICIALIZA DENTRO DEL MAIN UPDATE, PONGO EL UPDATE DE LA VENTANA SECUNDARIA
	}

	if (Items)
	{
		Champs = false;
		this->update_items();
	}



	for (int i = 0; i < 2; i++)
	{
		_Botones[i].cmd(*_Mouse);
		_Botones[i].update();
	}

}

void Conjuntos_Alta::init_items()
{
	ventana_Nueva->create(sf::VideoMode(550, 800), "Listado Items");// con todos los parametros y tal 
	ventana_Nueva->setFramerateLimit(30);

	_Titulo2 = new sf::Text;
	_BordeVentana2 = new sf::RectangleShape;

	_CantidadPaginas = 0;
	_ItemsAMostrar = 0;
	_PagActual = 1;

	_Titulo2->setFont(*_FUENTE);
	_Titulo2->setString("LISTADO DE ITEMS (ID Y NOMBRE)");
	_Titulo2->setPosition(50.0f, 30.0f);
	_Titulo2->setCharacterSize(15);

	_BordeVentana2->setSize({ 510, 770 });
	_BordeVentana2->setFillColor(sf::Color::Transparent);
	_BordeVentana2->setOutlineThickness(1.0f);
	_BordeVentana2->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana2->setPosition(20, 20);


	// Prueba ---------

	Item* aux;
	aux = new Item;

	Archivo* arch;
	arch = new Archivo("resources/items/itemsdata.dat", sizeof(Item));

	float y = 120;

	//Variable j para leer todos los registros, variable k para leer el registro especifico
	int j = 0, k = 0;


	//Consulto cuantos registros de item hay con true

	//Tambien veo cuantas paginas voy a tener
	_ItemsAMostrar = contarRegistros_It();
	///////////////////////////////////////////////////////////
	// Esto es para saber cuantas paginas va a tener la lista
	///////////////////////////////////////////////////////////

	//Declaro un float auxiliar para saber los decimales y le hago los casteos
	float auxFloat = (float)_ItemsAMostrar / (float)44;
	//Entero sin decimales

	_CantidadPaginas = _ItemsAMostrar / 44;

	//Con tener un decimal voy a necesitar una pagina mas asi que hago ese algoritmo para disciminar decimales
	auxFloat = auxFloat - (float)_CantidadPaginas;
	if (auxFloat != 0.0) _CantidadPaginas++;

	//La cantidad de registros es igual a la cantidad de egresos
	if (_CantidadPaginas == 0) outputWindow = new outputGUI;
	else outputWindow = new outputGUI[_ItemsAMostrar];

	//Inicializacion de la clase
	for (int i = 0; i < _ItemsAMostrar; i++)
	{
		outputWindow[i] = outputGUI({ 230, 30 });
	}
	//Seteos de la posicion

	bool segndaCol = true;

	for (int i = 0; i < _ItemsAMostrar; i++)
	{
		outputWindow[i].setidOutput(i + 1);

		if (i % 22 == 0)
		{
			if (segndaCol) segndaCol = false;
			else segndaCol = true;

			y = 100.0f;

			if (segndaCol)
			{
				outputWindow[i].setPosicion(y, false, 230.0f);	// Tercer parametro es un offset
			}
			else
			{
				outputWindow[i].setPosicion(y, false);	// Tercer parametro es un offset
			}

			y += 30.0f;
		}
		else
		{
			if (segndaCol)
			{
				outputWindow[i].setPosicion(y, false, 230.0f);
			}
			else
			{
				outputWindow[i].setPosicion(y, false);
			}
			y += 30.0f;
		}

	}

	//Ahora queda pasar los datos de los registros a los egresos

	while (arch->leerRegistro(*aux, j++) == 1)
	{
		if (aux->getEstado())
		{
			//Sobrecarga de operador
			outputWindow[k] = *aux;
			k++;
		}
	}

	delete arch;
	delete aux;

	// -------------------
}

void Conjuntos_Alta::update_items()
{
	while (ventana_Nueva->hasFocus()) {
		sf::Event e;
		while (ventana_Nueva->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				Items = false;
				ventana_Nueva->close();
			}
		}

		sf::Event e2;
		while (g->pollEvent(e2))
		{
			if (e2.type == sf::Event::MouseButtonPressed)
			{
				g->requestFocus();
			}
		}
		// ------------

		ventana_Nueva->clear(sf::Color(14, 22, 33, 255));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Sleep(200);
			if (_PagActual < _CantidadPaginas) (_PagActual)++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Sleep(200);
			if (_PagActual != 1) (_PagActual)--;
		}


		//DIBUJADO DE LOS EGRESOS DE LA LISTA
		if (_ItemsAMostrar <= 44)
		{
			for (int i = 0; i < _ItemsAMostrar; i++)
			{
				outputWindow[i].drawChConj(ventana_Nueva);
			}
		}
		else
		{
			if (_PagActual == _CantidadPaginas)
			{
				for (int i = 44 * (_PagActual - 1); i < _ItemsAMostrar; i++)
				{
					outputWindow[i].drawChConj(ventana_Nueva);
				}
			}
			else
			{
				for (int i = 44 * (_PagActual - 1); i < (44 * _PagActual); i++)
				{
					outputWindow[i].drawChConj(ventana_Nueva);
				}
			}

		}

		ventana_Nueva->draw(*_Titulo2);
		ventana_Nueva->draw(*_BordeVentana2);

		// -----------

		ventana_Nueva->display();

	}
}

void Conjuntos_Alta::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));
	//DRAW
	for (int i = 0; i < 20; i++)
	{
		_InputWindow[i].draw(_Ventana);
	}

	_Ventana.draw(*_BordeVentana);

	for (int i = 0; i < 2; i++)
	{
		_Botones[i].dibujarBotoncito(_Ventana);
	}


	//btn[2].dibujarBotoncito(*ventana);
}

Conjuntos_Alta::~Conjuntos_Alta()
{
	if (ventana_Nueva != nullptr) delete ventana_Nueva;
	if (_BordeVentana2 != nullptr) delete _BordeVentana2;
	if (_Titulo2 != nullptr) delete _Titulo2;
	if (outputWindow != nullptr) delete[] outputWindow;

	g = nullptr;
	delete g;

	delete conjcab;
	delete[] check;
	delete  conjdet;
	delete  _Titulo;
	delete[] _InputWindow;
	delete _Mouse;
	delete _Reloj;
	delete _BordeVentana;
}
