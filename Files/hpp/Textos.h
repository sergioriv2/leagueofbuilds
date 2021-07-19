#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include "GUI.h"


enum TextosMenu
{
	PEDIR_NOMBRE,
	PEDIR_ATAQUE,
	PEDIR_VELATAQUE,
	PEDIR_AP,
	PEDIR_VIDA,
	PEDIR_ARMOR,
	PEDIR_MR,
	PEDIR_CRITCHANCE,
	PEDIR_MANA,
	PEDIR_REGMANA,
	PEDIR_REGVIDA,
	PEDIR_CDR,
	PEDIR_LS  //LifeSteal
};


class Textos
{
private:
	sf::Text texto;
	sf::Font fuente;
	std::string stringTexto;
public:
	Textos();
	void setFuente(sf::Font& fuente) { texto.setFont(fuente); }

	void drawText(sf::RenderWindow& window, EstadoMenu stateMenu);
	void setStringTexto(const char* c) { 
		stringTexto = c; 
		texto.setString(stringTexto);
	}
	void setPosicion(float x, float y)
	{
		texto.setPosition(x, y);
	}
	sf::Text getTexto() { return texto; }
	/*
	void guardarRegistro()
	{
		FILE* pf;
		pf = fopen("resources/gui/textos.gui", "ab");
		if (pf == NULL) return;
		fwrite(this, sizeof *this, 1, pf);
		fclose(pf);
	}
	std::string getString() { return stringTexto; }
	void leerRegistro(int pos)
	{
		FILE* pf;
		pf = fopen("resources/gui/textos.gui", "rb");
		if (pf == NULL) return;
		fseek(pf, pos * (sizeof * this), 0);
		fread(this, sizeof * this, 1, pf);
		fclose(pf);
	}
	*/
};

//void inicializarTextos();