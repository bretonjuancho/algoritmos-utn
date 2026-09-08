#include <iostream>
#include <iomanip>
#define TAM 50

using namespace std;

struct Jugador{
    string nombre;
    int edad;
    int goles;
    int partidos;
};

void ingresoDatos(int &, Jugador []);
float promedioGol(Jugador);
void promedioPorJugador(Jugador [], int);
void goleadorYMejorPromedio(Jugador [], int);
void menoresDe20(Jugador [], int);
void masDe10Goles(Jugador [], int);

int main(){

    int n;
    Jugador jugadores[TAM] = {};

    ingresoDatos(n, jugadores);

    cout << fixed << setprecision(2);

    promedioPorJugador(jugadores, n);
    goleadorYMejorPromedio(jugadores, n);
    menoresDe20(jugadores, n);
    masDe10Goles(jugadores, n);

    return 0;
}

void ingresoDatos(int &n, Jugador jugadores[]){
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << endl << "Jugador N°" << i+1 << endl;
        cout << "Nombre: "; cin >> jugadores[i].nombre;
        cout << "Edad: "; cin >> jugadores[i].edad;
        cout << "Goles: "; cin >> jugadores[i].goles;
        cout << "Partidos: "; cin >> jugadores[i].partidos;
    }
}

float promedioGol(Jugador j){
    if(j.partidos == 0) return 0;
    return (float) j.goles / (float) j.partidos;
}

void promedioPorJugador(Jugador jugadores[], int n){
    cout << endl;
    for(int i=0; i<n; i++){
        cout << jugadores[i].nombre << " -- Promedio de gol: " << promedioGol(jugadores[i]) << endl;
    }
}

void goleadorYMejorPromedio(Jugador jugadores[], int n){
    int goleador = 0;
    int mejor = -1;

    for(int i=0; i<n; i++){
        if(jugadores[i].goles > jugadores[goleador].goles){
            goleador = i;
        }
        if(jugadores[i].partidos > 0){
            if(mejor == -1 || promedioGol(jugadores[i]) > promedioGol(jugadores[mejor])){
                mejor = i;
            }
        }
    }

    cout << endl << "Goleador: " << jugadores[goleador].nombre << " (" << jugadores[goleador].goles << " goles)" << endl;

    if(mejor == -1){
        cout << "Mejor promedio: Sin partidos jugados" << endl;
    }
    else{
        cout << "Mejor promedio: " << jugadores[mejor].nombre << " (" << promedioGol(jugadores[mejor]) << ")" << endl;
    }
}

void menoresDe20(Jugador jugadores[], int n){
    cout << endl << "Jugadores menores de 20 años:" << endl;

    bool hay = false;
    for(int i=0; i<n; i++){
        if(jugadores[i].edad < 20){
            cout << jugadores[i].nombre << " (" << jugadores[i].edad << " años)" << endl;
            hay = true;
        }
    }

    if(!hay){
        cout << "Ninguno" << endl;
    }
}

void masDe10Goles(Jugador jugadores[], int n){
    int cantidad = 0;

    for(int i=0; i<n; i++){
        if(jugadores[i].goles > 10){
            cantidad++;
        }
    }

    float porcentaje = 0;
    if(n > 0){
        porcentaje = (float) cantidad / (float) n * 100;
    }

    cout << endl << "Jugadores con mas de 10 goles: " << cantidad << " (" << porcentaje << "% del plantel)" << endl;
    cout << endl;
}
