//analisis del tiempo
#include <ctime>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../include/Compressor.h"

using namespace std;

int main(int argc, char* argv[]){
	int flag = 0;
	int N = -1;
	int L = -1;
	int S = -1;
	if(flag == -1){
		cerr << "Modo de uso: comp [archivo_texto.txt] >> archivo_comprimido.txt " << endl;
	}
	Compressor compressor;
	clock_t inicio = clock();
	int compressed_filesize =  compressor.CompressFile(argv[argc - 1]);
	clock_t final = clock();
	double tiempo_sim = (final - inicio)* 1000000 / CLOCKS_PER_SEC;
	if(compressed_filesize == -1){
		return 0;
	}

	ifstream orig(argv[argc - 1], ifstream::ate | ifstream::binary);
	int comp_size = orig.tellg();

	cerr << "Tamaño de archivo sin comprimir: " << comp_size <<" bytes" << endl;
	cerr << "Tamaño de archivo comprimido: " << compressed_filesize << " bytes" << endl;

	float compre_tot = roundf( ((float)compressed_filesize / comp_size) * 100);

	cerr << "Tiempo de duración: " << tiempo_sim << " ms"<< endl;
	cerr << "Compresión: " <<  compre_tot << "%" << endl;

	return 0;
}
