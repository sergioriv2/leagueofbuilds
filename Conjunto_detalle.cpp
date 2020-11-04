#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include "Conjunto_detalle.h"


void Conjunto_detalle::setDetalle() {
	idDetalle = contarRegistros();
}
void Conjunto_detalle::setidConjunto(int idConjunto) {
	this->idConjunto = idConjunto;
}
void Conjunto_detalle::setitemsEarly() {
	std::cout << "Ingresar ID de items early game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idEarly[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}
void Conjunto_detalle::setItemsMid() {
	std::cout << "Ingresar ID de items mid game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cin >> idMid[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}
void Conjunto_detalle::setItemsLate() {
	std::cout << "Ingresar ID de items late game(-1 Para finalizar): " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cin >> idLate[i];
		if (idEarly[i] == -1) {
			return;
		}
	}
}

int Conjunto_detalle::contarRegistros() {
	{
		Conjunto_detalle conj;
		FILE* pf;
		int c = 0;
		pf = fopen("resources/conjuntos/conjunto_detalle.dat", "rb");
		if (pf == NULL)
		{
			return 0;
		}
		while (fread(this, sizeof (*this), 1, pf) == 1) c++;
		fclose(pf);
		return c;
	}
}

