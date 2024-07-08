#include "include/gapPacked_Array.h"
#include "include/extraProg_3.h"
#include "include/creacionProg_3.h"

int main() {
  
  std::vector<int> gapCodingArray = readFile("DISTRIBUCION_LINEAL.txt"); // Llama a la función para leer datos desde archivo

  std::vector<int> frecs(256, 0); // Vector para las frecuencias de los caracteres
  
  for (char ch : gapCodingArray) { // Llena el vector frecs con las frecuencias de los caracteres según tus datos
    frecs[ch]++;
  }

  nodeH* root = HuffmanTree(frecs); // Construcción del árbol de Huffman
  
  std::unordered_map<char, std::string> huffmanCodes; // Mapa para los códigos Huffman
  generateHuffmanCodes(root, "", huffmanCodes); // Generación de los códigos Huffman
  
  std::vector<int> huffmanCodesInt;

  for (const auto& pair : huffmanCodes) {  
    const std::string& binaryCode = pair.second; 
    int intValue = std::stoi(binaryCode, nullptr, 2); // Convierte bin en int
    huffmanCodesInt.push_back(intValue); // Almacena en vector huffmanCodesInt
    std::cout << pair.first << ": bin = " << binaryCode << " int = " << intValue << std::endl;
  }
  printVector(huffmanCodesInt);

  deleteHuffmanTree(root); // Liberar la memoria del árbol de Huffman
  return EXIT_SUCCESS;
}
