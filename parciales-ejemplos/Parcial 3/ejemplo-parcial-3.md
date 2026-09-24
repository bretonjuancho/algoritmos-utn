# 📝 Ejemplo de Parcial 3 — Algoritmos y Estructuras de Datos

<div align="center">

**Ejemplo de parcial generado con IA. Usarlo para practicar, NO COMO PARÁMETRO DE LO QUE PUEDEN TOMAR**

⏱️ Tiempo máximo: **2 horas** · 📊 Puntaje total: **100 puntos**

</div>

---

## 🗂️ Estructura del parcial

| Parte | Contenido | Puntos | Tiempo sugerido |
|:-----:|-----------|:------:|:---------------:|
| 🧠 **A** | Teoría: selección múltiple, verdadero/falso y desarrollo | 20 | 20 min |
| 💻 **B** | Práctica: matrices, structs, TDA, pilas y colas | 60 | 65 min |
| 📈 **C** | Complejidad: análisis de algoritmos y órdenes | 20 | 20 min |
| | **Total** | **100** | **105 min** |

### 📚 Contenidos evaluados

| Tema | Dónde se evalúa |
|------|-----------------|
| Arreglos multidimensionales | A.1.1 · A.2.1 · A.3.1 · B.1 |
| Estructuras (`struct`) | A.1.2 · A.2.2 · B.2 |
| TDA | A.1.3 · A.3.3 · B.3 |
| Pilas y colas | A.1.4 · A.3.2 · B.4 |
| Complejidad | A.2.3 · C.1 |

---

## ✍️ Instrucciones

> - Leé todo el parcial antes de empezar y administrá el tiempo según la tabla de arriba.
> - En los ejercicios de código podés usar `using namespace std;`, funciones auxiliares y asumir que los datos ingresados son válidos, salvo que se indique lo contrario.
> - En la Parte A **siempre** hay que justificar; sin justificación no se otorga el puntaje.
> - No se permite el uso de apuntes, compilador ni ayudas externas.

---

# 🧠 Parte A — Teoría (20 puntos)

## A.1 Selección múltiple · 8 puntos (2 c/u)

*Marcá la única opción correcta y justificá en una línea.*

**1. (Matrices)** Al pasar una matriz `int m[5][3]` como parámetro a una función:

- **a)** Se pasa por valor: la función trabaja sobre una copia completa de la matriz.
- **b)** Se pasa la dirección del primer elemento: la función accede a la misma memoria y necesita conocer la cantidad de columnas.
- **c)** Es obligatorio declarar el parámetro como `const int m[5][3]`; de lo contrario el compilador rechaza el programa.
- **d)** No es posible pasar matrices a funciones: se deben pasar los elementos uno por uno.

**2. (Structs)** ¿Cuál de las siguientes operaciones con variables de un mismo tipo `struct` **no** está permitida en C++?

- **a)** Asignar una estructura a otra del mismo tipo: `a = b;`
- **b)** Acceder a un campo con el operador punto: `cout << a.campo;`
- **c)** Comparar dos estructuras completas: `if (a == b) { ... }`
- **d)** Obtener el tamaño en bytes de una estructura con `sizeof(a)`.

**3. (TDA)** ¿Cuál es la principal ventaja de definir un TDA?

- **a)** Los programas siempre ocupan menos memoria.
- **b)** El cliente puede modificar directamente los campos del `struct` cuando lo necesite.
- **c)** Permite separar la interfaz de la implementación: se puede cambiar la implementación sin afectar a los programas cliente.
- **d)** Ya no es necesario compilar el programa completo.

**4. (Pilas y colas)** ¿Cuál de las siguientes afirmaciones es verdadera?

- **a)** Desapilar un elemento de una pila vacía provoca un error de *overflow*.
- **b)** Una cola es una estructura LIFO: el último en entrar es el primero en salir.
- **c)** En una cola circular, el índice `final` se actualiza como `final = (final + 1) % MAXTAMQ`.
- **d)** En una pila implementada con un arreglo, el tope vale `-1` cuando la pila está llena.

