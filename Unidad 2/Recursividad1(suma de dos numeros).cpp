#include <iostream>

using namespace std;

int sum (int a,int b);

int main(void){
    int a=0,b=0;

    cout<<"Ingrese los numeros a Sumar  por favor"<<endl;
    cout<<"Ingrese Primer numero :  "; cin>>a;
    cout<<"Ingrese Segundo Numero:  ";cin>>b;

    sum (a,b);
    cout << sum(a,b) << endl;
}

int sum(int a,int b){

if (b==1){
    return 1;
    }else{

     return a+(b);

}
}            