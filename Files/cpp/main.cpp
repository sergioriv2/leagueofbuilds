#pragma warning(disable : 4996)

#include <SFML/Graphics.hpp>
#include "../hpp/../hpp/Singleton.h"
#include "../hpp/../hpp/SubMenu_Principal.h"

using namespace std;

#include "../hpp/../hpp/devmenu.h"

sf::Font* _FUENTE;

void cargarFuente()
{
    _FUENTE = new sf::Font;
    _FUENTE->loadFromFile("./resources/fuentes/Roboto-Medium.ttf");
}


int main()
{
    cargarFuente();

    SubMenu_Principal* _menu = new SubMenu_Principal();

    //pantalla y escena
    Singleton& _sg = Singleton::create(sf::VideoMode(800, 600), _menu, "League of Builds");

    //empieza la cola de eventos
    _sg.run();

	return 0;
}