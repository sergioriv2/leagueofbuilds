#include "iconosListado.h"

iconosListado::iconosListado()
{
	textura.loadFromFile("resources/gui/stats.png");
	textura.setSmooth(true);

	//Texto ---------
	id.setCharacterSize(12);
	costo.setCharacterSize(12);
	nombre.setCharacterSize(12);

	dmg.setCharacterSize(12);
	estilo.setCharacterSize(12);

	id.setFillColor(sf::Color::White);
	costo.setFillColor(sf::Color::White);
	nombre.setFillColor(sf::Color::White);
	dmg.setFillColor(sf::Color::White);
	estilo.setFillColor(sf::Color::White);

	id.setString("ID");
	costo.setString("COSTO");
	nombre.setString("NOMBRE");
	dmg.setString("TIPO DE DMG");
	estilo.setString("ESTILO");

	id.setPosition(62.0f, 90.0f);
	nombre.setPosition(95.0f, 90.0f);
	costo.setPosition(692.0f, 90.0f);
	dmg.setPosition(0.0f, 90.0f);
	estilo.setPosition(0.0f, 90.0f);
	
	//Iconos -------

	ataque.setTexture(textura);
	mana.setTexture(textura);
	regMana.setTexture(textura);
	ap.setTexture(textura);
	cdr.setTexture(textura);
	robodevida.setTexture(textura);
	velocidadAtaque.setTexture(textura);
	vida.setTexture(textura);
	regVida.setTexture(textura);
	resMagica.setTexture(textura);
	armadura.setTexture(textura);
	critico.setTexture(textura);

	ataque.setScale(0.5f, 0.5f);
	mana.setScale(0.5f, 0.5f);
	regMana.setScale(0.5f, 0.5f);
	ap.setScale(0.5f, 0.5f);
	cdr.setScale(0.5f, 0.5f);
	robodevida.setScale(0.5f, 0.5f);
	velocidadAtaque.setScale(0.5f, 0.5f);
	vida.setScale(0.5f, 0.5f);
	regVida.setScale(0.5f, 0.5f);
	resMagica.setScale(0.5f, 0.5f);
	armadura.setScale(0.5f, 0.5f);
	critico.setScale(0.5f, 0.5f);

	ataque.setTextureRect(sf::IntRect(40 * 0, 40 * 0, 40, 40));
	mana.setTextureRect(sf::IntRect(40 * 1, 40 * 0, 40, 40));
	regMana.setTextureRect(sf::IntRect(40 * 2, 40 * 0, 40, 40));
	ap.setTextureRect(sf::IntRect(40 * 3, 40 * 0, 40, 40));
	cdr.setTextureRect(sf::IntRect(40 * 4, 40 * 0, 40, 40));
	robodevida.setTextureRect(sf::IntRect(40 * 5, 40 * 0, 40, 40));
	velocidadAtaque.setTextureRect(sf::IntRect(40 * 0, 40 * 1, 40, 40));
	vida.setTextureRect(sf::IntRect(40 * 1, 40 * 1, 40, 40));
	regVida.setTextureRect(sf::IntRect(40 * 2, 40 * 1, 40, 40));
	resMagica.setTextureRect(sf::IntRect(40 * 3, 40 * 1, 40, 40));
	armadura.setTextureRect(sf::IntRect(40 * 4, 40 * 1, 40, 40));
	critico.setTextureRect(sf::IntRect(40 * 5, 40 * 1, 40, 40));

}

void iconosListado::setPosY(float posY)
{
	

	ataque.setPosition(275.0f, posY);
	velocidadAtaque.setPosition(302.0f, posY);
	ap.setPosition(342.0f, posY);
	vida.setPosition(372.0f, posY);
	regVida.setPosition(412.0f, posY);
	armadura.setPosition(452.0f, posY);
	resMagica.setPosition(492.0f, posY);
	critico.setPosition(532.0f, posY);
	mana.setPosition(572.0f, posY);
	regMana.setPosition(612.0f, posY);
	robodevida.setPosition(643.0f, posY);
	cdr.setPosition(672.0f, posY);

	id.setPosition(62.0f, posY + 4.0f);
	nombre.setPosition(95.0f, posY + 4.0f);
	costo.setPosition(702.0f, posY + 4.0f);
}

void iconosListado::dibujarIconos(sf::RenderWindow* ventana)
{
	ventana->draw(ataque);
	ventana->draw(mana);
	ventana->draw(regMana);
	ventana->draw(ap);
	ventana->draw(cdr);
	ventana->draw(robodevida);
	ventana->draw(velocidadAtaque);
	ventana->draw(vida);
	ventana->draw(regVida);
	ventana->draw(resMagica);
	ventana->draw(armadura);
	ventana->draw(critico);

	ventana->draw(id);
	ventana->draw(nombre);
	ventana->draw(costo);
}

void iconosListado::dibujarIconosC(sf::RenderWindow* ventana)
{
	ventana->draw(ataque);
	ventana->draw(mana);
	ventana->draw(velocidadAtaque);
	ventana->draw(vida);
	ventana->draw(resMagica);
	ventana->draw(armadura);

	ventana->draw(id);
	ventana->draw(nombre);
	ventana->draw(dmg);
	ventana->draw(estilo);
}