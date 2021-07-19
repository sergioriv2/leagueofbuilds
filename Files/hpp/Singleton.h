#pragma once
#include <SFML/Graphics.hpp>
#include "../hpp/SubMenu.h"
class Singleton
{
private:
	sf::RenderWindow _window;
	SubMenu *actual;
	SubMenu* siguiente;
	sf::Clock clock;

	void processEvents();
	void update();
	void draw();

	static Singleton* instancia;
	Singleton();

public:
	void close();
	//bucle de juego
	void run();
	///cambiar escena
	void cambiar_Menu(SubMenu* menu);
	// intancia de juego (diseño singleton)
	static Singleton& getInstancia();
	// Juego, ventana, escena inicial
	static Singleton& create(const sf::VideoMode& videoMode, SubMenu* menu, const std::string& nombre = "");

};

