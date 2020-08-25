#include <stdio.h>
#include <stdlib.h>

void fig0(size_t i, size_t n) {
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

void fig1(size_t i, size_t n) {
  for (size_t j = 0; j <= i; ++j) {
    printf("*");
  }
  printf("\n");
}

void fig2(size_t i, size_t n) {
  size_t len;
  if (i < n / 2)
    len = i;
  else
    len = (n - i - 1);
  for (size_t j = 0; j <= len; ++j) {
    printf("*");
  }
  printf("\n");
}

void fig3(size_t i, size_t n) {
  for (size_t j = 0; j < n; ++j) {
    printf("*");
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: ./ex3 N FIGN\n");
    return 1;
  }
  size_t n = atoi(argv[1]);
  size_t fignum = atoi(argv[2]);

  for (size_t i = 0; i < n; ++i) {
    switch (fignum) {
      case 0:
        fig0(i, n);
        break;
      case 1:
        fig1(i, n);
        break;
      case 2:
        fig2(i, n);
        break;
      case 3:
        fig3(i, n);
        break;

      default:
        break;
    }
  }
  return 0;
}
