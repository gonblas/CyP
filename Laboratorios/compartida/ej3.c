#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *m1, *m2, *result, N, T;

void *worker(void *arg) {
  int id = *(int*)arg; free(arg);

  int start_row = id * (N / T);
  int end_row = (id + 1) * (N / T);
  
  if (id == T - 1) {
    end_row = N;
  }

  for(int i=start_row; i<end_row;i++) {
    for(int j=0; j<N; j++) {
      int sum = 0;
      for(int k=0; k<N; k++) {
        sum += m1[i*N + k] * m2[k*N + j];
      }
      result[i*N + j] = sum;
    }
  }

  return NULL;
}

void print_matrix(int *m) {
  printf("[");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", m[i*N + j]);
    }
    printf("\n");
  }
  printf("]\n");
}

int main(int argc, char* argv[]){
  if(argc < 3) {
    printf("La cantidad de parámetros es incorrecta.\nUso: %s <N> <T>\n", argv[0]);
    return 1;
  }

  N = atoi(argv[1]);
  T = atoi(argv[2]);
  int i, j, k;
  m1 = (int*)malloc(N * N * sizeof(int));
  m2 = (int*)malloc(N * N * sizeof(int));
  result = (int*)malloc(N * N * sizeof(int));

  if (!m1 || !m2 || !result) {
      printf("Error al asignar memoria\n");
      return 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m1[i * N + j] = rand() % 5;
      m2[i * N + j] = rand() % 5;
    }
  }

  pthread_t threads[T];

  for(i = 0; i<T; i++) {
    int* thread_id = malloc(sizeof(int));
    if (thread_id == NULL) {
      printf("Error al asignar memoria para el thread_id.\n");
      return 1;
    }
    *thread_id = i;
    pthread_create(&threads[i], NULL, worker, thread_id);
  }

  for(i=0; i<T; i++) {
    pthread_join(threads[i], NULL);
  }

  print_matrix(m1); print_matrix(m2); print_matrix(result); 

  free(m1); free(m2); free(result);
  printf("\nPresiona ENTER para salir...\n");
  getchar();

  return 0;
}