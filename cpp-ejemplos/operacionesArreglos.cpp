#include <iostream>
#define TAMFIS 1000 // TAMAÑO FÍSICO, le pongo 1000 espacios por las dudas

using namespace std;

// Operaciones de arreglos
void ordenarSeleccionDirecta(int [], int);
void ordenarInsercionDirecta(int [], int);
void ordenarBurbuja(int [], int);
void ordenarBurbujaMejorado(int [], int);
int busquedaSecuencial(int [], int, int);
int busquedaBinaria(int [], int, int);
void borrarElemento(int[], int, int &);
void insertarElemento(int[], int, int, int &);
void merge(int [], int[], int[], int, int, int &);
void mostrarArreglo(int [], int);
void ingresarArreglo(int [], int &);

// Funciones para el programa
void nuevaOperacion(bool &);

int main(){

    int arreglo1[TAMFIS] = {}, tamLogico1; // Tamaño lógico es sinómimo de tamaño real
    int arreglo2[TAMFIS] = {}, tamLogico2;
    int arreglo3[TAMFIS] = {}, tamLogico3;
    int operacion;

    ingresarArreglo(arreglo1, tamLogico1);

    bool ingresoOperacion = true;

    while(ingresoOperacion){

        
        cout << endl << "1 - Mostrar arreglo" << endl
        << "2 - Buscar un elemento dentro del arreglo" << endl
        << "3 - Ordenar el arreglo" << endl
        << "4 - Intercalar dos arreglos" << endl << endl
        << "Seleccione la operacion a realizar sobre el arreglo (ingrese un numero): ";
        cin >> operacion;

        switch(operacion){
            case 1: // Mostrar arreglo
                mostrarArreglo(arreglo1, tamLogico1);
                nuevaOperacion(ingresoOperacion);
            break;
            case 2:
                int elementoABuscar, tipoBusqueda;
                cout << "Ingrese el elemento que desea buscar: ";
                cin >> elementoABuscar;

                cout << endl << "1 - Busqueda secuencial" << endl;
                cout << "2 - Busqueda binaria" << endl << endl;
                cout << "Ingrese el tipo de busqueda: ";
                cin >> tipoBusqueda;

                if(tipoBusqueda == 1){
                    cout << "Posicion donde esta el valor " << elementoABuscar << ": " 
                    << busquedaSecuencial(arreglo1, tamLogico1, elementoABuscar) << endl;
                }
                if(tipoBusqueda == 2){
                    cout << "Primero ordenamos el arreglo..." << endl;
                    ordenarSeleccionDirecta(arreglo1, tamLogico1);
                    cout << "Arreglo ordenado: "; mostrarArreglo(arreglo1, tamLogico1);

                    cout << "Posicion donde esta el valor " << elementoABuscar << ": " 
                    << busquedaBinaria(arreglo1, tamLogico1, elementoABuscar) << endl;
                }
                if(tipoBusqueda != 1 and tipoBusqueda != 2) cout << "Numero mal ingresado." << endl;

                nuevaOperacion(ingresoOperacion);
            break;
            case 3:
                int tipoOrdenamiento;
                cout << endl << "1 - Seleccion Directa" << endl;
                cout << "2 - Insercion Directa" << endl;
                cout << "3 - Burbuja" << endl;
                cout << "4 - Burbuja mejorado" << endl;
                cout << "Ingrese el tipo de ordenamiento: ";
                cin >> tipoOrdenamiento;

                switch(tipoOrdenamiento){
                    case 1:
                        ordenarSeleccionDirecta(arreglo1, tamLogico1);
                    break;
                    case 2:
                        ordenarInsercionDirecta(arreglo1, tamLogico1);
                    break;
                    case 3:
                        ordenarBurbuja(arreglo1, tamLogico1);
                    break;
                    case 4:
                        ordenarBurbujaMejorado(arreglo1, tamLogico1);
                    break;
                    
                    default:
                        cout << "Numero mal ingresado." << endl;
                    break;
                }
            break; 
            case 4:
                cout << endl << "Para intercalar dos arreglos vas a necesitar ingresar otro arreglo." << endl;
                ingresarArreglo(arreglo2, tamLogico2);

                cout << endl << "Ordenando los dos arreglos..." << endl;
                ordenarSeleccionDirecta(arreglo1, tamLogico1);
                ordenarSeleccionDirecta(arreglo2, tamLogico2);
                cout << "Arreglos ordenados." << endl;
                cout << "Arreglo 1: "; mostrarArreglo(arreglo1, tamLogico1);
                cout << "Arreglo 2: "; mostrarArreglo(arreglo2, tamLogico2);

                merge(arreglo1, arreglo2, arreglo3, tamLogico1, tamLogico2, tamLogico3);

                cout << endl << "Resultado de intercalar los dos arreglos: "; 
                mostrarArreglo(arreglo3, tamLogico3);

                nuevaOperacion(ingresoOperacion);
            break;
            default:
                cout << "No ingresaste una operacion valida. Volve a intentar." << endl << endl;
            break;
        }
    }

    return 0;
}

