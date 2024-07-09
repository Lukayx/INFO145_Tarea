import matplotlib.pyplot as plt
from PIL import Image

# Leer los datos del archivo CSV
sizes = []
times_lineal = []
times_normal = []
space_lineal = []
space_normal = []

try:
    with open('resExplicit.csv', 'r') as file:
        for line in file:
            size, time_lineal, space_l, time_normal, space_n = line.strip().split(',')
            sizes.append(int(size))
            times_lineal.append(float(time_lineal))
            times_normal.append(float(time_normal))
            space_lineal.append(float(space_l))
            space_normal.append(float(space_n))
except FileNotFoundError:
    print("El archivo 'resExplicit.csv' no se encontró.")
    exit(1)
except ValueError:
    print("El archivo 'resExplicit.csv' tiene un formato incorrecto.")
    exit(1)

# Crear la gráfica para tiempos de búsqueda
plt.figure(figsize=(10, 6))
plt.plot(sizes, times_lineal, label='Tiempo Arreglo Lineal', marker='o')
plt.plot(sizes, times_normal, label='Tiempo Arreglo Normal', marker='o')
plt.title('Tiempos de Búsqueda Binaria')
plt.xlabel('Tamaño del Arreglo')
plt.ylabel('Tiempo (segundos)')
plt.yscale('log') 
plt.legend()
plt.grid(True)
plt.savefig('GraficosAExplicitos_tiempos_busqueda_Explicit.png')  # Guardar como imagen
plt.close()

# Crear la gráfica para espacios utilizados en kilobytes
plt.figure(figsize=(10, 6))
plt.plot(sizes, space_lineal, label='Espacio Arreglo Lineal (KB)', marker='o', markersize=4, linestyle='-')
plt.plot(sizes, space_normal, label='Espacio Arreglo Normal (KB)', marker='o', markersize=4, linestyle='-')
plt.title('Espacios Utilizados por los Arreglos')
plt.xlabel('Tamaño del Arreglo')
plt.ylabel('Espacio (KB)')
plt.yscale('log') 
plt.legend()
plt.grid(True)
plt.savefig('GraficosAExplicitos_espacios_utilizados.png')  # Guardar como imagen
plt.close()