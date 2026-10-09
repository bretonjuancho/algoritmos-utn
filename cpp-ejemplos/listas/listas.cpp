#include <iostream>
using namespace std;

// ============================================================
// TEMA: Listas - Estructuras de Datos Dinamicas
// Basado en: "Listas _ Estructuras de Datos Dinamicas.pdf"
// Contenido del PDF cubierto:
//  1. Asignacion dinamica de memoria (new / delete)
//  2. Estructuras auto-referenciadas (struct Nodo)
//  3. Lista enlazada simple (insertar, mostrar, buscar, eliminar)
//  4. Lista circular y lista doblemente enlazada (ejemplos simples)
// ============================================================

// ---------- 2. Estructura auto-referenciada ----------
// Tiene un puntero a una estructura del mismo tipo.
// Ese puntero (proximoPtr) se llama "enlace".
// La lista termina con un puntero NULL.
struct Nodo {
    int dato;
    Nodo* proximoPtr;
};

// ---------- Lista doblemente enlazada ----------
// Cada nodo tiene un puntero al siguiente y otro al anterior.
// Se puede recorrer en ambas direcciones.
struct NodoDoble {
    int dato;
    NodoDoble* anteriorPtr;
    NodoDoble* siguientePtr;
};

// ---------- Prototipos lista simple ----------
Nodo* crearNodo(int valor);
void insertarAlInicio(Nodo*& lista, int valor);
void insertarAlFinal(Nodo*& lista, int valor);
void mostrarLista(Nodo* lista);
bool buscarEnLista(Nodo* lista, int valor);
void eliminarNodo(Nodo*& lista, int valor);
void liberarLista(Nodo*& lista);

// ---------- Prototipos lista doble (simple) ----------
void insertarAlFinalDoble(NodoDoble*& lista, int valor);
void mostrarDobleAdelante(NodoDoble* lista);
void mostrarDobleAtras(NodoDoble* lista);
void liberarDoble(NodoDoble*& lista);

// ---------- 1. Ejemplo de new / delete con un entero ----------
void ejemploNewDelete() {
    cout << "--- 1. new / delete (un entero) ---" << endl;

    int* ptr = new int;   // Ptr = new int; (reserva memoria en ejecucion)
    *ptr = 42;            // la variable dinamica solo se accede por puntero
    cout << "Valor dinamico: " << *ptr << endl;

    delete ptr;           // 1) destruye la variable, 2) libera la memoria
    ptr = NULL;           // buena practica del apunte: evitar doble delete
}

// ---------- 1b. Ejemplo de array dinamico ----------
void ejemploArrayDinamico() {
    cout << "\n--- 2. Array dinamico (new[] / delete[]) ---" << endl;

    int n = 5;
    int* vec = new int[n];  // se reserva memoria recien al ejecutar

    for (int i = 0; i < n; i++) {
        vec[i] = (i + 1) * 10;
    }

    cout << "Vector: ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    delete[] vec;  // delete[] libera un vector dinamico (delete solo: un objeto)
    vec = NULL;
}

// ---------- 1c. Ejemplo de matriz dinamica ----------
// Vector dinamico de vectores dinamicos.
void ejemploMatrizDinamica() {
    cout << "\n--- 3. Matriz dinamica ---" << endl;

    int filas = 2, columnas = 3;
    int** mat = new int*[filas];
    for (int i = 0; i < filas; i++) {
        mat[i] = new int[columnas];
    }

    int cont = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            mat[i][j] = cont++;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < filas; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    mat = NULL;
}

// ---------- 3. Operaciones de lista enlazada simple ----------

Nodo* crearNodo(int valor) {
    Nodo* nuevoPtr = new Nodo;
    nuevoPtr->dato = valor;
    nuevoPtr->proximoPtr = NULL;  // todo nodo nuevo nace apuntando a NULL
    return nuevoPtr;
}

// Insertar al inicio: el nuevo nodo apunta al que era primero,
// y el puntero maestro pasa a apuntar al nuevo.
void insertarAlInicio(Nodo*& lista, int valor) {
    Nodo* nuevoPtr = crearNodo(valor);
    nuevoPtr->proximoPtr = lista;
    lista = nuevoPtr;
}

// Insertar al final: se recorre hasta el ultimo (el que apunta a NULL)
// y se lo enlaza al nuevo nodo.
void insertarAlFinal(Nodo*& lista, int valor) {
    Nodo* nuevoPtr = crearNodo(valor);
    if (lista == NULL) {
        lista = nuevoPtr;
        return;
    }
    Nodo* actual = lista;
    while (actual->proximoPtr != NULL) {
        actual = actual->proximoPtr;
    }
    actual->proximoPtr = nuevoPtr;
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = lista;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->proximoPtr;
    }
    cout << "NULL" << endl;
}

bool buscarEnLista(Nodo* lista, int valor) {
    Nodo* actual = lista;
    while (actual != NULL) {
        if (actual->dato == valor) {
            return true;
        }
        actual = actual->proximoPtr;
    }
    return false;
}

