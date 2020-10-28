#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "clases.h"
#include "menu_desarrollador.h"

int Menu_Desarrollador::menuPrincipal()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE DESARROLLADOR" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Datos campeones" << endl;
	cout << "2. Datos items " << endl;
	cout << "3. Datos conjuntos" << endl;
	cout << "0. Salir" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 0:
		return 0;
		break;
	case 1: menuCampeones();
		break;
	case 2:
		break;
	}
	return opc;
}

void Menu_Desarrollador::menuCampeones()
{
	
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "MENU DE CAMPEONES" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Agregar campeones" << endl;
	cout << "2. Borrar campeones " << endl;
	cout << "3. Editar campeones" << endl;
	cout << "4. Mostrar campeones" << endl;
	cout << "0. Volver" << endl;
	cout << "-------------------------------" << endl;
	cout << "Elegir una opcion: ";
	cin >> opc2;
	system("cls");
	switch (opc2)
	{
	case 1:
		agregarCampeones();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:

		mostrarCampeon(leerCampeon());
		system("pause");
		break;
	case 0:
		return;
		break;
	}

}

void Menu_Desarrollador::agregarCampeones()
{
	Campeon champ;
	champ.setNombre();
	champ.setAtaque();
	champ.setVel_ataque();
	champ.setPoder_habilidad();
	champ.setVida();
	champ.setArmor();
	champ.setResistencia_magica();
	champ.setEstilo();
	champ.setDmg();
	grabarCampeon(champ);



	// TODO: Ver alguna forma de como guardar obj champ con la clase archivo
	return;
	
}

bool Menu_Desarrollador::grabarCampeon(Campeon reg) {
	FILE* p;
	p = fopen("campeones.dat", "ab");
	if (p == NULL) {
		cout << "Error abriendo campeones.dat" << endl;
		return false;
	}
	fwrite(&reg, sizeof(Campeon), 1, p);
	fclose(p);
	return true;
}

Campeon Menu_Desarrollador::leerCampeon() {
	Campeon reg;
	FILE* p;
	p = fopen("campeones.dat", "rb");
	if (p == NULL) {
		cout << "Error leyendo campeones.dat" << endl;
		return reg;
	}
	fread(&reg, sizeof(Campeon), 1, p);

	fclose(p);

	return reg;

}

void Menu_Desarrollador::mostrarCampeon(Campeon reg) {
	
	cout << "NOMBRE: " << reg.getNombre() << endl;
	cout << "ATAQUE: " << reg.getAtaque() << endl;
	cout << "VEL DE ATAQUE: " << reg.getVel_ataque() << endl;
	cout << "PODER DE HABILIDAD: " << reg.getPoder_habilidad() << endl;
	cout << "VIDA: " << reg.getVida() << endl;
	cout << "ARMADURA: " << reg.getArmor() << endl;
	cout << "RESISTENCIA MAGICA: " << reg.getResistencia_magica() << endl;
	cout << "TIPO DE PERSONAJE: " << reg.getEstilo() << endl;
	cout << "TIPO DE DANO " << reg.getDmg() << endl;
	
}