# Algoritmos y Estructuras de Datos
*Ejemplo de Examen Parcial 3 AEDD 2026 (Ejercicio de Papel)*

> **Ejemplo de parcial generado con IA. Usarlo para practicar, NO COMO PARÁMETRO DE LO QUE PUEDEN TOMAR.**

**Nombre y Apellido:** ............................................................................ **Comisión:** ..........

*Las entregas deben tener nombre y apellido en todas las hojas.*

**Tiempo de Resolución:** 90 minutos. **Puntaje Requerido:** 20/40 puntos.

---

## Ejercicio de Papel: Las empanadas de Sofía

Sofía abrió una ROTISERÍA y recibe PEDIDOS de empanadas durante toda la noche. Un PEDIDO queda identificado por un número de pedido (tipo entero), un cliente (tipo CLIENTE), una cantidad de empanadas (tipo entero), un importe (tipo double) y un tipo de entrega (0: retira en el local, 1: delivery). Un CLIENTE queda definido por su nombre (string) y su teléfono (string).

Para no tener problemas con los clientes, Sofía decidió atender los PEDIDOS **estrictamente en el orden en que llegan**: el primero que pidió es el primero en recibir sus empanadas. Por eso organiza su trabajo con una **COLA DE PEDIDOS**. Se sabe que en una noche la rotisería no recibe más de **50 PEDIDOS**.

A las 21 h llega el cadete de delivery y Sofía separa los PEDIDOS: los de delivery pasan a una nueva COLA para el cadete, y en la cola original quedan solo los que se retiran en el local. Ambos grupos se deben despachar en el mismo orden en que llegaron.

En base a estas definiciones, se le solicita:

1. **(5 pts)** Defina todas las estructuras de datos necesarias para representar el **TDA PEDIDO**.

2. **(5 pts)** Incluya en el TDA definido en el ítem anterior las funciones necesarias para la **asignación y consulta** de cada uno de los siguientes campos: `cliente`, `importe` y `tipo`.

3. **(10 pts)** Haciendo uso del TDA PEDIDO, defina las estructuras de datos necesarias para representar una **COLA DE PEDIDOS** en C++, implementada como **cola circular sobre un arreglo**. Implemente además sus operaciones primitivas: `crearCola()`, `colaVacia()`, `colaLlena()`, `encolar()` y `desencolar()`.

4. **(8 pts)** Implemente la función `imprimirPedidos()`, que recibe una COLA DE PEDIDOS e imprime por pantalla el número de pedido y el nombre del cliente de cada PEDIDO, **en el orden en que serán despachados**. Además, la función debe retornar el **importe total** de los pedidos. Al terminar, la cola del programa que la llamó **no debe quedar modificada**.

5. **(12 pts)** Implemente la función `separarDelivery()`, que recibe la COLA DE PEDIDOS de la noche y **retorna una nueva COLA DE PEDIDOS** con los pedidos de delivery. Al terminar, la cola recibida debe contener **solo** los pedidos que se retiran en el local. **Las dos colas deben respetar el orden de llegada original.**

---

> **Importante:** el alumno puede codificar todas las funciones auxiliares que considere necesarias. En los casos en los que no se indica un prototipo, los parámetros formales (cantidad, tipo y modo de pasaje) deben definirse según lo pedido. Fuera de las funciones del TDA, los PEDIDOS deben manejarse **solo con las funciones del TDA**, sin acceder a sus campos directamente. Las colas se recorren **solo con sus operaciones primitivas** (no se permite recorrer el arreglo interno con un `for`). El puntaje final tendrá en cuenta la eficiencia de la estrategia de resolución elegida.

<br>

---
---

# ✅ Resolución posible

> Para autocorrección o uso docente. Puede haber otras soluciones correctas. El código completo, con un `main` de prueba, está en [`resuelto.cpp`](resuelto.cpp).

### 1. TDA PEDIDO: estructuras

```cpp
const int RETIRA = 0;
const int DELIVERY = 1;

struct Cliente {
    string nombre;
    string telefono;
};

struct Pedido {
    int numero;
    Cliente cliente;
    int cantEmpanadas;
    double importe;
    int tipo;            // RETIRA o DELIVERY
};
```

### 2. Asignación y consulta

```cpp
void setCliente(Pedido &p, Cliente cli)   { p.cliente = cli; }
Cliente getCliente(Pedido p)              { return p.cliente; }

void setImporte(Pedido &p, double imp)    { p.importe = imp; }
double getImporte(Pedido p)               { return p.importe; }

void setTipo(Pedido &p, int tipo)         { p.tipo = tipo; }
int getTipo(Pedido p)                     { return p.tipo; }

int getNumero(Pedido p)                   { return p.numero; }   // auxiliar, se usa en el ítem 4
```

