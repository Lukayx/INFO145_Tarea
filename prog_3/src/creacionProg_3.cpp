#include "../include/creacionProg_3.h"

void creaArreglos(std::vector<int>& gapCodingArray, size_t size, int epsilon) {
  // Implementación de creaArreglos
  // Ejemplo básico
  gapCodingArray.push_back(rand() % 100); // Llenando gapCodingArray con algún valor de ejemplo
  for (size_t i = 1; i < size; ++i) {
    gapCodingArray.push_back(rand() * epsilon); // Llenando gapCodingArray con algún valor de ejemplo
  }
}

// Construye el árbol de Huffman
nodeH* HuffmanTree(const std::vector<int>& frecs){    
  std::priority_queue<nodeH*, std::vector<nodeH*>, decltype(&compareNodes)> minHeap(&compareNodes);
  
  for (size_t i = 0; i < frecs.size(); ++i) {  // Crea nodos para cada char con frec>0 y lo pone en el queue
    if (frecs[i] > 0) {
      minHeap.push(new nodeH(static_cast<char>(i), frecs[i]));
    }
  }

  while (minHeap.size() > 1){ // Se construye el arbol
    nodeH* izq = minHeap.top();
    minHeap.pop();
    nodeH* der = minHeap.top();
    minHeap.pop();
    nodeH* newNode = new nodeH('\0', izq->frec + der->frec); // Usamos '\0' para indicar que no es relevante
    newNode->izq = izq;
    newNode->der = der;
    minHeap.push(newNode);
  }
  return minHeap.top(); // Retorna raíz del árbol
}

void generateHuffmanCodes(nodeH* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes) { // Función que genera los códigos de Huffman
  if (!root) return;
  
  if (!root->izq && !root->der) // Si tiene hojas
    huffmanCodes[root->data] = code;

  generateHuffmanCodes(root->izq, code + "0", huffmanCodes);
  generateHuffmanCodes(root->der, code + "1", huffmanCodes);
}

// Función que compara las frecuencias de los nodos        
bool compareNodes(nodeH* a, nodeH* b){   
  if (a->frec > b->frec) 
    return true;
  return false;
}