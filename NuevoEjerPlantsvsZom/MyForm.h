#pragma once
#include"Controlador.h"
#include"Archivo.h"

namespace NuevoEjerPlantsvsZom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//
			srand(time(NULL));

			gr = this->CreateGraphics();
			ct = BufferedGraphicsManager::Current;
			buffer = ct->Allocate(gr, this->ClientRectangle);

			bmpzombi = gcnew Bitmap("imagenes\\zombi.png");
			bmpplanta = gcnew Bitmap("imagenes\\plantas.png");
			bmptronco = gcnew Bitmap("imagenes\\bloque.png");
			bmpmapa = gcnew Bitmap("imagenes\\fondo.png");
			archivo = new File();
			archivo->leerdatos();
			controlador = new Controlador(bmpzombi,bmptronco, archivo->getvida());
			controlador->agregarplanta(bmpplanta);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		//buffers
		Graphics^ gr;
		BufferedGraphicsContext^ ct;
		BufferedGraphics^ buffer;

		Bitmap^ bmpmapa;
		Bitmap^ bmptronco;
		Bitmap^ bmpzombi;
		Controlador* controlador;
		Bitmap^ bmpplanta;
		File* archivo;
	

	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Timer^ timer1;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(513, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 490);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		buffer->Graphics->DrawImage(bmpmapa, 0, 0, bmpmapa->Width , bmpmapa->Height );

		controlador->colision(buffer->Graphics);

		controlador->dibujartodo(buffer->Graphics, bmpzombi, bmpplanta, bmptronco);
		
		controlador->movertodo(buffer->Graphics);



		label1->Text = "Vidas" + Convert::ToString(controlador->getzombie()->gethp());
		if (controlador->getzombie()->gethp()<=0)
		{
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();

		}
		else if (controlador->getzombie()->getganaste() == 'g')
		{
			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			this->Close();
		}

		//render
		buffer->Render(gr);
	
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		switch (e->KeyCode)
		{
		case Keys::A:

			controlador->getzombie()->mover(buffer->Graphics, 'A');
			//controlador->getZombie()->mover(buffer->Graphics, 'A');
			break;

		case Keys::S:

			controlador->getzombie()->mover(buffer->Graphics, 'S');
			break;

		case Keys::D:

			controlador->getzombie()->mover(buffer->Graphics, 'D');
			break;

		case Keys::W:

			controlador->getzombie()->mover(buffer->Graphics, 'W');
			break;

		case Keys::Space:

			if (controlador->getdispara()==false)
			{
				Bala* balas = new Bala(controlador->getzombie()->getX(), controlador->getzombie()->gety(), controlador->getzombie()->getdireccion());
				controlador->agregarbalas(balas);
			}


		}
		


	
	}

private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

	

}
};
}
