#include <iostream>
using namespace std;

void calcularPuntajes(int [][10], int []);
int dueloHonor(int [][10]);

int main(int argc, char *argv[]) {
	
	int puntos[10][10], bonus[10];
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin >> puntos[i][j];
		}
	}
	
	for(int i=0; i<10; i++){
		cin >> bonus[i];
	}
	
	calcularPuntajes(puntos, bonus);
	
	cout << "Equipo ganador del duelo de Honor: " << dueloHonor(puntos) << endl;
	
	return 0;
}

void calcularPuntajes(int puntos[][10], int bonus[]){
	int mayorResultado = 0, mayorEquipo = 0;
	
	for(int i=0; i<10; i++){ // F
		int total = 0;
		for(int j=0; j<10; j++){ // C
			total += puntos[i][j] * bonus[j];
		}
		cout << total << " ";
		
		if(total > mayorResultado){
			mayorResultado = total;
			mayorEquipo = i+1;
		}
	}
	cout << endl;
	
	cout << "Equipo ganador: " << mayorEquipo;
	cout << ". Puntaje ganador: " << mayorResultado << endl;
	
}

int dueloHonor(int puntos[][10]){
	int ganador = 0, maxPuntos = puntos[0][0];
	
	for(int i=0; i<10; i++){
		if(puntos[i][i] > maxPuntos){
			maxPuntos = puntos[i][i];
			ganador = i+1;
		}
	}
	
	return ganador;
}
	
	
