import matplotlib.pyplot as plt
from PIL import Image

# Leer los datos del archivo CSV
sizes = []
times_lineal = []
times_normal = []
space_lineal = []
space_normal = []

try:
    with open('resGapCoding.csv', 'r') as file:
        for line in file:
            size, time_lineal, space_l, time_normal, space_n = line.strip().split(',')
            sizes.append(int(size))
            times_lineal.append(float(time_lineal))
            times_normal.append(float(time_normal))
            space_lineal.append(float(space_l))
            space_normal.append(float(space_n))
except FileNotFoundError:
    print("El archivo 'resGapCoding.csv' no se encontró.")
    exit(1)
except ValueError:
    print("El archivo 'resGapCoding.csv' tiene un formato incorrecto.")
    exit(1)

# Crear la gráfica para tiempos de búsqueda
plt.figure(figsize=(10, 6))
plt.plot(sizes, times_lineal, label='Tiempo representaciones del arreglo con distribucion Lineal', marker='o')
plt.plot(sizes, times_normal, label='Tiempo representaciones del arreglo con distribucion Normal', marker='o')
plt.title('Tiempos de Búsqueda Binaria')
plt.xlabel('Tamaño del Arreglo')
plt.ylabel('Tiempo (segundos)')
# plt.xscale('log')  # Escala logarítmica en el ejeL x
plt.yscale('log')  # Escala logarítmica en el eje y
plt.legend()
plt.grid(True, which="both", ls="--")
plt.savefig('GraficoGapCoding_tiempoLogaritmico.png')  # Guardar como imagen
plt.close()

# Crear la gráfica para espacios utilizados en kilobytes
plt.figure(figsize=(10, 6))
plt.plot(sizes, space_lineal, label='Espacio arreglos GC Y S de distribucion Lineal (KB)', marker='o', linestyle='-')
plt.plot(sizes, space_normal, label='Espacio arreglos GC Y S de distribucion Normal (KB)', marker='o', linestyle='-')
plt.title('Espacios Utilizados por los Arreglos')
plt.xlabel('Tamaño del Arreglo')
plt.yscale('log')  # Escala logarítmica en el eje y
# plt.xscale('log')  # Escala logarítmica en el eje x
plt.legend()
plt.grid(True, which="both", ls="--")
plt.savefig('GraficoGapCoding_espacioLogaritmico.png')  # Guardar como imagen
plt.close()
