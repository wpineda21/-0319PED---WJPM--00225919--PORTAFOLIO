#include <iostream>
#include <string>
using namespace std;

struct Orden{
    string Nombre;
    string pan;
    string ingredientes;
    int tiempo;
};

// Tipo de dato que contendran los nodos de la Cola
typedef Orden T;
const T noValido = {{" "},{" "},{" "},-1};

// Registros: nodo y Cola
struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

// Prototipos de funciones para Cola
void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct Subway{
    Cola ordenPedidos;
    int panesHechos;
};
Subway  subway;

//Prototipos de funciones principales
void agregar();
void consultar();
void servir();
void vertodos();

int main(){
 
    initialize(&subway.ordenPedidos);
    subway.panesHechos = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos lo.s pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);
    return 0;


}

// Implementacion de funciones
void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    // Transfiriendo desde q hasta colaTemporal
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

// Funciones ---------------------------------------
void agregar(){
    // Solicitar datos del pedido
    T Unpan;
    cout << "Digite su apellido: "; getline(cin, Unpan.Nombre);
    cout << "Digite el pan a utilizar "; getline(cin,Unpan.pan);
    cout << "Cantidad de revueltas: "; cin >> getline(cin,Unpan.ingredientes);

    // Agregar a la cola
    enqueue(&subway.ordenPedidos, Unpan);
    // Modificar contadores
}

void consultar(){
    cout << "Pedidos en espera: " << size(&subway.colaPedidos) << endl;

}

void servir(){
    T pedidoDespachado = dequeue(&subway.colaPedidos);
    cout << "Familia " << pedidoDespachado.Nombre << " su pedido esta listo\n";

}

void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    // Transfiriendo desde subway.colaPedidos hasta colaTemporal
    while(!empty(&subway.colaPedidos)){
        T Unpan = dequeue(&subway.colaPedidos);
        enqueue(&colaTemporal, Unpan);
        
        cout << "Info del pedido: " << Unpan.Nombre << ", ";
        cout << "Pan Seleccionado: " << Unpan.pan << ", ";
        cout << "Ingredientes: "  << Unpan.ingredientes << ", ";

    }
    // Transfiriendo desde colaTemporal hasta subway.colaPedidos
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&subway.colaPedidos, elemento);
    }
}

