#pragma once

#include <SFML/Graphics.hpp>

class clsMouse
{
private:
	sf::CircleShape mouse;
	sf::Vector2f posMouse;
public:
	clsMouse() 
	{
		mouse.setFillColor(sf::Color(39, 46, 52, 255));
		mouse.setRadius(5.0f);
	};
	void actualizarPosicion(sf::RenderWindow &ventana)
	{
		posMouse.x = static_cast<float>(sf::Mouse::getPosition(ventana).x);
		posMouse.y = static_cast<float>(sf::Mouse::getPosition(ventana).y);

		mouse.setPosition(posMouse.x, posMouse.y);
	}
	sf::CircleShape getCircleShape() { return mouse; }
};

