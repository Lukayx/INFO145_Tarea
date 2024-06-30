#include "gapPacked_Array.h"
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(0));               
  size_t size = 100000000;      // Tamaño del arreglo lineal
  int m = 100;                  // Tamaño del sampleArray
  int epsilon = 10;  
  int b = size / m;

  std::vector<int> gapCodingArray, sampleArray; // Creación de los arreglos
  creaArreglos(gapCodingArray, sampleArray, size, epsilon, m, b);
  
  int valor_a_buscar = 83563; 
  std::cout << "Escriba el valor que quiere buscar: " << valor_a_buscar << std::endl;

  int indice = -1; // Temporalmente, porque la función buscarIndice no está definida

  std::cout << "El índice donde está ese valor es el " << indice << std::endl;

  
  std::vector<int> frecs(256, 0); // Supongamos que frecs es un vector de frecuencias de 256 caracteres posibles
  
  for (char ch : gapCodingArray) { // Llena el vector frecs con las frecuencias de los caracteres según tus datos
    frecs[ch]++;
  }

  nodeH* root = HuffmanTree(frecs); // Construcción del árbol de Huffman
  
  std::unordered_map<char, std::string> huffmanCodes; // Generación de los códigos Huffman
  generateHuffmanCodes(root, "", huffmanCodes);

  for (const auto& pair : huffmanCodes) { // Mostrar los códigos Huffman
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  deleteHuffmanTree(root); // Liberar la memoria del árbol de Huffman
  return EXIT_SUCCESS;
}
void creaArreglos(std::vector<int>& gapCodingArray, std::vector<int>& sampleArray, size_t size, int epsilon, int m, int b) {
    // Implementación de creaArreglos
    // Ejemplo básico
    for (size_t i = 0; i < size; ++i) {
        gapCodingArray.push_back(i * epsilon); // Llenando gapCodingArray con algún valor de ejemplo
        sampleArray.push_back(i % m); // Llenando sampleArray con algún valor de ejemplo
    }
}
// Función que compara las frecuencias de los nodos        
bool compareNodes(nodeH* a, nodeH* b){   
  if (a->frec > b->frec) 
    return true;
  return false;
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

// Función que liberar la memoria 
void deleteHuffmanTree(nodeH* root) {
  if (!root) return;
  deleteHuffmanTree(root->izq);
  deleteHuffmanTree(root->der);
  delete root;
}
