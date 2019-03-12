#include <iostream>
#include <math.h>

#include "../include/Calculadora.h"
#include "../include/Fraccion.h"
#include "../include/Matriz.h"
#include "../include/Polinomio.h"
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {

    //Ejemplos de Fracción
    std::cout << std::endl;
    std::cout <<"Ejemplos Fracciones:"<< std::endl;
    Fraccion<int> Frac1(3, 5);
    Fraccion<int> Frac2(2, 5);
    Fraccion<int> Frac3(5, 21);
    Frac3 = Frac1 + Frac2;
    ~Frac3;
    Frac3 = Frac1 - Frac2;
    ~Frac3;
    Frac3 = Frac1 / Frac2;
    ~Frac3;
    Frac3 = Frac1 * Frac2;
    ~Frac3;

    //Ejemplos de polinomio
    std::cout << std::endl;
    std::cout <<"Ejemplos Polinomios:"<< std::endl;

    vector<int> vec(6);

    Polinomio<int> poli1(6);
    Polinomio<int> poli2(4);
    Polinomio<int> poli3(6);
    for (int i = 0; i < 6; i++) {
        poli1.poli[i] = int (i*i*7-8);
        poli2.poli[i]= (i/4+8);
    }
    ~poli2;
    ~poli1;
    std::cout << "Suma" << std::endl;
    poli3 = (poli1+poli2);
    ~poli3;
    std::cout << "Resta" << std::endl;
    poli3 = (poli1-poli2);
    ~poli3;
    std::cout << "Multiplicación" << std::endl;
    poli3 = (poli1*poli2);
    ~poli3;
    std::cout << "División" << std::endl;
    poli3 = (poli1/poli2);
    ~poli3;


    //Ejemplos de Matriz
    std::cout << std::endl;
    std::cout <<"Ejemplos Matrices:"<< std::endl;

    Matriz<int> mat1(10, 25);
    Matriz<int> mat2(10, 25);
    Matriz<int> mat3(10, 25);

    for(int i=0; i<mat1.n; i++){
       for(int j=0; j<mat1.m; j++){
           mat1.mtx[i][j] = int(i*j/(i+j+1));
       }
    }

   for(int i=0; i<mat2.n; i++){
       for(int j=0; j<mat2.m; j++){
           mat2.mtx[i][j] = i*j;
       }
   }

    ~mat2;
    ~mat1;
    mat3 = (mat1+mat2);
    ~mat3;
    mat3 = (mat1-mat2);
    ~mat3;
    mat3 = (mat1*mat2);
    ~mat3;

    Matriz<float> mat4(10, 25);
    Matriz<float> mat5(10, 25);
    Matriz<float> mat6(10, 25);

    for(int i=0; i<mat4.n; i++){
       for(int j=0; j<mat4.m; j++){
           mat4.mtx[i][j] = int(i*j*10/(i+j+1));
       }
    }

   for(int i=0; i<mat5.n; i++){
       for(int j=0; j<mat5.m; j++){
           mat5.mtx[i][j] = i*5.65+j;
       }
   }
    mat6 = (mat4/mat5);
    ~mat6;
    return 0;
}
