#pragma once

#include <iostream>
#include <vector>
#include <chrono> // Necesario para std::chrono y medir tiempos

template <typename T>
int binarySearch(std::vector<int>& sampleArray, int left, int right, int num, int b, std::vector<T>& gapCoding);

template <typename T>
int searchValor(std::vector<T>& gapCoding, int valor, int indice, int num);

template <typename T>
double medirTiempo(std::vector<T>& gapCodingArray, std::vector<int>& sampleArray, int m, int b, int value);