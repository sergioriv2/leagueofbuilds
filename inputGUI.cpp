#include "inputGUI.h"

inputGUI::inputGUI(sf::Font* fuente, float posY)
{
	cajaInput.setSize({ 160, 30 });
	cajaInput.setFillColor(sf::Color(11, 17, 26, 255));
	cajaInput.setOutlineColor(sf::Color(6, 150, 170, 255));
	cajaInput.setOutlineThickness(1.0f);
	cajaInput.setPosition(55, posY + offset);

	subtitulo.setPosition(55, posY);
	subtitulo.setCharacterSize(12);
	subtitulo.setFillColor(sf::Color::White);
	subtitulo.setString("NULL");
	subtitulo.setFont(*fuente);

	ingreso.setFuente(*fuente);
	ingreso.setSelected(false);
}

void inputGUI::setLimiteIngreso(int lim)
{
	ingreso.setLimit(true, lim);
}

void inputGUI::setColor(sf::Color colorcito)
{
	cajaInput.setOutlineColor(colorcito);
}

void inputGUI::callEventoIngreso(sf::Event evento)
{
	ingreso.typedOn(&evento);
}

void inputGUI::comandoInput(clsMouse *mouse, int* lastingreso)
{
	if (*lastingreso != id) ingreso.setSelected(false);

	if (cajaInput.getGlobalBounds().intersects(mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ingreso.setSelected(true);
			*lastingreso = id;
		}
		
	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) *lastingreso = NULL;


	
}


