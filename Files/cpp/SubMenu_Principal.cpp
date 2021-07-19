#include "../hpp/SubMenu_Principal.h"

const char* HEADER_MENUPRINCIPAL = "resources/gui/header_menuprincipal.jpg";
extern sf::Font* _FUENTE;

SubMenu_Principal::SubMenu_Principal()
{
	_Botones = new BotonGUI[6];
	_Banner = new headerGUI;
	_Titulo = new sf::Text;
	_BordeTitulo = new sf::RectangleShape;
	_BordeVentana = new sf::RectangleShape;

	_Mouse = new clsMouse;

	_BordeTitulo->setPosition(40.0f, 190.0f);
	_Titulo->setPosition(60.0f, 200.0f);
	_Titulo->setString("MENU PRINCIPAL");
	_Banner->setTexture(HEADER_MENUPRINCIPAL);
	
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

void SubMenu_Principal::inicializarBotones()
{
	_Botones[0].setbothPos(80.0f, 280.0f);
	_Botones[0].settxtPos(100.0f, 290.0f);
	_Botones[0].setBtnEstado(NINGUNO);
	_Botones[0].setBtnType(BTN_CHAMPS);
	_Botones[0].setTextoString("Menu Campeones");
	//1: MENU ITEMS
	_Botones[1].setbothPos(80.0f, 380.0f);
	_Botones[1].settxtPos(110.0f, 390.0f);
	_Botones[1].setBtnEstado(NINGUNO);
	_Botones[1].setBtnType(BTN_ITEMS);
	_Botones[1].setTextoString("Menu Items");
	//2: MENU CONJUNTOS
	_Botones[2].setbothPos(80.0f, 480.0f);
	_Botones[2].settxtPos(100.0f, 490.0f);
	_Botones[2].setBtnEstado(NINGUNO);
	_Botones[2].setBtnType(BTN_CONJ);
	_Botones[2].setTextoString("Menu Conjuntos");
	//3: BACKUP
	_Botones[3].setbothPos(480.0f, 280.0f);
	_Botones[3].settxtPos(510.0f, 290.0f);
	_Botones[3].setBtnEstado(NINGUNO);
	_Botones[3].setBtnType(BTN_BACKUP);
	_Botones[3].setTextoString("Menu Backups");
	//4: DEVMENU
	_Botones[4].setbothPos(480.0f, 380.0f);
	_Botones[4].settxtPos(525.0f, 390.0f);
	_Botones[4].setBtnEstado(NINGUNO);
	_Botones[4].setBtnType(BTN_DEVMENU);
	_Botones[4].setTextoString("DevMenu");
	//5: SALIR
	_Botones[5].setbothPos(480.0f, 480.0f);
	_Botones[5].settxtPos(540.0f, 490.0f);
	_Botones[5].setBtnType(BTN_SALIR);
	_Botones[5].setTextoString("Salir");
}

void SubMenu_Principal::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);

	//CMD De cada botoncito
	for (int i = 0; i < 6; i++) _Botones[i].cmd(*_Mouse);

	//UPDATE De cada botoncito
	for (int i = 0; i < 6; i++) _Botones[i].update();
}

void SubMenu_Principal::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	for (int i = 0; i < 6; i++)
	{
		_Botones[i].dibujarBotoncito(_Ventana);
	}

	//DRAW titulo
	_Ventana.draw(_Banner->getHeader());
	_Ventana.draw(*_BordeTitulo);
	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}

SubMenu_Principal::~SubMenu_Principal()
{
	delete[] _Botones;
	delete _BordeVentana;
	delete _Banner;
	delete _Titulo;
	delete _Mouse;
	delete _BordeTitulo;
}
