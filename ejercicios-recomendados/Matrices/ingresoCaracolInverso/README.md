# Ingreso en caracol inverso (espiral desde el centro)

## Enunciado

Escribir un programa que, teniendo una matriz cuadrada de `N x N`, inicialice el valor de sus elementos en forma de espiral (caracol) **desde el elemento central hacia fuera**, con la secuencia `1, 2, 3, ...`.

El `1` va en el centro de la matriz y los números siguientes lo rodean en espiral en sentido horario hasta llegar a `N * N`, que queda en la esquina superior izquierda `(0,0)`.

Por ejemplo, para `N = 5`:

```text
25 24 23 22 21
10  9  8  7 20
11  2  1  6 19
12  3  4  5 18
13 14 15 16 17
```

## Recorrido

Si se lee la matriz en el orden en que se asignaron los valores (`1, 2, 3, ...`), el recorrido desde el centro es:

1. Un paso a la **izquierda**.
2. Un paso hacia **abajo**.
3. Dos pasos a la **derecha**.
4. Dos pasos hacia **arriba**.
5. Tres pasos a la **izquierda**, tres hacia **abajo**, y así sucesivamente, aumentando el largo del tramo cada dos giros, hasta completar la matriz.

> **Equivalencia útil:** este caracol inverso es el mismo recorrido que el [caracol clásico](../ingresoCaracol/) (espiral horaria desde `(0,0)` hacia adentro), pero numerado al revés: donde el caracol clásico pone `k`, el inverso pone `N * N + 1 - k`. Por eso la forma más simple de implementarlo es reutilizar el algoritmo por bordes (`sup, inf, izq, der`) empezando el contador en `N * N` y decrementando.

## Entrada

1. La dimensión `N` de la matriz cuadrada.

Restricciones: `1 <= N <= 100`.

## Salida

La matriz de `N x N` completa en espiral inversa, mostrando cada fila en una línea con los valores separados por un espacio.

## Ejemplos

### Ejemplo 1 (enunciado original)

Entrada:

```text
5
```

Salida:

```text
25 24 23 22 21
10 9 8 7 20
11 2 1 6 19
12 3 4 5 18
13 14 15 16 17
```

### Ejemplo 2 (matriz chica impar)

Entrada:

```text
3
```

Salida:

```text
9 8 7
2 1 6
3 4 5
```

### Ejemplo 3 (caso borde 1x1)

Entrada:

```text
1
```

Salida:

```text
1
```

### Ejemplo 4 (matriz par)

Entrada:

```text
4
```

Salida:

```text
16 15 14 13
5 4 3 12
6 1 2 11
7 8 9 10
```

## Casos de prueba

| # | Entrada (`N`) | Salida esperada | Qué verifica |
|---|---------------|-----------------|--------------|
| 1 | `1` | `1` | Caso borde mínimo, el centro es toda la matriz |
| 2 | `2` | `4 3` / `1 2` | Caso par mínimo, sin un único centro |
| 3 | `3` | `9 8 7` / `2 1 6` / `3 4 5` | Espiral impar chica, giro completo alrededor del centro |
| 4 | `5` | (ver Ejemplo 1) | Caso del enunciado, dos vueltas completas |
| 5 | `4` | `16 15 14 13` / `5 4 3 12` / `6 1 2 11` / `7 8 9 10` | Dimensión par: el `1` queda en el centro del bloque `2x2` interior |

> Para verificar rápido: la esquina `(0,0)` siempre vale `N * N` y el centro (o bloque central si `N` es par) siempre contiene al `1`.