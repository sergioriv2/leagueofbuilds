#include "../hpp/Singleton.h"

Singleton::Singleton(){}
Singleton* Singleton::instancia = nullptr;

void Singleton::processEvents()
{
}

void Singleton::update()
{
    actual->update(_window);
    clock.restart();
}

void Singleton::draw()
{
    _window.clear();
    actual->dibujarEnVentana(_window);
    _window.display();
}

void Singleton::close()
{
    _window.close();
}

void Singleton::run()
{
    //GAME LOOP
    while (_window.isOpen() && actual != nullptr) {
        sf::Event e;
        while (_window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                _window.close();
            }
            else if (e.type == sf::Event::TextEntered) {
                actual->process_event(e);
            }
        }

        //ACTUALIZAR
        update();

        //DIBUJAR
        draw();

        //controlo si es la ultima escena
        if (siguiente != nullptr) {

            actual->~SubMenu();
            delete actual;

            actual = siguiente;
            siguiente = nullptr;
        }
    }
}

void Singleton::cambiar_Menu(SubMenu* menu)
{
    siguiente = menu;
}

Singleton& Singleton::getInstancia()
{
    if (!instancia) {
        instancia = new Singleton;
    }

    return *instancia;
}

Singleton& Singleton::create(const sf::VideoMode& videoMode, SubMenu* menu, const std::string& nombre)
{
    if (instancia) {
    }
    else
    {
        Singleton& g = getInstancia();
        g._window.create(videoMode, "League Of Builds", sf::Style::Close);
        g.actual = menu;
        g.siguiente = nullptr;
        g._window.setFramerateLimit(60);
        g.clock.restart();
        g._window.setMouseCursorVisible(true);
        // Cortesia de facu
    }
    return getInstancia();

}
