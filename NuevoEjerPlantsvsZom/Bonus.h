#pragma once
#include"Entidad.h"

class Bonus :public Entidad
{
private:

	int radio;

public:
	Bonus() {

		Random k,l;
		x =   400 + rand() % 600;
		y = 5 + rand() % 400;
		radio = 10;

	}
	~Bonus() {}

	void dibujarelipse(Graphics^ gr) {

		SolidBrush^ b = gcnew SolidBrush(Color::Red);
		gr->FillEllipse(b, x, y, radio, radio);


	}

	Rectangle getRectangle() { //para colision

		return Rectangle(x, y, radio, radio);

	}

	int getx() { return x; }
	int gety() { return y; }
	int getradio() { return radio; }

};

