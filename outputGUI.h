#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "claseIngresoTxt.h"
#include "clsMouse.h"
#include "Item.h"
#include "Campeon.h"
#include "clsMouse.h"
#include "enums.h"
#include <Windows.h>
#include "Archivo.h"
#include "Conjunto_cabecera.h"
#include "Conjunto_detalle.h"

class outputGUI
{
private:
	sf::RectangleShape cajaOutput;
	sf::CircleShape moreOpc;
	sf::Text moreOpcTxt;
	sf::Text id;
	sf::Text nombre;
	sf::Text ataque;
	sf::Text velAtaque;
	sf::Text poderHabilidad;
	sf::Text vida;
	sf::Text regVida;
	sf::Text armor;
	sf::Text resMagica;
	sf::Text critChance;
	sf::Text mana;
	sf::Text regMana;
	sf::Text lifeSteal;
	sf::Text cdr;
	sf::Text costo;

	sf::Text dmg;
	sf::Text estilo;

	sf::Text idch;

	int idOutput;
public:
	outputGUI() {};
	outputGUI(sf::Font* fuente);
	outputGUI(sf::Font* fuente, int size);

	sf::Text getId() { return id; }
	sf::Text getNombre() { return nombre; }
	sf::Text getAtaque() { return ataque; }
	sf::Text getvelAtaque() { return velAtaque; }
	sf::Text getpoderHabilidad() { return poderHabilidad; }
	sf::Text getregVida() { return regVida; }
	sf::Text getVida() { return vida; }
	sf::Text getArmor() { return armor; }
	sf::Text getresMagica() { return resMagica; }
	sf::Text getcritChance() { return critChance; }
	sf::Text getMana() { return mana; }
	sf::Text getregMana() { return regMana; }
	sf::Text getlifeSteal() { return lifeSteal; }
	sf::Text getCdr() { return cdr; }
	sf::Text getCosto() { return costo; }
	sf::Text getIdch() { return idch; }

	outputGUI operator=(Conjunto_cabecera aux)
	{
		std::string stringAux;
		std::stringstream ss;


		Campeon* c;
		c = new Campeon;
		int i = 0;
		Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
		while(arch.leerRegistro(*c, i++))
		{
			if (c->getID() == aux.getidCampeon() && c->getEstado())
			{
				idch.setString(c->getNombre());
			}
		}

		ss.str("");
		//Copio el int/float al buffer del string
		ss << aux.getidConjunto();
		//Paso del buffer al string
		stringAux = ss.str();
		//Seteo al texto de la clase
		id.setString(stringAux);

		ss.str("");
		ss << aux.getidCampeon();

		ss.str("");
		ss << aux.getNombre();
		stringAux = ss.str();
		nombre.setString(stringAux);
		delete c;
		return *this;

		
	}
	outputGUI operator=(Item aux)
	{
		std::string stringAux;
		std::stringstream ss;
		nombre.setString(aux.getNombre());

		//Copio el int/float al buffer del string
		ss << aux.getId();
		//Paso del buffer al string
		stringAux = ss.str();
		//Seteo al texto de la clase
		id.setString(stringAux);

		//Limpio el buffer
		ss.str("");
		ss << aux.getAtaque();
		stringAux = ss.str();
		ataque.setString(stringAux);

		ss.str("");
		ss << aux.getVel_ataque();
		stringAux = ss.str();
		velAtaque.setString(stringAux);

		ss.str("");
		ss << aux.getPoder_habilidad();
		stringAux = ss.str();
		poderHabilidad.setString(stringAux);

		ss.str("");
		ss << aux.getVida();
		stringAux = ss.str();
		vida.setString(stringAux);

		ss.str("");
		ss << aux.getregVida();
		stringAux = ss.str();
		regVida.setString(stringAux);

		ss.str("");
		ss << aux.getArmor();
		stringAux = ss.str();
		armor.setString(stringAux);

		ss.str("");
		ss << aux.getResistencia_magica();
		stringAux = ss.str();
		resMagica.setString(stringAux);

		ss.str("");
		ss << aux.getCrit_chance();
		stringAux = ss.str();
		critChance.setString(stringAux);

		ss.str("");
		ss << aux.getMana();
		stringAux = ss.str();
		mana.setString(stringAux);

		ss.str("");
		ss << aux.getregMana();
		stringAux = ss.str();
		regMana.setString(stringAux);

		ss.str("");
		ss << aux.getlifeSteal();
		stringAux = ss.str();
		lifeSteal.setString(stringAux);

		ss.str("");
		ss << aux.getCDR();
		stringAux = ss.str();
		cdr.setString(stringAux);

		ss.str("");
		ss << aux.getCosto();
		stringAux = ss.str();
		costo.setString(stringAux);
		return *this;
	}
	outputGUI operator=(Campeon aux)
	{
		std::string stringAux;
		std::stringstream ss;

		nombre.setString(aux.getNombre());

		//Copio el int/float al buffer del string
		ss << aux.getID();
		//Paso del buffer al string
		stringAux = ss.str();
		//Seteo al texto de la clase
		id.setString(stringAux);

		//Limpio el buffer
		ss.str("");
		ss << aux.getAtaque();
		stringAux = ss.str();
		ataque.setString(stringAux);

		ss.str("");
		ss << aux.getVel_ataque();
		stringAux = ss.str();
		velAtaque.setString(stringAux);

		ss.str("");
		ss << aux.getVida();
		stringAux = ss.str();
		vida.setString(stringAux);

		ss.str("");
		ss << aux.getArmor();
		stringAux = ss.str();
		armor.setString(stringAux);

		ss.str("");
		ss << aux.getResistencia_magica();
		stringAux = ss.str();
		resMagica.setString(stringAux);
		
		ss.str("");
		ss << aux.getMana();
		stringAux = ss.str();
		mana.setString(stringAux);
		
		ss.str("");
		if (aux.getDmg() == 1) ss.str("AD");
		else ss.str("AP");
		stringAux = ss.str();
		dmg.setString(stringAux);
		
		ss.str("");
		 switch (aux.getEstilo())
		 {
		 case 1: ss.str("LUCHADOR");
			 break;
		 case 2:
			 ss.str("MAGO");
			 break;
		 case 3:
			 ss.str("ASESINO");
			 break;
		 case 4:
			 ss.str("SOPORTE");
			 break;
		 case 5:
			 ss.str("TANQUE");
			 break;
		 case 6:
			 ss.str("TIRADOR");
			 break;
		 }

		stringAux = ss.str();
		estilo.setString(stringAux);

		return *this;
	}

