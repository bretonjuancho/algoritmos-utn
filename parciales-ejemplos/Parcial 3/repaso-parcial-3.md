# 📝 Repaso Completo — Tercer Parcial — Algoritmos y Estructuras de Datos

<div align="center">

**Material de repaso generado con IA. Usalo para practicar, NO COMO PARÁMETRO DE LO QUE PUEDEN TOMAR.**

⏱️ Tiempo sugerido: **2 horas** si se resuelve completo · 📊 Cobertura: **todos los temas del parcial**

</div>

---

## 🗂️ Temas incluidos

| # | Tema | Teoría | Práctica |
|:-:|------|:------:|:--------:|
| 1 | Arreglos multidimensionales (matrices) | ✅ | ✅ Parte 3 |
| 2 | Estructuras (`struct` / registros) | ✅ | ✅ Parte 4 |
| 3 | Tipos de Datos Abstractos (TDA) | ✅ | — |
| 4 | Pilas y colas | ✅ | — |
| 5 | Complejidad algorítmica | ✅ | ✅ Parte 2 |
| 6 | Punteros | ✅ | — |

---

## ✍️ Cómo usar este repaso

> 1. Leé el **repaso rápido** de cada tema (conceptos mínimos que tenés que tener claros).
> 2. Respondé las preguntas de teoría **sin mirar** el solucionario del final.
> 3. Resolvé los 3 ejercicios de complejidad y las dos prácticas (matrices y structs) en papel o en el compilador.
> 4. Recién después compará con el **Solucionario** (al final del documento).
>
> En las preguntas de teoría **siempre hay que justificar**. Sin justificación no se otorga el puntaje.

---

# 📚 Parte 1 — Teoría por tema

## 🧱 Tema 1 — Arreglos multidimensionales (matrices)

### 📖 Repaso rápido

- Un arreglo bidimensional se declara `tipo nombre[filas][columnas]`, por ejemplo `int m[5][3]`.
- Con tipo estructurado: `typedef double tTemperaturas[10][8];` y luego `tTemperaturas t;`.
- Se inicializan con **llaves anidadas** y se puede omitir **sólo la primera dimensión**:
  `const int mat[][2] = {{0,2},{4,4},{10,10}};`
- En memoria se guardan **por filas** (*row-major*): primero toda la fila 0, después la fila 1, etc.
- Acceso con **dos índices**: `m[i][j]` (fila `i`, columna `j`).
- Diagonal principal: `i == j`. Diagonal secundaria: `i + j == N - 1`.
- Al pasar una matriz como parámetro **es obligatorio indicar la cantidad de columnas**:
  `void f(int m[][8], int filas)`.
- Recorridos típicos: por filas, por columnas, sólo diagonales, bordes, ventanas.

### ❓ Preguntas

**T1.1 (Selección múltiple)** Al inicializar una matriz `int m[3][4]`, ¿qué dimensión se puede omitir?
- **a)** Ambas.
- **b)** La de columnas (4).
- **c)** La de filas (3), pero no la de columnas.
- **d)** Ninguna: siempre hay que escribir ambas.

**T1.2 (Selección múltiple)** Al pasar una matriz a una función, es obligatorio que la función conozca:
- **a)** La cantidad de filas.
- **b)** La cantidad de columnas.
- **c)** Ambas dimensiones.
- **d)** Ninguna: se deduce sola.

**T1.3 (Selección múltiple)** ¿Cuántos elementos almacena `double m[4][7]`?
- **a)** 11
- **b)** 28
- **c)** 47
- **d)** 4

**T1.4 (Verdadero/Falso)** El nombre de una matriz es la dirección de su primer elemento, por lo que modificarla dentro de una función afecta al programa que la invoca.

**T1.5 (Verdadero/Falso)** Las matrices se almacenan en memoria por columnas: todos los elementos de la columna 0, luego la columna 1, etc.

**T1.6 (Verdadero/Falso)** Al pasar una matriz como parámetro se copia completa, igual que un `int`.

**T1.7 (Desarrollo)** ¿Cómo se recorre la diagonal principal de una matriz de `N x N`? ¿Cuántas iteraciones realiza?

**T1.8 (Desarrollo)** Explicá la diferencia entre pasar un `int` y pasar una matriz como parámetro a una función.

