#include "../include/extrasProg_2.h"

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

void imprimeArray(std::vector<int> v){
  for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << "  ";
  std::cout << "\n\n";
}