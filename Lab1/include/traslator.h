#include <iostream>


class Traslator
{
	public:

		/**  @brief Función utilizada para llamar al constructor de Traslator.
		**/
		Traslator();

		/**  @brief Función utilizada para llamar al destructor de Traslator.
		**/
		~Traslator();

		/** @brief Función sobrecargada traslate , la cual recibe cadenas de
		* codones, y con un string de parametro, recibido del archivo de entrada,
		* escribe sobre result el aminoácido o parada correspondientes.
		*@param s: String que recibe translate para traducir a aminoácido
		**/
		std::string traslate(std::string s);

		/** @brief Función sobrecargada, la cual recibe un puntero string, recibido del archivo
		* de entrada, escribe sobre result el aminoácido o parada correspondientes.
		*@param s: String que recibe translate para traducir a aminoácido
		**/
		std::string* traslate(std::string *s);

		//declaración del result, el cual guarda el aminoáciod o parada.
		std::string result;


	private:
		//parametros privados
		int cut;
		std::string sub;


};



