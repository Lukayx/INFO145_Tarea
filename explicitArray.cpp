#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// creacion del arreglo con distribución lineal
vector<int> crearArrayLineal(size_t size, int epsilon) {
    vector<int> array;
    array.push_back(rand() % 100); //primer elemento
    for (size_t i = 1; i < size; ++i) {
      array.push_back(array.back() + rand() % epsilon);
    }
    return array;
}

// Búsqueda binaria
int binary_search(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
          return mid;
        }else if (arr[mid] < x) {
          l = mid + 1;
        }else {
          r = mid - 1;
        }
    }
    return -1;
}

// Medir el tiempo de ejecución de busqueda binaria
double medirTiempo(const vector<int>& array, int numx) {
    clock_t inicio = clock();
    binary_search(array, numx);
    clock_t fin = clock();
    return static_cast<double> (fin - inicio) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(0));// semilla para los números aleatorios
    size_t size = 1000000;  // largo de el array
    int epsilon = 10;

    // Inicialización arrays
    vector<int> arrayLineal = crearArrayLineal(size, epsilon);

    // Medición experimental
    int numero = arrayLineal[rand() % size]; // numero a buscar
    double tarraylineal = medirTiempo(arrayLineal, numero); // inicia busqueda binaria y mide el tiempo
    cout << "Busqueda binaria en Array lineal de tamaño"<< size << ",demoró :" << tarraylineal;
    return 0;
}
