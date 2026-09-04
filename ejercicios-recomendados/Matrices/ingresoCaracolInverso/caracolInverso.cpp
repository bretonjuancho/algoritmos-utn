#include <iostream>
#define TAM 100
using namespace std;

void ponerValores(int [][TAM], int);
void mostrarMatriz(int [][TAM], int);

int main() {
    int matriz[TAM][TAM];

    int N;

    cout << "Ingrese el tamaño de la matriz (NxN): ";
    cin >> N;

    ponerValores(matriz, N);

    mostrarMatriz(matriz, N);
    return 0;
}

void ponerValores(int matriz[][TAM], int N){
    int sup = 0, inf = N - 1;
    int izq = 0, der = N - 1;
    int n = N * N;

    while (sup <= inf && izq <= der) {
        for (int j = izq; j <= der; j++){
            matriz[sup][j] = n--;
        }
        sup++;

        for (int i = sup; i <= inf; i++){
            matriz[i][der] = n--;
        }
        der--;

        if (sup <= inf) {
            for (int j = der; j >= izq; j--){
                matriz[inf][j] = n--;
            }
            inf--;
        }

        if (izq <= der) {
            for (int i = inf; i >= sup; i--){
                matriz[i][izq] = n--;
            }
            izq++;
        }
    }
}

void mostrarMatriz(int matriz[][TAM], int N){
    cout << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
