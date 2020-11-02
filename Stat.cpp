#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "Stat.h"

Stat::Stat(const char* _nombre)
{
	strcpy(nombre, _nombre);
	ataque = vel_ataque = poder_habilidad = vida = armor = resistencia_magica = mana = crit_chance =0;
}

Stat::~Stat()
{

}

void Stat::setNombre()
{
	cin.ignore();
	cout << "Nombre: " << endl;
	cin.getline(nombre, 20);

}

void Stat::setAtaque()
{
	cout << "Ataque: " << endl;
	cin >> ataque;
}
void Stat::setVel_ataque()
{
	cout << "Velocidad de ataque: " << endl;
	cin >> vel_ataque;
}
void Stat::setPoder_habilidad()
{
	cout << "Poder de habilidad: " << endl;;
	cin >> poder_habilidad;
}
void Stat::setVida() {
	cout << "Vida: " << endl;;
	cin >> vida;
}
void Stat::setArmor() {
	cout << "Armor: " << endl;;
	cin >> armor;
}
void Stat::setResistencia_magica() {
	cout << "Resistencia magica: " << endl;;
	cin >> resistencia_magica;
}
void Stat::setCrit_chance() {
	crit_chance = 0.00;
}
void Stat::setMana() {
	cout << "Mana : " << endl;;
	cin >> mana;
}

const char* Stat::getNombre() { return nombre; } 
float Stat::getAtaque() { return ataque; };
float Stat::getVel_ataque() { return vel_ataque; }
float Stat::getPoder_habilidad() { return poder_habilidad; }
float Stat::getVida() { return vida; }
float Stat::getArmor() { return armor; }
float Stat::getResistencia_magica() { return resistencia_magica; }
float Stat::getCrit_chance() { return crit_chance; }
float Stat::getMana() { return mana; }