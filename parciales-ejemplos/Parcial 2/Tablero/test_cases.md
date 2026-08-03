# Casos de Prueba - Parcial 2.3

## Ejercicio A: Función `puntajes()`

**Regla:** Un jugador gana 5 puntos por cada secuencia MAYÚSCULA-minúscula-minúscula-MAYÚSCULA en posiciones adyacentes. Las secuencias pueden superponerse.

### Casos de Prueba

| # | Tablero | Esperado J1 | Esperado J2 | Descripción |
|---|---------|-------------|-------------|-------------|
| 1 | `"RrrR"` | 5 | 0 | Secuencia básica jugador 1 |
| 2 | `"AaaA"` | 0 | 5 | Secuencia básica jugador 2 |
| 3 | `""` | 0 | 0 | Tablero vacío |
| 4 | `"RrRaA"` | 0 | 0 | Sin secuencias completas |
| 5 | `"RrrRAaaA"` | 5 | 5 | Una secuencia por jugador |
| 6 | `"RrrRrrR"` | 10 | 0 | Secuencias superpuestas jugador 1 |
| 7 | `"AaaAaaA"` | 0 | 10 | Secuencias superpuestas jugador 2 |
| 8 | `"RrrRAaaARrrR"` | 10 | 5 | Múltiples secuencias |
| 9 | `"RRrrR"` | 5 | 0 | MAYÚSCULA-MIN-MIN-MAY en pos 1-4 |
| 10 | `"rRRrr"` | 0 | 0 | No hay patrón completo |
| 11 | `"RrrR RrrR"` | 10 | 0 | Dos secuencias separadas por espacio |
| 12 | `"AaaA RrrR AaaA"` | 5 | 10 | Alternando secuencias |
| 13 | `"RrrRAaaARrrRAaaA"` | 10 | 10 | Patrón completo alternado |

---

## Ejercicio B: Función recursiva `eliminarJugadas()`

**Regla:** Elimina las piezas del jugador `j` del tablero y devuelve la cantidad de desplazamientos (elementos desplazados a la izquierda al eliminar).

### Casos de Prueba

| # | Tablero | Jugador j | Esperado | Descripción |
|---|---------|-----------|----------|-------------|
| 1 | `"RrrR"` | 1 | 6 | Eliminar 4 piezas R: 3+2+1+0=6 desplazamientos |
| 2 | `"AaaA"` | 2 | 6 | Eliminar 4 piezas A: 3+2+1+0=6 desplazamientos |
| 3 | `""` | 1 | 0 | Tablero vacío, nada que eliminar |
| 4 | `"RrAaR"` | 1 | 7 | Eliminar 3 piezas R de un tablero de 5 |
| 5 | `"RrAaR"` | 2 | 3 | Eliminar 2 piezas A de un tablero de 5 |
| 6 | `"RrrRAaaA"` | 1 | 22 | Eliminar 4 piezas R de un tablero de 8 |
| 7 | `"RrrRAaaA"` | 2 | 6 | Eliminar 4 piezas A de un tablero de 8 |
| 8 | `"AaRrAa"` | 1 | 5 | Eliminar 2 piezas R del medio |
| 9 | `"AaRrAa"` | 2 | 10 | Eliminar 4 piezas A (extremos y medio) |
| 10 | `"RRRR"` | 1 | 6 | Solo hay piezas del jugador a eliminar |
| 11 | `"AAAA"` | 1 | 0 | No hay piezas del jugador a eliminar |
| 12 | `"RrAaRrAa"` | 1 | 18 | Eliminar jugador 1 en patrón alternado |

---

## Ejercicio C: Descripción del código

El código cuenta la cantidad de piezas de cada jugador (R/r para jugador 1, A/a para jugador 2) y muestra ambos conteos concatenados.

**Caso de prueba para verificación:**

| Tablero | Salida esperada | Descripción |
|---------|-----------------|-------------|
| `"RrrRAaaA"` | `44` | 4 piezas R/r + 4 piezas A/a |
| `"RRRR"` | `40` | 4 piezas R + 0 piezas A |
| `"AAAA"` | `04` | 0 piezas R + 4 piezas A |
| `""` | `00` | Tablero vacío |
| `"RrAa"` | `22` | 2 piezas R/r + 2 piezas A/a |
