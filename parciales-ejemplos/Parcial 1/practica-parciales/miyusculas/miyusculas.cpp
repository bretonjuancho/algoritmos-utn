#include <iostream>

using namespace std;

int main(){

    char c;
    bool primerCaracter = true, empiezaConMinuscula = false, soloLetras = true, siempreMasMinusculas = true,
    alMenosUnaMayuscula = false;
    int cantidadDeMayusculas = 0, cantidadDeMinusculas = 0, cantidadTotal = 0;

    while(cin >> c and c != '*'){
        if(primerCaracter){
            if(islower(c)){
                empiezaConMinuscula = true;
            }
            primerCaracter = false;
        }

        if(islower(c)) cantidadDeMinusculas++;
        if(isupper(c)){
            cantidadDeMayusculas++;
            if(alMenosUnaMayuscula == false) alMenosUnaMayuscula = true;
        }

        if(cantidadDeMayusculas >= cantidadDeMinusculas) siempreMasMinusculas = false;

        if(!(isalpha(c))) soloLetras = false;

        cantidadTotal++;
    }

    if(cantidadTotal == 0) cout << "NADA" << endl;
    else{
        if(empiezaConMinuscula and siempreMasMinusculas and alMenosUnaMayuscula and soloLetras){
            cout << "MIYUSCULA" << endl;
        }
        else cout << "OTRA" << endl;
    }

    return 0;
}