#include "BotonGUI.h"

void BotonGUI::cmd(clsMouse& mouse, sf::RenderWindow& window, EstadoMenu* state, bool* p)
{

	//Animaciones e inputs de los botones
	//Dependiendo que tipo de boton va a mostrar distintos comportamientos
	if (estadoBtn != DESHABILITADO)
	{
		switch (tipoBtn)
		{
		case BTN_DEFAULT:
			break;
		case BTN_CHAMPS:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = MENUCHAMP;
					*p = false;
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
					Sleep(150);
					*state = MENUITEM;
					*p = false;
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
					Sleep(150);
					*state = MENUCONJ;
					*p = false;
				}
			}

		case BTN_MOD_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = MENUMOD_CONJ;
					*p = false;
				}
			}
			break;
		case BTN_DET_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = MENUDET_CONJ;
					*p = false;
				}
			}
				break;
		case BTN_DEL_CONJ:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				//CLIC DEL MOUSE

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = MENUBAJA_CONJ;
					*p = false;
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
					Sleep(150);
					*state = MENUBKP;
					*p = false;
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
					*state = MENUDEV;
					*p = false;
				}
			}
			break;
		case BTN_SALIR:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.close();
				}
			}
			break;
		case BTN_ADD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = MENUALTA_CHAMP;
					*p = false;
				}

			}
			break;
		case BTN_MOD_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = MENUMOD_CHAMP;
					*p = false;
				}
			}

			break;
		case BTN_DEL_CHAMP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						*state = MENUBAJA_CHAMP;
						*p = false;
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
					Sleep(150);
					*state = MENUMOSTRAR_CHAMP;
					*p = false;
				}
			}
			break;
		case BTN_ADD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = MENUALTA_ITEM;
					*p = false;
				}

			}
			break;
		case BTN_MOD_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = MENUMOD_ITEM;
					*p = false;
				}
			}
			break;
		case BTN_DEL_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) *state = MENUBAJA_ITEM;
					*p = false;
				}
			}
			break;
		case BTN_LIST_ITEM:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(150);
					*state = MENUMOSTRAR_ITEM;
					*p = false;
				}
			}
			break;
		case BTN_VOLVER:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Sleep(200);
					//Dependiendo donde está el boton, va a tener distintas acciones
					switch (*state)
					{
					case MENUALTA_ITEM:
						*state = MENUITEM;
						break;
					case MENUMOSTRAR_ITEM:
						*state = MENUITEM;
						break;
					case MENUMASOPCIONES_ITEM:
						*state = MENUMOSTRAR_ITEM;
						break;
					case MENUALTA_CHAMP:
						*state = MENUCHAMP;
						break;
					case MENUMOSTRAR_CHAMP:
						*state = MENUCHAMP;
						break;
					case MENUMASOPCIONES_CHAMP:
						*state = MENUMOSTRAR_CHAMP;
						break;
					case MENUALTA_CONJ:
						*state = MENUCONJ;
						break;
					case MENUMOSTRAR_CONJ:
						*state = MENUCONJ;
						break;
					case MENUMASOPCIONES_CONJ:
						*state = MENUMOSTRAR_CONJ;
						break;
					case MENUDET_CONJ:
						*state = MENUMOSTRAR_CONJ;
						break;
					default: *state = MENUPRINCIPAL;
						break;
					}


			*p = false;
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
					*state = MENUBKP_CREATE;
					*p = false;
				}
			}
			break;
		case BTN_RESTORE_BKP:
			if (mouse.getCircleShape().getGlobalBounds().intersects(this->getButton().getGlobalBounds()))
			{
				estadoBtn = SELECCION;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					*state = MENUBKP_RESTORE;
					*p = false;
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
					*state = MENUALTA_CONJ;
					*p = false;
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
					*state = MENUMOSTRAR_CONJ;
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
	case SELECCION:
		button.setFillColor(sf::Color(22, 26, 29, 255));
		button.setOutlineColor(sf::Color(6, 200, 170, 255));
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

void BotonGUI::setTextoString(const sf::String& string)
{
	texto.setString(string);
}

