import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos desde el archivo de bits de Huffman
bits_data = pd.read_csv('bits_huffmanCodesInt.txt', header=None, names=['Bits'])

# Añadir los bits constantes (32 bits)
bits_data['Constant'] = 32

# Crear un gráfico de barras para comparar los bits de Huffman con los 32 bits constantes
plt.figure(figsize=(10, 6))
bars = plt.bar(bits_data.index, bits_data['Bits'], width=0.4, label='Huffman')
bars2 = plt.bar(bits_data.index + 0.4, bits_data['Constant'], width=0.4, label='Constante (32 bits)', color='red')

plt.xlabel('Índice del Elemento')
plt.ylabel('Cantidad de Bits')
plt.title('Comparación de Bits: Huffman vs. Constante (32 bits)')
plt.xticks(bits_data.index + 0.2, bits_data.index)  # Ajustar las etiquetas del eje x
plt.legend()

# Agregar etiquetas de valores en las barras
for bar in bars + bars2:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2, yval + 0.5, int(yval), ha='center', va='bottom')

plt.tight_layout()

# Guardar el gráfico como una imagen
output_image = f'Huffman.png'  # Generar nombre de archivo basado en el nombre de entrada
plt.savefig(output_image)

plt.show()