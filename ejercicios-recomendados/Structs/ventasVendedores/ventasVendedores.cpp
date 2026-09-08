#include <iostream>
#include <iomanip>
#define TAM 50
#define SEMANAS 4

using namespace std;

struct Zona{
    int numero;
    string nombre;
};

struct Vendedor{
    int codigo;
    string nombre;
    Zona zona;
    float ventas[SEMANAS];
};

string nombreZona(int);
void ingresoDatos(int &, Vendedor []);
float totalVendedor(Vendedor);
void totalPorVendedor(Vendedor [], int);
void mejorVendedor(Vendedor [], int);
void zonaConMayorVenta(Vendedor [], int);
void vendedoresConSemanaSinVentas(Vendedor [], int);
void ordenarPorTotal(Vendedor [], int);
void mostrarRanking(Vendedor [], int);

int main(){

    int n;
    Vendedor vendedores[TAM] = {};

    ingresoDatos(n, vendedores);

    cout << fixed << setprecision(2);

    totalPorVendedor(vendedores, n);
    mejorVendedor(vendedores, n);
    zonaConMayorVenta(vendedores, n);
    vendedoresConSemanaSinVentas(vendedores, n);

    ordenarPorTotal(vendedores, n);
    mostrarRanking(vendedores, n);

    return 0;
}

void ingresoDatos(int &n, Vendedor vendedores[]){
    cout << "Ingrese la cantidad de vendedores: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << endl << "Vendedor N°" << i+1 << endl;
        cout << "Codigo: "; cin >> vendedores[i].codigo;
        cout << "Nombre: "; cin >> vendedores[i].nombre;
        cout << "Zona (1-Norte 2-Sur 3-Este 4-Oeste): "; cin >> vendedores[i].zona.numero;
        vendedores[i].zona.nombre = nombreZona(vendedores[i].zona.numero);
        for(int s=0; s<SEMANAS; s++){
            cout << "Venta semana " << s+1 << ": ";
            cin >> vendedores[i].ventas[s];
        }
    }
}

string nombreZona(int numero){
    if(numero == 1) return "Norte";
    if(numero == 2) return "Sur";
    if(numero == 3) return "Este";
    if(numero == 4) return "Oeste";
    return "Desconocida";
}

float totalVendedor(Vendedor v){
    float total = 0;
    for(int s=0; s<SEMANAS; s++){
        total += v.ventas[s];
    }
    return total;
}

void totalPorVendedor(Vendedor vendedores[], int n){
    float general = 0;

    cout << endl;
    for(int i=0; i<n; i++){
        float total = totalVendedor(vendedores[i]);
        general += total;
        cout << vendedores[i].nombre << " (Zona " << vendedores[i].zona.nombre << ") -- Total mensual: " << total << endl;
    }

    cout << "Total general de la empresa: " << general << endl;
}

void mejorVendedor(Vendedor vendedores[], int n){
    int mejor = 0;

    for(int i=1; i<n; i++){
        if(totalVendedor(vendedores[i]) > totalVendedor(vendedores[mejor])){
            mejor = i;
        }
    }

    cout << endl << "Mejor vendedor: " << vendedores[mejor].nombre << " - Zona " << vendedores[mejor].zona.nombre << " (" << totalVendedor(vendedores[mejor]) << ")" << endl;
}

void zonaConMayorVenta(Vendedor vendedores[], int n){
    float porZona[5] = {};

    for(int i=0; i<n; i++){
        if(vendedores[i].zona.numero >= 1 && vendedores[i].zona.numero <= 4){
            porZona[vendedores[i].zona.numero] += totalVendedor(vendedores[i]);
        }
    }

    int mejor = 1;
    for(int z=2; z<=4; z++){
        if(porZona[z] > porZona[mejor]){
            mejor = z;
        }
    }

    cout << endl << "Zona con mayor venta: " << mejor << " - " << nombreZona(mejor) << " (" << porZona[mejor] << ")" << endl;
}

void vendedoresConSemanaSinVentas(Vendedor vendedores[], int n){
    cout << endl << "Vendedores sin ventas en alguna semana:" << endl;

    bool hay = false;
    for(int i=0; i<n; i++){
        for(int s=0; s<SEMANAS; s++){
            if(vendedores[i].ventas[s] == 0){
                cout << vendedores[i].nombre << endl;
                hay = true;
                break;
            }
        }
    }

    if(!hay){
        cout << "Ninguno" << endl;
    }
}

void ordenarPorTotal(Vendedor vendedores[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(totalVendedor(vendedores[j]) < totalVendedor(vendedores[j+1])){
                Vendedor aux = vendedores[j];
                vendedores[j] = vendedores[j+1];
                vendedores[j+1] = aux;
            }
        }
    }
}

void mostrarRanking(Vendedor vendedores[], int n){
    cout << endl << "Ranking de vendedores (de mayor a menor):" << endl;
    for(int i=0; i<n; i++){
        cout << vendedores[i].nombre << " (Zona " << vendedores[i].zona.nombre << ") - " << totalVendedor(vendedores[i]) << endl;
    }

    cout << endl;
}
