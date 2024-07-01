#include "gapCodingArray.h"

const int EPSILON = 30;

int main(int argc, const char* argv[]){
  int n, m, b, value;

  if (!convertirArgumentos(argc, argv, n, m, value)) {
    return EXIT_FAILURE;
  }

  srand(time(0));// semilla para los números aleatorios
  std::random_device rd;
  std::mt19937 generador(rd());

  double media = (n * EPSILON) / 2.0;
  double desviacionEstandar = EPSILON;
  b = n/m;

  //A PARTIR DE AQUI COMIENZA A CREAR LOS ARREGLOS Y BUSCAR EL VALOR
  creaArreglos(n, m, b, media, desviacionEstandar, value, generador);

  return EXIT_SUCCESS;
}

// creacion del arreglo con distribución lineal
std::vector<int> creaArregloLineal(int n, std::mt19937& generador) {
  std::vector<int> array;
  if(n > 0){
    array.push_back(rand() % 100); //primer elemento

    for (int i = 1; i < n; ++i) 
    {
      array.push_back(array.back() + rand() % EPSILON);//agrega siguiente elemento con una diferencia de 0 a EPSILON
    }
  } else {
    printf("No se pudo crear el Arreglo Lineal porque n = %d no es mayor que 0\n", n);
    exit(0);
  }

  return array;
}

std::vector<int> generarArregloNormal(size_t n, double media, double desviacionEstandar, std::mt19937& generador) {
  std::normal_distribution<double> distribucion(media, desviacionEstandar);
  
  std::vector<int> array(n);
  for (size_t i = 0; i < n; ++i) {
      array[i] = static_cast<int>(distribucion(generador)); // Generar valores con distribución normal
  }
  sort(array.begin(), array.end()); // Ordenar el arreglo
  return array;
}

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
  for (int i = 0; i < m; i++)
  {
    sampleArray.push_back(arregloLineal[i*b]); // agrega elementos a sampleArray de acuerdo al espaciado especificado anteriormente
  }
  return sampleArray;
}

void creaArreglos(int n, int m, int b, double media, double desviacionEstandar, int value, std::mt19937& generador){
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  {
    std::vector<int> arregloLineal = creaArregloLineal(n, generador);
    std::cout << "\nNumero a buscar: " <<  valor << std::endl;

    //REPRESENTACION DE DISTRIBUCION LINEAL
    std::vector<unsigned char> gapCodingArray1 = creaGapCoding(arregloLineal, n);
    std::vector<int> sampleArray1 = creaSample(arregloLineal, m, n, b);

    // Libera la memoria de arregloLineal
    arregloLineal.clear();
    arregloLineal.shrink_to_fit();

    std::cout << "_--------------------------DISTRIBUCION LINEAL--------------------------_\n" << std::endl;
    double distribucionLineal = medirTiempo(gapCodingArray1, sampleArray1, m, b, value);
    std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << distribucionLineal << " segundos\n" << std::endl;
  } // gapCodingArray1, y sampleArray1 se liberan aquí

  std::cout << "-------------------------------------------------------------------------" << std::endl;

  {
    std::vector<int> arregloNormal = generarArregloNormal(n, media, desviacionEstandar, generador);
    std::cout << "\nNumero a buscar: " <<  valor << std::endl;

    //REPRESENTACION DE DISTRIBUCION NORMAL
    std::vector<unsigned char > gapCodingArray2 = creaGapCoding(arregloNormal, n);
    std::vector<int> sampleArray2 = creaSample(arregloNormal, m, n, b);  

    // Libera la memoria de arregloNormal
    arregloNormal.clear();
    arregloNormal.shrink_to_fit();

    std::cout << "_--------------------------DISTRIBUCION NORMAL--------------------------_\n" << std::endl;
    double distribucionNormal = medirTiempo(gapCodingArray2, sampleArray2, m, b, value);
    std::cout << "Tiempo que tardó el Binary Search: " << std::fixed << std::setprecision(10) << distribucionNormal << " segundos\n" << std::endl;
  } // gapCodingArray2, y sampleArray2 se liberan aquí

  std::cout << "-------------------------------------------------------------------------" << std::endl;
}

int binarySearch(std::vector<int> sampleArray, int left, int right, int num, int b, std::vector<unsigned char> gapCoding){
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

int searchValor(std::vector<unsigned char> gapCoding, int valor, int indice, int num){ // valor esta justo donde el indice indica 
  if(valor == num) return indice; // si justo donde esta el indice es donde se encuentra num entonces devuelve el indice
  if(valor>num) // si el valor actual se encuentra por encima de num...
  { 
    while(indice > 0 && valor > num)//irá restando mientras el valor sea mayor que 0 y num
    { 
      valor = valor - gapCoding[indice]; // se calcula el valor del nuevo indice
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
      valor = valor + gapCoding[indice];// se calcula el valor del nuevo indice
      if(valor == num) return indice; // si valor es igual al del indice actual, entonces devuelve el indice
    }
  }
  return -1; // devuelve -1 si no logró encontrar el valor num
}

bool convertirArgumentos(int argc, const char* argv[], int& n, int& m, int& value){
  if (argc <= 3) {
      std::cerr << "Insuficientes argumentos." << std::endl;
      return false;
  }
  
  try {
      n = std::stoi(argv[1]);
      m = std::stoi(argv[2]);
      value = std::stoi(argv[3]);
      if(m == 0) {
        std::cout << "M debe ser mayor que 0" << std::endl;
        return false;
      }
  } catch (const std::invalid_argument& e) {
      std::cerr << "Error: Argumentos inválidos." << std::endl;
      return false;
  } catch (const std::out_of_range& e) {
      std::cerr << "Error: Argumentos fuera de rango." << std::endl;
      return false;
  }
  
  return true;
}

double medirTiempo(std::vector<unsigned char> gapCodingArray, std::vector<int> sampleArray, int m, int b, int value){
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

void imprimeArray(std::vector<int> v){
  for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << "  ";
  std::cout << "\n\n";
}