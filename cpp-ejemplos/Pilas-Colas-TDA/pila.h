// Archivo: pila.h
// TDA Pila - REPRESENTACION + INTERFAZ (parte publica)
// Pila LIFO con arreglo estatico de capacidad TAMp.

#ifndef PILA_H
#define PILA_H
#define TAMp 10

// Representacion: vec guarda los datos, ptrCima es el indice de la cima.
// ptrCima == -1 significa pila vacia.
struct Pila {
    int vec[TAMp];
    int ptrCima = -1;
};

// Apila un elemento en la cima. Devuelve false si la pila esta llena.
bool apilar(Pila &, int);

// Desapila y devuelve la cima. Si esta vacia devuelve -1.
// Limitacion didactica: -1 no se puede usar como dato valido.
// Para chequear antes, usar pilaVacia().
int desapilar(Pila &);

// Devuelve la cima sin sacarla. Si esta vacia devuelve -1.
int tope(const Pila &);

bool pilaVacia(const Pila &);
bool pilaLlena(const Pila &);

#endif