## A.2 Verdadero o falso · 6 puntos (2 c/u)

*Indicá V o F y justificá **siempre**. Sin justificación no se otorga puntaje.*

1. Al declarar `const int mat[][2] = {{0,2},{4,4},{10,10}};`, el compilador deduce la cantidad de filas a partir de la inicialización.

2. Si una función recibe un `struct` por valor y modifica sus campos, los cambios se reflejan en el programa que la invoca.

3. Al analizar la eficiencia de un algoritmo conviene estudiar el peor caso, porque acota el tiempo máximo que el algoritmo puede llegar a tardar.

## A.3 Desarrollo breve · 6 puntos (2 c/u)

*Respondé en no más de 5 renglones por pregunta.*

1. ¿En qué se diferencia el pasaje de un arreglo (o matriz) a una función del pasaje de una variable simple, como un `int`?

2. Explicá la diferencia entre una estructura LIFO y una FIFO. Mencioná un ejemplo de aplicación de cada una.

3. ¿Qué es la interfaz de un TDA y qué relación tiene con su implementación?

---

# 💻 Parte B — Práctica (60 puntos)

## B.1 Red de frío en supermercados · 15 puntos

Una cadena de supermercados controla la temperatura de las heladeras de sus sucursales. Se registra la **temperatura promedio diaria** en una matriz de `SF` sucursales (máximo 10) por `SH` heladeras (máximo 8):

```cpp
double tTemperaturas[10][8];
```

*Asumí que la matriz ya está cargada y que `SF` y `SH` tienen valores válidos. No hace falta implementar la carga.*

**a) (4 pts)** Escribí la función `promedioSucursal`, que reciba la matriz, la cantidad de heladeras y un número de sucursal, y devuelva la temperatura promedio de esa sucursal.

```cpp
double promedioSucursal(double t[][8], int sh, int suc);
```

**b) (5 pts)** Escribí la función `contarEnAlerta`, que reciba la matriz, sus dimensiones y un valor límite, y devuelva cuántas heladeras superan ese límite.

```cpp
int contarEnAlerta(double t[][8], int sf, int sh, double limite);
```

**c) (6 pts)** Escribí el procedimiento `heladeraMasCaliente`, que reciba la matriz y sus dimensiones, y devuelva **por referencia** la sucursal y la heladera donde se registró la temperatura más alta.

```cpp
void heladeraMasCaliente(double t[][8], int sf, int sh, int &suc, int &hel);
```

## B.2 Recitales · 15 puntos

