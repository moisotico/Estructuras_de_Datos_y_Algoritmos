#include <iostream>
#include <sstream>
#include <fstream>

#include "../include/LenEnc.h"

using namespace std;

LenEnc::LenEnc(){
  std::cout << "Compresion utilizando algoritmo Run Length"<< std::endl;
}

LenEnc::~LenEnc(){
}


void LenEnc::encoding(const std::string &filename){
    
  ifstream file ( filename.c_str() );
  string rawData = string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  streampos size = file.tellg();
  cout << "ORIGINAL FILE SIZE: "<< size <<endl;
    
  int rLen;
  
  clock_t inicio = clock();// Mdición del tiempo de ejecución
  
  
  int len = rawData.size(); // tamaño total del string rawData a comprimir
  std::string dest;         // donde guardar los resultados
  std::string::iterator it; // iterador del string
  // Guardamos datos comprimidos en un archivo de salida
  ofstream outputFile;
  outputFile.open(filename + ".rlen");
  
  // recorremos todo el string
  for(it= rawData.begin(); it != rawData.end(); it++)
  {
    //asignamos el primer caracter al resultado
    dest += *it;
    rLen = 1;   
    // mientras el caracter asignado este repetido incrementamos contador de repeticiones
    // y actualizamos el iterador
    while( ( *it == *(it+1) )  && ( it != rawData.end()) )
    {
      rLen++;
      it++;
    }   
    //optamos por añadir el numero de repeticiones solo si el caracter se repite dos o más veces
    if(rLen > 1) 
      dest.append( std::to_string(rLen) );

  }  
  outputFile<<dest;
  outputFile.close();
  
  clock_t final = clock();
  double tiempo_sim = (final - inicio)*1000/ CLOCKS_PER_SEC;

  cout<<"se finalizo la compresión"<<endl;
  cout<<"el tiempo total de compresión de un archivo de  "<< len << " bytes fue de: "<<tiempo_sim<<" milisegundos"<<endl;

}

void LenEnc::decoding(const std::string &filename){

  ifstream file ( filename.c_str() );
  string compressData = string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  std::string result;       // almacena el texto que resulta de la descompresion
  std::string::iterator it; // terador
 clock_t inicio = clock();

  streampos size = file.tellg();
  cout << "RUN LENGTH - COMPRESSED FILE SIZE: "<< size <<endl;
  
  ofstream outputFile;
  outputFile.open(filename + "_uncompressed");
  
  // recorremos todo el string que contiene el texto comprimido
  for( it = compressData.begin(); it != compressData.end(); it++ ){
    // buscamos caracteres númerico que indiquen la cantidad de veces que se repite
    // el caracter anterior
    int num = (int)*it;
    std::string count = "";
    count += *it;
    //count += *(it+1);
    //std::cout << count << std::endl;
    // evaluamos sea un numero en ASCII
    if( num >48 && num<58 ){
      int i_dec = std::stoi (count);
      while(i_dec > 1){
        //se añaden los caracteres repetidos al resultado
        result += *(it-1);
        // actualizamos contador de rpeticiones
        i_dec--;
      }
      // el caracter no equivale a un caracter numerico en ASCII de modo que se añade por defecto al string result
    }else{
      result += *it;
    }
  }
  outputFile<<result;
  outputFile.close();
  clock_t final = clock();
  double tiempo_sim = (final - inicio)*1000/ CLOCKS_PER_SEC;

  cout<<"se finalizo la descompresión"<<endl;
  cout<<"el tiempo total de descompresión de un archivo de  "<< size << " bytes fue de: "<<tiempo_sim<<" milisegundos"<<endl;
}

