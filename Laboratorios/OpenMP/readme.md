# OpenMP 

Realizar con C y la librería OPENMP

Compilar en Linux gcc: ```gcc -fopenmp –o salidaEjecutable archivoFuente```
1. Se tiene un vector de N elementos (números enteros en el rango 1..30). Y a cada uno de los datos se le debe aplicar una **operación** que tarda un tiempo relativo al valor del elemento. Se debe resolver en paralelo con 4 threads.
> **Nota:** la operación se simula por medio de la función ```sleep(tiempo)```. El valor de N debe ser un parámetro del programa.
2. Implementar la multiplicación de matrices cuadradas de NxN por medio de T threads. Ejecutarla con diferentes valores de N=256, 512 y 1024. Para cada valor de N usar T=2, 4 y 8.


## Ejecución

1. Siendo <N> el valor a reemplazar:
    ```
    gcc -fopenmp ej1.c -o ej1; OMP_NUM_THREADS=4 ./ej1 <N>
    ```
    Por ejemplo, para N=100:

    ```
    gcc -fopenmp ej1.c -o ej1; OMP_NUM_THREADS=4 ./ej1 100
    ```

2. Siendo <N> y <T> los valores a reemplazar:
    ```
    gcc -fopenmp ej2.c -o ej2; OMP_NUM_THREADS=8 ./ej2 10
    ```

    Por ejemplo, para N=256 y T=8:

    ```
    gcc -fopenmp ej2.c -o ej2; OMP_NUM_THREADS=8 ./ej2 256
    ```
