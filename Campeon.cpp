#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "Campeon.h"
#include "Archivo.h"

Campeon::Campeon(const char* _estilo, const char* _dmgtype) :Stat()
{
	strcpy(estilo, _estilo);
	strcpy(dmg_type, _dmgtype);
	id = 0;
	estado = 0;
}

Campeon::~Campeon()
{

}

void Campeon::setEstilo() {

	cin.ignore();
	cout << "Estilo: " << endl;
	cin.getline(estilo, 20);
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

	id = arch.getCantidadRegistros();

	estado = true;
	return true;
}

void Campeon::Mostrar()
{
	if (getEstado() == true) {
		getStats(1);
		cout << "Tipo de danio: " << dmg_type << endl;
		cout << "Rol: " << estilo << endl;
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

	champ.setEstadoFalse();

	b = arch.grabarRegistro(champ, ID, LecturaEscritura);
	if (b)return true;
	else return false;
}


bool Campeon::Modificar(int ID) {
	int opc, b;
	Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	arch.leerRegistro(champ, ID);

	//No hace falta, con usar ID ya está
	//pos=arch.buscarRegistro(champ);//Leo y cargo el registro para buscar la pos

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
		champ.setNombre();
		break;
	case 3:
		champ.setNombre();
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

	cout << "Tipo de danio: " << endl;
	cin >> dmg_type;

}
