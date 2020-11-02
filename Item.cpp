#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "Item.h"

const char* UBICACION_ITEMS = "resources/items/itemsdata.dat";

Item::Item() :Stat()
{
	costo = 0, id = 0;
	estado = true;
}

Item::Item(const char* _nombre) :Stat(_nombre)
{
	costo = id = 0;
	estado = true;
}

void Item::setEstado(bool _estado)
{
	estado = _estado;
}

void Item::setCosto()
{
	do
	{
		cout << "Costo: ";
		cin >> costo;
	} while (costo < 0);
	
}

void Item::cargarItem()
{
	setStats();
	setCosto();
	id = contar_reg();
	estado = true;
}

//archivos

bool Item::guardar(int pos)
{
	FILE* pf;
	if (pos == -1)
	{
		pf = fopen(UBICACION_ITEMS, "ab");
		if (pf == NULL)
		{
			cout << "clase items : guardar";
			return false;
		}
		bool save = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
		return save;
	}
	else
	{
		pf = fopen(UBICACION_ITEMS, "rb+");
		if (pf == NULL)
		{
			cout << "clase items : guardar";
			return false;
		}
		fseek(pf, (sizeof * this) * pos, 0);
		bool save = fwrite(this, sizeof * this, 1, pf);
		fclose(pf);
		return save;
	}
}

void Item::mostrar_registros()
{
	FILE* pf;
	pf = fopen(UBICACION_ITEMS, "rb");
	if (pf == NULL)
	{
		cout << "clase item : mostrar_registros";
		return;
	}
	while (fread(this, sizeof * this, 1, pf) == 1)
	{
		//if (estado) 
			mostrar();
	}
	fclose(pf);
}

void Item::mostrar_reg(int pos)
{
	FILE* pf;
	pf = fopen(UBICACION_ITEMS, "rb");
	if (pf == NULL)
	{
		cout << "clase item : mostrar_reg";
		return;
	}
	fseek(pf, (sizeof * this) * pos, 0);
	fread(this, sizeof * this, 1, pf);

	if (estado) mostrar();

	fclose(pf);
}

void Item::mostrar()
{
	getStats();
	cout << "Costo: " << costo << endl;
	cout << "ID: " << id << endl;
	cout << "-------------------------" << endl;
}

int Item::contar_reg()
{
	Item pitem;
	int c = 0;
	FILE* pf;
	pf = fopen(UBICACION_ITEMS, "rb");
	if (pf == NULL) return 0;
	while (fread(&pitem, sizeof pitem, 1, pf) == 1) c++;
	fclose(pf);
	return c;
}

bool Item::baja()
{
	char opc;
	int id, pos;
	do
	{
		cout << "Ingresar N de ID: ";
		cin >> id;
		pos = buscar_reg(id);
	} while (pos == -1);
	system("cls");
	cout << "Se encontro el siguiente registro: " << endl << endl;

	mostrar_reg(pos);

	cout << endl << "Darlo de baja? S/N" << endl;
	cin >> opc;
	system("cls");
	if (opc == 's' || opc == 'S')
	{
		opc_modif = MOD_ITEM::ESTADO;
		return modificar(pos);
	}
	else
	{
		return false;
	}


}

int Item::buscar_reg(int id)
{
	Item pitem;
	int pos = 0;
	FILE* pf;
	pf = fopen(UBICACION_ITEMS, "rb");
	if (pf == NULL)
	{
		cout << "item : buscar_reg";
		return -1;
	}
	while (fread(&pitem, sizeof pitem, 1, pf))
	{
		if (pitem.getEstado())
		{
			if (pitem.getId() == id)
			{
				return pos;
			}
		}
		pos++;
	}
	fclose(pf);
	return -1;
}

bool Item::editar()
{
	int opc;
	int id, pos;
	do
	{
		cout << "Escribir -1 para salir" << endl << endl;
		cout << "Ingresar N de ID: ";
		cin >> id;
		if (id == -1) return false;
		pos = buscar_reg(id);
	} while (pos == -1);
	system("cls");
	cout << "Se encontro el siguiente registro: " << endl << endl;

	mostrar_reg(pos);

	cout << endl;
	cout << "1 NOMBRE" << endl;
	cout << "2 ATAQUE" << endl;
	cout << "3 VELOCIDAD DE ATAQ" << endl;
	cout << "4 PODER DE HABILIDAD" << endl;
	cout << "5 VIDA" << endl;
	cout << "6 ARMOR" << endl;
	cout << "7 RESISTENCIA MAGICA" << endl;
	cout << "8 PROBABILIDAD DE CRITICO" << endl;
	cout << "9 MANA" << endl;
	cout << "10 COSTO" << endl << endl;
	cout << "Elegir que modificar: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 1:
		opc_modif = MOD_ITEM::NOMBRE;
		break;
	case 2: 
		opc_modif = MOD_ITEM::ATAQUE;
		break;
	case 3:
		opc_modif = MOD_ITEM::VEL_ATAQUE;
		break;
	case 4:
		opc_modif = MOD_ITEM::AP;
		break;
	case 5:
		opc_modif = MOD_ITEM::VIDA;
		break;
	case 6:
		opc_modif = MOD_ITEM::ARMOR;
		break;
	case 7:
		opc_modif = MOD_ITEM::MR;
		break;
	case 8:
		opc_modif = MOD_ITEM::CRIT_CHANCE;
		break;
	case 9:
		opc_modif = MOD_ITEM::MANA;
		break;
	case 10:
		opc_modif = MOD_ITEM::COSTO;
		break;
	default:return false;
	}

	return modificar(pos);

}

bool Item::modificar(int pos)
{
	FILE* pf;
	bool mod;
	pf = fopen(UBICACION_ITEMS, "rb+");
	if (pf == NULL)
	{
		cout << "item : modificar";
		return false;
	}
	fseek(pf, (sizeof *this) * pos, 0);

	//Depende que le mande el enum, hace otras cositas
	switch (opc_modif)
	{
	case NOMBRE:
		setNombre();
		break;
	case ATAQUE:
		setAtaque();
		break;
	case VEL_ATAQUE:
		setVel_ataque();
		break;
	case AP:
		setPoder_habilidad();
		break;
	case VIDA:
		setVida();
		break;
	case ARMOR:
		setArmor();
		break;
	case MR:
		setResistencia_magica();
		break;
	case CRIT_CHANCE:
		setCrit_chance();
		break;
	case MANA:
		setMana();
		break;
	case COSTO:
		setCosto();
		break;
	case ESTADO:
		estado = false;
		break;
	default:
		break;
	}
	mod = fwrite(this, sizeof * this, 1, pf);
	fclose(pf);
	return mod;
}