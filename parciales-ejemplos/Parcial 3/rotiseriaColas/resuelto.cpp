// Parcial 3 (ejemplo) - Ejercicio de Papel: "La rotiseria de Sofia"
// Resolucion posible. Tema principal: Colas (cola circular con arreglo).
#include <iostream>
#include <string>
using namespace std;

// =====================================================================
// 1. TDA PEDIDO - Estructuras de datos
// =====================================================================
const int RETIRA = 0;    // retira en el local
const int DELIVERY = 1;  // envio a domicilio

struct Cliente {
    string nombre;
    string telefono;
};

struct Pedido {
    int numero;
    Cliente cliente;
    int cantEmpanadas;
    double importe;
    int tipo;            // RETIRA o DELIVERY
};

// =====================================================================
// 2. TDA PEDIDO - Asignacion y consulta
// =====================================================================
Pedido crearPedido(int numero, Cliente cli, int cant, double importe, int tipo) {
    Pedido p;
    p.numero = numero;
    p.cliente = cli;
    p.cantEmpanadas = cant;
    p.importe = importe;
    p.tipo = tipo;
    return p;
}

void setCliente(Pedido &p, Cliente cli)   { p.cliente = cli; }
Cliente getCliente(Pedido p)              { return p.cliente; }

void setImporte(Pedido &p, double imp)    { p.importe = imp; }
double getImporte(Pedido p)               { return p.importe; }

void setTipo(Pedido &p, int tipo)         { p.tipo = tipo; }
int getTipo(Pedido p)                     { return p.tipo; }

int getNumero(Pedido p)                   { return p.numero; }

// =====================================================================
// 3. COLA DE PEDIDOS - Estructuras + primitivas (cola circular)
// =====================================================================
const int MAX_PEDIDOS = 50;
const int TAMC = MAX_PEDIDOS + 1;   // se reserva un lugar para distinguir llena de vacia

struct ColaPedidos {
    Pedido vec[TAMC];
    int inicio;   // posicion del primer pedido
    int fin;      // primera posicion libre
};

void crearCola(ColaPedidos &c) {
    c.inicio = 0;
    c.fin = 0;
}

bool colaVacia(const ColaPedidos &c) {
    return c.inicio == c.fin;
}

bool colaLlena(const ColaPedidos &c) {
    return (c.fin + 1) % TAMC == c.inicio;
}

bool encolar(ColaPedidos &c, Pedido p) {
    if (colaLlena(c)) {
        return false;
    }
    c.vec[c.fin] = p;
    c.fin = (c.fin + 1) % TAMC;
    return true;
}

// Precondicion: la cola no esta vacia.
Pedido desencolar(ColaPedidos &c) {
    Pedido p = c.vec[c.inicio];
    c.inicio = (c.inicio + 1) % TAMC;
    return p;
}

// =====================================================================
// 4. imprimirPedidos
//    La cola se recibe POR VALOR: se desencola una copia y la cola
//    original del programa que llama queda intacta.
// =====================================================================
double imprimirPedidos(ColaPedidos c) {
    double total = 0;
    while (!colaVacia(c)) {
        Pedido p = desencolar(c);
        cout << "Pedido " << getNumero(p) << " - " << getCliente(p).nombre;
        if (getTipo(p) == DELIVERY) {
            cout << " (delivery)";
        }
        cout << endl;
        total += getImporte(p);
    }
    return total;
}

// =====================================================================
// 5. separarDelivery
//    Devuelve una cola con los pedidos de delivery y deja en la cola
//    recibida solo los que se retiran en el local. Ambas respetan el
//    orden original. Complejidad: Theta(N), una sola pasada.
// =====================================================================
ColaPedidos separarDelivery(ColaPedidos &pedidos) {
    ColaPedidos delivery, local;
    crearCola(delivery);
    crearCola(local);

    while (!colaVacia(pedidos)) {
        Pedido p = desencolar(pedidos);
        if (getTipo(p) == DELIVERY) {
            encolar(delivery, p);
        } else {
            encolar(local, p);
        }
    }
    pedidos = local;   // asignacion de structs completos: valida en C++
    return delivery;
}

// =====================================================================
// Programa de prueba (no se pide en el parcial)
// =====================================================================
int main() {
    ColaPedidos cola;
    crearCola(cola);

    Cliente ana  = {"Ana",  "342-111"};
    Cliente beto = {"Beto", "342-222"};
    Cliente caro = {"Caro", "342-333"};
    Cliente dani = {"Dani", "342-444"};
    Cliente eli  = {"Eli",  "342-555"};

    encolar(cola, crearPedido(1, ana,  12, 18000, RETIRA));
    encolar(cola, crearPedido(2, beto,  6,  9500, DELIVERY));
    encolar(cola, crearPedido(3, caro, 24, 34000, DELIVERY));
    encolar(cola, crearPedido(4, dani,  6,  9000, RETIRA));
    encolar(cola, crearPedido(5, eli,  12, 19500, DELIVERY));

    cout << "== Todos los pedidos ==" << endl;
    double total = imprimirPedidos(cola);
    cout << "Total: $" << total << endl;

    cout << "\n== La cola original sigue intacta ==" << endl;
    imprimirPedidos(cola);

    ColaPedidos delivery = separarDelivery(cola);
    cout << "\n== Delivery ==" << endl;
    total = imprimirPedidos(delivery);
    cout << "Total: $" << total << endl;
    cout << "\n== Retiran en el local ==" << endl;
    total = imprimirPedidos(cola);
    cout << "Total: $" << total << endl;

    // Caso de cola circular: el indice fin "da la vuelta"
    ColaPedidos c2;
    crearCola(c2);
    for (int i = 1; i <= MAX_PEDIDOS; i++) {
        encolar(c2, crearPedido(i, ana, 1, 1, i % 2));
    }
    cout << "\nLlena con " << MAX_PEDIDOS << ": " << colaLlena(c2) << endl;
    for (int i = 0; i < 30; i++) desencolar(c2);
    for (int i = 51; i <= 70; i++) encolar(c2, crearPedido(i, beto, 1, 1, i % 2));
    ColaPedidos d2 = separarDelivery(c2);
    int nd = 0, nl = 0;
    while (!colaVacia(d2)) { desencolar(d2); nd++; }
    while (!colaVacia(c2)) { desencolar(c2); nl++; }
    cout << "Delivery: " << nd << "  Local: " << nl << " (esperado 20 y 20)" << endl;
    return 0;
}
