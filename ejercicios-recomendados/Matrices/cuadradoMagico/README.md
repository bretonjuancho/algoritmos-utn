# Cuadrado mágico (cuadradoMagico)

## Enunciado

Escribir la función `esMagico` que indique si la matriz recibida como argumento es un cuadrado mágico o no.

Un cuadrado mágico es una disposición de números naturales en una tabla cuadrada, de forma tal que las sumas de cada columna, de cada fila y de cada diagonal son iguales. 

En este ejercicio se considera cuadrado mágico si **todas las filas, todas las columnas y las dos diagonales suman lo mismo**.

Por ejemplo, la siguiente matriz **no** es un cuadrado mágico (la primera fila suma `9` y la segunda suma `13`):

```text
3 1 5
4 7 2
9 8 6
```

`esMagico(A) → False`

Mientras que la siguiente sí lo es (todas las filas, columnas y diagonales suman `15`):

```text
2 7 6
9 5 1
4 3 8
```

`esMagico(A) → True`

## Entrada

1. La dimensión `N` de la matriz cuadrada (`N x N`).
2. `N` filas con `N` valores enteros cada una.

Restricciones: `1 <= N <= 100`.

## Salida

El programa indica el resultado de evaluar `esMagico` sobre la matriz ingresada:

- `Es magico` si todas las filas, columnas y diagonales suman lo mismo.
- `No es magico` en caso contrario.

## Ejemplos

### Ejemplo 1 (no es mágico)

Entrada:

```text
3
3 1 5
4 7 2
9 8 6
```

Salida:

```text
No es magico
```

### Ejemplo 2 (cuadrado mágico de 3x3, suma 15)

Entrada:

```text
3
2 7 6
9 5 1
4 3 8
```

Salida:

```text
Es magico
```

### Ejemplo 3 (cuadrado mágico de 4x4, suma 34)

Entrada:

```text
4
16 2 3 13
5 11 10 8
9 7 6 12
4 14 15 1
```

Salida:

```text
Es magico
```

### Ejemplo 4 (matriz de 1x1, siempre es mágico)

Entrada:

```text
1
7
```

Salida:

```text
Es magico
```
