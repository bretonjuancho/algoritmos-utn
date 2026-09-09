// Archivo: cola.cpp
// TDA Cola - IMPLEMENTACION (parte privada / oculta para el cliente)

#include "cola.h"

bool encolar(Cola &cola, int elemento) {
    if (colaLlena(cola)) {
        return false;
    }
    cola.vec[cola.fin] = elemento;
    cola.fin = (cola.fin + 1) % TAMc;
    return true;
}

int desencolar(Cola &cola) {
    if (colaVacia(cola)) {
        return -1; // Cola vacia
    }
    int valor = cola.vec[cola.inicio];
    cola.inicio = (cola.inicio + 1) % TAMc;
    return valor;
}

int frente(const Cola &cola) {
    if (colaVacia(cola)) {
        return -1; // Cola vacia
    }
    return cola.vec[cola.inicio];
}

bool colaVacia(const Cola &cola) {
    return cola.inicio == cola.fin;
}

bool colaLlena(const Cola &cola) {
    return (cola.fin + 1) % TAMc == cola.inicio;
}