**T1.9 (Desarrollo)** Escribí la condición que identifica los elementos de la diagonal secundaria de una matriz de `N x N` y explicá con un ejemplo para `N = 4`.

---

## 🏗️ Tema 2 — Estructuras (`struct` / registros)

### 📖 Repaso rápido

- Un `struct` agrupa variables relacionadas bajo un mismo nombre; sus campos pueden ser de **distintos tipos**.
- La **definición** del struct **no reserva memoria**: sólo crea un nuevo tipo.
- Acceso a campos con el operador **punto** (`.`): `carta.valor`. Si se tiene un **puntero** a struct, se usa **flecha** (`->`): `ptr->valor`.
- Inicialización por lista (`Carta c = {8, "Trebol"};`), por asignación campo a campo, o copiando un struct completo del mismo tipo (`a = b;`).
- **Sí** se permite asignar structs completos del mismo tipo. **No** se permite compararlos con `==`, `!=`, `>`, `<`.
- Entrada/salida: **campo por campo** (no hay lectura/escritura predefinida del registro completo).
- Por defecto los structs se pasan **por valor** (copia). Para modificarlos hay que pasar por referencia (`&`).
- Pueden anidarse, contener arreglos y ser elementos de arreglos.
- `sizeof(variable)` devuelve el tamaño en bytes.

### ❓ Preguntas

**T2.1 (Selección múltiple)** ¿Cómo se pasan los `struct` a las funciones por defecto en C++?
- **a)** Por referencia.
- **b)** Por valor (copia).
- **c)** Por dirección siempre.
- **d)** No se pueden pasar.

**T2.2 (Selección múltiple)** ¿Cuál de estas operaciones con structs completos **no** está permitida?
- **a)** `a = b;` (mismo tipo).
- **b)** `cout << a.campo;`
- **c)** `if (a == b) { ... }`
- **d)** `sizeof(a)`

**T2.3 (Selección múltiple)** Si una función recibe un struct por valor y modifica sus campos:
- **a)** Los cambios se reflejan en quien la invoca.
- **b)** Los cambios se pierden al terminar la función.
- **c)** El programa no compila.
- **d)** El struct se convierte en puntero automáticamente.

**T2.4 (Verdadero/Falso)** Es posible asignar un struct completo a otro del mismo tipo, y esa asignación equivale a copiar campo por campo.

**T2.5 (Verdadero/Falso)** Si una función recibe un struct por valor y modifica sus campos, los cambios se reflejan en el programa que la invoca.

**T2.6 (Verdadero/Falso)** El operador `->` se usa únicamente cuando se accede a los campos a través de un puntero a struct.

**T2.7 (Desarrollo)** ¿Para qué sirve una estructura? Mencioná un ejemplo de la vida real donde convenga usarla.

**T2.8 (Desarrollo)** Explicá la diferencia entre acceder a un campo con `.` y con `->`. ¿Cuándo se usa cada uno?

---

## 🧩 Tema 3 — Tipos de Datos Abstractos (TDA)

### 📖 Repaso rápido

- Un **TDA** es un tipo definido por el programador formado por:
  1. un **conjunto de valores válidos**, y
  2. un **conjunto de operaciones primitivas** (su **interfaz**).
- La **implementación** consta de la **representación** (cómo se almacenan los datos) y los **algoritmos** de las operaciones.
- El **cliente** usa el TDA a través de su **interfaz**, sin conocer la implementación.
- En C++ se implementa con un **archivo de cabecera (`.h`)** que contiene la representación (el `struct`) y los **prototipos**, y un **archivo fuente (`.cpp`)** con el código de las funciones.
- El cliente escribe `#include "miTDA.h"`.
- Se puede **cambiar la implementación** (el `.cpp`) y sólo hay que recompilar ese archivo, sin afectar al cliente, **siempre que la interfaz y la representación se mantengan**.
- La **abstracción** (ocultar los detalles no esenciales) es la clave de los TDA.

### ❓ Preguntas

**T3.1 (Selección múltiple)** Un TDA está formado por:
- **a)** Sólo un `struct`.
- **b)** Un conjunto de valores válidos y un conjunto de operaciones primitivas.
- **c)** Únicamente funciones.
- **d)** Un archivo `.exe`.

**T3.2 (Selección múltiple)** ¿Qué puede hacer el programador **cliente** de un TDA?
- **a)** Modificar libremente los campos internos.
- **b)** Usar sólo las operaciones de la interfaz.
- **c)** Cambiar la representación interna.
- **d)** Nada: no puede usar el TDA.

