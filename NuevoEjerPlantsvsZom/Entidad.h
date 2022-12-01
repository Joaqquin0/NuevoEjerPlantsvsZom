#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<cmath>
#include<time.h>

using namespace System;
using namespace System::Drawing;

class Entidad
{
protected:

	int x, y, dx, dy, indiceW, indiceH, W, H;
	bool visibilidad;

public:
	Entidad(){
	
		this->W = 0;
		this->H = 0;

		visibilidad = true;
		x =  y =  dx = dy = 0;
		indiceW = indiceH = 0;

	}

	~Entidad(){}

	void dibujar(Graphics^ gr, Bitmap^ bmp) {
		//porcion del sprite a mostrar
		Rectangle porcionSprite = Rectangle(indiceW * W, indiceH * H, W, H);
		//porsicon donde se mostrara el sprote , modificar tamano
		bmp->MakeTransparent(bmp->GetPixel(1, 1)); // transparencia
		Rectangle zoom = Rectangle(x, y, W * 0.5, H * 0.5); //multiplicar w y h para cambiar tamano
		//dibujar
		gr->DrawImage(bmp, zoom, porcionSprite, GraphicsUnit::Pixel);

	}

	virtual void mover(Graphics^gr){}
	

	//colision

	Rectangle getRectangle() {

		return Rectangle(x, y, W * 0.5, H * 0.5);

	}

	int getX() { return this->x; }
	int gety() { return this->y; }

	void setx(int X) { this->x = X; }
	void sety(int Y) { this->y = Y; }

	void setvisible(bool c) { this->visibilidad = c; }
	bool getvisible() { return visibilidad; }

};
