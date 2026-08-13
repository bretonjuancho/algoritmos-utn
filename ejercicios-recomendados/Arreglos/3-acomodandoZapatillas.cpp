#include <iostream>
#define TAM 100000

using namespace std;

void zapatillas(int[], int &);
void desechables(int[], int &);

int main(){
	
	int n, placar[TAM]={};
	
	cin >> n;
	
	zapatillas(placar, n);
	
	desechables(placar, n);
	
	return 0;
}
	
void zapatillas(int placar[], int &n){
	
	int num;
	for(int i=0; i<n; i++){
		cin >> num;
		placar[num]++;
	}
}

void desechables(int placar[], int &n){
	
	bool clean=true; int aTirar=0;
	
	for(int i=0; i<TAM; i++){
		if((placar[i]%2)!=0){
			cout << i << " ";
			clean=false;
			aTirar++;
		}
	}
	if((clean==true))
		cout << ":D" << endl;
	else
		cout << endl;
	
	cout << aTirar << endl << n-aTirar << endl;
}