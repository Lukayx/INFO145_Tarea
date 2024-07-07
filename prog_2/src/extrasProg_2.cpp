#include "../include/extrasProg_2.h"

bool convertirArgumentos(int argc, const char* argv[], int& n, int& m){
  if (argc <= 2) {
      std::cerr << "Insuficientes argumentos." << std::endl;
      return false;
  }
  
  try {
      n = std::stoi(argv[1]);
      m = std::stoi(argv[2]);
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

// Función para guardar números en un archivo
template <typename t>
void save_to_file(const std::vector<t>& numbers, const std::string& filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (t num : numbers) {
      file << (int)num << '\n';
    }
    file.close();
  } else {
    std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
  }
}

template<typename T>
void imprimeArray(std::vector<T>& v){
  for (size_t i = 0; i < v.size(); i++)
    std::cout << static_cast<int>(v[i]) << "  ";
  std::cout << "\n\n";
}

void declaraTipos1(){ //declara los tipos de datos que hay para cada template
  std::vector<unsigned char> a;
  std::vector<short> b;
  std::vector<int> c;
  std::string text = "text";
  imprimeArray(a);
  imprimeArray(b);
  imprimeArray(c);
  save_to_file(a, text);
  save_to_file(b, text);
  save_to_file(c, text);
}