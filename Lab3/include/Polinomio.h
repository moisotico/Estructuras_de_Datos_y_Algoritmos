#ifndef _POLINOMIO_
#define _POLINOMIO_

#include "Calculadora.h"
#include <vector>
#include <stdlib.h>

template <class T>class Polinomio: public Calculadora<T>
{
    public:

        //vector el cual guarda el grado de los polinomios.
        std::vector<T> poli;

        /**Constructor para un polinomio de grado diferente a cero
        * @param g: int el cual representa el grado del polinomio
        **/
        Polinomio (int _g){
            poli.resize(_g + 1);
        }

        /** @brief Destructor por defecto
         **/
        ~Polinomio(){
        }

        /** @brief Sobrecarga del operador +, utilizado para sumar polinomios, los cuales
        * son representados por vectores, los cuales poseen sus valores, de izquiereda a
        * derecha en orden menor a mayor.
        * @param b polinomio a sumar con el this.
        * @return un objeto del tipo Polinomio equivalente a la suma de los dos Polinomios.
        */
        Polinomio operator +(Polinomio b){
            Polinomio c(1);
            int count;
            int end;
            if((this->poli.size()) > (b.poli.size()) ){
                count = b.poli.size();
                end = this->poli.size();
                c.poli.resize(end);
                for (int i = count; i < end; i++) {
                        c.poli[i] = this->poli[i];
                    }
            }
            else{
                count = this->poli.size();
                end =  b.poli.size();
                c.poli.resize(end);
                for (int i = count; i < end; i++) {
                    c.poli[i] = b.poli[i];
                }
            }

            for (int i = 0; i < count; i++) {
                    c.poli[i] = this->poli[i] + b.poli[i];
            }
            return c;
        }

        /** @brief Sobrecarga del operador -, utilizado para restar polinomios, los cuales
        * son representados por vectores los cuales poseen sus valores, de izquiereda a
        * derecha, en orden menor a mayor.
        * @param b polinomio a restar con el polinomio this.
        * @return un objeto del tipo Polinomio equivalente a la resta de los dos Polinomios.
        */
        Polinomio operator -(Polinomio b){
            Polinomio c(1);
            int count;
            int end;
            if((this->poli.size()) > (b.poli.size()) ){
                count = b.poli.size();
                end = this->poli.size();
                c.poli.resize(end);
                for (int i = count; i < end; i++) {
                    c.poli[i] = this->poli[i];
                }

            }
            else{
                count = this->poli.size();
                end =  b.poli.size();
                c.poli.resize(end);
                for (int i = count; i < end; i++) {
                        c.poli[i] = b.poli[i];
                    }
            }
            for (int i = 0; i < count; i++) {
                c.poli[i] = this->poli[i] - b.poli[i];
            }
            return c;
        }

        /** @brief Sobrecarga del operador *, utilizado para multiplicar polinomios, los
        * cuales son representados por vectores los cuales poseen sus valores, de
        * izquiereda a derecha, en orden menor a mayor.
        * @param b polinomio a multiplicar con el polinomio this.
        * @return un objeto del tipo Polinomio equivalente a la multiplicación de los dos
        * Polinomios.
        */
        Polinomio operator * (Polinomio b){
            Polinomio c(1);
            int countb = b.poli.size();
            int counta = this->poli.size();
            int countc = (counta + countb);
            c.poli.resize(countc);  //<-- Cambiamos el tamaño del polinomio de salida.

            for (int i = 0; i < countb; i++) {
                for(int j=0; j < counta; j++){
                    c.poli[i+j] += this->poli[j] * b.poli[i];
                }
            }
            return c;
        }

        /** @brief Sobrecarga del operador /, utilizado para dividir polinomios, los
        * cuales son representados por vectores, que poseen sus valores, de
        * izquiereda a derecha, en orden menor a mayor.
        * @param b polinomio a dividir con el polinomio this.
        * @return un objeto del tipo Polinomio equivalente a la división de los dos
        * Polinomios.
        */
        Polinomio operator /(Polinomio b){
            Polinomio c(1);
            int countb = b.poli.size();
            int counta = this->poli.size();
            if (counta >= countb) {            //<---Condición necesaria para dividir
                int countc = counta - countb;
                c.poli.resize(countc);
                for (int i = 0; i < countb; i++) {
                    for(int j=0; j < i; j++){
                        c.poli[abs(i-j)] += this->poli[j] / b.poli[i];
                    }
                }
                return c;
            }
            else{
            std::cout << "No se puede dividir" << std::endl;
            return b;
            }

        }

        /** @brief Sobrecarga del operador =, utilzando un puntero a Polinomio.
         * @param t puntero que almacenara el resultado de la instancia.
         * @return un objeto del tipo fraccion equivalente por medio del this.
         */
        Polinomio* operator =(Polinomio *t){
                if(this != t){
                    this->poli.size() = t->poli.size();
                    for(int i = 0; i<t->n; i++){
                        this->poli[i] = t->poli[i];
                    }
                }
                return this;
        }

        /** @brief Sobrecarga del operador ~, para que imprima el resultado de
         * las instancias y sus operaciones para un polinomio.
         */
         void operator ~(){
            std::cout << "El polinomio de grado " << (this->poli.size() -1) << " sería:"<< std::endl;
            for(int i=0; i < this->poli.size() ; i++){
              std::cout<< this->poli[i]<< "x^" << i <<"\t";
            }
            std::cout << std::endl;
        }
    };
#endif
