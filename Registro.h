#pragma once

class Registro {
public:
	virtual bool Modificar(int ID) = 0;
	virtual bool BajaVirtual(int ID) = 0;
	virtual bool Cargar() = 0;
	virtual void Mostrar() = 0;
	virtual int getSize() = 0;//DEVUELVE EL SIZEOF DEL OBJETO
	virtual Registro& operator = (Registro*) = 0;//SOBRECARGA PARA ASIGNAR UN PUNTERO REGISTRO A UNA REFERENCIA A UN OBJETO DE UNA CLASE DERIVADA DE REGISTRO
	virtual bool comparaID(Registro*) = 0;// SE SUPONE QUE CADA CLASE TIENE UNA PROPIEDAD QUE
};                                      // IDENTIFICA A CADA OBJETO (UN PROPIEDAD CLAVE)
   //COMO ESA IDENTIFICACION UNICA (ID) PUEDE SER DE DISTINTO TIPO SE DEBE HACER UN METODO
	//PARA COMPARAR EL VALOR DE LA PROPIEDAD CLAVE ENTRE DISTINTOS OBJETOS



