#ifndef _CIRCULO_
#define _CIRCULO_

#include "figura.h"
#include <SFML/Graphics.hpp>


class circulo: public figura
{
	//Atributos publicos
	public:

				/** @brief Función utilizada, para llamar al constructor de la clase
				* circulo.
				* @param radio: Tamaño del radio del circulo.
				* @param id: numero que identifica a la instancia.
				* @param nombre: nombre de la instancia.
				* @param color: color del círculo, se muestra en la consola cuando
				* corre el ejecutable.
				**/
        			circulo(double radio, int id, std::string nombre, std::string color);

				/** @brief Función utilizada, para llamar al destructor de circulo.
				**/
				~circulo();
				sf::CircleShape circle;

				/** @brief Función utilizada, para llamar al metodo que  dibuja circulo.
				* @param *rW : puntero tipo RenderWindow en referencia a la clase del
				* mismo nombre.
				**/
				sf::CircleShape dibujar(sf::RenderWindow *rW);

				/** @brief Función heredada, para llamar al método que calcula el área
				* del circulo, multiplicando el radio por si mismo y por PI, definido en
				la clase.
				**/
				void c_area();

				/** @brief Función heredada, para calcular el perímetro del circulo.
				**/
				void perimetro();

				/** @brief Función heredada, para imprimir la info del circulo a través
				* de los parámetros miembros de la clase.
				**/
				void info();

				/** @brief Función operador, para sobreescribir el simbolo ~.
				**/
        void operator ~(){
            std::cout << "nombre: "<<this->name<<" - color: "<<this->color<<" - radio: "<<this->radio<<std::endl;
        }

				/** @brief Función operador, para sobreescribir el simbolo !.
				**/
				void operator!(){
            std::cout << "area: "<<this->area <<" - perimetro: "<<this->peri<< std::endl;
        }

				/** @brief metodo operador para un pointer de tipo circulo, para
				* sobreescribir el simbolo =.
				* @param circulo *t: un pointer que no modifica sus valores, para la
				* lectura
				**/
        circulo* operator=(const circulo *t)
        {
            if(this != t){
                this->id = t->id;
                this->radio = t->radio;
                this->name = t->name;
                this->color = t->color;
                this->peri = t->peri;
                this->area = t->area;
            }
            return this;
        }
				/** @brief metodo get_num_circulos para obtener el numero de instancias
				 de la clase circulo.
				**/
        inline int get_num_circulos(){

            return circulo::num_circulos;
        }
	//valor que se mantiene hasta el final de programa
	static int num_circulos;

	private:

  			double radio,
            		area,
            		peri;

};

#endif
