#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

string patenteAleatoria(int);
void listarPatentes();

int main(){

    srand( time( NULL ) );

    int pais;
    cout << "Ingrese el país del que quiere una patente: ";
    cin >> pais;

    listarPatentes();

    return 0;
}

//EJERCICIO A)
string patenteAleatoria(int pais){

    string patenteGenerada = "";

    switch(pais){
        case 1: // URUGUAY AAA 1111
            patenteGenerada += (char)((rand() % (90 - 65)) + 65);
            patenteGenerada += (char)((rand() % (90 - 65)) + 65);
            patenteGenerada += (char)((rand() % (90 - 65)) + 65);
        
            patenteGenerada += (char)((rand() % 10) + 48);
            patenteGenerada += (char)((rand() % 10) + 48);
            patenteGenerada += (char)((rand() % 10) + 48);
            patenteGenerada += (char)((rand() % 10) + 48);
        break;

        case 2: // AAA 1 A 11 
            patenteGenerada += (char)((rand() % (90 - 65)) + 65);
            patenteGenerada += (char)((rand() % (90 - 65)) + 65);

            patenteGenerada += (char)((rand() % 10) + 48);

            patenteGenerada += (char)((rand() % (90 - 65)) + 65);

            patenteGenerada += (char)((rand() % 10) + 48);
            patenteGenerada += (char)((rand() % 10) + 48);
        break;

        case 3:
        break;
    }

    return patenteGenerada;

}

//EJERCICIO C)
void listarPatentes(){

    for(int i = 65; i <= 90; i++){
        for(int j = 65; j <= 90; j++){
            for(int k = 48; k <= 57; k++){
                for(int l = 48; l <= 57; l++){
                    for(int p = 48; p <= 57; p++){
                        for(int o = 48; o <= 57; o++){
                            for(int q=48; q<=57; q++){
                                cout << (char)i;
                                cout << (char)j;
                                cout << (char)k;
                                cout << (char)l;
                                cout << (char)p;
                                cout << (char)o;
                                cout << (char)q << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
    }


}