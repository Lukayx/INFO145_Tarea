# Tarea: Técnicas de Representación y Compresión de Arreglos Ordenados

## Clonacion repositorio

```sh
    git clone https://github.com/Lukayx/INFO145_Tarea.git
    cd INFO145_Tarea
```

## Complilacion
Para compilar todos los programas de este repositorio se debe estar en la raiz del reposiorio ejecutar en la terminal:
```sh
    make
```
Para compliar solo prog_1,ejecutar:
```sh
    make clean
    make bin/explicitArray
```
asi tambien para solo prog_2,ejecutar:
```sh
    make clean
    make bin/gapCoding
```
asi tambien para solo prog_3,ejecutar:
```sh
    make clean
    make bin/gapPacked
```
## Ejecutar programas
Para ejecutar un programa de los precentes en el repositorio se debe estar en la capeta bin y en esta carpeta para ejecutar en la terminal:
### Para ejecutar prog_1(explicitArray)
```sh
    ./explicitArray <n>
```
donde \<n\> es el tamaño del Array
### Para ejecutar prog_2(gapCoding_array)
```sh
    ./gapCoding <n>
```
donde \<n\> es el tamaño del Array
### Para ejecutar prog_3(gapPacked_Array)
```sh
    ./gapPacked <n>
```
donde \<n\>  es el tamaño del Array

Ademas los resultados de las ejecuciones de explicitArray,gapCoding,gapPacked_Array se guardan en archios .csv precentes en la carpeta scrpits 
## Para graficar
### Requisitos:
para ejecutar los programas se debe contar minimo con python 3.10,ademas se debe estar instalada la libreria matplotlib.
instalacion libreria matplotlib:
```sh
    pip install matplotlib
```

para obtener los graficos de ExplicitArrray, GapCodingArray,gapPacked_Array.
se debe estar dentro de la carpeta scripts y ejecutar:

```sh
    python3 graficosExplicitArrray.py
```
```sh
    python3 graficosGapCodingArray.py 

```
```sh
    python3 creaGRaficosHuffman.py 
    
```