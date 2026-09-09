// Archivo: cola.h
// TDA Cola - REPRESENTACION + INTERFAZ (parte publica)
// Cola FIFO circular con arreglo estatico.
// Capacidad util: TAMc - 1 (un hueco se reserva para distinguir
// cola llena de cola vacia).

#ifndef COLA_H
#define COLA_H
#define TAMc 10

// Representacion: vec guarda los datos, inicio apunta al primero,
// fin apunta a la posicion libre siguiente al ultimo.
struct Cola {
    int vec[TAMc];
    int inicio = 0, fin = 0;
};

// Agrega un elemento al final. Devuelve false si la cola esta llena.
bool encolar(Cola &, int);

// Saca y devuelve el primer elemento. Si esta vacia devuelve -1.
// Limitacion didactica: -1 no se puede usar como dato valido.
// Para chequear antes, usar colaVacia().
int desencolar(Cola &);

// Devuelve el primer elemento sin sacarlo. Si esta vacia devuelve -1.
int frente(const Cola &);

bool colaVacia(const Cola &);
bool colaLlena(const Cola &);

#endif
