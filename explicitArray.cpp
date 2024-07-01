#include <iostream>
#include <vector>

#include <random>
#include <algorithm>
#include <chrono> // Necesario para std::chrono y medir tiempos
#include <iomanip> //este sirve para la subpresición del tiempo que tarda
using namespace std;

// Creación del arreglo con distribución lineal
vector<int> crearArrayLineal(size_t size, int epsilon) {
    vector<int> array;
    array.push_back(rand() % 100); // Primer elemento
    for (size_t i = 1; i < size; ++i) {
        array.push_back(array.back() + rand() % epsilon);
    }
    return array;
}

// Generar un arreglo con distribución normal
vector<int> generarArregloNormal(size_t tamano, double media, double desviacionEstandar) {
    std::random_device rd;
    std::mt19937 generador(rd());
    normal_distribution<double> distribucion(media, desviacionEstandar);
    
    vector<int> array(tamano);
    for (size_t i = 0; i < tamano; ++i) {
        array[i] = static_cast<int>(distribucion(generador)); // Generar valores con distribución normal
    }
    sort(array.begin(), array.end()); // Ordenar el arreglo
    return array;
}

// Búsqueda binaria
int binary_search(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

// Medir el tiempo de ejecución de búsqueda binaria usando std::chrono
double medirTiempo(const vector<int>& array, int numx) {
    auto inicio = chrono::steady_clock::now(); // Captura el tiempo de inicio
    binary_search(array, numx); // Realiza la búsqueda binaria
    auto fin = chrono::steady_clock::now(); // Captura el tiempo de f

    // Calcula la duración en segundos como un valor de tipo double
    return chrono::duration<double>(fin - inicio).count();
}

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
    vector<int> arrayLineal = crearArrayLineal(size, epsilon);
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