#ifndef __QUEUE_LIST__
#define __QUEUE_LIST__
#include "Adt.h"


using namespace std;

/**
 * @class QueueList - clase que implementa una pila usando arreglos o listas
 * */
template <typename T> 
class QueueList: public Adt <T> {

  private:
      
    Node<T> *first; ///< Objeto tipo Nodo que representa el primer elemento en la lista
    Node<T> *last;  ///< Objeto tipo Nodo que representa el ultimo elemento en la lista
    
  public:
       
      /**
       * @brief constructor inicializa los puntero a NULL
       * */
        QueueList(){
            this->first = this->last = NULL;
		}
		
		/**
         * @brief: destructor encargado de eliminar toda la memoria dinámica del sistema
         * se que se implementase con arreglos o listas
         * */
		~QueueList(){
            cout << "Destructor " << endl; 
            while ( this->first != NULL ) { 
                this->Pop(); 
            }
		 } 


        /**
         * @brief verifica si la cola esta vacia
         * @return true si esta vacía
         * */
        bool isEmpty(){
            return (this->first == NULL); 
        }
        
        /**
         * @brief Para el caso de colas implementadas con listas, esta la asumimos
         * infinita, ya que se incrementara a medida que añadimos elementos
         * @return false, la cola con listas no se llenara
         * */
        bool isFull()
        {
            return false;
        }
        
        /**
         * @brief busca y obtiene el elemento en el extremo frontal de la cola
         * @return El elemento en la cola proximo a salir de estate
         * */
        T getFront(){
            return this->first->data;
        }
        
        /**
         * @brief Obtiene el ultimo elemento y el más reciente en ingresar a la cola
         * @return El dato tipo T del elemento 
         * */
        T getRear(){
            return this->last->data;
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
         * @brief inserta un elemento en la cola
         * @param elemento del typo T a insertar
         * */
        void Push( const T& value ){ // añade un elemento a la cola, este elemento se añade en la ultima posición

            Node<T> *temp = new Node<T>(value);
            temp->next = NULL;
            this->items++; // solo para llevar un conteo de items añadidos/removidos
            cout << "insertando item: " << value << endl;
            if(this->first == NULL){
                this->first = this->last = temp;
                this->last->next = NULL;
            }else{
                this->last->next = temp;
                this->last = temp;
            }
        }
        
        /**
         *@brief extrae y elimina un elemento de la cola
         *@return elemento tipo T extraido de la cola
         **/
        T Pop(){// siempre el elemento a retirar es el primero en la cola 
            
            if(this->first == NULL){
                cout << "cola vacia" << endl;
                return -1;
            }else{
                cout << "eliminano nodo con item: " << this->first->data << endl;
                Node<T> *temp = this->first->next;
                //delete this->first;
                this->first = temp;
                temp = NULL;
                this->items--;
            }
        }
};

#endif /*__QUEUE_LIST__ */
