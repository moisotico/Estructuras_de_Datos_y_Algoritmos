#include <iostream>

#include <math.h>

#include "../include/Adt.h"
#include "../include/Stack.h"
#include "../include/Queue.h"

#define PAI 40
#define PAD 41
#define PCI 91
#define PCD 93
#define COI 123
#define COD 125

using namespace std;

void testStack();
bool checkBalancedParenthesis(string s);
void testQueue();

int main(){
    
    // verificación del funcionamiento de la pila usando arreglos y listas
    testStack();
    
    // verificación del funcionamiento de una cola usando arreglos y listas
    testQueue();
    
    string s("main(){\nif(true){\n\tx=0;\n\t}\n}}");
    
    if (checkBalancedParenthesis( s ) ){
        cout << "Código sin errores de paréntesis !" << endl;
        cout << "\033[1;32m" << s <<"\033[0m" << endl;
    }else{
        cout<<endl;
        cout << "revise su código - paréntesis incompletos" << endl;
        cout << "\033[1;31m" << s <<"\033[0m" << endl;
    }

    
    return 0;
}

//******************************** Función para testear la implementación de un pila con listas y con arreglos*****
void testStack(){
    
    cout << "VERIFICANDO EL FUNCIONAMIENTO DE UNA PILA**" << endl;
    Stack<int> *stack1 = new Stack<int>(1);
    
    cout<<"verificando funcionamiento de la pila implementada con lista: "<<endl;
    for( int i = 0; i<SIZE;i++){
      int x = rand()%10;
      stack1->Push(x);
    }
    
    for( int i = 0; i<SIZE;i++){
      int x = stack1->Pop();
    }
    
    cout<<endl;
    
    Stack<char> stack3(0);
    cout<<"verificando funcionamiento de la pila implementada con arreglos: "<<endl;
    for( int i = 0; i<SIZE;i++){
      char hola = i*2 +'0';
      stack3.Push(hola);
    }

    for( int i = 0; i<SIZE;i++){
      char x = stack3.Pop();
    }

    cout << "item " << stack3.Pop() << endl;
    
    delete stack1;
}

//******************************** Función para testear la implementación de una cola con listas y con arreglos *****
void testQueue(){
    cout<<endl;
    cout << "VERIFICANDO EL FUNCIONAMIENTO DE UNA COLA *****" << endl;
    cout<<endl;
    Queue<int> *queue = new Queue<int>(0);
    //para enteros
    for( int i = 0; i<SIZE;i++){
      int x = rand()%100 ;
      queue->Push(x);
    }
    
    queue->Push(12587);
    
    while( !queue->isEmpty() ){
        queue->Pop();
    }
    queue->Pop();
    
    cout<<endl;
    // para chars
    Queue<char> *queue1 = new Queue<char>(1);
    for( int i = 0; i<20;i++){
      char x = rand()%94 + 33 ;
      queue1->Push(x);
    }
    
    while( !queue1->isEmpty() ){
        queue1->Pop();
    }
    
    delete queue;
    delete queue1;
}


//******************************** Función para chequear la sintaxis de paréntesis **********************************
bool checkBalancedParenthesis(string s){
    
    cout << endl;
    cout << "CÓDIGO PARA REVISIÓN DEL BALANCE EN LOS PARÉNTESIS " << endl;
    cout << endl;
    
    string::iterator it; ///< iterator para recorrer cada elemento tipo char en el string    
    Stack<char> stack(1);
    
    cout<<endl;
    bool ret = true;
    for (it= s.begin(); it != s.end(); it++)
    {	
        int type = (int)(*it);
        switch(type){
            case PAI:{
                cout << "parentesis izquierdo - apilamos: " << *it << endl;
                stack.Push(type);
                break;
            }
            case PCI:{
                cout << "parentesis cuadrado izquierdo - apilamos: " << *it << endl;
                stack.Push(type);
                break;
            }
            case COI:{
                cout << "corchete izquierdo- apilamos: " << *it << endl;
                stack.Push(type);
                break;
            }
            //******************* casos de los paréntesis derechos ****************
            case PAD:{
                cout << "parentesis derecho - desapilamos" << endl;
                int x = stack.Pop();
                if ( x != PAI ) ret = false;
                break;
            }
            case PCD:{
                cout << "parentesis cuadrado derecho - desapilamos" << endl;
                int x = stack.Pop();
                if ( x != PCI ) ret = false;
                break;
            }
            case COD:{
                cout << "corchete derecho - desapilamos" << endl;
                int x = stack.Pop();
                if ( x != COI ) ret = false;
                break;
            }
    
            default:
                break;
        }
    }
    return ret;
}
    
    
    
