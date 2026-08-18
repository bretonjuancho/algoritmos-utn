#include <iostream>
#define TAM 1000
using namespace std;

int DigitosPares(int);
int DigitosImpares(int);
int fibonacci(int);
int filtroNacci(int);

int main() {
	
    int numerosFiltroNacci[20] = {};

    for(int i=0; i<20; i++){
        numerosFiltroNacci[i] = filtroNacci(i+1);
    }

    int n;
    cin >> n;
    cout << "T = " << numerosFiltroNacci[n-1] << endl;

	return 0;
}

int filtroNacci(int n){
    int contador = 0, sucesion = 0;

    while(sucesion < n){
        contador++;
        int aux = fibonacci(contador);
        if(aux < 10 or (DigitosImpares(aux) > DigitosPares(aux))){
            sucesion++;
        }
    }

    return fibonacci(contador);
}

int DigitosPares(int n){
    if(n < 10){
        return (n%2 == 0);
    }
    else{
        return (n%2 == 0) + DigitosPares(n/10);
    }
}

int DigitosImpares(int n){
    if(n < 10){
        return !(n%2 == 0);
    }
    else{
        return !(n%2 == 0) + DigitosImpares(n/10);
    }
}

int fibonacci(int n){
    if(n == 1 or n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}