#include <iostream>
#include <climits>
#include <cfloat>

int main() {
    std::cout << "Valores máximos y mínimos de los tipos numéricos en C++:\n\n";
    
    // Tipos de datos enteros
    std::cout << "char:\n";
    std::cout << "  Mínimo: " << CHAR_MIN << "\n";
    std::cout << "  Máximo: " << CHAR_MAX << "\n\n";

    std::cout << "unsigned char:\n";
    std::cout << "  Máximo: " << UCHAR_MAX << "\n\n";

    std::cout << "short:\n";
    std::cout << "  Mínimo: " << SHRT_MIN << "\n";

    std::cout << "  Máximo: " << SHRT_MAX << "\n\n";
    std::cout << "unsigned short:\n";
    std::cout << "  Máximo: " << USHRT_MAX << "\n\n";

    std::cout << "int:\n";
    std::cout << "  Mínimo: " << INT_MIN << "\n";
    std::cout << "  Máximo: " << INT_MAX << "\n\n";

    std::cout << "unsigned int:\n";
    std::cout << "  Máximo: " << UINT_MAX << "\n\n";

    std::cout << "long:\n";
    std::cout << "  Mínimo: " << LONG_MIN << "\n";
    std::cout << "  Máximo: " << LONG_MAX << "\n\n";

    std::cout << "unsigned long:\n";
    std::cout << "  Máximo: " << ULONG_MAX << "\n\n";

    std::cout << "long long:\n";
    std::cout << "  Mínimo: " << LLONG_MIN << "\n";
    std::cout << "  Máximo: " << LLONG_MAX << "\n\n";

    std::cout << "unsigned long long:\n";
    std::cout << "  Máximo: " << ULLONG_MAX << "\n\n";

    // Tipos de datos de punto flotante
    std::cout << "float:\n";
    std::cout << "  Mínimo: " << FLT_MIN << "\n";
    std::cout << "  Máximo: " << FLT_MAX << "\n\n";

    std::cout << "double:\n";
    std::cout << "  Mínimo: " << DBL_MIN << "\n";
    std::cout << "  Máximo: " << DBL_MAX << "\n\n";

    std::cout << "long double:\n";
    std::cout << "  Mínimo: " << LDBL_MIN << "\n";
    std::cout << "  Máximo: " << LDBL_MAX << "\n\n";

    return 0;
}