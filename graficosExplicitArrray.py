import matplotlib.pyplot as plt
from PIL import Image

# Leer los datos del archivo CSV
sizes = []
times_lineal = []
times_normal = []

try:
    with open('resExplicit.csv', 'r') as file:
        for line in file:
            size, time_lineal, time_normal = line.strip().split(',')
            sizes.append(int(size))
            times_lineal.append(float(time_lineal))
            times_normal.append(float(time_normal))
except FileNotFoundError:
    print("El archivo 'resExplicit.csv' no se encontró.")
    exit(1)
except ValueError:
    print("El archivo 'resExplicit.csv' tiene un formato incorrecto.")
    exit(1)
# Crear la gráfica
plt.figure(figsize=(10, 6))
plt.plot(sizes, times_lineal, label='Tiempo Lineal', marker='o')
plt.plot(sizes, times_normal, label='Tiempo Normal', marker='o')

# Añadir título y etiquetas
plt.title('Tiempos de Búsqueda Binaria')
plt.xlabel('Tamaño del Arreglo')
plt.ylabel('Tiempo (segundos)')
plt.legend()


# Guardar el gráfico como una imagen
output_image = f'Grafico1.png'  # Generar nombre de archivo basado en el nombre de entrada
plt.savefig(output_image)

    # Mostrar la imagen
img = Image.open(output_image)
img.show()

    # Cerrar la figura para evitar que se acumulen
plt.close()
