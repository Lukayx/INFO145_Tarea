#include "include/gapPacked_Array.h"
#include "include/extraProg_3.h"
#include "include/creacionProg_3.h"

int main() {
  srand(time(0));               
  size_t size = 100000000;      // Tamaño del arreglo lineal
  int epsilon = 10;  

  std::vector<int> gapCodingArray; // Creación de los arreglos
  creaArreglos(gapCodingArray, size, epsilon);
  
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