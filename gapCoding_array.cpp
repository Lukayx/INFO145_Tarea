#include "gapCodingArray.h"

int main(){
  srand(time(0));// semilla para los números aleatorios
  size_t size = 100000000;  // largo de el arregloLineal
  int m = 100; // largo de sampleArray
  int epsilon = 10; // 
  int b = size/m;
  std::vector<int> gapCodingArray, sampleArray;
  creaArreglos(gapCodingArray, sampleArray, size, epsilon, m, b);
  std::cout << "Escriba el valor que quiere buscar: " << 83563 << std::endl;
  int indice = binarySearch(sampleArray, 0, sampleArray.size()-1, 83563, b, gapCodingArray);
  std::cout << "El indice donde está ese valor es el " << indice << std::endl;

  return EXIT_SUCCESS;
}

// creacion del arreglo con distribución lineal
std::vector<int> creaArregloLineal(size_t size, int epsilon) {
  std::vector<int> array;
  if(size > 0){
    array.push_back(rand() % 100); //primer elemento
    for (size_t i = 1; i < size; ++i) 
    {
      array.push_back(array.back() + rand() % epsilon+1);//agrega siguiente elemento con una diferencia minima de 1 mas y maxima de epsilon + 1
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
  gapCoding_Array.push_back(arregloLineal[0]); //inicia el gapCoding con el valor inicial del arregloLineal
  for (size_t i = 1; i < n; i++)
  {
    gapCoding_Array.push_back(arregloLineal[i] - arregloLineal[i-1]); // va agregando cuanto le falta (suma) para que sea igual al del arreglo lineal y lo agrega a gapCoding
  }
  return gapCoding_Array; // devuelve el arreglo utilizando gapCoding
}

std::vector<int> creaSample(std::vector<int> arregloLineal, int m, int b){
  int n = arregloLineal.size(); //largo de arregloLineal
  std::vector<int> sampleArray;
  if(m<=0){ 
    std::cout << "m debe ser mayor que 0" << std::endl;
    exit(0);
  }
  if(m>=n){ 
    printf("No se pudo crear el Arreglo Sample porque m = %d no es menor que n = %d\n", m, n);
    exit(0);
  }
  for (int i = 0; i < m; i++)
  {
    sampleArray.push_back(arregloLineal[i*b]); // agrega elementos a sampleArray de acuerdo al espaciado especificado anteriormente
  }
  return sampleArray;
}

void creaArreglos(std::vector<int> &gapCodingArray, std::vector<int> &sampleArray, size_t size, int epsilon, int m, int b){
    std::vector<int> arregloLineal = creaArregloLineal(size, epsilon);
    // imprimeArray(arregloLineal);
    gapCodingArray = creaGapCoding(arregloLineal);
    // imprimeArray(gapCodingArray);
    sampleArray = creaSample(arregloLineal, m, b);
    // imprimeArray(sampleArray);
}

int binarySearch(std::vector<int> sampleArray, int left, int right, int num, int b, std::vector<int> gapCoding){
  int mid = (left + right) / 2; // Calcula el indice central
  if(left<right) // if el indice izquierdo es menor que el indice derecho entonces...
  { 
    if(sampleArray[mid]==num) // si el valor a buscar coincide con el del arreglo sampleArray  
      return b*mid; // devuelve el idice correspondiente realizando b * mid
    sampleArray[mid] > num ? right = mid-1 : left = mid + 1;
    return binarySearch(sampleArray, left, right, num, b, gapCoding);
  }
  return searchX(gapCoding, sampleArray[mid], mid*b, num); // cuando left==rigth entonces llamará a la función searchX para buscar a partir de ahí
}

int searchX(std::vector<int> gapCoding, int valor, int indice, int num){ // valor esta justo donde el indice indica 
  if(valor == num) return indice; // si justo donde esta el indice es donde se encuentra num entonces devuelve el indice
  if(valor>num) // si el valor actual se encuentra por encima de num...
  { 
    while(indice > 0 && valor > num)//irá restando mientras el valor sea mayor que 0 y num
    { 
      indice--; // retrocede un indice
      valor = valor - gapCoding[indice]; // se calcula el valor del nuevo indice
      if(valor == num) return indice; // si valor es igual al del indice actual, entonces devuelve el indice
    }
  } 
  else 
  {
    int n = gapCoding.size()-1; 
    while(indice < n && valor < num) //irá sumando mientras el valor sea menor que n y num
    { 
      indice++; // avanza un indice
      valor = valor + gapCoding[indice];// se calcula el valor del nuevo indice
      if(valor == num) return indice; // si valor es igual al del indice actual, entonces devuelve el indice
    }
  }
  return -1; // devuelve -1 si no logró encontrar el valor num
}

void imprimeArray(std::vector<int> v){
  for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << "  ";
  std::cout << "\n\n";
}