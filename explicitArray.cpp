#include "include/explicitArray.h"
#include "include/creacionProg_1.h"
#include "include/busquedaProg_1.h"
#include "prog_2/include/pruebaMemoria.hpp"

#include <fstream>

using namespace std;

string getMemoryUsage(pid_t pid) {
  ifstream statusFile("/proc/" + to_string(pid) + "/status");
  string line;
size_t start, end;
  while (getline(statusFile, line)) {
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
void guardarResultados(const string& filename, size_t n, double tiempoLineal, double tiempoNormal, double espacioLineal, double espacioNormal) {
    ofstream file;
    file.open(filename, ios::app);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }
    file << n << "," << fixed << setprecision(10) << tiempoLineal << "," << espacioLineal << "," << tiempoNormal << "," << espacioNormal << endl;
    file.close();
}


int main(int argc, char *argv[]) {
    // Verificar que se proporcionen los argumentos correctos
    pid_t pid = getpid();
    if (argc < 1) {
        cout << "Uso: " << argv[0] << " <size>" << endl;
        return EXIT_FAILURE;
    }
    cout << "Memory usage for PID " << pid << ":\n" << endl;  
    // Obtener los valores de size y epsilon desde los argumentos
    size_t size = atoi(argv[1]);
    int epsilon = 20;
    double media = size*(epsilon/2)/2;
    double desviacionEstandar = size*(epsilon/2)/8;
    srand(time(0)); // Inicializa la semilla para rand()
    for (int i=0;i<24;i++)
    {
      /// Inicializar y crear el arreglo lineal
      vector<int> arrayLineal = creaArregloLineal(size, epsilon);

      // Medir el tiempo de búsqueda en el arreglo lineal
      double tarrayLineal = 0;
      for (size_t i = 0; i < 20; i++)
      {
        int numeroLineal = arrayLineal[rand() % size]; // Número a buscar
        tarrayLineal += medirTiempo(arrayLineal, numeroLineal); // Inicia búsqueda binaria y mide el tiempo
      }
      tarrayLineal/=20;
      // cout << "Numero del array a buscar: " << numeroLineal <<endl; 
      cout <<"Binary Search en Array lineal de largo " << size 
              << " tarda: " << fixed << setprecision(10) << tarrayLineal << " segundos" << endl;
      // Liberar la memoria del arreglo lineal

      int memoryArrLineal = stoi(getMemoryUsage(pid));
      arrayLineal.clear();
      arrayLineal.shrink_to_fit();
      
      // Inicializar y crear el arreglo normal
      vector<int> arrayNormal = generarArregloNormal(size, media, desviacionEstandar);
      double tarrayNormal = 0;
      // Medir el tiempo de búsqueda en el arreglo normal
      for (size_t i = 0; i < 20; i++)
      {
        int numeroNormal = arrayNormal[rand() % size]; // Número a buscar
        tarrayNormal += medirTiempo(arrayNormal, numeroNormal); // Inicia búsqueda binaria y mide el tiempo
      }
      tarrayNormal/=20;
      // cout << "Numero del array a buscar: " << numeroNormal <<endl; 
      cout << "Binary Search en Array normal de largo " << size 
              << " tarda: " << fixed << setprecision(10) << tarrayNormal << " segundos" << endl;
      int memoryArrNormal = stoi(getMemoryUsage(pid));
      arrayNormal.clear();
      arrayNormal.shrink_to_fit();
      size *= 2;
      guardarResultados("resExplicit.csv", size, tarrayLineal, tarrayNormal,memoryArrLineal,memoryArrNormal );
    }
    return EXIT_SUCCESS;
}