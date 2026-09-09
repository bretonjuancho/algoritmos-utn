// Archivo: main.cpp
// USO del TDA Fraccion (codigo del "cliente").
// El cliente SOLO conoce fraccion.h (representacion + prototipos).
// No necesita saber COMO estan implementadas las funciones.

#include <iostream>
#include "fraccion.h" // comillas "" porque es NUESTRO header, no del sistema
using namespace std;

int main() {
    int n, d;

    // 1) Pedimos una fraccion al usuario y la creamos con asigFrac.
    cout << "Ingrese una fraccion como num seguido de den: ";
    cin >> n >> d;

    fraccion fa, fb, fc;
    fa = asigFrac(n, d);
    fb = asigFrac(3, 5); // fraccion fija de ejemplo (como en la diapositiva 22)

    // 2) Operamos usando SOLO la interfaz del TDA.
    fc = multFrac(fa, fb);

    // 3) Mostramos resultados usando SOLO la interfaz del TDA.
    cout << endl << "El resultado de la multiplicacion por 3/5 es: ";
    printFrac(fc);
    cout << endl;

    // Ejemplo extra: suma y comparaciones.
    fraccion suma = sumFrac(fa, fb);
    cout << "La suma es: ";
    printFrac(suma);
    cout << endl;

    if (fracEquiv(fa, fb)) {
        cout << "Son equivalentes (valen lo mismo)." << endl;
    } else {
        cout << "No son equivalentes." << endl;
    }

    if (fracIguales(fa, fb)) {
        cout << "Son iguales (mismo num y mismo den)." << endl;
    } else {
        cout << "No son iguales." << endl;
    }

    // Pausa compatible con Zinjai y con consola normal.
    // (Evitar system("pause"): solo funciona en Windows y algunos antivirus lo bloquean).
    cout << endl << "Presione ENTER para terminar...";
    cin.ignore();
    cin.get();
    return 0;
}

