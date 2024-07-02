#include "include/explicitArray.h"
#include "include/creacionProg_1.h"
#include "include/busquedaProg_1.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Verificar que se proporcionen los argumentos correctos
    if (argc < 3) {
        cout << "Uso: " << argv[0] << " <size> <epsilon>" << endl;
        return 1;
    }

    // Obtener los valores de size y epsilon desde los argumentos
    size_t size = atoi(argv[1]);
    int epsilon = atoi(argv[2]);

    double media = 50;
    //double media = (size * epsilon) / 2;
    double desviacionEstandar = 10;
    srand(time(0)); // semilla

    // Inicialización de los arrays
    vector<int> arrayLineal = creaArregloLineal(size, epsilon);
    vector<int> arrayNormal = generarArregloNormal(size, media, desviacionEstandar);

    // Imprimir el arreglo lineal
    cout << "Array Lineal:" << endl;
    for (auto i : arrayLineal) {
        cout << i << " ";
    }
    cout << endl;

    // Imprimir el arreglo normal
    cout << "Array Normal:" << endl;
    for (auto i : arrayNormal) {
        cout << i << " ";
    }
    cout << endl;


    // Medición experimental en el arreglo lineal
    int numeroLineal = arrayLineal[rand() % size]; // Número a buscar
    double tarrayLineal = medirTiempo(arrayLineal, numeroLineal); // Inicia búsqueda binaria y mide el tiempo
    cout << "Numero del array a buscar: " << numeroLineal <<endl; 
    cout <<"Binary Search en Array lineal de largo " << size 
            << " tarda: " << fixed << setprecision(10) << tarrayLineal << " segundos" << endl;

    // Medición experimental en el arreglo normal
    int numeroNormal = arrayNormal[rand() % size]; // Número a buscar
    double tarrayNormal = medirTiempo(arrayNormal, numeroNormal); // Inicia búsqueda binaria y mide el tiempo
    cout << "Numero del array a buscar: " << numeroNormal <<endl; 
    cout << "Binary Search en Array normal de largo " << size 
            << " tarda: " << fixed << setprecision(10) << tarrayNormal << " segundos" << endl;
    return 0;
}