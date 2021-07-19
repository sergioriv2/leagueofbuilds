#include "../hpp/outputGUI.h"
#include "../hpp/Singleton.h"
#include "../hpp/Campeones_Opc.h"
#include "../hpp/Items_Opc.h"
#include "../hpp/Conjuntos_Opc.h"

extern sf::Font* _FUENTE;

outputGUI::outputGUI()
{
	idOutput = 0;
	float posYTexto = 127.0f;
	float posYCuadro = 120.0f;

	moreOpc.setRadius(10.0f);
	moreOpc.setFillColor(sf::Color::Black);
	moreOpc.setPointCount(20);

	moreOpcTxt.setFont(*_FUENTE);
	moreOpcTxt.setCharacterSize(15);
	moreOpcTxt.setStyle(sf::Text::Bold);
	moreOpcTxt.setString("...");
	moreOpcTxt.setColor(sf::Color::White);

	cajaOutput.setSize({ 700, 30 });
	cajaOutput.setFillColor(sf::Color(11, 17, 26, 255));
	cajaOutput.setOutlineColor(sf::Color::White);
	cajaOutput.setOutlineThickness(1.0f);
	cajaOutput.setPosition(50.0f, posYCuadro);

	//Texto --------------

	//Fuente
	id.setFont(*_FUENTE);
	nombre.setFont(*_FUENTE);
	ataque.setFont(*_FUENTE);
	velAtaque.setFont(*_FUENTE);
	poderHabilidad.setFont(*_FUENTE);
	regVida.setFont(*_FUENTE);
	vida.setFont(*_FUENTE);
	armor.setFont(*_FUENTE);
	resMagica.setFont(*_FUENTE);
	critChance.setFont(*_FUENTE);
	mana.setFont(*_FUENTE);
	regMana.setFont(*_FUENTE);
	lifeSteal.setFont(*_FUENTE);
	cdr.setFont(*_FUENTE);
	costo.setFont(*_FUENTE);
	dmg.setFont(*_FUENTE);
	estilo.setFont(*_FUENTE);

	//Ch. Size
	id.setCharacterSize(12);
	nombre.setCharacterSize(12);
	ataque.setCharacterSize(12);
	velAtaque.setCharacterSize(12);
	poderHabilidad.setCharacterSize(12);
	vida.setCharacterSize(12);
	regVida.setCharacterSize(12);
	armor.setCharacterSize(12);
	resMagica.setCharacterSize(12);
	critChance.setCharacterSize(12);
	mana.setCharacterSize(12);
	regMana.setCharacterSize(12);
	lifeSteal.setCharacterSize(12);
	cdr.setCharacterSize(12);
	costo.setCharacterSize(12);
	dmg.setCharacterSize(12);
	estilo.setCharacterSize(12);
	//Color
	sf::Color colorDefault(127, 127, 127, 255);
	id.setFillColor(colorDefault);
	nombre.setFillColor(colorDefault);
	ataque.setFillColor(colorDefault);
	velAtaque.setFillColor(colorDefault);
	poderHabilidad.setFillColor(colorDefault);
	regVida.setFillColor(colorDefault);
	vida.setFillColor(colorDefault);
	armor.setFillColor(colorDefault);
	resMagica.setFillColor(colorDefault);
	critChance.setFillColor(colorDefault);
	mana.setFillColor(colorDefault);
	regMana.setFillColor(colorDefault);
	lifeSteal.setFillColor(colorDefault);
	cdr.setFillColor(colorDefault);
	costo.setFillColor(colorDefault);
	dmg.setFillColor(colorDefault);
	estilo.setFillColor(colorDefault);

	//Texto default
	id.setString("NULL");
	nombre.setString("NULL");
	ataque.setString("NULL");
	velAtaque.setString("NULL");
	poderHabilidad.setString("NULL");
	regVida.setString("NULL");
	vida.setString("NULL");
	armor.setString("NULL");
	resMagica.setString("NULL");
	critChance.setString("NULL");
	mana.setString("NULL");
	regMana.setString("NULL");
	lifeSteal.setString("NULL");
	cdr.setString("NULL");
	costo.setString("NULL");
	dmg.setString("NULL");
	estilo.setString("NULL");

	idch.setFont(*_FUENTE);
	idch.setCharacterSize(12);
	idch.setFillColor(colorDefault);
	idch.setString("NULL");
}

