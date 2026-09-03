# Ingreso en caracol (Matriz espiral)

## Enunciado

Problema 7: Escribir un programa que llene una matriz de `FILAS x COLUMNAS` con la secuencia ordenada de números iniciada en `1`, desde el elemento `(0,0)` hacia adentro en forma de espiral (caracol), en sentido horario.

El recorrido es:

1. De izquierda a derecha por la fila superior disponible.
2. De arriba hacia abajo por la columna derecha disponible.
3. De derecha a izquierda por la fila inferior disponible.
4. De abajo hacia arriba por la columna izquierda disponible.
5. Repetir hacia adentro hasta completar la matriz.

Por ejemplo, para una matriz de `6 x 6`:

```text
1   2   3   4   5   6
20  21  22  23  24  7
19  32  33  34  25  8
18  31  36  35  26  9
17  30  29  28  27  10
16  15  14  13  12  11
```

## Entrada

1. La cantidad de filas `FILAS`.
2. La cantidad de columnas `COLUMNAS`.

Restricciones: `1 <= FILAS <= 100`, `1 <= COLUMNAS <= 100`.

## Salida

La matriz de `FILAS x COLUMNAS` completa en espiral, mostrando cada fila en una línea con los valores separados por un espacio.

## Ejemplos

### Ejemplo 1

Entrada:

```text
6 6
```

Salida:

```text
1 2 3 4 5 6
20 21 22 23 24 7
19 32 33 34 25 8
18 31 36 35 26 9
17 30 29 28 27 10
16 15 14 13 12 11
```

### Ejemplo 2 (matriz cuadrada chica)

Entrada:

```text
3 3
```

Salida:

```text
1 2 3
8 9 4
7 6 5
```

### Ejemplo 3 (matriz rectangular, más columnas que filas)

Entrada:

```text
3 4
```

Salida:

```text
1 2 3 4
10 11 12 5
9 8 7 6
```

### Ejemplo 4 (una sola fila)

Entrada:

```text
1 5
```

Salida:

```text
1 2 3 4 5
```
