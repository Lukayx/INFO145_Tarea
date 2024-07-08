#pragma once

#include "struct.h"
#include <vector>
#include <iostream>
#include <fstream>

void deleteHuffmanTree(nodeH* root); // Libera la memoria del árbol de Huffman
void printVector(const std::vector<int>& vec); // Imprime vector
std::vector<int> readFile(const std::string& file); //lee archivo 
