#pragma once
#pragma warning(disable : 4996)
#include "../hpp/Registro.h"
#include <iostream>

///////////////////////////
//TIPOS ENUMERADOS PARA USAR CON LA CLASE ARCHIVO
enum EstadoArch {//DEFINE LOS ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
	NoExiste,
	Cerrado,
	AbiertoR,
	AbiertoW,
	AbiertoA,
	AbiertoRW
};

enum Modo {//DEFINE LOS MODOS DE APERTURA DE UN ARCHIVO
	SoloLectura,
	Escritura,
	Agregar,
	LecturaEscritura
};

class Archivo
{
private:
	FILE* pF;
	int tamanioRegistro;
	void* pRegistro;
	char* nombreArchivo;
	int cantRegistros;
	int estado;
	int cantidadRegistros() {
		if (!abrirArchivo(SoloLectura)) {
			estado = Cerrado;
			return 0;
		}
		fseek(pF, 0, 2);
		long cant = ftell(pF) / tamanioRegistro;
		cerrarArchivo();
		return (int)cant;
	}
	bool abrirArchivo(Modo modo);
	void cerrarArchivo() {
		fclose(pF);
		estado = Cerrado;
	}

public:
	Archivo(const char* nombre, int tam) {
		nombreArchivo = new char[strlen(nombre) + 1];
		if (nombreArchivo == NULL)exit(1);
		strcpy(nombreArchivo, nombre);
		tamanioRegistro = tam;
		pRegistro = (void*)malloc(tamanioRegistro);
		cantRegistros = cantidadRegistros();
		estado = Cerrado;
	}
	~Archivo() {
		delete nombreArchivo;
		if (pF)fclose(pF);
		free(pRegistro);
	}

	int leerRegistro(Registro&, int);
	int buscarRegistro(Registro&);
	int grabarRegistro(Registro& dato, int pos, Modo modo);

	int alta(Registro&);
	const char* getNombreArchivo() { return nombreArchivo; }
	int getCantidadRegistros() { return cantRegistros; }
	bool listarArchivo(Registro& aux);

	bool crearBackup(Registro& aux, Archivo& archbkp);
	bool restoreBackup(Registro& aux, Archivo& torestore);
};
