#ifndef __QUEUE__
#define __QUEUE__
#include <typeinfo>

#include "Adt.h"
#include "QueueArray.h"
#include "QueueList.h"

using namespace std;

/**
 * @class Queue - clase que implementa una pila usando arreglos o listas
 * */

template <typename T> 
class Queue{

  public:
       
      /**
       * @brief Constructor de la clase pila, implementa una pila según el tipo elejido por el usuario
       * @param tipo de pila a implementar array/list
       * */
		Queue( int type ){
			
			switch(type){	
				case ARREGLO:{
                    adt = new QueueArray<T>();
                    cout<<" cola implementada usando arreglos "<<endl;
                    break;
				}
				
				case LISTA:{
                    adt = new QueueList<T>();
                    cout<<" cola implementada usando listas "<<endl;
                    break;
				}

				default:{
					cout<<"Opcion por defecto es una lista"<<endl;
                    adt = new QueueList<T>();
                    break;
				}
			}
		}
		
		/**
         * @brief: destructor encargado de eliminar toda la memoria dinámica del sistema
         * se que se implementase con arreglos o listas
         * */
		~Queue(){
            delete adt;
		 } 
		 
        /**
        * @brief Push: función generica para insertarun elemento según el tipo de implementación
        * @param value: valor a insertar en la cola 
        * */
        void Push(const T& value){
            adt->Push(value);
        }

        /**
        * @brief Pop: función principal que será llamada para extraer un dato de la cola
        * internamente utiliza un puntero para llamar al método correspondiente
        * @return ret: valor a retornar extraido de la la cola(primer elemento)
        * */
        T Pop(){
            return adt->Pop();
        }
        
        bool isEmpty(){
            return adt->isEmpty();
        }
        
        int getPos(){
            return adt->getPos();
        }
        
        bool isFull()
        {
            return adt->isFull();
        }
        
        T getFront(){
            return this->first->data;
        }
        T getRear(){
            return this->last->data;
        }

            

  private:
      Adt<T> *adt; ///< Estructura base utilizada para la implementación de la maravillosa pila
};

#endif /* __QUEUE__ */
