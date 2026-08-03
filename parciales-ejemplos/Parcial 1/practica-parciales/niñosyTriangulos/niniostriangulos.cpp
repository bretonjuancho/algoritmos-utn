#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    char ninio;
    int cantNinios = 0, cantTotalTriangulos = 0;
    float mayorAreaTotal = -1, mayorPerimetroTotal = -1, areaTotal = 0, ladoIndividualMasLargo = -1;

    while(cin >> ninio){
        cantNinios++;

        int cantTriangulos, trianguloConMayorArea = -1;
        float mayorArea = -1;

        cin >> cantTriangulos;
        cantTotalTriangulos += cantTriangulos; 

        for(int i=0; i<cantTriangulos; i++){
            int x1, x2, x3, y1, y2, y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            
            float area, a, b, c, p, perimetro;

            a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            b = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
            c = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));

            if(max(a,(max(b,c))) > ladoIndividualMasLargo){
                ladoIndividualMasLargo = max(a,(max(b,c)));
            }

            p = (a+b+c)/2.0;

            area = sqrt(p*(p-a)*(p-b)*(p-c));

            areaTotal += area;

            if(area > mayorArea){
                mayorArea = area;
                trianguloConMayorArea = i+1;
            }

            perimetro = a + b + c;
            if(perimetro > mayorPerimetroTotal) mayorPerimetroTotal = perimetro;
        }

        if(mayorArea > mayorAreaTotal) mayorAreaTotal = mayorArea;

        cout << "Triángulo de mayor área es el nro.: " << trianguloConMayorArea << endl;
    }

    cout << endl << "Cantidad de niños participantes: " << cantNinios << endl;
    cout << "Área del triángulo con mayor área: " << fixed << setprecision(2) << mayorAreaTotal << " cm2" << endl;
    cout << "Perímetro del triángulo de mayor perímetro: " << fixed << setprecision(2) << mayorPerimetroTotal << " cm" << endl;
    cout << "Área promedio de los triángulos: " << fixed << setprecision(2) << areaTotal / (float)cantTotalTriangulos << " cm2" << endl;
    cout << "Lado individual más largo: " << fixed << setprecision(2) << ladoIndividualMasLargo << " cm" << endl;

    return 0;
}