**T3.3 (Selección múltiple)** La principal ventaja de un TDA es que:
- **a)** Los programas ocupan menos memoria.
- **b)** Separa la interfaz de la implementación: se puede cambiar la implementación sin afectar al cliente.
- **c)** Evita tener que compilar.
- **d)** Obliga a usar punteros.

**T3.4 (Verdadero/Falso)** El cliente de un TDA necesita conocer la implementación de las operaciones para poder usarlas.

**T3.5 (Verdadero/Falso)** El archivo de cabecera (`.h`) de un TDA agrupa la representación de los datos y los prototipos de las operaciones.

**T3.6 (Verdadero/Falso)** Si se cambia la implementación de un TDA (su `.cpp`) manteniendo la misma interfaz, el programa cliente no necesita reescribirse.

**T3.7 (Desarrollo)** ¿Qué es la interfaz de un TDA y qué relación tiene con su implementación?

**T3.8 (Desarrollo)** Explicá qué contenido va típicamente en el archivo `.h` y qué contenido va en el `.cpp` de un TDA.

---

## 📚 Tema 4 — Pilas y colas

### 📖 Repaso rápido

- **Pila**: estructura **LIFO** (*Last In, First Out*). Se opera siempre por el **tope**.
  - `apilar` (push) agrega en la cima; `desapilar` (pop) quita la cima; `cima` consulta sin quitar.
  - Con arreglo: `tope = -1` indica **pila vacía**; `tope = MAXTAM - 1` indica **pila llena**.
  - Desapilar de una pila vacía es **underflow**; apilar en una llena es **overflow**.
- **Cola**: estructura **FIFO** (*First In, First Out*). Se **encola por el final** y se **desencola por el frente**.
  - Con arreglo circular: `frente` apunta al primer elemento y `final` al primer espacio libre.
  - **Vacía** cuando `frente == final`.
  - Los índices se actualizan con el resto: `final = (final + 1) % MAXTAMQ` y `frente = (frente + 1) % MAXTAMQ`.
- Aplicaciones: pila → deshacer (*undo*), paréntesis, llamadas a funciones; cola → impresora, turnos, mensajes.

### ❓ Preguntas

**T4.1 (Selección múltiple)** ¿Cuál de estas afirmaciones es verdadera?
- **a)** Desapilar de una pila vacía provoca *overflow*.
- **b)** La cola es LIFO.
- **c)** En una cola circular, `final = (final + 1) % MAXTAMQ`.
- **d)** En una pila con arreglo, el tope vale `-1` cuando está llena.

**T4.2 (Selección múltiple)** En una pila implementada con un arreglo, cuando `tope == -1` la pila está:
- **a)** Llena.
- **b)** Vacía.
- **c)** Invertida.
- **d)** Corrupta.

**T4.3 (Selección múltiple)** Una cola se caracteriza por ser:
- **a)** LIFO.
- **b)** FIFO.
- **c)** LILO.
- **d)** Aleatoria.

**T4.4 (Verdadero/Falso)** Una pila es una estructura FIFO.

**T4.5 (Verdadero/Falso)** En una cola circular, el índice `final` vuelve a 0 cuando supera la última posición del arreglo.

**T4.6 (Verdadero/Falso)** En una cola, `frente == final` indica que la cola está vacía.

**T4.7 (Desarrollo)** Describí cómo invertir el orden de los elementos de una cola usando una pila como auxiliar.

**T4.8 (Desarrollo)** Mencioná un ejemplo de aplicación de una pila y uno de una cola, y explicá por qué se elige cada estructura.

---

## 📈 Tema 5 — Complejidad algorítmica

### 📖 Repaso rápido

- **Complejidad temporal**: tiempo (cantidad de operaciones) que consume el algoritmo según el tamaño de entrada `N`. **Complejidad espacial**: memoria que utiliza.
- Se distinguen **mejor caso**, **peor caso** y **caso medio**. Se analiza el **peor caso**, porque acota el tiempo máximo.
- Se usa `T(N)` (expresión exacta) y el **análisis asintótico** (comportamiento cuando `N → ∞`), donde se descartan las **constantes** y los **términos de menor orden**.
- Órdenes de menor a mayor crecimiento:

  `Θ(1) < Θ(log N) < Θ(√N) < Θ(N) < Θ(N log N) < Θ(N²) < Θ(N³) < Θ(2^N) < Θ(N!)`

