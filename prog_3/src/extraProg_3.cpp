#include "../include/extraProg_3.h"

// Función que liberar la memoria 
void deleteHuffmanTree(nodeH* root) {
  if (root == nullptr) return;
  deleteHuffmanTree(root->izq);
  deleteHuffmanTree(root->der);
  delete root;
}

// Imprime vector
void printVector(const std::vector<int>& vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i];
      if (i != vec.size() - 1) {
          std::cout << ", ";
      }
  }
  std::cout << "]" << std::endl;
}

// Lee archivo del gapCoding
std::vector<int> readFile(const std::string& file) {
  std::vector<int> datos;
  std::ifstream archivo(file);

  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo: " << file<< std::endl;
    return datos; 
  }

  int valor;
  while (archivo >> valor) {
    datos.push_back(valor);
  }
  archivo.close();

  return datos;
}
