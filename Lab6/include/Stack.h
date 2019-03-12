#ifndef __STACK__
#define __STACK__
#include <typeinfo>

#include "Adt.h"
#include "StackArray.h"
#include "StackList.h"



using namespace std;

/**
 * @class Stack - clase que implementa una pila usando arreglos o listas
 * */
template <typename T> 
class Stack{

  public:
		
      /**
       * @brief Constructor de la clase pila, implementa una pila según el tipo elejido por el usuario
       * @param tipo de pila a implementar array/list
       * */
		Stack( int type ){
			
			switch(type){	
				case ARREGLO:{
                    cout << "Stack con arreglos" << endl;
                    adt = new StackArray<T>();
                    break;
				}
				
				case LISTA:{
                    
                    adt = new StackList<T>();
                    cout<<" Stack con listas"<<endl;
                    break;
				}

				default:{
					cout<<"Opcion por defecto Stack con listas"<<endl;
                    adt = new StackList<T>();
                    break;
				}
			}
		}

		~Stack(){
            cout << "destructor" << endl;
		 } 

        void Push(const T& value){
          adt->Push(value);
        }


        T Pop(){
            return adt->Pop();
        }

        int getPos(){
            return adt->getPos();
        }
        
        bool isEmpty(){
            return adt->isEmpty();
        }
            

  private:

        Adt<T> *adt;///< Estructura base utilizada para la implementación de la pila
};

#endif /* __STACK__ */
