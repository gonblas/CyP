#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("La cantidad de parámetros es incorrecta.\nUso: %s <N>\n", argv[0]);
        return 1;
    }

    int id, P, N = atoi(argv[1]);  
    int *vector = NULL, *split_vector = NULL;
    int X, occurrences = 0, my_occurrences = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    int base_split_size = N / P;
    int extra = N % P;

    int *sendcounts = (int*)malloc(P * sizeof(int));
    int *displs = (int*)malloc(P * sizeof(int));

    for (int i = 0; i < P; i++) {
        sendcounts[i] = base_split_size;
        displs[i] = i * base_split_size;
    }
    if(extra) {
        sendcounts[P-1] += extra;
    }

    if (id == 0) {
        srand(time(NULL));
        vector = (int*)malloc(N * sizeof(int));
        if (vector == NULL) {
            printf("Error al asignar memoria.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        X = rand() % 5;
        printf("Se busca %d en el array: ", X);
        for (int i = 0; i < N; i++) {
            vector[i] = rand() % 5;
            printf("%d, ", vector[i]);
        }
        printf("\n");
    }

    MPI_Bcast(&X, 1, MPI_INT, 0, MPI_COMM_WORLD);

    split_vector = (int*)malloc(sendcounts[id] * sizeof(int));
    if (split_vector == NULL) {
        printf("Error al asignar memoria en el proceso %d.\n", id);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    MPI_Scatterv(vector, sendcounts, displs, MPI_INT, split_vector, sendcounts[id], MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < sendcounts[id]; i++) {
        if (split_vector[i] == X) {
            my_occurrences++;
        }
    }

    MPI_Reduce(&my_occurrences, &occurrences, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (id == 0) {
        printf("\nOcurrencias totales: %d\n", occurrences);
        free(vector);
    }

    free(split_vector);
    free(sendcounts);
    free(displs);

    MPI_Finalize();

    return 0;
}
