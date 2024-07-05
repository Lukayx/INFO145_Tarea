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
  int epsilon = 21;
  double media = n*epsilon/4;
  double desviacionEstandar = 30;

  //A PARTIR DE AQUI COMIENZA A CREAR LOS ARREGLOS Y BUSCAR EL VALOR
  creaArreglos(n, m, b, media, desviacionEstandar, value, epsilon);

  return EXIT_SUCCESS;
}

void creaArreglos(size_t n, int m, int b, double media, double desviacionEstandar, int value, int epsilon){
  auto imprimirYMedir = [&](auto&& arreglo, const std::string& distribucionNombre) {
    std::cout << "\n_--------------------------" << distribucionNombre << "--------------------------_\n" << std::endl;
    std::cout << "Numero a buscar: " <<  value << "\n" <<std::endl;

    TipoVariant type = retornaTipo(arreglo[0]); // En base al primer elemento del arreglo, retorna el tipo de dato adecuado
    std::visit([&](auto&& arg) { // Para transformar type al tipo de dato correspondiente se usa std::visit
      using T = std::decay_t<decltype(arg)>; // Usa 'T' para asignarle el tipo de dato para gapCodingArray
      std::vector<T> gapCodingArray = creaGapCoding<T>(arreglo, n); 
      std::vector<int> sampleArray = creaSample(arreglo, m, n, b);

      // imprimeArray(arreglo);

      // Libera la memoria del arreglo
      arreglo.clear();
      arreglo.shrink_to_fit();

      double tiempo = medirTiempo(gapCodingArray, sampleArray, m, b, value); 
      std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << tiempo << " segundos\n" << std::endl;
      std::cout << "-------------------------------------------------------------------------\n" << std::endl;
    }, type);
  };

  // Distribución Lineal
  std::vector<int> arregloLineal = creaArregloLineal(n, epsilon);
  imprimirYMedir(arregloLineal, "DISTRIBUCION LINEAL");

  // Distribución Normal
  std::vector<int> arregloNormal = generarArregloNormal(n, media, desviacionEstandar);
  imprimirYMedir(arregloNormal, "DISTRIBUCION NORMAL");
}