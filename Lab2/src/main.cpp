
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/figura.h"
#include "../include/circulo.h"
#include "../include/rectangulo.h"
#include "../include/triangulo.h"


using namespace std;

int main(int argc, char *argv[])
{

   sf::RenderWindow *rW = new sf::RenderWindow(sf::VideoMode(720, 480), "lab2");
    // circulo(double radio, int id, std::string nombre, std::string color)
    circulo *c1 = new circulo( 2.0, 25, "primer_circulo", "Blue");
    circulo *c2 = new circulo(120.0, 45, "segundo_circulo", "Green");


    rectangulo r1(135.5, 185.78, 20, "rec1", "Pink"    );
    rectangulo r2(25.2, 32.5, 50, "rec2", "Black");

                //double lado,  int id, string nombre, string color
    triangulo t1(150.25,  1, "triangulo1", "Orange");
    triangulo t2(25,  2, "triangulo2", "Pink");
    triangulo t3(985.005, 3, "triangulo3", "Black");



    r1.c_area();
    r1.perimetro();
    !r1;// imprime area y perimetro
    ~r1;//imprime caracteristicas del objeto
    r2 = r1;
    !r2;
    ~r2;

    c1->c_area();
    c2->c_area();
    c2->perimetro();
    c1->perimetro();

    ~(*c1);
    !(*c1);
    ~(*c2);
    !(*c2);
    c1 = c2;
    ~(*c1);
    ~(*c1);
    !(*c1);

    t1.c_area();
    t1.perimetro();
    t2.c_area();
    t2.perimetro();
    ~t1;
    ~t2;
    !t2;
    !t1;

    cout << "número de instancias círculos: " << c1->get_num_circulos() << endl;
    cout << "número de instancias triángulos: " << t2.get_num_triangulos() << endl;
    cout << "número de instancias rectángulos: " << r2.get_num_rectangulos() << endl;


  //  c2->dibujar(rW1);
    while (rW->isOpen())
  	{
  		sf::Event event;
  		while (rW->pollEvent(event))
  		{
  				if (event.type == sf::Event::Closed)
  						rW->close();
  		}

  		rW->clear();
  		rW->draw(r1.dibujar(rW));
      rW->draw(c2->dibujar(rW));
      rW->draw(t1.dibujar(rW));
  		rW->display();
  	}


    delete rW;

    /* IMPORTANTE, debido a la instruccion :
     *                                          c1=c2
     * se utiliza un solo delete, ya que al hacer la copia de objeto c2 en c1, ambos punteros c1 y c2 apuntaran
     * a la misma dirección de memoria, por ello se aplica delete unicamente a c1
     * esto hara que se libere la  memoria asignada
     * **/

    delete c1;

}
