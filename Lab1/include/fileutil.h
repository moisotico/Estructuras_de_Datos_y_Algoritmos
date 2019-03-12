#include <fstream> ///< requerido para declaración del atributo infile


class FileUtil
{
	//Atributos publicos
	public:

	/**  @brief Función utilizada, para llamar al constructor de FileUtil
	* @param s: String del path de entrada del archivo con la cadena de codones
	* a convertir.
	* @param oname: path del archivo de salida, dónde se guardan los aminoácidos.
	**/
		FileUtil(std::string s, std::string oname);

	/**  @brief Función utilizada para llamar al destructor de FileUtil
	**/
		~FileUtil();

	/**  @brief abre el archivo
	**/
		std::string read();

	/**  @brief Función utilizada para leer el archivo línea por línea y
	* adjuntarlo a un string, el cual es retornado.
	**/
		std::string* readLines();

	/**  @brief Función utilizada para escribir sobre el archivo de salida.
	* @param s: String a escribir sobre el archivo de salida.
	**/
		int write(std::string s);

	/**  @brief Función sobrecargada utilizada para escribir sobre el archivo de salida.
	* @param *s: Puntero a escribir sobre el archivo de salida.
	**/
		int write(std::string *s);

		//declaración de strings
		std::string iFileName,
					oFileName;
		std::string out_data;

	//Atributos privados
	private:

	    std::string input_data;

			// declaración de clases ifstream y ofstream
			std::ifstream infile;
	    std::ofstream outfile;
};
