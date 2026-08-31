#include <iostream> 
#define TAM 100

using namespace std;

struct Ciudadano{
    string nombre;
    int edad;
    char voto;
};

void votosPorPartido(int [][3], Ciudadano [], int);
void ingresoDatos(int &, Ciudadano []);

int main(){

    int vpp[2][3] = {}; // -> cada fila es un partido y cada columna es un rango de edad
    // Fila 0 -> rojo || Fila 1 -> azul
    // Columna 0 -> de 18 a 40 años || Columna 1 de 41 a 60 años || Columna 2 de 60 en adelante

    int n;
    Ciudadano votantes[TAM] = {};

    ingresoDatos(n, votantes);

    votosPorPartido(vpp, votantes, n);

    return 0;
}

void ingresoDatos(int & n, Ciudadano votantes[]){
    cout << "Ingrese la cantidad de votantes: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << endl << "Votante N°" << i+1 << endl;
        cout << "Nombre: "; cin >> votantes[i].nombre;
        cout << "Edad: "; cin >> votantes[i].edad;
        cout << "Voto: "; cin >> votantes[i].voto;
    }
}

void votosPorPartido(int votos[][3], Ciudadano votantes[], int n){
    for(int i=0; i<n; i++){
        if(votantes[i].voto == 'R'){ 
            if(votantes[i].edad >= 18 and votantes[i].edad <= 40){
                votos[0][0]++;
            }
            else{
                if(votantes[i].edad >= 41 and votantes[i].edad <= 60){
                    votos[0][1]++;
                }
                else votos[0][2]++;
            }
        }
        else{
            if(votantes[i].edad >= 18 and votantes[i].edad <= 40){
                votos[1][0]++;
            }
            else{
                if(votantes[i].edad >= 41 and votantes[i].edad <= 60){
                    votos[1][1]++;
                }
                else votos[1][2]++;
            }
        }
    }

    float rojos, azules;
    rojos = ((float) votos[0][0] / (float) (votos[0][0]+votos[1][0])) * 100.00; 
    azules = ((float) votos[1][0] / (float) (votos[0][0]+votos[1][0])) * 100.00; 

    cout << endl << "Entre 18 y 40 años: " << endl;
    cout << "Porcentaje rojos: " << rojos << "%" << endl;
    cout << "Porcentaje azules: " << azules << "%" << endl;

    rojos = ((float) votos[0][1] / (float) (votos[0][1]+votos[1][1])) * 100.00; 
    azules = ((float) votos[1][1] / (float) (votos[0][1]+votos[1][1])) * 100.00; 

    cout << endl << "Entre 41 y 60 años: " << endl;
    cout << "Porcentaje rojos: " << rojos << "%" << endl;
    cout << "Porcentaje azules: " << azules << "%" << endl;

    rojos = ((float) votos[0][2] / (float) (votos[0][2]+votos[1][2])) * 100.00; 
    azules = ((float) votos[1][2] / (float) (votos[0][2]+votos[1][2])) * 100.00; 

    cout << endl << "Más de 60 años: " << endl;
    cout << "Porcentaje rojos: " << rojos << "%" << endl;
    cout << "Porcentaje azules: " << azules << "%" << endl;
}