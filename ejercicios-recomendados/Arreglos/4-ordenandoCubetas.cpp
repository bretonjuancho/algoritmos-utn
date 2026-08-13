#include <iostream>
#define TAM 101

using namespace std;

void ingresarPelotas(int &, int &, int[]);
void mostrarCubetas(int &, int[]);

int main(){
	
	int n, tl, cubetas[TAM]={};
	
	cin >> n >> tl;

	ingresarPelotas(n, tl, cubetas);
	
	mostrarCubetas(tl, cubetas);
	
	return 0;
}
	
void ingresarPelotas(int &n, int &tl, int cubetas[]){
	int color;
	for(int i=1; i<=n; i++){
		cin >> color;
		while ((color<0) or (color>tl)){
			cin >> color;
		}
		cubetas[color]++;
	}
}

void mostrarCubetas(int &tl, int cubetas[]){
	for(int i=1; i<=tl; i++)
		cout << i << ": " << cubetas[i] << endl; 
}