#include <iostream>
using namespace std;


int Arreglo[6];
int numero;

void Array(int tam);

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