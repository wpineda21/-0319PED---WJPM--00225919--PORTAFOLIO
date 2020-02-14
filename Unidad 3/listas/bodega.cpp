#include <iostream>//libreria de entrada y salida de datos
#include <vector>//libreria para lista
#include <algorithm>//libreria para funciones de lista
#include <string>//liberia para caracteres enteros
using namespace std;

//Estructura para guardar informacion
struct Articulo{
    string nombre;
    int peso;
    float precio;
    char S;
};
//incializacion de lista
vector<Articulo> bodega;

//funciones para comparar t buscar
bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

//prototipo de funciones
void agregar(), buscar(), eliminar(), mostrar(), ordenar(),Perecederos(),Mayorpeso(),MayorPrecio();


//Funcion principal
int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5) Mostrar solo Articulos con Fecha de vencimiento.\n";
        cout << "6) Mostrar solo Articulos que pesan mas de 300 gramos\n ";
        cout << "7) Mostrar Solo aquellos Articulos que valen mas de $50 \n";
        cout << "8) Ordenar.\n";
        cout << "9) Salir.\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: Perecederos(); break;
            case 6: Mayorpeso(); break;
            case 7: MayorPrecio(); break;
            case 8: ordenar(); break;
            case 9: continuar = false;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

//Agregar articulos ala bodega
void agregar(){
   
    Articulo unArticulo;
    cout << "Nombre: "; getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();
    cout << "El Articulo es perecedero? (s/n) "; cin>>unArticulo.S;
    bodega.insert(bodega.end(), unArticulo);
    cout << "Articulo ingresado exitosamente!\n";
}

//Buscar Articulos

void buscar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "Articulo si se encuentra en la bodega.\n";
    else
        cout << "Articulo no se encuentra en la bodega.\n";
        }

//funcion para eleminar un articulo de la lista       
void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}

//funcion para mostrar un articulo de la lista
void mostrar(){
    cout<<"\n"<<endl;
    for (int i = 0; i < bodega.size(); i++) {
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
        if(bodega[i].S == 's'||bodega[i].S =='S'){          
        cout<<"EL articulo si es perecedero"<<endl;    
    }else{
    cout<<" El Articulo No es perecedero "<<endl;
}
    }
}

//funcion para ordenar un articulo de la lista
void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

//fucion que clasifica los articulos perecederos 
void Perecederos(){
    cout<<"\n"<<endl;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].S == 's'||bodega[i].S =='S'){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
        cout<<"EL articulo es perecedero"<<endl;    
    }else{   
}
}
}


//funcion que clasifica si el peso de un articulo es mayor a 300 gr
void Mayorpeso(){
    int mayor=300;
    cout<<"\n"<<endl;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].peso>=mayor){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";    
    }else{   
}
}
}

//funcion que clasifica si el precio de un articulo es mayor a $50
void MayorPrecio(){
    int mayor=50;
    cout<<"\n"<<endl;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].precio>=mayor){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";    
    }else{   
}
}
}








