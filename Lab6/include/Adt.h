#ifndef __ADT__
#define __ADT__

#define SIZE    10 ///< Dimensiones del arreglo utilizado en estructuras tipo array

#define ARREGLO 0
#define LISTA   1

/**
 * @class Node: clase nodo, representa cada elemento a enlazar en una lista
 * */
template <typename T> class Node{

    public:
        T data;         ///< campo para l dato que contendrá este nodo
        Node *next;     ///< puntero al proximo nodo 
        Node(const T &value): next(NULL), data(value){
        }
        ~Node() { 
            if( next != NULL)
                delete next; 
        }
};


/**
 * @class Adt: clase base sobre la cual se implementaran las clases Stack y Queue
 * */
template <typename T> 
class Adt{
    
public:
    
        /**
         * @brief destructor virtual
         */
        virtual ~Adt(){}
        /**
         * @brief verifíca si la estructura esta o no vacia
         * @return bool: true si esta vacia, false caso contrario
         * */
        virtual bool    isEmpty() 																		= 0;
        
        /**
         * @brief Verifica si la estructura esta llena
         * @return true en caso de estar llena y false caso contrario
         * */
        virtual bool    isFull() 																		= 0;


        /**
         * @brief Push ejecuta la acción  de añadir a la Adt si esta es implementada con listas enlazadas
         * @param const T& - referencia al elemento a introducir a la Adt
         * */
        virtual void Push( const T& value /* el valor no se puede modificar de ahi el const */ )  = 0;
        
        /**
         * @brief Método que implementa la extracción de un elemento de la Adt, siendo esta implementada con listas
         * @return T: elemento almacenado en la estructura ya sea pila o cola implementada con listas
         * */
        virtual T    Pop()                                                                        = 0;
        
 protected:
     
        int items;///< numero de items en la estuctura de datos

};

#endif /* __ADT__ */
