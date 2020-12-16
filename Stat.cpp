#include <iostream>
#include <cstdio>
#include <string>

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
		if(!(setNombre())) return;
		setAtaque();
		setVel_ataque();
		setVida();
		setArmor();
		setResistencia_magica();
		setMana();
	}
	else
	{
		if (!(setNombre())) return;
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

bool Stat::setNombre()
{
	do {
		/*cin.ignore();
		cout << "Nombre: " << endl;

		int i;
		fflush(stdin);
		for (i = 0; i < 30; i++) {
			nombre[i] = cin.get();
			if (nombre[i] == '\n') break;
		}
		nombre[i] = '\0';
		fflush(stdin);
		*/

		cout << "Ingresar nombre: " << endl;
		cin.ignore();
		cin.getline(nombre, 30, '\n');
		if (nombre[0] == '0') return false;;
	} while (!Stat::validarNombre(nombre));
	return true;

}

void Stat::setAtaque()
{
	do {
		cout << "Ataque: " << endl;
		cin >> ataque;
	} while (!Stat::validarAtaque(ataque));
}
void Stat::setVel_ataque()
{
	do {
		cout << "Velocidad de ataque (): " << endl;
		cin >> vel_ataque;
	} while (!Stat::validarVa(vel_ataque));
}
void Stat::setPoder_habilidad()
{
	do {
		cout << "Poder de habilidad: " << endl;;
		cin >> poder_habilidad;
	} while (!Stat::validarPh(poder_habilidad));
}
void Stat::setVida() {
	do {
		cout << "Vida: " << endl;
		cin >> vida;
	} while (!Stat::validarVida(vida));
}
void Stat::setArmor() {
	do {
		cout << "Armor: " << endl;
		cin >> armor;
	} while (!Stat::validarArmor(armor));
}
void Stat::setResistencia_magica() {
	do {
		cout << "Resistencia magica: " << endl;
		cin >> resistencia_magica;
	} while (!Stat::validarRM(resistencia_magica));
}

void Stat::setCrit_chance()
{
	do {
		cout << "Crit chance: " << endl;
		cin >> crit_chance;
	} while (!Stat::validarCrit(crit_chance));
}
void Stat::setMana()
{
	do {
		cout << "Mana: " << endl;
		cin >> mana;
	} while (!Stat::validarMana(mana));
}

void Stat::setregMana()
{
	do {
		cout << "Reg. Mana: " << endl;
		cin >> regmana;
	} while (!Stat::validarRegmana(regmana));
}
void Stat::setregVida()
{
	do {
		cout << "Reg. Vida: " << endl;
		cin >> regvida;
	} while (!Stat::validarRegvida(regvida));
}
void Stat::setCDR()
{
	do {
		cout << "CDR: " << endl;
		cin >> CDR;
	} while (!Stat::validarCDR(CDR));
}
void Stat::setlifeSteal()
{
	do {
		cout << "Robo de vida: " << endl;
		cin >> lifeSteal;
	} while (!Stat::validarRobovida(lifeSteal));
}

float Stat::getAtaque() { return ataque; };
float Stat::getVel_ataque() { return vel_ataque; }
float Stat::getPoder_habilidad() { return poder_habilidad; }
float Stat::getVida() { return vida; }
float Stat::getArmor() { return armor; }
float Stat::getResistencia_magica() { return resistencia_magica; }
float Stat::getCrit_chance() { return crit_chance; }
float Stat::getMana() { return mana; }

bool Stat::validarNombre(char* nombre) {
	if (nombre[0] == '\0' || nombre[0] == ' ') {
		cout << "No ingresar espacios en blanco." << endl;
		return false;
	}
	return true;
}
bool Stat::validarAtaque(float ataque) {

	if (ataque > 200 || ataque < 0) {
		cout << "Checkear que el ataque ingresado no mayor a 200 ni menor a 0" << endl;
		return false;
	}
	return true;
}
bool Stat::validarVa(float va) {
	//champ
	if (va < 0.00f) {
		cout << "Checkear que la velocidad de ataque ingresada no sea un valor negativo " << endl;
		return false;
	}

	return true;
}
bool Stat::validarPh(float ph) {
	if (ph > 300 || ph < 0) {
		cout << "Checkear que el poder de habilidad no sea mayor a 300 ni un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarVida(float vida) {
	if (vida < 0) {
		cout << "Checkear que la vida no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarArmor(float armor) {
	if (armor < 0) {
		cout << "Checkear que la armadura no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarRM(float rm) {
	if (rm < 0) {
		cout << "Checkear que la resistencia magica no sea un valor negativo" << endl;

		return false;
	}
	return true;
}
bool Stat::validarCrit(float crit) {
	if (crit < 0) {
		cout << "Checkear que la probabilidad de critico no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarMana(float mana) {
	if (mana < 0) {
		cout << "Checkear que el mana no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarRegmana(float regmana) {
	if (regmana < 0) {
		cout << "Checkear que la regeneracion de  mana no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarRegvida(float regvida) {
	if (regvida < 0) {
		cout << "Checkear que la regeneracion de vida no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarCDR(float cdr) {
	if (cdr < 0) {
		cout << "Checkear que la reduccion de enfriamiento no sea un valor negativo" << endl;
		return false;
	}
	return true;
}
bool Stat::validarRobovida(float lifesteal) {
	if (lifesteal < 0) {
		cout << "Checkear que el robo de vida no sea un valor negativo" << endl;
		return false;
	}
	return true;
}