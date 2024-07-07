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
  int epsilon = 20;
  double media = n*(epsilon/2)/2;
  double desviacionEstandar = n*(epsilon/2)/8;
  //A PARTIR DE AQUI COMIENZA A CREAR LOS ARREGLOS Y BUSCAR EL VALOR
  creaArreglos(n, m, b, media, desviacionEstandar, value, epsilon);

  return EXIT_SUCCESS;
}

void creaArreglos(size_t n, int m, int b, double media, double desviacionEstandar, int value, int epsilon){
  auto imprimirYMedir = [&](auto&& arreglo, TipoVariant type, const std::string& distribucionNombre) {
    std::cout << "\n_--------------------------" << distribucionNombre << "--------------------------_\n" << std::endl;
    std::cout << "Numero a buscar: " <<  value << "\n" <<std::endl;

    std::visit([&](auto&& arg) { // Para transformar type al tipo de dato correspondiente se usa std::visit
      using T = std::decay_t<decltype(arg)>; // Usa 'T' para asignarle el tipo de dato para gapCodingArray
      std::vector<T> gapCodingArray = creaGapCoding<T>(arreglo, n); 
      std::vector<int> sampleArray = creaSample(arreglo, m, n, b);

      // imprimeArray(gapCodingArray);
      save_to_file(arreglo, distribucionNombre+".txt");

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
  imprimirYMedir(arregloLineal, char(),  "DISTRIBUCION_LINEAL");

  // Distribución Normal
  std::vector<int> arregloNormal = generarArregloNormal(n, media, desviacionEstandar);
  imprimirYMedir(arregloNormal, int(), "DISTRIBUCION_NORMAL");
}