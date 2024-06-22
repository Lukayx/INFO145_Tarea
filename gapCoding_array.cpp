#include "gapCodingArray.h"

int main(){
  srand(time(0));// semilla para los números aleatorios
  size_t size = 100;  // largo de el arregloLineal
  int m = 10; // largo de sampleArray
  int epsilon = 10;
  std::vector<int> gapCodingArray, sampleArray;
  creaArreglos(gapCodingArray, sampleArray, size, epsilon, m);
  // imprimeArray(gapCodingArray);
  return EXIT_SUCCESS;
}

// creacion del arreglo con distribución lineal
std::vector<int> creaArregloLineal(size_t size, int epsilon) {
  std::vector<int> array;
  if(size > 0){
    array.push_back(rand() % 100); //primer elemento
    for (size_t i = 1; i < size; ++i) 
    {
      array.push_back(array.back() + rand() % epsilon);
    }
  } else {
    printf("No se pudo crear el Arreglo Lineal porque size = %ld no es mayor que 0\n", size);
    exit(0);
  }
  return array;
}

std::vector<int> creaGapCoding(std::vector<int> arregloLineal){
  // imprimeArray(arregloLineal);
  std::vector<int> gapCoding_Array;
  size_t n = arregloLineal.size();
  gapCoding_Array.push_back(arregloLineal[0]);
  for (size_t i = 1; i < n; i++)
  {
    gapCoding_Array.push_back(arregloLineal[i] - arregloLineal[i-1]);
  }
  return gapCoding_Array;
}

std::vector<int> creaSample(std::vector<int> arregloLineal, int m){
  size_t n = arregloLineal.size(); //largo de arregloLineal
  std::vector<int> sampleArray;
  if(m<=0){ 
    std::cout << "m debe ser mayor que 0" << std::endl;
    exit(0);
  }
  if(m<=n){ 
    int b = n/m; // espaciado entre los elementos del sample
    for (size_t i = 0; i < m; i++)
    {
      sampleArray.push_back(arregloLineal[i*b]); // agrega elementos a sampleArray de acuerdo al espaciado especificado anteriormente
    }
  } else {
    printf("No se pudo crear el Arreglo Sample porque m = %d no es menor que n = %ld\n", m, n);
    exit(0);
  }
  return sampleArray;
}

void creaArreglos(std::vector<int> &gapCodingArray, std::vector<int> &sampleArray, size_t size, int epsilon, int m){
    std::vector<int> arregloLineal = creaArregloLineal(size, epsilon);
    // imprimeArray(arregloLineal);
    gapCodingArray = creaGapCoding(arregloLineal);
    // imprimeArray(gapCodingArray);
    sampleArray = creaSample(arregloLineal, m);
    // imprimeArray(sampleArray);
}

void imprimeArray(std::vector<int> v){
  for (size_t i = 0; i < v.size(); i++)
  {
    std::cout << v[i] << "  ";
  }
  std::cout << "\n\n";
}