- Un algoritmo de costo **constante** es lo ideal; uno **cuadrático** deja de ser útil para entradas grandes; uno **exponencial** rara vez es útil.
- **La complejidad es del algoritmo, no del código ni de los datos.**

### ❓ Preguntas

**T5.1 (Selección múltiple)** Dos ciclos anidados que recorren `N` veces cada uno tienen complejidad:
- **a)** Θ(N)
- **b)** Θ(N²)
- **c)** Θ(log N)
- **d)** Θ(1)

**T5.2 (Selección múltiple)** ¿Qué caso se analiza habitualmente para dar una garantía de comportamiento?
- **a)** El mejor caso.
- **b)** El peor caso.
- **c)** El caso medio.
- **d)** Ninguno.

**T5.3 (Selección múltiple)** Si `T(N) = 5N² + 10N + 3`, entonces:
- **a)** Θ(5N²)
- **b)** Θ(N²)
- **c)** Θ(N)
- **d)** Θ(N³)

**T5.4 (Verdadero/Falso)** Un algoritmo que resuelve un problema en tiempo constante es lo ideal, porque su tiempo no crece con el tamaño de la entrada.

**T5.5 (Verdadero/Falso)** El mejor caso es el más representativo para analizar la eficiencia de un algoritmo.

**T5.6 (Verdadero/Falso)** En general se analiza más la complejidad temporal que la espacial, porque el tiempo es un recurso más crítico.

**T5.7 (Desarrollo)** Explicá la diferencia entre complejidad temporal y complejidad espacial.

**T5.8 (Desarrollo)** ¿Por qué se analiza el peor caso y no el mejor? Justificá con un ejemplo.

---

## 🔗 Tema 6 — Punteros

### 📖 Repaso rápido

- Un **puntero** es una variable que contiene una **dirección de memoria** (referencia indirecta).
- Se declara con `*`: `int *p;`. Se inicializa con `NULL`, `0` o una dirección concreta.
- Operadores:
  - `&` (dirección): `p = &x;` guarda la dirección de `x`.
  - `*` (indirección/desreferencia): `*p` retorna el contenido de la variable apuntada; `*p = 7;` modifica `x`.
- **Aritmética de punteros**: `++`, `--`, `+`, `-` avanzan/retroceden tantos **bytes como el tipo apuntado**. Restar dos punteros devuelve el **número de elementos** entre ellos.
- **Punteros y arreglos**: el nombre de un arreglo es un **puntero constante** a su primer elemento. `*(b + i)` es equivalente a `b[i]`.
- **Puntero genérico** `void *`: apunta a cualquier tipo, **no se puede desreferenciar** y requiere conversión antes de asignarse a otro puntero.
- Con punteros a struct se accede a los campos con `->`.

### ❓ Preguntas

**T6.1 (Selección múltiple)** Un puntero almacena:
- **a)** Un valor entero.
- **b)** Una dirección de memoria.
- **c)** Un arreglo.
- **d)** Un struct.

**T6.2 (Selección múltiple)** Dado un arreglo `int b[5]` y un puntero `bPtr = b;`, la expresión `*(bPtr + 3)` es equivalente a:
- **a)** `b[0]`
- **b)** `b[3]`
- **c)** `b + 3`
- **d)** `&b[3]`

**T6.3 (Selección múltiple)** ¿Qué **no** se puede hacer con un puntero `void *`?
- **a)** Asignarle la dirección de cualquier tipo.
- **b)** Desreferenciarlo directamente.
- **c)** Convertirlo a otro tipo de puntero con un *cast*.
- **d)** Declararlo.

**T6.4 (Verdadero/Falso)** El nombre de un arreglo es un puntero constante: no se puede reasignar para que apunte a otro lado.

**T6.5 (Verdadero/Falso)** Si `p` es un `int *`, la operación `p++` siempre incrementa la dirección en 1 byte.

**T6.6 (Verdadero/Falso)** La resta de dos punteros del mismo tipo devuelve la cantidad de elementos que hay entre ellos.

**T6.7 (Desarrollo)** Explicá la diferencia entre `&` y `*` en el contexto de punteros.

**T6.8 (Desarrollo)** ¿Qué relación existe entre punteros y arreglos? Mencioná al menos dos equivalencias.

