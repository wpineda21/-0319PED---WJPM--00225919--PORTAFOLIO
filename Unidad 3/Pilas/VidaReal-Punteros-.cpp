#include <iostream>
using namespace std;

// Definicion de nodo ------------------------
struct nodo{
    int elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

// Prototipos de funciones ------------------------
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, int e);
int pop(Pila *s);
int top(Pila *s);


char letra1 ;
char letra2 = 's';
char letra3 = 'n';
bool continuar = true;

// Programa principal ------------------------
int main(){
	Pila s;
    initialize(&s);
int option=0;

    do{
    cout<<"que desea hacer??? \n"<<endl;
    cout<<"1)agregar ladrillo ala pila"<<endl;
    cout<<"2)quitar ladrillos ala pila"<<endl;
    cout<<"3)salir "<<endl;
    cin>>option;

    switch (option){
    
    case 1: cout<<"desea agregar un ladrillo: (s/n) "<<endl;
            cin>>letra1;
            if(letra1==letra2)
            push(&s,1);
            break;
    
    case 2: cout<<"desea quitar un ladrillo: (s/n) "<<endl;
            cin>>letra1;
            if(letra1==letra2)
            pop(&s);
            break;
    default: break;
    }

    }while(continuar);
     cout<<"saliendo "<<endl;
    
    return 0;
}

// Implementacion de funciones ------------------------
void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, int e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

int pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        int e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return -1;
}