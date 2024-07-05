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
      if(m <= 0 || m >= n) {
        std::cout << "m debe estar dentro del rango [1, n-1]" << std::endl;
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

template<typename T>
void imprimeArray(std::vector<T>& v){
  for (size_t i = 0; i < v.size(); i++)
    std::cout << static_cast<int>(v[i]) << "  ";
  std::cout << "\n\n";
}

TipoVariant retornaTipo(int primerValor){ // en base al primerValor retorna el tipo de dato adecuado
  if(primerValor <= std::numeric_limits<unsigned char>::max()) {
    return static_cast<unsigned char>(0);
  } else if (primerValor <= std::numeric_limits<short>::max()) {
    return short();
  } else {
    return int();
  }
}


void declaraTipos1(){ //declara los tipos de datos que hay para cada template
  std::vector<unsigned char> a;
  std::vector<short> b;
  std::vector<int> c;
  imprimeArray(a);
  imprimeArray(b);
  imprimeArray(c);
}