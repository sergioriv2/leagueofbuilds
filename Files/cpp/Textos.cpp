#include <iostream>
#include "Textos.h"


/*void borrarArchivoAnterior()
{
	Textos t;
	FILE* pf;
	pf = fopen("resources/gui/textos.gui", "wb");
	if (pf == NULL) return;
	fwrite(&t, sizeof t, 1, pf);
	fclose(pf);
}


void inicializarTextos()
{
	sf::Font* fuente;
	fuente = new sf::Font;
	fuente->loadFromFile("arial.ttf");

	borrarArchivoAnterior();
	//Por ahora solo hay 13 cargados
	const int tam = 13;
	Textos txt[tam];

	for (int i = 0; i < tam; i++)
	{
		switch (i)
		{
		case 0:
			txt[i].setStringTexto("Ingresar nombre de campeon:");
			txt[i].getTexto().setPosition({ 0,0 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();

			break;
		case 1:
			txt[i].setStringTexto("Ingresar ataque:");
			txt[i].getTexto().setPosition({ 0,40 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 2:
			txt[i].setStringTexto("Ingresar velocidad de ataque:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 3:
			txt[i].setStringTexto("Ingresar poder de habilidad:");
			txt[i].getTexto().setPosition({ 0,0 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 4:
			txt[i].setStringTexto("Ingresar vida:");
			txt[i].getTexto().setPosition({ 0,40 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 5:
			txt[i].setStringTexto("Ingresar armadura:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 6:
			txt[i].setStringTexto("Ingresar resistencia magica:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 7:
			txt[i].setStringTexto("Ingresar porc. critico:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 8:
			txt[i].setStringTexto("Ingresar mana:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 9:
			txt[i].setStringTexto("Ingresar reg. mana:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 10:
			txt[i].setStringTexto("Ingresar reg. vida:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 11:
			txt[i].setStringTexto("Ingresar cdr:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;
		case 12:
			txt[i].setStringTexto("Ingresar robo de vida:");
			txt[i].getTexto().setPosition({ 0,80 });
			txt[i].setFuente(*fuente);
			txt[i].guardarRegistro();
			break;

		}
	}
	delete fuente;
	
}
*/
Textos::Textos()
{
	texto.setFillColor(sf::Color::White);
	texto.setCharacterSize(20);
}

/*void Textos::drawText(sf::RenderWindow& window, EstadoMenu stateMenu)
{
	Textos aux;
	switch (stateMenu)
	{
	case MENUALTA_CHAMP:
		for (int i = 0; i < 3; i++)
		{
			aux.leerRegistro(i);
			std::cout << aux.getString();
			//window.draw(aux.getTexto());
		}
		break;
	}
}*/
