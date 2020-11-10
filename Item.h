#pragma once
#include "Stat.h"

enum MOD_ITEM
{
    NOMBRE,
    ATAQUE,
    VEL_ATAQUE,
    AP,
    VIDA,
    ARMOR,
    MR,
    CRIT_CHANCE,
    MANA,
    COSTO,
    ESTADO,
};

class Item : public Stat
{
private:
    int costo;
    int id;
    bool estado;
    MOD_ITEM opc_modif;
public:
    Item(const char* _nombre);
    Item();
    //archivos
    bool guardar(int pos = -1); // Guardo en la prox posicion si no se manda na, si se manda una pos se sobreescribe ahi
    bool baja(); // Se da de baja un obj que se pide por teclado
    bool editar();
    bool modificar(int pos); // Modifico en la pos que me manden
    void mostrar(bool); // Muestro un obj, true = solo muestra el nombre, false = detalles 
    int buscar_reg(int id); // Busco el obj que me manden segun el id
    void mostrar_reg(int pos, bool mostrar_nombre); // Muestro un obj en especifico. true = solo muestra el nombre, false = detalles 
    void mostrar_registros(); // Muestro todos los reg
    int contar_reg(); // Contar todos los obj
    //metodos
    bool cargarItem();
    //set
    void setEstado(bool);
    void setCosto();
    //get
    bool getEstado() { return estado; }
    int getId() { return id; }
    int getCosto(int);
};

