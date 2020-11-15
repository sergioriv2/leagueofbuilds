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
		cout << "Rol: " << estilo << endl << endl;
		cout << "---------------------------------------" << endl << endl;
	}
}

bool Campeon::Modificar(int ID) {
	int opc,pos, b;
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
	if (b)return true;
	else return false;
}
	
bool Campeon::BajaVirtual(int ID) {
	int opc, pos, b;
	Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
	Campeon champ;
	arch.leerRegistro(champ, ID);

	champ.setEstadoFalse();

	b = arch.grabarRegistro(champ, ID, LecturaEscritura);
	if (b)return true;
	else return false;

}



void Campeon::setdmgType()
{

	cout << "Tipo de danio: " << endl;
	cin >> dmg_type;

}


// Operaciones archivos

/*
int Campeon::contar_reg() // Fixed
{
	Campeon pchamp;
	FILE* pf;
	int c = 0;
	pf = fopen("resources/campeones/champsdata.dat", "rb");
	if (pf == NULL)
	{
		return 0;
		cout << "clase campeon : contar_reg";
	}
	while (fread(&pchamp, sizeof pchamp, 1, pf) == 1) c++;
	fclose(pf);
	return c;
}

bool Campeon::guardarCampeon(int pos)
{
	FILE* pf;
	if (pos == -1)
	{
		pf = fopen("resources/campeones/champsdata.dat", "ab");
		if (pf == NULL)
		{
			cout << "guardarCampeon" << endl;
			return false;
		}
		bool saved = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
		return saved;
	}
	else
	{
		pf = fopen("resources/campeones/champsdata.dat", "rb+");
		if (pf == NULL)
		{
			cout << "guardarCampeon" << endl;
			return false;
		}
		fseek(pf, (sizeof * this) * pos, 0);
		bool saved = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
		return saved;
	}
}

void Campeon::mostrarCampeones()
{
	FILE* pf;
	pf = fopen("resources/campeones/champsdata.dat", "rb");
	if (pf == NULL)
	{
		cout << "leerCampeon" << endl;
		system("pause");
		return;
	}
	while (fread(this, sizeof *this, 1, pf))
	{
		if (estado)
		{
			getStats(1);
			cout << "Estilo: " << getEstilo() << endl;
			cout << "Tipo de danio " << getDmg() << endl;
			cout << "ID: " << id << endl;
			cout << "-----------------------------" << endl;
		}
	
	}
	fclose(pf);

}

int Campeon::searchPos(int ID) {
	FILE* p;
	int pos = 0;
	p = fopen("resources/campeones/champsdata.dat", "rb");
	if (p == NULL) {
		cout << "Error abriendo champsdata.data" << endl;
		return -1;
	}
	while (fread(this, sizeof(*this), 1, p)) {
		if (Campeon::getID() == ID) {
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -1;
}

bool Campeon::modify(int POS, int OPC) {
	FILE* p;

	p = fopen("resources/campeones/champsdata.dat", "rb+");
	if (p == NULL) {
		cout << "Error abriendo champsdata.dat " << endl;
		return false;
	}
	fseek(p, sizeof(Campeon) * POS, 0);
	//fwrite
	//Modifico dependiendo lo que me hayan pedido
	switch (OPC) {
	case 1:
		setNombre();
		break;
	case 2:
		setAtaque();
		break;
	case 3:
		setVel_ataque();
		break;
	case 4:
		setPoder_habilidad();
		break;
	case 5:
		setVida();
		break;
	case 6:
		setArmor();
		break;
	case 7:
		setResistencia_magica();
		break;
	case 8:
		setCrit_chance();
		break;
	case 9:
		setMana();
		break;

	}
	fwrite(this, sizeof(*this), 1, p);
	fclose(p);
	return true;
}

bool Campeon::leerCampeon(int POS) {
	FILE* p;
	p = fopen("resources/campeones/champsdata.dat", "rb");
	if (p == NULL) {
		cout << "Error abriendo champsdata.dat " << endl;
		return false;
	}
	fseek(p, sizeof(Campeon) * POS, 0);
	fread(this, sizeof(*this), 1, p);
	fclose(p);
	return true;

}

*/