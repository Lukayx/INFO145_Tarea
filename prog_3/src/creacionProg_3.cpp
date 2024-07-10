#include "../include/creacionProg_3.h"

// Construye el árbol de Huffman    
nodeH* HuffmanTree(const std::unordered_map<int, int>& frecs){     
  std::priority_queue<nodeH*, std::vector<nodeH*>, compare> minHeap;
  
  for (auto& pair : frecs) {
    minHeap.push(createNode(static_cast<char>(pair.first), pair.second));
  }

  while (minHeap.size() != 1) {
    nodeH* izq = minHeap.top();
    minHeap.pop();

    nodeH* der = minHeap.top();
    minHeap.pop();

    int combinedFrec = izq->frec + der->frec;
    nodeH* newNode = createNode('\0', combinedFrec);

    newNode->izq = izq;
    newNode->der = der;

    minHeap.push(newNode);
  }
   return minHeap.top();
}

// Crea los nodos del árbol
nodeH* createNode(char data, int frec) {
  return new nodeH(data, frec);
}

// Función que genera los códigos de Huffman
void generateHuffmanCodes(nodeH* root, std::string code, std::unordered_map<int, std::string>& huffmanCodes) { 
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
