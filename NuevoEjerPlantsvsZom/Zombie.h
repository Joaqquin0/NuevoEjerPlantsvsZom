#pragma once
#include"Entidad.h"

class Zombie:public Entidad
{
private:

	int vidas;
	char direccion; 
	char ganaste;

public:

	Zombie(int W, int H, int vida) {
		
		x = 700;
		this->W = W;
		this->H = H;
		this->vidas = vida;
		dx = dy = 10;
		direccion = 'S';
	}
	~Zombie(){}

	void mover(Graphics^ gr, char Tecla ) {
	
		switch (Tecla)
		{
		case 'A':

			if (x+dx > 0) {

				x -= dx;
				indiceH = 3;
				direccion = 'A';
			}
			else
			{
				ganaste = 'g';
			}
			break;

		case 'D':

			if (x + W+ dx < gr->VisibleClipBounds.Width) {

				x += dx;
				indiceH = 1;
				direccion = 'D';

			}
			break;

		case 'W':

			if (y > 0) {

				y -= dy;
				indiceH = 0;
				direccion = 'W';
			}

			break;

		case 'S':

			if (y + H + dy< 790) {

				y += dy;
				indiceH = 2;
				direccion = 'S';

			}
			break;

		}


		indiceW++;
		if (indiceW > 3)
		{
			indiceW = 0;
		}


	}

	char getdireccion() { return direccion; }
	int gethp() { return vidas; }
	void perdervidas() { vidas--; }
	char getganaste() { return ganaste; }


};