Se quiere registrar la información de los recitales de una productora:

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Recital {
    string artista;
    Fecha fecha;
    int entradasVendidas;
    double recaudacion;
};
```

**a) (5 pts)** Escribí el procedimiento `cargarRecital(Recital &r)`, que lea por teclado los datos de un recital (artista, fecha, entradas vendidas y recaudación). Para leer el nombre del artista podés usar `getline(cin, r.artista)`.

**b) (4 pts)** Escribí la función `promedioRecaudacion`, que reciba un arreglo de recitales y su tamaño lógico, y devuelva la recaudación promedio.

```cpp
double promedioRecaudacion(tRecitales v, int n);
```

**c) (6 pts)** Escribí la función `masVendido`, que reciba un arreglo de recitales y su tamaño lógico, y **devuelva** (retorne) el recital con mayor cantidad de entradas vendidas.

```cpp
Recital masVendido(tRecitales v, int n);
```

## B.3 TDA Número Complejo · 15 puntos

Un número complejo se representa como `a + bi`, donde `a` es la parte real y `b` la imaginaria. Se quiere definir el **TDA Complejo** con estas operaciones primitivas:

| Operación | Descripción |
|-----------|-------------|
| `crearComplejo(real, imag)` | Devuelve un complejo con los valores indicados. |
| `sumarComplejos(a, b)` | Devuelve la suma: `(a.real + b.real) + (a.imag + b.imag)i`. |
| `multiplicarComplejos(a, b)` | Devuelve el producto: `(a.real·b.real − a.imag·b.imag) + (a.real·b.imag + a.imag·b.real)i`. |
| `modulo(c)` | Devuelve `sqrt(c.real² + c.imag²)`. |
| `mostrarComplejo(c)` | Muestra por pantalla con el formato `(real, imag)`. |

**a) (5 pts)** Escribí el archivo de cabecera `complejo.h` con la representación del TDA y los prototipos de sus operaciones.

**b) (6 pts)** Implementá en `complejo.cpp` las funciones `sumarComplejos` y `modulo` (usá `<cmath>` para `sqrt`).

**c) (4 pts)** Escribí un fragmento de un programa **cliente** que cree los complejos `3 + 4i` y `1 − 2i`, calcule su suma y muestre la suma junto con el módulo del primero. Acordate: el cliente solo puede usar las operaciones del TDA, nunca sus campos directamente.

## B.4 Pilas y colas · 15 puntos

### Parte 1 — Traza (6 pts)

Mostrá el estado final de cada estructura.

**a)** Pila implementada con un arreglo `int datos[6]` y un tope que comienza en `-1`. Se ejecutan en orden:

`apilar(4)`, `apilar(7)`, `apilar(2)`, `desapilar()`, `apilar(9)`, `apilar(1)`, `apilar(5)`, `desapilar()`

Indicá: valor final de `tope`, elementos de la pila (de base a cima) y cuál es la cima.

**b)** Cola circular implementada con un arreglo `int datos[5]`, con `frente = 0` y `final = 0` (primer espacio libre). Se ejecutan en orden:

`encolar(10)`, `encolar(20)`, `encolar(30)`, `desencolar()`, `desencolar()`, `encolar(40)`, `encolar(50)`

Indicá: valores finales de `frente` y `final`, el contenido de la cola (de frente a final) y la cantidad de elementos.

### Parte 2 — Código (9 pts)

**c) (5 pts)** Implementá las operaciones `esColaVacia`, `encolar` y `desencolar` de la cola circular, usando `% MAXTAMQ` para actualizar los índices. Partí de esta representación:

```cpp
const int MAXTAMQ = 100;

