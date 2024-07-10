#include "../include/creacionProg_1.h"

// Creación del arreglo con distribución lineal
std::vector<int> creaArregloLineal(size_t size, int epsilon) {
  std::vector<int> array;
  if(size > 0){
    array.reserve(size);
    array.push_back(rand()%100); // Primer elemento
    for (size_t i = 1; i < size; ++i) {
      array.push_back(array.back() + rand() % epsilon);
    }
  } else {
    printf("No se pudo crear el Arreglo Lineal porque n = %ld no es mayor que 0\n", size);
    exit(0);
  }    
  return array;
}

// Generar un arreglo con distribución normal
std::vector<int> generarArregloNormal(size_t size, double media, double desviacionEstandar) {
  std::random_device rd;
  std::mt19937 generador(rd());
  std::normal_distribution<double> distribucion(media, desviacionEstandar);
  
  std::vector<int> array;
  array.reserve(size);
  
  while (array.size() < size) {
    double value = distribucion(generador);
    if (value >= 0) {
      array.push_back(static_cast<int>(value));
    }
  }

  std::sort(array.begin(), array.end()); // Ordenar el arreglo
  return array;
}