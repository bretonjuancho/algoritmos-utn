# 📚 Matrices — Ejercicios recomendados

<div align="center">

Ejercicios prácticos para entrenar **Matrices** (arreglos de dos dimensiones).

</div>

---

## 📖 El tema en breve

Una matriz de `F x C` almacena datos en filas y columnas, accediendo a cada elemento con dos índices: `matriz[i][j]` (fila `i`, columna `j`).

Los patrones que se entrenan en estos ejercicios son:

- Recorrido completo por filas y por columnas.
- Acumuladores por fila/columna, máximos y filtros por cota.
- Condiciones sobre la diagonal principal (`i == j`) y secundaria (`i + j == N - 1`).
- Recorrido por bordes hacia adentro (espiral / caracol) y desde el centro hacia fuera (caracol inverso).

---

## 📋 Ejercicios resueltos

| # | Ejercicio | Descripción | Dificultad |
|---|-----------|-------------|------------|
| 1 | [Tráfico de servidores](./traficoServidores/) | Matriz `N x N` de kb enviados entre servidores. Total enviado por servidor, servidor con mayor envío y servidores que recibieron más de una cota `M`. | ⭐ Baja |
| 2 | [Matriz diagonal](./esDiagonal/) | Función `esDiagonal`: verifica que todo elemento fuera de la diagonal principal sea cero (`i != j`). | ⭐ Baja |
| 3 | [Cuadrado mágico](./cuadradoMagico/) | Función `esMagico`: verifica que todas las filas, columnas y ambas diagonales sumen lo mismo. | ⭐⭐ Media |
| 4 | [Ingreso en caracol](./ingresoCaracol/) | Llena una matriz `FILAS x COLUMNAS` en espiral horaria desde `(0,0)` hacia adentro, con la secuencia `1, 2, 3, ...`. | ⭐⭐⭐ Alta |
| 5 | [Ingreso en caracol inverso](./ingresoCaracolInverso/) | Llena una matriz `N x N` en espiral desde el centro hacia fuera, con el `1` en el centro y `N * N` en `(0,0)`. Equivale al caracol clásico numerado al revés. | ⭐⭐⭐ Alta |

---

## Recomendaciones

- Intentá resolver primero cada ejercicio sin mirar las soluciones.
- Probá tu solución con casos borde (matriz `1x1`, `1xN`, `Nx1`, matriz nula, identidad, rectangular).
- Orden sugerido por dificultad: diagonal → tráfico → cuadrado mágico → caracol → caracol inverso.
