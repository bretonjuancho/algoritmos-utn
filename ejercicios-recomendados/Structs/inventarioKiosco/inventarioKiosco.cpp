#include <iostream>
#include <iomanip>
#define TAM 100

using namespace std;

struct Producto{
    int codigo;
    string nombre;
    float precio;
    int stock;
};

void ingresoDatos(int &, Producto []);
void valorPorProducto(Producto [], int);
void productoMasCaroYBarato(Producto [], int);
void productosAReponer(Producto [], int);
void ordenarPorPrecio(Producto [], int);
void mostrarOrdenadosPorPrecio(Producto [], int);

int main(){

    int n;
    Producto productos[TAM] = {};

    ingresoDatos(n, productos);

    cout << fixed << setprecision(2);

    valorPorProducto(productos, n);
    productoMasCaroYBarato(productos, n);
    productosAReponer(productos, n);

    ordenarPorPrecio(productos, n);
    mostrarOrdenadosPorPrecio(productos, n);

    return 0;
}

void ingresoDatos(int &n, Producto productos[]){
    cout << "Ingrese la cantidad de productos: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << endl << "Producto N°" << i+1 << endl;
        cout << "Codigo: "; cin >> productos[i].codigo;
        cout << "Nombre: "; cin >> productos[i].nombre;
        cout << "Precio: "; cin >> productos[i].precio;
        cout << "Stock: "; cin >> productos[i].stock;
    }
}

void valorPorProducto(Producto productos[], int n){
    float total = 0;

    cout << endl;
    for(int i=0; i<n; i++){
        float valor = productos[i].precio * productos[i].stock;
        total += valor;
        cout << productos[i].nombre << " -- Valor en stock: " << valor << endl;
    }

    cout << "Valor total del inventario: " << total << endl;
}

void productoMasCaroYBarato(Producto productos[], int n){
    int caro = 0, barato = 0;

    for(int i=1; i<n; i++){
        if(productos[i].precio > productos[caro].precio){
            caro = i;
        }
        if(productos[i].precio < productos[barato].precio){
            barato = i;
        }
    }

    cout << endl << "Producto mas caro: " << productos[caro].nombre << " (" << productos[caro].precio << ")" << endl;
    cout << "Producto mas barato: " << productos[barato].nombre << " (" << productos[barato].precio << ")" << endl;
}

void productosAReponer(Producto productos[], int n){
    cout << endl << "Productos con stock menor a 5 (a reponer):" << endl;

    bool hay = false;
    for(int i=0; i<n; i++){
        if(productos[i].stock < 5){
            cout << productos[i].nombre << " (" << productos[i].stock << " unidades)" << endl;
            hay = true;
        }
    }

    if(!hay){
        cout << "Ninguno" << endl;
    }
}

void ordenarPorPrecio(Producto productos[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(productos[j].precio > productos[j+1].precio){
                Producto aux = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = aux;
            }
        }
    }
}

void mostrarOrdenadosPorPrecio(Producto productos[], int n){
    cout << endl << "Productos ordenados por precio (de menor a mayor):" << endl;
    for(int i=0; i<n; i++){
        cout << productos[i].nombre << " - " << productos[i].precio << endl;
    }

    cout << endl;
}
