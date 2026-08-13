#include <iostream>
#define TAM 1000

using namespace std;

bool permutables(int[], int[]);
void ingresarValores(int[], int &);

int main(){
	
	int A[TAM]={}, B[TAM]={}, n;
	
	cin >> n;
	
	ingresarValores(A, n);
	ingresarValores(B, n);
	
	if (permutables(A, B)==true)
		cout << "SI" << endl;
	else 
		cout << "NO" << endl;
	
	
	return 0;
}
	
void ingresarValores(int arreglo[], int &n){
	int num;
	for (int i=0; i<n; i++){
		cin >> num;
		arreglo[num]++;
	}
}

bool permutables(int A[], int B[]){
	bool todo_ok=true;
	for(int i=0; i<TAM; i++){
		if (A[i]!=B[i])
			todo_ok=false;
	}
	return todo_ok;
}