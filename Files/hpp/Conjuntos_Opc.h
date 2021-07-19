#pragma once
#include "../hpp/SubMenu.h"
#include "../hpp/outputGUI.h"

class Conjuntos_Opc :public SubMenu
{
private:
	sf::RectangleShape* _BordeVentana;
	outputGUI* _ConjAux;
	sf::Text* nombconj;
	sf::Text* idconj;
	sf::Text* idchamp;
	clsMouse* _Mouse;
	// DETALLES
	sf::Text* infoEarly;
	sf::Text* infoMid;
	sf::Text* infoLate;
	sf::Text* subtitulos;
	bool _Detalles;
	void inicializarBotones();
public:
	Conjuntos_Opc() {};
	Conjuntos_Opc(outputGUI& _Conj);
	void update(sf::RenderWindow& _Ventana) override;
	void dibujarEnVentana(sf::RenderWindow& _Ventana) override;
	void baja();
	void detalles();
	~Conjuntos_Opc();
};

