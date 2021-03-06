#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

void *thread(void *id) {
  printf("-> Thread %d\n", *(int *)id);
  pthread_exit(0);
  return 0;
}

int main(int argc, char const *argv[]) {
  pthread_t threads[N];
  int i;

  // for this loop the order of threads is unpredictable and it depends on the
  // OS scheduler
  for (i = 0; i < N; ++i) {
    printf("Starting thread %d\n", i);
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], 0, thread, id);
  }

  // wait for all threads to finish
  for (i = 0; i < N; ++i) {
    pthread_join(threads[i], 0);
  }

  printf("\n\nStrictly ordered execution\n");
  for (i = 0; i < N; ++i) {
    printf("Starting thread %d\n", i);
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], 0, thread, id);
    pthread_join(threads[i], 0);  // now we're waiting here
    printf("/Thread %d finish\n", i);
  }

  return 0;
}
