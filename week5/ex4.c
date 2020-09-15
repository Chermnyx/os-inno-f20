#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int numbers[MAX_N];
size_t n_size = MAX_N;
size_t T;
typedef struct th_t {
  int* arr;
  size_t size;
  int result;
  pthread_t thread;
} th_t;

int gcd(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return (a == 0 ? b : a);
}

int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void* lcm_t(void* th_v) {
  th_t* th = (th_t*)th_v;
  th->result = 1;
  for (size_t i = 0; i < th->size; ++i) {
    th->result = lcm(th->result, *(th->arr + i));
  }
  pthread_exit(0);
}

int lcm_a() {
  th_t* th_mem = malloc(sizeof(th_t) * T);
  size_t i = 0;
  size_t t_index = 0;
  size_t p = n_size / T;

  for (t_index = 0; t_index < T; ++t_index) {
    (th_mem + t_index)->arr = malloc(sizeof(int) * (p + 1));

    int size = 0;
    int* arr = (th_mem + t_index)->arr;

    for (; i < (p + 1) * (t_index + 1); ++i) {
      if (i >= n_size) break;
      *(arr + size) = numbers[i];
      ++size;
    }

    (th_mem + t_index)->size = size;

    pthread_create(&(th_mem + t_index)->thread, 0, lcm_t, (th_mem + t_index));
  }

  th_t* th = malloc(sizeof(th_t));
  th->arr = malloc(sizeof(int) * T);
  th->size = T;

  for (t_index = 0; t_index < T; ++t_index) {
    pthread_join((th_mem + t_index)->thread, 0);
    *(th->arr + t_index) = (th_mem + t_index)->result;
    free((th_mem + t_index)->arr);
  }
  free(th_mem);

  pthread_create(&th->thread, 0, lcm_t, th);
  pthread_join(th->thread, 0);

  int res = th->result;
  free(th);

  return res;
}

int main(int argc, char const* argv[]) {
  if (argc < 3) return 1;
  const char* fname = argv[1];
  T = atoi(argv[2]);
  FILE* fp = fopen(fname, "r");
  if (fp == 0) {
    printf("No such file");
    return 1;
  }

  for (size_t i = 0; i < MAX_N; ++i) {
    int tmp;
    int result = fscanf(fp, "%d", &tmp);
    if (result == EOF) {
      n_size = i;
      break;
    }
    numbers[i] = tmp;
  }
  fclose(fp);

  int result = lcm_a();
  printf("LCM: %d\n", result);
}
