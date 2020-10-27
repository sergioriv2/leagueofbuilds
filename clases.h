#pragma once

class Menu
{
private:
	RenderWindow* ventana;
	int resolucionAncho;
	int resolucionAlto;
	Text titulo;
	Font fuente;
	RectangleShape botones[2];
public:
	Menu(int _resAlto = 600, int _resAncho = 800);

	void setOffsetTitulo(float x = 250, float y = 10, int chSize = 30);

	~Menu();

};


class Items
{
private:
	RectangleShape rectangulo;
	Texture textura;
	Vector2u sizeTex;
public:
	Items()
	{
		rectangulo.setSize(Vector2f(64.0f, 64.0f));
		textura.loadFromFile("resources/items_iniciales.png");
		sizeTex = textura.getSize();
		sizeTex.x /= 4;
		sizeTex.y /= 1;

		rectangulo.setTexture(&textura);
		rectangulo.setTextureRect(IntRect(sizeTex.x * 3, sizeTex.y * 0, sizeTex.x, sizeTex.y));
	}

	RectangleShape getRectangulo() 
	{ 
		return rectangulo; 
	}
};


