# Laboratorio de Memoria Compartida

## OpenMP

Realizar con C y la librería OPENMP

Compilar en Linux gcc: ```gcc -fopenmp –o salidaEjecutable archivoFuente```
1. Se tiene un vector de N elementos (números enteros en el rango 1..30). Y a cada uno de los datos se le debe aplicar una **operación** que tarda un tiempo relativo al valor del elemento. Se debe resolver en paralelo con 4 threads.
> **Nota:** la operación se simula por medio de la función ```sleep(tiempo)```. El valor de N debe ser un parámetro del programa.
2. Implementar la multiplicación de matrices cuadradas de NxN por medio de T threads. Ejecutarla con diferentes valores de N=256, 512 y 1024. Para cada valor de N usar T=2, 4 y 8.


### Ejecución

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


## Pthreads

Realizar con C y la librería  Pthreads

Compilar en Linux gcc: ```gcc -pthread –o salidaEjecutable archivoFuente```
3. Implementar la multiplicación de matrices cuadradas de NxN por medio de T threads. Ejecutarla con diferentes valores de N=256, 512 y 1024. Para cada valor de N usar T=2, 4 y 8.
4. Realizar un algoritmo que dado un elemento **X** indique la cantidad de veces que aparece dentro de un vector de enteros de N elementos. Se cuenta con una cantidad T de threads buscadores. Al final la cantidad de veces que aparece el elemento X debe quedar en una variable llamada **ocurrencias**. Probar con los siguientes valores de T=2, 4 y 8.

### Ejecución

3. Siendo <N> el valor a reemplazar:
    ```
    gcc -pthread ej3.c -o ej3; ./ej3 <N> <T>
    ```
    Por ejemplo, para N=100 y T=4:

    ```
    gcc -pthread ej3.c -o ej3; ./ej3 100
    ```

4. Siendo <N> y <T> los valores a reemplazar:
    ```
    gcc -pthread ej4.c -o ej4; ./ej4 <N> <T>
    ```

    Por ejemplo, para N=100 y T=4:

    ```
    gcc -pthread ej4.c -o ej4; ./ej4 100 4
    ```
