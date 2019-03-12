#ifndef __STACK_LIST__
#define __STACK_LIST__

#include "Adt.h"



using namespace std;

/**
 * @class StackList - clase que implementa una pila usando listas
 * */
template <typename T> 
class StackList: public Adt <T> {
    
  private:
      
    Node<T> *first;   ///< Objeto tipo Nodo que representa el primer elemento en la lista
    Node<T> *last;    ///< Objeto tipo Nodo que representa el ultimo elemento en la lista

  public:
		
		StackList(){
			
			this->items = -1;
            this->first = this->last = NULL;
		}
		/**
         * @brief: destructor encargado de eliminar toda la memoria dinámica del sistema
         * */
		~StackList(){
            cout << "destructor" << endl;
            if( this->items != -1 ){
                cout << "eliminando lista"<<endl;
                while ( this->first != NULL ) { 
                    this->Pop(); 
                }
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
         * @brief Para el caso de pilasimplementadas con listas, esta la asumimos
         * infinita, ya que se incrementara a medida que añadimos elementos
         * @return false, la pila con listas no se llenara
         * */
        bool isFull()
        {
            return false;
        }
            
        /**
         * @brief inserta un elemento en la pila
         * @param elemento del typo T a insertar
         * */
        void Push( const T& value ){

            Node<T> *temp = new Node<T>(value);
            temp->next = NULL;
            
            if ( this->items == -1 ) {
                cout<<" insertando primer elemento"<<endl;
                this->first = temp;
                this->last = temp;
                this->items++;
                cout<<"apilando item: " << this->items << " = " << this->first->data << endl;
            } else {
                this->items++;
                this->last->next = temp;
                this->last = this->last->next;
                cout<<"apilando item: " << this->items << " = " << value << endl;
            }
            temp = NULL;
        }
        
         /**
         *@brief extrae y elimina un elemento de la pila
         *@return elemento tipo T extraido de la pila
         **/  
        T Pop(){
            
            if ( this->items == -1 ) {
                cout<<"ERROR: La pila esta vacia !"<<endl;
                return -1;
            }
            
            if (this->first == this->last) {
                cout << "ultimo elemento " << endl;
                T ret =  this->first->data;
                cout<<"desapilando item: " << this->items << " = " << ret << endl;
                this->items--;
                delete this->first;
                this->first = NULL;
                this->last = NULL; 
                return ret;
            }
            
            Node<T>* temp = this->first;
            while ( temp->next != this->last ) {
                temp = temp->next;
            }
            T ret =  this->last->data;
            delete this->last;
            this->last = temp;
            this->last->next = NULL;
            cout<<"desapilando: " << this->items << " = " << ret << endl;
            this->items--;
            return ret;
        }
};

#endif /* __STACK_LIST__ */
