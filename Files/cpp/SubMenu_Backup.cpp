#include "../hpp/SubMenu_Backup.h"
#include "../hpp/Singleton.h"
#include "../hpp/SubMenu_Principal.h"

const char* HEADER_MENUBACKUP = "resources/gui/header_menubackup.jpg";

extern sf::Font* _FUENTE;

void SubMenu_Backup::inicializarBotones()
{
	_Botones[0].setbothPos(80.0f, 320.0f);
	_Botones[0].setBtnType(btnType::BTN_CREATE_BKP);
	_Botones[0].setTextoString("Crear Backup");

	_Botones[1].setbothPos(80.0f, 400.0f);
	_Botones[1].setBtnType(btnType::BTN_RESTORE_BKP);
	_Botones[1].setTextoString("Restaurar Backup");

	_Botones[2].setbothPos(80.0f, 480.0f);
	_Botones[2].setBtnType(btnType::BTN_VOLVER);
	_Botones[2].setTextoString("Volver");
}

SubMenu_Backup::SubMenu_Backup()
{
	_Banner = new headerGUI;
	_BordeTitulo = new sf::RectangleShape;
	_Titulo = new sf::Text;
	_Botones = new BotonGUI[3];
	_Mouse = new clsMouse;
	_BordeVentana = new sf::RectangleShape;
	_Reloj = new sf::Clock;

	_Banner->setTexture(HEADER_MENUBACKUP);
	_BordeTitulo->setPosition(40.0f, 190.0f);
	_Titulo->setPosition(60.0f, 200.0f);
	_Titulo->setString("MENU DE BACKUP");
	_Reloj->restart();

	_BordeVentana->setSize({ 760, 560 });
	_BordeVentana->setFillColor(sf::Color::Transparent);
	_BordeVentana->setOutlineThickness(1.0f);
	_BordeVentana->setOutlineColor(sf::Color(6, 150, 170, 255));
	_BordeVentana->setPosition(20, 20);

	inicializarBotones();
}

bool SubMenu_Backup::Create_Bkp()
{
	//files
	Archivo archChamp("resources/campeones/champsdata.dat", sizeof(Campeon));
	Archivo archItem("resources/items/itemsdata.dat", sizeof(Item));
	Archivo archCab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	Archivo archDet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//bkp files
	Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
	Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
	Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
	Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

	champ = new Campeon;
	item = new Item;
	conjcab = new Conjunto_cabecera;
	conjdet = new Conjunto_detalle;

	if (archChamp.crearBackup(*champ, archChampbkp) == false)return false;
	if (archItem.crearBackup(*item, archItembkp) == false)return false;
	if (archCab.crearBackup(*conjcab, archCabbkp) == false)return false;
	if (archDet.crearBackup(*conjdet, archDetbkp) == false)return false;

	delete(champ);
	delete(item);
	delete(conjcab);
	delete(conjdet);
	return true;
}

bool SubMenu_Backup::Restore_Bkp()
{
	//files
	Archivo archChamp("resources/campeones/champsdata.dat", sizeof(Campeon));
	Archivo archItem("resources/items/itemsdata.dat", sizeof(Item));
	Archivo archCab("resources/conjuntos/conjunto_cabecera.dat", sizeof(Conjunto_cabecera));
	Archivo archDet("resources/conjuntos/conjunto_detalle.dat", sizeof(Conjunto_detalle));
	//bkp files
	Archivo archChampbkp("resources/backups/champsdata.bkp", sizeof(Campeon));
	Archivo archItembkp("resources/backups/itemsdata.bkp", sizeof(Item));
	Archivo archCabbkp("resources/backups/conjunto_cabecera.bkp", sizeof(Conjunto_cabecera));
	Archivo archDetbkp("resources/backups/conjunto_detalle.bkp", sizeof(Conjunto_detalle));

	champ = new Campeon;
	item = new Item;
	conjcab = new Conjunto_cabecera;
	conjdet = new Conjunto_detalle;

	if (archChampbkp.restoreBackup(*champ, archChamp) == false)return false;
	if (archItembkp.restoreBackup(*item, archItem) == false)return false;
	if (archCabbkp.restoreBackup(*conjcab, archCab) == false)return false;
	if (archDetbkp.restoreBackup(*conjdet, archDet) == false)return false;

	delete(champ);
	delete(item);
	delete(conjcab);
	delete(conjdet);
	return true;
}

SubMenu_Backup::~SubMenu_Backup()
{
	delete _Banner;
	delete _BordeTitulo;
	delete[] _Botones;
	delete _Titulo;
	delete _Mouse;
	delete _BordeVentana;
	delete _Reloj;
}

void SubMenu_Backup::update(sf::RenderWindow& _Ventana)
{
	_Mouse->actualizarPosicion(_Ventana);
	//CMD De cada botoncito
	for (int i = 0; i < 3; i++) _Botones[i].cmd(*_Mouse);
	//UPDATE De cada botoncito
	for (int i = 0; i < 3; i++)	_Botones[i].update();

	if (_Botones[0].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			if (this->Create_Bkp()) {
				std::cout << "Backups creados con exito" << std::endl;
			}
			else {
				std::cout << "Error creando backups" << std::endl;
			}
			_Reloj->restart();
		}
	}
	if (_Botones[1].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			if (this->Restore_Bkp()) {
				std::cout << "Archivos restaurados con exito" << std::endl;
			}
			else {
				std::cout << "Error restaurando archivos" << std::endl;
			}
			_Reloj->restart();
		}
	}

	//Volver
	if (_Botones[2].getButton().getGlobalBounds().intersects(_Mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Principal);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (_Reloj->getElapsedTime().asSeconds() > 0.5)
		{
			Singleton::getInstancia().cambiar_Menu(new SubMenu_Principal);
		}
	}
}

void SubMenu_Backup::dibujarEnVentana(sf::RenderWindow& _Ventana)
{
	_Ventana.clear(sf::Color(14, 22, 33, 255));

	//DRAW
	for (int i = 0; i < 3; i++)
	{
		_Botones[i].dibujarBotoncito(_Ventana);
	}

	_Ventana.draw(_Banner->getHeader());
	_Ventana.draw(*_BordeTitulo);
	_Ventana.draw(*_Titulo);
	_Ventana.draw(*_BordeVentana);
}