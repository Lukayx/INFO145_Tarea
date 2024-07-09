#include "../include/creacionProg_2.h"

template <typename T>
std::vector<T> creaGapCoding(std::vector<int>& arregloLineal, int n){
  std::vector<T> gapCoding_Array;
  gapCoding_Array.reserve(n);  // Reservar espacio para evitar realocaciones frecuentes

  gapCoding_Array.push_back(static_cast<T>(arregloLineal[0])); // Iniciar con el primer valor
  
  for (int i = 1; i < n; i++){
    gapCoding_Array.push_back(static_cast<T>(arregloLineal[i] - arregloLineal[i-1])); // Calcula y agrega el gap
  }
  return gapCoding_Array; // devuelve el arreglo utilizando gapCoding
}

std::vector<int> creaSample(std::vector<int>& arregloLineal, int m, int n, int b){
  std::vector<int> sampleArray;
  sampleArray.reserve(m);  // Reservar espacio para evitar realocaciones frecuentes
  
  for (int i = 0; i < m; i++){
    sampleArray.push_back(arregloLineal[i*b]); // agrega elementos de acuerdo al espaciado especificado anteriormente
  }

  return sampleArray;
}

void declaraTipos2(){ //declara los tipos de datos que hay para cada template
  std::vector<int> a;
  std::vector<unsigned char> b = creaGapCoding<unsigned char>(a, 0);
  std::vector<short> c = creaGapCoding<short>(a, 0);
  std::vector<int> d = creaGapCoding<int>(a, 0);
}