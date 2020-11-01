#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "devmenu.h"


int main()
{
bool DEV_MENU = true;

	if(DEV_MENU){
		Menu_Desarrollador menu;

		while (menu.menuPrincipal() != 0) {};
	}
	else {
		//Interfaz normal user.
	}
	

	return 0;
}