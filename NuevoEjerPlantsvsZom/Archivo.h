#pragma once

#include "Entidad.h"
using namespace std;

class File
{
private:
	ofstream escribirA;
	ifstream leerA;
	string texto;  //sacar los datos del archivo
	int vida;

public:
	File() {

	}
	~File() {}

	void leerdatos() {


		leerA.open("Configuracion.txt", ios::in); //intentas abrir el archivo
		if (leerA.fail()) {

			leerA.close();	//le el archivo, si da error lo cierra y crea uno
			//escribe el archivo 
			escribirA.open("Configuracion.txt", ios::out);
			escribirA << "10" << endl; //vida;

			escribirA.close();

			//abrimos el archivo para la lectura
			leerA.open("Configuracion.txt", ios::in);
		}

		getline(leerA, texto);
		vida = atoi(texto.c_str());


		leerA.close();


	}
	int getvida() { return vida; }



};