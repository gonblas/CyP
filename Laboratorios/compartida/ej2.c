#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]){
  if(argc == 1) {
    printf("La cantidad de parámetros es incorrecta.\nUso: %s <N>\n", argv[0]);
    return 1;
  }

  int N = atoi(argv[1]);
  printf("N = %d", N);
  int i, j, k;
  int *m1 = (int*)malloc(N * N * sizeof(int));
  int *m2 = (int*)malloc(N * N * sizeof(int));
  int *result = (int*)malloc(N * N * sizeof(int));

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

  #pragma omp parallel for schedule(guided, 32) shared(m1, m2, result, N)
  for(i=0; i<N; i++)
  {
    for(j=0; j<N; j++) 
    {
      result[i,j] = 0;
      for(k=0;k<N;k++) 
        result[i,j] += m1[i,k] * m2[k,j];
        printf("result[%d,%d] = %d\n", i, j, result[i,j]);
    }
  }

  free(m1); free(m2); free(result);

  return 0;
}