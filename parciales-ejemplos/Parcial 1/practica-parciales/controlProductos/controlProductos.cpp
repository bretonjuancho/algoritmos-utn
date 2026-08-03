#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int n;
	string producto;
	
	cin >> n;
	cin.ignore();
	
	while(n--){
		getline(cin,producto);
		
		bool esValido = true;
		int cantidadNumeros = 0;
		
		if(producto.size() > 15) esValido = false;
		
		for(int i=0; i<producto.size() and esValido; i++){
			if(!((producto[i] >= 'A' and producto[i] <= 'Z') 
			   or producto[i] == 'Ñ'
			   or (producto[i] >= '0' and producto[i] <= '9'))){
				esValido = false;
			}
			
			if(producto[i] >= '0' and producto[i] <= '9') cantidadNumeros++;
			
			if(i > 0){
				if(((producto[i] >= 'A' and producto[i] <= 'Z') 
				   or producto[i] == 'Ñ') and producto[i] == producto[i-1]){
					esValido = false;
				}
			}
		}
		
		if(cantidadNumeros < 2) esValido = false;
		
		if(!esValido) cout << "INVALIDO" << endl;
		else{
			for(int i = producto.size(); i >= 0; i--){
				if(producto[i] >= '0' and producto[i] <= '9')
					cout << producto[i];
			}
			cout << endl;
		}
	}
	
	return 0;
}

