#include <iostream> 
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

int main(){

    Empleado empleados[TAM] = {};
    int n;

    return 0;
}

void ingresoDatos(Empleado empleados[], int & n){
    cout << "Ingrese la cantidad de empleados: "; cin >> n;

    for(int i=0; i<n; i++){
        cout << "Empleado N°" << i+1 << endl;
        
        cout << endl << "Ingrese el nombre: "; 
        cin >> ws; 
        getline(cin, empleados[i].nombre);

        cout << endl << "Ingrese la dirección: ";
        

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

    cout << "Cuarto empleado: " << empleados[3].nombre << endl;
    cout << "Dirección: " << empleados[3].direccion.calle << " " << empleados[3].direccion.numero << endl;
    cout << "Sueldo: " << empleados[3].sueldo << endl;
    cout << "Categoría: " << empleados[3].categoria << endl; 
}