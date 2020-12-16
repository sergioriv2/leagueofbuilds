#pragma once
#include <SFML/Graphics.hpp>
class iconosListado
{
private:
	sf::Texture textura;
	sf::Sprite ataque;
	sf::Sprite mana;
	sf::Sprite regMana;
	sf::Sprite ap;
	sf::Sprite cdr;
	sf::Sprite robodevida;
	sf::Sprite velocidadAtaque;
	sf::Sprite vida;
	sf::Sprite regVida;
	sf::Sprite resMagica;
	sf::Sprite armadura;
	sf::Sprite critico;

	sf::Text id;
	sf::Text nombre;
	sf::Text costo;
	sf::Text dmg;
	sf::Text estilo;

public:
	iconosListado();

	void setposxId(float x) { id.setPosition(x, 90.0f); }
	void setposxNombre(float x) { nombre.setPosition(x, 90.0f); }
	void setposxAtaque(float x) { ataque.setPosition(x, 90.0f); }
	void setposxvelAtaque(float x) { velocidadAtaque.setPosition(x, 90.0f); }
	void setposxpoderHabilidad(float x) { ap.setPosition(x, 90.0f); }
	void setposxtregVida(float x) { regVida.setPosition(x, 90.0f); }
	void setposxVida(float x) { vida.setPosition(x, 90.0f); }
	void setposxArmor(float x) { armadura.setPosition(x, 90.0f); }
	void setposxresMagica(float x) { resMagica.setPosition(x, 90.0f); }
	void setposxcritChance(float x) { critico.setPosition(x, 90.0f); }
	void setposxMana(float x) { mana.setPosition(x, 90.0f); }
	void setposxregMana(float x) { regMana.setPosition(x, 90.0f); }
	void setposxlifeSteal(float x) { robodevida.setPosition(x, 90.0f); }
	void setposxCdr(float x) { cdr.setPosition(x, 90.0f); }
	void setposxCosto(float x) { costo.setPosition(x, 90.0f); }
	void setposxDmg(float x) { dmg.setPosition(x, 90.0f); }
	void setposxEstilo(float x) { estilo.setPosition(x, 90.0f); }

	sf::Text getid() { return id; }
	sf::Text getnombre() { return nombre; }
	sf::Text getcosto() { return costo; }
	sf::Text getdmg() { return dmg; }
	sf::Text getestilo() { return estilo; }

	void setFuente(sf::Font* fuente)
	{

		id.setFont(*fuente);
		costo.setFont(*fuente);
		nombre.setFont(*fuente);
		dmg.setFont(*fuente);
		estilo.setFont(*fuente);

	}
	void setPosY(float posY);
	void dibujarIconos(sf::RenderWindow* ventana);
	void dibujarIconosC(sf::RenderWindow* ventana);
};

