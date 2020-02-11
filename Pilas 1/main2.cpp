#include <iostream>
#include <stack>

using namespace std;

stack <int> l;

void agregarladrillo();
void quitarladrillo();
void cantidadladrillo();

char letra1 ;
char letra2 = 's';
char letra3 = 'n';

int main(){

bool continuar = true;
int option;

    cout<<"la pila de ladrillos actualmente contiene "<<endl;
    cout<<l.empty()<<endl;

do{
    cout<<"que desea hacer??? \n"<<endl;
    cout<<"1)agregar ladrillo ala pila"<<endl;
    cout<<"2)quitar ladrillos ala pila"<<endl;
    cout<<"3)mostrar la cantidad actual de ladrillos"<<endl;
    cout<<"4)salir "<<endl;
    cin>>option;

    switch (option){
    
    case 1: agregarladrillo();break;
    
    case 2: quitarladrillo();break;
    
    case 3: cantidadladrillo();break;
    
    case 4: cout<<"gracias por venir "<<endl;
            continuar=false;
            break;
    default: break;
    }

}while(continuar);
     cout<<"saliendo "<<endl;
    
    return 0;
}

void agregarladrillo(){
    cout<<"desea agregar un ladrillo: (s/n) "<<endl;
    cin>>letra1;
    if(letra1==letra2)
        l.push(1);
}

void quitarladrillo(){
    cout<<"desea quitar un ladrillo: (s/n) "<<endl;
    cin>>letra1;
    if(letra1==letra2)
        l.pop();

}

void cantidadladrillo(){

cout<<"la cantidad de ladrillos actuales es "<<l.size()<<endl;

}