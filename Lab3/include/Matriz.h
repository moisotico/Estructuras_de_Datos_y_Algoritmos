#ifndef _MATRIZ_
#define _MATRIZ_

#include<vector>
#include "Calculadora.h"

template < class T > class Matriz: public Calculadora<T>
{
    public:
        //! Definimos nuestro propio tipo de dato llamado matriz el cual es un vector de vectores
        typedef std::vector< std::vector<T> > matriz;
        //! mtx es una matriz construida a partir de dos vectores
        matriz mtx;

        int n, m; ///< n, m enteros que indican el tamaño de la matriz
        /** @brief Constructor de la clase Matriz,
         *  @param _n numero de filas
         *  @param _m numero de columnas
         */
        Matriz(int _n, int _m){
          n = _n;
          m = _m;
          std::vector<T> row(m, 0);
          for (int i=0;i<n;i++)
{
            mtx.push_back(row);
          }
          //mtx(n, std::vector<T>(m, 0));
        }
        /** @brief Destructor for defecto
         **/
        ~Matriz(){}


        /** @brief Sobrecarga del operador +, utilizado para sumar matrices del mismo tamaño
         * @param m1 matriz a sumar
         * @param m2 matriz a sumar
         * @return un objeto del tipo matriz equivalente a la suma miembro a miembro de las dos matrices
         */

        Matriz operator +(Matriz m2){
            Matriz m(this->n, m2.m);

            if((this->m == m2.m) && ( this->n == m2.n)){
                for(int i = 0; i<m2.n; i++){
                    for(int j=0; j<m2.m; j++){
                        m.mtx[i][j] = this->mtx[i][j] + m2.mtx[i][j];
                    }

                }
            }
            return m;
        }

        /** @brief Sobrecarga del operador - para restar matrices
         * @param m1 matriz
         * @param m2 matriz
         * @return una nueva matriz
         */

    Matriz operator -(Matriz m2){
        Matriz m(this->n, m2.m);
        if((this->m == m2.m) && ( this->n == m2.n)){
            for(int i = 0; i<m2.n; i++){
                for(int j=0; j<m2.m; j++){
                    m.mtx[i][j] = this->mtx[i][j] - m2.mtx[i][j];
                }
            }
        }
        return m;
    }

        /**@brief SObrecarga del operador de multiplicacion *
         * @param m1 multiplicando
         * @param m2 multiplicador
         * @return Matriz resultante
         */

    Matriz operator *(Matriz m2){

        Matriz m(m2.m, this->n);
        if(this->m == m2.n){

            for(int i = 0; i<m2.n; i++){
                for(int j=0; j<m2.m; j++){
                    m.mtx[i][j] = this->mtx[i][j] * m2.mtx[j][i];
                }
            }
        }
        return m;
        }

        /** @brief Sobrecarga de la division para matrices
         * @param m1 dividiendo
         * @param m2 divisor
         * @return matriz resultante
         */

    Matriz operator /(Matriz m2){

        Matriz m(this->n, this->m);
        if((this->m == m2.m) && ( this->n == m2.n)){
            for(int i = 0; i<m2.n; i++){
                for(int j=0; j<m2.m; j++){
                    m.mtx[i][j] = this->mtx[i][j]/m2.mtx[i][j];
                }

            }
        }
        return m;
    }

    Matriz* operator=(Matriz *t)
    {
        if(this != t){
            this->n = t->n;
            this->m = t->m;
            for(int i = 0; i<t->n; i++){
                for(int j=0; j<t->m; j++){
                    this->mtx[i][j] = t->mtx[i][j];
                }
            }
        }
        return this;
    }



        /**@brief Imprime los datos del objeto matriz, sus dimensiones y sus datos
         * @param matriz a imprimir
         */

    void operator ~(){
        std::cout<<" matriz de dimension :"<<this->n<<"x"<<this->m<<std::endl;
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
              std::cout<< this->mtx[i][j] << "\t";
            }
            std::cout<<std::endl;
        }
    }
};
#endif
