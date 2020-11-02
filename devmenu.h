#pragma once


class Menu_Desarrollador
{
private:
	int opc, opc2;
public:
	int menuPrincipal();
	void menuOpciones();
	void menuCampeones();
	void menuItems();
	void menuConjuntos();
	//Campeones
	void agregarCampeones();
	void mostrarCampeones();
	void modificarCampeon();
	void eliminarCampeon();
	//Items
	void agregarItems();
	void bajaItems();
	void mostrarItems();
	void editarItems();
};
