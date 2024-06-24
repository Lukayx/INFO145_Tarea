#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

std::vector<int> creaArregloLineal(size_t size, int epsilon);
std::vector<int> creaGapCoding(std::vector<int> arregloLineal);
std::vector<int> creaSample(std::vector<int> arregloLineal, int m, int b);
void creaArreglos(std::vector<int> &gapCodingArray, std::vector<int> &sampleArray, size_t size, int epsilon, int m, int b);
int binarySearch(std::vector<int> sample, int left, int right, int x, int b, std::vector<int> gapCoding);
int searchX(std::vector<int> gapCoding, int valor, int indice, int x);
void imprimeArray(std::vector<int> v);