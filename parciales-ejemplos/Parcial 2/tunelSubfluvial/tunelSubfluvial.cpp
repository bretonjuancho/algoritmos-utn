#include <iostream>
#define TAM 30

using namespace std;

void gananciaEnSemana(int [], float[]);
void diasMas13(int [], int);

int main(){

    int junio[30] = {};
    float gananciaSemanal[5] = {};

    for(int i=0; i<30; i++) cin >> junio[i];

    gananciaEnSemana(junio, gananciaSemanal);

    for(int i=0; i<5; i++){
        cout << "Ganancia en la semana " << i+1 << ": " << gananciaSemanal[i] << endl;
    }

    cout << "Dias que tuvieron una cola con mas de 13 vehiculos: ";
    diasMas13(junio, 0);

    return 0;
}

void gananciaEnSemana(int junio[], float gananciaSemanal[]){
    int semana = 0;

    for(int i=0; i<TAM; i++){
        gananciaSemanal[semana] += (float) (junio[i] * (178*0.83)); 
        
        if((i%7) == 6) semana++;
    }
}

void diasMas13(int junio[], int index){
    if(index == (TAM-1)){
        if(junio[index] > 13) cout << index+1 << " ";
    }
    else{
        if(junio[index] > 13) cout << index+1 << " ";
        diasMas13(junio, index+1); 
    } 
}

/* EJERCICIO C)

El código busca determinar si la suma de los elementos del arreglo
registro[] en algun momento supera las 100 unidades. Si supera
las 100 entonces a = !a, que sería a = !false = true, lo que haría 
cortar el bucle. Por otro lado, corta si i llega a 30 si no sucede 
que se llegue a los 100 elementos antes. 
*/