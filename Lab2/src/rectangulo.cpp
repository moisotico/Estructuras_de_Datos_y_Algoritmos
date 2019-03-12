	#include "../include/rectangulo.h"


	using namespace std;

	int rectangulo::num_rectangulos = 0;

	rectangulo::rectangulo( double lado1, double lado2, int id, std::string nombre, std::string color )
	{

		this->id = id;
		this->lado1 = lado1;
		this->lado2 = lado2;
		this->area = 0;
		this->peri = 0;
		this->name = nombre;
		this->color = color;
		this->rect.setPointCount(4);
	    rectangulo::num_rectangulos += 1;

	}

	rectangulo::~rectangulo()
	{

	}

	void rectangulo::info(){

	    cout << "lado 1 y 2:"<< this->lado1 <<"| "<<this->lado2<<"area: "<< this->area << "perimetro: "<<this->peri<<endl;

	}

	void rectangulo::c_area()
	{

		this->area = this->lado1 * this->lado2;
	}

	void rectangulo::perimetro()
	{

		this->peri = 2*(this->lado1 + this->lado2);
	}

	sf::ConvexShape rectangulo::dibujar(sf::RenderWindow *rW){

		rect.setPoint(0, sf::Vector2f(400,125));
		rect.setPoint(1, sf::Vector2f(400+this->lado1, 125));
		rect.setPoint(2, sf::Vector2f(400+this->lado1, 125+this->lado2));
		rect.setPoint(3, sf::Vector2f(400, 125+this->lado2));
		rect.setFillColor(sf::Color(20, 125, 250));

	  return rect;
	}
