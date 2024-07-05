#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <variant>

using TipoVariant = std::variant<unsigned char, short, int>;

template <typename T>
void imprimeArray(std::vector<T>& v);

TipoVariant retornaTipo(int primerValor);

bool convertirArgumentos(int argc, const char* argv[], int& n, int& m, int& value);