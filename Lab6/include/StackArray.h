#ifndef __STACK_ARRAY__
#define __STACK_ARRAY__
#include <typeinfo>

#include "Adt.h"



using namespace std;

/**
 * @class StackArray - clase que implementa una pila usando arreglos o listas
 * */
template <typename T> 
class StackArray: public Adt <T> {

  public:
		
		StackArray( ){
			
			this->items = -1;
            this->array = new T[ SIZE ];
		}

		/**
         * @brief: destructor encargado de eliminar toda la memoria dinámica del sistema
         * */
		~StackArray(){
            cout << "destructor" << endl;
            if(this->array != NULL){
                cout << "eliminando array" << endl;
                delete[] this->array;
            }
		 } 

		 /**
          * @brief Método para obtener el numero de nodos en la lista siendo el numero 
          * correspondiente al último nodo.
          * @return entero que indica la posición del ultimo elemento
          * */
        int getPos(){
            return this->items;
        }
       
        /**
         * @brief verifica si el arreglo interno de la liste esta vacio
         * @return true si esta vacia, false si esta llena
         * */
        bool isEmpty(){
            return (this->items == -1);
        }
        
        /**
         * @brief verifica si la cola esta o no llena
         * @return true si la cola esta llena, false caso contrario
         * */
        bool isFull()
        {
            return ( this->items >= SIZE ) ? true : false;
        }

        /**
         * @brief inserta un elemento en la pila
         * @param elemento del typo T a insertar
         * */
        void Push( const T& value ){
            
            if( this->items == SIZE-1 )  // Pila llena
            {
                cout<<"Error: la pila esta llena"<<endl;
                return;
            }
            else 
            {  
                this->items++;
                this->array[ this->items ] = value;
                cout<<"Apilando item: " << this->items << " = " << value  << endl;
            }
        }
        
        /**
         *@brief extrae y elimina un elemento de la pila
         *@return elemento tipo T extraido de la pila
         **/    
        T  Pop(){

            if( this->items == -1 )
            {
                cout<<"ERROR: La pila esta vacia !"<<endl;
                return -1;
            }
            T ret= this->array[ this->items ];
            cout<<"Desapilando item: " << this->items << " = " << ret << endl;
            this->items--;
            return ret; 
        }
        
    private:
    
        T *array;
            
};

#endif /* __STACK_ARRAY__ */