---

# 🧮 Parte 2 — Cálculo de complejidad (3 ejercicios)

> Determiná el **orden de complejidad Θ** de cada caso y **justificá** el cálculo.

### E1 (dificultad media) — Ciclos anidados triangulares

```cpp
int contador = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
        contador++;
    }
}
```

### E2 (dificultad media) — Ciclo combinado

```cpp
int contador = 0;
for (int i = 0; i < N; i++) {
    for (int j = N; j > 1; j /= 2) {
        contador++;
    }
}
```

### E3 (dificultad media) — Crecimiento por duplicación

```cpp
int contador = 0;
int i = 1;
while (i < N) {
    i *= 2;
    contador++;
}
```

> 💡 Soluciones detalladas en el **Solucionario → Parte 2**.

---

# 🧱 Parte 3 — Práctica de matrices

## B.1 Butacas de un teatro · 15 puntos

Un teatro registra en una matriz `int ocupadas[FIL][COL]` el estado de cada butaca: `1` si está **vendida** y `0` si está **libre**. `FIL = 10` filas y `COL = 12` columnas.

```cpp
const int FIL = 10;
const int COL = 12;
int ocupadas[FIL][COL];
```

*Asumí que la matriz ya está cargada y que todas las butacas se cargaron con `0` o `1`. No hace falta implementar la carga.*

**a) (4 pts)** Escribí la función `butacasVendidas`, que reciba la matriz y sus dimensiones, y devuelva cuántas butacas están vendidas.

```cpp
int butacasVendidas(int m[][COL], int fil, int col);
```

**b) (5 pts)** Escribí el procedimiento `filaMasVendida`, que reciba la matriz y sus dimensiones, y devuelva **por referencia** el índice de la fila con mayor cantidad de butacas vendidas y cuántas vendió.

```cpp
void filaMasVendida(int m[][COL], int fil, int col, int &fila, int &cantidad);
```

**c) (3 pts)** Escribí la función `teatroCompleto`, que devuelva `true` si **todas** las butacas del teatro están vendidas y `false` en caso contrario.

```cpp
bool teatroCompleto(int m[][COL], int fil, int col);
```

**d) (3 pts)** Escribí el procedimiento `mostrarMatriz`, que imprima la matriz fila por fila, separando cada valor con un espacio.

```cpp
void mostrarMatriz(int m[][COL], int fil, int col);
```

> 💡 Solución en el **Solucionario → Parte 3**.

---

# 🏗️ Parte 4 — Práctica de structs

## B.2 Liga de fútbol · 15 puntos

Se quiere registrar la información de los partidos de una liga:

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Partido {
    string local;          // equipo que juega de local
    string visitante;      // equipo que juega de visitante
    int golesLocal;
    int golesVisitante;
    Fecha fecha;
};

