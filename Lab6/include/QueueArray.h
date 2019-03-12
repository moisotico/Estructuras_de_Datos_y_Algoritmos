#ifndef __QUEUE_ARRAY__
#define __QUEUE_ARRAY__

#include "Adt.h"


using namespace std;

/**
 * @class QueueArray - clase que implementa una pila usando arreglos o listas
 * */
template <typename T> 
class QueueArray: public Adt <T> {

  public:
       
      /**
       * @brief constructor inicializa los indices de la cola
       * */
        QueueArray(){
			this->front = this->rear = -1;
            this->array = new T[ SIZE ];
		}
		

		/**
         * @brief: destructor encargado de eliminar toda la memoria dinámica del sistema
         * se que se implementase con arreglos o listas
         * */
		~QueueArray(){
            cout << "Destructor " << endl;
            if(this->array != NULL)
                delete[] this->array;
		 } 

        /**
         * @brief verifica si la cola esta vacia
         * @return true si esta vacía
         * */
        bool isEmpty(){
            return (front == -1 && rear == -1); 
        }
        
        /**
         * @brief verifica si la cola esta o no llena
         * @return true si la cola esta llena, false caso contrario
         * */
        bool isFull()
        {
            return (this->rear+1)%SIZE == this->front ? true : false;
        }

        /**
         * @brief busca y obtiene el elemento en el extremo frontal de la cola
         * @return El elemento en la cola proximo a salir de estate
         * */
        T getFront(){
            return this->array[this->front];
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
        void Push( const T& value ){

            if( this->isFull() )
            {
                cout<<"Error: Cola llena " << endl;
                return;
            }
            cout << "insertando dato: "<< value << endl;
            if ( this->isEmpty() )
            { 
                this->front = this->rear = 0; 
            }
            else
            {
                this->rear = (this->rear+1)%SIZE;
            }
            
            this->array[this->rear] = value;
            this->items++;
        }
          
        /**
         *@brief extrae y elimina un elemento de la cola
         *@return elemento tipo T extraido de la cola
         **/  
        T  Pop(){

            T ret;
            if( isEmpty() )
            {
                cout << "Error: Cola vacía" << endl;
                return -1;
            }
            else if( front == rear ) 
            {
                ret = this->array[front];
                rear = front = -1;
            }
            else
            {
                ret = this->array[front];
                front = (front+1)%SIZE;
            }
            cout<<"retirando elemento de la cola: " << ret << endl;
            return ret;
        }
            

  private:
        
        int front,
            rear;
        T *array;
};

#endif /* __QUEUE_ARRAY__ */
