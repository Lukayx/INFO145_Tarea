#pragma once

#include "struct.h"
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

nodeH* HuffmanTree(const std::vector<int>& frecs); // Funcion que construye el árbol de Huffman
nodeH* createNode(char data, int frec); // Función que crea los nodos del árbol de Huffman
void generateHuffmanCodes(nodeH* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes); // Funcion que genera los códigos de Huffman
bool compareNodes(nodeH* a, nodeH* b); // Función que compara las frecs de nodos
