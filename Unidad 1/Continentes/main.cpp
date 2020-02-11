#include <iostream>
#include <string>
using namespace std;

struct Country{
        string  Principal,Country;
        int Hab,aux;
};typedef Country T;

void Calcular(T elemento[]);

int main(){	
    T country1[3];
    for (int i = 0; i < 3; i++){
        cout <<"escriba el Pais "<<i+1<<":";
        getline(cin,country1[i].Country);
        cout <<"escriba la Capital "<<i+1<<":";
 		getline(cin,country1[i].Principal);
        cout <<"escriba el numero de habitantes "<<i+1<<":";
        cin >> country1[i].Hab;
        cout <<"escriba el promedio de las edades de los habitantes "<<i+1<<":";
        cin >>country1[i].aux;
        cout<<"\n"<<endl;
        cin.ignore();
    }
    Calcular(country1);

   return 0;
}


void Calcular(T elemento[]){
    
    int T1=0;
    float P1=0,P2=0;    
    string opt;
    cout<<"El o los contientes al que pertenece los paises : "<<endl;
	getline(cin,opt);
	cout<<""<<endl;

    for (int i = 0; i < 3; i++){
        cout<<""<<elemento[i].Country<<endl;
        cout<<""<<elemento[i].Principal<<endl;
        cout<<""<<elemento[i].Hab<<endl;
        T1+= elemento[i].Hab;
        cout<<""<<elemento[i].aux<<endl;
        P1+= elemento[i].aux;
        P2=P1/3;
    }
   cout<<"\n"<<endl; 
   cout << "el Total de  habitantes de los paises es: "<<endl;
   cout <<T1<<endl; 
   cout << "el  promedio es: "<<endl; 
   cout <<P2<<"\n"<<endl; 
}