#include "../include/extraProg_3.h"

// Función que liberar la memoria 
void deleteHuffmanTree(nodeH* root) {
  if (!root) return;
  deleteHuffmanTree(root->izq);
  deleteHuffmanTree(root->der);
  delete root;
}