#include <iostream> 

using namespace std;

int main(){

    int n;
    string x, y;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;

        if(x < y and x.size() == y.size()){
            int tam = x.size(), grado = 0;
            bool XmenoroigualYposPorpos = true;

            for(int j=0; j<tam; j++){
                if(x[j] > y[j]) XmenoroigualYposPorpos = false;
                grado += abs(x[j] - y[j]);
            }

            if(XmenoroigualYposPorpos == true){
                cout << "Ampliable" << endl << grado << endl;
            }
            else cout << "No Ampliable" << endl;
        }
        else cout << "No Ampliable" << endl;
    }


    return 0;
}