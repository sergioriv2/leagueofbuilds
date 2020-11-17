#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#include "Registro.h"
#include "Archivo.h"
#include "Campeon.h"


/////////////
//DEFINICIONES CLASE ARCHIVO
//Los registros del archivo deben ser objetos de clases
//derivadas de la clase registro
//
//Los métodos reciben una referencia a un objeto Registro.
//A partir de esta referencia, que representará a un objeto
//de alguna clase derivada de Registro, se consigue la especificidad
//de cada archivo.
//
//Todos los métodos abren y cierran el archivo de acuerdo
//a lo que sea necesario. No se pueda abrir el archivo desde fuera de la clase
///////////////////////////////////

//leerRegistro(Registro &var, int pos)
//LEE EL REGISTRO UBICADO EN LA POSICIÓN pos, Y LO ESCRIBE EN LA REFERENCIA var
//DEVUELVE 1 SI LEYO; 0 SI NO LEYO; -1 SI EL ARCHIVO NO EXISTE

int  Archivo::leerRegistro(Registro& var, int pos) {
    int x;
    if (!abrirArchivo(SoloLectura)) {
        return -1;
    }
    fseek(pF, pos * var.getSize(), 0);
    x = fread(pRegistro, var.getSize(), 1, pF);
    fclose(pF);
    var = (Registro*)pRegistro;
    cerrarArchivo();
    return x;
}

//grabarRegistro( Registro &dato, int pos).
//ESCRIBE EN EL DISCO LOS DATOS EXISTENTES EN LA REFERENCIA dato
//SI EL VALOR DE POS ES -1 AGREGA UN REGISTRO NUEVO
// SI EL VALOR ES 0 O POSITIVO SOBREESCRIBE EL REGISTRO UBICADO EN ESA POSICION
//DEVUELVE 1 SI GRABO; -1 SI NO EXISTE; 0 SI NO PUDO GRABAR
int Archivo::grabarRegistro(Registro& dato, int pos, Modo modo) {
    int grabo;

    switch (modo) {
    case Escritura:
        if (!abrirArchivo(Escritura)) {
            cout << "no pudo abrir en RB" << endl;
            system("pause");
            return -1;
        }
        grabo = fwrite(&dato, dato.getSize(), 1, pF);
        cerrarArchivo();

        return grabo;
        break;
    case LecturaEscritura:
        if (!abrirArchivo(LecturaEscritura)) {
            cout << "lecturaEscritura" << endl;
            return -1;
        }
        fseek(pF, dato.getSize() * pos, 0);
        grabo = fwrite(&dato, dato.getSize(), 1, pF);
        cerrarArchivo();
        return grabo;

        break;
    case Agregar:
        if (!abrirArchivo(Agregar)) {
            cout << "no pudo abrir en AB" << endl;
            system("pause");
            return -1;
        }
        grabo = fwrite(&dato, tamanioRegistro, 1, pF);
        cerrarArchivo();
        if (grabo && pos == -1)  cantRegistros++;
        return grabo;
        break;
    default: return -1;
    }

    // if (grabo && pos == -1)  cantRegistros++; not sure donde dejar esto

}

//alta(Registro &obj)
//AGREGA UN REGISTRO AL ARCHIVO
//VALIDA EL CAMPO CLAVE
//DEVUELVE -1 SI NO PUDO ABRIR EL ARCHIVO, 1 SI GRABO, 0 SI NO GRABO Y -2 SI SE REPITE EL CODIGO
int Archivo::alta(Registro& obj) {
    int grabo;
    if (!abrirArchivo(Agregar)) {
        return -1;
    }
    system("cls");
    cout << "ALTA DE REGISTRO" << endl;
    obj.Cargar();
    int pos = buscarRegistro(obj);
    if (pos == -1) {
        grabo = grabarRegistro(obj, -1, Agregar);
        cerrarArchivo();
        return grabo;
    }
    else {
        cout << "YA EXISTE EL CODIGO" << endl;
        cout << "NO SE GRABO EL REGISTRO" << endl;
        system("pause");
    }
    return -2;
}
//listarArchivo(Registro &aux)
//LISTA EL ARCHIVO COMPLETO
bool Archivo::listarArchivo(Registro& aux) {
    if (cantRegistros == 0)return false;
    if (!abrirArchivo(SoloLectura)) {
        return false;
    }
    while (fread(pRegistro, tamanioRegistro, 1, pF)) {
        aux = (Registro*)pRegistro;
        aux.Mostrar();
    };
    cerrarArchivo();
    return true;
}


