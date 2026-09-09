#include <iostream>
#define TAM 1000

using namespace std;

void celdasMaxRecorridas(int [][TAM], int, int);

int main(){
    int n, tiempo;
    static int matriz[TAM][TAM];
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    cin >> tiempo;

    celdasMaxRecorridas(matriz, tiempo, n);

    return 0;
}

void celdasMaxRecorridas(int matriz[][TAM], int tiempo, int n){
    int mejorFila = 1;
    int mayorCant = 0;

    for(int i = 0; i < n; i++){
        int izq = 0;
        long long suma = 0;
        int maxFila = 0;

        for(int der = 0; der < n; der++){
            suma += matriz[i][der];
            while(suma > tiempo and izq <= der){
                suma -= matriz[i][izq];
                izq++;
            }
            // Si el elemento individual supera a tiempo, izq = der+1 y suma = 0 -> longitud 0
            int len = der - izq + 1;
            if (len < 0) len = 0;
            if(len > maxFila){
                maxFila = len;
                // Optimizacion: si ya llega a N no puede mejorar
                if(maxFila == n) break;
            }
        }

        if(maxFila > mayorCant){
            mayorCant = maxFila;
            mejorFila = i + 1;
        }
    }

    cout << "Fila Numero: " << mejorFila << " - Cantidad maxima: " << mayorCant;
}