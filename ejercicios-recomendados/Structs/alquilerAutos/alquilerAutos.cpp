#include <iostream>
#include <iomanip>
#define MAX_AUTOS 300
#define MAX_CLIENTES 200

using namespace std;

struct Auto {
    int codigo = 0;
    int categoria = 0;
    float precioPorKm = 0;
    int vecesAlquilado = 0;
    float recaudado = 0;
};

int buscarAuto(Auto [], int, int);
void cargarAutos(Auto [], int &);
void procesarAlquileres(Auto [], int, float [], int []);
void listarClientesTop(float [], int);
void mostrarAutosNoAlquilados(Auto [], int);
void mostrarClientesFrecuentes(int [], int);
void categoriaMasAlquilada(Auto [], int);
void autoMayorRecaudacion(Auto [], int);

int main() {
    Auto autos[MAX_AUTOS] = {};
    float totalPorCliente[MAX_CLIENTES + 1] = {};
    int alquileresPorCliente[MAX_CLIENTES + 1] = {};
    int n;

    cargarAutos(autos, n);
    procesarAlquileres(autos, n, totalPorCliente, alquileresPorCliente);

    cout << fixed << setprecision(2);

    listarClientesTop(totalPorCliente, MAX_CLIENTES); // Punto 1
    mostrarAutosNoAlquilados(autos, n);               // Punto 2
    mostrarClientesFrecuentes(alquileresPorCliente, MAX_CLIENTES); // Punto 3
    categoriaMasAlquilada(autos, n);                  // Punto 4
    autoMayorRecaudacion(autos, n);                   // Punto 5

    return 0;
}

int buscarAuto(Auto autos[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (autos[i].codigo == codigo) return i;
    }
    return -1;
}

void cargarAutos(Auto autos[], int &n) {
    cout << "Ingrese la cantidad de autos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Auto N°" << i + 1 << " (codigo categoria precioPorKm): ";
        cin >> autos[i].codigo >> autos[i].categoria >> autos[i].precioPorKm;
        autos[i].vecesAlquilado = 0;
        autos[i].recaudado = 0;
    }
}

void procesarAlquileres(Auto autos[], int n, float totalPorCliente[], int alquileresPorCliente[]) {
    int codigo, cliente, dias, km;

    cout << "Ingrese los alquileres (codigo cliente dias km). Finaliza con codigo = 0 o cliente = 0:" << endl;
    while (cin >> codigo) {
        if (codigo == 0) break;
        cin >> cliente;
        if (cliente == 0) break;
        cin >> dias >> km;

        int idx = buscarAuto(autos, n, codigo);
        if (idx == -1 || cliente < 1 || cliente > MAX_CLIENTES) continue;

        float importe = autos[idx].precioPorKm * km;
        totalPorCliente[cliente] += importe;
        alquileresPorCliente[cliente]++;
        autos[idx].vecesAlquilado++;
        autos[idx].recaudado += importe;
    }
}

void listarClientesTop(float totalPorCliente[], int maxClientes) {
    int orden[MAX_CLIENTES + 1];
    int cantidad = 0;

    for (int c = 1; c <= maxClientes; c++) {
        if (totalPorCliente[c] > 1500) {
            orden[cantidad++] = c;
        }
    }

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (totalPorCliente[orden[j]] < totalPorCliente[orden[j + 1]]) {
                int aux = orden[j];
                orden[j] = orden[j + 1];
                orden[j + 1] = aux;
            }
        }
    }

    cout << endl << "Nro. Cliente - Total de $ abonados en alquiler:" << endl;
    if (cantidad == 0) {
        cout << "Ningun cliente supero los $1500." << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        cout << orden[i] << " " << totalPorCliente[orden[i]] << endl;
    }
}

void mostrarAutosNoAlquilados(Auto autos[], int n) {
    cout << endl << "Autos no alquilados: ";
    bool hay = false;
    for (int i = 0; i < n; i++) {
        if (autos[i].vecesAlquilado == 0) {
            cout << autos[i].codigo << " ";
            hay = true;
        }
    }
    if (!hay) cout << "Ninguno";
    cout << endl;
}

void mostrarClientesFrecuentes(int alquileresPorCliente[], int maxClientes) {
    cout << endl << "Clientes con mas de 2 alquileres: ";
    bool hay = false;
    for (int c = 1; c <= maxClientes; c++) {
        if (alquileresPorCliente[c] > 2) {
            cout << c << " ";
            hay = true;
        }
    }
    if (!hay) cout << "Ninguno";
    cout << endl;
}

void categoriaMasAlquilada(Auto autos[], int n) {
    int porCategoria[8] = {};
    for (int i = 0; i < n; i++) {
        if (autos[i].categoria >= 1 && autos[i].categoria <= 7) {
            porCategoria[autos[i].categoria] += autos[i].vecesAlquilado;
        }
    }

    int mejor = 0, maximo = 0;
    for (int c = 1; c <= 7; c++) {
        if (porCategoria[c] > maximo) {
            maximo = porCategoria[c];
            mejor = c;
        }
    }

    cout << endl << "Categoria mas alquilada: ";
    if (mejor == 0) {
        cout << "Sin alquileres" << endl;
    } else {
        cout << mejor << " (" << maximo << " alquileres)" << endl;
    }
}

void autoMayorRecaudacion(Auto autos[], int n) {
    int mejor = -1;
    for (int i = 0; i < n; i++) {
        if (autos[i].vecesAlquilado > 0 && (mejor == -1 || autos[i].recaudado > autos[mejor].recaudado)) {
            mejor = i;
        }
    }

    cout << endl << "Auto con mayor recaudacion: ";
    if (mejor == -1) {
        cout << "Sin alquileres" << endl;
    } else {
        cout << autos[mejor].codigo << " ($" << autos[mejor].recaudado << ")" << endl;
    }
}
