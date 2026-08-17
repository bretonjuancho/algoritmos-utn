#include <iostream>
#define TAM 750

using namespace std;

void mostrarArreglo(int [], int);
void intercambio(int &, int &);
void ordenar(int [], int);

// A) 
void borrado(int [], int &);
//B)
bool menor(int, int);
//C)
bool aprobado(int [], int, int, int);
//D)
void topisimo(int [], int, float []);

int main(){

    int n, notas[TAM] = {};
    cin >> n;

    for(int i=0; i<n; i++) cin >> notas[i];

    cout << "Arreglo original: ";
    mostrarArreglo(notas, n);

    borrado(notas, n);

    cout << endl << "Arreglo con las notas no válidas borradas: ";
    mostrarArreglo(notas, n);

    cout << endl << "Arreglo ordenado según los criterios: ";
    ordenar(notas, n);
    mostrarArreglo(notas, n);

    int comision, id;
    cout << endl << "Ingrese la comisión y el ID de un alumno para ver si aprobó la materia" << endl;
    //Para el caso de prueba del parcial se recomienda ingresar Comision = 1, ID = 8
    //Si hacen un caso de prueba propio si pongan el valor que quieran
    cout << "Comisión: "; cin >> comision;
    cout << "ID: "; cin >> id;

    if(aprobado(notas, n, comision, id)) cout << "El alumno aprobó la materia." << endl;
    else cout << "El alumno no aprobó la materia." << endl;


    float promedioMayor[5];
    topisimo(notas, n, promedioMayor);
    cout << "Los mejores promedios para cada comisión son: " << endl;
    cout << "COM 1: " << promedioMayor[0] << endl;
    cout << "COM 2: " << promedioMayor[1] << endl;
    cout << "COM 3: " << promedioMayor[2] << endl;
    cout << "COM 4: " << promedioMayor[3] << endl;
    cout << "COM 5: " << promedioMayor[4] << endl;

    cout << endl << "Las comisiones que tienen '-1' no tienen alumnos." << endl;

    return 0;
}

void mostrarArreglo(int vec[], int tl){
    cout << "[";
    for(int i=0; i<tl; i++) cout << " " << vec[i] << " ";
    cout << "]" << endl;
}

// EJERCICIO A)
void borrado(int vec[], int &tl){   
    for(int i=tl-1; i>=0; i--){
        if(vec[i] == -1){
            for(int j = i; j < tl-1; j++) vec[j] = vec[j+1];
            tl--;
        }
    }
}

//EJERCICIO B)
bool menor(int a, int b){
    return a < b;
}

//EJERCICIO C)
bool aprobado(int notas[], int tl, int comision, int id){
    //Esta función supone que el alumno rindió 3 parciales
    //No contempla casos de alumnos donde rindió menos de 3
    
    for(int i = 0; i<tl; i++){
        int comActual = notas[i] / 1000000;
        int idActual = (notas[i] / 10000) % 100;
       
        if(comision == comActual and id == idActual){
            float promedio = notas[i]%1000 + notas[i+1]%1000 + notas[i+2]%1000;
            promedio /= 3.0;

            if(promedio >= 60) return true;
        }
    }

    return false;
}

//EJERCICIO D)
void topisimo(int notas[], int tl, float promediomayor[]) {
    for (int k = 0; k < 5; k++) promediomayor[k] = -1;

    for (int i = 0; i < tl; i++) {
        int comision = notas[i] / 1000000;

        if (comision >= 1 && comision <= 5) {
            int totalnotas = notas[i] % 1000;
            int cantparciales = 1;
            int IDalumno = (notas[i] / 10000) % 100; 

            while (i + 1 < tl && IDalumno == ((notas[i+1] / 10000) % 100)) {
                totalnotas += notas[i+1] % 1000;
                cantparciales++;
                i++;
            }
            
            float promedio = (float) totalnotas / (float) cantparciales;
            if (promedio > promediomayor[comision-1]) {
                promediomayor[comision-1] = promedio;
            }
        }
    }
}

//FUNCIÓN QUE SIMPLIFICA EL CÓDIGO DE ORDENAR
void intercambio(int &a, int &b){
    int aux = b;
    b = a;
    a = aux;
}

//AYUDA CON EL DESARROLLO GENERAL DEL PARCIAL
void ordenar(int vec[], int tl){
    for(int i=0; i<tl; i++){
        for(int j=0; j < tl-i-1; j++){
            if(menor(vec[j+1], vec[j])){
                intercambio(vec[j+1], vec[j]);
            }
        }
    }
}