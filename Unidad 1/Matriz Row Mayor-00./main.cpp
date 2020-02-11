#include<iostream>// Libreria que permite la entra y salida de data
using namespace std;



//Varianles Globales
int **puntero1,**puntero2,Rows,Columns;


//Prototipo de funciones
void Data();
void Sum(int **,int **,int,int);
void Show(int **,int,int);


int main(){
	Data();
	Sum(puntero1,puntero2,Rows,Columns);
	Show(puntero1,Rows,Columns);
	return 0;
}

void Data(){

	//declaracion de matriz dinamica
	cout<<""<<endl;
	cout<<"Digite el numero de filas: ";
	cin>>Rows;
	cout<<"Digite el numero de columnas: ";
	cin>>Columns;
	cout<<""<<endl;

	//Reservando espacio de memoria para una matriz
	puntero1 = new int*[Rows]; 
	for(int i=0;i<Rows;i++){
		puntero1[i] = new int[Columns]; 
	}
	//pidiendo datos primera matriz
	cout<<"\nDigitando los elementos de la primera matriz: \n";
	for(int i=0;i<Rows;i++){
		for(int j=0;j<Columns;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero1+i)+j); 
		}
	}
	
	//Reservando memoria Segunda  Matriz
	puntero2 = new int*[Rows]; 
	for(int i=0;i<Rows;i++){
		puntero2[i] = new int[Columns];
	}
	//Pidiendo datos segunda matriz
	cout<<"\nDigitando los elementos de la segunda matriz: \n";
	for(int i=0;i<Rows;i++){
		for(int j=0;j<Columns;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero2+i)+j); //puntero1[i][j]
		}
	}
}

//Sumando Matriz
void Sum(int **puntero1,int **puntero2,int Rows,int Columns){
	for(int i=0;i<Rows;i++){
		for(int j=0;j<Columns;j++){
			*(*(puntero1+i)+j) += *(*(puntero2+i)+j);  
}
}
}
//Mostrando matriz
void Show(int **putero_matriz1,int Rows,int Columns){
	cout<<"\nLa Sum de ambas matrices es: \n";
	for(int i=0;i<Rows;i++){
		for(int j=0;j<Columns;j++){
			cout<<*(*(puntero1+i)+j)<<" ";
}
cout<<"\n";
}
}
