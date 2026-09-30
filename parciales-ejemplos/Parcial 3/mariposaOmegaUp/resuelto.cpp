#include <iostream>
#define TAM 30
using namespace std;

struct RGB{
    int rojo, verde, azul;
};

void asignarColorCelda(RGB &, char);

int main() {
  
    RGB mariposa[TAM][TAM];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = ' ';
            if (j < i && j < n - 1 - i) {
                c = '*';
            } else if (j > i && j > n - 1 - i) {
                c = '-';
            }

            asignarColorCelda(mariposa[i][j] , c);
            
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}

void asignarColorCelda(RGB & celda, char c){
    switch (c){
    case '*':
        celda = {0, 255, 255};
        break;

    case '-':
        celda = {255, 0, 255};
        break;
    
    default:
        celda = {100,100,100};
        break;
    }
}