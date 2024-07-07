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