const int MAXP = 100;
typedef Partido tPartidos[MAXP];
```

**a) (5 pts)** Escribí el procedimiento `cargarPartido(Partido &p)`, que lea por teclado los equipos, los goles y la fecha del partido.

**b) (5 pts)** Escribí la función `puntosEquipo`, que reciba el arreglo de partidos, su tamaño lógico y el nombre de un equipo, y devuelva los puntos obtenidos (victoria = 3, empate = 1, derrota = 0).

```cpp
int puntosEquipo(tPartidos v, int n, string equipo);
```

**c) (5 pts)** Escribí la función `partidoConMasGoles`, que reciba el arreglo de partidos y su tamaño lógico, y **devuelva** (retorne) el partido en el que se convirtió la mayor cantidad total de goles (goles local + goles visitante).

```cpp
Partido partidoConMasGoles(tPartidos v, int n);
```

> 💡 Solución en el **Solucionario → Parte 4**.

---

# ✅ Solucionario

> Soluciones posibles para autocorrección. En los ejercicios de código puede haber otras implementaciones correctas.

## 🧱 Tema 1 — Matrices

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T1.1 | **c** | Sólo puede omitirse la **primera** dimensión (filas); las columnas siempre deben indicarse. |
| T1.2 | **b** | Una matriz se pasa por dirección y la función necesita conocer la cantidad de **columnas** para calcular los desplazamientos. Las filas se pasan como parámetro aparte. |
| T1.3 | **b** | 4 × 7 = 28 elementos. |
| T1.4 | **V** | El nombre del arreglo es la dirección del primer elemento, así que la función accede a la misma memoria y puede modificarla. |
| T1.5 | **F** | Se almacenan **por filas** (*row-major*). |
| T1.6 | **F** | Los arreglos y matrices se pasan **por dirección**, no se copian. |

**T1.7** Se recorre con **un solo ciclo** accediendo a `m[i][i]`, para `i` de `0` a `N-1`; realiza **N iteraciones** → Θ(N).

**T1.8** Un `int` se pasa **por valor** (se copia) por defecto: si la función lo modifica, el original no cambia salvo que se use `int &`. Una **matriz se pasa por dirección**: el nombre es la dirección de su primer elemento, por lo que la función trabaja sobre la misma memoria y puede modificar sus elementos. Además, al ser un parámetro debe indicarse el número de columnas.

**T1.9** La condición es `i + j == N - 1`. Para `N = 4` los elementos son `(0,3)`, `(1,2)`, `(2,1)` y `(3,0)`, que cumplen `0+3 = 1+2 = 2+1 = 3+0 = 3 = N-1`.

## 🏗️ Tema 2 — Structs

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T2.1 | **b** | Por defecto los structs se pasan **por valor** (una copia). |
| T2.2 | **c** | Los operadores de comparación (`==`, `!=`, `>`, `<`) **no** son válidos entre structs completos. Sí lo son la asignación, el acceso a campos y `sizeof`. |
| T2.3 | **b** | Al pasarse por valor, la función trabaja sobre una copia; los cambios se pierden al retornar. |
| T2.4 | **V** | La asignación `a = b;` es válida y equivale a copiar campo por campo. |
| T2.5 | **F** | Al pasar por valor se copia el struct, por lo que los cambios **no** se reflejan. Para eso hay que pasar por referencia (`Partido &p`). |
| T2.6 | **V** | El operador `->` se usa con punteros a struct; con la variable se usa el punto. |

**T2.7** Una estructura agrupa bajo un mismo nombre variables relacionadas que pueden ser de distintos tipos, tratándolas como un todo. Ejemplo: en un sistema de una facultad, un `struct Estudiante` con legajo, nombre y promedio, o un `struct Fecha` con día, mes y año.

**T2.8** El operador **punto** (`.`) se usa cuando se tiene la **variable** del struct (`alumno.promedio`). El operador **flecha** (`->`) se usa cuando se tiene un **puntero** al struct (`ptr->promedio`), y equivale a `(*ptr).promedio`.

## 🧩 Tema 3 — TDA

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T3.1 | **b** | Un TDA = conjunto de valores válidos + operaciones primitivas. |
| T3.2 | **b** | El cliente sólo interactúa a través de la interfaz (las operaciones primitivas). |
| T3.3 | **b** | La ventaja principal es separar la interfaz de la implementación, permitiendo cambiar esta última sin afectar al cliente. |
| T3.4 | **F** | El cliente sólo necesita conocer la **interfaz** (y la representación pública); la implementación queda oculta. |
| T3.5 | **V** | El `.h` agrupa la representación de los datos y los prototipos de las operaciones. |
| T3.6 | **V** | Si la interfaz y la representación se mantienen, sólo se recompila el `.cpp` del TDA, sin tocar el programa cliente. |

**T3.7** La **interfaz** es el conjunto de operaciones primitivas que el cliente puede usar sobre los valores del tipo (qué reciben y qué devuelven). La **implementación** es cómo se representan internamente los datos y cómo se codifican esas operaciones. El cliente sólo necesita conocer la interfaz; la implementación puede cambiarse sin afectarlo.

**T3.8** En el **`.h`** va la definición del `struct` (representación) y los **prototipos** de las funciones (interfaz). En el **`.cpp`** va el **código** de esas funciones, incluyendo el `.h` con `#include`. Así el cliente sólo incluye el `.h`.

## 📚 Tema 4 — Pilas y colas

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T4.1 | **c** | La cola circular avanza con `final = (final + 1) % MAXTAMQ`. Desapilar una pila vacía es *underflow*; la cola es FIFO; `tope = -1` indica pila **vacía**. |
| T4.2 | **b** | `tope == -1` indica pila vacía. |
| T4.3 | **b** | La cola es FIFO: el primero en entrar es el primero en salir. |
| T4.4 | **F** | La pila es **LIFO**. |
| T4.5 | **V** | Es el comportamiento circular: `final = (final + 1) % MAXTAMQ` vuelve a 0. |
| T4.6 | **V** | La cola está vacía cuando `frente == final`. |

