#pragma once

#include "struct.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>

void deleteHuffmanTree(nodeH* root); // Libera la memoria del árbol de Huffman
void printVector(const std::vector<int>& vec); // Imprime vector
std::vector<int> readFile(const std::string& file); // Lee archivo txt
void writeToFile(const std::string& fileName, const std::vector<int>& data); // Crea un archivo compressed_array.txt 
std::vector<int> calcularBits(const std::vector<int>& huffmanCodesInt); // Función para calcular los bits necesarios para cada elemento
void escribirBitsEnArchivo(const std::vector<int>& bitsArray, const std::string& fileName); // Funcion que escribe los bits del array comprimido
