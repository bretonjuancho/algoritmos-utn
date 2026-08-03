#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if(x3 == x1 and y3 == y2 and x4 == x2 and y4 == y1 and abs(x2-x1) == abs(y3-y1)){
        int diametro = abs(x2-x1);
        double radio = (double)diametro / 2.0, area = 3.1415*radio*radio;

        cout << "Es un cuadrado cuyo circulo inscripto tiene area= " << fixed << setprecision(3) << area << endl;
    }
    
    else{
        if(x3 >= x1 and x3 <= x2 and x4 >= x1 and x4 <= x2 and y3 >= y1 and y3 <= y2 and y4 >= y1 and y4 <= y2){
            cout << "Todos los puntos se encuentran dentro del rectangulo" << endl;
        }
        else{
            if( (x3 >= x1 and x3 <= x2 and y3 >= y1 and y3 <= y2) or (x4 >= x1 and x4 <= x2 and y4 >= y1 and y4 <= y2)){
                cout << "Hay un unico punto fuera del rectangulo" << endl;
            }
        }

        int distanciaP1aP3, distanciaP1aP4;
        distanciaP1aP3 = abs(x3-x1) + abs(y3-y1);
        distanciaP1aP4 = abs(x4-x1) + abs(y4-y1);

        if(distanciaP1aP3 < distanciaP1aP4){
            cout << "El punto mas cercano a P1 es P3 a " << distanciaP1aP3 << " saltos" << endl;
        }
        else{
            cout << "El punto mas cercano a P1 es P4 a " << distanciaP1aP4 << " saltos" << endl;
        }
    }
    
    return 0;
}