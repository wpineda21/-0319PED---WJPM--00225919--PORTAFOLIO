#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct Actividades{
    string titulo,hora;
    int minutos;
};  
typedef struct Actividades actividad;  


struct Agenda{
    queue <Actividades> MostrarAgenda;
};
typedef struct Agenda agenda;

agenda ActividadActual;


//variables globales
string titulo1;


//protipo de funciones
void insertar();
void imprimir();
void borrar();

int main(){

bool continuar=true;

do{
int opt=0;

    cout<<"Mis actividades "<<endl;
    cout<<"1)insertar activades "<<endl;
    cout<<"2)ver todas las actividades del dia "<<endl;
    cout<<"3)borrar una actividad "<<endl;
    cout<<"4)borrar todas las actividades del dia "<<endl;
    cout<<"5)salir  "<<endl; 
    cin>>opt; cin.ignore();

    switch (opt)
    {
    case 1: insertar(); break;
    case 2: imprimir(); break;
    case 3: borrar(); break;
    case 4: break;
    case 5: continuar=false; break;
    default:
        break;
    }
}while (continuar); 
return 0;
}


void insertar(){
   
    actividad unactividad;
    cout<<""<<endl;
    cout<<"Digite su actividad: "; getline(cin,unactividad.titulo);
    cout<<"digite Hora estimada de dicha actividad: "; getline(cin,unactividad.hora);
    cout<<"Digite duracion de minutos estimada de dicha actividad: "; cin>>unactividad.minutos;
    ActividadActual.MostrarAgenda.push(unactividad);

}

void imprimir(){
    while(!ActividadActual.MostrarAgenda.empty()){

        actividad actividadahora = ActividadActual.MostrarAgenda.front();
        cout << "el titulo de la actividad es \n " << actividadahora.titulo<<endl;
        cout << " se realizara a la hora \n" << actividadahora.hora <<endl;
        cout << ". Tiempo estimado de demora:\n " << actividadahora.minutos << endl;
       // ActividadActual.MostrarAgenda.pop();
    }
    cout << "Cola vacia!" << endl;
}

void borrar(){
    while(!ActividadActual.MostrarAgenda.empty()){
     ActividadActual.MostrarAgenda.front();
      ActividadActual.MostrarAgenda.pop();
    }
     cout << "Cola vacia!" << endl;

}  
