#pragma once

enum Estado
{
	NINGUNO,
	CAMBIO_COLOR,
	ANIMACION
};

enum btnType
{
	DEFAULT,
	CHAMPS,
	ITEMS,
	CONJ,
	BACKUP,
	SALIR,
	ADD_CHAMP,
	MOD_CHAMP,
	DEL_CHAMP,
	LIST_CHAMP,
	ADD_ITEM,
	MOD_ITEM,
	DEL_ITEM,
	LIST_ITEM,
};

class BotonGUI
{
private:
	sf::RectangleShape button;
	sf::Vector2i cordBtn;
	Estado estadoBtn;
	btnType tipoBtn;
	sf::Font fuente;
	sf::Text texto;
public:

	///////////////////
	//CONSTRUCTORES
	////////////////////
	BotonGUI()
	{

		//Pongo todo lo que tenga que ver con texto
		if (fuente.loadFromFile("resources/fuentes/Roboto-Medium.ttf") == 0) return; // SI PASA ESTO, CAMBIA EL PROYECTO DE DEBUG A RELEASE
		texto.setFont(fuente);
		texto.setFillColor(sf::Color::White);
		texto.setCharacterSize(20);

		//Luego todo lo demas con la posicion y color del rectangulo que seria el boton
		tipoBtn = DEFAULT;
		estadoBtn = NINGUNO;
		button.setFillColor(sf::Color(30, 35, 40, 255));
		button.setSize(sf::Vector2f(200.0f, 50.0f));
		button.setOutlineThickness(2.0f);
		button.setOutlineColor(sf::Color(6, 150, 170, 255));
		button.setPosition(0, 0);
		cordBtn.x = 0;
		cordBtn.y = 0;
	}

	///////////////////
	//METODOS
	////////////////////

	void cmd(sf::RenderWindow &window);
	void update();

	///////////////////
	//SETS
	////////////////////



	void setPosY(float _y)
	{ 
		cordBtn.y = (int)_y;
		button.setPosition(0, (float)cordBtn.y); 
	}
	void setTextoString(const sf::String& string);
	void setBtnType(btnType _btn) { tipoBtn = _btn; }

	///////////////////
	//GETS
	////////////////////

	sf::Text getText() { return texto; }
	sf::Vector2i getVector2i() { return cordBtn; }
	sf::RectangleShape getButton() { return button; }
};

