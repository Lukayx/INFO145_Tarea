#include "../include/busquedaProg_2.h"

template <typename T>
int binarySearch(std::vector<int>& sampleArray, int left, int right, int num, int b, std::vector<T>& gapCoding){
  int mid = (left + right) / 2; // Calcula el indice central
  if(left<right) // if el indice izquierdo es menor que el indice derecho entonces...
  { 
    if(sampleArray[mid]==num) // si el valor a buscar coincide con el del arreglo sampleArray  
      return b*mid; // devuelve el idice correspondiente realizando b * mid
    sampleArray[mid] > num ? right = mid-1 : left = mid + 1;
    return binarySearch(sampleArray, left, right, num, b, gapCoding);
  }
  return searchValor(gapCoding, sampleArray[mid], mid*b, num); // cuando left==rigth entonces llamará a la función searchX para buscar a partir de ahí
}

template <typename T>
int searchValor(std::vector<T>& gapCoding, int valor, int indice, int num){ // valor esta justo donde el indice indica 
  if(valor == num) return indice; // si justo donde esta el indice es donde se encuentra num entonces devuelve el indice
  if(valor>num) // si el valor actual se encuentra por encima de num...
  { 
    while(indice > 0 && valor > num)//irá restando mientras el valor sea mayor que 0 y num
    { 
      valor = valor - static_cast<int>(gapCoding[indice]); // se calcula el valor del nuevo indice
      indice--; // retrocede un indice
      if(valor == num) return indice; // si valor es igual al del indice actual, entonces devuelve el indice
    }
  } 
  else 
  {
    int n = gapCoding.size(); 
    while(indice < n-1 && valor < num) //irá sumando mientras el valor sea menor que n y num
    { 
      indice++; // avanza un indice
      valor = valor + static_cast<int>(gapCoding[indice]);// se calcula el valor del nuevo indice
      if(valor == num) return indice; // si valor es igual al del indice actual, entonces devuelve el indice
    }
  }
  return -1; // devuelve -1 si no logró encontrar el valor num
}

template <typename T>
double medirTiempo(std::vector<T>& gapCodingArray, std::vector<int>& sampleArray, int m, int b, int value){
  auto inicio = std::chrono::steady_clock::now(); // Captura el tiempo de inicio
  int indice = binarySearch(sampleArray, 0, m - 1, value, b, gapCodingArray); // Realiza la búsqueda binaria
  auto fin = std::chrono::steady_clock::now(); // Captura el tiempo de fin

  if(indice != -1) 
    std::cout << "El índice donde está ese valor es el " << indice << std::endl;
  else 
    std::cout << "El valor no se encontró en el arreglo." << std::endl;

  // Calcula la duración en segundos como un valor de tipo double
  return std::chrono::duration<double>(fin - inicio).count();
}

void declaraTipos3(){ //declara los tipos de datos que hay para cada template
  std::vector<int> a;
  std::vector<unsigned char> b;
  std::vector<short> c;
  binarySearch(a, 0, 0, 0, 0, a);
  binarySearch(a, 0, 0, 0, 0, b);
  binarySearch(a, 0, 0, 0, 0, c);
  searchValor(a, 0, 0, 0);
  searchValor(b, 0, 0, 0);
  searchValor(c, 0, 0, 0);
  medirTiempo(a, a, 0, 0, 0);
  medirTiempo(b, a, 0, 0, 0);
  medirTiempo(c, a, 0, 0, 0);
}