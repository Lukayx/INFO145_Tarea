#include "../include/creacionProg_2.h"

std::vector<unsigned char> creaGapCoding(std::vector<int> arregloLineal, int n){
  // imprimeArray(arregloLineal);
  std::vector<unsigned char> gapCoding_Array;

  gapCoding_Array.push_back(arregloLineal[0]); //inicia el gapCoding con el valor inicial del arregloLineal
  
  for (int i = 1; i < n; i++)
  {
    gapCoding_Array.push_back(arregloLineal[i] - arregloLineal[i-1]); // va agregando cuanto le falta (suma) para que sea igual al del arreglo lineal y lo agrega a gapCoding
  }
  return gapCoding_Array; // devuelve el arreglo utilizando gapCoding
}

std::vector<int> creaSample(std::vector<int> arregloLineal, int m, int n, int b){
  std::vector<int> sampleArray;

  if(m>=n){ 
    printf("No se pudo crear el Arreglo Sample porque m = %d no es menor que n = %d\n", m, n);
    exit(0);
  }

  for (int i = 0; i < m; i++){
    sampleArray.push_back(arregloLineal[i*b]); // agrega elementos a sampleArray de acuerdo al espaciado especificado anteriormente
  }

  return sampleArray;
}