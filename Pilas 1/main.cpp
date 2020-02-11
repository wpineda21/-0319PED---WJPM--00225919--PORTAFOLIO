#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack <int> s;
    int contador=0 ;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);


    cout<<"el tamano de la pila es "<<s.size()<<endl;

    
    while(!s.empty()){
        s.pop();
        s.pop();
        s.pop();
        int  ultimonumero = s.top();
        cout << ultimonumero<<endl;
        cout<<"el top de la pila es "<<s.top()<<endl;

    }
    return 0;
    
}