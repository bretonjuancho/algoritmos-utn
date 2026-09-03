# Matriz diagonal (esDiagonal)

## Enunciado

Escribir la función `esDiagonal` que indique si la matriz recibida como argumento es diagonal o no.

Una matriz cuadrada `A` de `N x N` es diagonal si todos los elementos que **no** están en la diagonal principal tienen el valor cero. Es decir, `A[i][j] == 0` para todo `i != j`. Los elementos de la diagonal principal (`i == j`) pueden ser cualquier valor, incluido el cero.

Por ejemplo, la siguiente matriz es diagonal:

```text
1 0 0
0 6 0
0 0 1
```

`esDiagonal(A) → True`

Mientras que esta no lo es (el `5` está fuera de la diagonal principal):

```text
1 0 0
0 6 5
0 0 1
```

`esDiagonal(A) → False`

## Entrada

1. La dimensión `N` de la matriz cuadrada (`N x N`).
2. `N` filas con `N` valores enteros cada una.

Restricciones: `1 <= N <= 100`

## Salida

El programa indica el resultado de evaluar `esDiagonal` sobre la matriz ingresada:

- `Es diagonal` si todos los elementos fuera de la diagonal principal son cero.
- `No es diagonal` en caso contrario.

## Ejemplos

### Ejemplo 1 (matriz diagonal)

Entrada:

```text
3
1 0 0
0 6 0
0 0 1
```

Salida:

```text
Es diagonal
```

### Ejemplo 2 (no diagonal, elemento fuera de la diagonal distinto de cero)

Entrada:

```text
3
1 0 0
0 6 5
0 0 1
```

Salida:

```text
No es diagonal
```

### Ejemplo 3 (matriz identidad de 4x4, es diagonal)

Entrada:

```text
4
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
```

Salida:

```text
Es diagonal
```

### Ejemplo 4 (matriz de 1x1, siempre es diagonal)

Entrada:

```text
1
7
```

Salida:

```text
Es diagonal
```
