#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int X, *vector, N, T;

void *worker(void *arg) {
  int id = *(int*)arg; free(arg);

  int *my_occurrences = malloc(sizeof(int));
  *my_occurrences = 0;
  int start = id * (N / T);
  int end = (id + 1) * (N / T);
  
  if (id == T - 1) {
    end = N;
  }

  for (int i = start; i < end; i++) {
    if (vector[i] == X)
      (*my_occurrences)++;
  }

  return my_occurrences;
}

int main(int argc, char* argv[]) {
  if (argc <= 2) {
    printf("La cantidad de parámetros es incorrecta.\nUso: %s <N> <T>\n", argv[0]);
    return 1;
  }

  srand(time(NULL));

  N = atoi(argv[1]);
  T = atoi(argv[2]);
  X = rand() % 5;
  vector = (int*)malloc(N * sizeof(int));

  if (vector == NULL) {
    printf("Error al asignar memoria.\n");
    return 1;
  }

  printf("Se busca %d en el array: ", X);

  for (int i = 0; i < N; i++) {
    int number = rand() % 5;
    printf("%d, ", number);
    vector[i] = number;
  }

  int occurrences = 0;
  pthread_t threads[T];

  for (int i = 0; i < T; i++) {
    int* thread_id = malloc(sizeof(int));
    if (thread_id == NULL) {
      printf("Error al asignar memoria para el thread_id.\n");
      return 1;
    }
    *thread_id = i;
    pthread_create(&threads[i], NULL, worker, thread_id);
  }

  for (int i = 0; i < T; i++) {
    void *result;
    pthread_join(threads[i], &result);
    occurrences += *(int*)result;
    free(result);
  }

  printf("\nOcurrencias: %d.\n", occurrences);
  free(vector);

  return 0;
}
