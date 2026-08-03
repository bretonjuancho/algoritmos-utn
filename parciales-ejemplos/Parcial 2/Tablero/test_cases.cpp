#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Ejercicio A: Función puntajes()
// Recibe el tablero y devuelve los puntajes de ambos jugadores
void puntajes(char tablero[], int &puntaje1, int &puntaje2) {
    puntaje1 = 0;
    puntaje2 = 0;
    int n = strlen(tablero);

    for (int i = 0; i <= n - 4; i++) {
        // Patrón: MAYÚSCULA - minúscula - minúscula - MAYÚSCULA
        if (isupper(tablero[i]) && islower(tablero[i+1]) && islower(tablero[i+2]) && isupper(tablero[i+3])) {
            // Verificar que sea la misma letra (jugador)
            if (toupper(tablero[i]) == toupper(tablero[i+3])) {
                if (toupper(tablero[i]) == 'R') {
                    puntaje1 += 5;
                } else if (toupper(tablero[i]) == 'A') {
                    puntaje2 += 5;
                }
            }
        }
    }
}

// Ejercicio B: Función recursiva eliminarJugadas()
// Elimina las piezas del jugador j y devuelve la cantidad de desplazamientos
int eliminarJugadas(char tablero[], int j) {
    int n = strlen(tablero);
    if (n == 0) return 0;

    char piezaBuscada = (j == 1) ? 'R' : 'A';
    int desplazamientos = 0;

    // Buscar primera ocurrencia de la pieza del jugador j
    for (int i = 0; i < n; i++) {
        if (toupper(tablero[i]) == toupper(piezaBuscada)) {
            // Desplazar todo a la izquierda
            for (int k = i; k < n - 1; k++) {
                tablero[k] = tablero[k + 1];
                desplazamientos++;
            }
            tablero[n - 1] = '\0';
            // Recursión con el tablero modificado
            return desplazamientos + eliminarJugadas(tablero, j);
        }
    }

    // No se encontró más la pieza
    return desplazamientos;
}

// Función auxiliar para imprimir el tablero
void imprimirTablero(char tablero[]) {
    cout << "[" << tablero << "]";
}

// Función para ejecutar un caso de prueba
void testPuntajes(char tablero[], int esperado1, int esperado2, int numTest) {
    int p1, p2;
    char copia[1000];
    strcpy(copia, tablero);
    puntajes(copia, p1, p2);

    cout << "Test " << numTest << ": ";
    imprimirTablero(tablero);
    cout << " -> J1=" << p1 << " J2=" << p2;
    if (p1 == esperado1 && p2 == esperado2) {
        cout << " [OK]" << endl;
    } else {
        cout << " [FALLA] (esperado J1=" << esperado1 << " J2=" << esperado2 << ")" << endl;
    }
}

void testEliminar(char tablero[], int jugador, int esperado, int numTest) {
    char copia[1000];
    strcpy(copia, tablero);
    int result = eliminarJugadas(copia, jugador);

    cout << "Test " << numTest << ": ";
    imprimirTablero(tablero);
    cout << " jugador=" << jugador;
    cout << " -> desplazamientos=" << result;
    if (result == esperado) {
        cout << " [OK]" << endl;
    } else {
        cout << " [FALLA] (esperado=" << esperado << ")" << endl;
    }
}

int main() {
    cout << "=== EJERCICIO A: PUNTAJES ===" << endl;
    testPuntajes((char*)"RrrR", 5, 0, 1);
    testPuntajes((char*)"AaaA", 0, 5, 2);
    testPuntajes((char*)"", 0, 0, 3);
    testPuntajes((char*)"RrRaA", 0, 0, 4);
    testPuntajes((char*)"RrrRAaaA", 5, 5, 5);
    testPuntajes((char*)"RrrRrrR", 10, 0, 6);
    testPuntajes((char*)"AaaAaaA", 0, 10, 7);
    testPuntajes((char*)"RrrRAaaARrrR", 10, 5, 8);
    testPuntajes((char*)"RRrrR", 5, 0, 9);
    testPuntajes((char*)"rRRrr", 0, 0, 10);
    testPuntajes((char*)"RrrR RrrR", 10, 0, 11);
    testPuntajes((char*)"AaaA RrrR AaaA", 5, 10, 12);
    testPuntajes((char*)"RrrRAaaARrrRAaaA", 10, 10, 13);

    cout << endl << "=== EJERCICIO B: ELIMINAR JUGADAS ===" << endl;
    testEliminar((char*)"RrrR", 1, 6, 1);
    testEliminar((char*)"AaaA", 2, 6, 2);
    testEliminar((char*)"", 1, 0, 3);
    testEliminar((char*)"RrAaR", 1, 7, 4);
    testEliminar((char*)"RrAaR", 2, 3, 5);
    testEliminar((char*)"RrrRAaaA", 1, 22, 6);
    testEliminar((char*)"RrrRAaaA", 2, 6, 7);
    testEliminar((char*)"AaRrAa", 1, 5, 8);
    testEliminar((char*)"AaRrAa", 2, 10, 9);
    testEliminar((char*)"RRRR", 1, 6, 10);
    testEliminar((char*)"AAAA", 1, 0, 11);
    testEliminar((char*)"RrAaRrAa", 1, 18, 12);

    return 0;
}
