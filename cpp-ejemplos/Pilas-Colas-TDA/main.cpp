// Archivo: main.cpp
// USO de los TDA Pila y Cola (codigo del "cliente").
// El cliente SOLO conoce pila.h y cola.h (representacion + prototipos).

#include <iostream>
#include "pila.h" // comillas "" porque es NUESTRO header, no del sistema
#include "cola.h"
using namespace std;

int main() {
    // La cola circular guarda como maximo TAMc - 1 = 9 elementos.
    // Para que la demo sirva para ambas estructuras, pedimos de 1 a 9.
    const int MAX_DEMO = TAMc - 1;
    Pila miPila;
    Cola miCola;
    int n, elemento;

    cout << "Cantidad de elementos a cargar (1 a " << MAX_DEMO << "): ";
    if (!(cin >> n) || n < 1 || n > MAX_DEMO) {
        cout << "Cantidad invalida. Debe ser entre 1 y " << MAX_DEMO << "." << endl;
        return 1;
    }

    cout << "Ingrese " << n << " enteros para la PILA: ";
    for (int i = 0; i < n; i++) {
        cin >> elemento;
        if (!apilar(miPila, elemento)) {
            cout << "Error: pila llena, no se pudo apilar." << endl;
            return 1;
        }
    }

    cout << "Ingrese " << n << " enteros para la COLA: ";
    for (int i = 0; i < n; i++) {
        cin >> elemento;
        if (!encolar(miCola, elemento)) {
            cout << "Error: cola llena, no se pudo encolar." << endl;
            return 1;
        }
    }

    // Consulta sin remover (para mostrar tope vs frente).
    cout << endl << "Tope de la pila (ultimo que entro): " << tope(miPila) << endl;
    cout << "Frente de la cola (primero que entro): " << frente(miCola) << endl;

    // Vaciamos ambas para ver la diferencia LIFO vs FIFO.
    cout << endl << "Vaciando PILA (sale ultimo primero - LIFO): ";
    while (!pilaVacia(miPila)) {
        cout << desapilar(miPila) << " ";
    }
    cout << endl;

    cout << "Vaciando COLA (sale primero primero - FIFO): ";
    while (!colaVacia(miCola)) {
        cout << desencolar(miCola) << " ";
    }
    cout << endl;

    // Pausa compatible con Zinjai y con consola normal.
    // (Evitar system("pause"): solo funciona en Windows y algunos antivirus lo bloquean).
    cout << endl << "Presione ENTER para terminar...";
    cin.ignore();
    cin.get();
    return 0;
}
