// pair::pair example

#include <iostream>


#include "../include/fileutil.h"
#include "../include/traslator.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << argc << endl;
	if( argc < 3 ){
		cout << "\033[1;31m ERROR \033[0m\n" << endl;
		cout << "debe pasar dos argumentos: archivo de entrada y archivo de salida" << endl;
		cout << "saliendo del programa " << endl;
		return -1;
	}

    FileUtil *file = new FileUtil(argv[1], argv[2]);
	Traslator *tras = new Traslator();
 
    int i;
	file->read();
    string *patron =  file->readLines();
    
    cout << "scanning: " << *patron << endl;
	string *result = tras->traslate( patron );
	cout << "ahora pasmos patron por valor: " << endl;
    
	/* descomentar si se quiere verificar el método sobrecargado para
	 *  un argumento pasado por valor
	 * */
	 
	//string result2 = tras->traslate( *patron );
	
	file->write( result ); //paso por puntero
	
	/* descomentar si se quiere verificar el método sobrecargado para
	 *  un argumento pasado por valor
	 * */
	 
	//file->write( result2 ); //paso por valor

	delete file;
	delete tras;
    return 0;
}
