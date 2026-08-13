#include <iostream>
#define TAM 500

using namespace std;

void ejercicio(int, int, int []);

int main(){

    int n, k, vec[TAM] = {};

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }

    cin >> k;

    ejercicio(n, k, vec);

    return 0;
}

void ejercicio(int n, int k, int vec[]){

    if(k < 3){
        cout << "NO EXISTE" << endl;
        return;
    }

    for(int i = 0; i <= n-k; i++){
        if((vec[i] % 2 == 0) && (vec[i+1] % 2 == 1) && (vec[i+2] % 2 == 0)){
            for(int j = i; j <= i+k-1; j++){
                cout << vec[j];
            }
            cout << endl << "POSICION INICIAL: " << i << endl;
            return;
        }
    }

    cout << "NO EXISTE" << endl;
}