void nuevaOperacion(bool & ingresoOp){
    string respuesta;
    cout << endl << "�Desea realizar una nueva operacion? (SI / NO): ";
    cin >> respuesta;
    
    for(int i=0; i<respuesta.size(); i++) respuesta[i] = toupper(respuesta[i]);

    if(respuesta == "SI") ingresoOp = true;
    else ingresoOp = false;
}

void ingresarArreglo(int arreglo[], int &tamLogico){
    /* El tamaño lógico se pasa por referencia porque se modifica
    en la función y se quiere mantener el valor modificado. 
    IMPORTANTE: Siempre tamaño lógico <= tamaño físico*/ 
    cout << "Ingrese el tamano logico del arreglo: ";
    cin >> tamLogico;


    /* Uso el tamaño lógico para ingresar cada uno de
    los elementos del arreglo */
    cout << "Ingrese los " << tamLogico << " datos del arreglo: ";
    for(int i=0; i<tamLogico; i++){ 
        cin >> arreglo[i];
    }
}

void mostrarArreglo(int arreglo[], int tamLogico){
    cout << "[ ";
    for(int i=0; i<tamLogico; i++) cout << arreglo[i] << " ";
    cout << "]" << endl;
}

void ordenarSeleccionDirecta(int arreglo[], int tamLogico){
    int minimo; // No hace falta inicializarlo porque se inicializa en el primer for
    //En 'minimo' guardamos la posición del elemento más chico en esa iteración.

    for(int i=0; i<tamLogico; i++){ 
        /*Este for recorre todo el arreglo y va poniendo en cada iteración en 
        la posición 'i' el elemento más pequeño que queda sin ordenar.*/
        minimo = i; // minimo = i porque i es la posición del primer elemento sin ordenar 
        for(int j=i+1; j<tamLogico; j++){
            /* Este segundo for recorre el arreglo pero solo los elementos que NO 
            están ordenados (por eso parte desde i+1, los elementos que van 
            desde 0 hasta i están ordenados ya). La función de este for es encontrar
            el elemento más chico dentro de los elementos que no están ordenados. 
            
            Si encontramos un elemento menor que el que tenemos en arreglo[minimo], 
            entonces el minimo cambia y minimo = j (posicion del nuevo elemento más chico) */ 
            if(arreglo[j] < arreglo[minimo]) minimo = j;
        }
        /* Una vez que encontramos el elemento más chico dentro de los elementos no 
        ordenados, lo ponemos en la posición que le corresponde (posición i). Ese
        elemento pasa a quedar ordenado y la posición donde lo pusimos (i) es su
        posición definitiva (no va a cambiar). */
        swap(arreglo[i], arreglo[minimo]);
    }
}

/* Pasamos tamLogico por referencia porque se modifica su valor y queremos que 
en 'main' se vea este cambio. (En borrar elemento el tamaño del arreglo se reduce
y en insertar elemento el tamaño aumenta) */
void borrarElemento(int arreglo[], int posicionABorrar, int &tamLogico){
    if(tamLogico == 0){
        cout << "No se puede borrar un elemento porque el arreglo ya esta vacio.";
        return; // Cortamos la ejecución del procedimiento
    }
    
    for(int i = posicionABorrar; i < tamLogico - 1; i++){
        arreglo[i] = arreglo[i+1];
    }
    tamLogico--;
}

