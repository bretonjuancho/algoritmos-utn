#include <iostream>
#define TAM 100

using namespace std;

bool esMagico(int [][TAM], int);

int main() {
    int matriz[TAM][TAM];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    if (esMagico(matriz, n)) {
        cout << "Es magico" << endl;
    } else {
        cout << "No es magico" << endl;
    }

    return 0;
}

bool esMagico(int matriz[][TAM], int n) {
    int referencia = 0;
    for (int j = 0; j < n; j++) {
        referencia += matriz[0][j];
    }

    for (int i = 1; i < n; i++) {
        int sumaFila = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != referencia) {
            return false;
        }
    }

    for (int j = 0; j < n; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < n; i++) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != referencia) {
            return false;
        }
    }

    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonalPrincipal += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][n - 1 - i];
    }

    if ((sumaDiagonalPrincipal != referencia) or (sumaDiagonalSecundaria != referencia)) {
        return false;
    }

    return true;
}
