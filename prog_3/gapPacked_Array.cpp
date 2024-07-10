#include "include/gapPacked_Array.h"
#include "include/extraProg_3.h"
#include "include/creacionProg_3.h"

int main() {

  std::vector<int> gapCodingArray = readFile("DISTRIBUCION_LINEAL1.txt"); // Llama a la función para leer datos desde archivo

  std::unordered_map<int, int> frecs; 
  for (int num : gapCodingArray) {  // Llena el mapa frecs con las frecuencias de los enteros dek gapCodingArray
    frecs[num]++;
  }

  nodeH* root = HuffmanTree(frecs); // Construye del árbol de Huffman
  
  std::unordered_map<int, std::string> huffmanCodes; // Generación de los códigos Huffman
  generateHuffmanCodes(root, "", huffmanCodes); 

  std::unordered_map<int, int> huffmanCodesIntMap;  // Almacena 
  std::unordered_map<int, int> huffmanCodeLengths;  

  std::vector<int> huffmanCodesInt;
  for (const auto& pair : huffmanCodes) {  
    const std::string& binaryCode = pair.second; 
    int intValue = std::stoi(binaryCode, nullptr, 2); // Convierte bin en int
    huffmanCodesIntMap[pair.first] = intValue;
    huffmanCodeLengths[pair.first] = binaryCode.length();
    huffmanCodesInt.push_back(intValue);  // Almacena en vector huffmanCodesInt
    std::cout << pair.first << ": bin = " << binaryCode << " int = " << intValue << std::endl;
  }

  std::vector<int> compressedArray; 
  int originalBits = 0;
  int compressedBits = 0; 
  
  printVector(huffmanCodesInt);

  for (int num : gapCodingArray) {
    compressedArray.push_back(huffmanCodesInt[num]);
    originalBits += 32; // Suma bits gapCodingArray
    compressedBits += huffmanCodeLengths[num]; // Suma bits compressedArray
  }
  
  writeToFile("compressed_array.txt", compressedArray); // Escribe el arreglo comprimido a un archivo de texto

  std::cout << "Bits gapCodingArray: " << originalBits << std::endl;  
  std::cout << "Bits compressedArray: " << compressedBits << std::endl;

  std::vector<int> bitsArray = calcularBits(huffmanCodesInt);// Calcular los bits necesarios para cada elemento
  escribirBitsEnArchivo(bitsArray, "bits_huffmanCodesInt.txt");
  
  std::vector<int> bitsComprimidos = {0, 1, 1, 0, 1};  
  int valorDecodificado = buscarEnArbolHuffman(bitsComprimidos, raizHuffman);

  if (valorDecodificado != -1) {
      std::cout << "Valor decodificado: " << valorDecodificado << std::endl;
  } else {
      std::cout << "Valor no encontrado en el árbol de Huffman." << std::endl;
  }

  
  deleteHuffmanTree(root); // Liberar la memoria del árbol de Huffman
  std::cout << "Listo" << std::endl;

  std::ofstream bitsFile("bits_comparison.txt"); // Escribir la información de bits a un archivo para análisis en Python
  if (bitsFile.is_open()) {
    bitsFile << "OriginalBits CompressedBits\n";
    bitsFile << originalBits << " " << compressedBits << "\n";
    bitsFile.close();
  } else {
    std::cerr << "Error al abrir el archivo para escribir los bits." << std::endl;
  }

  return EXIT_SUCCESS;
}