outputGUI::outputGUI(int size)
{
	idOutput = 0;
	float posYTexto = 127.0f;
	float posYCuadro = 120.0f;

	moreOpc.setRadius(10.0f);
	moreOpc.setFillColor(sf::Color::Black);
	moreOpc.setPointCount(20);

	moreOpcTxt.setFont(*_FUENTE);
	moreOpcTxt.setCharacterSize(15);
	moreOpcTxt.setStyle(sf::Text::Bold);
	moreOpcTxt.setString("...");
	moreOpcTxt.setColor(sf::Color::White);

	cajaOutput.setSize({ 700, 30 });
	cajaOutput.setFillColor(sf::Color(11, 17, 26, 255));
	cajaOutput.setOutlineColor(sf::Color::White);
	cajaOutput.setOutlineThickness(1.0f);
	cajaOutput.setPosition(50.0f, posYCuadro);

	//Texto --------------

	//*_FUENTE
	id.setFont(*_FUENTE);
	nombre.setFont(*_FUENTE);
	ataque.setFont(*_FUENTE);
	velAtaque.setFont(*_FUENTE);
	vida.setFont(*_FUENTE);
	armor.setFont(*_FUENTE);
	resMagica.setFont(*_FUENTE);
	mana.setFont(*_FUENTE);
	dmg.setFont(*_FUENTE);
	estilo.setFont(*_FUENTE);

	//Ch. Size
	id.setCharacterSize(size);
	nombre.setCharacterSize(size);
	ataque.setCharacterSize(size);
	velAtaque.setCharacterSize(size);
	vida.setCharacterSize(size);
	armor.setCharacterSize(size);
	resMagica.setCharacterSize(size);
	mana.setCharacterSize(size);
	dmg.setCharacterSize(size);
	estilo.setCharacterSize(size);
	;

	//Color
	sf::Color colorDefault(127, 127, 127, 255);

	id.setFillColor(colorDefault);
	nombre.setFillColor(colorDefault);
	ataque.setFillColor(colorDefault);
	velAtaque.setFillColor(colorDefault);
	vida.setFillColor(colorDefault);
	armor.setFillColor(colorDefault);
	resMagica.setFillColor(colorDefault);
	mana.setFillColor(colorDefault);
	dmg.setFillColor(colorDefault);
	estilo.setFillColor(colorDefault);

	//Texto default
	id.setString("NULL");
	nombre.setString("NULL");
	ataque.setString("NULL");
	velAtaque.setString("NULL");
	vida.setString("NULL");
	armor.setString("NULL");
	resMagica.setString("NULL");
	mana.setString("NULL");
	dmg.setString("NULL");
	estilo.setString("NULL");
}

outputGUI::outputGUI(sf::Vector2f tam, bool champ)
{
	idOutput = 0;
	float posYTexto = 127.0f;
	float posYCuadro = 120.0f;

	cajaOutput.setSize(tam);
	cajaOutput.setFillColor(sf::Color(11, 17, 26, 255));
	cajaOutput.setOutlineColor(sf::Color::White);
	cajaOutput.setOutlineThickness(1.0f);
	cajaOutput.setPosition(50.0f, posYCuadro);

	//Texto --------------

	//*_FUENTE
	id.setFont(*_FUENTE);
	nombre.setFont(*_FUENTE);

	//Ch. Size
	id.setCharacterSize(12);
	nombre.setCharacterSize(12);

	//Color
	sf::Color colorDefault(127, 127, 127, 255);

	id.setFillColor(colorDefault);
	nombre.setFillColor(colorDefault);

	//Texto default
	id.setString("NULL");
	nombre.setString("NULL");

}

void outputGUI::drawChConj(sf::RenderWindow* ventana)
{
	ventana->draw(cajaOutput);
	ventana->draw(id);
	ventana->draw(nombre);
}

