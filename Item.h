#pragma once
#include "Stat.h"
class Item : public Stat
{
    char nombre[30];
    int costo;
    int id;
    bool estado;
};

