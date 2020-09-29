#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
  size_t n;
  printf("N = ");
  scanf("%zu", &n);

  int* arr = (int*)malloc(sizeof(int) * n);
  for (size_t i = 0; i < n; ++i) {
    *(arr + i) = i;
  }

  return 0;
}
