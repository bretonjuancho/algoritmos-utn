# Ejemplo TDA — Pilas y Colas

Ejemplo práctico y mínimo de **Pila (LIFO)** y **Cola (FIFO)** como TDA en C++.

## Archivos de esta carpeta

```text
Pilas-Colas-TDA/
├── pila.h         → REPRESENTACIÓN (struct Pila) + INTERFAZ (prototipos)
├── pila.cpp       → IMPLEMENTACIÓN de la pila
├── cola.h         → REPRESENTACIÓN (struct Cola) + INTERFAZ (prototipos)
├── cola.cpp       → IMPLEMENTACIÓN de la cola
├── main.cpp       → USO / CLIENTE (usa ambos TDA sin saber cómo están hechos)
├── Pilas-Colas.zpr → Proyecto Zinjai
└── README.md
```

| Archivo | Qué contiene |
|---|---|
| `pila.h` | `struct Pila { vec[TAMp], ptrCima }` + `apilar`, `desapilar`, `tope`, `pilaVacia`, `pilaLlena` |
| `cola.h` | `struct Cola { vec[TAMc], inicio, fin }` + `encolar`, `desencolar`, `frente`, `colaVacia`, `colaLlena` |
| `main.cpp` | Carga `n` elementos en cada estructura y las vacía para mostrar LIFO vs FIFO |

## Representación

* **Pila:** arreglo estático de capacidad `TAMp = 10`. `ptrCima == -1` significa vacía.
* **Cola:** arreglo circular de tamaño `TAMc = 10`. Capacidad útil **9**: un hueco se reserva para distinguir llena de vacía (`(fin+1)%TAMc == inicio`).

## Limitación didáctica

`desapilar`, `tope`, `desencolar` y `frente` devuelven `-1` si la estructura está vacía. Por eso `-1` no se usa como dato válido en este ejemplo. En código real se chequearía antes con `pilaVacia()` / `colaVacia()`.

## Cómo hacerlo andar en Zinjai

Los 5 archivos `.h/.cpp` deben estar en el **mismo proyecto**. Si compilás solo el `main`, da error de *undefined reference*.

1. Abrí `Pilas-Colas.zpr` en Zinjai.
2. Compilá y ejecutá.
3. Probá ingresando por ejemplo:
   ```text
   3
   10 20 30
   1 2 3
   ```
   Deberías ver:
   ```text
   Tope de la pila (ultimo que entro): 30
   Frente de la cola (primero que entro): 1
   Vaciando PILA (sale ultimo primero - LIFO): 30 20 10
   Vaciando COLA (sale primero primero - FIFO): 1 2 3
   ```

## Cómo compilar por consola

```bash
g++ -Wall -Wextra -std=c++14 main.cpp pila.cpp cola.cpp -o pilas-colas
```

> La demo pide de 1 a 9 elementos para que sirva para ambas estructuras (límite de la cola).
