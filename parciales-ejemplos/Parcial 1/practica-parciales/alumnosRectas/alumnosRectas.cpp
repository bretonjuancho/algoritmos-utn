#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int x1, x2, x3, x4, y1, y2, y3, y4, cantAlumnos = 0, cantSinRectasPositivas = 0, cantTotalRectasPositivas = 0;

    float mayorPendientePositiva = 0;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 and x1 != EOF){
        cantAlumnos++;

        int cantMPos = 0;

        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }

        if(x3 > x4){
            swap(x3, x4);
            swap(y3, y4);
        }

        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;  

        float m1, m2;

        m1 = (float)(y2-y1)/(float)(x2-x1);
        m2 = (float)(y3-y4)/(float)(x3-x4);

        if(m1 > 0) cantMPos++;
        if(m2 > 0) cantMPos++;
        if(m1 <= 0 and m2 <= 0) cantSinRectasPositivas++;
        cantTotalRectasPositivas += cantMPos;

        cout << cantMPos << endl;

        if(m1 > mayorPendientePositiva) mayorPendientePositiva = m1;
        if(m2 > mayorPendientePositiva) mayorPendientePositiva = m2; 

    }

    cout << endl;
    cout << "Cantidad de alumnos participantes: " << cantAlumnos << endl;
    cout << "Alumnos sin rectas con pendiente positiva: " << cantSinRectasPositivas << endl;
    cout << "Cantidad total de rectas con pendiente positiva: " << cantTotalRectasPositivas << endl;
    cout << "Mayor pendiente positiva de una recta: " << fixed << setprecision(1) << mayorPendientePositiva << endl;

    return 0;
}