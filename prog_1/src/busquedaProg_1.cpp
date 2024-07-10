#include "../include/busquedaProg_1.h"

// Búsqueda binaria
int binary_search(const std::vector<int>& arr, int x) {
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
double medirTiempo(const std::vector<int>& array, int numx) {
    auto inicio = std::chrono::steady_clock::now(); // Captura el tiempo de inicio
    binary_search(array, numx); // Realiza la búsqueda binaria
    auto fin = std::chrono::steady_clock::now(); // Captura el tiempo de f

    // Calcula la duración en segundos como un valor de tipo double
    return std::chrono::duration<double>(fin - inicio).count();
}