//buscarRegistro(Registro &obj)
//COMPARA EL CAMPO CLAVE DEL REGISTRO RECIBIDO COMO PARAMETRO
//CON LOS REGISTROS DEL ARCHIVO.
//SI YA EXISTE EL VALOR DEL CAMPO CLAVE DEVUELVE LA POSICIÓN QUE OCUPA EN EL ARCHIVO
//SI NO LO ENCUENTRA DEVUELVE -1, Y SI NO PUDO ABRIR EL ARCHIVO DEVUELVE -2
int Archivo::buscarRegistro(Registro& obj) {
    if (!abrirArchivo(SoloLectura)) {
        return -2;
    }
    while (fread(pRegistro, tamanioRegistro, 1, pF)) {
        if (obj.comparaID((Registro*)pRegistro)) {
            int pos = (ftell(pF) - tamanioRegistro) / tamanioRegistro;
            cerrarArchivo();
            return pos;
        }
    };
    cerrarArchivo();
    return -1;
}

//abrirArchivo(Modo modo)
//ABRE EL ARCHIVO EN EL MODO ESTABLECIDO POR EL PARAMETRO modo.
//DEVUELVE TRUE SI PUDO ABRIR Y FALSE SI NO PUDO ABRIR
bool Archivo::abrirArchivo(Modo modo) {
    switch (estado) {
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:cerrarArchivo();
        break;
    }
    switch (modo) {
    case SoloLectura:
        pF = fopen(nombreArchivo, "rb");
        if (!pF)return false;
        estado = AbiertoR;
        break;
    case Escritura:
        pF = fopen(nombreArchivo, "wb");
        if (!pF)return false;
        estado = AbiertoW;
        break;
    case Agregar:
        pF = fopen(nombreArchivo, "ab");
        if (!pF) return false;
        estado = AbiertoA;
        break;
    case LecturaEscritura:
        pF = fopen(nombreArchivo, "rb+");
        if (!pF)return false;
        estado = AbiertoRW;
        break;

    }
    return true;
}

//El archivo que va a llamar a este metodo es del que se va a generar un bkp
//Deberia llamarse desde los .dat e ingresar el .bkp
bool Archivo::crearBackup(Registro& aux ,Archivo& archbkp) {

    this->pF = fopen(nombreArchivo, "rb");
    if (this->pF == NULL) {
        cout << "Error leyendo archivo L204" << endl;
        return false;
    }
    archbkp.pF = fopen(archbkp.getNombreArchivo(), "wb");
    if (archbkp.pF==NULL) {
        cout << "Error creando archivo bkp." << endl;
        return false;
    }
    //mientras pueda leer en el dat escribe en el bkp
    while (fread(&aux,sizeof(aux),1,this->pF)) {
        fwrite(&aux, sizeof(aux), 1, archbkp.pF);
    }
    fclose(this->pF);
    fclose(archbkp.pF);

    return true;
}
//El archivo que llame a este metodo va ser desde el que se restaurara
//Deberia llamarse desde los .bkp e ingresar el .dat
bool Archivo::restoreBackup(Registro& aux, Archivo& torestore) {

    this->pF = fopen(nombreArchivo, "rb");
    if (this->pF == NULL) {
        cout << "Error leyendo archivo L220" << endl;
        return false;
    }
    torestore.pF = fopen(torestore.getNombreArchivo(), "wb");
    if (torestore.pF == NULL) {
        cout << "Error restaurando el archivo .dat " << endl;
        return false;
    }
    //mientras pueda leer en el dat escribe en el bkp
    while (fread(&aux, sizeof(aux), 1, this->pF)) {
        fwrite(&aux, sizeof(aux), 1, torestore.pF);
    }
    fclose(this->pF);
    fclose(torestore.pF);

    return true;
}