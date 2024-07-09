#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <variant>
#include <sys/resource.h>

using TipoVariant = std::variant<unsigned char, short, int>;

template <typename T>
void imprimeArray(std::vector<T>& v);

void obtener_y_mostrar_memoria(std::string nombre_etiqueta);

template <typename t>
void save_to_file(const std::vector<t>& numbers, const std::string& filename);

bool convertirArgumentos(int argc, const char* argv[], int& n, int& m);