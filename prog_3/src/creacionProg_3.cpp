#include "../include/creacionProg_3.h"

// Construye el árbol de Huffman    
nodeH* HuffmanTree(const std::vector<int>& frecs){     
  std::priority_queue<nodeH*, std::vector<nodeH*>, decltype(&compareNodes)> minHeap(&compareNodes);
  
  for (size_t i = 0; i < frecs.size(); ++i) {  // Crea nodos para cada char con frec>0 y lo pone en el queue
    if (frecs[i] > 0) 
      minHeap.push(createNode(static_cast<char>(i), frecs[i]));
  }

  while (minHeap.size() > 1){ 
    nodeH* izq = minHeap.top();
    minHeap.pop();
    nodeH* der = minHeap.top();
    minHeap.pop();
    nodeH* newNode = createNode('\0', izq->frec + der->frec);
    newNode->izq = izq;
    newNode->der = der;
    minHeap.push(newNode);
  }

  if (!minHeap.empty()) {
    return minHeap.top();
  }else {
    return nullptr; // Cola vacia
  }
}

// Crea los nodos del árbol
nodeH* createNode(char data, int frec) {
    nodeH* newNode = new nodeH(data, frec);
    return newNode;
}

// Función que genera los códigos de Huffman
void generateHuffmanCodes(nodeH* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes) { 
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
