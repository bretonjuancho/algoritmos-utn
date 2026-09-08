# Ejemplo TDA — Fracción

Ejemplo práctico y mínimo de **TDA (Tipo de Dato Abstracto)** en C++.

## Qué es un TDA

Un TDA = **Representación (datos)** + **Operaciones (funciones)**.

- **Representación:** cómo se guarda el dato. Acá sería: `struct fraccion { int num; int den; };`
- **Interfaz:** qué operaciones puede usar el cliente (prototipos en el `.h`).
- **Implementación:** cómo se hace cada operación (código en el `.cpp`, oculto para el cliente).

## Archivos de este ejemplo

```text
ejemplo-tda/
├── fraccion.h   → REPRESENTACIÓN (struct) + INTERFAZ (prototipos)
├── fraccion.cpp → IMPLEMENTACIÓN (cómo se hace cada función)
├── main.cpp     → USO / CLIENTE (usa el TDA sin saber cómo está hecho)
└── README.md
```

| Archivo | Qué contiene | Quién lo necesita ver |
|---|---|---|
| `fraccion.h` | `struct fraccion` + prototipos (`asigFrac`, `sumFrac`, `multFrac`, `restFrac`, `divFrac`, `fracIguales`, `fracEquiv`, `printFrac`) | Todos (es lo público) |
| `fraccion.cpp` | El cuerpo de esas funciones + `#include "fraccion.h"` | Solo el compilador (es lo privado) |
| `main.cpp` | `#include "fraccion.h"` y usa las funciones | El programador cliente |

## Pasos para implementar un TDA (receta)

1. **Definir la representación.** Elegí qué `struct` guarda el dato.
   ```cpp
   struct fraccion{
      int num; 
      int den; 
   };
   ```
2. **Definir la interfaz.** Listá las operaciones con el formato "informal" de la teoría:
   `Operación(tipos) → resultado. Descripción`.
   Ejemplo: `sumFrac(fraccion, fraccion) → fraccion. Suma dos fracciones.`
3. **Crear el `.h`** con el struct + los prototipos + guardas anti-doble-inclusión:
   ```cpp
   #ifndef FRACCION_H
   #define FRACCION_H
   // ... struct + prototipos ...
   #endif
   ```
4. **Crear el `.cpp`** con `#include "fraccion.h"` e implementar cada función.
5. **Usarlo desde `main.cpp`** con `#include "fraccion.h"` (con **comillas**, no con `< >`).
   El `main` nunca toca `num`/`den` directamente para operar: llama a las funciones del TDA.
6. **Compilar los DOS `.cpp` juntos** (el `main` solo no alcanza).

## Cómo hacerlo andar en Zinjai (paso a paso)

Zinjai necesita que los 3 archivos estén en el **mismo proyecto**. Si compilás solo el `main`, da error de *undefined reference*.

Para crear un proyecto hacemos (en la pantalla de inicio): 

1. **Crear un nuevo proyecto**: Ingresamos nombre y directorio donde vamos a guardar el proyecto.
2. **Seleccionar plantilla**: Recomiendo que empiecen con un proyecto en blanco para aprender bien qué es cada cosa. 
   Ahora vamos a tener una pantalla en blanco y 3 carpetas:
   - **Fuente:** Archivos .cpp
   - **Cabeceras:** Archivos .h
   - **Otros:** otros archivos relevantes para el proyecto 
3. **Agregá los archivos:** Hacé click en el archivo blanco de arriba a la izquierda y creá un nuevo archivo dependiendo de qué quieras agregar (si una fuente o una cabecera). En este caso vamos a tener 3 archivos: 
   - **fraccion.h (cabecera):** Interfaz del TDA fraccion. Tiene los prototipos de las funciones que una fraccion puede usar y la estructura fraccion. 
   - **fraccion.cpp (fuente):** Implementacion de todas las funciones que una fraccion puede usar. 
   - **main.cpp (fuente).** 

   En `main.cpp` y en `fraccion.cpp` debe decir `#include "fraccion.h"` (con comillas).
4. **Compilar y ejecutar**.
   - Si pide argumentos, dejá vacío.
   - Probá ingresando por ejemplo `1 2` (= 1/2). Deberías ver la multiplicación por 3/5, la suma y las comparaciones.
5. Para modificar el TDA (ej. cambiar cómo suma), tocá solo `fraccion.cpp`, guardá y volvé a compilar. El `main.cpp` no se toca mientras la interfaz no cambie.