void outputGUI::cmd(clsMouse& mouse, int& lastI)
{
	if (moreOpc.getGlobalBounds().intersects(mouse.getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			lastI = idOutput;
			cajaOutput.setPosition(50.0f, 120.0f);
			id.setPosition(62.0f, 127.0f);
			nombre.setPosition(95.0f, 127.0f);
			ataque.setPosition(282.0f, 127.0f);
			velAtaque.setPosition(312.0f, 127.0f);
			poderHabilidad.setPosition(342.0f, 127.0f);
			vida.setPosition(375.0f, 127.0f);
			regVida.setPosition(415.0f, 127.0f);
			armor.setPosition(455.0f, 127.0f);
			resMagica.setPosition(495.0f, 127.0f);
			critChance.setPosition(535.0f, 127.0f);
			mana.setPosition(575.0f, 127.0f);
			regMana.setPosition(615.0f, 127.0f);
			lifeSteal.setPosition(643.0f, 127.0f);
			cdr.setPosition(675.0f, 127.0f);
			costo.setPosition(705.0f, 127.0f);
			Singleton::getInstancia().cambiar_Menu(new Items_Opc(*this));
		}
	}
}

void outputGUI::cmdC(clsMouse& mouse, int& lastI)
{
	if (moreOpc.getGlobalBounds().intersects(mouse.getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			lastI = idOutput;
			cajaOutput.setPosition(50.0f, 120.0f);
			id.setPosition(62.0f, 127.0f);
			nombre.setPosition(95.0f, 127.0f);
			ataque.setPosition(222.0f, 127.0f);
			velAtaque.setPosition(287.0f, 127.0f);
			vida.setPosition(352.0f, 127.0f);
			armor.setPosition(417.0f, 127.0f);
			resMagica.setPosition(482.0f, 127.0f);
			mana.setPosition(547.0f, 127.0f);
			dmg.setPosition(610.0f, 127.0f);
			estilo.setPosition(682.0f, 127.0f);
			Singleton::getInstancia().cambiar_Menu(new Campeones_Opc(*this));
		}
	}
}

void outputGUI::cmdConjuntos(clsMouse& mouse, int& lastI) {
	if (moreOpc.getGlobalBounds().intersects(mouse.getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			lastI = idOutput;
			cajaOutput.setPosition(50.0f, 120.0f);
			nombre.setPosition(62.0f, 127.0f);
			id.setPosition(300.0f, 127.0f);
			idch.setPosition(500.0f, 127.0f);
			Singleton::getInstancia().cambiar_Menu(new Conjuntos_Opc(*this));
		}
	}
}

void outputGUI::setPosicion(float y, bool champ, float x)
{
	cajaOutput.setPosition(50.0f + x, y);
	moreOpc.setPosition(755.0f + x, y + 2.0f);
	moreOpcTxt.setPosition(758.0f + x, y - 1.0f);
	y += 7.0f;

	if (champ)
	{
		id.setPosition(62.0f + x, y);
		nombre.setPosition(95.0f + x, y);
		ataque.setPosition(222.0f + x, y);
		velAtaque.setPosition(287.0f + x, y);
		vida.setPosition(352.0f + x, y);
		armor.setPosition(417.0f + x, y);
		resMagica.setPosition(482.0f + x, y);
		mana.setPosition(547.0f + x, y);
		dmg.setPosition(610.0f + x, y);
		estilo.setPosition(682.0f + x, y);
	}
	else
	{
		//Texto --------------

		id.setPosition(62.0f + x, y);
		nombre.setPosition(95.0f + x, y);
		ataque.setPosition(282.0f + x, y);
		velAtaque.setPosition(312.0f + x, y);
		poderHabilidad.setPosition(342.0f + x, y);
		vida.setPosition(375.0f + x, y);
		regVida.setPosition(415.0f + x, y);
		armor.setPosition(455.0f + x, y);
		resMagica.setPosition(495.0f + x, y);
		critChance.setPosition(535.0f + x, y);
		mana.setPosition(575.0f + x, y);
		regMana.setPosition(615.0f + x, y);
		lifeSteal.setPosition(643.0f + x, y);
		cdr.setPosition(675.0f + x, y);
		costo.setPosition(705.0f + x, y);
	}
}
void outputGUI::setPosicionConj(float y) {
	cajaOutput.setSize({ 600, 30 });
	cajaOutput.setPosition(50.0f, y);
	moreOpc.setPosition(655.0f, y + 2.0f);
	moreOpcTxt.setPosition(658.0f, y - 1.0f);
	y += 7.0f;
	nombre.setPosition(62.0f, y);
	id.setPosition(300.0f, y);
	idch.setPosition(500.0f, y);
}