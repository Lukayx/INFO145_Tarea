#include "../include/creacionProg_1.h"
#include "include/gapCodingArray.h"
#include "include/busquedaProg_2.h"
#include "include/creacionProg_2.h"
#include "include/extrasProg_2.h"
#include "include/pruebaMemoria.hpp"

std::string getMemoryUsage(pid_t pid) {
  std::ifstream statusFile("/proc/" + std::to_string(pid) + "/status");
  std::string line;
size_t start, end;
  while (std::getline(statusFile, line)) {
    if (line.find("VmRSS:") != std::string::npos) {
      // Encuentra la posición del primer dígito
      start = line.find_first_of("0123456789");
      end = line.find_first_not_of("0123456789", start);
      // Encuentra la posición del primer carácter que no es un dígito después del inicio
      break;
    }
  }
  statusFile.close();
  return line.substr(start, end - start);
}

// Función para guardar los resultados en un archivo CSV
void guardarResultados(const std::string& filename, size_t n, double tiempoLineal, int espacioLineal, double tiempoNormal, int espacioNormal) {
  std::ofstream file(filename.c_str(), std::ios::app);
  if (file.is_open()) {
    printf("a");
    file << n << ","  << std::fixed << std::setprecision(10) << tiempoLineal << "," << espacioLineal << "," << tiempoNormal << "," << espacioNormal << std::endl;
    file.close();
  } else {
    std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
  }
}

int main(int argc, const char* argv[]){
  int n, m, b;
  pid_t pid = getpid();
  std::cout << "Memory usage for PID " << pid << ":\n" << std::endl;
  if(!convertirArgumentos(argc, argv, n)) {
    return EXIT_FAILURE;
  }
  
  srand(time(0));// semilla para los números aleatorios
  m = log2(n);
  b = n/m;
  int epsilon = 20;
  double media = n*(epsilon/2)/2;
  double desviacionEstandar = n*(epsilon/2)/8;
  
  //A PARTIR DE AQUI COMIENZA A CREAR LOS ARREGLOS Y BUSCAR EL VALOR
  creaArreglos(n, m, b, media, desviacionEstandar, epsilon, pid);

  return EXIT_SUCCESS;
}

void creaArreglos(size_t n, int m, int b, double media, double desviacionEstandar, int epsilon, pid_t pid){
  auto imprimirYMedir = [&](auto&& arreglo, TipoVariant type, double& tiempo, int& memory, const std::string& distribucionNombre) {
    // std::cout << "\n_--------------------------" << distribucionNombre << "--------------------------_\n" << std::endl;
    int value = arreglo[rand() % n];
    std::cout << "Numero a buscar: " <<  value << "\n" <<std::endl;
    std::visit([&](auto&& arg) { // Para transformar type al tipo de dato correspondiente se usa std::visit
      using T = std::decay_t<decltype(arg)>; // Usa 'T' para asignarle el tipo de dato para gapCodingArray

      // std::cout << "Se creó arreglo: " << getMemoryUsage(pid);  
      std::vector<T> gapCodingArray = creaGapCoding<T>(arreglo, n); 
      
      // std::cout << "\nSe creó gapCodingArray: " << getMemoryUsage(pid);
      std::vector<int> sampleArray = creaSample(arreglo, m, n, b);
      
      // std::cout << "\nSe creó sampleArray: " << getMemoryUsage(pid);

      // imprimeArray(gapCodingArray);
      // save_to_file(arreglo, distribucionNombre+".txt");

      // Libera la memoria del arreglo
      arreglo.clear();
      arreglo.shrink_to_fit();

      memory += stoi(getMemoryUsage(pid));
      // std::cout << "\nSe borró de memoria arregloLineal: " << memory;

      tiempo += medirTiempo(gapCodingArray, sampleArray, m, b, value); 
      // std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << tiempo << " segundos\n" << std::endl;
      // std::cout << "-------------------------------------------------------------------------\n" << std::endl;

    }, type);
  };
  for (size_t i = 0; i < 24; i++)
  {
    double tiempoLineal = 0.0, tiempoNormal = 0.0;
    int espacioLineal = 0, espacioNormal = 0;
    // Distribución Lineal
    // std::cout << "Inicia representacion 1: " << getMemoryUsage(pid);
    for (size_t i = 0; i < 20; i++){
      std::vector<int> arregloLineal = creaArregloLineal(n, epsilon);
      imprimirYMedir(arregloLineal, static_cast<unsigned char>(0), tiempoLineal, espacioLineal,  "DISTRIBUCION_LINEAL");
      // Distribución Normal
      // std::cout << "\nInicia representacion 2: " << getMemoryUsage(pid);
      std::vector<int> arregloNormal = generarArregloNormal(n, media, desviacionEstandar);
      imprimirYMedir(arregloNormal, int(), tiempoNormal, espacioNormal, "DISTRIBUCION_NORMAL");
    }
    tiempoLineal/=20;
    espacioLineal/=20;
    tiempoNormal/=20;
    espacioNormal/=20;
    guardarResultados("resGapCoding.csv", n, tiempoLineal, espacioLineal, tiempoNormal, espacioNormal);
    n *= 2;
    m = log2(n);
    b = n/m;
    media = n*(epsilon/2)/2;
    desviacionEstandar = n*(epsilon/2)/8;
  }
}