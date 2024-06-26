#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

std::vector<int> creaArregloLineal(int n);
std::vector<int> creaGapCoding(std::vector<int> arregloLineal);
std::vector<int> creaSample(std::vector<int> arregloLineal, int m, int b);
void creaArreglos(std::vector<int> &gapCodingArray, std::vector<int> &sampleArray, int n, int m, int b);
int binarySearch(std::vector<int> sampleArray, int left, int right, int num, int b, std::vector<int> gapCoding);
int searchValor(std::vector<int> gapCoding, int valor, int indice, int num);
void imprimeArray(std::vector<int> v);