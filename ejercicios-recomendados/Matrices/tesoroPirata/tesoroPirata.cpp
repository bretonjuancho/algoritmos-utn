#include <iostream>
#define TAM 200

using namespace std;

int cantidadEnergiaNecesaria(int [][TAM], int, int, int, int, int);

int main(){

    int n, m;
    int mapa[TAM][TAM];

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mapa[i][j];
        }
    }

    return 0;
}


int cantidadEnergiaNecesaria(int mapa[][TAM], int n, int xAnt, int yAnt, int x, int y){

    // CASO BASE
    if(x == n-1 and y == n-1){
        return 0;
    }


}