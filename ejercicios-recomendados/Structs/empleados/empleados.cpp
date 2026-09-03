#include <iostream> 
#include <ctime>
#define TAM 100

using namespace std;

struct Fecha{
    unsigned dia, mes, anio;
};

struct Direccion{
    string calle, barrio;
    int numero;
};

struct Empleado{
    string nombre, categoria;
    Direccion direccion;
    float sueldo; 
    Fecha fecha_nacimiento, fecha_ingreso;
    char sexo; 
};

void ingresoDatos(Empleado [], int &);
void cuartoEmpleado(Empleado [], int);
void aumentarSueldoAntiguedad(Empleado [], int);
void sueldoMayorA_57500(Empleado [], int);
void empleadosMenoresde25(Empleado [], int);
void empleadosPorBarrio(Empleado [], int, string);
void ordenarEmpleadosPorNombre(Empleado [], int);
void mostrarEmpleadosPorNombre(Empleado [], int);

int main(){

    Empleado empleados[TAM] = {};
    int n;

    ingresoDatos(empleados, n);

    cuartoEmpleado(empleados, n); // Ejercicio 1

    sueldoMayorA_57500(empleados, n); // Ejercicio 2

    aumentarSueldoAntiguedad(empleados, n); // Ejercicio 3

    empleadosMenoresde25(empleados, n); // Ejercicio 4

    empleadosPorBarrio(empleados, n, "Sur"); // Ejercicio 5

    empleadosPorBarrio(empleados, n, "Candioti"); // Ejercicio 6

    ordenarEmpleadosPorNombre(empleados, n);

    mostrarEmpleadosPorNombre(empleados, n);

    return 0;
}

void ingresoDatos(Empleado empleados[], int & n){
    cout << "Ingrese la cantidad de empleados: "; cin >> n;

    for(int i=0; i<n; i++){
        cout << "Empleado N°" << i+1 << endl;
        
        cout << endl << "Ingrese el nombre: "; 
        cin >> empleados[i].nombre;

        cout << endl << "Ingrese la dirección: ";
        cin >> empleados[i].direccion.calle;
        cin >> empleados[i].direccion.numero;
        cin >> empleados[i].direccion.barrio;

        cout << endl << "Fecha de nacimiento" << endl;
        cout << "Día: "; cin >> empleados[i].fecha_nacimiento.dia;
        cout << "Mes: "; cin >> empleados[i].fecha_nacimiento.mes;
        cout << "Año: "; cin >> empleados[i].fecha_nacimiento.anio;

        cout << endl << "Sexo (M = masculino, F = femenino, O = otro) (poner solo la letra): ";
        cin >> empleados[i].sexo;
        
        cout << endl << "Sueldo: "; cin >> empleados[i].sueldo;

        cout << endl << "Categoría: "; cin >> empleados[i].categoria;

        cout << endl << "Fecha de ingreso" << endl;
                cout << "Día: "; cin >> empleados[i].fecha_ingreso.dia;
        cout << "Mes: "; cin >> empleados[i].fecha_ingreso.mes;
        cout << "Año: "; cin >> empleados[i].fecha_ingreso.anio;
    }
}

void cuartoEmpleado(Empleado empleados[], int n){
    if(n < 4){
        cout << "Hay menos de 4 empleados en el sistema" << endl;
        return;
    }

    cout << endl << "Cuarto empleado: " << empleados[3].nombre << endl;
    cout << "Dirección: " << empleados[3].direccion.calle << " " << empleados[3].direccion.numero << endl;
    cout << "Sueldo: " << empleados[3].sueldo << endl;
    cout << "Categoría: " << empleados[3].categoria << endl; 
}

void sueldoMayorA_57500(Empleado empleados[], int n){
    cout << endl << "Empleados con sueldo mayor a $57.500: ";
    
    for(int i=0; i<n; i++){
        if(empleados[i].sueldo > 57500){
            cout << empleados[i].nombre << " ";
        }
    }
    cout << endl;
}

void aumentarSueldoAntiguedad(Empleado empleados[], int n){
    /* Esto calcula la antiguedad con el día de hoy, pero tranquilamente podrían tomar un año fijo cómo referencia
    (ej. 2026) y calcular a partir de ahí la antiguedad, ya que la función 'localtime()' de ctime no se ve en la materia. */

    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    int diaActual = ahora->tm_mday;
    int mesActual = ahora->tm_mon + 1;
    int anioActual = ahora->tm_year + 1900;

    cout << endl << "Sueldos actualizados por antigüedad mayor a 5 años:" << endl;
    for(int i=0; i<n; i++){
        int antiguedad = anioActual - (int)empleados[i].fecha_ingreso.anio;
        if(mesActual < (int)empleados[i].fecha_ingreso.mes ||
          (mesActual == (int)empleados[i].fecha_ingreso.mes && diaActual < (int)empleados[i].fecha_ingreso.dia)){
            antiguedad--;
        }
        if(antiguedad > 5){
            empleados[i].sueldo *= 1.15;
            cout << empleados[i].nombre << ": $" << empleados[i].sueldo << endl;
        }
    }
}

void empleadosMenoresde25(Empleado empleados[], int n){
    int anioActual = 2026;

    cout << endl << "Empleados menores de 25 años: "; 

    for(int i=0; i<n; i++){
        if(anioActual - empleados[i].fecha_nacimiento.anio < 25){
            cout << empleados[i].nombre << " ";
        }
    }
    cout << endl;
}

void empleadosPorBarrio(Empleado empleados[], int n, string barrio){
    cout << endl << "Empleados del barrio " << barrio << ": ";

    for(int i=0; i<n; i++){
        if(empleados[i].direccion.barrio == barrio) cout << empleados[i].nombre << " ";
    }

    cout << endl;
}

void ordenarEmpleadosPorNombre(Empleado empleados[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(empleados[j].nombre > empleados[j+1].nombre){
                Empleado aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
            }
        }
    }
}

void mostrarEmpleadosPorNombre(Empleado empleados[], int n){
    cout << endl << "Empleados por nombre: ";
    for(int i=0; i<n; i++){
        cout << empleados[i].nombre << " ";
    }

    cout << endl << endl;
}