//analisis del tiempo
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include "../include/Decompressor.h"

using namespace std;
int main(int argc, char const *argv[]) {
    //número de argumentos
    if (argc > 2){
        cerr << "Modo de uso: decomp [archivo_comprimido.txt] >> archivo_Descomprimido.txt  " << endl;
        //sale del programa
        return 0;
    }

    Decompressor decomp;

    clock_t inicio = clock();
    //necesario primer argumento como tamaño de archivo
    int decomp_size = decomp.DecompFile(argv[1]);
    clock_t final = clock();
    double tiempo_sim = (final - inicio)* 1000000 / CLOCKS_PER_SEC;
    if(decomp_size != -1){
        cerr << "Tamaño de archivo comprimido: " << decomp.getCompSize() << " bytes" << endl;
        cerr << "Tamaño de archivo descomprimido: " << decomp_size <<" bytes" << endl;

        float compre = roundf( ( (float)decomp_size /(float)decomp.getCompSize() ) * 100);
        cerr << "Tiempo de duración: " << tiempo_sim << " ms"<< endl;
        cerr << "Descompresión: " << compre << "%" << endl;

    }

    return 0 ;
}
