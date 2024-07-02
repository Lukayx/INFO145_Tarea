#include "../include/creacionProg_1.h"
#include "include/gapCodingArray.h"
#include "include/busquedaProg_2.h"
#include "include/creacionProg_2.h"
#include "include/extrasProg_2.h"

int main(int argc, const char* argv[]){
  int n, m, b, value;

  if (!convertirArgumentos(argc, argv, n, m, value)) {
    return EXIT_FAILURE;
  }

  srand(time(0));// semilla para los números aleatorios
  b = n/m;
  int epsilon = 30;
  double media = 50;
  double desviacionEstandar = 10;

  //A PARTIR DE AQUI COMIENZA A CREAR LOS ARREGLOS Y BUSCAR EL VALOR
  creaArreglos(n, m, b, media, desviacionEstandar, value, epsilon);

  return EXIT_SUCCESS;
}

void creaArreglos(size_t n, int m, int b, double media, double desviacionEstandar, int value, int epsilon){
  {
    std::cout << "\n_--------------------------DISTRIBUCION LINEAL--------------------------_\n" << std::endl;
    std::vector<int> arregloLineal = creaArregloLineal(n, epsilon);
    std::cout << "\nNumero a buscar: " <<  value << std::endl;

    //REPRESENTACION DE DISTRIBUCION LINEAL
    std::vector<unsigned char> gapCodingArray1 = creaGapCoding(arregloLineal, n);
    std::vector<int> sampleArray1 = creaSample(arregloLineal, m, n, b);

    //imprimeArray(arregloLineal);
    // Libera la memoria de arregloLineal
    arregloLineal.clear();
    arregloLineal.shrink_to_fit();

    double distribucionLineal = medirTiempo(gapCodingArray1, sampleArray1, m, b, value);
    std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << distribucionLineal << " segundos\n" << std::endl;
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;
  } // gapCodingArray1, y sampleArray1 se liberan aquí

  {
    std::cout << "_--------------------------DISTRIBUCION NORMAL--------------------------_\n" << std::endl;
    std::vector<int> arregloNormal = generarArregloNormal(n, media, desviacionEstandar);
    std::cout << "\nNumero a buscar: " <<  value << std::endl;

    //REPRESENTACION DE DISTRIBUCION NORMAL
    std::vector<unsigned char> gapCodingArray2 = creaGapCoding(arregloNormal, n);
    std::vector<int> sampleArray2 = creaSample(arregloNormal, m, n, b);  

    //imprimeArray(arregloNormal);
    // Libera la memoria de arregloNormal
    arregloNormal.clear();
    arregloNormal.shrink_to_fit();
    double distribucionNormal = medirTiempo(gapCodingArray2, sampleArray2, m, b, value);
    std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << distribucionNormal << " segundos\n" << std::endl;
    std::cout << "-------------------------------------------------------------------------\n" << std::endl;
  } // gapCodingArray2, y sampleArray2 se liberan aquí
}

