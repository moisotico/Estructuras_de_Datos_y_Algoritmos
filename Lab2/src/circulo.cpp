#include "../include/circulo.h"

#define PI 3,14159265358

using namespace std;

int circulo::num_circulos = 0;

circulo::circulo(double radio, int id, string nombre, string color ){

	this->id = id;
  	circulo::num_circulos += 1;
	this->radio = radio;
	this->area = 0;
	this->peri = 0;
	this->name = nombre;
	this->color = color;
	circle.setRadius(this->radio);
	circle.setPosition (150,200);
}

circulo::~circulo()
{

}

void circulo::info()
{
    cout << "radio:"<< this->radio <<"area: "<< this->area << "perimetro: "<<this->peri<<endl;

}


sf::CircleShape circulo::dibujar(sf::RenderWindow *rW){

	circle.setFillColor(sf::Color::Red);

  return circle;
}

void circulo::c_area()
{
	this->area = PI * (this->radio * this->radio);
}

void circulo::perimetro()
{
	this->peri = 2*PI*this->radio;
}
