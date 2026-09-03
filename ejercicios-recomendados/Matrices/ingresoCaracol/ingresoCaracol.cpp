#include <iostream>
#define TAM 100
using namespace std;

void ponerValores(int [][TAM], int, int);
void mostrarMatriz(int [][TAM], int, int);

int main() {
    int matriz[TAM][TAM];

    int FILAS, COLUMNAS;

    cout << "Ingrese las filas: ";
    cin >> FILAS;
    cout << "Ingrese las columnas: ";
    cin >> COLUMNAS;

    ponerValores(matriz, FILAS, COLUMNAS);

    mostrarMatriz(matriz, FILAS, COLUMNAS);
    return 0;
}

void ponerValores(int matriz[][TAM], int FILAS, int COLUMNAS){
    int sup = 0, inf = FILAS - 1;
    int izq = 0, der = COLUMNAS - 1;
    int n = 1;

    while (sup <= inf && izq <= der) { 
        for (int j = izq; j <= der; j++){
            matriz[sup][j] = n++;
        }
        sup++;

        for (int i = sup; i <= inf; i++){
            matriz[i][der] = n++;
        }
        der--;

        if (sup <= inf) {
            for (int j = der; j >= izq; j--){
                matriz[inf][j] = n++;
            }
            inf--;
        }

        if (izq <= der) {
            for (int i = inf; i >= sup; i--){
                matriz[i][izq] = n++;
            }
            izq++;
        }
    }
}

void mostrarMatriz(int matriz[][TAM], int F, int C){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}