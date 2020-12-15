#pragma warning(disable : 4996)

#include <iostream>
#include "Campeon.h"
#include "Item.h"
#include "Archivo.h"
#include <fstream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

void MenuGUI();

void cargarCampeon(Campeon* c, std::string aux, int row)
{

    switch (row)
    {
    case 1:
        c->setNombre(aux.c_str());
        break;
    case 2:
        c->setAtaque(stof(aux.c_str()));
        break;
    case 3:
        c->setVel_ataque(stof(aux.c_str()));
        break;
    case 4:
        c->setVida(stof(aux.c_str()));
        break;
    case 5:
        c->setArmor(stof(aux.c_str()));
        break;
    case 6:
        c->setResistencia_magica(stof(aux.c_str()));
        break;
    case 7:
        c->setMana(stof(aux.c_str()));
        break;
    case 8:
        c->setEstilo(stoi(aux.c_str()));
        break;
    case 9:
        c->setdmgType(stoi(aux.c_str()));
        break;
    }
}

void cargarItem(Item* c, std::string aux, int row)
{

    switch (row)
    {
    case 1:
        c->setNombre(aux.c_str());
        break;
    case 2:
        c->setAtaque(stof(aux.c_str()));
        break;
    case 3:
        c->setVel_ataque(stof(aux.c_str()));
        break;
    case 4:
        c->setPoder_habilidad(stof(aux.c_str()));
        break;
    case 5:
        c->setVida(stof(aux.c_str()));
        break;
    case 6:
        c->setArmor(stof(aux.c_str()));
        break;
    case 7:
        c->setResistencia_magica(stof(aux.c_str()));
        break;
    case 8:
        c->setCrit_chance(stof(aux.c_str()));
        break;
    case 9:
        c->setMana(stof(aux.c_str()));
        break;
    case 10:
        c->setregVida(stof(aux.c_str()));
        break;
    case 11:
        c->setregMana(stof(aux.c_str()));
        break;
    case 12:
        c->setlifeSteal(stof(aux.c_str()));
        break;
    case 13:
        c->setCDR(stof(aux.c_str()));
        break;
    case 14:
     
        c->setCosto(stoi(aux.c_str()));
        break;
    }
}


class CSVMatrix
{
private:
    //Campeon ch[152];
    Item it1_2_3[43];
    Item it4[23];
public:
    void loadMatrix(std::istream& inStream)
    {
        std::string         line;
        std::stringstream   lineStream;
        std::string         cell;

        int row = 0;
        int vuelta = 0;
        std::string         string_aux;

        //Archivo arch("resources/campeones/champsdata.dat", sizeof(Campeon));
        Archivo arch("resources/items/itemsdata.dat", sizeof(Item));

        //read lines
        while (std::getline(inStream, line))
        {
            vuelta = 0;
            lineStream.clear();
            lineStream.str(line);
            std::cout << "row=" << row++ << std::endl;

            //read cells
            while (std::getline(lineStream, cell, ','))
            {
                if (vuelta != 0)
                {
                  //Campeon -----------------
                  // cargarCampeon(&ch[vuelta-1], cell, row);
                  // ch[vuelta - 1].setID(vuelta);

                  //Archivo item 1
                  //cargarItem(&it1_2_3[vuelta - 1], cell, row);
                  //it1_2_3[vuelta - 1].setID(vuelta);

                  //Archivo item 2
                  //cargarItem(&it1_2_3[vuelta - 1], cell, row);
                  //it1_2_3[vuelta - 1].setID(43 + vuelta);

                  //Archivo item 3
                  //cargarItem(&it1_2_3[vuelta - 1], cell, row);
                  //it1_2_3[vuelta - 1].setID(86 + vuelta);

                  //Archivo item 4
                  cargarItem(&it4[vuelta - 1], cell, row);
                  it4[vuelta - 1].setID(129 + vuelta);

                }
                vuelta++;
            }
        }

        //Archivo item 1_2_3
       //for (int i = 0; i < 43; i++) arch.grabarRegistro(it1_2_3[i], -1, Agregar);

       //Archivo item 4
       for (int i = 0; i < 23; i++) arch.grabarRegistro(it4[i], -1, Agregar);
        


    }
};

//Metodo para leer excel y pasarlo a archivo.dat
int main()
{
    //Path de .csv campeon
    //std::ifstream       infile("champs.csv");
     //Path de .csv item
    std::ifstream       infile("items4.csv");

    CSVMatrix           matrix;

    matrix.loadMatrix(infile);

    system("pause");
}




