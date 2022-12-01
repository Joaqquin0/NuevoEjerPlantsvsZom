#pragma once
#include"Entidad.h"

class Bala:public Entidad
{
private:

	char direccion;
	int radio;

public:
	Bala(int x, int y, int direccion) {

		this->x = x;
		this->y = y;
		this->direccion = direccion;
		dx = dy = 15;
		radio = 6;

	}
	~Bala(){}

	void dibujar(Graphics^ gr) {

		SolidBrush^ b = gcnew SolidBrush(Color::Red);
		gr->FillEllipse(b, x, y, radio, radio);

	}

	void mover(Graphics^ gr) {

		if (direccion == 'S' && y + radio <= gr->VisibleClipBounds.Height)
		{
			y += dy;
		}
		if (direccion == 'W' && y  >= 0)
		{
			y -= dy;
		}
		if (direccion == 'A' && x  >= 0)
		{
			x -= dx;
		}
		if (direccion == 'D' && x + radio <= gr->VisibleClipBounds.Width)
		{
			x += dx;
		}


	}

	Rectangle getRectangle() { //para colision

		return Rectangle(x, y, radio, radio);

	}

	int getx() { return x; }
	int gety() { return y; }
	int getradio() { return radio; }




};