// Eliminar un nodo: se reconectan los nodos sueltos
// (el anterior apunta al siguiente del eliminado) y se hace delete.
void eliminarNodo(Nodo*& lista, int valor) {
    if (lista == NULL) return;

    Nodo* actual = lista;
    Nodo* anterior = NULL;

    // Buscar el nodo (previousPtr / currentPtr del grafico del PDF)
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->proximoPtr;
    }

    if (actual == NULL) {
        cout << "No se encontro el valor " << valor << endl;
        return;
    }

    if (anterior == NULL) {
        lista = actual->proximoPtr;  // era el primero
    } else {
        anterior->proximoPtr = actual->proximoPtr;  // "puente" sobre el eliminado
    }

    delete actual;  // libera la memoria del nodo
    actual = NULL;
}

void liberarLista(Nodo*& lista) {
    while (lista != NULL) {
        Nodo* tempPtr = lista;
        lista = lista->proximoPtr;
        delete tempPtr;
    }
    lista = NULL;
}

// ---------- 4. Lista doblemente enlazada (ejemplo minimo) ----------

void insertarAlFinalDoble(NodoDoble*& lista, int valor) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = valor;
    nuevo->anteriorPtr = NULL;
    nuevo->siguientePtr = NULL;

    if (lista == NULL) {
        lista = nuevo;
        return;
    }
    NodoDoble* actual = lista;
    while (actual->siguientePtr != NULL) {
        actual = actual->siguientePtr;
    }
    actual->siguientePtr = nuevo;
    nuevo->anteriorPtr = actual;
}

void mostrarDobleAdelante(NodoDoble* lista) {
    NodoDoble* actual = lista;
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        if (actual->siguientePtr == NULL) break;
        actual = actual->siguientePtr;
    }
    cout << "NULL" << endl;
}

void mostrarDobleAtras(NodoDoble* lista) {
    if (lista == NULL) {
        cout << "NULL" << endl;
        return;
    }
    // Ir al ultimo
    NodoDoble* actual = lista;
    while (actual->siguientePtr != NULL) {
        actual = actual->siguientePtr;
    }
    // Volver hacia atras
    while (actual != NULL) {
        cout << actual->dato << " <-> ";
        actual = actual->anteriorPtr;
    }
    cout << "NULL" << endl;
}

void liberarDoble(NodoDoble*& lista) {
    while (lista != NULL) {
        NodoDoble* temp = lista;
        lista = lista->siguientePtr;
        delete temp;
    }
    lista = NULL;
}

// ---------- 4b. Lista circular (ejemplo minimo) ----------
// El ultimo nodo NO apunta a NULL: apunta al primero.
// No hay principio/fin definidos; el puntero maestro marca el ingreso.
void ejemploListaCircular() {
    cout << "\n--- 6. Lista circular ---" << endl;

    Nodo* lista = crearNodo(3);
    lista->proximoPtr = crearNodo(8);
    lista->proximoPtr->proximoPtr = crearNodo(2);

    // Cerrar el circulo: ultimo -> primero
    lista->proximoPtr->proximoPtr->proximoPtr = lista;

    // Recorrer una vuelta completa (3 nodos)
    Nodo* actual = lista;
    for (int i = 0; i < 3; i++) {
        cout << actual->dato << " -> ";
        actual = actual->proximoPtr;
    }
    cout << "(vuelve al inicio: " << actual->dato << ")" << endl;

    // Liberar: primero romper el circulo
    lista->proximoPtr->proximoPtr->proximoPtr = NULL;
    liberarLista(lista);
}

int main() {
    ejemploNewDelete();
    ejemploArrayDinamico();
    ejemploMatrizDinamica();

    // --- Lista enlazada simple ---
    cout << "\n--- 4. Lista enlazada simple ---" << endl;
    Nodo* lista = NULL;  // puntero maestro: empieza vacia (NULL)

    insertarAlFinal(lista, 10);
    insertarAlFinal(lista, 20);
    insertarAlFinal(lista, 30);
    insertarAlInicio(lista, 5);
    cout << "Lista: ";
    mostrarLista(lista);

    cout << "Buscar 20: " << (buscarEnLista(lista, 20) ? "encontrado" : "no encontrado") << endl;
    cout << "Buscar 99: " << (buscarEnLista(lista, 99) ? "encontrado" : "no encontrado") << endl;

    cout << "Elimino el 20: ";
    eliminarNodo(lista, 20);
    mostrarLista(lista);

    cout << "Elimino el primero (5): ";
    eliminarNodo(lista, 5);
    mostrarLista(lista);

    liberarLista(lista);  // liberar toda la memoria al final

    // --- Lista doblemente enlazada ---
    cout << "\n--- 5. Lista doblemente enlazada ---" << endl;
    NodoDoble* listaDoble = NULL;
    insertarAlFinalDoble(listaDoble, 3);
    insertarAlFinalDoble(listaDoble, 8);
    insertarAlFinalDoble(listaDoble, 2);
    cout << "Hacia adelante: ";
    mostrarDobleAdelante(listaDoble);
    cout << "Hacia atras:    ";
    mostrarDobleAtras(listaDoble);
    liberarDoble(listaDoble);

    ejemploListaCircular();

    return 0;
}
