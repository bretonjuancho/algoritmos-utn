#include <iostream>
#include <iomanip>
#define TAM 50

using namespace std;

struct Materia{
    string nombre;
    float nota; 
};

struct Estudiante{
    int legajo;
    string nombre;
    string apellido;
    Materia cursando[3];
};

void ingresoDatos(int &, Estudiante []);
void promedioPorEstudiante(Estudiante [], int);

int main(){

    int n;
    Estudiante estudiantes[TAM];
    
    ingresoDatos(n, estudiantes);
    promedioPorEstudiante(estudiantes, n);

    return 0;
}

void ingresoDatos(int &n, Estudiante estudiantes[]){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> estudiantes[i].legajo; 
        cin >> estudiantes[i].nombre;
        cin >> estudiantes[i].apellido;

        for(int j=0; j<3; j++){
            cin >> estudiantes[i].cursando[j].nombre;
            cin >> estudiantes[i].cursando[j].nota;
        }
    }
}

void promedioPorEstudiante(Estudiante estudiantes[], int n){
    float mejorPromedio = -1; string mejorEstudiante;

    for(int i=0; i<n; i++){
        float promedio = 0;
        for(int j=0; j<3; j++){
            promedio += estudiantes[i].cursando[j].nota;
        }
        cout << estudiantes[i].nombre << " " << estudiantes[i].apellido << " -- Promedio: ";
        cout << fixed << setprecision(2) << promedio / 3.00 << endl;

        if(promedio / 3.00 > mejorPromedio){
            mejorPromedio = promedio / 3.00;
            mejorEstudiante = estudiantes[i].nombre + " " + estudiantes[i].apellido; 
        }
    }

    cout << endl << "El mejor estudiante es " << mejorEstudiante << " con el promedio de " << mejorPromedio << endl; 

}