#include "gapPacked_Array.h"
#include <iostream>
#include <queue>
#include <unordered_map>

// Función que compara las frecuencias de los nodos        
bool compareNodes(nodeH* a, nodeH* b){   
  if (a->frec > b->frec) 
    return true;
  return false;
}

// Construye el árbol de Huffman
nodeH* HuffmanTree(const std::vector<int>& frecs){    
  std::priority_queue<nodeH*, std::vector<nodeH*>, decltype(&compareNodes)> minHeap(&compareNodes);
  
  for (int i = 0; i < frecs.size(); ++i) {  // Crea nodos para cada char con frec>0 y lo pone en el queue
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

// Función que liberar la memoria 
void deleteHuffmanTree(nodeH* root) {
  if (!root) return;
  deleteHuffmanTree(root->izq);
  deleteHuffmanTree(root->der);
  delete root;
}

int main(){
  nodeH* root = HuffmanTree(frecs);
  
  std::unordered_map<char, std::string> huffmanCodes;
  
  generateHuffmanCodes(root, "", huffmanCodes);

  deleteHuffmanTree(root);

  return EXIT_SUCCESS;
}
