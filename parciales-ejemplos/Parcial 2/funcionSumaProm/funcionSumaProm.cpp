#include <iostream>
#include <iomanip>

using namespace std;

// codifique completamente la funcionA aquí 
int funcionA(int x, int y, double & prom){ 
    int sum = 0, contadorMult5 = 0;
    
    while(x <= y){
        if(x%2 == 0 and x%3 == 0) sum+=x;

        if(x%5 == 0){
            prom += x;
            contadorMult5++;
        }

        x++;
    }

    if(contadorMult5) prom/=contadorMult5;

    return sum;
}

int main(){

    // declare las variables necesarias aquí...
    int x, y;
    double prom = 0;

    // codifique el ingreso de datos del problema aquí...
    cin >> x >> y;
    while(y < x*3) cin >> y;

    // llamada a la función y visualización de resultados aquí...
    cout << funcionA(x, y, prom) << endl;
    cout << fixed << setprecision(2) << prom << endl;

    return 0;
}