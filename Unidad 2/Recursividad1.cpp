#include <iostream>//Libreria para uso de entra o salida de datos
using namespace std;

//prototipo de funcion
int Sum(int n1, int num);


int main(){
int n1=0,n2=0,p=0;

 cout << "Introduzca primer numero: ";
 cin >> n1;
 cout << "Introduzca segundo numero: ";
 cin >> n2;
 p=Sum(n1,n2);
 cout << "producto: " << p << endl;
	
}

int Sum(int n1, int num){
	if(num==1){
		cout << "n=" << num << " caso base" << endl;
		return n1;
	}else{
		int x = num - 1;
		int y = Sum(n1,x);
		cout << "n=" << n1 << " x=" << x <<	" y=" << y << endl;
		return n1 + y;
	}
}