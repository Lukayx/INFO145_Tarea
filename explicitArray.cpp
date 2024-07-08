#include "include/explicitArray.h"
#include "include/creacionProg_1.h"
#include "include/busquedaProg_1.h"
#include <fstream>

using namespace std;

// Función para guardar los resultados en un archivo CSV
void guardarResultados(const string& filename, size_t n, double tiempoLineal, double tiempoNormal) {
    ofstream file;
    file.open(filename, ios::app);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }
    file << n << "," << fixed << setprecision(10) << tiempoLineal << "," << tiempoNormal << endl;
    file.close();
}


int main(int argc, char *argv[]) {
    // Verificar que se proporcionen los argumentos correctos
    if (argc < 1) {
        cout << "Uso: " << argv[0] << " <size>" << endl;
        return EXIT_FAILURE;
    }

    // Obtener los valores de size y epsilon desde los argumentos
    size_t size = atoi(argv[1]);
    int epsilon = 20;
    double media = size*(epsilon/2)/2;
    double desviacionEstandar = size*(epsilon/2)/8;
    srand(time(0)); // Inicializa la semilla para rand()
    for (int i=0;i<=100;i++){
        /// Inicializar y crear el arreglo lineal
        vector<int> arrayLineal = creaArregloLineal(size, epsilon);

        // Imprimir el arreglo lineal
        //cout << "Array Lineal:" << endl;
        //for (auto i : arrayLineal) {
        //    cout << i << " ";
        //}
        //cout << endl;

        // Medir el tiempo de búsqueda en el arreglo lineal
        int numeroLineal = arrayLineal[rand() % size]; // Número a buscar
        double tarrayLineal = medirTiempo(arrayLineal, numeroLineal); // Inicia búsqueda binaria y mide el tiempo
        cout << "Numero del array a buscar: " << numeroLineal <<endl; 
        cout <<"Binary Search en Array lineal de largo " << size 
                << " tarda: " << fixed << setprecision(10) << tarrayLineal << " segundos" << endl;

        // Liberar la memoria del arreglo lineal
        arrayLineal.clear();
        arrayLineal.shrink_to_fit();

        arrayLineal.clear();
        arrayLineal.shrink_to_fit();
        // Inicializar y crear el arreglo normal
        vector<int> arrayNormal = generarArregloNormal(size, media, desviacionEstandar);

        // Imprimir el arreglo normal
        //cout << "Array Normal:" << endl;
        //for (auto i : arrayNormal) {
        //    cout << i << " ";
        //}
        //cout << endl;

        // Medir el tiempo de búsqueda en el arreglo normal
        int numeroNormal = arrayNormal[rand() % size]; // Número a buscar
        double tarrayNormal = medirTiempo(arrayNormal, numeroNormal); // Inicia búsqueda binaria y mide el tiempo
        cout << "Numero del array a buscar: " << numeroNormal <<endl; 
        cout << "Binary Search en Array normal de largo " << size 
                << " tarda: " << fixed << setprecision(10) << tarrayNormal << " segundos" << endl;
        arrayNormal.clear();
        arrayNormal.shrink_to_fit();
        size = size + 100;
        guardarResultados("../resExplicit.csv", size, tarrayLineal, tarrayNormal);
    
    }
    return EXIT_SUCCESS;
}