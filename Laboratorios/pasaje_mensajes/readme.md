# Laboratorio de Pasaje de Mensajes

## OpenMPI

Realizar con C y la librería OpenMPI

Compilar en Linux Openmpi: ```mpicc –o salidaEjecutable archivoFuente```
1. Implementar la multiplicación de matrices cuadradas de NxN por medio de P procesos. Ejecutarla con diferentes valores de N=256, 512 y 1024. Para cada valor de N usar P=2, 4 y 8.
2. Realizar un algoritmo que dado un elemento X indique la cantidad de veces que aparece dentro de un vector de enteros de N elementos. Se cuenta con una cantidad P de procesos buscadores. Probar con los siguientes valores de P=2, 4 y 8.


### Ejecución

1. Siendo <N> y <P> los valores a reemplazar:
    ```
    mpicc ej1.c -o ej1
    mpirun -np <P> ./ej1 <N>
    ```
    Por ejemplo, para N=100 y P=8:

    ```
    mpicc ej1.c -o ej1
    mpirun -np 8 ./ej1 100
    ```

2. Siendo <N> y <P> los valores a reemplazar:
    ```
    mpicc ej2.c -o ej2
    mpirun -np <P> ./ej2 <N>
    ```

    Por ejemplo, para N=256 y T=8:

    ```
    mpicc ej2.c -o ej2
    mpirun -np 8 ./ej2 256
    ```

