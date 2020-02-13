#include <iostream>//Libreria de entrada y salida de datos
using namespace std;


//Prototipo de funciones
int buscar(int[], int, int); 
void Arreglo(int[], int); 
void inter(int&, int&); 

//declarando funcion principal
int main(){
  int num=0,elementos = 8;
  int arreglo[elementos] = {1,3,4,5,17,18,31,33};
  
  cout <<"digite el numero que desee y se le devolvera su posicion " << endl;cin>>num;
  cout<< "Su valor si se encuentra en el arreglo y en la posicion :"<<buscar(arreglo,elementos,num)<< endl;
  return 0;
}

//funcion que hace la bsuqueda de tipo binaria
int buscar(int arreglo[], int elementos, int num){
int Barrasuperior = elementos-1,Barrainferior = 0,medio;  
    while (Barrainferior <= Barrasuperior){
    medio = (Barrasuperior + Barrainferior)/2;
    if (arreglo[medio] == num)
    return medio;
    else
    if (num < arreglo[medio])
    Barrasuperior=medio-1;
    else
    Barrainferior=medio+1;
    }
  return -1;
}

//funcion de comparacion de posicion del  arreglo
void Arreglo(int arreglo[], int elementos){
    for (int i = 0; i< elementos -1 ; i++)
    for (int j = 0; j< elementos -1 ; j++)
    if (arreglo[j] > arreglo[j+1])
 inter(arreglo[j],arreglo[j+1]);
}

void inter(int &a, int &b){
  int tmp = b;
  b = a;
  a = tmp;
}