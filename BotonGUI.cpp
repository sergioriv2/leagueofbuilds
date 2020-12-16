#include "BotonGUI.h"

void BotonGUI::cmd(clsMouse& mouse, sf::RenderWindow& window, EstadoMenu* state, bool* p)
{

	//Animaciones e inputs de los botones
	//Dependiendo que tipo de boton va a mostrar distintos comportamientos 
	if (estadoBtn != Estado::DESHABILITADO)
	{
		switch (tipoBtn)
		{
		case btnType::BTN_DEFAULT:
			break;
		case btnType::BTN_CHAMPS:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUCHAMP;
					*p = false;
				}
			}
			break;
		case btnType::BTN_ITEMS:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUITEM;
					*p = false;
				}
			}
			break;
		case btnType::BTN_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUCONJ;
					*p = false;
				}
			}

		case btnType::BTN_MOD_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUMOD_CONJ;
					*p = false;
				}
			}
			break;
		case btnType::BTN_DET_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUDET_CONJ;
					*p = false;
				}
			}
				break;
		case btnType::BTN_DEL_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUBAJA_CONJ;
					*p = false;
				}
			}
			break;
		case btnType::BTN_BACKUP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUBKP;
					*p = false;
				}

			}
			break;
		case btnType::BTN_DEVMENU:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUDEV;
					*p = false;
				}
			}
			break;
		case btnType::BTN_SALIR:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.close();
				}
			}
			break;
		case btnType::BTN_ADD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUALTA_CHAMP;
					*p = false;
				}

			}
			break;
		case btnType::BTN_MOD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUMOD_CHAMP;
					*p = false;
				}
			}

			break;
		case btnType::BTN_DEL_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						*state = EstadoMenu::MENUBAJA_CHAMP;
						*p = false;
					}
				}
			}
			break;
		case btnType::BTN_LIST_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUMOSTRAR_CHAMP;
					*p = false;
				}
			}
			break;
		case btnType::BTN_ADD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = EstadoMenu::MENUALTA_ITEM;
					*p = false;
				}

			}
			break;
		case btnType::BTN_MOD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = EstadoMenu::MENUMOD_ITEM;
					*p = false;
				}
			}
			break;
		case btnType::BTN_DEL_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = EstadoMenu::MENUBAJA_ITEM;
					*p = false;
				}
			}
			break;
		case btnType::BTN_LIST_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = EstadoMenu::MENUMOSTRAR_ITEM;
					*p = false;
				}
			}
			break;
		case btnType::BTN_VOLVER:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(200);
					//Dependiendo donde está el boton, va a tener distintas acciones
					switch (*state)
					{
					case EstadoMenu::MENUALTA_ITEM:
						*state = EstadoMenu::MENUITEM;
						break;
					case EstadoMenu::MENUMOSTRAR_ITEM:
						*state = EstadoMenu::MENUITEM;
						break;
					case EstadoMenu::MENUMASOPCIONES_ITEM:
						*state = EstadoMenu::MENUMOSTRAR_ITEM;
						break;
					case EstadoMenu::MENUALTA_CHAMP:
						*state = EstadoMenu::MENUCHAMP;
						break;
					case EstadoMenu::MENUMOSTRAR_CHAMP:
						*state = EstadoMenu::MENUCHAMP;
						break;
					case EstadoMenu::MENUMASOPCIONES_CHAMP:
						*state = EstadoMenu::MENUMOSTRAR_CHAMP;
						break;
					case EstadoMenu::MENUALTA_CONJ:
						*state = EstadoMenu::MENUCONJ;
						break;
					case EstadoMenu::MENUMOSTRAR_CONJ:
						*state = EstadoMenu::MENUCONJ;
						break;
					case EstadoMenu::MENUMASOPCIONES_CONJ:
						*state = EstadoMenu::MENUMOSTRAR_CONJ;
						break;
					case EstadoMenu::MENUDET_CONJ:
						*state = EstadoMenu::MENUMOSTRAR_CONJ;
						break;
					default: *state = EstadoMenu::MENUPRINCIPAL;
						break;
					}
		

			*p = false;
				}

			}
			break;
		case btnType::BTN_GUARDAR:

			break;
		case btnType::BTN_CREATE_BKP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUBKP_CREATE;
					*p = false;
				}
			}
			break;
		case btnType::BTN_RESTORE_BKP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUBKP_RESTORE;
					*p = false;
				}
			}
			break;
		case btnType::BTN_ADD_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUALTA_CONJ;
					*p = false;
				}
			}
			break;
		case btnType::BTN_LIST_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = Estado::SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = EstadoMenu::MENUMOSTRAR_CONJ;
					*p = false;
				}
			}
			break;

		default:
			break;
		}
	}


}

void BotonGUI::update(sf::RenderWindow& window)
{
	switch (estadoBtn)
	{
	case Estado::SELECCION:
		button.setFillColor(sf::Color(22, 26, 29, 255));
		button.setOutlineColor(sf::Color(6, 200, 170, 255));
		estadoBtn = Estado::NINGUNO;
		break;
	case Estado::NINGUNO:
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setOutlineColor(sf::Color(6, 150, 170, 255));
		break;
	case Estado::DESHABILITADO:
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setOutlineColor(sf::Color(127, 127, 127, 255));
		break;
	}
}

void BotonGUI::setTextoString(const sf::String& string)
{
	texto.setString(string);
}

