#pragma warning(disable : 4996)

#include <SFML/Graphics.hpp>
#include "Campeon.h"
#include "Archivo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>

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
        MenuGUI.init();
    }


    return 0;

}

