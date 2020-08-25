#include <stdio.h>
#include <stdlib.h>

void printline(size_t i, size_t n) {
  size_t spaces_pre = (n - i - 1);
  for (size_t j = 0; j < spaces_pre; ++j) {
    printf(" ");
  }
  printf("*");
  for (size_t j = 0; j < (i * 2); ++j) {
    printf("*");
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: ./ex3 N\n");
    return 1;
  }
  size_t n = atoi(argv[1]);
  for (size_t i = 0; i < n; ++i) {
    printline(i, n);
  }
  return 0;
}
