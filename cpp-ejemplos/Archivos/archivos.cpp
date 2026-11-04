#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	ifstream datosEntrada("entrada.txt");
	ofstream datosSalida("salida.txt");
	
	if(datosEntrada.fail()){
		cout << "No se pudo abrir el archivo de entrada" << endl;
		return 1;
	}
	
	if(datosSalida.fail()){
		cout << "No se pudo abrir el archivo de salida" << endl;
		return 1;
	}
	
	string x;
	
	while(datosEntrada >> x){
		cout << x << endl;
	}
	
	datosEntrada.close();
	
	
	for(int i=0; i<4; i++){
		cin >> x;
		datosSalida << x + " ";
	}
	datosSalida.close();
	
	
	return 0;
}

