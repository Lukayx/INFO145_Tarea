#pragma once

#include <iostream>
#include <vector>
#include <chrono> // Necesario para std::chrono y medir tiempos

int binarySearch(std::vector<int> sampleArray, int left, int right, int num, int b, std::vector<unsigned char> gapCoding);
int searchValor(std::vector<unsigned char> gapCoding, int valor, int indice, int num);
double medirTiempo(std::vector<unsigned char> gapCodingArray, std::vector<int> sampleArray, int m, int b, int value);
