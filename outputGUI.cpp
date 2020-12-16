#include "outputGUI.h"

outputGUI::outputGUI(sf::Font* fuente)
{
	idOutput = 0;
	float posYTexto = 127.0f;
	float posYCuadro = 120.0f;

	moreOpc.setRadius(10.0f);
	moreOpc.setFillColor(sf::Color::Black);
	moreOpc.setPointCount(20);

	moreOpcTxt.setFont(*fuente);
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
	id.setFont(*fuente);
	nombre.setFont(*fuente);
	ataque.setFont(*fuente);
	velAtaque.setFont(*fuente);
	poderHabilidad.setFont(*fuente);
	regVida.setFont(*fuente);
	vida.setFont(*fuente);
	armor.setFont(*fuente);
	resMagica.setFont(*fuente);
	critChance.setFont(*fuente);
	mana.setFont(*fuente);
	regMana.setFont(*fuente);
	lifeSteal.setFont(*fuente);
	cdr.setFont(*fuente);
	costo.setFont(*fuente);
	dmg.setFont(*fuente);
	estilo.setFont(*fuente);

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


	idch.setFont(*fuente);
	idch.setCharacterSize(12);
	idch.setFillColor(colorDefault);
	idch.setString("NULL");

}

outputGUI::outputGUI(sf::Font* fuente, int size)
{
	idOutput = 0;
	float posYTexto = 127.0f;
	float posYCuadro = 120.0f;

	moreOpc.setRadius(10.0f);
	moreOpc.setFillColor(sf::Color::Black);
	moreOpc.setPointCount(20);

	moreOpcTxt.setFont(*fuente);
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
	id.setFont(*fuente);
	nombre.setFont(*fuente);
	ataque.setFont(*fuente);
	velAtaque.setFont(*fuente);
	vida.setFont(*fuente);
	armor.setFont(*fuente);
	resMagica.setFont(*fuente);
	mana.setFont(*fuente);
	dmg.setFont(*fuente);
	estilo.setFont(*fuente);

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


void outputGUI::cmd(clsMouse *mouse, bool* p ,EstadoMenu* state ,int* lastI)
{
	if (moreOpc.getGlobalBounds().intersects(mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*lastI = idOutput;

			cajaOutput.setPosition(50.0f, 120.0f);
			id.setPosition(62.0f, 127.0f);
			nombre.setPosition(95.0f, 127.0f);
			ataque.setPosition(282.0f, 127.0f);
			velAtaque.setPosition(312.0f, 127.0f);
			poderHabilidad.setPosition(342.0f, 127.0f);
			vida.setPosition(375.0f, 127.0f);
			regVida.setPosition(412.0f, 127.0f);
			armor.setPosition(452.0f, 127.0f);
			resMagica.setPosition(495.0f, 127.0f);
			critChance.setPosition(535.0f, 127.0f);
			mana.setPosition(575.0f, 127.0f);
			regMana.setPosition(615.0f, 127.0f);
			lifeSteal.setPosition(643.0f, 127.0f);
			cdr.setPosition(675.0f, 127.0f);
			costo.setPosition(702.0f, 127.0f);
			*state = EstadoMenu::MENUMASOPCIONES_ITEM;
			*p = false;

		}
	}
}

void outputGUI::cmdC(clsMouse* mouse, bool* p, EstadoMenu* state, int* lastI)
{
	if (moreOpc.getGlobalBounds().intersects(mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			
			*lastI = idOutput;
			cajaOutput.setPosition(50.0f, 120.0f);
			id.setPosition(62.0f, 127.0f);
			nombre.setPosition(95.0f, 127.0f);
			ataque.setPosition(222.0f, 127.0f);
			velAtaque.setPosition(287.0f, 127.0f);
			vida.setPosition(352.0f, 127.0f);
			armor.setPosition(417.0f, 127.0f);
			resMagica.setPosition(482.0f, 127.0f);
			mana.setPosition(547.0f, 127.0f);
			dmg.setPosition(597.0f, 127.0f);
			estilo.setPosition(692.0f, 127.0f);
			*state = EstadoMenu::MENUMASOPCIONES_CHAMP;
			*p = false;

		}
	}
}

void outputGUI::cmdConjuntos(clsMouse* mouse, bool* p, EstadoMenu* state, int* lastI) {

	if (moreOpc.getGlobalBounds().intersects(mouse->getCircleShape().getGlobalBounds()))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			*lastI = idOutput;
			cajaOutput.setPosition(50.0f, 120.0f);
			nombre.setPosition(62.0f, 127.0f);
			id.setPosition(300.0f, 127.0f);
			idch.setPosition(500.0f, 127.0f);

			*state = EstadoMenu::MENUMASOPCIONES_CONJ;
			*p = false;

		}
	}
}

void outputGUI::setPosicion(float y, bool champ)
{
	cajaOutput.setPosition(50.0f, y);
	moreOpc.setPosition(755.0f, y + 2.0f);
	moreOpcTxt.setPosition(758.0f, y - 1.0f);
	y += 7.0f;

	if (champ)
	{
		id.setPosition(62.0f, y);
		nombre.setPosition(95.0f, y);
		ataque.setPosition(222.0f, y);
		velAtaque.setPosition(287.0f, y);
		vida.setPosition(352.0f, y);
		armor.setPosition(417.0f, y);
		resMagica.setPosition(482.0f, y);
		mana.setPosition(547.0f, y);
		dmg.setPosition(610.0f, y);
		estilo.setPosition(682.0f, y);
	}
	else
	{
		//Texto --------------

		id.setPosition(62.0f, y);
		nombre.setPosition(95.0f, y);
		ataque.setPosition(282.0f, y);
		velAtaque.setPosition(312.0f, y);
		poderHabilidad.setPosition(342.0f, y);
		vida.setPosition(375.0f, y);
		regVida.setPosition(412.0f, y);
		armor.setPosition(452.0f, y);
		resMagica.setPosition(495.0f, y);
		critChance.setPosition(535.0f, y);
		mana.setPosition(575.0f, y);
		regMana.setPosition(615.0f, y);
		lifeSteal.setPosition(643.0f, y);
		cdr.setPosition(675.0f, y);
		costo.setPosition(702.0f, y);
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