	void draw(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(id);
		ventana->draw(nombre);
		ventana->draw(ataque);
		ventana->draw(velAtaque);
		ventana->draw(poderHabilidad);
		ventana->draw(vida);
		ventana->draw(regVida);
		ventana->draw(armor);
		ventana->draw(resMagica);
		ventana->draw(critChance);
		ventana->draw(mana);
		ventana->draw(regMana);
		ventana->draw(lifeSteal);
		ventana->draw(cdr);
		ventana->draw(costo);
		ventana->draw(moreOpc);
		ventana->draw(moreOpcTxt);
	}

	void drawC(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(id);
		ventana->draw(nombre);
		ventana->draw(ataque);
		ventana->draw(velAtaque);
		ventana->draw(vida);
		ventana->draw(armor);
		ventana->draw(resMagica);
		ventana->draw(mana);
		ventana->draw(dmg);
		ventana->draw(estilo);
		ventana->draw(moreOpc);
		ventana->draw(moreOpcTxt);
	}

	void drawMenuMoreOPC(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(id);
		ventana->draw(nombre);
		ventana->draw(ataque);
		ventana->draw(velAtaque);
		ventana->draw(poderHabilidad);
		ventana->draw(vida);
		ventana->draw(regVida);
		ventana->draw(armor);
		ventana->draw(resMagica);
		ventana->draw(critChance);
		ventana->draw(mana);
		ventana->draw(regMana);
		ventana->draw(lifeSteal);
		ventana->draw(cdr);
		ventana->draw(costo);
	}

	void drawMenuMoreOPC_C(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(id);
		ventana->draw(nombre);
		ventana->draw(ataque);
		ventana->draw(velAtaque);
		ventana->draw(vida);
		ventana->draw(armor);
		ventana->draw(resMagica);
		ventana->draw(mana);
		ventana->draw(dmg);
		ventana->draw(estilo);
	}

	void drawConjuntoOPC(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(idch);
		ventana->draw(id);
		ventana->draw(nombre);
	}

	void drawConjunto(sf::RenderWindow* ventana)
	{
		ventana->draw(cajaOutput);
		ventana->draw(moreOpc);
		ventana->draw(moreOpcTxt);
		ventana->draw(idch);
		ventana->draw(id);
		ventana->draw(nombre);
	}

	void cmd(clsMouse* mouse,bool*,EstadoMenu*, int*);
	void cmdC(clsMouse* mouse, bool* p, EstadoMenu* state, int* lastI);
	void cmdConjuntos(clsMouse* mouse, bool* p, EstadoMenu*, int*);
	void setPosicion(float y, bool);
	void setPosicionConj(float y);
	void setidOutput(int _id) { idOutput = _id; }
};

