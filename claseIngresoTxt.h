#pragma once
#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox
{
private:
	sf::Text textbox;
	std::ostringstream texto;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped) {
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
		{
			texto << static_cast<char>(charTyped);
		}
		else 
		{
			if (charTyped == DELETE_KEY)
			{
				if (texto.str().length() > 0)
				{
					borrarultimoChar();
				}
			}
		}
		textbox.setString(texto.str() + "_");
	}
	void borrarultimoChar()
	{
		std::string t = texto.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		texto.str("");
		texto << newT;

		textbox.setString(texto.str());
	}

public:
	TextBox()
	{
		limit = 30;
		textbox.setCharacterSize(12);
		textbox.setFillColor(sf::Color(127,127,127,255));
		textbox.setString("_");
	}
	TextBox(int size, sf::Color Color, bool sel)
	{
		limit = 30;
		textbox.setCharacterSize(size);
		textbox.setFillColor(Color);
		isSelected = sel;
		if (sel)
		{
			textbox.setString("_");
		}
		else
		{
			textbox.setString("");
		}
	}
	void setTexto(std::string texto) { 
		sf::String aux = texto;
		textbox.setString(aux); 
	}
	void setFuente(sf::Font &fuente) { textbox.setFont(fuente); }
	void setPosition(sf::Vector2f pos) {textbox.setPosition(pos); }
	void setLimit(bool ToF) { hasLimit = ToF; }
	void setLimit(bool ToF, int lim)
	{
		hasLimit = ToF;
		limit = lim -1;
	}
	void setSelected(bool sel)
	{
		isSelected = sel;
		if (!sel)
		{
			std::string t = texto.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++)
			{
				newT += t[i];
			}
			textbox.setString(newT);

		}
		else
		{
			textbox.setString(texto.str() + "_");
		}
	}
	std::string getText() { return texto.str(); }

	void drawTo(sf::RenderWindow& window) { window.draw(textbox); }
	void typedOn(sf::Event* input)
	{
		if (isSelected)
		{
			int charTyped = input->text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (texto.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (texto.str().length() > limit && charTyped == DELETE_KEY) borrarultimoChar();
				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
};