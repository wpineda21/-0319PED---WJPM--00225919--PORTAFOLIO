#include  <iostream> 
#include <string>

using namespace std;

void menu();    
void datos();

string conti;

struct continente{
string Continente;
string Pais;
string Capital;
int NumeroHabitantes;
float PromEdadHabitantes;};

struct continente registro [5];
int CantRegistro=0;

int main(){

menu();

return 0;

}

void menu(){
int opc;    
bool seguir = true;
do{
cout<<"bienvenido al registro de Paises "<<endl;
cout<<"1-Ingresar Datos"<<endl;
cout<<"2-Mostar polacion total de continente"<<endl;
cout<<"3-Mostrar Capital con mayor Poblacion"<<endl;
cout<<"4-Mostrar promedio de edad de continente"<<endl;
cout<<""<<endl;
cout<<"por favor seleccione una opcion"  <<endl;
cin>>opc;

switch (opc){
case 1:  datos();  
        break;
case 2: seguir = false;
default:
    break;
}

}while(seguir);
cout<<"vuelva pronto"<<endl;
}

void datos(){
    if ( CantRegistro <= 5){
        cin.ignore();
        cout<<"Ingrese El Continente inicial"<<endl;
        getline(cin, registro[CantRegistro].Continente);
        cout<<"Ingrese El Pais"<<endl;
        getline(cin, registro[CantRegistro].Pais);
        cout<<"Ingrese La capital"<<endl;
        getline(cin, registro[CantRegistro].Capital);
        cout<<"Ingrese El numero de Habitantes"<<endl;
        getline(cin, registro[CantRegistro].NumeroHabitantes);
         cout<<"Ingrese El Promedio de Edad de habitantes"<<endl;
        getline(cin, registro[CantRegistro].PromEdadHabitantes);
        
        CantRegistro++;
    }
else cout<<"Error , Catalogo lleno "<<endl;
}
