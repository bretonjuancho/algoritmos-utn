// Archivo: fraccion.h
// TDA Fraccion - REPRESENTACION + INTERFAZ (parte publica)
// Basado en diapositiva 15_ClaseTeoria_TDA.pdf (TDA Fraccion)

#ifndef FRACCION_H
#define FRACCION_H

// 1) REPRESENTACION: como guardamos una fraccion internamente.
//    Una fraccion es un par ordenado de enteros: numerador / denominador.
struct fraccion {
    int num; // numerador
    int den; // denominador (nunca debe ser 0)
};

fraccion asigFrac(int x, int y);

fraccion sumFrac(fraccion a, fraccion b);

fraccion restFrac(fraccion a, fraccion b);

fraccion multFrac(fraccion a, fraccion b);

fraccion divFrac(fraccion a, fraccion b);

int fracIguales(fraccion a, fraccion b);

int fracEquiv(fraccion a, fraccion b);

void printFrac(fraccion f);

#endif
