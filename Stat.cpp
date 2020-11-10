#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

#include "Stat.h"

Stat::Stat(const char* _nombre)
{
	strcpy(nombre, _nombre);
	ataque = vel_ataque = poder_habilidad = vida = armor = resistencia_magica = crit_chance = mana = regvida = regmana = CDR = lifeSteal = 0;
}

/*Stat::~Stat()
{
	const char* _nombre = "None";
	strcpy(nombre, nombre);
	ataque = vel_ataque = poder_habilidad = vida = armor = resistencia_magica = crit_chance = mana = 0;
}*/

void Stat::setStats(bool basicStats)
{
	if (basicStats)
	{
		setNombre();
		if (nombre[0] == '0') return;
		setAtaque();
		setVel_ataque();
		setVida();
		setArmor();
		setResistencia_magica();
		setMana();
	}
	else
	{
		setNombre();
		if (nombre[0] == '0') return;
		setAtaque();
		setVel_ataque();
		setPoder_habilidad();
		setVida();
		setArmor();
		setResistencia_magica();
		setCrit_chance();
		setMana();
		setregVida();
		setregMana();
		setlifeSteal();
		setCDR();

	}




}

void Stat::getStats(bool basicStats)
{
	if (basicStats)
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Velocidad de ataque: " << vel_ataque << endl;
		cout << "Vida: " << vida << endl;
		cout << "Armadura: " << armor << endl;
		cout << "Resistencia magica: " << resistencia_magica << endl;
		cout << "Mana: " << mana << endl;
	}
	else
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Velocidad de ataque: " << vel_ataque << endl;
		cout << "Poder de Habilidad: " << poder_habilidad << endl;
		cout << "Vida: " << vida << endl;
		cout << "Armadura: " << armor << endl;
		cout << "Resistencia magica: " << resistencia_magica << endl;
		cout << "Prob. Critico: " << crit_chance << endl;
		cout << "Mana: " << mana << endl;
		cout << "Reg. Mana: " << regmana << endl;
		cout << "Reg. Vida: " << regvida << endl;
		cout << "CDR: " << CDR << endl;
		cout << "Robo de vida: " << lifeSteal << endl;
	}

}

void Stat::setNombre()
{
	cin.ignore();
	cout << "Nombre: " << endl;

	int i;
	fflush(stdin);
	for (i = 0; i < 30; i++) {
		nombre[i] = cin.get();
		if (nombre[i] == '\n') break;
	}
	nombre[i] = '\0';
	fflush(stdin);

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
	cout << "Vida: " << endl;
	cin >> vida;
}
void Stat::setArmor() {
	cout << "Armor: " << endl;
	cin >> armor;
}
void Stat::setResistencia_magica() {
	cout << "Resistencia magica: " << endl;
	cin >> resistencia_magica;
}

void Stat::setCrit_chance()
{
	cout << "Crit chance: " << endl;
	cin >> crit_chance;
}
void Stat::setMana()
{
	cout << "Mana: " << endl;
	cin >> mana;
}

void Stat::setregMana()
{
	cout << "Reg. Mana: " << endl;
	cin >> regmana;
}
void Stat::setregVida()
{
	cout << "Reg. Vida: " << endl;
	cin >> regvida;
}
void Stat::setCDR()
{
	cout << "CDR: " << endl;
	cin >> CDR;
}
void Stat::setlifeSteal()
{
	cout << "Robo de vida: " << endl;
	cin >> lifeSteal;
}

float Stat::getAtaque() { return ataque; };
float Stat::getVel_ataque() { return vel_ataque; }
float Stat::getPoder_habilidad() { return poder_habilidad; }
float Stat::getVida() { return vida; }
float Stat::getArmor() { return armor; }
float Stat::getResistencia_magica() { return resistencia_magica; }
float Stat::getCrit_chance() { return crit_chance; }
float Stat::getMana() { return mana; }