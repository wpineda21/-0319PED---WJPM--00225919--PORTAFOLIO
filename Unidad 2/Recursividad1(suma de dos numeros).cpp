#include <iostream>//libreria para entrada y salida de datos

using namespace std;

//prototipo de funciones
int sum (int a,int b);


//funcion principal
int main(void){
    int a=0,b=0;

    cout<<"Ingrese los numeros a Sumar  por favor"<<endl;
    cout<<"Ingrese Primer numero :  "; cin>>a;
    cout<<"Ingrese Segundo Numero:  ";cin>>b;
    
    //llamando ala funcion recursiva y pasandole parametros
    sum (a,b);
    cout << sum(a,b) << endl;
}

//fucion recursiva que suma los numeros
int sum(int a,int b){

if (b==1){
    return 1;
    }else{

     return a+(b);

}
}            