struct tCola {
    int datos[MAXTAMQ];
    int frente;  // índice del primer elemento
    int final;   // índice del primer espacio libre
};
```

La cola está vacía cuando `frente == final`.

**d) (4 pts)** Usando las operaciones de una `tPila` (`esPilaVacia`, `apilar` y `desapilar`) y las operaciones `esColaVacia`, `encolar` y `desencolar` de la cola, escribí el procedimiento `invertirCola(tCola &c, tPila &p)`, que invierte el orden de los elementos de la cola usando la pila como auxiliar.

```cpp
void invertirCola(tCola &c, tPila &p);
```

---

# 📈 Parte C — Complejidad (20 puntos)

## C.1 Análisis de complejidad · 20 puntos

**a) (10 pts — 2 c/u)** Determiná el orden de complejidad **Θ** de cada caso y justificá en una línea:

**1.**

```cpp
int contador = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        contador++;
    }
}
```

**2.** (matriz de `N x N`)

```cpp
for (int i = 0; i < N; i++) {
    cout << matriz[i][i] << " ";
}
```

**3.** Obtener el menor de un arreglo de `N` elementos que está **ordenado ascendentemente**.

**4.** Buscar un número en un arreglo **desordenado** de `N` elementos.

**5.** Mezclar dos arreglos de `N` elementos cada uno.

**b) (3 pts)** ¿Por qué al analizar un algoritmo se estudia el peor caso y no el mejor caso? Explicá brevemente.

**c) (3 pts)** Explicá la diferencia entre **complejidad temporal** y **complejidad espacial**. ¿Cuál de las dos se analiza con más frecuencia y por qué?

**d) (4 pts — 2 c/u)** Respondé:

1. Un algoritmo resuelve un problema en tiempo constante. ¿Cuál es su orden de complejidad y por qué se considera lo ideal?
2. Si el tiempo de ejecución de un algoritmo se expresa como `T(N) = 3N² + 2N + 1`, ¿cuál es su orden de complejidad y por qué?

---

## 📊 Distribución de puntajes

| Parte | Ejercicio | Tema | Puntos |
|:-----:|-----------|------|:------:|
| A | A.1 | Selección múltiple (4 × 2) | 8 |
| A | A.2 | Verdadero o falso (3 × 2) | 6 |
| A | A.3 | Desarrollo breve (3 × 2) | 6 |
| B | B.1 | Arreglos multidimensionales | 15 |
| B | B.2 | Structs | 15 |
| B | B.3 | TDA | 15 |
| B | B.4 | Pilas y colas | 15 |
| C | C.1 | Complejidad | 20 |
| | | **Total** | **100** |

---

> 🧾 **Criterios de corrección:** se evaluará el uso correcto de funciones y parámetros, el pasaje por referencia cuando corresponda, el respeto de la interfaz del TDA, la prolijidad del código y la justificación de las respuestas teóricas.

<div align="center">

**¡Éxitos! 🍀**

</div>

---

# ✅ Respuestas esperadas

> Soluciones posibles para autocorrección o uso docente. En los ejercicios de código puede haber otras implementaciones correctas.

## 🧠 Parte A — Teoría

### A.1 Selección múltiple

| # | Tema | Respuesta | Justificación |
|:-:|------|:---------:|---------------|
| 1 | Matrices | **b** | Los arreglos se pasan por dirección: la función accede a la misma memoria y, en una matriz, debe conocer la cantidad de columnas. |
| 2 | Structs | **c** | Entre structs completos no hay comparación: los operadores `==`, `!=`, `>`, `<` no son válidos. Sí son válidas la asignación completa (`a = b;`), el acceso a campos y `sizeof`. |
| 3 | TDA | **c** | El TDA separa la interfaz de la implementación: se puede cambiar la implementación (incluso su `.cpp`) sin afectar a los programas cliente, mientras la interfaz se mantenga. |
| 4 | Pilas y colas | **c** | En la cola circular el índice avanza como `final = (final + 1) % MAXTAMQ`. Desapilar de una pila vacía es *underflow*; la cola es FIFO; el tope vale `-1` cuando la pila está **vacía**. |

### A.2 Verdadero o falso

1. **V** — Se puede omitir la longitud de la **primera** dimensión (solo de esa); el compilador deduce la cantidad de filas contando las llaves de la inicialización.
2. **F** — Por defecto los `struct` se pasan **por valor** (una copia). Los cambios dentro de la función no se reflejan: para que se reflejen hay que pasarlo por referencia (`Recital &r`).
3. **V** — El peor caso acota el tiempo máximo que puede tardar el algoritmo sin importar los datos de entrada; por eso da una garantía de comportamiento.

### A.3 Desarrollo breve

1. Un arreglo se pasa **por dirección**: el nombre del arreglo es la dirección de su primer elemento, por lo que la función accede a la misma memoria y puede modificarlo. Una variable simple como `int` se pasa **por valor** (copia) por defecto; para modificarla hay que usar una referencia (`int &`).
2. **LIFO (pila):** el último en entrar es el primero en salir; se apila y desapila siempre por el tope. Ejemplo: deshacer (*undo*), validación de paréntesis. **FIFO (cola):** el primero en entrar es el primero en salir; se encola al final y se desencola del frente. Ejemplo: trabajos enviados a la impresora, turnos de atención.
3. La **interfaz** es el conjunto de operaciones primitivas que el cliente puede usar sobre los valores del tipo (los datos que manejan y qué devuelven). La **implementación** es cómo se representan internamente los datos y cómo se codifican esas operaciones. El cliente solo necesita conocer la interfaz; la implementación puede cambiarse sin afectarlo.

## 💻 Parte B — Práctica

### B.1 Red de frío

**a)**

```cpp
double promedioSucursal(tTemperaturas t, int sh, int suc) {
    double suma = 0;
    for (int j = 0; j < sh; j++) {
        suma += t[suc][j];
    }
    return suma / sh;
}
```

**b)**

```cpp
int contarEnAlerta(tTemperaturas t, int sf, int sh, double limite) {
    int cant = 0;
    for (int i = 0; i < sf; i++) {
        for (int j = 0; j < sh; j++) {
            if (t[i][j] > limite) {
                cant++;
            }
        }
    }
    return cant;
}
```

**c)**

```cpp
void heladeraMasCaliente(tTemperaturas t, int sf, int sh, int &suc, int &hel) {
    suc = 0;
    hel = 0;
    for (int i = 0; i < sf; i++) {
        for (int j = 0; j < sh; j++) {
            if (t[i][j] > t[suc][hel]) {
                suc = i;
                hel = j;
            }
        }
    }
}
```

### B.2 Recitales

```cpp
const int MAXREC = 100;
typedef Recital tRecitales[MAXREC];
```

**a)**

```cpp
void cargarRecital(Recital &r) {
    cout << "Fecha (dia mes anio): ";
    cin >> r.fecha.dia >> r.fecha.mes >> r.fecha.anio;
    cout << "Entradas vendidas: ";
    cin >> r.entradasVendidas;
    cout << "Recaudacion: ";
    cin >> r.recaudacion;
    cin.ignore();               // descarta el salto de línea pendiente
    cout << "Artista: ";
    getline(cin, r.artista);
}
```

> Se accede a la fecha anidada con `r.fecha.dia`. Conviene leer los campos numéricos primero y el string al final (o usar `cin.ignore()` antes del `getline`), para que el salto de línea no se consuma como nombre.

**b)**

```cpp
double promedioRecaudacion(tRecitales v, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i].recaudacion;
    }
    return suma / n;
}
```

**c)**

```cpp
Recital masVendido(tRecitales v, int n) {
    Recital mejor = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i].entradasVendidas > mejor.entradasVendidas) {
            mejor = v[i];
        }
    }
    return mejor;
}
```

> La asignación `mejor = v[i];` es válida: C++ permite asignar structs completos del mismo tipo.

### B.3 TDA Complejo

**a) `complejo.h`**

```cpp
struct Complejo {
    double real;
    double imag;
};

