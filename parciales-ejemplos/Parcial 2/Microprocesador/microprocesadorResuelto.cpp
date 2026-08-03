#include <iostream>
#define TAM 25

using namespace std;

float promedioProcesamiento(float [], float, int);
void procesadorDanado(float []);

int main(){

    float tiempos[TAM] = {};

    for(int i = 0; i<TAM; i++) cin >> tiempos[i];

    //cout << "Promedio de microprocesador: " << promedioProcesamiento(tiempos, 0, 0) << endl;

    procesadorDanado(tiempos);

    return 0;
}

float promedioProcesamiento(float tiempos[], float acumulador, int i){
    
    if(i == TAM){
        return acumulador / (float) TAM;
    }
    else{
        return promedioProcesamiento(tiempos, acumulador + tiempos[i], i+1);
    }
}

/*
float acumulador = 0;
    for(int i = 0; i < TAM; i++){
        acumulador += tiempos[i];
    }
    return acumulador / (float) TAM;
    */

void procesadorDanado(float tiempos[]){
    int contador = 1;
    float elementoActual = tiempos[7]; 
    
    for(int i=8; i<21; i++){
        if(elementoActual == tiempos[i]) contador++;
        else{
            elementoActual = tiempos[i];
            contador = 1;
        }
        if(contador == 7){
            cout << "Existe una secuencia sospechosa" << endl;
            return;
        }
    }

    cout << "No existe ninguna secuencia sospechosa" << endl;
}