#include <fstream>
#include <vector>
#include <string>

// Función para guardar números en un archivo
template <typename t>
void save_to_file(const std::vector<t>& numbers, const std::string& filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (t num : numbers) {
      file << (int)num << '\n';
    }
    // file << (int)numbers[numbers.size()-1] << '\n';
    file.close();
  } else {
    std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
  }
}