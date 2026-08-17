#include <iostream>
#define TAM 500

using namespace std;

void ejercicio(int [], int, int);

int main(){

    int tl, arreglo[TAM], k;

    cin >> tl;

    for(int i=0; i<tl; i++) cin >> arreglo[i];

    cin >> k;

    ejercicio(arreglo, tl, k);

    return 0;
}

void ejercicio(int a[], int tl, int k){

    for(int i = tl-1; i >= k-1; i--){
        if( (a[i]%2) != 0 and (a[i-k+1]%2) == 0){
            for(int j = i-k+1; j < i+1; j++) cout << a[j];
            cout << endl << "POSICION INICIAL: " << i-k+1 << endl;
            return;
        }
    }

    cout << "NO EXISTE" << endl;

}