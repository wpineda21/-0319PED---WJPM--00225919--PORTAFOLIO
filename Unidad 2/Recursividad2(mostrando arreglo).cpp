#include <iostream>//libreria de entra y salida de datos
using namespace std;

//variables globales
int Arreglo[6];
int numero;

//Prototipo de funciones
void Array(int tam);

//funcion principal
int main(){
cout<<"ingrese 5 numeros a continuacion por favor :  "<<endl;
Array(1);
for(int i = 1; i < 6; i++){
    cout<<"\n"<<endl;
    cout<<"los numeros son "<<endl;
    cout << Arreglo[i] << ' '<<endl;
}
return 0;
}


//funcion recursiva que recorre el arreglo
void Array(int tam){
if(tam == 6)
    return;
else{
    
    cout<<"Por favor ingrese un numero  :  "<<endl;
    cin >> numero;
    Arreglo[tam] = numero;
    Array(tam+1);
    
}

}