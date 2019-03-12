#ifndef _RECTANGULO_
#define _RECTANGULO_

#include <SFML/Graphics.hpp>
#include "figura.h"

class rectangulo: public figura
{
	public:

				/** @brief Función utilizada para llamar al constructor de la clase
				* rectangulo.
				* @param lado1: Tamaño del largo del rectangulo.
				* @param lado2: Tamaño del ancho del rectangulo.
				* @param id: numero que identifica a la instancia.
				* @param nombre: nombre de la instancia.
				* @param color: color del rectángulo, se muestra en la consola cuando
				* corre el ejecutable.
				**/
        rectangulo( double lado1, double lado2, int id, std::string nombre, std::string color );

				/** @brief Función la cual llama al destructor de rectangulo.
				**/
        ~rectangulo();

				/** @brief Función heredada, para llamar al método que calcula el área
				* del rectangulo.
				**/
        void c_area();

				/** @brief Función heredada, para calcular el perímetro del rectangulo,
				* multiplicando lado por lado.
				**/
        void perimetro();

				/** @brief Función heredada, para imprimir la info del rectangulo a través
				* de los parámetros miembros de la clase.
				**/
        void info();

				/** @brief Función utilizada, para llamar al metodo que  dibuja el
				* rectángulo.
				* @param *rW : puntero tipo RenderWindow en referencia a la clase del
				* mismo nombre.
				**/
				sf::ConvexShape dibujar(sf::RenderWindow *rW);

				//declaración del objeto de la clase ConvexShape.
				sf::ConvexShape rect;

		/** @brief Función operador, para sobreescribir el simbolo ~.
		**/
		void operator ~(){
			std::cout << "nombre: "<<this->name <<" - color: "<<this->color<<" - lado1: "<<this->lado1<<" - lado2: "<<this->lado2<<std::endl;
		}

		/** @brief Función operador, para sobreescribir el simbolo !.
		**/
		void operator !(){
			std::cout << "area: "<<this->area <<" - perimetro: "<<this->peri<<std::endl;
		}

		/** @brief metodo operador para un pointer de tipo rectangulo (clase), para
		* sobreescribir el simbolo =.
		* @param rectangulo *t: un pointer que no modifica sus valores, para la
		* lectura.
		**/
        rectangulo* operator=(const rectangulo *t)
        {
            if(this != t){
                this->id = t->id;
                this->lado1 = t->lado1;
                this->lado2 = t->lado2;
                this->name = t->name;
                this->color = t->color;
                this->peri = t->peri;
                this->area = t->area;
            }
            return this;
        }

			/** @brief metodo get_num_rectangulos para obtener el numero de instancias
			 de la clase rectangulo.
			**/
       inline int get_num_rectangulos(){

            return rectangulo::num_rectangulos;
        }

        static int num_rectangulos;

	//atributos privados heredados.
	private:
        double area,
            lado1,
            lado2,
            peri;
};
#endif
