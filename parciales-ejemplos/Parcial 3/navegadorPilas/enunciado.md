# Algoritmos y Estructuras de Datos
*Ejemplo de Examen Parcial 3 AEDD 2026 (Ejercicio de Papel)*

> **Ejemplo de parcial generado con IA. Usarlo para practicar, NO COMO PARÁMETRO DE LO QUE PUEDEN TOMAR.**

**Nombre y Apellido:** ............................................................................ **Comisión:** ..........

*Las entregas deben tener nombre y apellido en todas las hojas.*

**Tiempo de Resolución:** 90 minutos. **Puntaje Requerido:** 20/40 puntos.

---

## Ejercicio de Papel: El botón "Atrás" de Lucía

Lucía está programando su propio NAVEGADOR WEB como proyecto de la facultad. Cada vez que el usuario entra a una página, el navegador registra una VISITA. Una VISITA queda identificada por una página (tipo PÁGINA), el tiempo de permanencia en segundos (tipo entero) y si la conexión fue segura (tipo bool: `true` si fue *https*, `false` si fue *http*). Una PÁGINA queda definida por su dominio (string, por ejemplo `"frsf.utn.edu.ar"`) y su ruta (string, por ejemplo `"/alumnos"`).

Para implementar el botón **"Atrás"**, Lucía guarda el historial de navegación en una **PILA DE VISITAS**: cada vez que se visita una página nueva, la VISITA se apila. Al apretar "Atrás", el navegador vuelve a la visita **más reciente**, después a la anterior, y así sucesivamente. El historial guarda como máximo las **30 VISITAS** más recientes.

Por seguridad, el navegador ofrece la opción de **borrar del historial las visitas no seguras** (*http*). Al hacerlo, las visitas seguras deben quedar en el historial **en el mismo orden en el que estaban**, para que el botón "Atrás" siga funcionando como antes.

En base a estas definiciones, se le solicita:

1. **(5 pts)** Defina todas las estructuras de datos necesarias para representar el **TDA VISITA**.

2. **(5 pts)** Incluya en el TDA definido en el ítem anterior las funciones necesarias para la **asignación y consulta** de cada uno de los siguientes campos: `pagina`, `segundos` y `segura`.

3. **(10 pts)** Haciendo uso del TDA VISITA, defina las estructuras de datos necesarias para representar una **PILA DE VISITAS** en C++, implementada **sobre un arreglo**. Implemente además sus operaciones primitivas: `crearPila()`, `pilaVacia()`, `pilaLlena()`, `apilar()`, `desapilar()` y `cima()`.

4. **(8 pts)** Implemente la función `imprimirHistorial()`, que recibe una PILA DE VISITAS e imprime por pantalla el dominio y la ruta de cada VISITA **en el orden en que se recorrerían apretando "Atrás"** (de la más reciente a la más antigua). Además, la función debe retornar el **tiempo total de navegación** en segundos. Al terminar, la pila del programa que la llamó **no debe quedar modificada**.

5. **(12 pts)** Implemente la función `borrarInseguras()`, que recibe la PILA DE VISITAS del historial y elimina de ella todas las visitas **no seguras**. Las visitas que quedan deben conservar **el mismo orden** que tenían en la pila original. La función debe retornar la **cantidad de visitas eliminadas**.

---

> **Importante:** el alumno puede codificar todas las funciones auxiliares que considere necesarias. En los casos en los que no se indica un prototipo, los parámetros formales (cantidad, tipo y modo de pasaje) deben definirse según lo pedido. Fuera de las funciones del TDA, las VISITAS deben manejarse **solo con las funciones del TDA**, sin acceder a sus campos directamente. Las pilas se recorren **solo con sus operaciones primitivas** (no se permite recorrer el arreglo interno con un `for`). El puntaje final tendrá en cuenta la eficiencia de la estrategia de resolución elegida.

<br>

---
---

# ✅ Resolución posible

> Para autocorrección o uso docente. Puede haber otras soluciones correctas. El código completo, con un `main` de prueba, está en [`resuelto.cpp`](resuelto.cpp).

### 1. TDA VISITA: estructuras

```cpp
struct Pagina {
    string dominio;
    string ruta;
};

struct Visita {
    Pagina pagina;
    int segundos;
    bool segura;      // true: https, false: http
};
```

### 2. Asignación y consulta

```cpp
void setPagina(Visita &v, Pagina pag)   { v.pagina = pag; }
Pagina getPagina(Visita v)              { return v.pagina; }

void setSegundos(Visita &v, int seg)    { v.segundos = seg; }
int getSegundos(Visita v)               { return v.segundos; }

void setSegura(Visita &v, bool segura)  { v.segura = segura; }
bool getSegura(Visita v)                { return v.segura; }
```

> Los *set* reciben la visita **por referencia** porque la modifican; los *get* pueden recibirla por valor.

