#include "../include/extraProg_3.h"

// Función que liberar la memoria 
void deleteHuffmanTree(nodeH* root) {
  if (root == nullptr) return;
  deleteHuffmanTree(root->izq);
  deleteHuffmanTree(root->der);
  delete root;
}

// Imprime vectores
void printVector(const std::vector<int>& vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i];
      if (i != vec.size() - 1) {
          std::cout << ", ";
      }
  }
  std::cout << "]" << std::endl;
}

// Lee archivo del gapCoding
std::vector<int> readFile(const std::string& file) {
  std::vector<int> datos;
  std::ifstream archivo(file);

  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo: " << file<< std::endl;
    return datos; 
  }

  int valor;
  while (archivo >> valor) {
    datos.push_back(valor);
  }
  archivo.close();

  return datos;
}

void writeToFile(const std::string& fileName, const std::vector<int>& data) {
  std::ofstream outFile(fileName);
  if (!outFile.is_open()) {
    std::cerr << "Error al abrir el archivo para escribir: " << fileName << std::endl;
    return;
  }
  for (int num : data) {
    outFile << num << ","; // Escribe cada número seguido de un espacio
  }
  outFile.close();
}

// Función para calcular los bits necesarios para cada elemento
std::vector<int> calcularBits(const std::vector<int>& huffmanCodesInt) {
  std::vector<int> bitsArray;
  for (int num : huffmanCodesInt) {
    int bits = 0;
    if (num != 0) {
      bits = std::bitset<sizeof(num) * 8>(num).to_string().find('1') + 1;
    }
    bitsArray.push_back(bits);
  }
  return bitsArray;
}

// Función para escribir los bits en un archivo
void escribirBitsEnArchivo(const std::vector<int>& bitsArray, const std::string& fileName) {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir: " << fileName << std::endl;
        return;
    }
    for (int bits : bitsArray) {
        outFile << bits << std::endl;
    }
    outFile.close();
}

int buscarEnArbolHuffman(const std::vector<int>& bitsComprimidos, HuffmanNode* raiz) {
    HuffmanNode* nodoActual = raiz;

    for (int bit : bitsComprimidos) {
        if (bit == 0 && nodoActual->izquierdo != nullptr) {
            nodoActual = nodoActual->izquierdo;
        } else if (bit == 1 && nodoActual->derecho != nullptr) {
            nodoActual = nodoActual->derecho;
        }

        if (nodoActual->esHoja()) {
            return nodoActual->valor;
        }
    }
    return -1;  
}
