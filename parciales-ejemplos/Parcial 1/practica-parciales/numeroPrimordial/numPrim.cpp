#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	string cadena = "", mayorPrimordial = "";
	int cantNumeros = 0;
	
	while(cin >> cadena and cadena != "FIN"){
		cantNumeros++;
		
		int n = cadena.size() - 2;
		bool paresEnPar = true;
		
		while(n >= 0 and paresEnPar == true){
			if((((int)cadena.at(n) - '0') % 2) != 0){
				paresEnPar = false;
			}
			n-=2;
		}
		
		int mayorCentro, indice;
		if((cadena.size() % 2) == 0){
			int b = cadena.size() / 2, a = b-1;
			if(cadena.at(a) == cadena.at(b) or cadena.at(a) > cadena.at(b)){
				indice = a;
			}
			else{
				indice = b;
			}
		}
		else{
			indice = cadena.size()/2;
		}
		mayorCentro = cadena.at(indice);
		
		int sumaPrevia = 0;
		for(int i=0; i<indice; i++){
			sumaPrevia += cadena.at(i) - '0';
		}
		
		if(mayorCentro > sumaPrevia and paresEnPar){
			cout << cadena << " ACEPTADO" << endl;
			if(mayorPrimordial == "" or cadena > mayorPrimordial or cadena.size() > mayorPrimordial.size()){
				mayorPrimordial = cadena;
			}
		}
		else cout << cadena << " NO PRIMORDIAL" << endl;
	
	}
	
	cout << cantNumeros << endl;
	if(mayorPrimordial == ""){
		cout << "SIN PRIMORDIALES" << endl;
	}
	else{
		cout << mayorPrimordial << endl;
	}
	
	return 0;
}

