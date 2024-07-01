// Creación del arreglo con distribución lineal
std::vector<int> crearArrayLineal(size_t size, int epsilon) {
  std::vector<int> array;
  if(n > 0){
    array.push_back(rand() % 100); // Primer elemento
    for (size_t i = 1; i < size; ++i) {
      array.push_back(array.back() + rand() % epsilon);
    }
  } else {
    printf("No se pudo crear el Arreglo Lineal porque n = %d no es mayor que 0\n", n);
    exit(0);
  }    
  return array;
}

// Generar un arreglo con distribución normal
std::vector<int> generarArregloNormal(size_t n, double media, double desviacionEstandar) {
  std::normal_distribution<double> distribucion(media, desviacionEstandar);

  std::vector<int> array(n);
  for (size_t i = 0; i < n; ++i) {
      array[i] = static_cast<int>(distribucion(generador)); // Generar valores con distribución normal
  }

  sort(array.begin(), array.end()); // Ordenar el arreglo
  return array;
}


