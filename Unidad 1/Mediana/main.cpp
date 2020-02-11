#include <iostream>
using namespace std;

int num;// mi variable global

float mediana(int *); // mi prototipo de funcion 

int main(){ // funcion principal


cout<<"bienvenido al programa de calculo de mediana"<<endl;
// primero pedimos al usuario que digite el tamano del arreglo
int arreglo[num];
cout<<"ingrese la cantidad de elementos del arreglo: "<<endl;
cin>>num;
   int a[num];
   for(int i=0;i<num;i++){
    cout << "Introduzca los numeros de forma ordenada: " << i+1 <<endl;
    cin >> a[i];
   }
//arrojando el resultado   
cout << "Mediana: " << mediana(a) << endl; 
}

//funcion de calculo de mediana
float mediana(int *p) {
 float mediana=0;
 int i;
 for(i=0;i<num;i++)
 {
     mediana += *p; 
     p++; 
 }
 return mediana/num;
}