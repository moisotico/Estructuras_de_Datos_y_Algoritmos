#ifndef _CALCULADORA_
#define _CALCULADORA_

#include <iostream>

template <class Data>
class Calculadora
{
    public:
        Calculadora(){
        }

        ~Calculadora(){
        }

        Data add(Data &d1, const Data &d2){
            return d1+d2 ;
        }

        Data sub(Data &d1, const Data &d2){
            return d1-d2 ;
        }

        Data mul(Data &d1, const Data &d2){
            return d1*d2 ;
        }

        Data div(Data &d1, const Data &d2){
            return d1/d2 ;
        }

        Data print(Data &d);
};
#endif
