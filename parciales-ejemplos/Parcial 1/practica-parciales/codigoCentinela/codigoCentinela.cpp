#include <iostream>

using namespace std;


int main() {
	
	int n, cantidadEspejos = 0, sumaDPCentinela = -1;
	string codigoCentinela;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		string codigoActual;
		cin >> codigoActual;
		
		int tam = codigoActual.size()-1, j=0;
		bool esEspejo = true;
		
		while(esEspejo and j < tam){
			if(codigoActual.at(j) != codigoActual.at(tam)){
				esEspejo = false;
			}
			j++; tam--;
		}
		
		if(esEspejo){
			cantidadEspejos++;
			int sumaDPActual = 0;
			for(int k=0; k<codigoActual.size(); k++){
				if(k%2 != 0){
					switch(codigoActual.at(k)){
					case '1':
						sumaDPActual++;
						break;
					case '2':
						sumaDPActual += 2;
						break;
					case '3':
						sumaDPActual += 3;
						break;
					case '4':
						sumaDPActual += 4;
						break;
					case '5':
						sumaDPActual += 5;
						break;
					case '6':
						sumaDPActual += 6;
						break;
					case '7':
						sumaDPActual += 7;
						break;
					case '8':
						sumaDPActual += 8;
						break;
					case '9':
						sumaDPActual += 9;
						break;
					}
				}
			}
			if(sumaDPActual > sumaDPCentinela){
				codigoCentinela = codigoActual;
				sumaDPCentinela = sumaDPActual;
			}
		}
	}
	
	cout << cantidadEspejos << endl;
	if(cantidadEspejos > 0){
		cout << codigoCentinela << endl << sumaDPCentinela << endl;
	}
	else{
		cout << "SIN ESPEJOS" << endl << "CERO" << endl;
	}
	
	return 0;
}
