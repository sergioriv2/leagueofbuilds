#pragma once


class Menu_Desarrollador
{
private:
	int opc, opc2;
public:
	int menuPrincipal();
	void menuOpciones();
	void menuCampeones();
	
	void agregarCampeones();
	void mostrarCampeones();
	void modificarCampeon();
	void eliminarCampeon();
};
