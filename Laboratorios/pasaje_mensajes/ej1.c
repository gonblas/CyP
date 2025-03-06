#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <time.h>

void print_matrix(int *m, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", m[i*size + j]);
    }
    printf("\n");
  }
  printf("]\n");
}

void print_vector(int *v, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d ", v[i]);
  }
  printf("]\n");
}

int main(int argc, char* argv[]){
  if(argc < 2) {
    printf("La cantidad de parámetros es incorrecta.\nUso: %s <N>\n", argv[0]);
    return 1;
  }
  int *m1, *m2, *result, *m1_split, *m2_split, N, P, id;
  N = atoi(argv[1]);
  int i, j, k;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &P);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  int base_split_size = N / P;
  int extra = N % P;

  int *sendcounts = (int*)malloc(P * sizeof(int));
  int *displs = (int*)malloc(P * sizeof(int));

  for (int i = 0; i < P; i++) {
      sendcounts[i] = base_split_size * N;
      displs[i] = i * base_split_size * N;
  }
  if(extra) {
      sendcounts[P-1] += extra * N; // Corrected to add extra rows * N columns
  }

  m2 = (int*)malloc(N * N * sizeof(int));
  m1 = NULL;
  result = NULL;
  if(id == 0){
    m1 = (int*)malloc(N * N * sizeof(int));
    result = (int*)malloc(N * N * sizeof(int));
    if (!m1 || !m2 || !result) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        m1[i * N + j] = rand() % 5;
        m2[i * N + j] = rand() % 5;
      }
    }
  } else {
      if (!m2) {
          printf("Error al asignar memoria en proceso %d para m2\n", id);
          MPI_Abort(MPI_COMM_WORLD, 1);
      }
  }


  m1_split = (int*)malloc(sendcounts[id] * sizeof(int));
  if (m1_split == NULL) {
    printf("Error al asignar memoria en el proceso %d para m1_split.\n", id);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  MPI_Scatterv(m1, sendcounts, displs, MPI_INT, m1_split, sendcounts[id], MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(m2, N * N, MPI_INT, 0, MPI_COMM_WORLD);

  int *internal_result = (int*)malloc(sendcounts[id] * sizeof(int));
  if(internal_result == NULL) {
      printf("Error al asignar memoria para internal_result en proceso %d.\n", id);
      MPI_Abort(MPI_COMM_WORLD, 1);
  }

  for(int i=0; i<sendcounts[id] / N; i++) {
    for(int j=0; j<N; j++) {
      int sum = 0;
      for(int k=0; k<N; k++) {
        sum += m1_split[(i)*N + k] * m2[k*N + j];
      }
      internal_result[i*N + j] = sum;
    }
  }

  MPI_Gatherv(internal_result, (sendcounts[id] / N) * N, MPI_INT, result, sendcounts, displs, MPI_INT, 0, MPI_COMM_WORLD);

  if(id==0){
    printf("m1 es: \n");
    print_matrix(m1, N);
    printf("m2 es: \n");
    print_matrix(m2, N);
    printf("Result matrix es: \n");
    print_matrix(result, N);
  }

  if(id == 0) {
      free(m1); free(result);
  }
  free(m2);
  free(m1_split);
  free(internal_result);
  free(sendcounts);
  free(displs);

  MPI_Finalize();

  return 0;
}