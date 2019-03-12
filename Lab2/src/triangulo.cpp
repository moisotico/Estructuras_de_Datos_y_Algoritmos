#include <math.h>
#include "../include/triangulo.h"

using namespace std;

int triangulo::num_triangulos = 0;

triangulo::triangulo(double lado,  int id, string nombre, string color){

	this->id = id;
  triangulo::num_triangulos += 1;
	this->lado = lado;
	this->area = 0;
	this->peri = 0;
	this->name = nombre;
	this->color = color;
	tri.setRadius (float(0.66 * this->lado));
	tri.setPointCount(3);

}

triangulo::~triangulo()
{

}

void triangulo::info()
{
	cout << "largo"<< this->lado <<"area: "<< this->area << "perimetro: "<<this->peri<<endl;

}

void triangulo::c_area()
{

	this->area = (sqrt(3)/4) * this->lado * this->lado;
}

void triangulo::perimetro()
{

	this->peri = 3 * this->lado;
}

sf::CircleShape triangulo::dibujar(sf::RenderWindow *rW){
		tri.setFillColor(sf::Color::Green);
		return tri;
}