void insertarElemento(int arreglo[], int posicionAInsertar, int valorAInsertar, int &tamLogico){
    if(tamLogico == TAMFIS){
        cout << "No se puede insertar un elemento porque no hay mas espacio en el arreglo.";
        return; // Cortamos la ejecución del procedimiento
    }
    
    for(int i = tamLogico; i > posicionAInsertar; i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[posicionAInsertar] = valorAInsertar;
    tamLogico++;
}

int busquedaSecuencial(int arreglo[], int tamLogico, int elementoABuscar){
    for(int i=0; i<tamLogico; i++){
        /* Si encontramos el elemento directamente retornamos el índice 
        donde lo encontramos y cortamos la ejecución de la función */ 
        if(arreglo[i] == elementoABuscar) return i;
    }
    /* Retornamos -1 (indice imposible dentro de un arreglo)
    cuando recorrimos todo el arreglo y no encontramos
    el elemento que se estaba buscando*/
    return -1;
}

int busquedaBinaria(int arreglo[], int tamLogico, int elementoABuscar){
    /* limiteInferior y limiteSuperior establecen el rango de valores.
    IMPORTANTE: el arreglo debe estar ordenado para poder usar búsqueda binaria.
    A partir de ver arreglo[medio] vemos cómo actualizamos los limites.
    
    Si arreglo[medio] > elementoABuscar -> limiteSuperior = medio-1
    Esto porque el arreglo está ordenado y podemos asegurar que los elementos 
    a la izquierda de arreglo[medio] son más chicos que arreglo[medio] y que
    se acercan más al elemento que estamos buscando.
    
    Lo mismo para si arreglo[medio] es menor que el elementoABuscar
    Si arreglo[medio] < elementoABuscar -> limiteInferior = medio+1 */
    int medio, limiteInferior = 0, limiteSuperior = tamLogico-1;

    /* Cuando los dos límites son iguales es la última iteración. Si
    limiteInferior > limiteSuperior entonces ya debería cortar porque 
    no se encontró el elemento. */
    while(limiteInferior <= limiteSuperior){
        // Establecemos el elemento del medio del rango de valores que estamos viendo
        medio = (limiteInferior + limiteSuperior) / 2;

        // Si encontramos el elemento retornamos la posición donde lo encontramos
        if(arreglo[medio] == elementoABuscar) return medio;
        else{
            if(arreglo[medio] > elementoABuscar) limiteSuperior = medio-1;
            else limiteInferior = medio+1;
        }
    }

    /* Si no encontramos el elemento que se buscaba retornamos -1 cómo en la 
    búsqueda secuencial */

    return -1;
}

void merge(int arreglo1[], int arreglo2[], int arregloMergeado[],
    int tamLogico1, int tamLogico2, int &tamLogicoMerge){
    int iterador1, iterador2, iteradorMerge;
    //Inicializamos todo en 0
    iterador1 = iterador2 = iteradorMerge = tamLogicoMerge = 0;

    /* Mientras los dos arreglos todavía tengan elementos que no hayan sido
    insertados en el nuevo arreglo, vamos insertando el menor elemento actual
    entre los dos arreglos */
    while(iterador1 < tamLogico1 and iterador2 < tamLogico2){
        if(arreglo1[iterador1] < arreglo2[iterador2]){
            arregloMergeado[iteradorMerge] = arreglo1[iterador1];
            iterador1++;
            iteradorMerge++;
        }
        else{
            arregloMergeado[iteradorMerge] = arreglo2[iterador2];
            iterador2++;
            iteradorMerge++;
        }
    }


    /* Si uno de los dos arreglos se quedó sin elementos, insertamos todos los 
    elementos del arreglo que todavía tiene valores. En este while hacemos arreglo1 */
    while(iterador1 < tamLogico1){
        arregloMergeado[iteradorMerge] = arreglo1[iterador1];
        iterador1++;
        iteradorMerge++;
    }

    // Lo mismo para arreglo2
    while(iterador2 < tamLogico2){
        arregloMergeado[iteradorMerge] = arreglo2[iterador2];
        iterador2++;
        iteradorMerge++;
    }

    /* El tamaño del arreglo mergeado va a ser la suma de los tamaños de los arreglos
    que se intercalaron porque se usan todos los elementos de cada uno. 
    */
    tamLogicoMerge = tamLogico1 + tamLogico2;
}

void ordenarInsercionDirecta(int arreglo[], int tamLogico){
    
    for(int i=1; i<tamLogico; i++){
        /* Igualo j a i y trato de llevar el arreglo[j] lo más a la izquierda posible, hasta que
        encuentre un valor menor a arreglo[j] */
        int j = i;
        while(j > 0 and arreglo[j] < arreglo[j-1]){
            swap(arreglo[j], arreglo[j-1]);
            j--;
        }
    }
}

void ordenarBurbuja(int arreglo[], int tamLogico){
    /* Por cada pasada ordeno el mayor elemento actualmente desordenado. Es decir,
    en la pasada 1 pongo el elemento más grande en el posición final, en la pasada
    2 pongo el segundo elemento más grande en la anteúltima posición y así sucesivamente.
    Hacemos pasada = 1 porque si ordenamos n-1 elementos el elemento que queda también 
    estará ordenado. */
    for(int pasada = 1; pasada < tamLogico; pasada++){
        for(int k=0; k< tamLogico-1; k++){
            if(arreglo[k] > arreglo[k+1]) swap(arreglo[k], arreglo[k+1]);
        }
    }
}

void ordenarBurbujaMejorado(int arreglo[], int tamLogico){
    /* Lo único que cambia con respecto al burbuja original es que tenemos en cuenta
    que por cada pasada los elementos más grandes se van ordenando al final del arreglo,
    entonces nos podemos ahorrar un par de iteraciones haciendo k < tl - pasada en vez 
    de k < tl-1 */
    for(int pasada = 1; pasada < tamLogico; pasada++){
        for(int k=0; k< tamLogico-pasada; k++){
            if(arreglo[k] > arreglo[k+1]) swap(arreglo[k], arreglo[k+1]);
        }
    }
}
