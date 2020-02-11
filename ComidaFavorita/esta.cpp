#include <iostream>
#include <string>
using namespace std;

struct Pedido{
    string apellido;
    int mesa;
    int revueltas;
    int queso;
    int frijolqueso;
    int tiempo;
};

// Tipo de dato que contendran los nodos de la Cola
typedef Pedido T;
const T noValido = {{" "},-1,-1,-1,-1,-1};

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

struct Pupuseria{
    Cola colaPedidos;
    int pupusasHechas;
};
Pupuseria laBendicion;

void agregar();
void consultar();
void servir();
void vertodos();

int main(){
    initialize(&laBendicion.colaPedidos);
    laBendicion.pupusasHechas = 0;
    
    bool continuar = true;
    do{
       
        cout<<&laBendicion.colaPedidos.frente<<endl;  
        int opcion = 0;
        cout<<""<<endl;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion;cin.ignore();

                
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
    Pedido unPedido;
    cout << "Digite su apellido: "; getline(cin, unPedido.apellido);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Cantidad de revueltas: "; cin >> unPedido.revueltas; cin.ignore();
    cout << "Cantidad de queso: "; cin >> unPedido.queso; cin.ignore();
    cout << "Cantidad de FQ: "; cin >> unPedido.frijolqueso; cin.ignore();
    unPedido.tiempo = (unPedido.revueltas+unPedido.queso+unPedido.frijolqueso) * 90;
    
    // Agregar a la cola
    enqueue(&laBendicion.colaPedidos, unPedido);
    // Modificar contadores
    laBendicion.pupusasHechas += (unPedido.revueltas+unPedido.queso+unPedido.frijolqueso);
}

void consultar(){
    cout << "Pedidos en espera: " << size(&laBendicion.colaPedidos) << endl;
    cout << "Total pupusas hechas: " << laBendicion.pupusasHechas << endl;
}

void servir(){
    Pedido pedidoDespachado = dequeue(&laBendicion.colaPedidos);
    cout << "Familia " << pedidoDespachado.apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.mesa << endl;
}

void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    // Transfiriendo desde laBendicion.colaPedidos hasta colaTemporal
    while(!empty(&laBendicion.colaPedidos)){
        Pedido unPedido = dequeue(&laBendicion.colaPedidos);
        enqueue(&colaTemporal, unPedido);
        
        cout << "Info del pedido: " << unPedido.apellido << ", ";
        cout << "R: " << unPedido.revueltas << ", ";
        cout << "Q: " << unPedido.queso << ", ";
        cout << "FQ: " << unPedido.frijolqueso << "\n\n";
    }
    // Transfiriendo desde colaTemporal hasta laBendicion.colaPedidos
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&laBendicion.colaPedidos, elemento);
    }
}

