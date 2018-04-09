#include <iostream>

using namespace std;

class coordenadas {
		public:
		
		coordenadas();
		virtual ~coordenadas();
		
		int x; 
		int y;
		
		void set(int x, int y);
		void imprimir();
		void suma(int sx,int sy);
};

coordenadas::coordenadas(){
		this->x=0;
		this->y=0;
}

void coordenadas::imprimir(){
		cout << this->x << endl;
		cout << this->y << endl;
}

void coordenadas::suma(int sx,int sy){
	this->x+=sx;
	this->y+=sy;

}

void coordenadas::set(int x, int y){
	this->x=x;
	this->y=y;
}


//Clase virtual pura
class figura{
		public:
			
			figura();
			virtual ~figura();
			
			virtual void trasladar_x(int x)=0;
			virtual void trasladar_y(int y)=0;
			virtual void mostrarse()=0;
};

//Clases dependientes de Figura

class rectangulo : public figura{
		public:
			
			rectangulo(coordenadas&c1,coordenadas&c2,coordenadas&c3,coordenadas&c4);
			virtual ~rectangulo();
			
			virtual void trasladar_x(int x);
			virtual void trasladar_y(int x);
			virtual void mostrarse();
			
		private:
			 coordenadas c[4]; //Coordenadas
};

class triangulo : public figura{
		public:
			
			triangulo(coordenadas&c1,coordenadas&c2,coordenadas&c3);
			virtual ~triangulo();
			
			virtual void trasladar_x(int x);
			virtual void trasladar_y(int x);
			virtual void mostrarse();
			
		private:
			 coordenadas c[3]; //Coordenadas
};

class circulo : public figura{
		public:
			
			circulo(coordenadas&c1,int radio);
			virtual ~circulo();
			
			virtual void trasladar_x(int x);
			virtual void trasladar_y(int x);
			virtual void mostrarse();
			
		private:
			 coordenadas c1; //Coordenadas
			 int radio;
};


//Implementaciones para rectangulo
rectangulo::rectangulo(coordenadas&c1,coordenadas&c2,coordenadas&c3,coordenadas&c4){
	this->c[1]=c1;
	this->c[2]=c2;
	this->c[3]=c3;
	this->c[4]=c4;
}

rectangulo::~rectangulo(){
}

void rectangulo::mostrarse(){
	//Imprimir en pantalla
	this->c[1].imprimir();
	this->c[2].imprimir();
	this->c[3].imprimir();
	this->c[4].imprimir();
}

void rectangulo::trasladar_x(int x){
	for (int i=1; i<5; i++){
		this->c[i].suma(x,0);
	}
}

void rectangulo::trasladar_y(int y){
		for (int i=1; i<5; i++){
		this->c[i].suma(0,y);
	}
}


//Implementaciones para triangulo
triangulo::triangulo(coordenadas&c1,coordenadas&c2,coordenadas&c3){
	this->c[1]=c1;
	this->c[2]=c2;
	this->c[3]=c3;
}

triangulo::~triangulo(){
}

void triangulo::mostrarse(){
	for (int i=1; i<4; i++){
		this->c[i].imprimir();
	}
}

void triangulo::trasladar_x(int x){
	for (int i=1; i<4; i++){
		this->c[i].suma(x,0);
	}
}

void triangulo::trasladar_y(int y){
	for (int i=1; i<4; i++){
		this->c[i].suma(0,y);
	}
}

//Implementaciones para circulo

circulo::circulo(coordenadas&c1,int radio){
		this->c1=c1;
		this->radio=radio;
}

circulo::~circulo(){
}

void circulo::mostrarse(){
		this->c1.imprimir();
		cout << this->radio << endl;
}

void circulo::trasladar_x(int x){
	this->c1.suma(x,0);
}

void circulo::trasladar_y(int y){
	this->c1.suma(0,y);
}


//Clase para gestionar figuras mas facilmente

class Gestor : public figura{
	public:
		Gestor();
		virtual ~Gestor();
		
		void add_figura(figura *item);
		void remover_figura(int ind);
		void mostrarse(int id); //Estos 3 eran virtual
		void trasladar_x(int id, int x);
		void trasladar_y(int id, int y);
		
	private:
		figura figuras[5];
		int id;
};

//Implementacion del gestor

Gestor::Gestor(){
	this->id=0;
}

Gestor::~Gestor(){
}

void Gestor::add_figura(figura *item){
	//No puedo añadir si hay mas de 5 figuras 
	if (id<5){
		figuras[id]=item;	
	} else { return; }
}

void Gestor::remover_figura(int ind){
	this->id--;
	figuras[ind]=nullptr; //Paso un puntero nulo
}

void Gestor::mostrarse(int id){
	if ( (id>0)||(id<6) ){
		this->figuras[id].mostrarse();
	}
}

void Gestor::trasladar_x(int id, int x){
	if ( (id>0)||(id<6) ){
		this->figuras[id].trasladar_x(x);
	}
}

void Gestor::trasladar_y(int id, int y){
	if ( (id>0)||(id<6) ){
		this->figuras[id].trasladar_y(y);
	}
}

//Clase del menu

class Menu{
	public:
		Menu();
		virtual ~Menu();
		
		void EscribirMenu();
		char entrada();
	private:
		char caracter;
	protected:
};

Menu::Menu(){
	cout << "Menu Opcion: 1: Imprimir Figuras" << endl;
	cout << "Menu Opcion: 2: Añadir Rectangulo" << endl;
	cout << "Menu Opcion: 3: Añadir Triangulo" << endl;
	cout << "Menu Opcion: 4: Añadir Circulo" << endl;
	cout << "Menu Opcion: 5: Eliminar figura" << endl;
	char aux;
	cin >> aux;
	this->caracter=aux;
}

char Menu::entrada(){
}

//Principal del codigo

int main(){

	return 1;
}
