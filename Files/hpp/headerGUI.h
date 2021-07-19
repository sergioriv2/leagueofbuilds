#pragma once
#include <SFML/Graphics.hpp>
class headerGUI
{
private:
	sf::RectangleShape header;
	sf::Texture headerTexture;
public:
	headerGUI()
	{
		header.setSize({ 760, 200 });
		header.setPosition({ 20, 20 });
	}
	void setTexture(const char* _tex)
	{
		headerTexture.loadFromFile(_tex);
		headerTexture.setSmooth(true);
		header.setTexture(&headerTexture);
	}
	sf::RectangleShape getHeader() { return header; }
};
