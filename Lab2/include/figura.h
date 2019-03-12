#ifndef _FIGURA_
#define _FIGURA_

#include <iostream>


class figura
{
	public:
	/**  @brief función virtual c_area utilizada para llamar a la función
	 * de area debida a la hora de correr el programa.
	**/
				virtual void c_area()     = 0;

	/**  @brief funciónes virtuales c_area utilizada para llamar a la función
	 * de perímetro debida a la hora de correr el programa.
	**/
				virtual void perimetro()  = 0;

	/**  @brief funciónes virtuales c_area utilizada para llamar a la
	 * identificacíon la hora de correr el programa.
	**/
			  virtual void info()       = 0;

				//parametros a heredar
        std::string name,
                    color;
        int         id;

};

#endif
