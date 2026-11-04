// Parcial 3 (ejemplo) - Ejercicio de Papel: "El boton Atras de Lucia"
// Resolucion posible. Tema principal: Pilas (pila con arreglo y tope).
#include <iostream>
#include <string>
using namespace std;

// =====================================================================
// 1. TDA VISITA - Estructuras de datos
// =====================================================================
struct Pagina {
    string dominio;   // ej: "frsf.utn.edu.ar"
    string ruta;      // ej: "/alumnos"
};

struct Visita {
    Pagina pagina;
    int segundos;     // tiempo de permanencia
    bool segura;      // true: https, false: http
};

// =====================================================================
// 2. TDA VISITA - Asignacion y consulta
// =====================================================================
Visita crearVisita(Pagina pag, int seg, bool segura) {
    Visita v;
    v.pagina = pag;
    v.segundos = seg;
    v.segura = segura;
    return v;
}

void setPagina(Visita &v, Pagina pag)   { v.pagina = pag; }
Pagina getPagina(Visita v)              { return v.pagina; }

void setSegundos(Visita &v, int seg)    { v.segundos = seg; }
int getSegundos(Visita v)               { return v.segundos; }

void setSegura(Visita &v, bool segura)  { v.segura = segura; }
bool getSegura(Visita v)                { return v.segura; }

// =====================================================================
// 3. PILA DE VISITAS - Estructuras + primitivas
// =====================================================================
const int MAX_VISITAS = 30;

struct PilaVisitas {
    Visita vec[MAX_VISITAS];
    int tope;   // posicion de la cima; -1 si esta vacia
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

// Precondicion: la pila no esta vacia.
Visita desapilar(PilaVisitas &p) {
    Visita v = p.vec[p.tope];
    p.tope--;
    return v;
}

// Precondicion: la pila no esta vacia.
Visita cima(const PilaVisitas &p) {
    return p.vec[p.tope];
}

// =====================================================================
// 4. imprimirHistorial
//    Por VALOR: se desapila una copia, el historial original no cambia.
// =====================================================================
int imprimirHistorial(PilaVisitas h) {
    int total = 0;
    while (!pilaVacia(h)) {
        Visita v = desapilar(h);
        Pagina pag = getPagina(v);
        cout << pag.dominio << pag.ruta << endl;
        total += getSegundos(v);
    }
    return total;
}

// =====================================================================
// 5. borrarInseguras
//    Elimina del historial las visitas no seguras, conservando el orden
//    de las demas. Devuelve la cantidad de visitas eliminadas.
//    Se usa UNA pila auxiliar: al pasar a la auxiliar el orden se
//    invierte, y al devolverlas al historial se vuelve a invertir
//    (queda el orden original). Theta(N): cada visita se mueve 2 veces.
// =====================================================================
int borrarInseguras(PilaVisitas &h) {
    PilaVisitas aux;
    crearPila(aux);
    int borradas = 0;

    while (!pilaVacia(h)) {
        Visita v = desapilar(h);
        if (getSegura(v)) {
            apilar(aux, v);
        } else {
            borradas++;
        }
    }
    while (!pilaVacia(aux)) {
        apilar(h, desapilar(aux));
    }
    return borradas;
}

// =====================================================================
// Programa de prueba (no se pide en el parcial)
// =====================================================================
int main() {
    PilaVisitas h;
    crearPila(h);

    // Se apilan en el orden en que Lucia las visito (la ultima queda en la cima)
    apilar(h, crearVisita({"frsf.utn.edu.ar", "/"}, 40, true));
    apilar(h, crearVisita({"frsf.utn.edu.ar", "/alumnos"}, 120, true));
    apilar(h, crearVisita({"apuntes-gratis.com", "/aedd"}, 300, false));
    apilar(h, crearVisita({"omegaup.com", "/problemas"}, 900, true));
    apilar(h, crearVisita({"descargas.net", "/zinjai"}, 60, false));
    apilar(h, crearVisita({"cppreference.com", "/stack"}, 240, true));

    cout << "== Historial (de la mas reciente a la mas antigua) ==" << endl;
    int total = imprimirHistorial(h);
    cout << "Tiempo total: " << total << " s" << endl;

    cout << "\n== El historial sigue intacto ==" << endl;
    imprimirHistorial(h);

    int borradas = borrarInseguras(h);
    cout << "\n== Sin inseguras (" << borradas << " borradas) ==" << endl;
    total = imprimirHistorial(h);
    cout << "Tiempo total: " << total << " s" << endl;
    cout << "Cima: " << getPagina(cima(h)).dominio << endl;

    // Caso borde: pila llena y todas inseguras
    PilaVisitas h2;
    crearPila(h2);
    for (int i = 0; i < MAX_VISITAS; i++) {
        apilar(h2, crearVisita({"x.com", "/"}, 1, false));
    }
    cout << "\nLlena: " << pilaLlena(h2) << "  apilar de mas: " << apilar(h2, cima(h2)) << endl;
    cout << "Borradas: " << borrarInseguras(h2) << "  vacia: " << pilaVacia(h2) << endl;
    return 0;
}
