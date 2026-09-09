// Archivo: pila.cpp
// TDA Pila - IMPLEMENTACION (parte privada / oculta para el cliente)

#include "pila.h"

bool apilar(Pila &pila, int elemento) {
    if (pilaLlena(pila)) {
        return false;
    }
    pila.ptrCima++;
    pila.vec[pila.ptrCima] = elemento;
    return true;
}

int desapilar(Pila &pila) {
    if (pilaVacia(pila)) {
        return -1; // Pila vacia
    }
    int valor = pila.vec[pila.ptrCima];
    pila.ptrCima--;
    return valor;
}

int tope(const Pila &pila) {
    if (pilaVacia(pila)) {
        return -1; // Pila vacia
    }
    return pila.vec[pila.ptrCima];
}

bool pilaVacia(const Pila &pila) {
    return pila.ptrCima == -1;
}

bool pilaLlena(const Pila &pila) {
    return pila.ptrCima >= TAMp - 1;
}
