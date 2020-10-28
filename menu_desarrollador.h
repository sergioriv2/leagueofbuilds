#pragma once


class Menu_Desarrollador
{
private:
	int opc, opc2;
public:
	int menuPrincipal();
	void menuOpciones();
	void menuCampeones();
	//Agregar campeones
	void agregarCampeones();
	bool grabarCampeon(Campeon reg);
	Campeon leerCampeon();
	void mostrarCampeon(Campeon reg);
	
};
