import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# Función para leer los datos desde el archivo
def read_from_file(filename):
    numbers = []
    with open(filename, 'r') as file:
        for line in file:
            numbers.append(int(line.strip()))
    return numbers

# Lista de archivos a procesar
filenames = ['DISTRIBUCION_NORMAL.txt', 'DISTRIBUCION_LINEAL.txt']  # Añade más nombres de archivos según sea necesario

for filename in filenames:
    # Leer los datos del archivo
    data = read_from_file(filename)

    # Crear el gráfico de distribución normal
    plt.figure(figsize=(10, 6))
    plt.hist(data, bins=30, density=True, alpha=0.6, color='g')

    # Calcular y graficar la curva de densidad de probabilidad normal
    mu, std = np.mean(data), np.std(data)
    xmin, xmax = plt.xlim()
    x = np.linspace(xmin, xmax, 100)
    p = np.exp(-0.5 * ((x - mu) / std) ** 2) / (std * np.sqrt(2 * np.pi))
    plt.plot(x, p, 'k', linewidth=2)

    title = f"Histograma y curva de densidad de una distribución normal\n$\mu={mu:.2f}$, $\sigma={std:.2f}$"
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