**T4.7** Se desencola cada elemento de la cola y se apila en la pila; como la pila es LIFO, al desapilarlos salen en orden inverso. Luego se desapila todo y se vuelve a encolar: el último que había entrado en la pila (que era el primero de la cola) queda al final, invirtiendo el orden.

**T4.8** **Pila**: deshacer (*undo*) o validación de paréntesis; conviene porque interesa recuperar lo más reciente primero (LIFO). **Cola**: trabajos enviados a una impresora o turnos de atención; conviene porque debe respetarse el orden de llegada (FIFO).

## 📈 Tema 5 — Complejidad

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T5.1 | **b** | El ciclo externo se repite N veces y, por cada una, el interno N veces: N × N = N². |
| T5.2 | **b** | El peor caso acota el tiempo máximo que puede tardar el algoritmo. |
| T5.3 | **b** | Cuando N crece, el término de mayor orden (`5N²`) domina y se descartan constantes y términos menores. |
| T5.4 | **V** | El costo constante no crece con N; es lo ideal. |
| T5.5 | **F** | El más representativo es el **peor** caso; el mejor puede ser poco realista (por ejemplo, encontrar el valor buscado en la primera posición). |
| T5.6 | **V** | El tiempo es un recurso más valioso y crítico que el espacio. |

**T5.7** La complejidad **temporal** mide el tiempo (cantidad de operaciones) que consume el algoritmo en función del tamaño de la entrada `N`; la **espacial** mide la memoria que utiliza. Se analiza más la temporal porque el tiempo es un recurso más crítico.

**T5.8** Porque el peor caso da una **garantía**: acota el tiempo máximo sin importar los datos de entrada. El mejor caso puede ser poco representativo. Ejemplo: buscar un número en un arreglo desordenado; el mejor caso es encontrarlo en la primera posición (Θ(1)), pero en el peor caso hay que recorrer los N elementos (Θ(N)).

## 🔗 Tema 6 — Punteros

| # | Respuesta | Justificación |
|:-:|:---------:|---------------|
| T6.1 | **b** | Un puntero contiene una dirección de memoria. |
| T6.2 | **b** | `*(bPtr + 3)` es la notación puntero/desplazamiento y equivale a `b[3]`. |
| T6.3 | **b** | Un `void *` no puede desreferenciarse; primero hay que convertirlo al tipo adecuado. |
| T6.4 | **V** | El nombre del arreglo es un puntero constante; sólo sirve para acceder a sus elementos, no puede reasignarse. |
| T6.5 | **F** | `p++` avanza tantos **bytes como el tipo apuntado** (para `int *`, típicamente 4 bytes). |
| T6.6 | **V** | La resta de punteros del mismo tipo devuelve el número de elementos entre ellos. |

**T6.7** El operador `&` (dirección) devuelve la **dirección de memoria** de una variable: `p = &x;`. El operador `*` (indirección/desreferencia) accede al **contenido** de la variable apuntada: `*p` devuelve el valor de `x`, y `*p = 7;` lo modifica.

**T6.8** Un arreglo y un puntero se relacionan estrechamente: el nombre del arreglo es un puntero constante a su primer elemento. Equivalencias: `b` es igual a `&b[0]`; `b[i]` es igual a `*(b + i)`; `bPtr = b` hace que el puntero apunte al arreglo, y `bPtr[i]` accede a `b[i]`.

## 🧮 Parte 2 — Cálculo de complejidad

**E1 — Θ(N²).** Aunque el ciclo interno no llega siempre a N, se ejecuta `0 + 1 + 2 + ... + (N-1) = N(N-1)/2` veces. Al desarrollar, el término dominante es `N²/2`; se descarta la constante 1/2 → **Θ(N²)**.

**E2 — Θ(N log N).** El ciclo externo se ejecuta `N` veces. En cada una, el ciclo interno divide `j` entre 2 hasta que llega a 1, lo que ocurre en aproximadamente `log₂ N` pasos. Total: `N × log₂ N` → **Θ(N log N)**.

**E3 — Θ(log N).** La variable `i` toma los valores `1, 2, 4, 8, ...` (potencias de 2) hasta alcanzar o superar a `N`. La cantidad de duplicaciones `k` cumple `2^k ≥ N`, es decir `k ≈ log₂ N`. El ciclo se repite `log₂ N` veces → **Θ(log N)**.

