#include <iostream>
#define TAM 10000

using namespace std;

bool encontrarCodigo(int [], int [], int);

int main(){

    int vec[TAM], tl, t, digitosCodigo[4];

    cin >> t >> tl;

    for(int i=0; i<tl; i++) cin >> vec[i];

    int k = 3;
    while(t > 0){
        digitosCodigo[k] = t%10;
        t/=10;
        k--;
    }

    while(k > 0){
        digitosCodigo[k] = 0;
        k--;
    }

    if(encontrarCodigo(vec, digitosCodigo, tl)) cout << "SI" << endl;
    else cout << "NO" << endl;

    return 0;
}

bool encontrarCodigo(int vec[], int digitos[], int tl){

    for(int i=0; i<tl-3; i++){
        bool encontrado = true; 
        for(int j=0; j<4 and encontrado; j++){
            if(vec[i+j] != digitos[j]) encontrado = false;
        }
        if(encontrado) return true;
    }
    return false;

}