#pragma once
#include"Bala.h"
#include"Planta.h"
#include"Zombie.h"
#include"Tronco.h"
#include"Bonus.h"


using namespace std;

class Controlador
{
private:

	vector<Planta*>* arrP;
	vector<Tronco*>* arrT;
	Zombie* zombi;
	Tronco* tronco;
	vector<Bonus*>* bonus;
	vector<Bala*>* arrB;
	bool dispara= true;

public:
	Controlador(Bitmap^ bmpzombie, Bitmap^ bmptronco,int vidas) {

		arrP = new vector<Planta*>();
		arrT = new vector<Tronco*>();

		arrB = new vector<Bala*>();

		zombi = new Zombie(bmpzombie->Width / 4, bmpzombie->Height/4, vidas);

		bonus = new vector<Bonus*>();
		
		/*arrT->push_back(new Tronco(bmptronco->Width, bmptronco->Height));*/
		
		for (int i = 0; i < 5; i++)
		{
			arrT->push_back(new Tronco(bmptronco->Width, bmptronco->Height));
		}
			
		
		for (int i = 0; i < 4; i++)
		{
			bonus->push_back(new Bonus());
		}


			
	}
	~Controlador(){}

	void agregarplanta(Bitmap^ bmpplanta) {


		for (int i = 0; i < 7; i++)
		{
			arrP->push_back(new Planta(bmpplanta->Width / 8, bmpplanta->Height));
		}
			
		
	}

	void agregarbalas(Bala* obl) {

		arrB->push_back(obl);

	}

	void dibujartodo(Graphics^ gr, Bitmap^ bmpzombie, Bitmap^ bmpplanta, Bitmap^ bmptronco) {

		for (int i = 0; i < arrP->size(); i++)
		{
			arrP->at(i)->dibujar(gr, bmpplanta);
		}

		for (int i = 0; i < arrB->size(); i++)
		{
			arrB->at(i)->dibujar(gr);
		}


		for (int i = 0; i < bonus->size(); i++)
		{
			bonus->at(i)->dibujarelipse(gr);
		}

		for (int i = 0; i < arrT->size(); i++)
		{
			arrT->at(i)->dibujars(gr, bmptronco);
		}

	

		zombi->dibujar(gr, bmpzombie);

		//bonus->dibujarelipse(gr);

	}

	void movertodo(Graphics^ gr) {

		for (int i = 0; i < arrP->size(); i++)
		{
			arrP->at(i)->mover(gr);
		}

		for (int i = 0; i < arrB->size(); i++)
		{
			arrB->at(i)->mover(gr);
		}


	}

	Zombie* getzombie() { return zombi; }

	void colision(Graphics^ gr) {

		//colision zombi planta
		
		for (int i = 0; i < arrP->size(); i++)
		{
			if (zombi->getRectangle().IntersectsWith(arrP->at(i)->getRectangle()))
			{
				zombi->setx(700);
				zombi->sety(50);
				zombi->perdervidas();
			}
		}

		//bonus con persona

		for (size_t i = 0; i < bonus->size(); i++)
		{
			if (zombi->getRectangle().IntersectsWith(bonus->at(i)->getRectangle()))
			{
				bonus->at(i)->setvisible(false);
				dispara = false;
			}

		}

		//balas con plantas

		for (int i = 0; i < arrP->size(); i++)
		{
			for (int j = 0; j < arrB->size(); j++)
			{
				if (arrP->at(i)->getRectangle().IntersectsWith(arrB->at(j)->getRectangle()))
				{ 
					arrP->at(i)->setvisible(false);
					arrB->at(j)->setvisible(false);
				}
			}

		
		}

		//bloque choca con zombi

		for (int i = 0; i < arrT->size(); i++)
		{
			if (zombi->getRectangle().IntersectsWith(arrT->at(i)->getRectangles()))
			{
				zombi->setx(700);
				zombi->sety(50);
			}
		}


		////si la bala toca con un extremo desaparece
		//for (int i = 0; i < arrP->size(); i++)
		//{
		//	if (arrP->at(i)->gety() <= 10)
		//	{
		//		arrP->at(i)->setvisible(false);
		//	}
		//}

		//borrar del arreglo

		for (int i = 0; i < arrP->size(); i++)
		{
			if (!arrP->at(i)->getvisible())
			{
				arrP->erase(arrP->begin() + i);
			}
		}

		for (int i = 0; i < arrB->size(); i++)
		{
			if (!arrB->at(i)->getvisible())
			{
				arrB->erase(arrB->begin() + i);
			}
		}

		for (int i = 0; i < bonus->size(); i++)
		{
			if (!bonus->at(i)->getvisible())
			{
				bonus->erase(bonus->begin() + i);
			}
		}
	}


	bool getdispara() { return this->dispara; }

};

