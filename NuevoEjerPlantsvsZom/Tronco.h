#pragma once
#include"Entidad.h"

class Tronco:public Entidad
{
private:


public:
	Tronco(int W, int H) {

		this->W = W;
		this->H = H;

		x = 400 + rand() % 6;
		y = 1 + rand() % 400;

	}
	~Tronco(){}

	void dibujars(Graphics^ gr, Bitmap^ bmp) {

		gr->DrawImage(bmp, x, y, W * 0.3, H * 0.3); 
	}

	Rectangle getRectangles() {

		return Rectangle(x, y, W * 0.3, H * 0.3);

	}

};

