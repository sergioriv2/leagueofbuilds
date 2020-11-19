#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "devmenu.h"
#include "GUI.h"

int main()
{
	bool DEV_MENU = false;

	if (DEV_MENU) {
		Menu_Desarrollador menu;

		while (menu.menuPrincipal() != 0) {};
	}
	else
	{
		Menu MenuGUI;
	}


		return 0;
	
}

/*int WinMain()
{
	Menu MenuGUI;
}*/