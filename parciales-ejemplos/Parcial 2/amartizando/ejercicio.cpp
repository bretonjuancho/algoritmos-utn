#include <iostream>
#include <iomanip>
#define TF 1000
using namespace std;
void leerDatosTerna(int[], int[], char[]);
int main(){
	int altitud[TF], distancia[TF];
	char direccion[TF];
	leerDatosTerna(altitud,distancia, direccion);
	return 0;
}
	void leerDatosTerna(int altitud[], int distancia[], char direccion[]){
		int Tl=0;
		
		while(cin>> altitud[Tl]>> distancia[Tl]>> direccion[Tl] && altitud[Tl]!=0){
			Tl++; 
		} Tl++;

		float velprom;
		velprom= ( (float) altitud[0]/ (float) Tl);

		cout<< fixed << setprecision (2) <<velprom<<endl;
		
		int x=0, y=0;
		for (int i=0; i<Tl; i++){
			if(direccion[i] == 'N' ){
				y +=distancia[i];
			}
			
			if(direccion[i] == 'S' ){
				y -=distancia[i];
			}
			if(direccion[i] == 'E' ){
				x +=distancia[i];
			}
			if(direccion[i] == 'O' ){
				x -=distancia[i];
			}
			
		}
		cout<< "("<<x <<","<<y <<" )" <<endl;
		
	}