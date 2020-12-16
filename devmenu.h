#pragma once

class Menu_Desarrollador
{
private:
	int opc, opc2;
public:
	int menuPrincipal();
	void menuCampeones();
	void menuItems();
	void menuConjuntos();
	void menuBackup();
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
	//Conjuntos
	void agregarConjunto();
	void mostrarConjunto();
	void editarConjunto();
	void bajaConjunto();
	//Backup
	bool backupFiles();
	bool restoreFiles();
};