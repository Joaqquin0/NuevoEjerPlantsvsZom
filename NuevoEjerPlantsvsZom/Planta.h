#pragma once
#include"Entidad.h"

class Planta:public Entidad
{
private:

public:

	Planta(int W, int H) {

		this->W = W;
		this->H = H;

		Random r, j;
		x = 3 + rand() % 400;
		y = 3 + rand() % 400;;
		dx = dy = 10;

	}

	~Planta(){}

	void mover(Graphics^ gr) {

		if (y+dy<0 || y+dy+H>gr->VisibleClipBounds.Height)
		{
			dy *= -1;
		}if (dy>0)
		{
			indiceW = 7;

		}
		else
		{
			indiceW = 6;
		}
		y += dy;
	}




};

