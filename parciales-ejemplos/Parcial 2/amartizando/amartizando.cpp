#include <iostream>
#include <iomanip>
#define TAM 1000

using namespace std;

void leerDatosTerna(int [3][TAM], int &);
int movimientos(int, int, int);

int main(){

    /* Lo resuelvo usando matrices. Si estás en algoritmos 2026 y matrices
    no entra en el segundo parcial, se resuelve igual pero haciendo 3 arreglos,
    uno para cada dato (altura[TAM], posicion[TAM], direccion[TAM])
    */
    int datos[3][TAM] = {}, tl;

    leerDatosTerna(datos, tl);

    return 0;
}

void leerDatosTerna(int datos [3][TAM], int &tl){
    tl = 0;
    int altura, posicion, pfX = 0, pfY = 0;
    char direccion;

    while(cin >> altura >> posicion >> direccion){
        datos[0][tl] = altura;
        datos[1][tl] = posicion;
        datos[2][tl] = direccion;
        tl++;

        switch (direccion)
        {
        case 'N': pfY += posicion; break;
        case 'S': pfY -= posicion; break;
        case 'O': pfX -= posicion; break;
        case 'E': pfX += posicion; break;
        }

        if(altura == 0) break;
    }

    float velocidadPromedio;

    velocidadPromedio = (float) datos[0][0] / (float) tl;

    cout << "Velocidad promedio: " << fixed << setprecision(2) << velocidadPromedio << "m/s" << endl;
    cout << "Posición Final: " << pfX << ", " << pfY << endl;

    //cout << "Movimientos(5, 5): " << movimientos(5, 5, 0) << endl;
    //cout << "Movimientos(4, 2): " << movimientos(4, 2, 0) << endl;
}

int movimientos(int x, int y, int resultado){
    if(x == 0 and y == 0) return resultado;
    
    if(x > 0 and y > 0) return movimientos(x-1, y-1, resultado+1);
    
    if(x > 0) return movimientos(x-1, y, resultado+1);

    if(y > 0) return movimientos(x, y-1, resultado+1);
}