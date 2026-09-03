#include <iostream>
#define TAM 100

using namespace std;

bool esDiagonal(int [][TAM], int);

int main() {
    int matriz[TAM][TAM];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    if (esDiagonal(matriz, n)) {
        cout << "Es diagonal" << endl;
    } else {
        cout << "No es diagonal" << endl;
    }

    return 0;
}

bool esDiagonal(int matriz[][TAM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matriz[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
