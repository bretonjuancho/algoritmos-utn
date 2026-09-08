// Archivo: fraccion.cpp
// TDA Fraccion - IMPLEMENTACION (parte privada / oculta para el cliente)
// Aqui va el COMO se hace cada operacion. El main.cpp NO necesita ver
// este archivo, solo necesita el .h. Pero este .cpp SI debe compilarse
// junto al main (ver README).

#include "fraccion.h"
#include <iostream>
using namespace std;

// Crea una fraccion. Si el denominador es 0 lo corregimos a 1
// para evitar division por cero (decision simple de disenio).
fraccion asigFrac(int x, int y) {
    fraccion aux;
    aux.num = x;
    if (y == 0) {
        cout << "Advertencia: denominador 0 no permitido, se usa 1." << endl;
        aux.den = 1;
    } else {
        aux.den = y;
    }
    return aux;
}

// Suma: a/b + c/d = (a*d + c*b) / (b*d)
// Version simple de la diapositiva 23 (no simplifica el resultado).
fraccion sumFrac(fraccion a, fraccion b) {
    fraccion aux;
    aux.den = a.den * b.den;
    aux.num = b.den * a.num + a.den * b.num;
    return aux;
}

// Resta: a/b - c/d = (a*d - c*b) / (b*d)
fraccion restFrac(fraccion a, fraccion b) {
    fraccion aux;
    aux.den = a.den * b.den;
    aux.num = b.den * a.num - a.den * b.num;
    return aux;
}

// Multiplicacion: (a/b) * (c/d) = (a*c) / (b*d)
fraccion multFrac(fraccion a, fraccion b) {
    fraccion aux;
    aux.num = a.num * b.num;
    aux.den = a.den * b.den;
    return aux;
}

// Division: (a/b) / (c/d) = (a*d) / (b*c)
fraccion divFrac(fraccion a, fraccion b) {
    fraccion aux;
    aux.num = a.num * b.den;
    aux.den = a.den * b.num;
    return aux;
}

// Iguales: mismo numerador Y mismo denominador.
int fracIguales(fraccion a, fraccion b) {
    return (a.num == b.num && a.den == b.den);
}

// Equivalentes: mismo valor. Ej: 1/2 == 2/4.
// Truco: a/b == c/d si a*d == b*c (evitamos usar float).
int fracEquiv(fraccion a, fraccion b) {
    return (a.num * b.den == a.den * b.num);
}

// Muestra la fraccion como "num / den".
void printFrac(fraccion f) {
    cout << f.num << " / " << f.den;
}