Complejo crearComplejo(double real, double imag);
Complejo sumarComplejos(Complejo a, Complejo b);
Complejo multiplicarComplejos(Complejo a, Complejo b);
double modulo(Complejo c);
void mostrarComplejo(Complejo c);
```

**b) `complejo.cpp`**

```cpp
#include <cmath>
#include "complejo.h"

Complejo sumarComplejos(Complejo a, Complejo b) {
    Complejo res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

double modulo(Complejo c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}
```

**c) Programa cliente**

```cpp
#include <iostream>
#include "complejo.h"
using namespace std;

int main() {
    Complejo c1 = crearComplejo(3, 4);
    Complejo c2 = crearComplejo(1, -2);
    Complejo suma = sumarComplejos(c1, c2);
    mostrarComplejo(suma);
    cout << "Modulo de c1: " << modulo(c1) << endl;
    return 0;
}
```

> El cliente nunca accede a `c1.real` ni a `c1.imag`: obtiene el módulo llamando a `modulo(c1)`.

### B.4 Pilas y colas

**Parte 1 a)** Pila, operación por operación:

| Operación | Efecto | `tope` |
|-----------|--------|:------:|
| `apilar(4)` | datos[0] = 4 | 0 |
| `apilar(7)` | datos[1] = 7 | 1 |
| `apilar(2)` | datos[2] = 2 | 2 |
| `desapilar()` | devuelve 2 | 1 |
| `apilar(9)` | datos[2] = 9 | 2 |
| `apilar(1)` | datos[3] = 1 | 3 |
| `apilar(5)` | datos[4] = 5 | 4 |
| `desapilar()` | devuelve 5 | 3 |

**Estado final:** `tope = 3`; pila de base a cima: `4, 7, 9, 1`; cima: `1`.

**Parte 1 b)** Cola circular:

| Operación | Efecto | `frente` | `final` |
|-----------|--------|:--------:|:-------:|
| `encolar(10)` | datos[0] = 10 | 0 | 1 |
| `encolar(20)` | datos[1] = 20 | 0 | 2 |
| `encolar(30)` | datos[2] = 30 | 0 | 3 |
| `desencolar()` | devuelve 10 | 1 | 3 |
| `desencolar()` | devuelve 20 | 2 | 3 |
| `encolar(40)` | datos[3] = 40 | 2 | 4 |
| `encolar(50)` | datos[4] = 50 | 2 | 0 |

**Estado final:** `frente = 2`, `final = 0`; contenido de frente a final: `30, 40, 50`; cantidad de elementos: `3`.

> El índice `final` se envuelve con `(4 + 1) % 5 = 0`.

**c)**

```cpp
bool esColaVacia(tCola c) {
    return c.frente == c.final;
}

void encolar(tCola &c, int x) {
    c.datos[c.final] = x;
    c.final = (c.final + 1) % MAXTAMQ;
}

int desencolar(tCola &c) {
    int x = c.datos[c.frente];
    c.frente = (c.frente + 1) % MAXTAMQ;
    return x;
}
```

**d)**

```cpp
void invertirCola(tCola &c, tPila &p) {
    int x;
    while (!esColaVacia(c)) {
        x = desencolar(c);
        apilar(p, x);
    }
    while (!esPilaVacia(p)) {
        x = desapilar(p);
        encolar(c, x);
    }
}
```

> Al pasar por la pila, el primer elemento de la cola queda en el fondo y sale último: el orden de la cola se invierte.

## 📈 Parte C — Complejidad

### C.1 Análisis de complejidad

**a)**

1. **Θ(N²)** — El ciclo externo se repite N veces y, por cada una, el interno N veces: N × N.
2. **Θ(N)** — Solo se recorre la diagonal (`i == i` en cada vuelta), es decir N elementos.
3. **Θ(1)** — El arreglo está ordenado ascendentemente: el menor está en la primera posición, se accede directamente sin recorrer.
4. **Θ(N)** — En un arreglo desordenado, en el peor caso (el valor no está o está al final) hay que revisar los N elementos.
5. **Θ(N)** — Se recorre una vez cada arreglo: N + N operaciones, de orden lineal.

**b)** Porque el peor caso acota el tiempo **máximo**: da una garantía de cuánto puede tardar el algoritmo sin importar los datos de entrada. El mejor caso puede ser poco representativo (por ejemplo, encontrar lo buscado en la primera posición).

**c)** La complejidad **temporal** mide el tiempo (cantidad de operaciones) que consume el algoritmo en función del tamaño de la entrada; la **espacial** mide la memoria que utiliza. Se analiza con más frecuencia la temporal, porque el tiempo es un recurso más valioso y crítico que el espacio.

**d)**

1. **Θ(1)** (constante). Es lo ideal porque el tiempo de ejecución **no crece** con el tamaño de la entrada.
2. **Θ(N²)**. Cuando N crece, el término de mayor orden (`3N²`) domina, y los términos menores (`2N`) y las constantes (`1`) se vuelven despreciables.
