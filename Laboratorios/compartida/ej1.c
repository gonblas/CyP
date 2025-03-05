#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <time.h>
#include <omp.h>

int main(int argc, char* argv[]){
  if(argc == 1) {
    printf("La cantidad de parámetros es incorrecta.\nUso: %s <N>\n", argv[0]);
    return 1;
  }

  int N = atoi(argv[1]);
  srand(time(NULL));
  int vector[N];

  for(int i = 0; i < N; i++) {
    int number = rand() % 30 + 1;
    printf("%d \n", number);
    vector[i] = number;
  }
  int i;
  #pragma omp parallel for schedule(dynamic) shared(N, vector)
    for(i = 0; i < N; i++)
    {
      printf("Soy el hilo %d y me voy a dormir %d segundos\n", omp_get_thread_num(), vector[i]);
      sleep(vector[i]);
    }

  return 0;
}