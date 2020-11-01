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

	getStats();
	cout << "Tipo de danio: " << dmg_type << endl;
	cout << "Rol: " << estilo << endl << endl;
	cout << "---------------------------------------" << endl;
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
}

// Operaciones archivos

int Campeon::contar_reg()
{
	FILE* pf;
	int c = 0;
	pf = fopen("resources/campeones/champsdata.dat", "rb");
	if (pf == NULL)
	{
		return 0;
		cout << "clase campeon : contar_reg";
	}
	while (fread(this, sizeof * this, 1, pf) == 1) c++;
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
	while (fread(this, sizeof * this, 1, pf))
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
}