#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "Campeon.h"
#include "Archivo.h"

Campeon::Campeon(int _estilo, int _dmgtype) :Stat()
{

	this->estilo = _estilo;
	this->dmg_type = _dmgtype;
	id = 0;
	estado = true;
}

void Campeon::setEstilo() {
	do {
		cout << "1-Luchador | 2-Mago | 3-Asesino | 4-Soporte | 5-Tanque | 6-Tirador" << endl;
		cout << "Estilo: " << endl;
		cin >> estilo;
	} while (!Campeon::validarEstilo(estilo));
}

void Campeon::setEstadoFalse() {
	estado = false;
}

bool Campeon::Cargar()
{
	Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));

	setStats(1);
	if (nombre[0] == '0') return false;
	setEstilo();
	setdmgType();

	id = arch.getCantidadRegistros()+1;

	estado = true;
	return true;
}

void Campeon::Mostrar()
{
	if (getEstado() == true) {
		getStats(1);
		switch (dmg_type) {
		case 1:
			cout << "Tipo de danio: AD" << endl;
			break;
		case 2:
			cout << "Tipo de danio: AP" << endl;
			break;
		}
		switch (estilo) {
		case 1:
			cout << "Rol: Luchador" << endl;
			break;
		case 2:
			cout << "Rol: Mago" << endl;
			break;
		case 3:
			cout << "Rol: Asesino" << endl;
			break;
		case 4:
			cout << "Rol: Soporte" << endl;
			break;
		case 5:
			cout << "Rol: Tanque" << endl;
			break;
		case 6:
			cout << "Rol: Tirador" << endl;
			break;
		}
		cout << "ID: " << id << endl << endl;
		cout << "---------------------------------------" << endl << endl;
	}
}

bool Campeon::BajaVirtual(int ID)
{
	int b;
	Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	arch.leerRegistro(champ, ID);

	champ.setEstado(false);

	b = arch.grabarRegistro(champ, ID, LecturaEscritura);
	if (b)return true;
	else return false;
}


bool Campeon::Modificar(int ID) {
	int opc, b;
	Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	arch.leerRegistro(champ, ID);

	cout << "Elija lo que desea modificar " << endl;

	cout << "1 NOMBRE" << endl;
	cout << "2 ATAQUE" << endl;
	cout << "3 VELOCIDAD DE ATAQ" << endl;
	cout << "4 PODER DE HABILIDAD" << endl;
	cout << "5 VIDA" << endl;
	cout << "6 ARMOR" << endl;
	cout << "7 RESISTENCIA MAGICA" << endl;
	cout << "8 PROBABILIDAD DE CRITICO" << endl;
	cout << "9 MANA" << endl;
	cin >> opc;
	switch (opc) {
	case 1:
		champ.setNombre();
		break;
	case 2:
		champ.setAtaque();
		break;
	case 3:
		champ.setVel_ataque();
		break;
	case 4:
		champ.setPoder_habilidad();
		break;
	case 5:
		champ.setVida();
		break;
	case 6:
		champ.setArmor();
		break;
	case 7:
		champ.setResistencia_magica();
		break;
	case 8:
		champ.setCrit_chance();
		break;
	case 9:
		champ.setMana();
		break;

	}
	b = arch.grabarRegistro(champ, ID, LecturaEscritura);
	if (b == -1) return false;
	else
	{
		if (b) return true;
		else return false;
	}
}


void Campeon::setdmgType()
{
	do {
		cout << "Tipo de danio(1-ad,2-ap): " << endl;
		cin >> dmg_type;
	} while (!validarTipodmg(dmg_type));
}

bool Campeon::validarEstilo(int estilo) {
	if (estilo > 6 || estilo < 0) {
		cout << "Ingresar un estilo valido (1-Luchador | 2-Mago | 3-Asesino | 4-Soporte | 5-Tanque | 6-Tirador)" << endl;
		return false;
	}
	return true;
}
bool Campeon::validarTipodmg(int tipodmg) {
	if (tipodmg > 2 || tipodmg < 0) {
		cout << "Ingresar un tipo valido (1-AD,2-AP)" << endl;
		return false;
	}
	return true;
}

