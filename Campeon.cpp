#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "Campeon.h"

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

void Campeon::cargarCampeon()
{
	setStats();
	setEstilo();
	setdmgType();
	id = contar_reg();
	estado = true;

}

void Campeon::mostrarCampeon()
{
	system("cls");
	if(getEstado() == true){
	getStats();
	cout << "Tipo de danio: " << dmg_type << endl;
	cout << "Rol: " << estilo << endl << endl;
	cout << "---------------------------------------" << endl;
	}
}


void Campeon::setdmgType()
{

	cout << "Tipo de danio: " << endl;
	cin >> dmg_type;

}

void Campeon::setStats()
{
	setNombre();
	setAtaque();
	setVel_ataque();
	setPoder_habilidad();
	setVida();
	setArmor();
	setResistencia_magica();
	setCrit_chance();
	setMana();
	
}

// Operaciones archivos

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
		return;
	}
	while (fread(this, sizeof * this, 1, pf)&&getEstado()==true)
	{
		getStats();
		cout << "Estilo: " << getEstilo() << endl;
		cout << "Tipo de danio " << getDmg() << endl;
		cout << "ID: " << id << endl;
		cout << "-----------------------------" << endl;
	}
	fclose(pf);

}

void Campeon::getStats()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Ataque: " << ataque << endl;
	cout << "Velocidad de ataque: " << vel_ataque << endl;
	cout << "Poder de habilidad: " << poder_habilidad << endl;
	cout << "Vida: " << vida << endl;
	cout << "Armadura: " << armor << endl;
	cout << "Resistencia magica: " << resistencia_magica << endl;
	cout << "Probablidad de critico: " << crit_chance << endl;
	cout << "Mana " << mana << endl;
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
	return -1;
}

bool Campeon::modify(int POS, int OPC) {
	FILE* p;	
	
	p=fopen("resources/campeones/champsdata.dat", "rb+");
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
