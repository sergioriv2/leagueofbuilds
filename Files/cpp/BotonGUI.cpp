#include "../hpp/BotonGUI.h"
#include "../hpp/Singleton.h"

#include "../hpp/SubMenu_Campeones.h"
#include "../hpp/Campeones_Listado.h"

#include "../hpp/SubMenu_Items.h"
#include "../hpp/Campeones_Alta.h"
#include "../hpp/Items_Alta.h"
#include "../hpp/Items_Listado.h"

#include "../hpp/SubMenu_Conjuntos.h"
#include "../hpp/Conjuntos_Alta.h"
#include "../hpp/Conjuntos_Listado.h"

#include "../hpp/SubMenu_Backup.h"

#include "../hpp/devmenu.h"

BotonGUI::BotonGUI()
{
	tipoBtn = btnType::BTN_DEFAULT;
	estadoBtn = Estado::NINGUNO;

	texto.setFont(*_FUENTE);
	texto.setFillColor(sf::Color::White);
	texto.setCharacterSize(18);

	//Luego todo lo demas con la posicion y color del rectangulo que seria el boton

	button.setFillColor(sf::Color(30, 35, 40, 255));
	button.setSize(sf::Vector2f(180.0f, 50.0f));
	button.setOutlineThickness(2.0f);
	button.setOutlineColor(sf::Color(6, 150, 170, 255));
	button.setPosition(0, 0);
	cordBtn.x = 0;
	cordBtn.y = 0;
	_Reloj.restart();


	//Sound
	if (!buffer.loadFromFile("./resources/Button-SFX.wav")) {
		std::cout << "Error cargando efecto de sonido." << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(25);


	//sound.play(); Cada vez que se necesite usar el sonido
}

//sound.play(); Cada vez que se necesite usar el sonido

void BotonGUI::cmd(clsMouse & mouse)
{
	//Animaciones e inputs de los botones
	//Dependiendo que tipo de boton va a mostrar distintos comportamientos
	if (estadoBtn != DESHABILITADO)
	{
		switch (tipoBtn)
		{
		case BTN_DEFAULT:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
			}
			break;
		case BTN_CHAMPS:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
			
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Campeones);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_ITEMS:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Items);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Conjuntos);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_MOD_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE
			}
			break;
		case BTN_DET_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE
			}
			break;
		case BTN_DEL_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE
				if (_Reloj.getElapsedTime().asSeconds() > 0.5)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Conjuntos);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_BACKUP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Singleton::getInstancia().cambiar_Menu(new SubMenu_Backup);
					_Reloj.restart();
				}
			}
			break;
		case BTN_DEVMENU:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Menu_Desarrollador* devmenu;
					devmenu = new Menu_Desarrollador;

					system("cls");
					if (devmenu->menuPrincipal() == 0)delete devmenu;
				}
			}
			break;
		case BTN_SALIR:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Singleton::getInstancia().close();
				}
			}
			break;
		case BTN_ADD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Campeones_Alta);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_MOD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
			}

			break;
		case BTN_DEL_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (_Reloj.getElapsedTime().asSeconds() > 0.5)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Campeones);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_LIST_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Campeones_Listado);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_ADD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Items_Alta);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_MOD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

			}
			break;
		case BTN_DEL_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (_Reloj.getElapsedTime().asSeconds() > 0.5)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Singleton::getInstancia().cambiar_Menu(new SubMenu_Items);
						_Reloj.restart();
					}
				}
			}
			break;
		case BTN_LIST_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Items_Listado);
						_Reloj.restart();
					}

				}
			}
			break;
		case BTN_VOLVER:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

				}
			}
			break;
		case BTN_GUARDAR:

			break;
		case BTN_CREATE_BKP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

				}
			}
			break;
		case BTN_RESTORE_BKP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

				}
			}
			break;
		case BTN_ADD_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Conjuntos_Alta);
						_Reloj.restart();
					}

				}
			}
			break;
		case BTN_LIST_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (_Reloj.getElapsedTime().asSeconds() > 0.5)
					{
						Singleton::getInstancia().cambiar_Menu(new Conjuntos_Listado);
						_Reloj.restart();
					}

				}
			}
			break;
		break;
		default:
			break;
		}
	}
}

void BotonGUI::update()
{
	switch (estadoBtn)
	{
	case SELECCION:
		button.setFillColor(sf::Color(22, 26, 29, 255));
		button.setOutlineColor(sf::Color(6, 200, 170, 255));
		sound.play();
		estadoBtn = NINGUNO;
		break;
	case NINGUNO:
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setOutlineColor(sf::Color(6, 150, 170, 255));
		break;
	case DESHABILITADO:
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setOutlineColor(sf::Color(127, 127, 127, 255));
		break;
	}
}

void BotonGUI::setTextoString(const sf::String & string)
{
	texto.setString(string);
}

BotonGUI::~BotonGUI()
{

}
