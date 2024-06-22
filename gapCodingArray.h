#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

std::vector<int> creaArregloLineal(size_t size, int epsilon);
std::vector<int> creaGapCoding(std::vector<int> arregloLineal);
std::vector<int> creaSample(std::vector<int> arregloLineal, int m);
void creaArreglos(std::vector<int> &gapCodingArray, std::vector<int> &sampleArray, size_t size, int epsilon, int m);
void imprimeArray(std::vector<int> v);