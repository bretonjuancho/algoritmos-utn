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

// 2) INTERFAZ: operaciones primitivas que el usuario (cliente) puede usar.
//    Formato: Operacion(tipos de argumentos) -> resultado. Descripcion.

// Crea una fraccion a partir de dos enteros.
fraccion asigFrac(int x, int y);

// Suma dos fracciones.
fraccion sumFrac(fraccion a, fraccion b);

// Resta dos fracciones: a - b.
fraccion restFrac(fraccion a, fraccion b);

// Multiplica dos fracciones.
fraccion multFrac(fraccion a, fraccion b);

// Divide dos fracciones: a / b.
fraccion divFrac(fraccion a, fraccion b);

// Devuelve 1 (true) si tienen mismo numerador Y mismo denominador.
int fracIguales(fraccion a, fraccion b);

// Devuelve 1 (true) si tienen el mismo valor aunque se escriban distinto.
// Ejemplo: 1/2 y 2/4 son equivalentes pero no iguales.
int fracEquiv(fraccion a, fraccion b);

// Muestra una fraccion con el formato "numerador / denominador".
void printFrac(fraccion f);

#endif
