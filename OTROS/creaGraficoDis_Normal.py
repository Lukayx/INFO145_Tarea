import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# Función para leer los datos desde el archivo en partes
def read_from_file_in_batches(filename, batch_size=1000000):
    with open(filename, 'r') as file:
        batch = []
        for line in file:
            batch.append(int(line.strip()))
            if len(batch) >= batch_size:
                yield batch
                batch = []
        if batch:
            yield batch

# Lista de archivos a procesar
filenames = ['DISTRIBUCION_NORMAL.txt']  # Añade más nombres de archivos según sea necesario

# Definir manualmente la media y desviación estándar
n = input("Introduce el valor de n: ")

try:
    n = int(n)
except ValueError:
    print("El valor ingresado para n no es válido. Debe ser un número entero.")
    exit()

epsilon = 20
mu_manual = (n / 2) * epsilon/2  # INT_MAX / 2
std_manual = (n / 8) * epsilon/2  # Ajusta esto según sea necesario

for filename in filenames:
    # Inicializar el histograma acumulado
    histogram_accum = np.zeros(30)  # Usaremos 30 bins
    total_count = 0

    # Leer los datos del archivo en partes y acumular el histograma
    for batch in read_from_file_in_batches(filename):
        total_count += len(batch)
        hist, _ = np.histogram(batch, bins=30, range=(0, n*10))
        histogram_accum += hist

    # Normalizar el histograma acumulado
    histogram_accum = histogram_accum / total_count

    # Crear el gráfico de distribución normal
    plt.figure(figsize=(10, 6))
    bin_edges = np.linspace(0, n*10, 31)  # Edges of the bins
    bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2
    plt.bar(bin_centers, histogram_accum, width=bin_edges[1] - bin_edges[0], alpha=0.6, color='g')

    # Calcular y graficar la curva de densidad de probabilidad normal usando la media y desviación estándar manuales
    x = np.linspace(0, n*10, 100)
    p = np.exp(-0.5 * ((x - mu_manual) / std_manual) ** 2) / (std_manual * np.sqrt(2 * np.pi))
    plt.plot(x, p, 'k', linewidth=2)

    title = f"Histograma y curva de densidad de una distribución normal\n$\mu={mu_manual:.2f}$, $\sigma={std_manual:.2f}$"
    plt.title(title)
    plt.xlabel('Valor')
    plt.ylabel('Densidad de Probabilidad')
    plt.grid(True)

    # Guardar el gráfico como una imagen
    output_image = f'distribucion_normal_{filename[:-4]}.png'  # Generar nombre de archivo basado en el nombre de entrada
    plt.savefig(output_image)

    # Mostrar la imagen
    img = Image.open(output_image)
    img.show()

    # Cerrar la figura para evitar que se acumulen
    plt.close()