### 3. PILA DE VISITAS

```cpp
const int MAX_VISITAS = 30;

struct PilaVisitas {
    Visita vec[MAX_VISITAS];
    int tope;   // posición de la cima; -1 si está vacía
};

void crearPila(PilaVisitas &p) {
    p.tope = -1;
}

bool pilaVacia(const PilaVisitas &p) {
    return p.tope == -1;
}

bool pilaLlena(const PilaVisitas &p) {
    return p.tope == MAX_VISITAS - 1;
}

bool apilar(PilaVisitas &p, Visita v) {
    if (pilaLlena(p)) {
        return false;
    }
    p.tope++;
    p.vec[p.tope] = v;
    return true;
}

// Precondición: la pila no está vacía.
Visita desapilar(PilaVisitas &p) {
    Visita v = p.vec[p.tope];
    p.tope--;
    return v;
}

// Precondición: la pila no está vacía.
Visita cima(const PilaVisitas &p) {
    return p.vec[p.tope];
}
```

> **Para corregir:**
> - Con `tope` empezando en `-1`, la pila está llena cuando `tope == MAX_VISITAS - 1` (no `== MAX_VISITAS`). Otra convención válida es que `tope` sea la primera posición libre (empieza en `0`), siempre que sea coherente en todas las operaciones.
> - En `apilar` el orden importa: primero se incrementa `tope` y después se asigna (o al revés si `tope` es la primera posición libre). Mezclar las convenciones pisa un elemento o deja un hueco.
> - A diferencia de la cola, la pila **no necesita** `%`: solo crece y decrece por un extremo.
> - `desapilar` y `cima` devuelven una `Visita`, así que no pueden devolver `-1`. Es válido dejarlo como precondición o usar `bool desapilar(PilaVisitas &p, Visita &v)`.

### 4. `imprimirHistorial`

```cpp
int imprimirHistorial(PilaVisitas h) {     // POR VALOR
    int total = 0;
    while (!pilaVacia(h)) {
        Visita v = desapilar(h);
        Pagina pag = getPagina(v);
        cout << pag.dominio << pag.ruta << endl;
        total += getSegundos(v);
    }
    return total;
}
```

> **Lo que se evalúa:**
> - Desapilar da justamente el orden pedido (de la más reciente a la más antigua): **no hace falta invertir nada**.
> - La pila se pasa **por valor**, así que la función desapila una **copia** y el historial original no cambia. Si se pasa por referencia, el historial queda vacío y no cumple la consigna.

### 5. `borrarInseguras`

```cpp
int borrarInseguras(PilaVisitas &h) {
    PilaVisitas aux;
    crearPila(aux);
    int borradas = 0;

    while (!pilaVacia(h)) {
        Visita v = desapilar(h);
        if (getSegura(v)) {
            apilar(aux, v);       // la segura se guarda (queda invertida)
        } else {
            borradas++;           // la insegura se descarta
        }
    }
    while (!pilaVacia(aux)) {
        apilar(h, desapilar(aux));   // se vuelve a invertir: orden original
    }
    return borradas;
}
```

> **Lo que se evalúa:**
> - `h` va **por referencia**, porque la función la modifica.
> - **La idea clave del ejercicio:** pasar los elementos de una pila a otra **invierte** el orden. Para conservarlo hay que pasarlos **dos veces** (ida a la auxiliar y vuelta al historial).
> - Error típico: hacer solo la primera pasada y devolver `aux` (o asignar `h = aux`): el historial queda **al revés** y "Atrás" lleva a la página más vieja.
> - Error típico: filtrar en la vuelta en vez de en la ida. También funciona, pero hay que contar bien las borradas y no mezclar las dos pasadas.
> - Se resuelve en Θ(N): cada visita se desapila y apila a lo sumo dos veces.

### Traza de ejemplo

Historial (de la **base** a la **cima**, es decir, en el orden en que se visitaron):

| # | Página | Seg. | Segura |
|:-:|--------|-----:|:------:|
| 1 | frsf.utn.edu.ar/ | 40 | ✔ |
| 2 | frsf.utn.edu.ar/alumnos | 120 | ✔ |
| 3 | apuntes-gratis.com/aedd | 300 | ✘ |
| 4 | omegaup.com/problemas | 900 | ✔ |
| 5 | descargas.net/zinjai | 60 | ✘ |
| 6 | cppreference.com/stack ← **cima** | 240 | ✔ |

- `imprimirHistorial(h)` imprime 6, 5, 4, 3, 2, 1 y retorna **1660**. El historial sigue con las 6 visitas.
- `borrarInseguras(h)` retorna **2**. El historial queda (de la base a la cima): 1, 2, 4, 6, con cima `cppreference.com/stack`. Un nuevo `imprimirHistorial(h)` imprime 6, 4, 2, 1 y retorna **1300**.
