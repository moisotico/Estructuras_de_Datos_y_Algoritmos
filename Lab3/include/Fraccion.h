#ifndef _FRACCION_
#define _FRACCION_

#include "Calculadora.h"

template <class T>class Fraccion: public Calculadora<T>
    {
    public:

        T num, den;

        /** @brief Constructor de la clase Fraccion,
         *  @param num numerador de la fracción.
         *  @param den denominador de la fracción.
         */
        Fraccion(T _num, T _den){
            num = _num;
            den = _den;
        }

        /** @brief Constructor de la clase Fraccion, sin parametros.
         */
        Fraccion(){
            num = 0;
            den = 1;
        }

        /** @brief Destructor de la clase Fraccion, sin parametros.
         */
        ~Fraccion(){
        }

        /** @brief Sobrecarga del operador +, utilizado para sumar fracciones.
         * @param b fraccion a sumar
         * @param c fraccion sumada
         * @return un objeto del tipo fraccion equivalente a la suma de las dos fracciones
         */
        Fraccion operator +(Fraccion b){
            Fraccion c;
            c.num = this->num*b.den + b.num*this->den ;
            c.den = this->den*b.den;

            return c;
        }

        /** @brief Sobrecarga del operador -, utilizado para restar fracciones.
         * @param b fraccion a restar.
         * @param c fraccion restada.
         * @return un objeto del tipo fraccion equivalente a la resta de las dos fracciones.
         */
        Fraccion operator -(Fraccion b){
             Fraccion c;
             c.num = this->num*b.den - b.num*this->den ;
             c.den = this->den*b.den;

             return c;
        }

        /** @brief Sobrecarga del operador *, utilizado para multiplicar fracciones.
         * @param b fraccion a multiplicar con this.
         * @param c fraccion producto.
         * @return un objeto del tipo fraccion equivalente al producto de las dos fracciones.
         */
        Fraccion operator *(Fraccion b){
            Fraccion c;
            c.num = this->num*b.num;
            c.den = this->den*b.den;

            return c;
        }

        /** @brief Sobrecarga del operador /, utilizado para dividir fracciones.
         * @param b fraccion la cual se dividirá con this.
         * @param c fraccion producto.
         * @return un objeto del tipo fraccion equivalente al cociente de las dos fracciones.
         */
        Fraccion operator /(Fraccion b){
            Fraccion c;
            c.num = this->num/b.num;
            c.den = this->den/b.den;

            return c;
        }

        /** @brief Sobrecarga del operador =, utilzando un puntero a Fraccion.
        * @param t puntero que almacenara el resultado de la instancia.
        * @return un objeto del tipo fraccion equivalente por medio del this.
        */
        Fraccion* operator =(Fraccion b){
            Fraccion c;
            this->num=b.num;
            this->den=b.den;

            return this;
        }
        /** @brief Sobrecarga del operador ~, para que imprima el resultado de
         * las instancias y sus operaciones de las fracciones.
         */
        void operator ~(){
            std::cout << "Resultado: " << this->num << "/" << this->den << std::endl;
        }
    };
#endif
