#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	
	int x1, x2, x3, x4, y1, y2, y3, y4;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	if(x1 != x3 or x2 != x4 or y2 != y1 or y3 != y4){
		cout << "Datos incorrectos" << endl;
	}
	else{
		int n, c1, c2, serieMasLarga = 0;
		float xCentro, yCentro, diametro, radio, puntajeGanador = -2;
		string nombreParticipante, participanteGanador = "", jugadorLPS = "";
		
		xCentro = (x1+x2)/2;
		yCentro =  (y3+y1)/2;
		diametro = x2-x1;
		radio = diametro / 2.0;

		cin >> n;
		
		for(int i=0; i<n; i++){
			cin >> nombreParticipante;
			float puntajeTotal = -2, menorDistAlCentro = -1;
			int serie = 0;
			bool afueraCuadrado, afueraCirculo, distMayorADistAnterior, centroAbsoluto;
			afueraCuadrado = false;
			afueraCirculo = false;
			distMayorADistAnterior = false;
			centroAbsoluto = false;
			
			do{
				cin >> c1 >> c2;
				serie++;
				
				if(c1 < x1 or c1 > x2 or c2 > y1 or c2 < y3){
					afueraCuadrado = true;
				}
				
				float distanciaAlCentro = sqrt(
											   ((float)c1 - xCentro)*((float)c1 - xCentro) + 
											   ((float)c2 - yCentro)*((float)c2 - yCentro)
											   );
				
				if(afueraCuadrado == false and distanciaAlCentro > radio){
					afueraCirculo = true;
				}
				
				if(afueraCirculo == false and menorDistAlCentro != -1 and 
				   distanciaAlCentro > menorDistAlCentro){
					distMayorADistAnterior = true;
				}
				else{
					if(afueraCirculo == false and menorDistAlCentro == -1){
						menorDistAlCentro = distanciaAlCentro;
					}
				}
				
				if(c1 == xCentro and c2 == yCentro){
					centroAbsoluto = true;
				}
				
				float puntajeActual;
				
				if(afueraCuadrado) puntajeActual = -1;
				else{
					if(afueraCirculo) puntajeActual = 0;
					else{
						puntajeActual = (diametro / 2.0) - distanciaAlCentro;
					}
				}
				
				if(puntajeTotal == -2){
					puntajeTotal = puntajeActual;
				}
				else{
					puntajeTotal += puntajeActual;
				}
				
			} while(!(afueraCuadrado or centroAbsoluto or distMayorADistAnterior or afueraCirculo));
			
			if(!afueraCirculo and !afueraCuadrado){
				puntajeTotal += 10;
			}
			
			cout << nombreParticipante << " " << fixed << setprecision(2) << puntajeTotal << " puntos" << endl;
			
			if(serie > serieMasLarga){
				jugadorLPS = nombreParticipante;
				serieMasLarga = serie;
			}
			
			if(participanteGanador == ""){
				participanteGanador = nombreParticipante;
				puntajeGanador = puntajeTotal;
			}
			else{
				if(puntajeTotal > puntajeGanador){
					participanteGanador = nombreParticipante;
					puntajeGanador = puntajeTotal;
				}
			}
		}
		
		cout << endl << "Ganador: " << participanteGanador << " " << puntajeGanador << " puntos" << endl;
		cout << "Jugador LPS: " << jugadorLPS << endl;
	}
	
	
	return 0;
}

