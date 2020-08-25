#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

int main(int argc, char const* argv[]) {
  int a, b;
  printf("Input a and b:\n");
  scanf("%d %d", &a, &b);
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}
