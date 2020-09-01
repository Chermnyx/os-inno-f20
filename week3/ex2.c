#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void bubble_sort(int array[], size_t n) {
  int swapped;
  do {
    swapped = 0;
    for (size_t i = 1; i < n; ++i) {
      if (array[i - 1] > array[i]) {
        swap(&array[i - 1], &array[i]);
        swapped = 1;
      }
    }
  } while (swapped);
}

int main(int argc, char const* argv[]) {
  int n = 8;
  int a[] = {5, 4, 3, 1, 1, 2, 4, 5};
  bubble_sort(a, n);
  for (size_t i = 0; i < n; ++i) {
    printf("%d\n", a[i]);
  }
  return 0;
}
