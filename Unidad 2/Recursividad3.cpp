#include <iostream>//libreria para entrada y salida de datos
using namespace std;

//Prototipo de funcion
void buscar(int *A, int *B, int X);


//funcion princiapal
int main(){

	int vector[5], numero;
	cout<<"Ingrese los numeros a guardar: "<<endl;
	for(int i = 0; i < 5; i++){
	cout<<"Ingrese el "<<i+1<<" valor: ";cin>>vector[i];
	}
	cout<<"\n"<<endl;
	cout<<"Ingrese el Numero a buscar: "<<endl;cin>>numero;
	
	//llamada de funcion dentro del main
	buscar(vector, vector + 5, numero);

	return 0;

}

//funcion recursiva que busca los numeros
void buscar(int *A, int *B, int X){
	if(A < B){
		if(*A == X){
			cout<<"SI se encuentra en el arreglo el numero : " <<*A<<endl;
		}else{
			buscar(A + 1, B, X);
		}
	}else{
		cout<<"\n"<<endl;
		cout<<"No se encontro el numero"<<endl;
	}
}
