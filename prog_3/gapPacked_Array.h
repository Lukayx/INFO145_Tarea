#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

struct HuffmanNode{       
  char data;              // Data del nodo
  int frec;               // Frecuencia de aparicion del carácter
  HuffmanNode *izq, *der; // Punteros a los nodos hijos izquierdo y derecho

  HuffmanNode(char data, int frec){    // Constructor   
    this->data = data;
    this->frec = frec;
    this->izq = nullptr;
    this->der = nullptr;
  }
}; typedef struct HuffmanNode nodeH;

bool compareNodes(nodeH* a, nodeH* b); // Función que compara las frecs de nodos

nodeH* HuffmanTree(const std::vector<int>& frecs); // Funcion que construye el árbol de Huffman

void generateHuffmanCodes(nodeH* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes); // Funcion que genera los códigos de Huffman

void deleteHuffmanTree(nodeH* root); // Libera la memoria del árbol de Huffman

void creaArreglos(std::vector<int>& gapCodingArray, std::vector<int>& sampleArray, size_t size, int epsilon, int m, int b);
