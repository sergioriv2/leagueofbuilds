#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace sf;
using namespace std;

#include "clases.h"
#include "menu_desarrollador.h"
int main()
{
	Menu_Desarrollador menu;

	while (menu.menuPrincipal() != 0);

	return 0;
}