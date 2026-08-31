#include <iostream>
#define TAM 100

using namespace std;

void correoEnviadoxServer(int [][TAM], int, int []);
void serverQueMasEnvio(int [], int);
void serverEncimadeCota(int [][TAM], int, int);

int main(){

    int n, m, server[TAM][TAM], correoEnviado[TAM];

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> server[i][j];
        }
    }

    correoEnviadoxServer(server, n, correoEnviado);
    serverQueMasEnvio(correoEnviado, n);
    serverEncimadeCota(server, n, m);

    return 0;
}

void correoEnviadoxServer(int server[][TAM], int n, int enviado[]){
    for(int i=0; i<n; i++){
        enviado[i] = 0;
        for(int j=0; j<n; j++){
            enviado[i] += server[i][j];
        }
    }

    for(int i=0; i<n; i++){
        cout << "Correo (en kb) enviado por el servidor " << i+1 << ": " << enviado[i] << endl;
    }
    cout << endl;
}

void serverQueMasEnvio(int enviado[], int n){
    int sv_masEnvios = 0;

    for(int i=0; i<n; i++){
        if(enviado[i] > enviado[sv_masEnvios]) sv_masEnvios = i;
    }

    cout << "El servidor con más kb enviados es el " << sv_masEnvios+1 << endl << endl;  
}

void serverEncimadeCota(int server[][TAM], int n, int m){
    int recibidos;

    for(int i=0; i<n; i++){
        recibidos = 0;
        for(int j=0; j<n; j++){
            recibidos += server[j][i];
        }
        if(recibidos > m){
            cout << "El servidor " << i+1 << " recibió más de " << m 
            << " kb de correo (" << recibidos << " kb)." << endl;
        }
    }
    cout << endl;

}