#pragma once

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

struct compare {
  bool operator()(nodeH* izq, nodeH* der) {
    return izq->frec > der->frec;
  }
};


