#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono> // Necesario para std::chrono y medir tiempos
#include <iomanip> //este sirve para la subpresición del tiempo que tarda
#include <random>
#include <algorithm>

bool convertirArgumentos(int argc, const char* argv[], int& n, int& m, int& value);
std::vector<int> creaArregloLineal(int n, std::mt19937& generador);
std::vector<int> generarArregloNormal(size_t tamano, double media, double desviacionEstandar, std::mt19937& generador);
std::vector<unsigned char> creaGapCoding(std::vector<int> arregloLineal, int n);
std::vector<int> creaSample(std::vector<int> arregloLineal, int m, int n, int b);
void creaArreglos(int n, int m, int b, double media, double desviacionEstandar, int value, std::mt19937& generador);
int binarySearch(std::vector<int> sampleArray, int left, int right, int num, int b, std::vector<unsigned char> gapCoding);
int searchValor(std::vector<unsigned char> gapCoding, int valor, int indice, int num);
double medirTiempo(std::vector<unsigned char> gapCodingArray, std::vector<int> sampleArray, int m, int b, int value);
void imprimeArray(std::vector<int> v);