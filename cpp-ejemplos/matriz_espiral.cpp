#include <iostream>
using namespace std;

const int FILAS = 4;
const int COLUMNAS = 4;

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    int sup = 0, inf = FILAS - 1;
    int izq = 0, der = COLUMNAS - 1;

    cout << "Recorrido en espiral: " << endl;

    while (sup <= inf && izq <= der) { 
        for (int j = izq; j <= der; j++)
            cout << matriz[sup][j] << " ";
        sup++;

        for (int i = sup; i <= inf; i++)
            cout << matriz[i][der] << " ";
        der--;

        if (sup <= inf) {
            for (int j = der; j >= izq; j--)
                cout << matriz[inf][j] << " ";
            inf--;
        }

        if (izq <= der) {
            for (int i = inf; i >= sup; i--)
                cout << matriz[i][izq] << " ";
            izq++;
        }
    }

    cout << endl;
    return 0;
}