> Los *set* reciben el pedido **por referencia** porque lo modifican; los *get* pueden recibirlo por valor.

### 3. COLA DE PEDIDOS

```cpp
const int MAX_PEDIDOS = 50;
const int TAMC = MAX_PEDIDOS + 1;   // un lugar se reserva para distinguir llena de vacía

struct ColaPedidos {
    Pedido vec[TAMC];
    int inicio;   // posición del primer pedido
    int fin;      // primera posición libre
};

void crearCola(ColaPedidos &c) {
    c.inicio = 0;
    c.fin = 0;
}

bool colaVacia(const ColaPedidos &c) {
    return c.inicio == c.fin;
}

bool colaLlena(const ColaPedidos &c) {
    return (c.fin + 1) % TAMC == c.inicio;
}

bool encolar(ColaPedidos &c, Pedido p) {
    if (colaLlena(c)) {
        return false;
    }
    c.vec[c.fin] = p;
    c.fin = (c.fin + 1) % TAMC;
    return true;
}

// Precondición: la cola no está vacía.
Pedido desencolar(ColaPedidos &c) {
    Pedido p = c.vec[c.inicio];
    c.inicio = (c.inicio + 1) % TAMC;
    return p;
}
```

> **Para corregir:**
> - Con la convención "un lugar libre", para guardar 50 pedidos el arreglo necesita **51** posiciones. Otra opción válida es usar un contador `cant` y un arreglo de 50.
> - El `% TAMC` es lo que hace circular a la cola. Si `fin` e `inicio` solo se incrementan, la cola se "agota" aunque se hayan desencolado elementos.
> - `desencolar` no puede devolver `-1` como en la cola de enteros, porque devuelve un `Pedido`. Por eso es válido: (a) dejarlo como precondición, o (b) usar `bool desencolar(ColaPedidos &c, Pedido &p)`.

### 4. `imprimirPedidos`

```cpp
double imprimirPedidos(ColaPedidos c) {     // POR VALOR
    double total = 0;
    while (!colaVacia(c)) {
        Pedido p = desencolar(c);
        cout << "Pedido " << getNumero(p) << " - " << getCliente(p).nombre << endl;
        total += getImporte(p);
    }
    return total;
}
```

> **Lo que se evalúa:** la cola se pasa **por valor**, así que la función desencola una **copia** y la cola original no cambia. Si se pasa por referencia (`ColaPedidos &c`) la cola original queda vacía, y eso no cumple la consigna. Otra opción válida es pasarla por referencia y, al desencolar cada pedido, volver a encolarlo (contando cuántos hay), pero es más larga y hay más lugar para errores.

### 5. `separarDelivery`

```cpp
ColaPedidos separarDelivery(ColaPedidos &pedidos) {
    ColaPedidos delivery, local;
    crearCola(delivery);
    crearCola(local);

    while (!colaVacia(pedidos)) {
        Pedido p = desencolar(pedidos);
        if (getTipo(p) == DELIVERY) {
            encolar(delivery, p);
        } else {
            encolar(local, p);
        }
    }
    pedidos = local;    // asignación de structs completos
    return delivery;
}
```

> **Lo que se evalúa:**
> - `pedidos` va **por referencia**, porque la función la modifica.
> - Como la cola es FIFO, desencolar y encolar en otra cola **conserva el orden**. Si se usara una **pila** como auxiliar, el orden se invertiría: es un error típico.
> - Se resuelve en **una sola pasada**: Θ(N).
> - Error frecuente: hacer `encolar(pedidos, p)` dentro del mismo `while (!colaVacia(pedidos))`. Así la cola nunca queda vacía y el ciclo no termina. Si se quiere reusar la misma cola, hay que contar primero cuántos pedidos hay y repetir exactamente esa cantidad de veces.

### Traza de ejemplo

Cola inicial (frente → final):

| Nº | Cliente | Importe | Tipo |
|:--:|---------|--------:|:----:|
| 1 | Ana | 18000 | local |
| 2 | Beto | 9500 | delivery |
| 3 | Caro | 34000 | delivery |
| 4 | Dani | 9000 | local |
| 5 | Eli | 19500 | delivery |

- `imprimirPedidos(cola)` imprime 1, 2, 3, 4, 5 y retorna **90000**. La cola sigue con los 5 pedidos.
- `delivery = separarDelivery(cola)`:
  - `delivery` → 2, 3, 5 (total 63000)
  - `cola` → 1, 4 (total 27000)
