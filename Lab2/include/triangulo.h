#ifndef _TRIANGULO_
#define _TRIANGULO_

#include "figura.h"
#include <SFML/Graphics.hpp>

class triangulo: public figura
{
	public:
				/** @brief Función utilizada para llamar al constructor de la clase
				* triangulo.
				* @param lado: Tamaño del lado del triangulo equilátero.
				* @param id: numero que identifica a la instancia.
				* @param nombre: nombre de la instancia.
				* @param color: color del triangulo, se muestra en la consola cuando
				* corre el ejecutable.
				**/
        triangulo(double lado, int id, std::string nombre, std::string color);

				/** @brief Función utilizada para llamar al destructor de triangulo.
				**/
				~triangulo();

				/** @brief Función heredada, para llamar al método que calcula el área
				* del triangulo. Toma en cuenta la mitad del lado y la altura mediante
				* el método de Pitágoras.
				**/
        void c_area();

				/** @brief Función heredada, para calcular el perímetro del triangulo.
				**/
				void perimetro();

				/** @brief Función heredada, para imprimir la info del triangulo a través
				* de los parámetros miembros de la clase.
				**/
				void info();

				/**utlizamos la claase circle shape para hacer un polígono simple con su distancia
				al centro igual al "radio" para CircleShape.**/
				sf::CircleShape tri;

				/** @brief Función utilizada, para llamar al metodo que  dibuja el
				* triángulo.
				* @param *rW : puntero tipo RenderWindow en referencia a la clase del
				* mismo nombre.
				**/
				sf::CircleShape dibujar(sf::RenderWindow *rW);

		/** @brief Función operador, para sobreescribir el simbolo ~.
		**/
		void operator ~(){
			std::cout << "nombre: "<<this->name <<" - color: "<<this->color<<" - lado "<<this->lado<<std::endl;
		}

		/** @brief Función operador, para sobreescribir el simbolo !.
		**/
		void operator !(){
			std::cout << "area: "<<this->area <<" - perimetro: "<<this->peri<<std::endl;
		}

				/** @brief metodo operador para un pointer de tipo triangulo( su clase), para
				* sobreescribir el simbolo =.
				* @param triangulo *t: un pointer que no modifica sus valores, para la
				* lectura.
				**/
        triangulo* operator=(const triangulo *t)
        {
            if(this != t){
                this->id = t->id;
                this->lado = t->lado;
                this->name = t->name;
                this->color = t->color;
                this->peri = t->peri;
                this->area = t->area;
            }
            return this;
        }

				/** @brief metodo get_num_triangulos para obtener el numero de instancias
				 de la clase triangulo.
				**/
        inline int get_num_triangulos(){

            return triangulo::num_triangulos;
        }

        static int num_triangulos;


	private:
				//atributos privados
        double  area,
				lado,
				peri;

};
#endif