## 🧱 Parte 3 — Butacas del teatro

```cpp
int butacasVendidas(int m[][COL], int fil, int col) {
    int cant = 0;
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 1) {
                cant++;
            }
        }
    }
    return cant;
}

void filaMasVendida(int m[][COL], int fil, int col, int &fila, int &cantidad) {
    fila = 0;
    cantidad = 0;
    for (int j = 0; j < col; j++) {
        cantidad += m[0][j];
    }
    for (int i = 1; i < fil; i++) {
        int suma = 0;
        for (int j = 0; j < col; j++) {
            suma += m[i][j];
        }
        if (suma > cantidad) {
            cantidad = suma;
            fila = i;
        }
    }
}

bool teatroCompleto(int m[][COL], int fil, int col) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void mostrarMatriz(int m[][COL], int fil, int col) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
```

> En `filaMasVendida` se inicializa con la fila 0 y luego se comparan las demás. Como se usa `>` (y no `>=`), si hay empate se conserva la primera fila con el máximo.

## 🏗️ Parte 4 — Liga de fútbol

```cpp
void cargarPartido(Partido &p) {
    cout << "Equipo local: ";
    cin >> p.local;
    cout << "Equipo visitante: ";
    cin >> p.visitante;
    cout << "Goles del local: ";
    cin >> p.golesLocal;
    cout << "Goles del visitante: ";
    cin >> p.golesVisitante;
    cout << "Fecha (dia mes anio): ";
    cin >> p.fecha.dia >> p.fecha.mes >> p.fecha.anio;
}

int puntosEquipo(tPartidos v, int n, string equipo) {
    int puntos = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].local == equipo) {
            if (v[i].golesLocal > v[i].golesVisitante) {
                puntos += 3;
            } else if (v[i].golesLocal == v[i].golesVisitante) {
                puntos += 1;
            }
        } else if (v[i].visitante == equipo) {
            if (v[i].golesVisitante > v[i].golesLocal) {
                puntos += 3;
            } else if (v[i].golesVisitante == v[i].golesLocal) {
                puntos += 1;
            }
        }
    }
    return puntos;
}

Partido partidoConMasGoles(tPartidos v, int n) {
    Partido mejor = v[0];
    int maxGoles = v[0].golesLocal + v[0].golesVisitante;
    for (int i = 1; i < n; i++) {
        int total = v[i].golesLocal + v[i].golesVisitante;
        if (total > maxGoles) {
            maxGoles = total;
            mejor = v[i];
        }
    }
    return mejor;
}
```

> Observaciones:
> - Se accede a la fecha anidada con `p.fecha.dia`, `p.fecha.mes`, `p.fecha.anio`.
> - El parámetro `Partido &p` se pasa **por referencia**: si se pasara por valor, los datos cargados se perderían al retornar.
> - La asignación `mejor = v[i];` es válida porque C++ permite asignar structs completos del mismo tipo.

---

## 📄 Resumen de fórmulas y reglas útiles

| Concepto | Regla |
|---|---|
| Matriz | Diagonal principal: `i == j` · Secundaria: `i + j == N - 1` |
| Pasaje de matriz | Obligatorio indicar las **columnas**: `void f(int m[][COL], int fil)` |
| Struct por defecto | Se pasa **por valor**; para modificar usar `&` |
| Comparar structs | **No** se permite con `==`, `!=`, `>`, `<` |
| TDA | Pila = LIFO · Cola = FIFO |
| Pila vacía / llena | `tope == -1` / `tope == MAXTAM - 1` |
| Cola vacía | `frente == final` |
| Cola circular | `final = (final + 1) % MAXTAMQ` |
| Peor caso | Es el caso que se analiza (garantía) |
| Descartar en Θ | Constantes y términos de menor orden |
| Puntero | `&` = dirección · `*` = contenido · `b[i] == *(b + i)` |

---

> 🧾 **Criterio de corrección sugerido:** se evalúa el uso correcto de funciones y parámetros, el pasaje por referencia cuando corresponde, el respeto de la interfaz del TDA, la prolijidad del código y la justificación de las respuestas teóricas.

<div align="center">

**¡Muchos éxitos en el parcial! 🍀**

</div>
